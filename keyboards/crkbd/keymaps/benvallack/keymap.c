

#include QMK_KEYBOARD_H
#include "keymap_portuguese.h"
#include "color.h"
#include "print.h"


enum layers {
	L_A1,
	L_A2,
	L_NU,
	L_S1,
	L_S2,
	L_SY,
};
 
// #define ALT_COLEMAK_DH
#define ALT_COLEMAK
// #define ALT_DEC_HNIOP1
// #define ALT_ROMAK
// #define ALT_ENGRAM
// #define ALT_MIGRAM

// Tap-hold keys definitions
#define MG_SFT SFT_T(KC_CAPS)
// #define MG_SFT SFT_T(OSM(MOD_LSFT))

// home row mods
#define _C(kc) CTL_T(kc)
#define _S(kc) SFT_T(kc)
#define _G(kc) GUI_T(kc)
#define _A(kc) ALT_T(kc)
#define _CS(kc) MT(MOD_LCTL | MOD_LSFT, (kc))
#define _SG(kc) MT(MOD_LGUI | MOD_LSFT, (kc))
#define _GA(kc) MT(MOD_LGUI | MOD_LALT, (kc))
#define _SA(kc) MT(MOD_LSFT | MOD_LALT, (kc))



enum custom_keycodes {
	M_0B = KC_INT1,
	M_0X,
	M_PDIR,
	M_DCLN,
	ND_TILD,
	ND_CIRC,
	ND_TICK,

	CB_BSLS,
	CB_MINS,
	CB_EQL,
	CB_LPRN,
	CB_EXLM,
	CB_RPRN,
};




const key_override_t dot_comm_ko = ko_make_basic(MOD_BIT(KC_LSFT), PT_DOT, PT_COMM);
const key_override_t quot_dquo_ko = ko_make_basic(MOD_BIT(KC_LSFT), PT_QUOT, PT_DQUO);
const key_override_t bsps_del_ko = ko_make_basic(MOD_BIT(KC_LSFT), KC_BSPC, KC_DEL);

// This globally defines all key overrides to be used´
const key_override_t *key_overrides[] = {
	&dot_comm_ko,
	&quot_dquo_ko,
	&bsps_del_ko,
};

#define _CB(cb,kc) COMBO(cb,kc)
#define _DC(name,k1,k2) const uint16_t PROGMEM (name)[] = {(k1),(k2),COMBO_END};
#define _TC(name,k1,k2,k3) const uint16_t PROGMEM (name)[] = {(k1),(k2),(k3),COMBO_END};

// Combos definitions
_DC(cb_lg,      _C(PT_L),      _A(PT_G)) _DC(cb_ld,      _C(PT_L),      _G(PT_D)) _DC(cb_gd,      _A(PT_G),      _G(PT_D))
_DC(cb_sr, LT(L_S2,PT_S), LT(L_S1,PT_R)) _DC(cb_st, LT(L_S2,PT_S), LT(L_SY,PT_T)) _DC(cb_rt, LT(L_S1,PT_R), LT(L_SY,PT_T))

_DC(cb_hu,      _G(PT_H),      _A(PT_U)) _DC(cb_ho,      _G(PT_H),      _C(PT_O)) _DC(cb_uo,      _A(PT_U),      _C(PT_O))
_DC(cb_ne, LT(L_SY,PT_N), LT(L_S1,PT_E)) _DC(cb_na, LT(L_SY,PT_N), LT(L_S2,PT_A)) _DC(cb_ea, LT(L_S1,PT_E), LT(L_S2,PT_A))

_TC(cb_lgd,      _C(PT_L),      _A(PT_G),      _G(PT_D))
_TC(cb_srt, LT(L_S2,PT_S), LT(L_S1,PT_R), LT(L_SY,PT_T))

_TC(cb_huo,      _G(PT_H),      _A(PT_U),      _C(PT_O))
_TC(cb_nea, LT(L_SY,PT_N), LT(L_S1,PT_E), LT(L_S2,PT_I))


combo_t key_combos[] = {
	// left half
	_CB(cb_lgd, KC_ESC),
	_CB(cb_huo, KC_ENT),
	_CB(cb_srt, KC_TAB),
	_CB(cb_nea, KC_BSPC)
// 	//----------------------,----------------------------,------------------------------,------------------------------,
// 	_CB(cb_qw,      PT_RABK), _CB(   cb_we,      PT_SLSH), _CB(     cb_er,      PT_LABK), _CB(     cb_rt,      PT_COLN),
// 	//----------------------|----------------------------|------------------------------|------------------------------|
// 	_CB(cb_as, _CS(CB_BSLS)), _CB(   cb_sd, _SG(CB_MINS)), _CB(     cb_df,  _GA(CB_EQL)), _CB(     cb_fg,      PT_SCLN),
// 	//----------------------|----------------------------|------------------------------|------------------------------|
// 	_CB(cb_zx,      ND_TICK), _CB(   cb_xc,      PT_PLUS), _CB(     cb_cv,      PT_ASTR), _CB(     cb_vb,      ND_CIRC),
// 	//----------------------'----------------------------'------------------------------'------------------------------'
// 
// 	// right half
// 	//----------------------,----------------------------,------------------------------,------------------------------,
// 	_CB(cb_yu,      PT_AMPR), _CB(   cb_ui,      PT_LBRC), _CB(     cb_io,      PT_QUES), _CB(    cb_oqt,      PT_RBRC),
// 	//----------------------|----------------------------|------------------------------|------------------------------|
// 	_CB(cb_hj,      PT_PIPE), _CB(   cb_jk, _GA(CB_LPRN)), _CB(     cb_kl, _SG(CB_EXLM)), _CB(     cb_lp, _CS(CB_RPRN)),
// 	//----------------------|----------------------------|------------------------------|------------------------------|
// 	_CB(cb_nm,      ND_TILD), _CB(cb_mcomm,      PT_LCBR), _CB(cb_commdot,      PT_UNDS), _CB(cb_dotdqts,      PT_RCBR),
// 	//----------------------'----------------------------'------------------------------'------------------------------'
//   
// 	_CB(cb_sl, KC_CAPS)
};


// static uint8_t led_counter = 0;

#define LAYOUT_split_2x4_2(k1,k2,k3,k4,k5,k6,k7,k8,k9,k10,k11,k12,k13,k14,k15,k16,k17,k18) LAYOUT_split_3x6_3( \
	  XXXXXXX, XXXXXXX,      k1,      k2,      k3, XXXXXXX,     XXXXXXX,      k4,      k5,      k6, XXXXXXX, XXXXXXX, \
	  XXXXXXX,      k7,      k8,      k9,     k10, XXXXXXX,     XXXXXXX,     k11,     k12,     k13,     k14, XXXXXXX, \
	  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
	                             XXXXXXX,     k15,     k16,         k17,     k18, XXXXXXX \
)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[L_A1] = LAYOUT_split_2x4_2(
	               //--------------,--------------,--------------,    ,--------------,--------------,--------------//
	                       _C(PT_C),      _A(PT_R),      _G(PT_F),           _G(PT_L),      _A(PT_U),      _C(PT_O),
	//--------------|--------------|--------------|--------------|    |--------------|--------------|--------------|--------------//
	   LT(L_NU,PT_H), LT(L_S2,PT_S), LT(L_S1,PT_D), LT(L_SY,PT_T),      LT(L_SY,PT_N), LT(L_S1,PT_E), LT(L_S2,PT_I), LT(L_NU,PT_A),
	//--------------|--------------'--------------|--------------'    |--------------'--------------|--------------'--------------//
	                                        KC_SPC,        MG_SFT,   LT(L_SY,XXXXXXX),     OSL(L_A2)
	                              //--------------'--------------'    '--------------'--------------//
	),
 
	[L_A2] = LAYOUT_split_2x4_2(
	               //--------------,--------------,--------------,    ,--------------,--------------,--------------//
	                       _C(PT_W),      _A(PT_B),      _G(PT_V),           _G(PT_K),      _A(PT_Q),      _C(PT_Z),
	//--------------|--------------|--------------|--------------|    |--------------|--------------|--------------|--------------//
	            PT_X,          PT_G,          PT_M,          PT_P,               PT_J,       PT_COMM,        PT_DOT,          PT_Y,
	//--------------|--------------'--------------|--------------'    |--------------'--------------|--------------'--------------//
	                                       _______,       _______,            _______,      TO(L_A1)
	                              //--------------'--------------'    '--------------'--------------//
	),

	[L_NU] = LAYOUT_split_2x4_2(
	               //--------------,--------------,--------------,    ,--------------,--------------,--------------//
	                     _C(PT_DOT),      _A(PT_0),      _G(PT_1),           _G(PT_2),      _A(PT_3),      _C(PT_4),
	//--------------|--------------|--------------|--------------|    |--------------|--------------|--------------|--------------//
	         PT_MINS,       PT_PLUS,          PT_5,          PT_6,               PT_7,          PT_8,          PT_9,        PT_EQL,
	//--------------|--------------'--------------|--------------'    |--------------'--------------|--------------'--------------//
	                                       _______,       _______,            _______,       XXXXXXX
	                              //--------------'--------------'    '--------------'--------------//
	),

	[L_S1] = LAYOUT_split_2x4_2(
	               //--------------,--------------,--------------,    ,--------------,--------------,--------------//
	                    _C(PT_EURO),   _A(PT_HASH),    _G(PT_DLR),        _G(PT_LABK),   _A(PT_RABK),   _C(ND_CIRC),
	//--------------|--------------|--------------|--------------|    |--------------|--------------|--------------|--------------//
	         ND_TICK,       ND_TILD,       PT_MINS,       PT_BSLS,            PT_LBRC,       PT_RBRC,       PT_PIPE,       PT_SLSH,
	//--------------|--------------'--------------|--------------'    |--------------'--------------|--------------'--------------//
	                                       _______,       _______,            _______,       XXXXXXX
	                              //--------------'--------------'    '--------------'--------------//
	),

	[L_S2] = LAYOUT_split_2x4_2(
	               //--------------,--------------,--------------,    ,--------------,--------------,--------------//
	                      _C(PT_AT),   _A(PT_QUES),   _G(PT_QUOT),        _G(PT_LPRN),   _A(PT_RPRN),   _C(PT_SCLN),
	//--------------|--------------|--------------|--------------|    |--------------|--------------|--------------|--------------//
	         PT_ASTR,       PT_PERC,       PT_EXLM,       PT_DQUO,            PT_LCBR,       PT_RCBR,       PT_AMPR,       PT_COLN,
	//--------------|--------------'--------------|--------------'    |--------------'--------------|--------------'--------------//
	                                       _______,       _______,            _______,       XXXXXXX
	                              //--------------'--------------'    '--------------'--------------//
	),

	[L_SY] = LAYOUT_split_2x4_2(
	               //--------------,--------------,--------------,    ,--------------,--------------,--------------//
	                     _C(KC_ESC),   _A(XXXXXXX),   _G(XXXXXXX),        _G(XXXXXXX),     _A(KC_UP),   _C(XXXXXXX),
	//--------------|--------------|--------------|--------------|    |--------------|--------------|--------------|--------------//
	          KC_TAB,        KC_DEL,       XXXXXXX,       XXXXXXX,            KC_LEFT,       KC_DOWN,       KC_RGHT,        KC_ENT,
	//--------------|--------------'--------------|--------------'    |--------------'--------------|--------------'--------------//
	                                       _______,       _______,            _______,       XXXXXXX
	                              //--------------'--------------'    '--------------'--------------//
	),

// 	[L_FUN] = LAYOUT_split_3x6_3(
// 	//-------,--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,--------,
// 	  XXXXXXX,  KC_F12,   KC_F7,   KC_F8,   KC_F9,  KC_F15,                      _______, _______, _______, _______, _______, XXXXXXX,
// 	//-------|--------|--------|--------|--------|--------,                    |--------|--------|--------|--------|--------|--------|
// 	  XXXXXXX,  KC_F11,   KC_F4,   KC_F5,   KC_F6,  KC_F14,                      _______, _______, _______, _______, _______, XXXXXXX,
// 	//-------|--------|--------|--------|--------|--------,                    |--------|--------|--------|--------|--------|--------|
// 	  XXXXXXX,  KC_F10,   KC_F1,   KC_F2,   KC_F3,  KC_F13,                       _______, _______, _______, _______, _______, XXXXXXX,
// 	//-------|--------'--------|--------'--------|--------'--------,  ,--------'--------|--------'--------|--------'--------|--------'
// 	                    _______,          _______,          _______,             _______,         _______,          _______
// 	        //-----------------'-----------------'-----------------'  '-----------------'-----------------'-----------------'
// 	),
// 
// 	[L_NAV] = LAYOUT_split_3x6_3(
// 	//-------,--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,--------,
// 	  XXXXXXX, _______, _______, _______, _______, _______,                      KC_PGUP, KC_HOME,   KC_UP,  KC_END, KC_MPRV, XXXXXXX,
// 	//-------|--------|--------|--------|--------|--------,                    |--------|--------|--------|--------|--------|--------|
// 	  XXXXXXX, _______, _______, _______, _______, _______,                      KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_MPLY, XXXXXXX,
// 	//-------|--------|--------|--------|--------|--------,                    |--------|--------|--------|--------|--------|--------|
// 	  XXXXXXX, _______, _______, _______, _______, _______,                      KC_PSCR, KC_MUTE, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX,
// 	//-------|--------'--------|--------'--------|--------'--------,  ,--------'--------|--------'--------|--------'--------|--------'
// 	                    _______,          _______,          _______,             _______,         _______,          _______
// 	        //-----------------'-----------------'-----------------'  '-----------------'-----------------'-----------------'
// 	),
// 
// 	[L_CMD] = LAYOUT_split_3x6_3(
// 	//-------,--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,--------,
// 	  XXXXXXX, RM_TOGG, XXXXXXX, XXXXXXX, KC_BRID, KC_BRIU,                      KC_SLEP, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT, XXXXXXX,
// 	//-------|--------|--------|--------|--------|--------,                    |--------|--------|--------|--------|--------|--------|
// 	  XXXXXXX, RM_SPDU, RM_VALU, RM_SATU, RM_HUEU, RM_NEXT,                      KC_WAKE, XXXXXXX, XXXXXXX, XXXXXXX,  EE_CLR, XXXXXXX,
// 	//-------|--------|--------|--------|--------|--------,                    |--------|--------|--------|--------|--------|--------|
// 	  XXXXXXX, RM_SPDD, RM_VALD, RM_SATD, RM_HUED, RM_PREV,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DB_TOGG, XXXXXXX,
// 	//-------|--------'--------|--------'--------|--------'--------,  ,--------'--------|--------'--------|--------'--------|--------'
// 	                    _______,          _______,          _______,             _______,          _______,          _______
// 	        //-----------------'-----------------'-----------------'  '-----------------'-----------------'-----------------'
// 	),

};


// style_t *current_style = &style_alpha;
// 
// extern void animation_next_mode(style_t *style);
// extern void animation_previous_mode(style_t *style);

const uint16_t cb_tap_kcs[] = {
	PT_BSLS,
	PT_MINS,
	PT_EQL,
	PT_LPRN,
	PT_EXLM,
	PT_RPRN,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	uint16_t cb_kc;
  
	// for performance reasons, this switch should apply to custom keycodes
	// only. So it can create a small jump table.
	switch (keycode) {
		case M_0B:
			if (record->event.pressed) SEND_STRING("0b");
			return false;
		case M_0X:
			if (record->event.pressed) SEND_STRING("0x");
			return false;
		
		case M_PDIR:
			if (record->event.pressed) SEND_STRING("..&"); // equiv to ../ in us ansi
			return false;
		case M_DCLN:
			if (record->event.pressed) SEND_STRING(">>"); // equiv to :: in us ansi
			return false;

		case ND_TILD:
			if (record->event.pressed) SEND_STRING(SS_TAP(X_NUHS)" ");//SS_TAP(PT_TILD) SS_TAP(PT_TILD));
			return false;
		case ND_CIRC:
			if (record->event.pressed) SEND_STRING(SS_LSFT(SS_TAP(X_NUHS))" ");//SS_TAP(PT_CIRC) SS_TAP(PT_CIRC));
			return false;
		case ND_TICK:
			if (record->event.pressed) SEND_STRING("} ");//SS_TAP(PT_GRV) SS_TAP(PT_GRV));
			return false;
		
		case _CS(CB_BSLS):
		case _SG(CB_MINS):
		case _GA(CB_EQL):
		case _GA(CB_LPRN):
		case _SG(CB_EXLM):
		case _CS(CB_RPRN):
			cb_kc = cb_tap_kcs[0b111 & (keycode - CB_BSLS)];
			
			dprintf("Sending keycode from combo: 0x%d\n", cb_kc);
			if (record->event.pressed && record->tap.count) {
				// for some reason tap_code16 doesn't send the correct modifier,
				// so I do that manually :) (There reason was access outside the
				// limits of the array cp_tap_kcs)
				//set_weak_mods(MOD_BIT(KC_LSFT));
				tap_code16(cb_kc);
				return false;
			}
			return true;
			
	}

	// // beacuse of the jump table of the upper switch, its more efficient to keep
	// // caps behaviour outside of it.
	// // emulate caps word without occupying so much space
	// 
	// if (host_keyboard_led_state().caps_lock) {
	// 	switch (keycode) {
	// 		// Keycodes that continue Caps Word, with shift applied.
	// 		case PT_MINS:
	// 			// add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
	// 			tgl_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
	// 			break;
	// 
	// 		// // Exit from CAPS LOCK on space and enter
	// 		// case KC_ENT:
	// 		// case KC_SPC:
	// 		// 	tap_code(KC_CAPS);
	// 		// 	break;
	// 		// 
	// 		// case ALT_T(KC_SPC):
	// 		// 	if (record->tap.count > 0 && record->event.pressed)
	// 		// 		tap_code(KC_CAPS);
	// 		// 	break;
	// 	}
	// }
	
	return true;
}




// static uint8_t last_lock = 0;
// static uint8_t slave_lock_state = 0;
// 
// void housekeeping_task_user(void) {
// 	uint8_t is_locked = is_layer_locked(L_CMD) | is_layer_locked(L_NUM) | is_layer_locked(L_NAV);
// 	static uint32_t last_sync = 0;
// 	static uint8_t success = 0;
// 	if (is_keyboard_master()) {
// 		if (last_lock != is_locked) {
// 			last_lock = is_locked;
// 			last_sync = timer_read32();
// 			success = transaction_rpc_send(USER_SYNC_LOCK, 1, &last_lock);
// 		} else if (!success && timer_elapsed32(last_sync) > 100) {
// 			success = transaction_rpc_send(USER_SYNC_LOCK, 1, &last_lock);
// 		}
// 	}
// }
// 
// void user_sync_lock_slave_handler(uint8_t in_buflen, const void* in_data, uint8_t out_buflen, void* out_data) {
// 	const uint8_t *m2s = (const uint8_t*)in_data;
// 	slave_lock_state = *m2s;
// }

// const uint8_t mod_leds[] = {
// 	 6,  7,  8,  9, 10, 13, 14, 17, 18, 22, 23, 24, 25, 26,
// 	27, 28, 29, 30, 31, 34, 35, 38, 39, 43, 44, 45, 46, 47
// };

void keyboard_post_init_user(void) {
	// Set a specific RGB lighting mode
	// rgblight_mode(RGBLIGHT_MODE_BREATHING); // Replace with your desired mode
	// rgb_matrix_set_color(0, 0x00, 0x00, 0xff);
	// transaction_register_rpc(USER_SYNC_LOCK, user_sync_lock_slave_handler);
	#ifdef COMMAND_ENABLE
	debug_enable=true;
	debug_matrix=true;
	#endif // COMMAND_ENABLE
	

	// for (uint8_t i = 0; i < sizeof(mod_leds); i++)
	// 	g_led_config.flags[mod_leds[i]] = LED_FLAG_MODIFIER;
}


#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
	hsv_t hsv = rgb_matrix_config.hsv;
	hsv.h -= rgb_matrix_config.speed;
	hsv.s = 0xff;
	rgb_t rgb = hsv_to_rgb(hsv);

	if (host_keyboard_led_state().caps_lock) RGB_MATRIX_INDICATOR_SET_COLOR(CAPS_ID, rgb.r, rgb.g, rgb.b);
	
	// uint8_t mods = get_mods();
	// if (mods & 0b01000000) RGB_MATRIX_INDICATOR_SET_COLOR(MOD_5, rgb.r, rgb.g, rgb.b);
	// 
	// // home row mods indicators
	// uint8_t mod_mask = 0b1000;
	// const uint8_t mod_leds[] = {16,11,19,22};
	// for (uint8_t i = 0; i < 4; i++) {
	// 	if (mods & mod_mask) {
	// 		uint8_t led_n = mod_leds[i];
	// 		RGB_MATRIX_INDICATOR_SET_COLOR(led_n, rgb.r, rgb.g, rgb.b);
	// 		RGB_MATRIX_INDICATOR_SET_COLOR(led_n + 27, rgb.r, rgb.g, rgb.b);
	// 	}
	// 	mod_mask = mod_mask >> 1;
	// }

	// layer indicators
	// const uint8_t layer_leds[] = {
	// 	[L_BASE] = 0,
	// 	[L_GAME] = MOD_11,
	// 	[L_ALT] = MOD_2,
	// 	[L_NUM] = MOD_6,
	// 	[L_FUN] = MOD_4,
	// 	[L_CMD] = MOD_3,
	// };
	// for (uint8_t i = 1; i < 6; i++) {
	// 	if (layer_state_is(i))
	// 		RGB_MATRIX_INDICATOR_SET_COLOR(layer_leds[i], rgb.r, rgb.g, rgb.b);
	// }

	return false;
}
#endif //RGB_MATRIX_ENABLE

