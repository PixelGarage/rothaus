/**
 * This file contains all Drupal behaviours of the Apia theme.
 *
 * Created by ralph on 05.01.14.
 */

(function ($) {

    function calcMinContentHeight () {
        var headerH = $('#header').outerHeight(),
            footerH = $('#footer').outerHeight();

        return $(window).height() - headerH - footerH;
    }

    function calcContentHeight () {
        var columnHeight = calcMinContentHeight(),
            $width = $(window).width(),
            minHeight = ($width >= 768) ? $width / 2 : $width*2/3;

        return Math.max( minHeight, columnHeight );
    }

    /**
     * Close the accordion menu on specific menu click.
     */
    Drupal.behaviors.closeAccordionMenu = {
        attach: function () {
            var closingMenus = $('#superfish-1-accordion #menu-2032-1, #superfish-1-accordion #menu-1826-1 > ul #edit-field-filter-tags-tid-wrapper .form-item');

            closingMenus.once('click', function () {
                closingMenus.on('click', function () {
                    // close menu
                    $('#superfish-1-accordion').removeClass('sf-expanded').addClass('sf-hidden').hide();
                });
            });

        }
    }

    /**
     * Handles explore menu behavior.
     * - synchronize clicked filters between menus
     * - support touch devices (close menu when filter is clicked or on click outside of menu)
     */
    Drupal.behaviors.handleExploreMenuClick = {
        attach: function () {
            var $mapRegion = $('#columns .region-content-aside'),
                $exploreDropdown = $('#block-superfish-1 #menu-1826-1 > ul'),
                $exploreMenuItems = $('#superfish-1 > #menu-1826-1 > span, #block-superfish-1 #menu-1826-1 > ul .views-exposed-widget .form-item'),
                $filterDropdown = $('#superfish-2 > #menu-2026-2 > ul'),
                $filterMenuItems = $('#superfish-2 > #menu-2026-2 > ul .views-exposed-widget .form-item'),
                $dayNightDropdown = $('#superfish-2 > #menu-2027-2 > ul'),
                $dayNightMenuItems = $('#superfish-2 > #menu-2027-2 > ul .views-exposed-widget .form-item');

            // close filter menus, when user touches anywhere outside of menu (dropdown event excludes menu)
            $(document).off('.filters');
            $(document).on('touchstart.filters', function() {
                $exploreDropdown.fadeOut(300);
                $filterDropdown.fadeOut(300);
                $dayNightDropdown.fadeOut(300);
            });
            $exploreDropdown.off('.filters');
            $exploreDropdown.on('touchstart.filters', function(e){
                e.stopPropagation();
            });
            $filterDropdown.off('.filters');
            $filterDropdown.on('touchstart.filters', function(e){
                e.stopPropagation();
            });
            $dayNightDropdown.off('.filters');
            $dayNightDropdown.on('touchstart.filters', function(e){
                e.stopPropagation();
            });

            // explore menu: open map section on click and sync clicked filter between all menus
            $exploreMenuItems.once('click', function () {
                $exploreMenuItems.on('click', function () {
                    // display map region
                    $mapRegion.click();

                    // synchronize explore menus
                    if ($(this).hasClass('form-item')) {
                        var radioIdSel = '#superfish-2  > #menu-2026-2 > ul #edit-field-filter-tags-tid-wrapper #' + $(this).find('input').attr('id');
                        $(radioIdSel).prop("checked", true);
                        // close menu on touch screens
                        $exploreDropdown.fadeOut(300);
                    }
                });
            });

            // filter menu in map: sync clicked filter between all menus
            $filterMenuItems.once('click', function () {
                $filterMenuItems.on('click', function () {
                    // synchronize explore menus
                    if ($(this).hasClass('form-item')) {
                        var radioIdSel = '#block-superfish-1 #menu-1826-2 > ul #edit-field-filter-tags-tid-wrapper #' + $(this).find('input').attr('id');
                        $(radioIdSel).prop("checked", true);
                        // close menu on touch screens
                        $filterDropdown.fadeOut(300);
                    }
                });
            });

            // close dropdown
            $dayNightMenuItems.once('click', function () {
                $dayNightMenuItems.on('click', function () {
                    // close menu on touch screen
                    $dayNightDropdown.fadeOut(300);
                });
            });
        }
    }

    /**
     * Toggle the description box and the menu box.
     */
    Drupal.behaviors.handleDescriptionAndMenuBox = {
        attach: function () {
            var $w = $(window).width(),
                $body = $('body'),
                $descBox = $('.node.node-full .group-description'),
                $descBoxBody = $descBox.find('.group-desc-body'),
                $menuBox = $('.node.node-room .field-name-rooms-menu-block, .node.node-room .field-name-rooms-menu-block-deutsch-'),
                $menuBoxBody = $menuBox.find('.menu-block-wrapper');

            // handle node description box
            $descBox.once('click', function () {
                $descBox.on('click', function (ev) {
                    $descBox.toggleClass('box-visible');
                    $descBoxBody.animate({height: "toggle"}, 200, 'linear');
                    ev.stopPropagation();
                });
            });

            // handle room menu block
            $menuBox.once('click', function () {
                $menuBox.on('click', function (ev) {
                    $menuBox.toggleClass('box-visible');
                    $menuBoxBody.animate({height: "toggle"}, 200, 'linear');
                    ev.stopPropagation();
                });
            });

            // close desc-box for rooms and always for mobile devices, open desc-box for hotel and front pages
            if ( $w >= 768 && ($body.hasClass('node-type-hotel') || $body.hasClass('front')) ) {
                // show desc box on hotel page load
                $descBox.addClass('box-visible');
            } else {
                // hide desc box on room page load
                $descBoxBody.css('display', 'none');
            }
            // always hide menu box on page load
            $menuBoxBody.css('display', 'none');
        }
    };

    /**
     * Switches between main content and map.
     */
    Drupal.behaviors.handleMainAndMapSection = {
        attach: function () {
            var $mainRegion = $('#columns .region-content-main'),
                $mapRegion = $('#columns .region-content-aside'),
                $flexImgs = $mainRegion.find('.flexslider img'),
                $descBox = $('.node.node-full .group-description'),
                $descBoxBody = $descBox.find('.group-desc-body'),
                $menuBox = $('.node.node-room .field-name-rooms-menu-block'),
                $menuBoxBody = $menuBox.find('.menu-block-wrapper'),
                _resizeRegions = function() {
                    var sliderHeight = calcContentHeight();

                    // resize flexslider and map
                    $flexImgs.height(sliderHeight).width('auto');
                    $mapRegion.find('.view-custom-map .custom-map').height(sliderHeight);
                };

            // switch between regions on click
            $mainRegion.once('click', function () {
                $mainRegion.on('click', function () {
                    $mainRegion.addClass('selected');
                    $mapRegion.removeClass('selected');
                    $mapRegion.find('.custom-map').addClass('map-disabled');
                    $('body').removeClass('map-selected');
                    // close desc boxes
                    $descBox.removeClass('box-visible');
                    $descBoxBody.css('display', 'none');
                    $menuBox.removeClass('box-visible');
                    $menuBoxBody.css('display', 'none');
                    //return false;
                });
            });
            $mapRegion.once('click', function () {
                $mapRegion.on('click', function () {
                    $mapRegion.addClass('selected');
                    $mapRegion.find('.custom-map').removeClass('map-disabled');
                    $mainRegion.removeClass('selected');
                    setTimeout(function() {
                        $('body').addClass('map-selected');
                        $(window).resize();
                    }, 300);
                    //return false;
                });
            });

            // region with full height on load, resize
            $(window).off('.rothaus');
            $(window).on('load.rothaus resize.rothaus', _resizeRegions);
        }
    };

    /**
     * Defines a modal dialog to book rooms.
     */
    Drupal.behaviors.bookingModalDialog =  {
        attach: function() {
            // create a dialog with the sihot booking frame
            var $bookingFrame = $("div.block-sihot-frame"),
                $bookingMenu = $('#menu-2032-1'),
                $openingElements = $bookingMenu.add('.node-room.node-full .group-desc-header .field-name-booking-link');

            // create a hidden dialog with the booking frame
            var $w = $(window).width(),
                $width = Math.min( $w - 20, 520 ),
                position = ($w >= 768) ? { my: "right top", at: "right bottom+12", of: $bookingMenu, collision: 'none'} : { of: $('body'), collision: 'none'},
                dlg = $bookingFrame.dialog({
                autoOpen: false,
                width: $width,
                modal: true,
                resizable: false,
                draggable: true,
                position: position,
                open: function(ev, ui){
                    $('#sihot-rothaus').attr('src','https://mysihot.net/SIHOTWeb/rothaus.htm?NOPAXPERGT=1A,2&LN=de');
                    $("html, body").css('overflow-y', 'hidden'); // disable scrolling in body
                },
                close: function(ev, ui){
                    $("html, body").css('overflow-y', 'auto'); // enable scrolling in body
                },
                show: {
                    effects: "fade",
                    duration: 400
                },
                hide: {
                    effects: "fade",
                    duration: 400
                }
            });

            // open dialog with click on opening elements
            $openingElements.once('click-binding', function() {
                // bind click event to all opening buttons
                $(this).on('click', function() {
                    //var dlgHeight = Math.min( calcMinContentHeight(), 790 );
                    //dlg.dialog("option", "height", dlgHeight);
                    //dlg.dialog("open");
                    window.open('https://mysihot.net/SIHOTWeb/rothaus.htm?NOPAXPERGT=1A,2&LN=de', '_blank');
                });
            });

        }
    }

    /**
     * Open file links in its own tab. The file field doesn't implement this behaviour right away.
     */
    Drupal.behaviors.openDocumentsInTab = {
        attach: function () {
            $(".field-name-field-documents").find(".field-item a").attr('target', '_blank');
        }
    }



})(jQuery);
