
// RGB_MATRIX_EFFECT(my_cool_effect)
RGB_MATRIX_EFFECT(indicator_effect)
RGB_MATRIX_EFFECT(eco_effect)
RGB_MATRIX_EFFECT(triple_color_effect)
// RGB_MATRIX_EFFECT(my_alpha_mods)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static bool update_leds_effect (effect_params_t *params, hsv_t alpha_hsv, hsv_t mod_hsv, hsv_t glow_hsv);

// static hsv_t alpha_hsv;
// static hsv_t mod_hsv;
// static hsv_t glow_hsv;

// e.g: A simple effect, self-contained within a single method
// bool my_cool_effect(effect_params_t* params) {
// 	return update_leds_effect(
// 		params,
// 		(hsv_t){HSV_YELLOW},
// 		(hsv_t){HSV_YELLOW},
// 		(hsv_t){HSV_YELLOW}
// 	);
// }


static bool triple_color_effect(effect_params_t* params) {
	hsv_t alpha_hsv = rgb_matrix_config.hsv;
	hsv_t mod_hsv = alpha_hsv;
	hsv_t glow_hsv = alpha_hsv;
	
	mod_hsv.h += rgb_matrix_config.speed;
	glow_hsv.h -= rgb_matrix_config.speed;
	
	return update_leds_effect(params, alpha_hsv, mod_hsv, glow_hsv);
}


static bool eco_effect(effect_params_t *params) {
	hsv_t hsv = rgb_matrix_config.hsv;
	
	hsv_t mod_hsv = (hsv_t){
		hsv.h,
		0xff,
		hsv.v //(RGB_MATRIX_MAXIMUM_BRIGHTNESS * hsv.v) / 0xff
	};
	hsv_t alpha_hsv = (hsv_t){
		0,
		0,
		hsv.v * hsv.s / 0xff //((RGB_MATRIX_MAXIMUM_BRIGHTNESS * hsv.v / 0xff) * hsv.s) / 0xff // (0xff * 0xff)
	};
	hsv_t glow_hsv = alpha_hsv;

	return update_leds_effect(params, alpha_hsv, mod_hsv, glow_hsv);
}

static bool indicator_effect(effect_params_t *params) {
	hsv_t off = (hsv_t){0,0,0};
	return update_leds_effect(params, off, off, off);
}

static bool update_leds_effect (effect_params_t *params, hsv_t alpha_hsv, hsv_t mod_hsv, hsv_t glow_hsv)  {
	RGB_MATRIX_USE_LIMITS(led_min, led_max);

	rgb_t alpha_rgb = rgb_matrix_hsv_to_rgb(alpha_hsv);
	rgb_t mod_rgb = rgb_matrix_hsv_to_rgb(mod_hsv);
	rgb_t glow_rgb = rgb_matrix_hsv_to_rgb(glow_hsv); 
	
	for (uint8_t i = led_min; i < led_max; i++) {
		RGB_MATRIX_TEST_LED_FLAGS();
		if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_KEYLIGHT)) {
			rgb_matrix_set_color(i, alpha_rgb.r, alpha_rgb.g, alpha_rgb.b);
		} else if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_MODIFIER)) {
			rgb_matrix_set_color(i, mod_rgb.r, mod_rgb.g, mod_rgb.b);
		} else {
			rgb_matrix_set_color(i, glow_rgb.r, glow_rgb.g, glow_rgb.b);
		}
	}

	return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
