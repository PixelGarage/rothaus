/**
 * Created by ralph on 02.12.14.
 */

(function($) {

    /* Holds all active markers in the map */
    var mapMarkers = [];

    /**
     * Add all markers to the custom map.
     * @param map
     * @param locations
     */
    function createMapMarker(map, marker, altStyled) {
        var $infoBox = $('.view-custom-map .custom-map-info-box'),
            position = new google.maps.LatLng(marker.position.lat, marker.position.lng),
            animation = marker.animation == 'DROP' ? google.maps.Animation.DROP : marker.animation == 'BOUNCE' ? google.maps.Animation.BOUNCE : null;

        var shape = {
            coords: [0, 0, marker.icon.width, marker.icon.height],
            type: 'rect'
        };

        // Origins, anchor positions and coordinates of the marker
        // increase in the X direction to the right and in
        // the Y direction down.
        var icon = {
                url: marker.icon.url,
                size: new google.maps.Size(marker.icon.width, marker.icon.height),
                origin: new google.maps.Point(0,0),
                anchor: new google.maps.Point(marker.anchor.x, marker.anchor.y)
            };

        if (altStyled && marker.iconNight.hasOwnProperty('url')) {
            icon.url = marker.iconNight.url;
            icon.size = new google.maps.Size(marker.iconNight.width, marker.iconNight.height);
        }
        var iconHover = {
                origin: new google.maps.Point(0,0),
                anchor: new google.maps.Point(marker.anchor.x, marker.anchor.y)
            };
        if (marker.iconHover.hasOwnProperty('url')) {
            iconHover.url = marker.iconHover.url;
            iconHover.size = new google.maps.Size(marker.iconHover.width, marker.iconHover.height);
        } else {
            iconHover.url = marker.icon.url;
            iconHover.size = new google.maps.Size(marker.icon.width, marker.icon.height);
        }

        // create the marker
        var mapMarker = new google.maps.Marker({
            position: position,
            map: map,
            title: marker.title,
            icon: icon,
            shape: shape,
            zIndex: marker.zIndex,
            animation: animation,
            clickable: marker.clickable,
            draggable: false,
            opacity: 1.0,
            visible: true,
            cursor: 'pointer'
        });
        //mapMarkers[i] = mapMarker;

        // create tour if any
        if (marker.hasOwnProperty('tour') && marker.tour !== '') {
            var kmlLayer = new google.maps.KmlLayer({
                map: map,
                url: marker.tour,
                preserveViewport: true,
                suppressInfoWindows: false,
                zIndex: marker.zIndex
            });
        }

        // add events to map marker
        google.maps.event.addListener(mapMarker, 'click', function() {
            // add marker info to info box
            var $infoBoxIcon = $infoBox.find('.icon-title');
            $infoBoxIcon.html('').css('padding', '0');
            if (marker.iconTitle.hasOwnProperty('url')) {
                var iconTitle = '<img src="%1" width="%2px" height="%3px"/>'.replace('%1', marker.iconTitle.url).replace('%2', marker.iconTitle.width).replace('%3', marker.iconTitle.height);
                $infoBoxIcon.html(iconTitle).css('padding', '');
            }
            var $infoBoxTitle = $infoBox.find('.field-name-title h2');
            $infoBoxTitle.html(marker.title);
            var $infoBoxShort = $infoBox.find('.field-name-field-short-description');
            $infoBoxShort.html(marker.short);
            var $infoBoxBody = $infoBox.find('.custom-map-info-body');
            $infoBoxBody.find('.field-name-body').html(marker.body);
            $infoBoxBody.find('.field-name-field-special-link').html(marker.specialLink);

            // show info body on marker click
            if (!$infoBox.hasClass('info-visible')) {
                $infoBox.click();
            }
        });
        google.maps.event.addListener(mapMarker, 'dblclick', function() {
            // toggle info box
            $infoBox.click();
        });
        google.maps.event.addListener(mapMarker, 'mouseover', function() {
            // display hover icon of marker
            mapMarker.setIcon(iconHover);
        });
        google.maps.event.addListener(mapMarker, 'mouseout', function() {
            // display marker icon
            mapMarker.setIcon(icon);
        });
    }

    /**
     * Remove all markers from the custom map.
     */
    function removeMapMarkers() {
        // Remove map markers from the map
        for (var i = 0; i < mapMarkers.length; i++) {
            var mapMarker = mapMarkers[i];
            mapMarker.setMap(null);
            google.maps.event.clearListeners(mapMarker);
        }
    }


    /**
     * This behavior adds a custom map to defined containers and initializes it with the given settings.
     * The behavior is supported in IE 10+ (uses transitions), Chrome, Firefox, Safari and Opera.
     *
     * @type {{attach: Function}}
     */
    Drupal.behaviors.customMap =  {
        attach: function(context, settings) {

            // Iterate through all custom map instances
            $.each(Drupal.settings.custom_map, function (map_id, options) {
                // Set container with class 'isotope'
                var map,
                    mapElement = document.getElementById(map_id),
                    mapDisabled = false,
                    _resizeMap = function() {
                        // resize only initialized maps
                        if (typeof(map) !== "object") return;

                        // resize the map
                        var center = map.getCenter();
                        google.maps.event.trigger(map, "resize");
                        map.setCenter(center);
                    },
                    _disableMap = function() {
                        // disable only initialized maps
                        if (typeof(map) !== "object") return;

                        // disable map for mouse and keyboard interactions
                        map.setOptions({draggable: false, zoomControl: false, scrollwheel: false, keyboardShortcuts: false, disableDoubleClickZoom: true});
                        mapDisabled = true;
                    },
                    _enableMap = function() {
                        // enable only initialized maps
                        if (typeof(map) !== "object") return;

                        // enable map for mouse and keyboard interactions
                        map.setOptions({draggable: true, zoomControl: true, scrollwheel: true, keyboardShortcuts: true, disableDoubleClickZoom: false});
                        mapDisabled = false;
                    },
                    _initializeMap = function () {
                        var mapOptions = {
                                center: { lat: options.latitude, lng: options.longitude},
                                zoom: options.zoomFactor,
                                minZoom: options.minZoomFactor,
                                maxZoom: options.maxZoomFactor,
                                mapTypeId: google.maps.MapTypeId.ROADMAP,
                                styles: options.style,
                                disableDefaultUI: true
                            };

                        // create the map
                        map = new google.maps.Map(mapElement, mapOptions);

                        // initialize marker array and add the markers
                        mapMarkers = [];
                        for (var i = 0; i < options.markers.length; i++) {
                            // create map markers  (use function to prevent overwriting of markers in loop)
                            createMapMarker(map, options.markers[i], options.altStyled);
                        }

                        // add listener for mouse move (enable/disable map) and mouse click (close info box)
                        var $infoBox = $('.view-custom-map .custom-map-info-box'),
                            $infoBoxBody = $infoBox.find('.custom-map-info-body');
                        google.maps.event.addListener(map, 'mousemove', function() {
                            // disable map, when it contains class 'map-disabled'
                            if ($(mapElement).hasClass('map-disabled')) {
                                if (!mapDisabled) _disableMap();
                            } else {
                                if (mapDisabled) _enableMap();
                            }
                        });
                        google.maps.event.addListener(map, 'click', function() {
                            if (!$(mapElement).hasClass('map-disabled')) {
                                $infoBox.removeClass('info-visible');
                                $infoBoxBody.css('display', 'none');
                            }
                        });
                    },
                    _filterChanged = function() {
                        //
                        // Due to the fact that a filter button change sends several ajax requests (why???)
                        // we call the map update only once when all request have finished
                        //

                        // remove existing markers from the old map
                        //removeMapMarkers();
                        $('.ajax-progress').remove();

                        // initialize and enable new map
                        _initializeMap();
                        $(mapElement).removeClass('map-disabled');
                        _enableMap();
                        $(window).trigger('resize'); // force window resize event
                        _resizeMap();
                    };

                // always reattach map and ajax events, because of ajax requests calling this behavior several times
                // initialize map after page load is finished, resize map on window resize
                $(window).off('.custom_map');
                $(window).on('load.custom_map', _initializeMap);
                $(window).on('resize.custom_map', _resizeMap);

                // add ajax events to control
                $(document).off('.ajax_map');
                $(document).on('ajaxStop.ajax_map', _filterChanged);

                // zoom items must be available (elements with id = "menu-zoom-in" and id = "menu-zoom-out")
                var $zoomIn = $('#menu-zoom-in'),
                    $zoomOut = $('#menu-zoom-out');

                if ($zoomIn.length > 0 && $zoomOut.length > 0) {
                    $zoomIn.off('.zoom');
                    $zoomIn.on('click.zoom', function () {
                        map.setZoom(map.getZoom()+1);
                    });
                    $zoomOut.off('.zoom');
                    $zoomOut.on('click.zoom', function () {
                        map.setZoom(map.getZoom()-1);
                    });
                }
            });

        }
    };

    /**
     * Toggle the map info box's height on click.
     */
    Drupal.behaviors.handleMapInfoBox = {
        attach: function () {
            var $w = $(window).width(),
                $infoBox = $('.view-custom-map .custom-map-info-box'),
                $infoBoxBody = $infoBox.find('.custom-map-info-body');

            $infoBox.once('click', function () {
                $infoBox.on('click', function (ev) {
                    $infoBox.toggleClass('info-visible');
                    $infoBoxBody.animate({height: "toggle"}, 200, 'linear');
                    ev.stopPropagation();
                });
            });
            // show info body on page load when not on mobile device
            if ($w >= 768) {
                $infoBox.addClass('info-visible');
            } else {
                // hide desc box on room page load
                $infoBoxBody.css('display', 'none');
            }
        }
    };

    /**
     * Ajax command to replace map markers instead of merging it.
     */
    Drupal.ajax.prototype.commands.replaceMapMarkerSettings = function(ajax, response, status) {
        if (response.merge) {
            $.extend(true, Drupal.settings, response.settings);
        }
        else {
            ajax.settings = response.settings;
        }

        // replace map settings
        try {
            var mapIDs = Object.keys(Drupal.settings.custom_map),
                newMarkers = {};

            mapIDs.forEach(function(mapID){
                // custom map settings can be missing in response, check existance
                if (response.settings.hasOwnProperty('custom_map') && typeof response.settings.custom_map === 'object' &&
                    response.settings.custom_map.hasOwnProperty(mapID) && typeof response.settings.custom_map[mapID] === 'object') {
                    newMarkers = response.settings.custom_map[mapID].markers;
                }
                Drupal.settings.custom_map[mapID].markers = newMarkers;
            });
        } catch (e) {
            console.log('Ajax marker replacement failed', e);
        }
    };

})(jQuery);
