

#include QMK_KEYBOARD_H
#include "keymap_portuguese.h"

#include "print.h"

enum layers {
	L_BASE,
	L_LOL,
	//L_GNUM,
	//L_PT,
	L_ACT,
	L_NUM,
	L_SYM,
	L_NAV,
	L_MSE,
	N_LAYERS,
};

#define DF_BASE DF(L_BASE)
#define DF_LOL DF(L_LOL)
#define DF_MSE DF(L_MSE)

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
	MPT_OES, // õe

	M_COMUS, // ,_
//	M_DOTDQ, // ."
	M_QUOTDQUO, // '"

	// CB_BSLS,
	// CB_MINS,
	// CB_EQL,
	// CB_LPRN,
	// CB_EXLM,
	// CB_RPRN,
};

#define L_ENC XXXXXXX
#define R_ENC XXXXXXX

const key_override_t semicolon_key_override = ko_make_basic(MOD_MASK_SHIFT, PT_SCLN, PT_COLN);
const key_override_t dot_key_override = ko_make_basic(MOD_MASK_SHIFT, PT_DOT, PT_RABK);
const key_override_t comma_key_override = ko_make_basic(MOD_MASK_SHIFT, PT_COMM, PT_LABK);
const key_override_t slash_key_override = ko_make_basic(MOD_MASK_SHIFT, PT_SLSH, PT_QUES);

// This globally defines all key overrides to be used´
const key_override_t *key_overrides[] = {
	&semicolon_key_override,
	&dot_key_override,
	&comma_key_override,
	&slash_key_override,
};

#define _CB(cb,kc) COMBO(cb,kc)
#define _DC(name,k1,k2) const uint16_t PROGMEM (name)[] = {(k1),(k2),COMBO_END};
#define _TC(name,k1,k2,k3) const uint16_t PROGMEM (name)[] = {(k1),(k2),(k3),COMBO_END};

// Combos definitions
_DC(cb_quote, M_COMUS, PT_DOT)

combo_t key_combos[] = {
	_CB(cb_quote, PT_QUOT),
};

#define MY_ESC LT(L_ACT, KC_ESC)
#define MY_SPC LT(L_NAV, KC_SPC)
#define MY_TAB KC_TAB
#define MY_BSPC LT(L_SYM, KC_BSPC)
#define MY_ENT LT(L_ACT, KC_ENT)
#define MY_DEL LT(L_NUM, KC_DEL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[L_BASE] = LAYOUT_Swoopiest(
//--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,
      PT_Q,    PT_W,    PT_R,    PT_F,    PT_K,                         PT_J,    PT_L,    PT_U,    PT_O,    PT_Y,
//--------|--------|--------|--------|--------|       ROLMAK       |--------|--------|--------|--------|--------|
     PT_A ,   PT_S ,   PT_D ,   PT_T ,    PT_G,                         PT_P,   PT_N ,   PT_E ,   PT_I ,   PT_H ,
//--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|
      PT_Z,  PT_X,    PT_C,    PT_V,    PT_B,                        PT_SCLN,  PT_M,  PT_COMM, PT_DOT,  PT_SLSH ,
//--------'--------'--------'--------|--------|--------,  ,--------|--------|--------'--------'--------'--------'
	                                  KC_LSFT,  KC_LCTL,    KC_RCTL, KC_RSFT,
                  //--------,--------|--------|--------|  |--------|--------|--------,--------,
                    DF_MSE,   MY_ESC, MY_BSPC,  MY_DEL,     MY_ENT, MY_SPC,   MY_TAB , KC_LGUI
                  //--------'--------'--------'--------'  '-----------------'-----------------'
),

[L_NAV] = LAYOUT_Swoopiest(
//--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,
  XXXXXXX, XXXXXXX,   KC_UP,  XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX,   XXXXXXX,  XXXXXXX, XXXXXXX,
//--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|
   XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,                      LGUI(PT_1), LGUI(PT_2), LGUI(PT_3), LGUI(PT_4), LGUI(PT_5),
//--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|
   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      LSG(PT_1), LSG(PT_2), LSG(PT_3), LSG(PT_4), LSG(PT_5),
//--------'--------'--------'--------|--------|--------,  ,--------|--------|--------'--------'--------'--------'
                                       KC_MPLY, KC_MPRV,    XXXXXXX, XXXXXXX,
                  //--------,--------|--------|--------|  |--------|--------|--------,--------,
                     KC_MUTE, XXXXXXX, KC_LALT, KC_MNXT,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                  //--------'--------'--------'--------'  '-----------------'-----------------'
),

[L_MSE] = LAYOUT_Swoopiest(
//--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,
   XXXXXXX, XXXXXXX,   MS_UP,  XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, MS_WHLU, XXXXXXX, PT_Y,
//--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|
   XXXXXXX, MS_LEFT, MS_DOWN, MS_RGHT, KC_PGUP,                      MS_BTN1, MS_WHLL, MS_WHLD, MS_WHLR, MS_BTN4,
//--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|
     PT_Z,   PT_X,   PT_C,    PT_V,   KC_PGDN,                      MS_BTN2, MS_BTN3, XXXXXXX, XXXXXXX, MS_BTN5,
//--------'--------'--------'--------|--------|--------,  ,--------|--------|--------'--------'--------'--------'
                                      KC_LSFT,  KC_LCTL,   KC_RCTL, KC_RSFT,
                  //--------,--------|--------|--------|  |--------|--------|--------,--------,
                     DF_BASE, XXXXXXX, XXXXXXX, XXXXXXX,    KC_PSCR, XXXXXXX, XXXXXXX, DF_LOL
                  //--------'--------'--------'--------'  '-----------------'-----------------'
),

[L_NUM] = LAYOUT_Swoopiest(
//--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,
 XXXXXXX,   KC_F7,   KC_F8,   KC_F9,  KC_F12,                     XXXXXXX,   PT_7,   PT_8,   PT_9,  XXXXXXX,
//--------|--------|--------|--------|--------,                    |--------|--------|--------|--------|--------|
  XXXXXXX,   KC_F4,   KC_F5,   KC_F6,  KC_F11,                     XXXXXXX,   PT_4,   PT_5,   PT_6, PT_DOT,
//--------|--------|--------|--------|--------,                    |--------|--------|--------|--------|--------|
  XXXXXXX,   KC_F1,   KC_F2,   KC_F3,  KC_F10,                       XXXXXXX, PT_1,   PT_2,   PT_3,  PT_COMM,
//--------'--------'--------'--------|--------|--------,  ,--------|--------|--------'--------'--------'--------'
                                       XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,
                  //--------,--------|--------|--------|  |--------|--------|--------,--------,
                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_ENT,  KC_0,  XXXXXXX, XXXXXXX
                  //--------'--------'--------'--------'  '-----------------'-----------------'
),

[L_SYM] = LAYOUT_Swoopiest(
//--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,
   XXXXXXX, XXXXXXX, PT_UNDS, PT_PLUS, XXXXXXX,                      PT_RBRC, PT_RPRN, PT_RCBR, PT_MORD, PT_FORD,
//--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|
    PT_EXLM, PT_AT, PT_HASH,  PT_DLR, PT_PERC,                      ND_CIRC, PT_AMPR, PT_ASTR, PT_QUOT,  PT_BSLS,
//--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|
    KC_LCTL, XXXXXXX, PT_MINS, PT_EQL, XXXXXXX,                      PT_LBRC, PT_LPRN, PT_LCBR, PT_DQUO, PT_PIPE,
//--------'--------'--------'--------|--------|--------,  ,--------|--------|--------'--------'--------'--------'
                                       XXXXXXX, XXXXXXX,    PT_CIRC, PT_TILD,
                  //--------,--------|--------|--------|  |--------|--------|--------,--------,
                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    PT_CCED, PT_ACUT, PT_GRV, XXXXXXX
                  //--------'--------'--------'--------'  '-----------------'-----------------'
),

[L_ACT] = LAYOUT_Swoopiest(
//--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,
XXXXXXX,LGUI(KC_W),XXXXXXX,LGUI(KC_F), XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//--------|--------|--------|--------|--------,                    |--------|--------|--------|--------|--------|
  XXXXXXX ,XXXXXXX ,XXXXXXX, LGUI(KC_T),  XXXXXXX,                  XXXXXXX, LGUI(KC_N), XXXXXXX, XXXXXXX, XXXXXXX,
//--------|--------|--------|--------|--------,                    |--------|--------|--------|--------|--------|
   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX ,XXXXXXX,                      LGUI(KC_SPC), LAG(KC_SPC), XXXXXXX, XXXXXXX, XXXXXXX,
//--------'--------'--------'--------|--------|--------,  ,--------|--------|--------'--------'--------'--------'
                                       XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,
                  //--------,--------|--------|--------|  |--------|--------|--------,--------,
                     XXXXXXX, XXXXXXX, KC_PSCR, LCG(KC_T),    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                  //--------'--------'--------'--------'  '-----------------'-----------------'
),

[L_LOL] = LAYOUT_Swoopiest(
//--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,
     PT_1,    PT_2,    PT_3,    PT_4,   PT_5,                         PT_J,    PT_L,    PT_U,    PT_O,    PT_Y,
//--------|--------|--------|--------|--------|       ROLMAK       |--------|--------|--------|--------|--------|
     PT_Q,    PT_W,    PT_E,    PT_R,    PT_F,                         PT_P,   PT_N ,   PT_E ,   PT_I ,   PT_H ,
//--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|
      KC_TAB,  PT_T,    PT_C,    PT_D,    PT_S,                        PT_SCLN,  PT_M,  PT_COMM, PT_DOT,  PT_SLSH ,
//--------'--------'--------'--------|--------|--------,  ,--------|--------|--------'--------'--------'--------'
	                                  PT_H,      PT_B,        KC_RCTL, KC_RSFT,
                  //--------,--------|--------|--------|  |--------|--------|--------,--------,
                    KC_RCTL, KC_LCTL, KC_LSFT, KC_SPC,     MY_ENT, MY_SPC,   MY_TAB , DF_BASE
                  //--------'--------'--------'--------'  '-----------------'-----------------'
),

/*
[L_PT] = LAYOUT_Swoopiest(
//-------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,
    PT_GRV, PT_ACUT, PT_CIRC, PT_TILD, PT_DIAE,                      XXXXXXX, XXXXXXX, MPT_UAC, MPT_OAC, XXXXXXX,
//--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|
   MPT_ATL, MPT_AAC, PT_CCED,  MPT_AO, XXXXXXX,                      XXXXXXX, MPT_NTL, MPT_EAC, MPT_IAC, XXXXXXX,
//--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|
   MPT_ACR, MPT_AGR, XXXXXXX, MPT_OES, XXXXXXX,                      XXXXXXX, XXXXXXX, MPT_ECR, MPT_OCR, XXXXXXX,
//--------'--------'--------'--------|--------|--------,  ,--------|--------|--------'--------'--------'--------'
                                       XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,
                  //--------,--------|--------|--------|  |--------|--------|--------,--------,
                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                  //--------'--------'--------'--------'  '-----------------'-----------------'
),
*/
/*
` ´ ^ ~   ¨ | _ _ ú ó _
ã á ç ão  _ | _ ñ é í _
â à _ ões _ | _ _ ê ô _
*/

};
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
	[L_BASE] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(QK_MOUSE_WHEEL_DOWN, QK_MOUSE_WHEEL_UP) },
	[L_LOL] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(QK_MOUSE_WHEEL_DOWN, QK_MOUSE_WHEEL_UP) },
	//[L_GNUM] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(QK_MOUSE_WHEEL_DOWN, QK_MOUSE_WHEEL_UP) },
	//  [L_PT] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(QK_MOUSE_WHEEL_DOWN, QK_MOUSE_WHEEL_UP) },
	 [L_ACT] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(QK_MOUSE_WHEEL_DOWN, QK_MOUSE_WHEEL_UP) },
	 [L_NUM] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(QK_MOUSE_WHEEL_DOWN, QK_MOUSE_WHEEL_UP) },
	 [L_SYM] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(QK_MOUSE_WHEEL_DOWN, QK_MOUSE_WHEEL_UP) },
	 [L_NAV] = { ENCODER_CCW_CW(KC_BRIU, KC_BRID), ENCODER_CCW_CW(QK_MOUSE_WHEEL_DOWN, QK_MOUSE_WHEEL_UP) },
	 [L_MSE] = { ENCODER_CCW_CW(QK_MOUSE_WHEEL_RIGHT, QK_MOUSE_WHEEL_LEFT), ENCODER_CCW_CW(QK_MOUSE_WHEEL_DOWN, QK_MOUSE_WHEEL_UP) },
};
#endif

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
	bool shifted = (mods & MOD_MASK_SHIFT);  // Was Shift held?
	switch (keycode) {
		case MY_TAB:
			if (shifted) {        // If the last key was Shift + Tab,
				return KC_TAB;    // ... the reverse is Tab.
			} else {              // Otherwise, the last key was Tab,
				return S(KC_TAB); // ... and the reverse is Shift + Tab.
			}
		case MY_SPC:
			return KC_BSPC;
	}

	return KC_TRNS;
}

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
		// case M_DCLN:
		// 	if (record->event.pressed) SEND_STRING(">>"); // equiv to :: in us ansi
		// 	return false;

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

		case M_COMUS: // ,_
			if (record->event.pressed) {
				if (get_mods() & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT)))
					tap_code_unshifted(PT_UNDS);
				else
					tap_code_unshifted(PT_COMM);
			}
			return false;
		case M_QUOTDQUO: // '"
			if (record->event.pressed) {
				if (get_mods() & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT)))
					tap_code_unshifted(PT_DQUO);
				else
					tap_code_unshifted(PT_QUOT);
			}
			return false;
	}

	return true;
}


// void process_combo_event(uint16_t combo_index, bool pressed) {
// 	if (pressed && !(default_layer_state & (1 << L_LOL))) {
// 		tap_code16(key_combos[combo_index].keycode);
// 	}
// }


void keyboard_post_init_user(void) {
	#ifdef COMMAND_ENABLE
	debug_enable=true;
	debug_matrix=true;
	#endif // COMMAND_ENABLE
}
