<?php
/**
 * @file
 * Implements the custom map views style plugin.
 */

class views_plugin_style_custom_map extends views_plugin_style {

  /**
   * Set default options.
   */
  function option_definition() {
    $options = parent::option_definition();

    // Get default options
    $default_options = custom_map_default_options();

    // Set default values for Isotope
    foreach ($default_options as $option => $default_value) {
      $options[$option] = array(
        'default' => $default_value,
      );
      if (is_int($default_value)) {
        $options[$option]['bool'] = TRUE;
      }
      if (is_string($default_value)) {
        $options[$option]['translatable'] = TRUE;
      }
    }

    return $options;
  }

  /**
   * Includes the custom map option form into the views style form.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    // Add custom map layout options to views style form in a dedicated field set
    $form['custom_map_fieldset'] = array(
      '#type' => 'fieldset',
      '#title' => t('Custom map settings'),
    );

    // add options to form filled with saved values
    custom_map_add_options_to_form($form, $this->options);

    // Display each option field within the Isotope fieldset
    foreach (custom_map_default_options() as $option => $default_value) {
      $form[$option]['#fieldset'] = 'custom_map_fieldset';
    }

    // display help text for filter and sort usage
    $form['custom_map_help'] = array(
      '#markup' => t('<br><h2>Display of markers and routes in the map.</h2>' .
        '<p> To be done... </p><br>.'),
      '#fieldset' => 'custom_map_fieldset',
    );
  }

}

