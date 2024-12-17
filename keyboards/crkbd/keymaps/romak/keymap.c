

#include QMK_KEYBOARD_H
#include "keymap_portuguese.h"
#include "color.h"
#include "print.h"


enum layers {
	R_A,
	R_A2
};

// home row mods
#define _C(kc) CTL_T(kc)
#define _S(kc) SFT_T(kc)
#define _G(kc) GUI_T(kc)
#define _A(kc) ALT_T(kc)
#define _CS(kc) MT(MOD_LCTL | MOD_LSFT, (kc))
#define _SG(kc) MT(MOD_LGUI | MOD_LSFT, (kc))
#define _GA(kc) MT(MOD_LGUI | MOD_LALT, (kc))



enum custom_keycodes {
	M_0B = KC_INT1,
	M_0X,
	M_PDIR,
	M_DCLN,
	ND_TILD,
	ND_CIRC,
	ND_TICK,
	
	CB_DLR,
	CB_ASTR,
	CB_EQL,
	CB_LPRN,
	CB_EXLM,
	CB_RPRN,
};


// const key_override_t cedilla_ko = ko_make_basic(MOD_BIT(KC_ALGR), HRM_QT, PT_CCED);
// const key_override_t quote_ko = ko_make_basic(MOD_MASK_SHIFT, HRM_QT, PT_DQUO);
const key_override_t spc_bsps_ko = ko_make_basic(MOD_MASK_SHIFT, LT(L_NUM,KC_SPC), LT(L_NUM,KC_BSPC));
// const key_override_t bsps_del_ko = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
// const key_override_t tab_ent_ko = ko_make_basic(MOD_MASK_SHIFT, KC_TAB, KC_ENT);

const key_override_t comm_bsls_ko = ko_make_basic(MOD_BIT(KC_LSFT), PT_COMM, PT_BSLS);
const key_override_t dot_perc_ko = ko_make_basic(MOD_BIT(KC_LSFT), PT_DOT, PT_PERC);
const key_override_t dquo_at_ko = ko_make_basic(MOD_BIT(KC_LSFT), PT_DQUO, PT_AT);
const key_override_t quot_tick_ko = ko_make_basic(MOD_BIT(KC_LSFT), PT_QUOT, ND_TICK);


// This globally defines all key overrides to be used´
const key_override_t *key_overrides[] = {
	&spc_bsps_ko,
	// &bsps_del_ko,
	// &tab_ent_ko,
	&comm_bsls_ko,
	&dot_perc_ko,
	&dquo_at_ko,
	&quot_tick_ko
};

#define DUAL_COMBO(name,k1,k2) \
	const uint16_t PROGMEM (name)[] = {(k1),(k2),COMBO_END};

#define TRIPLE_COMBO(name,k1,k2,k3) \
	const uint16_t PROGMEM (name)[] = {(k1),(k2),(k3),COMBO_END};

// Combos definitions
DUAL_COMBO(cb_qw, PT_Q, PT_W)
DUAL_COMBO(cb_we, PT_W, PT_E)
DUAL_COMBO(cb_er, PT_E, PT_R)
DUAL_COMBO(cb_rt, PT_R, PT_T)

DUAL_COMBO(cb_as, _C(PT_A), _S(PT_S))
DUAL_COMBO(cb_sd, _S(PT_S), _G(PT_D))
DUAL_COMBO(cb_df, _G(PT_D), _A(PT_F))
DUAL_COMBO(cb_fg, _A(PT_F),     PT_G)

DUAL_COMBO(cb_zx, PT_Z, PT_X)
DUAL_COMBO(cb_xc, PT_X, PT_C)
DUAL_COMBO(cb_cv, PT_C, PT_V)
DUAL_COMBO(cb_vb, PT_V, PT_B)


DUAL_COMBO( cb_yu, PT_Y, PT_U)
DUAL_COMBO( cb_ui, PT_U, PT_I)
DUAL_COMBO( cb_io, PT_I, PT_O)
DUAL_COMBO(cb_oqt, PT_O, PT_QUOT)

DUAL_COMBO(cb_hj,     PT_H, _A(PT_J))
DUAL_COMBO(cb_jk, _A(PT_J), _G(PT_K))
DUAL_COMBO(cb_kl, _G(PT_K), _S(PT_L))
DUAL_COMBO(cb_lp, _S(PT_L), _C(PT_P))

DUAL_COMBO(     cb_nm,    PT_N,    PT_M)
DUAL_COMBO(  cb_mcomm,    PT_M, PT_COMM)
DUAL_COMBO(cb_commdot, PT_COMM,  PT_DOT)
DUAL_COMBO(cb_dotdqts,  PT_DOT, PT_DQUO)

DUAL_COMBO(cb_sl, _S(PT_S), _S(PT_L))

TRIPLE_COMBO(cb_rae, _A(PT_R), _G(PT_A), _S(PT_E))

combo_t key_combos[] = {
	COMBO(cb_qw, PT_RABK),
	COMBO(cb_we, PT_SLSH),
	COMBO(cb_er, PT_LABK),
	COMBO(cb_rt, PT_COLN),

	COMBO(cb_as, _CS(CB_DLR)), //CB_DLR), //PT_DLR),
	COMBO(cb_sd, _SG(CB_ASTR)), //CB_ASTR), //PT_ASTR),
	COMBO(cb_df, _GA(CB_EQL)), //CB_EQL), //PT_EQL),
	COMBO(cb_fg, PT_SCLN),

	COMBO(cb_zx, PT_HASH),
	COMBO(cb_xc, PT_PLUS),
	COMBO(cb_cv, PT_MINS),
	COMBO(cb_vb, ND_CIRC),


	COMBO(cb_yu, PT_AMPR),
	COMBO(cb_ui, PT_LBRC),
	COMBO(cb_io, PT_QUES),
	COMBO(cb_oqt, PT_RBRC),

	COMBO(cb_hj, PT_PIPE),
	COMBO(cb_jk, _GA(CB_LPRN)), //CB_LPRN), //PT_LPRN),
	COMBO(cb_kl, _SG(CB_EXLM)), //CB_EXLM), //PT_EXLM),
	COMBO(cb_lp, _CS(CB_RPRN)), //CB_RPRN), //PT_RPRN),

	COMBO(cb_nm, ND_TILD),
	COMBO(cb_mcomm, PT_LCBR),
	COMBO(cb_commdot, PT_UNDS),
	COMBO(cb_dotdqts, PT_RCBR),

	COMBO(cb_sl, KC_CAPS),
	
	COMBO(cb_rae, KC_ENT),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// 	[L_NAV] = LAYOUT_split_3x6_3(
// 	//-------,--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,--------,
// 	  _______, _______, _______, _______, _______, _______,                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END, KC_MPRV, XXXXXXX,
// 	//-------|--------|--------|--------|--------|--------,                    |--------|--------|--------|--------|--------|--------|
// 	  _______, _______, _______, _______, _______, _______,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_MPLY, XXXXXXX,
// 	//-------|--------|--------|--------|--------|--------,                    |--------|--------|--------|--------|--------|--------|
// 	  _______, _______, _______, _______, _______, _______,                      KC_PSCR, KC_MUTE, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX,
// 	//-------|--------'--------|--------'--------|--------'--------,  ,--------'--------|--------'--------|--------'--------|--------'
// 	                    _______,          _______,          _______,             _______,         _______,          _______
// 	        //-----------------'-----------------'-----------------'  '-----------------'-----------------'-----------------'
// 	),
// 
// 	[L_CMD] = LAYOUT_split_3x6_3(
// 	//-------,--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,--------,
// 	  RM_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, KC_BRID, KC_BRIU,                      KC_SLEP,   KC_F7,   KC_F8,   KC_F9,  KC_F12, QK_BOOT,
// 	//-------|--------|--------|--------|--------|--------,                    |--------|--------|--------|--------|--------|--------|
// 	  XXXXXXX, RM_SPDU, RM_VALU, RM_SATU, RM_HUEU, RM_NEXT,                      KC_WAKE,   KC_F4,   KC_F5,   KC_F6,  KC_F11,  EE_CLR,
// 	//-------|--------|--------|--------|--------|--------,                    |--------|--------|--------|--------|--------|--------|
// 	  XXXXXXX, RM_SPDD, RM_VALD, RM_SATD, RM_HUED, RM_PREV,                      XXXXXXX,   KC_F1,   KC_F2,   KC_F3,  KC_F10, DB_TOGG,
// 	//-------|--------'--------|--------'--------|--------'--------,  ,--------'--------|--------'--------|--------'--------|--------'
// 	                    _______,          _______,          _______,             _______,          _______,          _______
// 	        //-----------------'-----------------'-----------------'  '-----------------'-----------------'-----------------'
// 	),

	[R_A] = LAYOUT_split_3x6_3(
	//-------,--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,--------,
	  XXXXXXX, XXXXXXX,    PT_B,    PT_M,    PT_G, XXXXXXX,                      XXXXXXX,    PT_L,    PT_O,    PT_U, XXXXXXX,TO(L_BASE),
	//-------|--------|--------|--------|--------|--------,                    |--------|--------|--------|--------|--------|--------|
	  XXXXXXX,_C(PT_D),_S(PT_N),_G(PT_S),_A(PT_T), XXXXXXX,                      XXXXXXX,_A(PT_R),_G(PT_A),_S(PT_E),_C(PT_I), XXXXXXX,
	//-------|--------|--------|--------|--------|--------,                    |--------|--------|--------|--------|--------|--------|
	  XXXXXXX, XXXXXXX,    PT_F,    PT_C,    PT_P, XXXXXXX,                      XXXXXXX,    PT_H, PT_COMM,  PT_DOT, XXXXXXX, XXXXXXX,
	//-------|--------'--------|--------'--------|--------'--------,  ,--------'--------|--------'--------|--------'--------|--------'
	                    XXXXXXX, LT(L_NUM,KC_SPC),  LT(R_A,KC_TAB),    LT(L_NAV,KC_ENT),          KC_BSPC,          XXXXXXX
	        //-----------------'-----------------'-----------------'  '-----------------'-----------------'-----------------'
	),

	[R_SYM] = LAYOUT_split_3x6_3(
	//-------,--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,--------,
	  XXXXXXX, XXXXXXX, PT_SLSH, PT_LABK, PT_COLN, XXXXXXX,                      XXXXXXX, PT_AMPR, PT_LBRC, PT_QUES, XXXXXXX,TO(L_BASE),
	//-------|--------|--------|--------|--------|--------,                    |--------|--------|--------|--------|--------|--------|
	  XXXXXXX, ND_CIRC, PT_ASTR,  PT_EQL, PT_SCLN, XXXXXXX,                      XXXXXXX, PT_PIPE, PT_LPRN, PT_EXLM, _______, XXXXXXX,
	//-------|--------|--------|--------|--------|--------,                    |--------|--------|--------|--------|--------|--------|
	  XXXXXXX, XXXXXXX, PT_PLUS, PT_MINS, XXXXXXX, XXXXXXX,                      XXXXXXX, ND_TILD, PT_LCBR, PT_UNDS, XXXXXXX, XXXXXXX,
	//-------|--------'--------|--------'--------|--------'--------,  ,--------'--------|--------'--------|--------'--------|--------'
	                    XXXXXXX, LT(L_NUM,KC_SPC),           KC_TAB,    LT(L_NAV,KC_ENT),          KC_BSPC,          XXXXXXX
	        //-----------------'-----------------'-----------------'  '-----------------'-----------------'-----------------'
	),

	[L_NUM] = LAYOUT_split_3x6_3(
	//-------,--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,--------,
	  XXXXXXX, XXXXXXX,    PT_7,    PT_8,    PT_9, XXXXXXX,                      _______, _______, _______, _______, _______, _______,
	//-------|--------|--------|--------|--------|--------,                    |--------|--------|--------|--------|--------|--------|
	  XXXXXXX, _______,    PT_4,    PT_5,    PT_6, XXXXXXX,                      _______, _______, _______, _______, _______, _______,
	//-------|--------|--------|--------|--------|--------,                    |--------|--------|--------|--------|--------|--------|
	  XXXXXXX, XXXXXXX,    PT_1,    PT_2,    PT_3, XXXXXXX,                      _______, _______, _______, _______, _______, _______,
	//-------|--------'--------|--------,--------|--------'--------,  ,--------'--------|--------'--------|--------'--------|--------'
	                    _______,             PT_0,          _______,             _______,          _______,          _______
	        //-----------------'-----------------'-----------------'  '-----------------'-----------------'-----------------'
	),

};

const uint16_t combomaps[][3*6] = {
	[R_A] = {
		//-----------,------------,------------,     ,------------,------------,------------,
		      XXXXXXX,        PT_Q,        PT_W,           _______,     PT_TILD,     XXXXXXX,
		//-----------|------------|------------|     |------------|------------|------------|
		  _CS(PT_ESC),   _SG(PT_Z),   _GA(PT_Y),         _GA(PT_J),   _SG(PT_K),_CS(PT_CCED),
		//-----------|------------|------------|     |------------|------------|------------|
		      XXXXXXX,        PT_X,        PT_V,           _______,     PT_ACUT,     XXXXXXX
		//-----------'------------|------------'     '------------|------------'------------'
	},
};


// style_t *current_style = &style_alpha;
// 
// extern void animation_next_mode(style_t *style);
// extern void animation_previous_mode(style_t *style);

const uint16_t cb_tap_kcs[] = {
	PT_DLR,
	PT_ASTR,
	PT_EQL,
	PT_LPRN,
	PT_EXLM,
	PT_RPRN,
	PT_QUES,
	PT_QUES,
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
		
		case _CS(CB_DLR):
		case _SG(CB_ASTR):
		case _GA(CB_EQL):
		case _GA(CB_LPRN):
		case _SG(CB_EXLM):
		case _CS(CB_RPRN):
			cb_kc = cb_tap_kcs[0b111 & (keycode - CB_DLR)];
			
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



void keyboard_post_init_user(void) {
	// Set a specific RGB lighting mode
	// rgblight_mode(RGBLIGHT_MODE_BREATHING); // Replace with your desired mode
	// rgb_matrix_set_color(0, 0x00, 0x00, 0xff);
	// transaction_register_rpc(USER_SYNC_LOCK, user_sync_lock_slave_handler);
	#ifdef COMMAND_ENABLE
	debug_enable=true;
	debug_matrix=true;
	#endif // COMMAND_ENABLE
	
	const uint8_t led_flags[] = {
		2,2,2,2,2,2,
		1,0,0,0,
		4,4,4,1,
		0,4,4,4,
		4,4,4,
		0,4,0,
		0,1,1,
		
		2,2,2,2,2,2,
		1,0,0,0,
		4,4,4,1,
		0,4,4,4,
		4,4,4,
		0,4,0,
		0,1,1
	};
	memcpy(&g_led_config.flags, &led_flags, sizeof(led_flags));
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
	const uint8_t layer_leds[] = {
		[L_BASE] = 0,
		[L_GAME] = MOD_11,
		[L_ALT] = MOD_2,
		[L_NUM] = MOD_4,
		[L_NAV] = MOD_6,
		[L_CMD] = MOD_3,
	};
	for (uint8_t i = 1; i < 6; i++) {
		if (layer_state_is(i))
			RGB_MATRIX_INDICATOR_SET_COLOR(layer_leds[i], rgb.r, rgb.g, rgb.b);
	}

	return false;
}
#endif //RGB_MATRIX_ENABLE

