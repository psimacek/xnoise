/* libxnoiseutils-1.0.vapi generated by valac 0.12.0, do not modify. */

[CCode (cprefix = "Xnoise", lower_case_cprefix = "xnoise_")]
namespace Xnoise {
	[CCode (cprefix = "XnoisePl", lower_case_cprefix = "xnoise_pl_")]
	namespace Pl {
		[CCode (cprefix = "XnoisePlAsx", lower_case_cprefix = "xnoise_pl_asx_")]
		namespace Asx {
		}
		[CCode (cprefix = "XnoisePlM3u", lower_case_cprefix = "xnoise_pl_m3u_")]
		namespace M3u {
		}
		[CCode (cprefix = "XnoisePlPls", lower_case_cprefix = "xnoise_pl_pls_")]
		namespace Pls {
		}
		[CCode (cprefix = "XnoisePlWpl", lower_case_cprefix = "xnoise_pl_wpl_")]
		namespace Wpl {
		}
		[CCode (cprefix = "XnoisePlXspf", lower_case_cprefix = "xnoise_pl_xspf_")]
		namespace Xspf {
		}
		[CCode (ref_function = "xnoise_pl_item_ref", unref_function = "xnoise_pl_item_unref", cheader_filename = "libxnoiseutils.h")]
		public class Item {
			[CCode (cprefix = "XNOISE_PL_ITEM_FIELD_", cheader_filename = "libxnoiseutils.h")]
			public enum Field {
				URI,
				TITLE,
				AUTHOR,
				GENRE,
				ALBUM,
				COPYRIGHT,
				DURATION,
				PARAM_NAME,
				PARAM_VALUE,
				IS_REMOTE,
				IS_PLAYLIST
			}
			public Item ();
			public void add_field (Xnoise.Pl.Item.Field field, string val);
			public string? get_abs_path ();
			public string? get_album ();
			public string? get_author ();
			public Xnoise.Pl.Item.Field[] get_contained_fields ();
			public string? get_copyright ();
			public long get_duration ();
			public string? get_duration_string ();
			public string get_field (Xnoise.Pl.Item.Field field);
			public string? get_genre ();
			public string? get_param_name ();
			public string? get_param_value ();
			public string? get_rel_path ();
			public string? get_title ();
			public string? get_uri ();
			public bool is_playlist ();
			public bool is_remote ();
			public string? base_path { get; set; }
			public Xnoise.Pl.TargetType target_type { get; set; }
		}
		[CCode (ref_function = "xnoise_pl_item_collection_ref", unref_function = "xnoise_pl_item_collection_unref", cheader_filename = "libxnoiseutils.h")]
		public class ItemCollection {
			[CCode (ref_function = "xnoise_pl_item_collection_iterator_ref", unref_function = "xnoise_pl_item_collection_iterator_unref", cheader_filename = "libxnoiseutils.h")]
			public class Iterator {
				public Iterator (Xnoise.Pl.ItemCollection dc);
				public void append (Xnoise.Pl.Item item);
				public bool first ();
				public Xnoise.Pl.Item @get ();
				public bool has_previous ();
				public int index ();
				public void insert (Xnoise.Pl.Item item);
				public bool next ();
				public bool previous ();
				public void remove ();
				public void @set (Xnoise.Pl.Item item);
			}
			public ItemCollection ();
			public void add_general_info (string key, string val);
			public bool append (Xnoise.Pl.Item item);
			public void clear ();
			public bool contains (Xnoise.Pl.Item d);
			public bool contains_field (Xnoise.Pl.Item.Field field, string value);
			public bool data_available ();
			public Xnoise.Pl.Item @get (int index);
			public string? get_album_for_uri (ref string uri_needle);
			public string? get_author_for_uri (ref string uri_needle);
			public Xnoise.Pl.Item.Field[] get_contained_fields_for_idx (int idx);
			public Xnoise.Pl.Item.Field[] get_contained_fields_for_uri (ref string uri);
			public string? get_copyright_for_uri (ref string uri_needle);
			public long get_duration_for_uri (ref string uri_needle);
			public string? get_duration_string_for_uri (ref string uri_needle);
			public string[] get_found_uris ();
			public string get_general_info (string key);
			public string[] get_general_info_keys ();
			public string? get_genre_for_uri (ref string uri_needle);
			public bool get_is_playlist_for_uri (ref string uri_needle);
			public bool get_is_remote_for_uri (ref string uri_needle);
			public int get_number_of_entries ();
			public string? get_param_name_for_uri (ref string uri_needle);
			public string? get_param_value_for_uri (ref string uri_needle);
			public int get_size ();
			public string? get_title_for_uri (ref string uri_needle);
			public int index_of (Xnoise.Pl.Item d);
			public void insert (int index, Xnoise.Pl.Item item);
			public Xnoise.Pl.ItemCollection.Iterator iterator ();
			public void merge (Xnoise.Pl.ItemCollection data_collection);
			public bool remove (Xnoise.Pl.Item item);
			public Xnoise.Pl.Item remove_at (int index);
			public void @set (int index, Xnoise.Pl.Item item);
		}
		[CCode (cheader_filename = "libxnoiseutils.h")]
		public class Reader : GLib.Object {
			public Reader ();
			public bool data_available ();
			public string? get_album_for_uri (ref string uri_needle);
			public string? get_author_for_uri (ref string uri_needle);
			public string? get_copyright_for_uri (ref string uri_needle);
			public long get_duration_for_uri (ref string uri_needle);
			public string? get_duration_string_for_uri (ref string uri_needle);
			public string[] get_found_uris ();
			public string? get_genre_for_uri (ref string uri_needle);
			public bool get_is_playlist_for_uri (ref string uri_needle);
			public bool get_is_remote_for_uri (ref string uri_needle);
			public int get_number_of_entries ();
			public string? get_title_for_uri (ref string uri_needle);
			public Xnoise.Pl.Result read (string list_uri, GLib.Cancellable? cancellable = null) throws Xnoise.Pl.ReaderError;
			public async Xnoise.Pl.Result read_asyn (string list_uri, GLib.Cancellable? cancellable = null) throws Xnoise.Pl.ReaderError;
			public Xnoise.Pl.ItemCollection data_collection { get; }
			public string playlist_uri { get; }
			public Xnoise.Pl.ListType ptype { get; }
			public signal void finished (string playlist_uri);
			public signal void started (string playlist_uri);
		}
		[CCode (cprefix = "XNOISE_PL_LIST_TYPE_", cheader_filename = "libxnoiseutils.h")]
		public enum ListType {
			UNKNOWN,
			IGNORED,
			M3U,
			PLS,
			ASX,
			XSPF,
			WPL
		}
		[CCode (cprefix = "XNOISE_PL_RESULT_", cheader_filename = "libxnoiseutils.h")]
		public enum Result {
			UNHANDLED,
			ERROR,
			IGNORED,
			SUCCESS,
			EMPTY,
			DOUBLE_WRITE
		}
		[CCode (cprefix = "XNOISE_PL_TARGET_TYPE_", cheader_filename = "libxnoiseutils.h")]
		public enum TargetType {
			URI,
			REL_PATH,
			ABS_PATH
		}
		[CCode (cprefix = "XNOISE_PL_READER_ERROR_", cheader_filename = "libxnoiseutils.h")]
		public errordomain ReaderError {
			UNKNOWN_TYPE,
			SOMETHING_ELSE,
		}
		[CCode (cheader_filename = "libxnoiseutils.h")]
		public static bool debug;
		[CCode (cheader_filename = "libxnoiseutils.h")]
		public const string[] known_playlist_extensions;
		[CCode (cheader_filename = "libxnoiseutils.h")]
		public const string[] remote_schemes;
		[CCode (cheader_filename = "libxnoiseutils.h")]
		public static long get_duration_from_string (ref string? duration_string);
		[CCode (cheader_filename = "libxnoiseutils.h")]
		public static string? get_extension (GLib.File? f);
		[CCode (cheader_filename = "libxnoiseutils.h")]
		public static GLib.File get_file_for_location (string adr, ref string base_path, out Xnoise.Pl.TargetType tt);
		[CCode (cheader_filename = "libxnoiseutils.h")]
		public static Xnoise.Pl.ListType get_playlist_type_for_uri (ref string uri_);
		[CCode (cheader_filename = "libxnoiseutils.h")]
		public static Xnoise.Pl.ListType get_type_by_data (ref string uri_);
		[CCode (cheader_filename = "libxnoiseutils.h")]
		public static Xnoise.Pl.ListType get_type_by_extension (ref string uri_);
		[CCode (cheader_filename = "libxnoiseutils.h")]
		public static bool is_known_playlist_extension (ref string ext);
	}
	[CCode (cprefix = "XnoiseSimpleXml", lower_case_cprefix = "xnoise_simple_xml_")]
	namespace SimpleXml {
		[CCode (ref_function = "xnoise_simple_xml_node_ref", unref_function = "xnoise_simple_xml_node_unref", cheader_filename = "libxnoiseutils.h")]
		public class Node {
			[CCode (ref_function = "xnoise_simple_xml_node_attributes_ref", unref_function = "xnoise_simple_xml_node_attributes_unref", cheader_filename = "libxnoiseutils.h")]
			public class Attributes {
				[CCode (ref_function = "xnoise_simple_xml_node_attributes_keys_ref", unref_function = "xnoise_simple_xml_node_attributes_keys_unref", cheader_filename = "libxnoiseutils.h")]
				public class Keys {
					[CCode (ref_function = "xnoise_simple_xml_node_attributes_keys_iterator_ref", unref_function = "xnoise_simple_xml_node_attributes_keys_iterator_unref", cheader_filename = "libxnoiseutils.h")]
					public class Iterator {
						public Iterator (Xnoise.SimpleXml.Node.Attributes _iter_attib);
						public string? @get ();
						public bool next ();
					}
					public Keys (Xnoise.SimpleXml.Node.Attributes _attrib);
					public bool contains (string needle_key);
					public Xnoise.SimpleXml.Node.Attributes.Keys.Iterator iterator ();
				}
				public Xnoise.SimpleXml.Node.Attributes.Keys keys;
				public Attributes ();
				public void add (string key, string val);
				public void clear ();
				public string? @get (string key);
				public void remove (string key);
				public void replace (string key, string val);
				public void @set (string key, string? val);
				public int item_count { get; }
				public GLib.List<weak string> key_list { owned get; }
				public GLib.List<weak string> value_list { owned get; }
			}
			[CCode (ref_function = "xnoise_simple_xml_node_iterator_ref", unref_function = "xnoise_simple_xml_node_iterator_unref", cheader_filename = "libxnoiseutils.h")]
			public class Iterator {
				public Iterator (Xnoise.SimpleXml.Node parent_node);
				public unowned Xnoise.SimpleXml.Node @get ();
				public bool next ();
				public void @set (Xnoise.SimpleXml.Node node);
			}
			public Xnoise.SimpleXml.Node.Attributes attributes;
			public Node (string? name);
			public void append_child (Xnoise.SimpleXml.Node node);
			public void clear ();
			public unowned Xnoise.SimpleXml.Node? @get (int idx);
			public unowned Xnoise.SimpleXml.Node? get_child_by_name (string childname);
			public Xnoise.SimpleXml.Node[] get_children_by_name (string childname);
			public int get_idx_of_child (Xnoise.SimpleXml.Node node);
			public bool has_attributes ();
			public bool has_children ();
			public bool has_text ();
			public void insert_child (int pos, Xnoise.SimpleXml.Node node);
			public Xnoise.SimpleXml.Node.Iterator iterator ();
			public void prepend_child (Xnoise.SimpleXml.Node node);
			public bool remove_child (Xnoise.SimpleXml.Node node);
			public bool remove_child_at_idx (int idx);
			public void @set (int idx, Xnoise.SimpleXml.Node node);
			public int children_count { get; }
			public string? name { get; }
			public Xnoise.SimpleXml.Node? next { get; }
			public Xnoise.SimpleXml.Node? parent { get; }
			public Xnoise.SimpleXml.Node? previous { get; }
			public string? text { get; set; }
		}
		[CCode (cheader_filename = "libxnoiseutils.h")]
		public class Reader : GLib.Object {
			public Xnoise.SimpleXml.Node root;
			public Reader (GLib.File file);
			public Reader.from_string (string? xml_string);
			public void read (bool case_sensitive = true, GLib.Cancellable? cancellable = null);
			public async void read_asyn (bool case_sensitive = true, GLib.Cancellable? cancellable = null);
			public signal void finished ();
			public signal void started ();
		}
		[CCode (cheader_filename = "libxnoiseutils.h")]
		public class Writer : GLib.Object {
			public Writer (Xnoise.SimpleXml.Node root, string header_string = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
			public void write (string filename);
		}
		[CCode (cheader_filename = "libxnoiseutils.h")]
		public const string AMPERSAND_ESCAPED;
		[CCode (cheader_filename = "libxnoiseutils.h")]
		public const string APOSTROPH_ESCAPED;
		[CCode (cheader_filename = "libxnoiseutils.h")]
		public const string GREATER_THAN_ESCAPED;
		[CCode (cheader_filename = "libxnoiseutils.h")]
		public const string LOWER_THAN_ESCAPED;
		[CCode (cheader_filename = "libxnoiseutils.h")]
		public const string QUOTE_ESCAPED;
	}
}
