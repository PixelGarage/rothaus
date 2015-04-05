<?php
/**
 * Created by PhpStorm.
 * User: ralph
 * Date: 09.12.14
 * Time: 20:25
 */

/**
 * Adds a configuration form for the custom map.
 * @param $form
 * @param $form_state
 */
function custom_map_config_form ($form, &$form_state) {
  $form['custom_map_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Import the selected content types'),
    '#tree' => true,
  );
  // Create checkboxes for content types to import
  if (module_exists('bundle_copy')) {
    $node_imports = _custom_map_get_node_imports();
    foreach ($node_imports as $node_name => $file) {
      $form['custom_map_fieldset'][$node_name] = array(
        '#type' => 'checkbox',
        '#title' => $node_name,
        '#default_value' => variable_get($node_name),
        '#return_value' => 1,
      );
    };
  } else {
    $form['custom_map_fieldset']['custom_map_error_msg'] = array(
      '#markup' => t('<p style="color: indianred">ERROR: The Drupal module "bundle_copy" is not installed! To import map node types, please install this module first.</p>'),
    );
  }

  $form['custom_map_fieldset']['custom_map_note'] = array(
    '#markup' => t('<p>The imported content types can be found in the <a href="http://localhost/admin/structure/types">Admin-Menu->Structure/Content types</a>. Use these content types to define markers and routes for the custom map.</p>' .
                   '<p>REMARK: Unchecking content types does not remove the content type from the database!</p>'),
  );
  $form['custom_map_fieldset']['custom_map_submit'] = array(
    '#type' => 'submit',
    '#value' => t('Import'),
  );

  // store node imports for later use
  $form_state['node_imports'] = $node_imports;

  return $form;
}

/**
 * Validates configuration form for the custom map.
 * @param $form
 * @param $form_state
 */
function custom_map_config_form_validate ($form, &$form_state) {
}

/**
 * Submits configuration form for the custom map.
 * @param $form
 * @param $form_state
 */
function custom_map_config_form_submit ($form, &$form_state) {
  // import the content types
  if (module_exists('bundle_copy')) {
    $node_imports = $form_state['node_imports'];
    foreach ($node_imports as $node_name => $file) {
      // save the import flag for the content type
      $value = $form_state['values']['custom_map_fieldset'][$node_name];
      variable_set($node_name, $value);

      // check if content type should be imported
      if (!$value) continue;

      // import content type
      $form_state['values']['macro'] = $file;
      bundle_copy_import_submit($form, $form_state);
    }
  }

}

/**
 * Returns an array of all available content types defined for the custom map. The associative array
 * has the content type name as key and the content type import string as value.
 *
 * @return array All available content types as import string in an associative array.
 */
function _custom_map_get_node_imports() {
  $path = drupal_get_path('module', 'custom_map') . '/imports/*.inc';
  $nodes = '';

  // build import array of all available nodes
  foreach (glob($path) as $node_filename) {
    if (($file = file_get_contents($node_filename)) !== false) {
      if (eval($file) !== false && isset($data) && is_array($data)) {

        // Create array entries.
        foreach ($data['bundles'] as $key => $bundle) {
          $node_name = '';
          if (is_object($bundle)) {
            $node_name = $bundle->name;
          }
          elseif (is_array($bundle)) {
            $node_name = $bundle['name'];
          }
          if (!empty($node_name)) {
            $nodes[$node_name] = $file;
          }
        }
      }
    }
  }
  return $nodes;
}

