#pragma once

#include "tusb.h"

// Override weak to handle unhandled control msgs.
__attribute__((weak)) bool tud_custom_control_cb(
    uint8_t port, tusb_control_request_t const* request);

__attribute__((weak)) bool tud_custom_control_complete_cb(
    uint8_t port, tusb_control_request_t const* request);


// We copy these from tinyusb.h because that file includes descriptor_control
// when then declares some structs but not as "extern" which means there are
// errors if we inclue them outside of the tinyusb static library.
typedef char *tusb_desc_strarray_device_t[7];

typedef struct {
		    tusb_desc_device_t *descriptor;
				    char **string_descriptor;
						    bool external_phy;
} tinyusb_config_t;

esp_err_t tinyusb_driver_install(const tinyusb_config_t *config);
