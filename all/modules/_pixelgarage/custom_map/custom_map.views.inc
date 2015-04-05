<?php
/**
 * @file
 * Defines a views style plugin to add Isotope magical layouts to views.
 */

/**
 * Implements hook_views_plugins().
 */
function custom_map_views_plugins() {
  return array(
    'style' => array(
      'custom_map' => array(
        'title' => t('Custom map'),
        'handler' => 'views_plugin_style_custom_map',
        'uses options' => TRUE,
        'help' => t("Display markers and routes in a custom map."),
        'theme' => 'views_custom_map', // theme hook
        'type' => 'normal',
        'uses row plugin' => TRUE,
        'uses row class' => TRUE,
        'uses grouping' => FALSE,
      ),
    ),
  );
}

