<?php
/**
 * @file
 * Hooks provided by custom map API.
 */

/* -----------------------------------------------------------------
 *  Custom map hooks
 * ----------------------------------------------------------------- */
/**
 * Alter cusom map's style.
 *
 * @param $style  The map style to be altered.
 * @param $view The custom map view
 * @param $options  An associative array of views options and their default values.
 */
function hook_custom_map_style_alter(&$style, &$view, &$options) {
  // loads another map style
  $path = drupal_get_path('module', 'custom_map') . '/styles/alternate.json';
  if (file_exists($path) && ($file = file_get_contents($path)) !== false) {
    $style = json_decode($file);
    // sets the flag to indicate an alternate style
    $options['alt_styled'] = true;
  }
}

