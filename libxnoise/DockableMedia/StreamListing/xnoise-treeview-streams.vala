/* xnoise-treeview-streams.vala
 *
 * Copyright (C) 2012  Jörn Magens
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  The Xnoise authors hereby grant permission for non-GPL compatible
 *  GStreamer plugins to be used and distributed together with GStreamer
 *  and Xnoise. This permission is above and beyond the permissions granted
 *  by the GPL license by which Xnoise is covered. If you modify this code
 *  you may extend this exception to your version of the code, but you are not
 *  obligated to do so. If you do not wish to do so, delete this exception
 *  statement from your version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301  USA.
 *
 * Author:
 *     Jörn Magens
 */


using Gtk;
using Gdk;

using Xnoise;
using Xnoise.Services;
using Xnoise.Database;


private class Xnoise.TreeViewStreams : Gtk.TreeView, TreeQueryable {
    private unowned MainWindow win;
    private unowned DockableMedia dock;
    private bool dragging = false;
    private Gtk.Menu menu;

    private const TargetEntry[] src_target_entries = {
        {"application/custom_dnd_data", TargetFlags.SAME_APP, 0}
    };
    
//    private int fontsizeMB = 10;
    private Pango.FontDescription font_description;
    private int last_width;
    //parent container of this widget (most likely scrolled window)
    private unowned Widget ow;
    private TreeViewStreamsModel tvm;
    
    public TreeViewStreams(DockableMedia dock, MainWindow window, Widget ow) {
        this.win = window;
        this.dock = dock;
        this.ow = ow;
        //this.get_style_context().add_class(Gtk.STYLE_CLASS_SIDEBAR);
        this.headers_visible = false;
        this.get_selection().set_mode(SelectionMode.MULTIPLE);
        this.set_enable_search(false);
        
        var column = new TreeViewColumn();
        
//        fontsizeMB = Params.get_int_value("fontsizeMB");
        Gtk.StyleContext context = this.get_style_context();
        font_description = context.get_font(StateFlags.NORMAL).copy();
        font_description.set_size((int)(global.fontsize_dockable * Pango.SCALE));
        
        int hsepar = 0;
        this.style_get("horizontal-separator", out hsepar);
        var renderer = new ListFlowingTextRenderer(font_description, column, hsepar);
        renderer.editable = true;
        renderer.editable_set = true;
        renderer.editing_started.connect( () => {
            global.cellrenderer_in_edit = true;
        });
        renderer.editing_canceled.connect( () => {
            global.cellrenderer_in_edit = false;
        });
        renderer.edited.connect( (s,ps,t) => {
            if(t == EMPTYSTRING)
                return;
            TreePath p = new TreePath.from_string(ps);
            TreeIter iter;
            tvm.get_iter(out iter, p);
            Item? item;
            tvm.get(iter, TreeViewStreamsModel.Column.ITEM, out item);
            if(item.text == t)
                return;
            item.text = t;
            tvm.set(iter, 
                    TreeViewStreamsModel.Column.VIS_TEXT,   t,
                    TreeViewStreamsModel.Column.ITEM,       item
            );
            global.cellrenderer_in_edit = false;
            Worker.Job job = new Worker.Job(Worker.ExecutionType.ONCE_HIGH_PRIORITY, update_stream_name_job);
            job.item = item;
            db_worker.push_job(job);
        });
        var rendererPb = new CellRendererPixbuf();
        
        column.pack_start(rendererPb, false);
        column.pack_start(renderer, true);
        column.add_attribute(rendererPb, "pixbuf", 0);
        column.add_attribute(renderer, "text", 1);
        column.add_attribute(renderer, "pix", 0);
        
        this.insert_column(column, -1);
        tvm = new TreeViewStreamsModel(dock, this);
        this.model = tvm;
        
        this.row_activated.connect( (s,tp,c) => {
            Item? item = Item(ItemType.UNKNOWN);
            TreeIter iter;
            this.model.get_iter(out iter, tp);
            this.model.get(iter, TreeViewStreamsModel.Column.ITEM, out item);
            ItemHandler? tmp = itemhandler_manager.get_handler_by_type(ItemHandlerType.TRACKLIST_ADDER);
            if(tmp == null)
                return;
            unowned Action? action = tmp.get_action(item.type, ActionContext.QUERYABLE_TREE_ITEM_ACTIVATED, ItemSelectionType.SINGLE);
            
            if(action != null)
                action.action(item, null);
            else
                print("action was null\n");
        });
        Gtk.drag_source_set(this,
                            Gdk.ModifierType.BUTTON1_MASK,
                            this.src_target_entries,
                            Gdk.DragAction.COPY
        );
        this.drag_begin.connect(this.on_drag_begin);
        this.drag_data_get.connect(this.on_drag_data_get);
        this.drag_end.connect(this.on_drag_end);
        this.button_release_event.connect(this.on_button_release);
        this.button_press_event.connect(this.on_button_press);
        
        this.ow.size_allocate.connect_after( (s, a) => {
            unowned TreeViewColumn tvc = this.get_column(0);
            int current_width = this.ow.get_allocated_width();
            if(last_width == current_width)
                return;
            
            last_width = current_width;
            
            tvc.max_width = tvc.min_width = current_width - 20;
            TreeModel? xm = this.get_model();
            if(xm != null)
                xm.foreach( (mo, pt, it) => {
                    if(mo == null)
                        return true;
                    mo.row_changed(pt, it);
                    return false;
                });
        });
        this.realize.connect_after( () => {
            Idle.add( () => {
                //print("realized\n");
                unowned TreeViewColumn tvc = this.get_column(0);
                int current_width = this.ow.get_allocated_width();
                
                tvc.max_width = tvc.min_width = current_width - 20;
                TreeModel? xm = this.get_model();
                if(xm != null)
                    xm.foreach( (mo, pt, it) => {
                        if(mo == null)
                            return true;
                        mo.row_changed(pt, it);
                        return false;
                    });
                return false;
            });
        });
        global.notify["fontsize-dockable"].connect( () => {
            if(global.fontsize_dockable == 0) { //default
                font_description.set_size((int)(10 * Pango.SCALE));
            }
            else {
                font_description.set_size((int)(global.fontsize_dockable * Pango.SCALE));
                Idle.add(()  => {
                    this.set_model(null);
                    this.set_model(tvm);
                    return false;
                });
            }
        });
    }
    
    private bool update_stream_name_job(Worker.Job job) {
        db_writer.update_stream_name(job.item);
        return false;
    }
    
    private class ListFlowingTextRenderer : CellRendererText {
        private int maxiconwidth;
        private unowned Pango.FontDescription font_description;
        private unowned TreeViewColumn col;
        private int hsepar;
        
        public int level                { get; set; }
        public unowned Gdk.Pixbuf pix   { get; set; }
        
        public ListFlowingTextRenderer(Pango.FontDescription font_description, TreeViewColumn col, int hsepar) {
            GLib.Object();
            this.col = col;
            this.hsepar = hsepar;
            this.font_description = font_description;
            maxiconwidth = 0;
        }
        
        public override void get_preferred_height_for_width(Gtk.Widget widget,
                                                            int width,
                                                            out int minimum_height,
                                                            out int natural_height) {
            int column_width = col.get_width();
            int sum = 0;
            int iconwidth = (pix == null) ? 16 : pix.get_width();
            if(maxiconwidth < iconwidth)
                maxiconwidth = iconwidth;
            sum = hsepar + (2 * (int)xpad) + maxiconwidth;
            var pango_layout = widget.create_pango_layout(text);
            pango_layout.set_font_description(this.font_description);
            pango_layout.set_alignment(Pango.Alignment.LEFT);
            pango_layout.set_width( (int)((column_width - sum) * Pango.SCALE));
            pango_layout.set_wrap(Pango.WrapMode.WORD_CHAR);
            int wi, he = 0;
            pango_layout.get_pixel_size(out wi, out he);
            natural_height = minimum_height = he + 2;
        }
    
        public override void get_size(Widget widget, Gdk.Rectangle? cell_area,
                                      out int x_offset, out int y_offset,
                                      out int width, out int height) {
            // function not used for gtk+-3.0 !
            x_offset = 0;
            y_offset = 0;
            width = 0;
            height = 0;
        }
    
        public override void render(Cairo.Context cr, Widget widget,
                                    Gdk.Rectangle background_area,
                                    Gdk.Rectangle cell_area,
                                    CellRendererState flags) {
            StyleContext context;
            var pango_layout = widget.create_pango_layout(text);
            pango_layout.set_font_description(this.font_description);
            pango_layout.set_alignment(Pango.Alignment.LEFT);
            pango_layout.set_width( (int)(cell_area.width * Pango.SCALE));
            pango_layout.set_wrap(Pango.WrapMode.WORD_CHAR);
            context = widget.get_style_context();
            int wi = 0, he = 0;
            pango_layout.get_pixel_size(out wi, out he);
            if(cell_area.height > he)
                context.render_layout(cr, cell_area.x, cell_area.y + (cell_area.height -he)/2, pango_layout);
            else
                context.render_layout(cr, cell_area.x, cell_area.y, pango_layout);
        }
    }
    
    private void on_drag_begin(Gtk.Widget sender, DragContext context) {
        this.dragging = true;
        List<unowned TreePath> treepaths;
        Gdk.drag_abort(context, Gtk.get_current_event_time());
        Gtk.TreeSelection selection = this.get_selection();
        treepaths = selection.get_selected_rows(null);
        if(treepaths != null) {
            TreeIter iter;
            Pixbuf p;
            this.model.get_iter(out iter, treepaths.nth_data(0));
            this.model.get(iter, TreeViewStreamsModel.Column.ICON, out p);
            Gtk.drag_source_set_icon_pixbuf(this, p);
        }
        else {
            if(selection.count_selected_rows() > 1) {
                Gtk.drag_source_set_icon_stock(this, Gtk.Stock.DND_MULTIPLE);
            }
            else {
                Gtk.drag_source_set_icon_stock(this, Gtk.Stock.DND);
            }
        }
    }

    private void on_drag_data_get(Gtk.Widget sender, Gdk.DragContext context, Gtk.SelectionData selection_data, uint info, uint etime) {
        List<unowned TreePath> treepaths;
        unowned Gtk.TreeSelection selection;
        selection = this.get_selection();
        treepaths = selection.get_selected_rows(null);
        DndData[] ids = {};
        if(treepaths.length() < 1)
            return;
        foreach(TreePath treepath in treepaths) { 
            //TreePath tp = filtermodel.convert_path_to_child_path(treepath);
            DndData[] l = ((TreeViewStreamsModel)this.model).get_dnd_data_for_path(ref treepath); 
            foreach(DndData u in l) {
                //print("dnd data get %d  %s\n", u.db_id, u.mediatype.to_string());
                ids += u; // this is necessary, if more than one path can be selected
            }
        }
        Gdk.Atom dnd_atom = Gdk.Atom.intern(src_target_entries[0].target, true);
        unowned uchar[] data = (uchar[])ids;
        data.length = (int)(ids.length * sizeof(DndData));
        selection_data.set(dnd_atom, 8, data);
    }

    private void on_drag_end(Gtk.Widget sender, Gdk.DragContext context) {
        this.dragging = false;
        this.unset_rows_drag_dest();
    }
    
    private bool on_button_press(Gdk.EventButton e) {
        Gtk.TreePath treepath = null;
        Gtk.TreeViewColumn column;
        Gtk.TreeSelection selection = this.get_selection();
        int x = (int)e.x;
        int y = (int)e.y;
        int cell_x, cell_y;
        
        if(!this.get_path_at_pos(x, y, out treepath, out column, out cell_x, out cell_y))
            return true;
        
        switch(e.button) {
            case 1: {
                if(selection.count_selected_rows()<= 1) {
                    return false;
                }
                else {
                    if(selection.path_is_selected(treepath)) {
                        if(((e.state & Gdk.ModifierType.SHIFT_MASK)==Gdk.ModifierType.SHIFT_MASK)|
                           ((e.state & Gdk.ModifierType.CONTROL_MASK)==Gdk.ModifierType.CONTROL_MASK)) {
                            selection.unselect_path(treepath);
                        }
                        return true;
                    }
                    else if(!(((e.state & Gdk.ModifierType.SHIFT_MASK)==Gdk.ModifierType.SHIFT_MASK)|
                            ((e.state & Gdk.ModifierType.CONTROL_MASK)==Gdk.ModifierType.CONTROL_MASK))) {
                        return true;
                    }
                    return false;
                }
            }
            case 3: {
                TreeIter iter;
                this.tvm.get_iter(out iter, treepath);
                if(!selection.path_is_selected(treepath)) {
                    selection.unselect_all();
                    selection.select_path(treepath);
                }
                rightclick_menu_popup(e.time);
                return true;
            }
            default: {
                break;
            }
        }
        if(!(selection.count_selected_rows()>0 ))
            selection.select_path(treepath);
        return false;
    }

    public int get_model_item_column() {
        return (int)TreeViewVideosModel.Column.ITEM;
    }
    
    private void rightclick_menu_popup(uint activateTime) {
        menu = create_rightclick_menu();
        if(menu != null)
            menu.popup(null, null, null, 0, activateTime);
    }

    private Gtk.Menu create_rightclick_menu() {
        TreeIter iter;
        var rightmenu = new Gtk.Menu();
        GLib.List<TreePath> list;
        list = this.get_selection().get_selected_rows(null);
        ItemSelectionType itemselection = ItemSelectionType.SINGLE;
        if(list.length() > 1)
            itemselection = ItemSelectionType.MULTIPLE;
        Item? item = null;
        Array<unowned Action?> array = null;
        TreePath path = (TreePath)list.data;
        tvm.get_iter(out iter, path);
        tvm.get(iter, TreeViewVideosModel.Column.ITEM, out item);
        array = itemhandler_manager.get_actions(item.type, ActionContext.QUERYABLE_TREE_MENU_QUERY, itemselection);
        for(int i =0; i < array.length; i++) {
            unowned Action x = array.index(i);
            //print("%s\n", x.name);
            var menu_item = new ImageMenuItem.from_stock((x.stock_item != null ? x.stock_item : Gtk.Stock.INFO), null);
            menu_item.set_label(x.info);
            menu_item.activate.connect( () => {
                x.action(item, this);
            });
            rightmenu.append(menu_item);
        }
        rightmenu.show_all();
        return rightmenu;
    }
    private bool on_button_release(Gtk.Widget sender, Gdk.EventButton e) {
        Gtk.TreePath treepath;
        Gtk.TreeViewColumn column;
        int cell_x, cell_y;
        
        if((e.button != 1)|(this.dragging)) {
            this.dragging = false;
            return true;
        }
        if(((e.state & Gdk.ModifierType.SHIFT_MASK) == Gdk.ModifierType.SHIFT_MASK)|
            ((e.state & Gdk.ModifierType.CONTROL_MASK) == Gdk.ModifierType.CONTROL_MASK)) {
            return true;
        }
        
        Gtk.TreeSelection selection = this.get_selection();
        int x = (int)e.x;
        int y = (int)e.y;
        if(!this.get_path_at_pos(x, y, out treepath, out column, out cell_x, out cell_y))
            return false;
        selection.unselect_all();
        selection.select_path(treepath);
        
        return false;
    }
}

