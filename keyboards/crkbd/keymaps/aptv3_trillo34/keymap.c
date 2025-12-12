

#include QMK_KEYBOARD_H
#include "keymap_portuguese.h"
#include "color.h"

enum layers {
	L_BASE,
	L_GAME,
	L_GNUM,
	L_PT,
	L_FUN,
	L_NUM,
	L_SYM,
	L_NAV,
	L_MSE,
	L_RGB,
	N_LAYERS,
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


enum custom_keycodes {
	M_0B = KC_INT1, // 0b
	M_0X, // 0x
	M_PDIR, // ../
	ND_TILD, // ~
	ND_CIRC, // ^
	ND_TICK, // `
	
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
	MPT_AO,  // ão
	MPT_OES, // õe
	
	M_DSHDQ,    // - "
	M_COMUS,    // , _
	M_DOTCL,    // . :
	M_QTIQT, // ' I'
	
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
_DC(cb_esc, PT_W, PT_G)
_DC(cb_tab, LT(L_FUN,PT_X), PT_C)
_DC(cb_del, PT_F, PT_K)
_DC(cb_bsp, _A(PT_H), PT_B)
_DC(cb_enter, PT_P, PT_V)
//_DC(cb_bpsc, M_COMUS, M_DOTCL)


combo_t key_combos[] = {
	_CB(cb_esc, KC_ESC),
	_CB(cb_tab, KC_TAB),
	_CB(cb_del, KC_DEL),
	_CB(cb_bsp, KC_BSPC),
	_CB(cb_enter, KC_ENT),
//	_CB(cb_bpsc, KC_BSPC),
};

#define MY_ESC SH_T(KC_ESC)
#define MY_SPC LT(L_NUM, KC_SPC)
#define MY_TAB LT(L_MSE, KC_TAB)

#define MY_ENT LT(L_NAV, KC_ENT)
#define MY_BSPC LT(L_SYM, KC_BSPC)
//#define MY_BSPC OS_LSFT
#define MY_DEL LT(L_RGB, KC_DEL)
//#define MY_DEL OSL(L_PT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[L_BASE] = LAYOUT_split_3x5_3_on_3x6_3(
	//--------,--------,--------,--------,--------,  ,--------,--------,--------,--------,--------,
	      PT_W,    PT_G,    PT_D,    PT_F,    PT_K,       PT_J,    PT_L,    PT_U,    PT_O,    PT_Y,
	//--------|--------|--------|--------|--------|  |--------|--------|--------|--------|--------|
	  _C(PT_R),_S(PT_S),_G(PT_T),_A(PT_H),    PT_B,       PT_Q,_A(PT_N),_G(PT_E),_S(PT_A),_C(PT_I),
	//--------|--------|--------|--------|--------|  |--------|--------|--------|--------|--------|
	LT(L_FUN,PT_Z),PT_C,    PT_M,    PT_P,    PT_V,    M_DSHDQ,    PT_X, M_COMUS,  PT_DOT,LT(L_PT,M_QTIQT),
	//--------'--------|--------|--------|--------|  |--------|--------|--------|--------'--------'
	                      MY_ESC,  MY_SPC,  MY_TAB,     MY_ENT, MY_BSPC,  MY_DEL
	                  //--------'--------'--------'  '--------'--------'--------'
	                                          /* APTvMR */
	),
	
	[L_NAV] = LAYOUT_split_3x5_3_on_3x6_3(
	//--------,--------,--------,--------,--------,  ,--------,--------,--------,--------,--------,
	    KC_NUM, KC_CAPS, DF_BASE, DF_GAME, _______,    KC_PGUP, KC_HOME,   KC_UP,  KC_END, KC_MPRV,
	//--------|--------|--------|--------|--------|  |--------|--------|--------|--------|--------|
	   KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, KC_BRIU,    KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_MPLY,
	//--------|--------|--------|--------|--------|  |--------|--------|--------|--------|--------|
	   _______, _______, _______, _______, KC_BRID,    KC_PSCR, KC_VOLD, KC_MUTE, KC_VOLU, KC_MNXT,
	//--------'--------|--------|--------|--------|  |--------|--------|--------|--------'--------'
	                     _______, _______, _______,    _______, _______, _______
	                  //--------'--------'--------'  '--------'--------'--------'
	),

	[L_MSE] = LAYOUT_split_3x5_3_on_3x6_3(
	//--------,--------,--------,--------,--------,  ,--------,--------,--------,--------,--------,
	   C(PT_Q), C(PT_W), C(PT_E), C(PT_R), C(PT_A),    MS_WHLU, MS_WHLL,   MS_UP, MS_WHLR, MS_ACL0,
	//--------|--------|--------|--------|--------|  |--------|--------|--------|--------|--------|
	   KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, C(PT_S),    MS_WHLD, MS_LEFT, MS_DOWN, MS_RGHT, MS_ACL1,
	//--------|--------|--------|--------|--------|  |--------|--------|--------|--------|--------|
	   C(PT_Z), C(PT_X), C(PT_C), C(PT_V), C(PT_Y),    MS_BTN6, MS_BTN4, MS_BTN7, MS_BTN5, MS_ACL2,
	//--------'--------|--------|--------|--------|  |--------|--------|--------|--------'--------'
	                     _______, _______, _______,    MS_BTN1, MS_BTN2, MS_BTN3
	                  //--------'--------'--------'  '--------'--------'--------'
	),

	[L_NUM] = LAYOUT_split_3x5_3_on_3x6_3(
	//--------,--------,--------,--------,--------,  ,--------,--------,--------,--------,--------,
	      M_0X,    PT_7,    PT_8,    PT_9, PT_MINS,       PT_F,   KC_P7,   KC_P8,   KC_P9,    PT_C,
	//--------|--------|--------|--------|--------,  |--------|--------|--------|--------|--------|
	  _C(PT_0),_S(PT_4),_G(PT_5),_A(PT_6),  PT_DOT,       PT_E,   KC_P4,   KC_P5,   KC_P6,    PT_B,
	//--------|--------|--------|--------|--------,  |--------|--------|--------|--------|--------|
	      M_0B,    PT_1,    PT_2,    PT_3, PT_COMM,       PT_D,   KC_P1,   KC_P2,   KC_P3,    PT_A,
	//--------'--------|--------|--------|--------|  |--------|--------|--------|--------'--------'
	                     _______, _______, _______,     KC_SPC,   KC_P0, KC_BSPC
	                  //--------'--------'--------'  '--------'--------'--------'
	),

	[L_SYM] = LAYOUT_split_3x5_3_on_3x6_3(
	//--------,--------,--------,--------,--------,  ,--------,--------,--------,--------,--------,
	   ND_CIRC, PT_LABK, PT_RABK, PT_MINS, PT_BSLS,    PT_AMPR, PT_LCBR, PT_QUES, PT_RCBR,  PT_DLR,
	//--------|--------|--------|--------|--------|  |--------|--------|--------|--------|--------|
	   PT_COLN, PT_ASTR, PT_SLSH,  PT_EQL, PT_HASH,    PT_PIPE, PT_LPRN, PT_EXLM, PT_RPRN, PT_SCLN,
	//--------|--------|--------|--------|--------|  |--------|--------|--------|--------|--------|
	   ND_TILD, PT_PLUS, ND_TICK,  M_PDIR, PT_PERC,      PT_AT, PT_LBRC, PT_UNDS, PT_RBRC, PT_EURO,
	//--------'--------|--------|--------|--------|  |--------|--------|--------|--------'--------'
	                     _______, _______, _______,    _______, _______, _______
	                  //--------'--------'--------'  '--------'--------'--------'
	),

	[L_FUN] = LAYOUT_split_3x5_3_on_3x6_3(
	//--------,--------,--------,--------,--------,  ,--------,--------,--------,--------,--------,
	 QK_REBOOT,   KC_F7,   KC_F8,   KC_F9,  KC_F12,    _______, _______, _______, _______, _______,
	//--------|--------|--------|--------|--------,  |--------|--------|--------|--------|--------|
	   QK_BOOT,   KC_F4,   KC_F5,   KC_F6,  KC_F11,    _______, _______, _______, _______, _______,
	//--------|--------|--------|--------|--------,  |--------|--------|--------|--------|--------|
	   XXXXXXX,   KC_F1,   KC_F2,   KC_F3,  KC_F10,    _______, _______, _______, _______, _______,
	//--------'--------|--------|--------|--------|  |--------|--------|--------|--------'--------'
	                     _______, _______, _______,    _______, _______, _______
	                  //--------'--------'--------'  '--------'--------'--------'
	),

	[L_PT] = LAYOUT_split_3x5_3_on_3x6_3(
	//--------,--------,--------,--------,--------,  ,--------,--------,--------,--------,--------,
	    PT_GRV, PT_ACUT, PT_CIRC, PT_TILD, PT_DIAE,    XXXXXXX, XXXXXXX, MPT_UAC, MPT_OAC, XXXXXXX,
	//--------|--------|--------|--------|--------|  |--------|--------|--------|--------|--------|
	   MPT_ATL, MPT_AAC, PT_CCED,  MPT_AO, XXXXXXX,    XXXXXXX, MPT_NTL, MPT_EAC, MPT_IAC, XXXXXXX,
	//--------|--------|--------|--------|--------|  |--------|--------|--------|--------|--------|
	   MPT_ACR, MPT_AGR, XXXXXXX, MPT_OES, XXXXXXX,    XXXXXXX, XXXXXXX, MPT_ECR, MPT_OCR, XXXXXXX,
	//--------'--------|--------|--------|--------|  |--------|--------|--------|--------'--------'
	                     _______, _______, _______,    _______, _______, _______
	                  //--------'--------'--------'  '--------'--------'--------'
	),

/*
` ´ ^ ~   ¨ | _ _ ú ó _
ã á ç ão  _ | _ ñ é í _
â à _ ões _ | _ _ ê ô _
*/

	[L_GAME] = LAYOUT_split_3x5_3_on_3x6_3(
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

	[L_GNUM] = LAYOUT_split_3x5_3_on_3x6_3(
	//--------,--------,--------,--------,--------,  ,--------,--------,--------,--------,--------,
	      PT_6,    PT_7,    PT_8,    PT_9,    PT_0,    _______, _______, _______, _______, _______,
	//--------|--------|--------|--------|--------|  |--------|--------|--------|--------|--------|
	      PT_1,    PT_2,    PT_3,    PT_4,    PT_5,    _______, _______, _______, _______, _______,
	//--------|--------|--------|--------|--------|  |--------|--------|--------|--------|--------|
	    KC_ESC, XXXXXXX,    PT_B,    PT_G,    PT_T,    _______, _______, _______, _______, _______,
	//--------'--------|--------|--------|--------|  |--------|--------|--------|--------'--------'
                         XXXXXXX, XXXXXXX, XXXXXXX,    _______, _______, _______
	                  //--------'--------'--------'  '--------'--------'--------'
	),

	[L_RGB] = LAYOUT_split_3x5_3_on_3x6_3(
	//--------,--------,--------,--------,--------,  ,--------,--------,--------,--------,--------,
	   RM_TOGG, XXXXXXX, XXXXXXX, KC_BRID, KC_BRIU,    KC_SLEP, XXXXXXX, XXXXXXX,  EE_CLR, DB_TOGG,
	//--------|--------|--------|--------|--------|  |--------|--------|--------|--------|--------|
	   RM_SPDU, RM_VALU, RM_SATU, RM_HUEU, RM_NEXT,    KC_WAKE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
	//--------|--------|--------|--------|--------|  |--------|--------|--------|--------|--------|
	   RM_SPDD, RM_VALD, RM_SATD, RM_HUED, RM_PREV,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
	//--------'--------|--------|--------|--------|  |--------|--------|--------|--------'--------'
	                     _______, _______, _______,    _______, _______, _______
	                  //--------'--------'--------'  '--------'--------'--------'
	),
};

	// [L_] = LAYOUT_split_3x5_2(
	// //--------,--------,--------,--------,--------,  ,--------,--------,--------,--------,--------,
	//    _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,
	// //--------|--------|--------|--------|--------|  |--------|--------|--------|--------|--------|
	//    _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,
	// //--------|--------|--------|--------|--------|  |--------|--------|--------|--------|--------|
	//    _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,
	// //--------'--------|--------|--------|--------|  |--------|--------|--------|--------'--------'
	//                      _______, _______, _______,    _______, _______, _______
	//                   //--------'--------'--------'  '--------'--------'--------'
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

		case ND_TILD:
			if (record->event.pressed) SEND_STRING(SS_TAP(X_NUHS)" ");//SS_TAP(PT_TILD) SS_TAP(PT_TILD));
			return false;
		case ND_CIRC:
			if (record->event.pressed) SEND_STRING(SS_LSFT(SS_TAP(X_NUHS))" ");//SS_TAP(PT_CIRC) SS_TAP(PT_CIRC));
			return false;
		case ND_TICK:
			if (record->event.pressed) SEND_STRING("} ");//SS_TAP(PT_GRV) SS_TAP(PT_GRV));
			return false;
	
		case MPT_ATL: // ã
			if (record->event.pressed) {
				tap_code_unshifted(PT_TILD);
				tap_code(PT_A);
			}
			return false;
		case MPT_ACR: // â
			if (record->event.pressed) {
				tap_code_unshifted(PT_CIRC);
				tap_code(PT_A);
			}
			return false;
		case MPT_AAC: // á
			if (record->event.pressed) {
				tap_code_unshifted(PT_ACUT);
				tap_code(PT_A);
			}
			return false;
		case MPT_AGR: // à
			if (record->event.pressed) {
				tap_code_unshifted(PT_GRV);
				tap_code(PT_A);
			}
			return false;
		case MPT_EAC: // é
			if (record->event.pressed) {
				tap_code_unshifted(PT_ACUT);
				tap_code(PT_E);
			}
			return false;
		case MPT_ECR: // ê
			if (record->event.pressed) {
				tap_code_unshifted(PT_CIRC);
				tap_code(PT_E);
			}
			return false;
		case MPT_IAC: // í
			if (record->event.pressed) {
				tap_code_unshifted(PT_ACUT);
				tap_code(PT_I);
			}
			return false;
		case MPT_OAC: // ó
			if (record->event.pressed) {
				tap_code_unshifted(PT_ACUT);
				tap_code(PT_O);
			}
			return false;
		case MPT_OCR: // ô
			if (record->event.pressed) {
				tap_code_unshifted(PT_CIRC);
				tap_code(PT_O);
			}
			return false;
		case MPT_UAC: // ú
			if (record->event.pressed) {
				tap_code_unshifted(PT_ACUT);
				tap_code(PT_U);
			}
			return false;
		case MPT_NTL: // ñ
			if (record->event.pressed) {
				tap_code_unshifted(PT_TILD);
				tap_code(PT_N);
			}
			return false;
		case MPT_AO: // ão
			if (record->event.pressed) {
				tap_code_unshifted(PT_TILD);
				tap_code(PT_A);
				tap_code(PT_O);
			}
			return false;
		case MPT_OES: // ões
			if (record->event.pressed) {
				tap_code_unshifted(PT_TILD);
				tap_code(PT_O);
				tap_code(PT_E);
				tap_code(PT_S);
			}
			return false;
		
		case M_DSHDQ: // - "
			if (record->event.pressed) {
				if (get_mods() & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT)))
					tap_code_unshifted(PT_DQUO);
				else
					tap_code_unshifted(PT_MINS);
			}
			return false;
		case M_COMUS: // ,_
			if (record->event.pressed) {
				if (get_mods() & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT)))
					tap_code_unshifted(PT_UNDS);
				else
					tap_code_unshifted(PT_COMM);
			}
			return false;
		case LT(L_PT,M_QTIQT): // ' I'
			if (record->event.pressed) {
				if (get_mods() & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT))) {
					tap_code(PT_I);
					tap_code_unshifted(PT_QUOT);
				}
				else
					tap_code_unshifted(PT_QUOT);
			}
			return false;
		
		case _C(PT_A):
		case _G(PT_E):
		case _S(PT_I):
			if ( record->tap.count && get_last_keycode() == PT_Q )
				tap_code(PT_U);
			return true;
		case PT_O:
			if ( get_last_keycode() == PT_Q )
				tap_code(PT_U);
			return true;
	}
	
	return true;
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
	if (layer_state_is(L_RGB))
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
