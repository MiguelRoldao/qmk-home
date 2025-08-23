

#include QMK_KEYBOARD_H
#include "keymap_portuguese.h"
#include "color.h"

enum layers {
	L_BASE,
	L_GAME,
	L_ALT,
	L_FUN,
	L_NUM,
	L_SYM,
	L_NAV,
	L_CMD,
	L_GNUM,
};

#define DF_BASE DF(L_BASE)
#define DF_GAME DF(L_GAME)
#define DF_ALT DF(L_ALT)

// #define ALT_COLEMAK_DH
// #define ALT_COLEMAK
#define ALT_COLEMAK_VH
// #define ALT_DEC_HNIOP1
// #define ALT_ROMAK
// #define ALT_ENGRAM
// #define ALT_MIGRAM
// #define ALT_ASET
// #define ALT_APTV3

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
	M_0B = KC_INT1,
	M_0X,
	M_PDIR,
	M_DCLN,
	ND_TILD,
	ND_CIRC,
	ND_TICK,

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
const key_override_t quot_dquo_ko = ko_make_basic(MOD_BIT(KC_LSFT), PT_QUOT, PT_DQUO);

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
	&quot_dquo_ko,
	// &shift_caps_ko,
};

// #define _CB(cb,kc) COMBO(cb,kc)
// #define _DC(name,k1,k2) const uint16_t PROGMEM (name)[] = {(k1),(k2),COMBO_END};
// #define _TC(name,k1,k2,k3) const uint16_t PROGMEM (name)[] = {(k1),(k2),(k3),COMBO_END};
// 
// // Combos definitions
// _DC(cb_lo, PT_L, PT_O)
// _DC(cb_ni, _A(PT_N), _S(PT_I))
// _DC(cb_wf, PT_W, PT_F)
// _DC(cb_st, _S(PT_S), _A(PT_T))
// 
// // _TC(cb_wer, PT_W, PT_E, PT_R)
// // _TC(cb_sdf, PT_S, PT_D, PT_F)
// 
// combo_t key_combos[] = {
// 	_CB(cb_lo, PT_CIRC),
// 	_CB(cb_ni, PT_TILD),
// 	_CB(cb_wf, PT_ACUT),
// 	_CB(cb_st, PT_GRV),
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[L_BASE] = LAYOUT_split_3x6_3(
	//--------------,--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,--------,
               SH_OS,    PT_Q,    PT_W,    PT_E,    PT_R,    PT_T,                         PT_Y,    PT_U,    PT_I,    PT_O, PT_QUOT, _G(KC_DEL),
	//--------------|--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|--------|
	   OSM(MOD_LSFT),_C(PT_A),_S(PT_S),_G(PT_D),_A(PT_F),    PT_G,                         PT_H,_A(PT_J),_G(PT_K),_S(PT_L),_C(PT_P), _A(KC_BSPC),
	//--------------|--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|--------|
	   OSM(MOD_LCTL),    PT_Z,    PT_X,    PT_C,    PT_V,    PT_B,                         PT_N,    PT_M, PT_COMM,  PT_DOT, PT_CCED, _C(KC_ENT),
	//--------------|--------'--------|--------'--------|--------'--------,  ,--------'--------|--------'--------|--------'--------|--------'
	                  LT(L_FUN,KC_ESC), LT(L_NUM,KC_SPC),       _S(KC_TAB),    LT(L_NAV,KC_ENT),LT(L_SYM,KC_BSPC), LT(L_CMD,KC_DEL)
	               //-----------------'-----------------'-----------------'  '-----------------'-----------------'-----------------'
	),

	[L_NAV] = LAYOUT_split_3x6_3(
	//-------,--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,--------,
	  _______,  KC_NUM, KC_CAPS, DF_BASE,  DF_ALT, DF_GAME,                      KC_PGUP, KC_HOME,   KC_UP,  KC_END, KC_MPRV, XXXXXXX,
	//-------|--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|--------|
	  _______, _______, _______, _______, _______, _______,                      KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_MPLY, XXXXXXX,
	//-------|--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|--------|
	  _______, _______, _______, _______, _______, _______,                      KC_PSCR, KC_MUTE, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX,
	//-------|--------'--------|--------'--------|--------'--------,  ,--------'--------|--------'--------|--------'--------|--------'
	                    _______,          _______,          _______,             _______,          _______,          _______
	        //-----------------'-----------------'-----------------'  '-----------------'-----------------'-----------------'
	),

	[L_NUM] = LAYOUT_split_3x6_3(
	//-------,--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,--------,
	  _______, PT_MINS,    PT_7,    PT_8,    PT_9,    M_0X,                         PT_C,   KC_P7,   KC_P8,   KC_P9,    PT_F, PT_SLSH,
	//-------|--------|--------|--------|--------|--------,                    |--------|--------|--------|--------|--------|--------|
	  _______,  PT_DOT,    PT_4,    PT_5,    PT_6,    PT_0,                         PT_B,   KC_P4,   KC_P5,   KC_P6,    PT_E, PT_ASTR,
	//-------|--------|--------|--------|--------|--------,                    |--------|--------|--------|--------|--------|--------|
	  _______, PT_COMM,    PT_1,    PT_2,    PT_3,    M_0B,                         PT_A,   KC_P1,   KC_P2,   KC_P3,    PT_D, PT_PLUS,
	//-------|--------'--------|--------,--------|--------'--------,  ,--------'--------|--------'--------|--------'--------|--------'
	                    _______,          _______,          _______,             PT_COMM,            KC_P0,           PT_DOT
	        //-----------------'-----------------'-----------------'  '-----------------'-----------------'-----------------'
	),

	[L_SYM] = LAYOUT_split_3x6_3(
	//-------,--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,--------,
	  _______,  M_DCLN, PT_LABK, PT_SLSH, PT_RABK, PT_COLN,                      PT_AMPR, PT_LBRC, PT_QUES, PT_RBRC, PT_PERC, XXXXXXX,
	//-------|--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|--------|
	  _______,  M_PDIR, PT_BSLS, PT_MINS,  PT_EQL, PT_SCLN,                      PT_PIPE, PT_LPRN, PT_EXLM, PT_RPRN, PT_HASH, XXXXXXX,
	//-------|--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|--------|
	  _______,  PT_DLR, ND_TICK, PT_PLUS, PT_ASTR, ND_CIRC,                      ND_TILD, PT_LCBR, PT_UNDS, PT_RCBR,   PT_AT, XXXXXXX,
	//-------|--------'--------|--------'--------|--------'--------,  ,--------'--------|--------'--------|--------'--------|--------'
	                    _______,          _______,          _______,             _______,          _______,          _______
	        //-----------------'-----------------'-----------------'  '-----------------'-----------------'-----------------'
	),

	[L_FUN] = LAYOUT_split_3x6_3(
	//-------,--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,--------,
	  _______,  KC_F12,   KC_F7,   KC_F8,   KC_F9,  KC_F15,                      _______, _______, PT_CIRC, _______, _______, XXXXXXX,
	//-------|--------|--------|--------|--------|--------,                    |--------|--------|--------|--------|--------|--------|
	  _______,  KC_F11,   KC_F4,   KC_F5,   KC_F6,  KC_F14,                      _______, PT_ACUT, PT_TILD,  PT_GRV, _______, XXXXXXX,
	//-------|--------|--------|--------|--------|--------,                    |--------|--------|--------|--------|--------|--------|
	  _______,  KC_F10,   KC_F1,   KC_F2,   KC_F3,  KC_F13,                      _______, _______, _______, _______, _______, XXXXXXX,
	//-------|--------'--------|--------'--------|--------'--------,  ,--------'--------|--------'--------|--------'--------|--------'
	           LT(L_CMD,KC_DEL),LT(L_SYM,KC_BSPC), LT(L_NAV,KC_ENT),             _______,          _______,          _______
	        //-----------------'-----------------'-----------------'  '-----------------'-----------------'-----------------'
	),

	[L_CMD] = LAYOUT_split_3x6_3(
	//-------,--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,--------,
	  _______, RM_TOGG, XXXXXXX, XXXXXXX, KC_BRID, KC_BRIU,                      KC_SLEP, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT, XXXXXXX,
	//-------|--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|--------|
	  _______, RM_SPDU, RM_VALU, RM_SATU, RM_HUEU, RM_NEXT,                      KC_WAKE, XXXXXXX, XXXXXXX, XXXXXXX,  EE_CLR, XXXXXXX,
	//-------|--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|--------|
	  _______, RM_SPDD, RM_VALD, RM_SATD, RM_HUED, RM_PREV,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DB_TOGG, XXXXXXX,
	//-------|--------'--------|--------'--------|--------'--------,  ,--------'--------|--------'--------|--------'--------|--------'
	                    _______,          _______,          _______,             _______,          _______,          _______
	        //-----------------'-----------------'-----------------'  '-----------------'-----------------'-----------------'
	),

	// [L_] = LAYOUT_split_3x6_3(
	// //-------,--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,--------,
	//   XXXXXXX, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, XXXXXXX,
	// //-------|--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|--------|
	//   XXXXXXX, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, XXXXXXX,
	// //-------|--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|--------|
	//   XXXXXXX, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, XXXXXXX,
	// //-------|--------'--------|--------'--------|--------'--------,  ,--------'--------|--------'--------|--------'--------|--------'
	//                     _______,          _______,          _______,             _______,         _______,          _______
	//         //-----------------'-----------------'-----------------'  '-----------------'-----------------'-----------------'
	// ),



	[L_GAME] = LAYOUT_split_3x6_3(
	//-------,--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,--------,
	     PT_T,MO(L_GNUM),  PT_Q,    PT_W,    PT_E,    PT_R,                         PT_Y,    PT_U,    PT_I,    PT_O,    PT_P,  KC_ESC,
	//-------,--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|--------|
	     PT_G, KC_LSFT,    PT_A,    PT_S,    PT_D,    PT_F,                         PT_H,    PT_J,    PT_K,    PT_L, PT_CCED, PT_TILD,
	//-------,--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|--------|
	     PT_B, KC_LCTL,    PT_Z,    PT_X,    PT_C,    PT_V,                         PT_N,    PT_M, PT_COMM,  PT_DOT, PT_MINS, PT_PLUS,
	//-------,--------|--------'--------|--------'--------'--------,  ,--------'--------|--------'--------|--------'--------|--------'
	                    KC_LALT,           KC_SPC,           KC_TAB,             _______,          _______,          _______
	        //-----------------'-----------------'-----------------'  '-----------------'-----------------'-----------------'
	),

	[L_GNUM] = LAYOUT_split_3x6_3(
	//-------,--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,--------,
	  _______,  KC_TAB,    PT_1,    PT_2,    PT_3,    PT_4,                      _______, _______, _______, _______, _______, XXXXXXX,
	//-------,--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|--------|
	  _______, KC_LSFT,    PT_5,    PT_6,    PT_7,    PT_8,                      _______, _______, _______, _______, _______, XXXXXXX,
	//-------,--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|--------|
	  _______, KC_LCTL,    PT_9,    PT_0,    PT_V,    PT_B,                      _______, _______, _______, _______, _______, XXXXXXX,
	//-------,--------|--------|--------'--------|--------'--------,  ,--------'--------|--------'--------|--------'--------|--------'
	                    _______,          _______,          _______,             _______,         _______,           _______
	        //-----------------'-----------------'-----------------'  '-----------------'-----------------'-----------------'
	),

	[L_ALT] = LAYOUT_split_3x6_3(
#ifdef ALT_DEC_HNIOP1
	//-------,--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,--------,
	  _______,    PT_Q,    PT_W,    PT_D,    PT_R,    PT_F,                         PT_Y,    PT_U,    PT_K,    PT_L, _______, _______,
	//-------|--------|--------|--------|--------|--------|     DEC-HNIOP1     |--------|--------|--------|--------|--------|--------|
	  _______,    PT_A,    PT_S,    PT_E,    PT_T,    PT_G,                         PT_H,    PT_N,    PT_I,    PT_O,    PT_P, _______,
	//-------|--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|--------|
	  _______,    PT_Z,    PT_X,    PT_C,    PT_V,    PT_B,                         PT_J,    PT_M, _______, _______, _______, _______,
	//-------|--------'--------|--------'--------|--------'--------,  ,--------'--------|--------'--------|--------'--------|--------'
	                    _______,          _______,          _______,             _______,          _______,          _______
	        //-----------------'-----------------'-----------------'  '-----------------'-----------------'-----------------'
#endif
#ifdef ALT_COLEMAK_DH
	//-------,--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,--------,
	  _______,    PT_Q,    PT_W,    PT_F,    PT_P,    PT_B,                         PT_J,    PT_L,    PT_U,    PT_Y, _______, _______,
	//-------|--------|--------|--------|--------|--------|     COLEMAK-DH     |--------|--------|--------|--------|--------|--------|
	  _______,    PT_A,    PT_R,    PT_S,    PT_T,    PT_G,                         PT_M,    PT_N,    PT_E,    PT_I,    PT_O, _______,
	//-------|--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|--------|
	  _______,    PT_Z,    PT_X,    PT_C,    PT_D,    PT_V,                         PT_K,    PT_H, _______, _______, _______, _______,
	//-------|--------'--------|--------'--------|--------'--------,  ,--------'--------|--------'--------|--------'--------|--------'
	                    _______,          _______,          _______,             _______,          _______,          _______
	        //-----------------'-----------------'-----------------'  '-----------------'-----------------'-----------------'
#endif
#ifdef ALT_COLEMAK
	//-------,--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,--------,
	  _______,    PT_Q,    PT_W,    PT_F,    PT_P,    PT_G,                         PT_J,    PT_L,    PT_U,    PT_Y, _______, _______,
	//-------|--------|--------|--------|--------|--------|      COLEMAK       |--------|--------|--------|--------|--------|--------|
	  _______,    PT_A,    PT_R,    PT_S,    PT_T,    PT_D,                         PT_H,    PT_N,    PT_E,    PT_I,    PT_O, _______,
	//-------|--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|--------|
	  _______,    PT_Z,    PT_X,    PT_C,    PT_V,    PT_B,                         PT_K,    PT_M, _______, _______, _______, _______,
	//-------|--------'--------|--------'--------|--------'--------,  ,--------'--------|--------'--------|--------'--------|--------'
	                    _______,          _______,          _______,             _______,          _______,          _______
	        //-----------------'-----------------'-----------------'  '-----------------'-----------------'-----------------'
#endif
#ifdef ALT_ENGRAM
	//-------,--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,--------,
	  _______,    PT_B,    PT_Y,    PT_O,    PT_U,    PT_Z,                         PT_Q,    PT_L,    PT_D,    PT_W,    PT_V, _______,
	//-------|--------|--------|--------|--------|--------|       ENGRAM       |--------|--------|--------|--------|--------|--------|
	  _______,    PT_C,    PT_I,    PT_E,    PT_A, PT_COMM,                       PT_DOT,    PT_H,    PT_T,    PT_S,    PT_N, _______,
	//-------|--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|--------|
	  _______,    PT_G,    PT_X,    PT_J,    PT_K, PT_QUOT,                      PT_DQUO,    PT_R,    PT_M,    PT_F,    PT_P, _______,
	//-------|--------'--------|--------'--------|--------'--------,  ,--------'--------|--------'--------|--------'--------|--------'
	                    _______,          _______,          _______,             _______,          _______,          _______
	        //-----------------'-----------------'-----------------'  '-----------------'-----------------'-----------------'
#endif
#ifdef ALT_MIGRAM
	//-------,--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,--------,
	  _______,    PT_Q,    PT_W,    PT_Y,    PT_U,    PT_J,                      PT_QUOT,    PT_L,    PT_D,    PT_G,    PT_P, _______,
	//-------|--------|--------|--------|--------|--------|       MIGRAM       |--------|--------|--------|--------|--------|--------|
	  _______,    PT_A,    PT_E,    PT_O,    PT_I, PT_COMM,                       PT_DOT,    PT_R,    PT_T,    PT_S,    PT_N, _______,
	//-------|--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|--------|
	  _______,    PT_Z,    PT_X,    PT_C,    PT_V, PT_DQUO,                         PT_K,    PT_H,    PT_M,    PT_F,    PT_B, _______,
	//-------|--------'--------|--------'--------|--------'--------,  ,--------'--------|--------'--------|--------'--------|--------'
	                    _______,          _______,          _______,             _______,          _______,          _______
	        //-----------------'-----------------'-----------------'  '-----------------'-----------------'-----------------'
#endif
#ifdef ALT_APTV3
	//-------,--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,--------,
	  _______,    PT_W,    PT_G,    PT_D,    PT_F,    PT_B,                         PT_Q,    PT_L,    PT_U,    PT_O,    PT_Y, _______,
	//-------|--------|--------|--------|--------|--------|       APT-V3       |--------|--------|--------|--------|--------|--------|
	  _______,    PT_R,    PT_S,    PT_T,    PT_H,    PT_K,                         PT_J,    PT_N,    PT_E,    PT_A,    PT_I, _______,
	//-------|--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|--------|
	  _______,    PT_X,    PT_C,    PT_M,    PT_P,    PT_V,                         PT_Z, PT_QUOT, PT_COMM,  PT_DOT, PT_DQUO, _______,
	//-------|--------'--------|--------'--------|--------'--------,  ,--------'--------|--------'--------|--------'--------|--------'
	                    _______,          _______,          _______,             _______,          _______,          _______
	        //-----------------'-----------------'-----------------'  '-----------------'-----------------'-----------------'
#endif
#ifdef ALT_ASET
	//-------,--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,--------,
	  _______,    PT_Q,    PT_W,    PT_D,    PT_R,    PT_F,                         PT_Y,    PT_U,    PT_K,    PT_L, PT_QUOT, _______,
	//-------|--------|--------|--------|--------|--------,        ASET        |--------|--------|--------|--------|--------|--------|
	  _______,    PT_A,    PT_S,    PT_E,    PT_T,    PT_G,                         PT_H,    PT_N,    PT_I,    PT_O,    PT_P, _______,
	//-------|--------|--------|--------|--------|--------,                    |--------|--------|--------|--------|--------|--------|
	  _______,    PT_Z,    PT_X,    PT_C,    PT_V,    PT_B,                         PT_J,    PT_M, PT_COMM,  PT_DOT, PT_DQUO, _______,
	//-------|--------'--------|--------'--------|--------'--------,  ,--------'--------|--------'--------|--------'--------|--------'
	                    _______,          _______,          _______,             _______,          _______,          _______
	        //-----------------'-----------------'-----------------'  '-----------------'-----------------'-----------------'
#endif
#ifdef ALT_COLEMAK_VH
	//-------,--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,--------,
	  _______,    PT_Q,    PT_W,    PT_R,    PT_F,    PT_K,                         PT_J,    PT_L,    PT_U,    PT_O,    PT_Y, _______,
	//-------|--------|--------|--------|--------|--------,     COLEMAK-VH     |--------|--------|--------|--------|--------|--------|
	  _______,_C(PT_A),_S(PT_S),_G(PT_D),_A(PT_T),    PT_G,                         PT_H,_A(PT_N),_G(PT_E),_S(PT_I),_C(PT_P), _______,
	//-------|--------|--------|--------|--------|--------,                    |--------|--------|--------|--------|--------|--------|
	_______,LT(L_FUN,PT_Z),PT_X,    PT_C,    PT_V,    PT_B,                      PT_CCED,    PT_M, PT_COMM,  PT_DOT, PT_QUOT, _______,
	//-------|--------'--------|--------'--------|--------'--------,  ,--------'--------|--------'--------|--------'--------|--------'
	                    _______,          _______,          _______,             _______,          _______,          _______
	        //-----------------'-----------------'-----------------'  '-----------------'-----------------'-----------------'
#endif
	),
};

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
		RGB_MATRIX_INDICATOR_SET_COLOR(MOD_0, rgb.r, rgb.g, rgb.b);
	if (layer_state_is(L_NUM))
		RGB_MATRIX_INDICATOR_SET_COLOR(MOD_4, rgb.r, rgb.g, rgb.b);
	if (layer_state_is(L_CMD))
		RGB_MATRIX_INDICATOR_SET_COLOR(MOD_8, rgb.r, rgb.g, rgb.b);
	if (layer_state_is(L_SYM))
		RGB_MATRIX_INDICATOR_SET_COLOR(MOD_7, rgb.r, rgb.g, rgb.b);
		
	if (layer_state_is(L_NAV)) {
		RGB_MATRIX_INDICATOR_SET_COLOR(MOD_6, rgb.r, rgb.g, rgb.b);
		if (default_layer_state & (1 << L_BASE))
			RGB_MATRIX_INDICATOR_SET_COLOR(17, rgb.r, rgb.g, rgb.b);
		if (default_layer_state & (1 << L_ALT))
			RGB_MATRIX_INDICATOR_SET_COLOR(10, rgb.r, rgb.g, rgb.b);
		if (default_layer_state & (1 << L_GAME))
			RGB_MATRIX_INDICATOR_SET_COLOR(9, rgb.r, rgb.g, rgb.b);
		
		if (host_keyboard_led_state().caps_lock)
			RGB_MATRIX_INDICATOR_SET_COLOR(18, rgb.r, rgb.g, rgb.b);
		if (host_keyboard_led_state().num_lock)
			RGB_MATRIX_INDICATOR_SET_COLOR(23, rgb.r, rgb.g, rgb.b);
	} else {
		uint8_t osm = get_oneshot_mods();
		if (osm & MOD_BIT(KC_LCTL)) RGB_MATRIX_INDICATOR_SET_COLOR(LCTL_ID, rgb.r, rgb.g, rgb.b);
		if (osm & MOD_BIT(KC_LSFT)) RGB_MATRIX_INDICATOR_SET_COLOR(LSFT_ID, rgb.r, rgb.g, rgb.b);
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
