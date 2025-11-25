

#include QMK_KEYBOARD_H
#include "keymap_portuguese.h"
#include "color.h"
#include "config.h"

enum layers {
	L_BASE,
	L_BASE2,
	L_CCED,
	L_GAME,
	L_GNUM,
	L_FUN,
	L_NUM,
	L_SYM,
	L_NAV,
	L_CMD,
	L_MSE,
};

#define DF_BASE DF(L_BASE)
#define DF_GAME DF(L_GAME)

// Tap-hold keys definitions
#define MG_SFT SFT_T(KC_CAPS)

// home row mods
#define _C(kc) CTL_T(kc)
#define _S(kc) SFT_T(kc)
#define _G(kc) GUI_T(kc)
#define _A(kc) ALT_T(kc)
#define _CS(kc) MT(MOD_LCTL | MOD_LSFT, (kc))
#define _SG(kc) MT(MOD_LGUI | MOD_LSFT, (kc))
#define _GA(kc) MT(MOD_LGUI | MOD_LALT, (kc))
#define _SA(kc) MT(MOD_LSFT | MOD_LALT, (kc))

#define MY_SPC LT(L_NUM,KC_SPC)
#define MY_TAB _S(KC_TAB)


enum custom_keycodes {
	M_0B = KC_INT1, // 0b
	M_0X, // 0x
	M_PDIR, // ../
	ND_TILD,
	ND_CIRC,
	ND_TICK,
	
	MPT_ATL, // ã
	MPT_ACR, // â
	MPT_AAC, // á
	MPT_AGR, // à
	MPT_EAC, // é
	MPT_ECR, // ê
	MPT_IAC, // í
	MPT_OAC, // ó
	MPT_OCR, // ô
	MPT_UAC, // ú
	MPT_NTL, // ñ
	MPT_AO, // ão
	MPT_OES, // ões
	
	M_COME, // ,!
	M_DOTQ, // .?
	M_QUOTDQUO, // '"
	
	MT_LB2,
	MT_MSF,
	MPT_QU,
	
	// CB_BSLS,
	// CB_MINS,
	// CB_EQL,
	// CB_LPRN,
	// CB_EXLM,
	// CB_RPRN,
};


// const key_override_t cedilla_ko = ko_make_basic(MOD_BIT(KC_ALGR), HRM_QT, PT_CCED);
// const key_override_t quote_ko = ko_make_basic(MOD_MASK_SHIFT, HRM_QT, PT_DQUO);
// const key_override_t spc_bsps_ko = ko_make_basic(MOD_MASK_SHIFT, LT(L_NUM,KC_SPC), LT(L_NUM,KC_BSPC));
// const key_override_t bsps_del_ko = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
// const key_override_t tab_ent_ko = ko_make_basic(MOD_MASK_SHIFT, KC_TAB, KC_ENT);

// const key_override_t comm_bsls_ko = ko_make_basic(MOD_BIT(KC_LSFT), PT_COMM, PT_AT);
// const key_override_t dot_perc_ko = ko_make_basic(MOD_BIT(KC_LSFT), PT_DOT, PT_PERC);
// const key_override_t dquo_at_ko = ko_make_basic(MOD_BIT(KC_LSFT), PT_DQUO, PT_HASH);
// const key_override_t quot_tick_ko = ko_make_basic(MOD_BIT(KC_LSFT), PT_QUOT, PT_DLR);
// const key_override_t quot_dquo_ko = ko_make_basic(MOD_BIT(KC_LSFT), PT_QUOT, PT_DQUO);

// const key_override_t shift_caps_ko = ko_make_basic(MOD_BIT(KC_LSFT), OSM(MOD_LSFT), KC_CAPS);



// This globally defines all key overrides to be used´
const key_override_t *key_overrides[] = {
	// &spc_bsps_ko,
	// &bsps_del_ko,
	// &tab_ent_ko,
	// &comm_bsls_ko,
	// &dot_perc_ko,
	// &dquo_at_ko,
	// &quot_tick_ko,
	// &quot_dquo_ko,
	// &shift_caps_ko,
};

#define _CB(cb,kc) COMBO(cb,kc)
#define _DC(name,k1,k2) const uint16_t PROGMEM (name)[] = {(k1),(k2),COMBO_END};
#define _TC(name,k1,k2,k3) const uint16_t PROGMEM (name)[] = {(k1),(k2),(k3),COMBO_END};

// Combos definitions
_TC(cb_escl, _G(PT_D), PT_B, PT_M)
_TC(cb_tabl, _G(PT_D), _A(PT_N), _S(PT_S))
_TC(cb_dell, PT_B, PT_M, PT_G)
_TC(cb_bspl, _A(PT_N), _S(PT_S), _C(PT_T))
_TC(cb_enterl, PT_F, PT_C, PT_P)

_TC(cb_escr, PT_O, PT_U, _G(PT_I))
_TC(cb_tabr, _S(PT_A), _A(PT_E), _G(PT_I))
_TC(cb_delr, PT_L, PT_O, PT_U)
_TC(cb_bspr, _C(PT_R), _S(PT_A), _A(PT_E))
_TC(cb_enterr, PT_H, M_COME, M_DOTQ)

_DC(cb_dquo, M_COME, M_DOTQ)
_DC(cb_agr, _C(MPT_ATL), _S(MPT_AAC))

_DC(cb_f10, KC_F1, KC_F2)
_DC(cb_f11, KC_F2, KC_F3)
_DC(cb_f12, KC_F4, KC_F5)
_DC(cb_brdn, KC_F7, KC_F8)
_DC(cb_brup, KC_F8, KC_F9)

combo_t key_combos[] = {
	_CB(cb_escl, KC_ESC),
	_CB(cb_tabl, KC_TAB),
	_CB(cb_dell, KC_DEL),
	_CB(cb_bspl, KC_BSPC),
	_CB(cb_enterl, KC_ENT),
	
	_CB(cb_escr, KC_ESC),
	_CB(cb_tabr, KC_TAB),
	_CB(cb_delr, KC_DEL),
	_CB(cb_bspr, KC_BSPC),
	_CB(cb_enterr, KC_ENT),
	
	_CB(cb_dquo, PT_DQUO),
	_CB(cb_agr, MPT_AGR),
	
	_CB(cb_f10, KC_F10),
	_CB(cb_f11, KC_F11),
	_CB(cb_f12, KC_F12),
	_CB(cb_brdn, KC_BRID),
	_CB(cb_brup, KC_BRIU),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[L_BASE] = LAYOUT_split_1333_2(
	         //--------,--------,--------,                    ,--------,--------,--------,
	               PT_B,    PT_M,    PT_G,                         PT_L,    PT_O,    PT_U,
	//--------|--------|--------|--------|      ROMAK 24      |--------|--------|--------|--------,
	  _G(PT_D),_A(PT_N),_S(PT_S),_C(PT_T),                     _C(PT_R),_S(PT_A),_A(PT_E),_G(PT_I),
	//--------|--------|--------|--------|                    |--------|--------|--------|--------'
	               PT_F,    PT_C,    PT_P,                         PT_H,  M_COME,  M_DOTQ,
	         //--------'--------|--------'--------,  ,--------'--------|--------'--------|
	            LT(L_FUN,QK_REP), LT(L_NUM,KC_SPC),    LT(L_SYM,MT_LB2), LT(L_NAV,MT_MSF)
	         //-----------------'-----------------'  '-----------------'-----------------'
	),

	[L_BASE2] = LAYOUT_split_1333_2(
	         //--------,--------,--------,                    ,--------,--------,--------,
	               PT_Q,  MPT_QU,    PT_K,                      MPT_OCR, MPT_OAC, MPT_UAC,
	//--------|--------|--------|--------|      ROMAK 24      |--------|--------|--------|--------,
	  _G(PT_Y),_A(PT_Z),_S(PT_X),_C(PT_W),                  _C(MPT_ATL),_S(MPT_AAC),_A(MPT_EAC),_G(MPT_IAC),
	//--------|--------|--------|--------|                    |--------|--------|--------|--------'
	               PT_J, PT_CCED,    PT_V,                      MPT_OES, MPT_ACR, MPT_ECR,
	         //--------'--------|--------'--------,  ,--------'--------|--------'--------|
	                     PT_QUOT,          _______,             _______,          _______
	         //-----------------'-----------------'  '-----------------'-----------------'
	),

	[L_CCED] = LAYOUT_split_1333_2(
	         //--------,--------,--------,                    ,--------,--------,--------,
	            _______, _______, _______,                      _______, _______, _______,
	//--------|--------|--------|--------|                    |--------|--------|--------|--------,
	   _______, _______,_______,_C(MPT_AO),                  _C(MPT_ATL), _______, _______, _______,
	//--------|--------|--------|--------|                    |--------|--------|--------|--------'
	            _______, _______, MPT_OES,                      MPT_OES, _______, _______,
	         //--------'--------|--------'--------,  ,--------'--------|--------'--------|
	                     _______,          _______,             _______,          _______
	         //-----------------'-----------------'  '-----------------'-----------------'
	),

	[L_NAV] = LAYOUT_split_1333_2(
	         //--------,--------,--------,                    ,--------,--------,--------,
	             KC_NUM, KC_CAPS, DF_GAME,                      KC_HOME,   KC_UP,  KC_END,
	//--------|--------|--------|--------|                    |--------|--------|--------|--------,
	_G(KC_PSCR),_A(KC_VOLD),_S(KC_MUTE),_C(KC_VOLU),            KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,
	//--------|--------|--------|--------|                    |--------|--------|--------|--------'
	            KC_MPRV, KC_MPLY, KC_MNXT,                      KC_PGDN, XXXXXXX, KC_PGUP,
	         //--------'--------|--------'--------,  ,--------'--------|--------'--------|
	                     _______,          _______,             _______,          _______
	         //-----------------'-----------------'  '-----------------'-----------------'
	),

	[L_NUM] = LAYOUT_split_1333_2(
	         //--------,--------,--------,                    ,--------,--------,--------,
	            PT_EURO, ND_TICK,    M_0B,                         PT_7,    PT_8,    PT_9,
	//--------|--------|--------|--------|                    |--------|--------|--------|--------,
	     PT_AT, PT_PERC, PT_HASH, PT_UNDS,                         PT_4,    PT_5,    PT_6,  PT_DOT,
	//--------|--------|--------|--------|                    |--------|--------|--------|--------'
	             PT_DLR,  M_PDIR,    M_0X,                         PT_1,    PT_2,    PT_3,
	         //--------'--------|--------'--------,  ,--------'--------|--------'--------|
	                     _______,          _______,    LT(L_SYM,KC_SPC),             PT_0
	         //-----------------'-----------------'  '-----------------'-----------------'
	),

	[L_SYM] = LAYOUT_split_1333_2(
	         //--------,--------,--------,                    ,--------,--------,--------,
	            PT_LABK, PT_SLSH, PT_RABK,                      PT_AMPR, PT_LBRC, PT_RBRC,
	//--------|--------|--------|--------|                    |--------|--------|--------|--------,
	    PT_EQL, PT_COLN, PT_MINS, PT_PLUS,                      PT_PIPE, PT_LPRN, PT_RPRN, PT_BSLS,
	//--------|--------|--------|--------|                    |--------|--------|--------|--------'
	            PT_SCLN, ND_CIRC, PT_ASTR,                      ND_TILD, PT_LCBR, PT_RCBR,
	         //--------'--------|--------'--------,  ,--------'--------|--------'--------|
	                     _______,          _______,             _______,          _______
	         //-----------------'-----------------'  '-----------------'-----------------'
	),

	[L_FUN] = LAYOUT_split_1333_2(
	         //--------,--------,--------,                    ,--------,--------,--------,
	              KC_F7,   KC_F8,   KC_F9,                      MS_WHLL,   MS_UP, MS_WHLR,
	//--------|--------|--------|--------|                    |--------|--------|--------|--------,
	   QK_BOOT,   KC_F4,   KC_F5,   KC_F6,                      MS_LEFT, MS_DOWN, MS_RGHT, MS_BTN3,
	//--------|--------|--------|--------|                    |--------|--------|--------|--------'
	              KC_F1,   KC_F2,   KC_F3,                      MS_WHLD, _______, MS_WHLU,
	         //--------'--------|--------'--------,  ,--------'--------|--------'--------|
	                     _______,          _______,             MS_BTN1,          MS_BTN2
	         //-----------------'-----------------'  '-----------------'-----------------'
	),
	
#if 0
	[L_GAME] = LAYOUT_split_1333_2(
	//--------,--------,--------,--------,--------,  ,--------,--------,--------,--------,--------,
	    KC_TAB,    PT_Q,    PT_W,    PT_E,    PT_R,    _______, _______, _______, _______, _______,
	//--------|--------|--------|--------|--------|  |--------|--------|--------|--------|--------|
	   KC_LSFT,    PT_A,    PT_S,    PT_D,    PT_F,    _______, _______, _______, _______, _______,
	//--------|--------|--------|--------|--------|  |--------|--------|--------|--------|--------|
	   KC_LCTL,    PT_Z,    PT_X,    PT_C,    PT_V,    _______, _______, _______, _______, _______,
	//--------'--------|--------|--------|--------|  |--------|--------|--------|--------'--------'
	                  _A(KC_ESC),KC_SPC,OSL(L_GNUM),   _______, _______, _______
	                  //--------'--------'--------'  '--------'--------'--------'
	),

	[L_GNUM] = LAYOUT_split_1333_2(
	//--------,--------,--------,--------,--------,  ,--------,--------,--------,--------,--------,
	      PT_6,    PT_7,    PT_8,    PT_9,    PT_0,    _______, _______, _______, _______, _______,
	//--------|--------|--------|--------|--------|  |--------|--------|--------|--------|--------|
	      PT_1,    PT_2,    PT_3,    PT_4,    PT_5,    _______, _______, _______, _______, _______,
	//--------|--------|--------|--------|--------|  |--------|--------|--------|--------|--------|
	   XXXXXXX, XXXXXXX,    PT_B,    PT_G,    PT_T,    _______, _______, _______, _______, _______,
	//--------'--------|--------|--------|--------|  |--------|--------|--------|--------'--------'
	                     XXXXXXX, XXXXXXX, XXXXXXX,    _______, _______, _______
	                  //--------'--------'--------'  '--------'--------'--------'
	),

	[L_CMD] = LAYOUT_split_1333_2(
	//--------,--------,--------,--------,--------,  ,--------,--------,--------,--------,--------,
	   RM_TOGG, XXXXXXX, XXXXXXX, KC_BRID, KC_BRIU,    KC_SLEP, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
	//--------|--------|--------|--------|--------|  |--------|--------|--------|--------|--------|
	   RM_SPDU, RM_VALU, RM_SATU, RM_HUEU, RM_NEXT,    KC_WAKE, XXXXXXX, XXXXXXX, XXXXXXX,  EE_CLR,
	//--------|--------|--------|--------|--------|  |--------|--------|--------|--------|--------|
	   RM_SPDD, RM_VALD, RM_SATD, RM_HUED, RM_PREV,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DB_TOGG,
	//--------'--------|--------|--------|--------|  |--------|--------|--------|--------'--------'
	                     _______, _______, _______,    _______, _______, _______
	                  //--------'--------'--------'  '--------'--------'--------'
	),
#endif

};

	// [L_] = LAYOUT_split_3x5_2(
	//          //--------,--------,--------,                    ,--------,--------,--------,
	//             _______, _______, _______,                      _______, _______, _______,
	// //--------|--------|--------|--------|                    |--------|--------|--------|--------,
	//    _______, _______, _______, _______,                      _______, _______, _______, _______,
	// //--------|--------|--------|--------|                    |--------|--------|--------|--------'
	//             _______, _______, _______,                      _______, _______, _______,
	//          //--------'--------|--------'--------,  ,--------'--------|--------'--------|
	//                      _______,          _______,             _______,          _______
	//          //-----------------'-----------------'  '-----------------'-----------------'
	// ),


static void tap_code_unshifted(uint16_t keycode) {
	// push shift status
	uint8_t mods = get_mods();
	bool l_shift_held = mods & MOD_BIT(KC_LSFT);
	bool r_shift_held = mods & MOD_BIT(KC_RSFT);
	if (l_shift_held) unregister_code(KC_LSFT);
	if (r_shift_held) unregister_code(KC_RSFT);
	
	tap_code16(keycode);
	
	// pop shift status
	if (l_shift_held) register_code(KC_LSFT);
	if (r_shift_held) register_code(KC_RSFT);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	bool retval = true;
	bool clear_one_shot_layers = true;
	
	// for performance reasons, this switch should apply to custom keycodes
	// only. So it can create a small jump table.
	switch (keycode) {
		case M_0B:
			if (record->event.pressed) SEND_STRING("0b");
			retval = false;
			break;
		case M_0X:
			if (record->event.pressed) SEND_STRING("0x");
			retval = false;
			break;
		
		case M_PDIR:
			if (record->event.pressed) SEND_STRING("..&"); // equiv to ../ in us ansi
			retval = false;
			break;

		case ND_TILD:
			if (record->event.pressed) SEND_STRING(SS_TAP(X_NUHS)" ");//SS_TAP(PT_TILD) SS_TAP(PT_TILD));
			retval = false;
			break;
		case ND_CIRC:
			if (record->event.pressed) SEND_STRING(SS_LSFT(SS_TAP(X_NUHS))" ");//SS_TAP(PT_CIRC) SS_TAP(PT_CIRC));
			retval = false;
			break;
		case ND_TICK:
			if (record->event.pressed) SEND_STRING("} ");//SS_TAP(PT_GRV) SS_TAP(PT_GRV));
			retval = false;
			break;
	
		case MPT_ATL: // ã
			if (record->event.pressed) {
				tap_code_unshifted(PT_TILD);
				tap_code(PT_A);
			}
			retval = false;
			break;
		case MPT_ACR: // â
			if (record->event.pressed) {
				tap_code_unshifted(PT_CIRC);
				tap_code(PT_A);
			}
			retval = false;
			break;
		case MPT_AAC: // á
			if (record->event.pressed) {
				tap_code_unshifted(PT_ACUT);
				tap_code(PT_A);
			}
			retval = false;
			break;
		case MPT_AGR: // à
			if (record->event.pressed) {
				tap_code_unshifted(PT_GRV);
				tap_code(PT_A);
			}
			retval = false;
			break;
		case MPT_EAC: // é
			if (record->event.pressed) {
				tap_code_unshifted(PT_ACUT);
				tap_code(PT_E);
			}
			retval = false;
			break;
		case MPT_ECR: // ê
			if (record->event.pressed) {
				tap_code_unshifted(PT_CIRC);
				tap_code(PT_E);
			}
			retval = false;
			break;
		case MPT_IAC: // í
			if (record->event.pressed) {
				tap_code_unshifted(PT_ACUT);
				tap_code(PT_I);
			}
			retval = false;
			break;
		case MPT_OAC: // ó
			if (record->event.pressed) {
				tap_code_unshifted(PT_ACUT);
				tap_code(PT_O);
			}
			retval = false;
			break;
		case MPT_OCR: // ô
			if (record->event.pressed) {
				tap_code_unshifted(PT_CIRC);
				tap_code(PT_O);
			}
			retval = false;
			break;
		case MPT_UAC: // ú
			if (record->event.pressed) {
				tap_code_unshifted(PT_ACUT);
				tap_code(PT_U);
			}
			retval = false;
			break;
		case MPT_NTL: // ñ
			if (record->event.pressed) {
				tap_code_unshifted(PT_TILD);
				tap_code(PT_N);
			}
			retval = false;
			break;
		case MPT_AO: // ão
			if (record->event.pressed) {
				tap_code_unshifted(PT_TILD);
				tap_code(PT_A);
				tap_code(PT_O);
			}
			retval = false;
			break;
		case MPT_OES: // ões
			if (record->event.pressed) {
				tap_code_unshifted(PT_TILD);
				tap_code(PT_O);
				tap_code(PT_E);
				tap_code(PT_S);
			}
			retval = false;
			break;
		case MPT_QU: // qu
			if (record->event.pressed) {
				tap_code(PT_Q);
				tap_code(PT_U);
			}
			retval = false;
			break;
		
		case M_COME: // ,!
			if (record->event.pressed) {
				if (get_mods() & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT)))
					tap_code_unshifted(PT_EXLM);
				else
					tap_code_unshifted(PT_COMM);
			}
			retval = false;
			break;
		case M_DOTQ: // .?
			if (record->event.pressed) {
				if (get_mods() & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT)))
					tap_code_unshifted(PT_QUES);
				else
					tap_code_unshifted(PT_DOT);
			}
			retval = false;
			break;

		case LT(L_SYM,MT_LB2):
			if (record->tap.count) {
				clear_one_shot_layers = false;
				if ( record->event.pressed) {
					set_oneshot_layer(L_BASE2, ONESHOT_START);
					retval = false;
				}
			}
			break;
		case LT(L_NAV,MT_MSF):
			clear_one_shot_layers = false;
			if (record->tap.count) {
				if (record->event.pressed) {
					set_oneshot_mods(MOD_BIT(KC_LSFT));
					retval = false;
				}
			}
			break;
	}
	
	if (!record->event.pressed && clear_one_shot_layers)
		clear_oneshot_layer_state(ONESHOT_PRESSED);
	
	return retval;
}

// void process_combo_event(uint16_t combo_index, bool pressed) {
// 	if (pressed && !(default_layer_state & (1 << L_GAME))) {
// 		tap_code16(key_combos[combo_index].keycode);
// 	}
// }


void keyboard_post_init_user(void) {
	#ifdef COMMAND_ENABLE
	debug_enable=true;
	debug_matrix=true;
	#endif // COMMAND_ENABLE
}


#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
	hsv_t hsv = rgb_matrix_config.hsv;
	hsv.h -= rgb_matrix_config.speed;
	hsv.s = 0xff;
	rgb_t rgb = hsv_to_rgb(hsv);
	
	// layer indicators
	if (layer_state_is(L_FUN))
		RGB_MATRIX_INDICATOR_SET_COLOR(LP_L, rgb.r, rgb.g, rgb.b);
	if (is_swap_hands_on())
		RGB_MATRIX_INDICATOR_SET_COLOR(LT_I, rgb.r, rgb.g, rgb.b);
	if (layer_state_is(L_NUM))
		RGB_MATRIX_INDICATOR_SET_COLOR(LT_M, rgb.r, rgb.g, rgb.b);
	if (layer_state_is(L_MSE))
		RGB_MATRIX_INDICATOR_SET_COLOR(LT_O, rgb.r, rgb.g, rgb.b);
	
	if (layer_state_is(L_SYM))
		RGB_MATRIX_INDICATOR_SET_COLOR(RT_M, rgb.r, rgb.g, rgb.b);
	if (layer_state_is(L_CMD))
		RGB_MATRIX_INDICATOR_SET_COLOR(RT_I, rgb.r, rgb.g, rgb.b);
	if (layer_state_is(L_PT))
		RGB_MATRIX_INDICATOR_SET_COLOR(RP_L, rgb.r, rgb.g, rgb.b);
		
	if (layer_state_is(L_NAV)) {
		RGB_MATRIX_INDICATOR_SET_COLOR(RT_O, rgb.r, rgb.g, rgb.b);
		if (default_layer_state & (1 << L_BASE))
			RGB_MATRIX_INDICATOR_SET_COLOR(LM_H, rgb.r, rgb.g, rgb.b);
		if (default_layer_state & (1 << L_GAME))
			RGB_MATRIX_INDICATOR_SET_COLOR(LO_H, rgb.r, rgb.g, rgb.b);
		
		if (host_keyboard_led_state().caps_lock)
			RGB_MATRIX_INDICATOR_SET_COLOR(LR_H, rgb.r, rgb.g, rgb.b);
		if (host_keyboard_led_state().num_lock)
			RGB_MATRIX_INDICATOR_SET_COLOR(LP_H, rgb.r, rgb.g, rgb.b);
	}

	return false;
}
#endif //RGB_MATRIX_ENABLE


#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case L_BASE:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case L_NAV:
            oled_write_P(PSTR("Nav\n"), false);
            break;
        case L_NUM:
            oled_write_P(PSTR("Num\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Other"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
    
    return false;
}
#endif
