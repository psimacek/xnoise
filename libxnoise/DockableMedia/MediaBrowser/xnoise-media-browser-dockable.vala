/* xnoise-media-browser-dockable.vala
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

using Xnoise;



// Media Browser is a special case of the DockableMedia,
// because it's the main source of media.
private class Xnoise.MediaBrowserDockable : DockableMedia {
    private unowned MainWindow win;
    
    public override string name() {
        return "MediaBrowserDockable";
    }
    
    public override string headline() {
        return _("Music");
    }
    
    public override DockableMedia.Category category() {
        return DockableMedia.Category.MEDIA_COLLECTION;
    }
    
    public override Gtk.Widget? get_widget(MainWindow window) {
        this.win = window; // use this ref because static main_window
                           //is not yet set up at construction time
        win.mediaBrScrollWin = new ScrolledWindow(null, null);
        win.mediaBrScrollWin.border_width = 0;
        win.mediaBrScrollWin.set_shadow_type(ShadowType.IN);
        win.mediaBr = new MediaBrowser(this, win.mediaBrScrollWin);
        //win.mediaBr.get_style_context().add_class(Gtk.STYLE_CLASS_SIDEBAR);
        win.mediaBrScrollWin.add(win.mediaBr);
        return (Gtk.Widget)win.mediaBrScrollWin;
    }
    
    public override Gdk.Pixbuf get_icon() {
        return icon_repo.title_icon;
    }
}

