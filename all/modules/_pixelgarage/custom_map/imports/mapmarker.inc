$data = array(
  'bundles' => array(
    'map_marker' => (object) array(
      'type' => 'map_marker',
      'name' => 'Map marker',
      'base' => 'node_content',
      'module' => 'node',
      'description' => 'Defines a custom marker. These markers can be added to the custom map.',
      'help' => '',
      'has_title' => '1',
      'title_label' => 'Title',
      'custom' => '1',
      'modified' => '1',
      'locked' => '0',
      'disabled' => '0',
      'orig_type' => 'map_marker',
      'disabled_changed' => FALSE,
      'bc_entity_type' => 'node',
    ),
  ),
  'fields' => array(
    'body' => array(
      'entity_types' => array(
        0 => 'node',
      ),
      'translatable' => '0',
      'settings' => array(),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_body' => array(
                'value' => 'body_value',
                'summary' => 'body_summary',
                'format' => 'body_format',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_body' => array(
                'value' => 'body_value',
                'summary' => 'body_summary',
                'format' => 'body_format',
              ),
            ),
          ),
        ),
      ),
      'foreign keys' => array(
        'format' => array(
          'table' => 'filter_format',
          'columns' => array(
            'format' => 'format',
          ),
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'field_name' => 'body',
      'type' => 'text_with_summary',
      'module' => 'text',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'value' => array(
          'type' => 'text',
          'size' => 'big',
          'not null' => FALSE,
        ),
        'summary' => array(
          'type' => 'text',
          'size' => 'big',
          'not null' => FALSE,
        ),
        'format' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'node' => array(
          0 => 'page',
          1 => 'article',
          2 => 'contacts',
          3 => 'room',
          4 => 'hotel',
          5 => 'map_marker',
        ),
      ),
    ),
    'field_animation' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'allowed_values' => array(
          'none' => 'None',
          'drop' => 'DROP',
          'bounce' => 'BOUNCE',
        ),
        'allowed_values_function' => '',
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_animation' => array(
                'value' => 'field_animation_value',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_animation' => array(
                'value' => 'field_animation_value',
              ),
            ),
          ),
        ),
      ),
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'field_name' => 'field_animation',
      'type' => 'list_text',
      'module' => 'list',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'value' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'node' => array(
          0 => 'map_marker',
        ),
      ),
    ),
    'field_clickable' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'allowed_values' => array(
          0 => 'No',
          1 => 'Yes',
        ),
        'allowed_values_function' => '',
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_clickable' => array(
                'value' => 'field_clickable_value',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_clickable' => array(
                'value' => 'field_clickable_value',
              ),
            ),
          ),
        ),
      ),
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'field_name' => 'field_clickable',
      'type' => 'list_boolean',
      'module' => 'list',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'value' => array(
          'type' => 'int',
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'node' => array(
          0 => 'map_marker',
        ),
      ),
    ),
    'field_icon' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'uri_scheme' => 'public',
        'default_image' => 0,
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_icon' => array(
                'fid' => 'field_icon_fid',
                'alt' => 'field_icon_alt',
                'title' => 'field_icon_title',
                'width' => 'field_icon_width',
                'height' => 'field_icon_height',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_icon' => array(
                'fid' => 'field_icon_fid',
                'alt' => 'field_icon_alt',
                'title' => 'field_icon_title',
                'width' => 'field_icon_width',
                'height' => 'field_icon_height',
              ),
            ),
          ),
        ),
      ),
      'foreign keys' => array(
        'fid' => array(
          'table' => 'file_managed',
          'columns' => array(
            'fid' => 'fid',
          ),
        ),
      ),
      'indexes' => array(
        'fid' => array(
          0 => 'fid',
        ),
      ),
      'field_name' => 'field_icon',
      'type' => 'image',
      'module' => 'image',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'fid' => array(
          'description' => 'The {file_managed}.fid being referenced in this field.',
          'type' => 'int',
          'not null' => FALSE,
          'unsigned' => TRUE,
        ),
        'alt' => array(
          'description' => 'Alternative image text, for the image\'s \'alt\' attribute.',
          'type' => 'varchar',
          'length' => 512,
          'not null' => FALSE,
        ),
        'title' => array(
          'description' => 'Image title text, for the image\'s \'title\' attribute.',
          'type' => 'varchar',
          'length' => 1024,
          'not null' => FALSE,
        ),
        'width' => array(
          'description' => 'The width of the image in pixels.',
          'type' => 'int',
          'unsigned' => TRUE,
        ),
        'height' => array(
          'description' => 'The height of the image in pixels.',
          'type' => 'int',
          'unsigned' => TRUE,
        ),
      ),
      'bundles' => array(
        'node' => array(
          0 => 'map_marker',
        ),
      ),
    ),
    'field_icon_anchor_point' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'max_length' => '100',
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_icon_anchor_point' => array(
                'value' => 'field_icon_anchor_point_value',
                'format' => 'field_icon_anchor_point_format',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_icon_anchor_point' => array(
                'value' => 'field_icon_anchor_point_value',
                'format' => 'field_icon_anchor_point_format',
              ),
            ),
          ),
        ),
      ),
      'foreign keys' => array(
        'format' => array(
          'table' => 'filter_format',
          'columns' => array(
            'format' => 'format',
          ),
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'field_name' => 'field_icon_anchor_point',
      'type' => 'text',
      'module' => 'text',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'value' => array(
          'type' => 'varchar',
          'length' => '100',
          'not null' => FALSE,
        ),
        'format' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'node' => array(
          0 => 'map_marker',
        ),
      ),
    ),
    'field_icon_hover' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'uri_scheme' => 'public',
        'default_image' => 0,
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_icon_hover' => array(
                'fid' => 'field_icon_hover_fid',
                'alt' => 'field_icon_hover_alt',
                'title' => 'field_icon_hover_title',
                'width' => 'field_icon_hover_width',
                'height' => 'field_icon_hover_height',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_icon_hover' => array(
                'fid' => 'field_icon_hover_fid',
                'alt' => 'field_icon_hover_alt',
                'title' => 'field_icon_hover_title',
                'width' => 'field_icon_hover_width',
                'height' => 'field_icon_hover_height',
              ),
            ),
          ),
        ),
      ),
      'foreign keys' => array(
        'fid' => array(
          'table' => 'file_managed',
          'columns' => array(
            'fid' => 'fid',
          ),
        ),
      ),
      'indexes' => array(
        'fid' => array(
          0 => 'fid',
        ),
      ),
      'field_name' => 'field_icon_hover',
      'type' => 'image',
      'module' => 'image',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'fid' => array(
          'description' => 'The {file_managed}.fid being referenced in this field.',
          'type' => 'int',
          'not null' => FALSE,
          'unsigned' => TRUE,
        ),
        'alt' => array(
          'description' => 'Alternative image text, for the image\'s \'alt\' attribute.',
          'type' => 'varchar',
          'length' => 512,
          'not null' => FALSE,
        ),
        'title' => array(
          'description' => 'Image title text, for the image\'s \'title\' attribute.',
          'type' => 'varchar',
          'length' => 1024,
          'not null' => FALSE,
        ),
        'width' => array(
          'description' => 'The width of the image in pixels.',
          'type' => 'int',
          'unsigned' => TRUE,
        ),
        'height' => array(
          'description' => 'The height of the image in pixels.',
          'type' => 'int',
          'unsigned' => TRUE,
        ),
      ),
      'bundles' => array(
        'node' => array(
          0 => 'map_marker',
        ),
      ),
    ),
    'field_icon_z_index' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_icon_z_index' => array(
                'value' => 'field_icon_z_index_value',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_icon_z_index' => array(
                'value' => 'field_icon_z_index_value',
              ),
            ),
          ),
        ),
      ),
      'foreign keys' => array(),
      'indexes' => array(),
      'field_name' => 'field_icon_z_index',
      'type' => 'number_integer',
      'module' => 'number',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'value' => array(
          'type' => 'int',
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'node' => array(
          0 => 'map_marker',
        ),
      ),
    ),
    'field_position' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'max_length' => '255',
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_position' => array(
                'value' => 'field_position_value',
                'format' => 'field_position_format',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_position' => array(
                'value' => 'field_position_value',
                'format' => 'field_position_format',
              ),
            ),
          ),
        ),
      ),
      'foreign keys' => array(
        'format' => array(
          'table' => 'filter_format',
          'columns' => array(
            'format' => 'format',
          ),
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'field_name' => 'field_position',
      'type' => 'text',
      'module' => 'text',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'value' => array(
          'type' => 'varchar',
          'length' => '255',
          'not null' => FALSE,
        ),
        'format' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'node' => array(
          0 => 'map_marker',
        ),
      ),
    ),
    'field_short_description' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'max_length' => '255',
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_short_description' => array(
                'value' => 'field_short_description_value',
                'format' => 'field_short_description_format',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_short_description' => array(
                'value' => 'field_short_description_value',
                'format' => 'field_short_description_format',
              ),
            ),
          ),
        ),
      ),
      'foreign keys' => array(
        'format' => array(
          'table' => 'filter_format',
          'columns' => array(
            'format' => 'format',
          ),
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'field_name' => 'field_short_description',
      'type' => 'text',
      'module' => 'text',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'value' => array(
          'type' => 'varchar',
          'length' => '255',
          'not null' => FALSE,
        ),
        'format' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'node' => array(
          0 => 'room',
          1 => 'hotel',
          2 => 'map_marker',
        ),
      ),
    ),
    'field_special_link' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'attributes' => array(
          'target' => 'default',
          'class' => '',
          'rel' => '',
        ),
        'url' => 0,
        'title' => 'optional',
        'title_value' => '',
        'title_maxlength' => 128,
        'enable_tokens' => 1,
        'display' => array(
          'url_cutoff' => 80,
        ),
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_special_link' => array(
                'url' => 'field_special_link_url',
                'title' => 'field_special_link_title',
                'attributes' => 'field_special_link_attributes',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_special_link' => array(
                'url' => 'field_special_link_url',
                'title' => 'field_special_link_title',
                'attributes' => 'field_special_link_attributes',
              ),
            ),
          ),
        ),
      ),
      'foreign keys' => array(),
      'indexes' => array(),
      'field_name' => 'field_special_link',
      'type' => 'link_field',
      'module' => 'link',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'url' => array(
          'type' => 'varchar',
          'length' => 2048,
          'not null' => FALSE,
          'sortable' => TRUE,
        ),
        'title' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => FALSE,
          'sortable' => TRUE,
        ),
        'attributes' => array(
          'type' => 'text',
          'size' => 'medium',
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'node' => array(
          0 => 'room',
          1 => 'map_marker',
        ),
      ),
    ),
    'field_title_icon' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'uri_scheme' => 'public',
        'default_image' => 0,
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_title_icon' => array(
                'fid' => 'field_title_icon_fid',
                'alt' => 'field_title_icon_alt',
                'title' => 'field_title_icon_title',
                'width' => 'field_title_icon_width',
                'height' => 'field_title_icon_height',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_title_icon' => array(
                'fid' => 'field_title_icon_fid',
                'alt' => 'field_title_icon_alt',
                'title' => 'field_title_icon_title',
                'width' => 'field_title_icon_width',
                'height' => 'field_title_icon_height',
              ),
            ),
          ),
        ),
      ),
      'foreign keys' => array(
        'fid' => array(
          'table' => 'file_managed',
          'columns' => array(
            'fid' => 'fid',
          ),
        ),
      ),
      'indexes' => array(
        'fid' => array(
          0 => 'fid',
        ),
      ),
      'field_name' => 'field_title_icon',
      'type' => 'image',
      'module' => 'image',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'fid' => array(
          'description' => 'The {file_managed}.fid being referenced in this field.',
          'type' => 'int',
          'not null' => FALSE,
          'unsigned' => TRUE,
        ),
        'alt' => array(
          'description' => 'Alternative image text, for the image\'s \'alt\' attribute.',
          'type' => 'varchar',
          'length' => 512,
          'not null' => FALSE,
        ),
        'title' => array(
          'description' => 'Image title text, for the image\'s \'title\' attribute.',
          'type' => 'varchar',
          'length' => 1024,
          'not null' => FALSE,
        ),
        'width' => array(
          'description' => 'The width of the image in pixels.',
          'type' => 'int',
          'unsigned' => TRUE,
        ),
        'height' => array(
          'description' => 'The height of the image in pixels.',
          'type' => 'int',
          'unsigned' => TRUE,
        ),
      ),
      'bundles' => array(
        'node' => array(
          0 => 'map_marker',
        ),
      ),
    ),
    'field_tour' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'display_field' => 0,
        'display_default' => 0,
        'uri_scheme' => 'public',
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_tour' => array(
                'fid' => 'field_tour_fid',
                'display' => 'field_tour_display',
                'description' => 'field_tour_description',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_tour' => array(
                'fid' => 'field_tour_fid',
                'display' => 'field_tour_display',
                'description' => 'field_tour_description',
              ),
            ),
          ),
        ),
      ),
      'foreign keys' => array(
        'fid' => array(
          'table' => 'file_managed',
          'columns' => array(
            'fid' => 'fid',
          ),
        ),
      ),
      'indexes' => array(
        'fid' => array(
          0 => 'fid',
        ),
      ),
      'field_name' => 'field_tour',
      'type' => 'file',
      'module' => 'file',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'fid' => array(
          'description' => 'The {file_managed}.fid being referenced in this field.',
          'type' => 'int',
          'not null' => FALSE,
          'unsigned' => TRUE,
        ),
        'display' => array(
          'description' => 'Flag to control whether this file should be displayed when viewing content.',
          'type' => 'int',
          'size' => 'tiny',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'default' => 1,
        ),
        'description' => array(
          'description' => 'A description of the file.',
          'type' => 'text',
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'node' => array(
          0 => 'map_marker',
        ),
      ),
    ),
  ),
  'instances' => array(
    'body' => array(
      0 => array(
        'label' => 'Description',
        'widget' => array(
          'weight' => '10',
          'type' => 'text_textarea_with_summary',
          'module' => 'text',
          'active' => 1,
          'settings' => array(
            'rows' => '20',
            'summary_rows' => 5,
          ),
        ),
        'settings' => array(
          'text_processing' => '1',
          'display_summary' => 0,
          'user_register_form' => FALSE,
        ),
        'display' => array(
          'default' => array(
            'label' => 'hidden',
            'type' => 'text_default',
            'weight' => '2',
            'settings' => array(),
            'module' => 'text',
          ),
          'teaser' => array(
            'label' => 'hidden',
            'type' => 'text_summary_or_trimmed',
            'settings' => array(
              'trim_length' => 600,
            ),
            'module' => 'text',
            'weight' => 0,
          ),
        ),
        'required' => 1,
        'description' => 'Add a description of the marker. The description is displayed in the marker description info box.',
        'default_value' => NULL,
        'field_name' => 'body',
        'entity_type' => 'node',
        'bundle' => 'map_marker',
        'deleted' => '0',
      ),
    ),
    'field_animation' => array(
      0 => array(
        'label' => 'Animation',
        'widget' => array(
          'weight' => '14',
          'type' => 'options_select',
          'module' => 'options',
          'active' => 1,
          'settings' => array(
            'apply_chosen' => '',
          ),
        ),
        'settings' => array(
          'user_register_form' => FALSE,
        ),
        'display' => array(
          'default' => array(
            'label' => 'hidden',
            'type' => 'hidden',
            'weight' => '16',
            'settings' => array(),
          ),
          'teaser' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => 'Add an animation to the marker when displayed.',
        'default_value' => NULL,
        'field_name' => 'field_animation',
        'entity_type' => 'node',
        'bundle' => 'map_marker',
        'deleted' => '0',
      ),
    ),
    'field_clickable' => array(
      0 => array(
        'label' => 'Clickable',
        'widget' => array(
          'weight' => '15',
          'type' => 'options_onoff',
          'module' => 'options',
          'active' => 1,
          'settings' => array(
            'display_label' => 0,
          ),
        ),
        'settings' => array(
          'user_register_form' => FALSE,
        ),
        'display' => array(
          'default' => array(
            'label' => 'above',
            'type' => 'list_default',
            'settings' => array(),
            'module' => 'list',
            'weight' => 22,
          ),
        ),
        'required' => 0,
        'description' => 'Select this field if the marker should react on click events.',
        'default_value' => array(
          0 => array(
            'value' => 1,
          ),
        ),
        'field_name' => 'field_clickable',
        'entity_type' => 'node',
        'bundle' => 'map_marker',
        'deleted' => '0',
      ),
    ),
    'field_icon' => array(
      0 => array(
        'label' => 'Icon',
        'widget' => array(
          'weight' => '4',
          'type' => 'image_image',
          'module' => 'image',
          'active' => 1,
          'settings' => array(
            'progress_indicator' => 'throbber',
            'preview_image_style' => 'thumbnail',
          ),
        ),
        'settings' => array(
          'file_directory' => 'markers',
          'file_extensions' => 'png gif jpg jpeg',
          'max_filesize' => '',
          'max_resolution' => '100x100',
          'min_resolution' => '',
          'alt_field' => 0,
          'title_field' => 0,
          'default_image' => 0,
          'user_register_form' => FALSE,
        ),
        'display' => array(
          'default' => array(
            'label' => 'hidden',
            'type' => 'hidden',
            'weight' => '12',
            'settings' => array(),
          ),
          'teaser' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 1,
        'description' => 'Add a custom icon for the marker.',
        'field_name' => 'field_icon',
        'entity_type' => 'node',
        'bundle' => 'map_marker',
        'deleted' => '0',
      ),
    ),
    'field_icon_anchor_point' => array(
      0 => array(
        'label' => 'Icon anchor point',
        'widget' => array(
          'weight' => '7',
          'type' => 'text_textfield',
          'module' => 'text',
          'active' => 1,
          'settings' => array(
            'size' => '60',
          ),
        ),
        'settings' => array(
          'text_processing' => '0',
          'user_register_form' => FALSE,
        ),
        'display' => array(
          'default' => array(
            'label' => 'hidden',
            'type' => 'hidden',
            'weight' => '14',
            'settings' => array(),
          ),
          'teaser' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 1,
        'description' => 'Add the icon anchor point coordinates in pixels relative to the icon coordinate system. Format is x-coord, y-coord.
Examples: Anchor point at the top left = 0, 0; Anchor point at the bottom left = 0, [icon height in pixels]',
        'default_value' => NULL,
        'field_name' => 'field_icon_anchor_point',
        'entity_type' => 'node',
        'bundle' => 'map_marker',
        'deleted' => '0',
      ),
    ),
    'field_icon_hover' => array(
      0 => array(
        'label' => 'Icon hover',
        'widget' => array(
          'weight' => '6',
          'type' => 'image_image',
          'module' => 'image',
          'active' => 1,
          'settings' => array(
            'progress_indicator' => 'throbber',
            'preview_image_style' => 'thumbnail',
          ),
        ),
        'settings' => array(
          'file_directory' => 'markers',
          'file_extensions' => 'png gif jpg jpeg',
          'max_filesize' => '',
          'max_resolution' => '',
          'min_resolution' => '',
          'alt_field' => 0,
          'title_field' => 0,
          'default_image' => 0,
          'user_register_form' => FALSE,
        ),
        'display' => array(
          'default' => array(
            'label' => 'hidden',
            'type' => 'hidden',
            'weight' => '13',
            'settings' => array(),
          ),
        ),
        'required' => 0,
        'description' => 'Add the hover icon to the marker. The hover icon uses the same anchor point than the icon itself.',
        'field_name' => 'field_icon_hover',
        'entity_type' => 'node',
        'bundle' => 'map_marker',
        'deleted' => '0',
      ),
    ),
    'field_icon_z_index' => array(
      0 => array(
        'label' => 'Icon z-index',
        'widget' => array(
          'weight' => '8',
          'type' => 'number',
          'module' => 'number',
          'active' => 0,
          'settings' => array(),
        ),
        'settings' => array(
          'min' => '',
          'max' => '',
          'prefix' => '',
          'suffix' => '',
          'user_register_form' => FALSE,
        ),
        'display' => array(
          'default' => array(
            'label' => 'hidden',
            'type' => 'hidden',
            'weight' => '15',
            'settings' => array(),
          ),
          'teaser' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => 'Add the z-index of the icon. Higher values means, the marker is displayed in front of lower indexed markers.',
        'default_value' => array(
          0 => array(
            'value' => '0',
          ),
        ),
        'field_name' => 'field_icon_z_index',
        'entity_type' => 'node',
        'bundle' => 'map_marker',
        'deleted' => '0',
      ),
    ),
    'field_position' => array(
      0 => array(
        'label' => 'Position',
        'widget' => array(
          'weight' => '3',
          'type' => 'text_textfield',
          'module' => 'text',
          'active' => 1,
          'settings' => array(
            'size' => '80',
          ),
        ),
        'settings' => array(
          'text_processing' => '0',
          'user_register_form' => FALSE,
        ),
        'display' => array(
          'default' => array(
            'label' => 'hidden',
            'type' => 'hidden',
            'weight' => '11',
            'settings' => array(),
          ),
          'teaser' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 1,
        'description' => 'Add the position of the marker on the map. Allowed values are:
Latitude/Longitude values separated by comma. Example: 47.367000, 8.543100 or
Address of the marker, e.g. Quaibrücke, Zürich',
        'default_value' => NULL,
        'field_name' => 'field_position',
        'entity_type' => 'node',
        'bundle' => 'map_marker',
        'deleted' => '0',
      ),
    ),
    'field_short_description' => array(
      0 => array(
        'label' => 'Short description',
        'widget' => array(
          'weight' => '9',
          'type' => 'text_textfield',
          'module' => 'text',
          'active' => 1,
          'settings' => array(
            'size' => '60',
          ),
        ),
        'settings' => array(
          'text_processing' => '0',
          'user_register_form' => FALSE,
        ),
        'display' => array(
          'default' => array(
            'label' => 'hidden',
            'type' => 'text_plain',
            'weight' => '1',
            'settings' => array(),
            'module' => 'text',
          ),
        ),
        'required' => 1,
        'description' => 'Add a short slogan to be displayed in the title section of the info box.',
        'default_value' => NULL,
        'field_name' => 'field_short_description',
        'entity_type' => 'node',
        'bundle' => 'map_marker',
        'deleted' => '0',
      ),
    ),
    'field_special_link' => array(
      0 => array(
        'label' => 'Special link',
        'widget' => array(
          'weight' => '11',
          'type' => 'link_field',
          'module' => 'link',
          'active' => 0,
          'settings' => array(),
        ),
        'settings' => array(
          'absolute_url' => 0,
          'validate_url' => 1,
          'url' => 0,
          'title' => 'optional',
          'title_value' => '',
          'title_label_use_field_label' => 0,
          'title_maxlength' => '128',
          'enable_tokens' => 1,
          'display' => array(
            'url_cutoff' => '80',
          ),
          'attributes' => array(
            'target' => 'default',
            'rel' => '',
            'configurable_class' => 0,
            'class' => '',
            'configurable_title' => 0,
            'title' => '',
          ),
          'rel_remove' => 'default',
          'user_register_form' => FALSE,
        ),
        'display' => array(
          'default' => array(
            'label' => 'hidden',
            'type' => 'link_default',
            'weight' => '3',
            'settings' => array(),
            'module' => 'link',
          ),
        ),
        'required' => 0,
        'description' => 'Add a special link to a Hotel room or any other special location.',
        'default_value' => NULL,
        'field_name' => 'field_special_link',
        'entity_type' => 'node',
        'bundle' => 'map_marker',
        'deleted' => '0',
      ),
    ),
    'field_title_icon' => array(
      0 => array(
        'label' => 'Title Icon',
        'widget' => array(
          'weight' => '2',
          'type' => 'image_image',
          'module' => 'image',
          'active' => 1,
          'settings' => array(
            'progress_indicator' => 'throbber',
            'preview_image_style' => 'thumbnail',
          ),
        ),
        'settings' => array(
          'file_directory' => '',
          'file_extensions' => 'png gif jpg jpeg',
          'max_filesize' => '',
          'max_resolution' => '',
          'min_resolution' => '',
          'alt_field' => 0,
          'title_field' => 0,
          'default_image' => 0,
          'user_register_form' => FALSE,
        ),
        'display' => array(
          'default' => array(
            'label' => 'above',
            'type' => 'image',
            'settings' => array(
              'image_style' => '',
              'image_link' => '',
            ),
            'module' => 'image',
            'weight' => 21,
          ),
        ),
        'required' => 0,
        'description' => 'Add an icon that is displayed in the header section of the info box.',
        'field_name' => 'field_title_icon',
        'entity_type' => 'node',
        'bundle' => 'map_marker',
        'deleted' => '0',
      ),
    ),
    'field_tour' => array(
      0 => array(
        'label' => 'Tour',
        'widget' => array(
          'weight' => '16',
          'type' => 'file_generic',
          'module' => 'file',
          'active' => 1,
          'settings' => array(
            'progress_indicator' => 'throbber',
          ),
        ),
        'settings' => array(
          'file_directory' => 'tours',
          'file_extensions' => 'kml kmz',
          'max_filesize' => '',
          'description_field' => 0,
          'user_register_form' => FALSE,
        ),
        'display' => array(
          'default' => array(
            'label' => 'above',
            'type' => 'file_default',
            'settings' => array(),
            'module' => 'file',
            'weight' => 20,
          ),
        ),
        'required' => 0,
        'description' => 'Add a city tour (polyline in .kml, .kmz format) to the marker. A .kml-file can be created and saved in Google Earth.',
        'field_name' => 'field_tour',
        'entity_type' => 'node',
        'bundle' => 'map_marker',
        'deleted' => '0',
      ),
    ),
  ),
);