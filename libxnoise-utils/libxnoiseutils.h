/* libxnoiseutils.h generated by valac 0.11.6, the Vala compiler, do not modify */


#ifndef __LIBXNOISEUTILS_H__
#define __LIBXNOISEUTILS_H__

#include <glib.h>
#include <stdlib.h>
#include <string.h>
#include <gio/gio.h>
#include <glib-object.h>

G_BEGIN_DECLS


#define XNOISE_PL_TYPE_LIST_TYPE (xnoise_pl_list_type_get_type ())

#define XNOISE_PL_TYPE_RESULT (xnoise_pl_result_get_type ())

#define XNOISE_PL_TYPE_TARGET_TYPE (xnoise_pl_target_type_get_type ())

#define XNOISE_PL_TYPE_ITEM (xnoise_pl_item_get_type ())
#define XNOISE_PL_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), XNOISE_PL_TYPE_ITEM, XnoisePlItem))
#define XNOISE_PL_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), XNOISE_PL_TYPE_ITEM, XnoisePlItemClass))
#define XNOISE_PL_IS_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), XNOISE_PL_TYPE_ITEM))
#define XNOISE_PL_IS_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), XNOISE_PL_TYPE_ITEM))
#define XNOISE_PL_ITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), XNOISE_PL_TYPE_ITEM, XnoisePlItemClass))

typedef struct _XnoisePlItem XnoisePlItem;
typedef struct _XnoisePlItemClass XnoisePlItemClass;
typedef struct _XnoisePlItemPrivate XnoisePlItemPrivate;

#define XNOISE_PL_ITEM_TYPE_FIELD (xnoise_pl_item_field_get_type ())

#define XNOISE_PL_TYPE_ITEM_COLLECTION (xnoise_pl_item_collection_get_type ())
#define XNOISE_PL_ITEM_COLLECTION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), XNOISE_PL_TYPE_ITEM_COLLECTION, XnoisePlItemCollection))
#define XNOISE_PL_ITEM_COLLECTION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), XNOISE_PL_TYPE_ITEM_COLLECTION, XnoisePlItemCollectionClass))
#define XNOISE_PL_IS_ITEM_COLLECTION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), XNOISE_PL_TYPE_ITEM_COLLECTION))
#define XNOISE_PL_IS_ITEM_COLLECTION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), XNOISE_PL_TYPE_ITEM_COLLECTION))
#define XNOISE_PL_ITEM_COLLECTION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), XNOISE_PL_TYPE_ITEM_COLLECTION, XnoisePlItemCollectionClass))

typedef struct _XnoisePlItemCollection XnoisePlItemCollection;
typedef struct _XnoisePlItemCollectionClass XnoisePlItemCollectionClass;
typedef struct _XnoisePlItemCollectionPrivate XnoisePlItemCollectionPrivate;

#define XNOISE_PL_ITEM_COLLECTION_TYPE_ITERATOR (xnoise_pl_item_collection_iterator_get_type ())
#define XNOISE_PL_ITEM_COLLECTION_ITERATOR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), XNOISE_PL_ITEM_COLLECTION_TYPE_ITERATOR, XnoisePlItemCollectionIterator))
#define XNOISE_PL_ITEM_COLLECTION_ITERATOR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), XNOISE_PL_ITEM_COLLECTION_TYPE_ITERATOR, XnoisePlItemCollectionIteratorClass))
#define XNOISE_PL_ITEM_COLLECTION_IS_ITERATOR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), XNOISE_PL_ITEM_COLLECTION_TYPE_ITERATOR))
#define XNOISE_PL_ITEM_COLLECTION_IS_ITERATOR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), XNOISE_PL_ITEM_COLLECTION_TYPE_ITERATOR))
#define XNOISE_PL_ITEM_COLLECTION_ITERATOR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), XNOISE_PL_ITEM_COLLECTION_TYPE_ITERATOR, XnoisePlItemCollectionIteratorClass))

typedef struct _XnoisePlItemCollectionIterator XnoisePlItemCollectionIterator;
typedef struct _XnoisePlItemCollectionIteratorClass XnoisePlItemCollectionIteratorClass;
typedef struct _XnoisePlItemCollectionIteratorPrivate XnoisePlItemCollectionIteratorPrivate;

#define XNOISE_PL_TYPE_READER (xnoise_pl_reader_get_type ())
#define XNOISE_PL_READER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), XNOISE_PL_TYPE_READER, XnoisePlReader))
#define XNOISE_PL_READER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), XNOISE_PL_TYPE_READER, XnoisePlReaderClass))
#define XNOISE_PL_IS_READER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), XNOISE_PL_TYPE_READER))
#define XNOISE_PL_IS_READER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), XNOISE_PL_TYPE_READER))
#define XNOISE_PL_READER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), XNOISE_PL_TYPE_READER, XnoisePlReaderClass))

typedef struct _XnoisePlReader XnoisePlReader;
typedef struct _XnoisePlReaderClass XnoisePlReaderClass;
typedef struct _XnoisePlReaderPrivate XnoisePlReaderPrivate;

#define XNOISE_SIMPLE_XML_TYPE_READER (xnoise_simple_xml_reader_get_type ())
#define XNOISE_SIMPLE_XML_READER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), XNOISE_SIMPLE_XML_TYPE_READER, XnoiseSimpleXmlReader))
#define XNOISE_SIMPLE_XML_READER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), XNOISE_SIMPLE_XML_TYPE_READER, XnoiseSimpleXmlReaderClass))
#define XNOISE_SIMPLE_XML_IS_READER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), XNOISE_SIMPLE_XML_TYPE_READER))
#define XNOISE_SIMPLE_XML_IS_READER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), XNOISE_SIMPLE_XML_TYPE_READER))
#define XNOISE_SIMPLE_XML_READER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), XNOISE_SIMPLE_XML_TYPE_READER, XnoiseSimpleXmlReaderClass))

typedef struct _XnoiseSimpleXmlReader XnoiseSimpleXmlReader;
typedef struct _XnoiseSimpleXmlReaderClass XnoiseSimpleXmlReaderClass;
typedef struct _XnoiseSimpleXmlReaderPrivate XnoiseSimpleXmlReaderPrivate;

#define XNOISE_SIMPLE_XML_TYPE_NODE (xnoise_simple_xml_node_get_type ())
#define XNOISE_SIMPLE_XML_NODE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), XNOISE_SIMPLE_XML_TYPE_NODE, XnoiseSimpleXmlNode))
#define XNOISE_SIMPLE_XML_NODE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), XNOISE_SIMPLE_XML_TYPE_NODE, XnoiseSimpleXmlNodeClass))
#define XNOISE_SIMPLE_XML_IS_NODE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), XNOISE_SIMPLE_XML_TYPE_NODE))
#define XNOISE_SIMPLE_XML_IS_NODE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), XNOISE_SIMPLE_XML_TYPE_NODE))
#define XNOISE_SIMPLE_XML_NODE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), XNOISE_SIMPLE_XML_TYPE_NODE, XnoiseSimpleXmlNodeClass))

typedef struct _XnoiseSimpleXmlNode XnoiseSimpleXmlNode;
typedef struct _XnoiseSimpleXmlNodeClass XnoiseSimpleXmlNodeClass;
typedef struct _XnoiseSimpleXmlNodePrivate XnoiseSimpleXmlNodePrivate;

#define XNOISE_SIMPLE_XML_NODE_TYPE_ATTRIBUTES (xnoise_simple_xml_node_attributes_get_type ())
#define XNOISE_SIMPLE_XML_NODE_ATTRIBUTES(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), XNOISE_SIMPLE_XML_NODE_TYPE_ATTRIBUTES, XnoiseSimpleXmlNodeAttributes))
#define XNOISE_SIMPLE_XML_NODE_ATTRIBUTES_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), XNOISE_SIMPLE_XML_NODE_TYPE_ATTRIBUTES, XnoiseSimpleXmlNodeAttributesClass))
#define XNOISE_SIMPLE_XML_NODE_IS_ATTRIBUTES(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), XNOISE_SIMPLE_XML_NODE_TYPE_ATTRIBUTES))
#define XNOISE_SIMPLE_XML_NODE_IS_ATTRIBUTES_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), XNOISE_SIMPLE_XML_NODE_TYPE_ATTRIBUTES))
#define XNOISE_SIMPLE_XML_NODE_ATTRIBUTES_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), XNOISE_SIMPLE_XML_NODE_TYPE_ATTRIBUTES, XnoiseSimpleXmlNodeAttributesClass))

typedef struct _XnoiseSimpleXmlNodeAttributes XnoiseSimpleXmlNodeAttributes;
typedef struct _XnoiseSimpleXmlNodeAttributesClass XnoiseSimpleXmlNodeAttributesClass;

#define XNOISE_SIMPLE_XML_NODE_TYPE_ITERATOR (xnoise_simple_xml_node_iterator_get_type ())
#define XNOISE_SIMPLE_XML_NODE_ITERATOR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), XNOISE_SIMPLE_XML_NODE_TYPE_ITERATOR, XnoiseSimpleXmlNodeIterator))
#define XNOISE_SIMPLE_XML_NODE_ITERATOR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), XNOISE_SIMPLE_XML_NODE_TYPE_ITERATOR, XnoiseSimpleXmlNodeIteratorClass))
#define XNOISE_SIMPLE_XML_NODE_IS_ITERATOR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), XNOISE_SIMPLE_XML_NODE_TYPE_ITERATOR))
#define XNOISE_SIMPLE_XML_NODE_IS_ITERATOR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), XNOISE_SIMPLE_XML_NODE_TYPE_ITERATOR))
#define XNOISE_SIMPLE_XML_NODE_ITERATOR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), XNOISE_SIMPLE_XML_NODE_TYPE_ITERATOR, XnoiseSimpleXmlNodeIteratorClass))

typedef struct _XnoiseSimpleXmlNodeIterator XnoiseSimpleXmlNodeIterator;
typedef struct _XnoiseSimpleXmlNodeIteratorClass XnoiseSimpleXmlNodeIteratorClass;
typedef struct _XnoiseSimpleXmlNodeAttributesPrivate XnoiseSimpleXmlNodeAttributesPrivate;

#define XNOISE_SIMPLE_XML_NODE_ATTRIBUTES_TYPE_KEYS (xnoise_simple_xml_node_attributes_keys_get_type ())
#define XNOISE_SIMPLE_XML_NODE_ATTRIBUTES_KEYS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), XNOISE_SIMPLE_XML_NODE_ATTRIBUTES_TYPE_KEYS, XnoiseSimpleXmlNodeAttributesKeys))
#define XNOISE_SIMPLE_XML_NODE_ATTRIBUTES_KEYS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), XNOISE_SIMPLE_XML_NODE_ATTRIBUTES_TYPE_KEYS, XnoiseSimpleXmlNodeAttributesKeysClass))
#define XNOISE_SIMPLE_XML_NODE_ATTRIBUTES_IS_KEYS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), XNOISE_SIMPLE_XML_NODE_ATTRIBUTES_TYPE_KEYS))
#define XNOISE_SIMPLE_XML_NODE_ATTRIBUTES_IS_KEYS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), XNOISE_SIMPLE_XML_NODE_ATTRIBUTES_TYPE_KEYS))
#define XNOISE_SIMPLE_XML_NODE_ATTRIBUTES_KEYS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), XNOISE_SIMPLE_XML_NODE_ATTRIBUTES_TYPE_KEYS, XnoiseSimpleXmlNodeAttributesKeysClass))

typedef struct _XnoiseSimpleXmlNodeAttributesKeys XnoiseSimpleXmlNodeAttributesKeys;
typedef struct _XnoiseSimpleXmlNodeAttributesKeysClass XnoiseSimpleXmlNodeAttributesKeysClass;
typedef struct _XnoiseSimpleXmlNodeAttributesKeysPrivate XnoiseSimpleXmlNodeAttributesKeysPrivate;

#define XNOISE_SIMPLE_XML_NODE_ATTRIBUTES_KEYS_TYPE_ITERATOR (xnoise_simple_xml_node_attributes_keys_iterator_get_type ())
#define XNOISE_SIMPLE_XML_NODE_ATTRIBUTES_KEYS_ITERATOR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), XNOISE_SIMPLE_XML_NODE_ATTRIBUTES_KEYS_TYPE_ITERATOR, XnoiseSimpleXmlNodeAttributesKeysIterator))
#define XNOISE_SIMPLE_XML_NODE_ATTRIBUTES_KEYS_ITERATOR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), XNOISE_SIMPLE_XML_NODE_ATTRIBUTES_KEYS_TYPE_ITERATOR, XnoiseSimpleXmlNodeAttributesKeysIteratorClass))
#define XNOISE_SIMPLE_XML_NODE_ATTRIBUTES_KEYS_IS_ITERATOR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), XNOISE_SIMPLE_XML_NODE_ATTRIBUTES_KEYS_TYPE_ITERATOR))
#define XNOISE_SIMPLE_XML_NODE_ATTRIBUTES_KEYS_IS_ITERATOR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), XNOISE_SIMPLE_XML_NODE_ATTRIBUTES_KEYS_TYPE_ITERATOR))
#define XNOISE_SIMPLE_XML_NODE_ATTRIBUTES_KEYS_ITERATOR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), XNOISE_SIMPLE_XML_NODE_ATTRIBUTES_KEYS_TYPE_ITERATOR, XnoiseSimpleXmlNodeAttributesKeysIteratorClass))

typedef struct _XnoiseSimpleXmlNodeAttributesKeysIterator XnoiseSimpleXmlNodeAttributesKeysIterator;
typedef struct _XnoiseSimpleXmlNodeAttributesKeysIteratorClass XnoiseSimpleXmlNodeAttributesKeysIteratorClass;
typedef struct _XnoiseSimpleXmlNodeAttributesKeysIteratorPrivate XnoiseSimpleXmlNodeAttributesKeysIteratorPrivate;
typedef struct _XnoiseSimpleXmlNodeIteratorPrivate XnoiseSimpleXmlNodeIteratorPrivate;

typedef enum  {
	XNOISE_PL_READER_ERROR_UNKNOWN_TYPE,
	XNOISE_PL_READER_ERROR_SOMETHING_ELSE
} XnoisePlReaderError;
#define XNOISE_PL_READER_ERROR xnoise_pl_reader_error_quark ()
typedef enum  {
	XNOISE_PL_LIST_TYPE_UNKNOWN = 0,
	XNOISE_PL_LIST_TYPE_IGNORED,
	XNOISE_PL_LIST_TYPE_M3U,
	XNOISE_PL_LIST_TYPE_PLS,
	XNOISE_PL_LIST_TYPE_ASX,
	XNOISE_PL_LIST_TYPE_XSPF,
	XNOISE_PL_LIST_TYPE_WPL
} XnoisePlListType;

typedef enum  {
	XNOISE_PL_RESULT_UNHANDLED = 0,
	XNOISE_PL_RESULT_ERROR,
	XNOISE_PL_RESULT_IGNORED,
	XNOISE_PL_RESULT_SUCCESS,
	XNOISE_PL_RESULT_EMPTY,
	XNOISE_PL_RESULT_DOUBLE_WRITE
} XnoisePlResult;

typedef enum  {
	XNOISE_PL_TARGET_TYPE_URI,
	XNOISE_PL_TARGET_TYPE_REL_PATH,
	XNOISE_PL_TARGET_TYPE_ABS_PATH
} XnoisePlTargetType;

struct _XnoisePlItem {
	GTypeInstance parent_instance;
	volatile int ref_count;
	XnoisePlItemPrivate * priv;
};

struct _XnoisePlItemClass {
	GTypeClass parent_class;
	void (*finalize) (XnoisePlItem *self);
};

typedef enum  {
	XNOISE_PL_ITEM_FIELD_URI = 0,
	XNOISE_PL_ITEM_FIELD_TITLE,
	XNOISE_PL_ITEM_FIELD_AUTHOR,
	XNOISE_PL_ITEM_FIELD_GENRE,
	XNOISE_PL_ITEM_FIELD_ALBUM,
	XNOISE_PL_ITEM_FIELD_COPYRIGHT,
	XNOISE_PL_ITEM_FIELD_DURATION,
	XNOISE_PL_ITEM_FIELD_PARAM_NAME,
	XNOISE_PL_ITEM_FIELD_PARAM_VALUE,
	XNOISE_PL_ITEM_FIELD_IS_REMOTE,
	XNOISE_PL_ITEM_FIELD_IS_PLAYLIST
} XnoisePlItemField;

struct _XnoisePlItemCollection {
	GTypeInstance parent_instance;
	volatile int ref_count;
	XnoisePlItemCollectionPrivate * priv;
};

struct _XnoisePlItemCollectionClass {
	GTypeClass parent_class;
	void (*finalize) (XnoisePlItemCollection *self);
};

struct _XnoisePlItemCollectionIterator {
	GTypeInstance parent_instance;
	volatile int ref_count;
	XnoisePlItemCollectionIteratorPrivate * priv;
};

struct _XnoisePlItemCollectionIteratorClass {
	GTypeClass parent_class;
	void (*finalize) (XnoisePlItemCollectionIterator *self);
};

struct _XnoisePlReader {
	GObject parent_instance;
	XnoisePlReaderPrivate * priv;
};

struct _XnoisePlReaderClass {
	GObjectClass parent_class;
};

struct _XnoiseSimpleXmlReader {
	GObject parent_instance;
	XnoiseSimpleXmlReaderPrivate * priv;
	XnoiseSimpleXmlNode* root;
};

struct _XnoiseSimpleXmlReaderClass {
	GObjectClass parent_class;
};

struct _XnoiseSimpleXmlNode {
	GTypeInstance parent_instance;
	volatile int ref_count;
	XnoiseSimpleXmlNodePrivate * priv;
	XnoiseSimpleXmlNodeAttributes* attributes;
};

struct _XnoiseSimpleXmlNodeClass {
	GTypeClass parent_class;
	void (*finalize) (XnoiseSimpleXmlNode *self);
};

struct _XnoiseSimpleXmlNodeAttributes {
	GTypeInstance parent_instance;
	volatile int ref_count;
	XnoiseSimpleXmlNodeAttributesPrivate * priv;
	XnoiseSimpleXmlNodeAttributesKeys* keys;
};

struct _XnoiseSimpleXmlNodeAttributesClass {
	GTypeClass parent_class;
	void (*finalize) (XnoiseSimpleXmlNodeAttributes *self);
};

struct _XnoiseSimpleXmlNodeAttributesKeys {
	GTypeInstance parent_instance;
	volatile int ref_count;
	XnoiseSimpleXmlNodeAttributesKeysPrivate * priv;
};

struct _XnoiseSimpleXmlNodeAttributesKeysClass {
	GTypeClass parent_class;
	void (*finalize) (XnoiseSimpleXmlNodeAttributesKeys *self);
};

struct _XnoiseSimpleXmlNodeAttributesKeysIterator {
	GTypeInstance parent_instance;
	volatile int ref_count;
	XnoiseSimpleXmlNodeAttributesKeysIteratorPrivate * priv;
};

struct _XnoiseSimpleXmlNodeAttributesKeysIteratorClass {
	GTypeClass parent_class;
	void (*finalize) (XnoiseSimpleXmlNodeAttributesKeysIterator *self);
};

struct _XnoiseSimpleXmlNodeIterator {
	GTypeInstance parent_instance;
	volatile int ref_count;
	XnoiseSimpleXmlNodeIteratorPrivate * priv;
};

struct _XnoiseSimpleXmlNodeIteratorClass {
	GTypeClass parent_class;
	void (*finalize) (XnoiseSimpleXmlNodeIterator *self);
};


GQuark xnoise_pl_reader_error_quark (void);
GType xnoise_pl_list_type_get_type (void) G_GNUC_CONST;
GType xnoise_pl_result_get_type (void) G_GNUC_CONST;
GType xnoise_pl_target_type_get_type (void) G_GNUC_CONST;
extern gboolean xnoise_pl_debug;
gboolean xnoise_pl_is_known_playlist_extension (gchar** ext);
gchar* xnoise_pl_get_extension (GFile* f);
gpointer xnoise_pl_item_ref (gpointer instance);
void xnoise_pl_item_unref (gpointer instance);
GParamSpec* xnoise_pl_param_spec_item (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void xnoise_pl_value_set_item (GValue* value, gpointer v_object);
void xnoise_pl_value_take_item (GValue* value, gpointer v_object);
gpointer xnoise_pl_value_get_item (const GValue* value);
GType xnoise_pl_item_get_type (void) G_GNUC_CONST;
GType xnoise_pl_item_field_get_type (void) G_GNUC_CONST;
XnoisePlItem* xnoise_pl_item_new (void);
XnoisePlItem* xnoise_pl_item_construct (GType object_type);
void xnoise_pl_item_add_field (XnoisePlItem* self, XnoisePlItemField field, const gchar* val);
XnoisePlItemField* xnoise_pl_item_get_contained_fields (XnoisePlItem* self, int* result_length1);
gchar* xnoise_pl_item_get_field (XnoisePlItem* self, XnoisePlItemField field);
gchar* xnoise_pl_item_get_uri (XnoisePlItem* self);
gchar* xnoise_pl_item_get_rel_path (XnoisePlItem* self);
gchar* xnoise_pl_item_get_abs_path (XnoisePlItem* self);
gchar* xnoise_pl_item_get_title (XnoisePlItem* self);
gchar* xnoise_pl_item_get_author (XnoisePlItem* self);
gchar* xnoise_pl_item_get_genre (XnoisePlItem* self);
gchar* xnoise_pl_item_get_album (XnoisePlItem* self);
gchar* xnoise_pl_item_get_copyright (XnoisePlItem* self);
gchar* xnoise_pl_item_get_duration_string (XnoisePlItem* self);
gchar* xnoise_pl_item_get_param_name (XnoisePlItem* self);
gchar* xnoise_pl_item_get_param_value (XnoisePlItem* self);
glong xnoise_pl_item_get_duration (XnoisePlItem* self);
gboolean xnoise_pl_item_is_remote (XnoisePlItem* self);
gboolean xnoise_pl_item_is_playlist (XnoisePlItem* self);
XnoisePlTargetType xnoise_pl_item_get_target_type (XnoisePlItem* self);
void xnoise_pl_item_set_target_type (XnoisePlItem* self, XnoisePlTargetType value);
const gchar* xnoise_pl_item_get_base_path (XnoisePlItem* self);
void xnoise_pl_item_set_base_path (XnoisePlItem* self, const gchar* value);
gpointer xnoise_pl_item_collection_ref (gpointer instance);
void xnoise_pl_item_collection_unref (gpointer instance);
GParamSpec* xnoise_pl_param_spec_item_collection (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void xnoise_pl_value_set_item_collection (GValue* value, gpointer v_object);
void xnoise_pl_value_take_item_collection (GValue* value, gpointer v_object);
gpointer xnoise_pl_value_get_item_collection (const GValue* value);
GType xnoise_pl_item_collection_get_type (void) G_GNUC_CONST;
XnoisePlItemCollection* xnoise_pl_item_collection_new (void);
XnoisePlItemCollection* xnoise_pl_item_collection_construct (GType object_type);
gint xnoise_pl_item_collection_get_size (XnoisePlItemCollection* self);
void xnoise_pl_item_collection_add_general_info (XnoisePlItemCollection* self, const gchar* key, const gchar* val);
gchar** xnoise_pl_item_collection_get_general_info_keys (XnoisePlItemCollection* self, int* result_length1);
gchar* xnoise_pl_item_collection_get_general_info (XnoisePlItemCollection* self, const gchar* key);
gboolean xnoise_pl_item_collection_data_available (XnoisePlItemCollection* self);
gchar** xnoise_pl_item_collection_get_found_uris (XnoisePlItemCollection* self, int* result_length1);
gchar* xnoise_pl_item_collection_get_title_for_uri (XnoisePlItemCollection* self, gchar** uri_needle);
gchar* xnoise_pl_item_collection_get_author_for_uri (XnoisePlItemCollection* self, gchar** uri_needle);
gchar* xnoise_pl_item_collection_get_genre_for_uri (XnoisePlItemCollection* self, gchar** uri_needle);
gchar* xnoise_pl_item_collection_get_album_for_uri (XnoisePlItemCollection* self, gchar** uri_needle);
gchar* xnoise_pl_item_collection_get_copyright_for_uri (XnoisePlItemCollection* self, gchar** uri_needle);
gchar* xnoise_pl_item_collection_get_duration_string_for_uri (XnoisePlItemCollection* self, gchar** uri_needle);
glong xnoise_pl_item_collection_get_duration_for_uri (XnoisePlItemCollection* self, gchar** uri_needle);
gchar* xnoise_pl_item_collection_get_param_name_for_uri (XnoisePlItemCollection* self, gchar** uri_needle);
gchar* xnoise_pl_item_collection_get_param_value_for_uri (XnoisePlItemCollection* self, gchar** uri_needle);
gboolean xnoise_pl_item_collection_get_is_remote_for_uri (XnoisePlItemCollection* self, gchar** uri_needle);
gboolean xnoise_pl_item_collection_get_is_playlist_for_uri (XnoisePlItemCollection* self, gchar** uri_needle);
gint xnoise_pl_item_collection_get_number_of_entries (XnoisePlItemCollection* self);
gboolean xnoise_pl_item_collection_contains (XnoisePlItemCollection* self, XnoisePlItem* d);
gboolean xnoise_pl_item_collection_contains_field (XnoisePlItemCollection* self, XnoisePlItemField field, const gchar* value);
XnoisePlItemField* xnoise_pl_item_collection_get_contained_fields_for_idx (XnoisePlItemCollection* self, gint idx, int* result_length1);
XnoisePlItemField* xnoise_pl_item_collection_get_contained_fields_for_uri (XnoisePlItemCollection* self, gchar** uri, int* result_length1);
gpointer xnoise_pl_item_collection_iterator_ref (gpointer instance);
void xnoise_pl_item_collection_iterator_unref (gpointer instance);
GParamSpec* xnoise_pl_item_collection_param_spec_iterator (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void xnoise_pl_item_collection_value_set_iterator (GValue* value, gpointer v_object);
void xnoise_pl_item_collection_value_take_iterator (GValue* value, gpointer v_object);
gpointer xnoise_pl_item_collection_value_get_iterator (const GValue* value);
GType xnoise_pl_item_collection_iterator_get_type (void) G_GNUC_CONST;
XnoisePlItemCollectionIterator* xnoise_pl_item_collection_iterator (XnoisePlItemCollection* self);
gint xnoise_pl_item_collection_index_of (XnoisePlItemCollection* self, XnoisePlItem* d);
XnoisePlItem* xnoise_pl_item_collection_get (XnoisePlItemCollection* self, gint index);
void xnoise_pl_item_collection_set (XnoisePlItemCollection* self, gint index, XnoisePlItem* item);
gboolean xnoise_pl_item_collection_append (XnoisePlItemCollection* self, XnoisePlItem* item);
void xnoise_pl_item_collection_insert (XnoisePlItemCollection* self, gint index, XnoisePlItem* item);
gboolean xnoise_pl_item_collection_remove (XnoisePlItemCollection* self, XnoisePlItem* item);
XnoisePlItem* xnoise_pl_item_collection_remove_at (XnoisePlItemCollection* self, gint index);
void xnoise_pl_item_collection_clear (XnoisePlItemCollection* self);
void xnoise_pl_item_collection_merge (XnoisePlItemCollection* self, XnoisePlItemCollection* data_collection);
XnoisePlItemCollectionIterator* xnoise_pl_item_collection_iterator_new (XnoisePlItemCollection* dc);
XnoisePlItemCollectionIterator* xnoise_pl_item_collection_iterator_construct (GType object_type, XnoisePlItemCollection* dc);
gboolean xnoise_pl_item_collection_iterator_next (XnoisePlItemCollectionIterator* self);
gboolean xnoise_pl_item_collection_iterator_first (XnoisePlItemCollectionIterator* self);
XnoisePlItem* xnoise_pl_item_collection_iterator_get (XnoisePlItemCollectionIterator* self);
void xnoise_pl_item_collection_iterator_remove (XnoisePlItemCollectionIterator* self);
gboolean xnoise_pl_item_collection_iterator_previous (XnoisePlItemCollectionIterator* self);
gboolean xnoise_pl_item_collection_iterator_has_previous (XnoisePlItemCollectionIterator* self);
void xnoise_pl_item_collection_iterator_set (XnoisePlItemCollectionIterator* self, XnoisePlItem* item);
void xnoise_pl_item_collection_iterator_insert (XnoisePlItemCollectionIterator* self, XnoisePlItem* item);
void xnoise_pl_item_collection_iterator_append (XnoisePlItemCollectionIterator* self, XnoisePlItem* item);
gint xnoise_pl_item_collection_iterator_index (XnoisePlItemCollectionIterator* self);
GType xnoise_pl_reader_get_type (void) G_GNUC_CONST;
XnoisePlReader* xnoise_pl_reader_new (void);
XnoisePlReader* xnoise_pl_reader_construct (GType object_type);
XnoisePlResult xnoise_pl_reader_read (XnoisePlReader* self, const gchar* list_uri, GCancellable* cancellable, GError** error);
void xnoise_pl_reader_read_asyn (XnoisePlReader* self, const gchar* list_uri, GCancellable* cancellable, GAsyncReadyCallback _callback_, gpointer _user_data_);
XnoisePlResult xnoise_pl_reader_read_asyn_finish (XnoisePlReader* self, GAsyncResult* _res_, GError** error);
gboolean xnoise_pl_reader_data_available (XnoisePlReader* self);
gint xnoise_pl_reader_get_number_of_entries (XnoisePlReader* self);
gchar** xnoise_pl_reader_get_found_uris (XnoisePlReader* self, int* result_length1);
gchar* xnoise_pl_reader_get_title_for_uri (XnoisePlReader* self, gchar** uri_needle);
gchar* xnoise_pl_reader_get_author_for_uri (XnoisePlReader* self, gchar** uri_needle);
gchar* xnoise_pl_reader_get_genre_for_uri (XnoisePlReader* self, gchar** uri_needle);
gchar* xnoise_pl_reader_get_album_for_uri (XnoisePlReader* self, gchar** uri_needle);
gchar* xnoise_pl_reader_get_copyright_for_uri (XnoisePlReader* self, gchar** uri_needle);
gchar* xnoise_pl_reader_get_duration_string_for_uri (XnoisePlReader* self, gchar** uri_needle);
glong xnoise_pl_reader_get_duration_for_uri (XnoisePlReader* self, gchar** uri_needle);
gboolean xnoise_pl_reader_get_is_remote_for_uri (XnoisePlReader* self, gchar** uri_needle);
gboolean xnoise_pl_reader_get_is_playlist_for_uri (XnoisePlReader* self, gchar** uri_needle);
XnoisePlListType xnoise_pl_reader_get_ptype (XnoisePlReader* self);
const gchar* xnoise_pl_reader_get_playlist_uri (XnoisePlReader* self);
XnoisePlItemCollection* xnoise_pl_reader_get_data_collection (XnoisePlReader* self);
XnoisePlListType xnoise_pl_get_playlist_type_for_uri (gchar** uri_);
XnoisePlListType xnoise_pl_get_type_by_extension (gchar** uri_);
XnoisePlListType xnoise_pl_get_type_by_data (gchar** uri_);
glong xnoise_pl_get_duration_from_string (gchar** duration_string);
GFile* xnoise_pl_get_file_for_location (const gchar* adr, gchar** base_path, XnoisePlTargetType* tt);
#define XNOISE_SIMPLE_XML_AMPERSAND_ESCAPED "&amp;"
#define XNOISE_SIMPLE_XML_GREATER_THAN_ESCAPED "&gt;"
#define XNOISE_SIMPLE_XML_LOWER_THAN_ESCAPED "&lt;"
#define XNOISE_SIMPLE_XML_QUOTE_ESCAPED "&quot;"
#define XNOISE_SIMPLE_XML_APOSTROPH_ESCAPED "&apos;"
GType xnoise_simple_xml_reader_get_type (void) G_GNUC_CONST;
gpointer xnoise_simple_xml_node_ref (gpointer instance);
void xnoise_simple_xml_node_unref (gpointer instance);
GParamSpec* xnoise_simple_xml_param_spec_node (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void xnoise_simple_xml_value_set_node (GValue* value, gpointer v_object);
void xnoise_simple_xml_value_take_node (GValue* value, gpointer v_object);
gpointer xnoise_simple_xml_value_get_node (const GValue* value);
GType xnoise_simple_xml_node_get_type (void) G_GNUC_CONST;
XnoiseSimpleXmlReader* xnoise_simple_xml_reader_new (GFile* file);
XnoiseSimpleXmlReader* xnoise_simple_xml_reader_construct (GType object_type, GFile* file);
XnoiseSimpleXmlReader* xnoise_simple_xml_reader_new_from_string (const gchar* xml_string);
XnoiseSimpleXmlReader* xnoise_simple_xml_reader_construct_from_string (GType object_type, const gchar* xml_string);
void xnoise_simple_xml_reader_read (XnoiseSimpleXmlReader* self, gboolean case_sensitive, GCancellable* cancellable);
void xnoise_simple_xml_reader_read_asyn (XnoiseSimpleXmlReader* self, gboolean case_sensitive, GCancellable* cancellable, GAsyncReadyCallback _callback_, gpointer _user_data_);
void xnoise_simple_xml_reader_read_asyn_finish (XnoiseSimpleXmlReader* self, GAsyncResult* _res_);
gpointer xnoise_simple_xml_node_attributes_ref (gpointer instance);
void xnoise_simple_xml_node_attributes_unref (gpointer instance);
GParamSpec* xnoise_simple_xml_node_param_spec_attributes (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void xnoise_simple_xml_node_value_set_attributes (GValue* value, gpointer v_object);
void xnoise_simple_xml_node_value_take_attributes (GValue* value, gpointer v_object);
gpointer xnoise_simple_xml_node_value_get_attributes (const GValue* value);
GType xnoise_simple_xml_node_attributes_get_type (void) G_GNUC_CONST;
XnoiseSimpleXmlNode* xnoise_simple_xml_node_new (const gchar* name);
XnoiseSimpleXmlNode* xnoise_simple_xml_node_construct (GType object_type, const gchar* name);
gboolean xnoise_simple_xml_node_has_text (XnoiseSimpleXmlNode* self);
gboolean xnoise_simple_xml_node_has_children (XnoiseSimpleXmlNode* self);
gboolean xnoise_simple_xml_node_has_attributes (XnoiseSimpleXmlNode* self);
void xnoise_simple_xml_node_prepend_child (XnoiseSimpleXmlNode* self, XnoiseSimpleXmlNode* node);
void xnoise_simple_xml_node_append_child (XnoiseSimpleXmlNode* self, XnoiseSimpleXmlNode* node);
void xnoise_simple_xml_node_insert_child (XnoiseSimpleXmlNode* self, gint pos, XnoiseSimpleXmlNode* node);
XnoiseSimpleXmlNode* xnoise_simple_xml_node_get_child_by_name (XnoiseSimpleXmlNode* self, const gchar* childname);
XnoiseSimpleXmlNode** xnoise_simple_xml_node_get_children_by_name (XnoiseSimpleXmlNode* self, const gchar* childname, int* result_length1);
gint xnoise_simple_xml_node_get_idx_of_child (XnoiseSimpleXmlNode* self, XnoiseSimpleXmlNode* node);
XnoiseSimpleXmlNode* xnoise_simple_xml_node_get (XnoiseSimpleXmlNode* self, gint idx);
void xnoise_simple_xml_node_set (XnoiseSimpleXmlNode* self, gint idx, XnoiseSimpleXmlNode* node);
gboolean xnoise_simple_xml_node_remove_child (XnoiseSimpleXmlNode* self, XnoiseSimpleXmlNode* node);
gboolean xnoise_simple_xml_node_remove_child_at_idx (XnoiseSimpleXmlNode* self, gint idx);
void xnoise_simple_xml_node_clear (XnoiseSimpleXmlNode* self);
gpointer xnoise_simple_xml_node_iterator_ref (gpointer instance);
void xnoise_simple_xml_node_iterator_unref (gpointer instance);
GParamSpec* xnoise_simple_xml_node_param_spec_iterator (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void xnoise_simple_xml_node_value_set_iterator (GValue* value, gpointer v_object);
void xnoise_simple_xml_node_value_take_iterator (GValue* value, gpointer v_object);
gpointer xnoise_simple_xml_node_value_get_iterator (const GValue* value);
GType xnoise_simple_xml_node_iterator_get_type (void) G_GNUC_CONST;
XnoiseSimpleXmlNodeIterator* xnoise_simple_xml_node_iterator (XnoiseSimpleXmlNode* self);
const gchar* xnoise_simple_xml_node_get_text (XnoiseSimpleXmlNode* self);
void xnoise_simple_xml_node_set_text (XnoiseSimpleXmlNode* self, const gchar* value);
const gchar* xnoise_simple_xml_node_get_name (XnoiseSimpleXmlNode* self);
XnoiseSimpleXmlNode* xnoise_simple_xml_node_get_parent (XnoiseSimpleXmlNode* self);
XnoiseSimpleXmlNode* xnoise_simple_xml_node_get_previous (XnoiseSimpleXmlNode* self);
XnoiseSimpleXmlNode* xnoise_simple_xml_node_get_next (XnoiseSimpleXmlNode* self);
gint xnoise_simple_xml_node_get_children_count (XnoiseSimpleXmlNode* self);
gpointer xnoise_simple_xml_node_attributes_keys_ref (gpointer instance);
void xnoise_simple_xml_node_attributes_keys_unref (gpointer instance);
GParamSpec* xnoise_simple_xml_node_attributes_param_spec_keys (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void xnoise_simple_xml_node_attributes_value_set_keys (GValue* value, gpointer v_object);
void xnoise_simple_xml_node_attributes_value_take_keys (GValue* value, gpointer v_object);
gpointer xnoise_simple_xml_node_attributes_value_get_keys (const GValue* value);
GType xnoise_simple_xml_node_attributes_keys_get_type (void) G_GNUC_CONST;
XnoiseSimpleXmlNodeAttributes* xnoise_simple_xml_node_attributes_new (void);
XnoiseSimpleXmlNodeAttributes* xnoise_simple_xml_node_attributes_construct (GType object_type);
void xnoise_simple_xml_node_attributes_add (XnoiseSimpleXmlNodeAttributes* self, const gchar* key, const gchar* val);
void xnoise_simple_xml_node_attributes_replace (XnoiseSimpleXmlNodeAttributes* self, const gchar* key, const gchar* val);
void xnoise_simple_xml_node_attributes_remove (XnoiseSimpleXmlNodeAttributes* self, const gchar* key);
void xnoise_simple_xml_node_attributes_clear (XnoiseSimpleXmlNodeAttributes* self);
gchar* xnoise_simple_xml_node_attributes_get (XnoiseSimpleXmlNodeAttributes* self, const gchar* key);
void xnoise_simple_xml_node_attributes_set (XnoiseSimpleXmlNodeAttributes* self, const gchar* key, const gchar* val);
gint xnoise_simple_xml_node_attributes_get_item_count (XnoiseSimpleXmlNodeAttributes* self);
GList* xnoise_simple_xml_node_attributes_get_key_list (XnoiseSimpleXmlNodeAttributes* self);
GList* xnoise_simple_xml_node_attributes_get_value_list (XnoiseSimpleXmlNodeAttributes* self);
XnoiseSimpleXmlNodeAttributesKeys* xnoise_simple_xml_node_attributes_keys_new (XnoiseSimpleXmlNodeAttributes* _attrib);
XnoiseSimpleXmlNodeAttributesKeys* xnoise_simple_xml_node_attributes_keys_construct (GType object_type, XnoiseSimpleXmlNodeAttributes* _attrib);
gboolean xnoise_simple_xml_node_attributes_keys_contains (XnoiseSimpleXmlNodeAttributesKeys* self, const gchar* needle_key);
gpointer xnoise_simple_xml_node_attributes_keys_iterator_ref (gpointer instance);
void xnoise_simple_xml_node_attributes_keys_iterator_unref (gpointer instance);
GParamSpec* xnoise_simple_xml_node_attributes_keys_param_spec_iterator (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void xnoise_simple_xml_node_attributes_keys_value_set_iterator (GValue* value, gpointer v_object);
void xnoise_simple_xml_node_attributes_keys_value_take_iterator (GValue* value, gpointer v_object);
gpointer xnoise_simple_xml_node_attributes_keys_value_get_iterator (const GValue* value);
GType xnoise_simple_xml_node_attributes_keys_iterator_get_type (void) G_GNUC_CONST;
XnoiseSimpleXmlNodeAttributesKeysIterator* xnoise_simple_xml_node_attributes_keys_iterator (XnoiseSimpleXmlNodeAttributesKeys* self);
XnoiseSimpleXmlNodeAttributesKeysIterator* xnoise_simple_xml_node_attributes_keys_iterator_new (XnoiseSimpleXmlNodeAttributes* _iter_attib);
XnoiseSimpleXmlNodeAttributesKeysIterator* xnoise_simple_xml_node_attributes_keys_iterator_construct (GType object_type, XnoiseSimpleXmlNodeAttributes* _iter_attib);
gboolean xnoise_simple_xml_node_attributes_keys_iterator_next (XnoiseSimpleXmlNodeAttributesKeysIterator* self);
gchar* xnoise_simple_xml_node_attributes_keys_iterator_get (XnoiseSimpleXmlNodeAttributesKeysIterator* self);
XnoiseSimpleXmlNodeIterator* xnoise_simple_xml_node_iterator_new (XnoiseSimpleXmlNode* parent_node);
XnoiseSimpleXmlNodeIterator* xnoise_simple_xml_node_iterator_construct (GType object_type, XnoiseSimpleXmlNode* parent_node);
gboolean xnoise_simple_xml_node_iterator_next (XnoiseSimpleXmlNodeIterator* self);
XnoiseSimpleXmlNode* xnoise_simple_xml_node_iterator_get (XnoiseSimpleXmlNodeIterator* self);
void xnoise_simple_xml_node_iterator_set (XnoiseSimpleXmlNodeIterator* self, XnoiseSimpleXmlNode* node);

extern const gchar* XNOISE_PL_known_playlist_extensions[5];
extern const gchar* XNOISE_PL_remote_schemes[2];

G_END_DECLS

#endif
