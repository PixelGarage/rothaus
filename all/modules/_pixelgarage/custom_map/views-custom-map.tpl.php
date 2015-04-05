<?php
/**
 * @file
 * Default view template to display markers and routes in a custom map including information about each item.
 */
?>
<div class="custom-map-container">
  <div id="<?php print $map_id; ?>" class="map custom-map <?php print $map_enabled; ?>"></div>
  <div id="custom-map-info-box" class="custom-map-info-box">
    <div class="custom-map-info-header group-info-header">
      <div class="field icon-title"><?php print $info_icon; ?></div>
      <div class="field field-name-title">
        <h2><?php print $info_title; ?></h2>
      </div>
      <div class="field field-name-field-short-description"><?php print $info_short; ?></div>
    </div>
    <div class="custom-map-info-body group-info-body">
      <div class="field field-name-body"><?php print $info_body; ?></div>
      <div class="field field-name-field-special-link"></div>
    </div>
  </div>
</div>
