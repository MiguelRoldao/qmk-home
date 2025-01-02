

#include QMK_KEYBOARD_H
#include "keymap_portuguese.h"
#include "color.h"
#include "print.h"


enum layers {
	L_BASE,
	L_GAME,
	L_ALT,
	L_SYM,
	L_NUM,
	L_FUN,
	L_NAV,
	L_CMD,
};
 
// #define ALT_COLEMAK_DH
// #define ALT_COLEMAK
// #define ALT_DEC_HNIOP1
// #define ALT_ROMAK
// #define ALT_ENGRAM
// #define ALT_MIGRAM
#define ALT_APTV3

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

	CB_BSLS,
	CB_MINS,
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

const key_override_t comm_bsls_ko = ko_make_basic(MOD_BIT(KC_LSFT), PT_COMM, PT_AT);
const key_override_t dot_perc_ko = ko_make_basic(MOD_BIT(KC_LSFT), PT_DOT, PT_PERC);
const key_override_t dquo_at_ko = ko_make_basic(MOD_BIT(KC_LSFT), PT_DQUO, PT_HASH);
const key_override_t quot_tick_ko = ko_make_basic(MOD_BIT(KC_LSFT), PT_QUOT, PT_DLR);

const key_override_t shift_caps_ko = ko_make_basic(MOD_BIT(KC_LSFT), OSM(MOD_LSFT), KC_CAPS);



// This globally defines all key overrides to be used´
const key_override_t *key_overrides[] = {
	&spc_bsps_ko,
	// &bsps_del_ko,
	// &tab_ent_ko,
	&comm_bsls_ko,
	&dot_perc_ko,
	&dquo_at_ko,
	&quot_tick_ko,
	&shift_caps_ko,
};

#define _CB(cb,kc) COMBO(cb,kc)
#define _DC(name,k1,k2) \
	const uint16_t PROGMEM (name)[] = {(k1),(k2),COMBO_END};

// Combos definitions
_DC(cb_we,     PT_W,     PT_E) _DC(cb_er,     PT_E,     PT_R)
_DC(cb_sd, _S(PT_S), _G(PT_D)) _DC(cb_df, _G(PT_D), _A(PT_F))
_DC(cb_xc,     PT_X,     PT_C) _DC(cb_cv,     PT_C,     PT_V)

_DC(   cb_ui,     PT_U,     PT_I) _DC(     cb_io,     PT_I,     PT_O)
_DC(   cb_jk, _A(PT_J), _G(PT_K)) _DC(     cb_kl, _G(PT_K), _S(PT_L))
_DC(cb_mcomm,     PT_M,  PT_COMM) _DC(cb_commdot,  PT_COMM,   PT_DOT)

_DC(cb_sl, _S(PT_S), _S(PT_L))

combo_t key_combos[] = {
	// left half
	_CB(cb_we,        KC_ESC), _CB(cb_er,      KC_DEL),
	_CB(cb_sd,   _SG(KC_TAB)), _CB(cb_df, _SG(KC_ENT)),
	_CB(cb_xc, OSM(MOD_LCTL)), _CB(cb_cv,     KC_BSPC),

	// right half
	_CB(   cb_ui,        KC_ESC), _CB(     cb_io,      KC_DEL),
	_CB(   cb_jk,   _SG(KC_TAB)), _CB(     cb_kl, _SG(KC_ENT)),
	_CB(cb_mcomm, OSM(MOD_LCTL)), _CB(cb_commdot,     KC_BSPC),

	_CB(cb_sl, KC_CAPS)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[L_BASE] = LAYOUT_split_3x6_3(
	//-------,--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,--------,
	   KC_ESC,    PT_Q,    PT_W,    PT_E,    PT_R,    PT_T,                         PT_Y,    PT_U,    PT_I,    PT_O, PT_QUOT, PT_TILD,
	//-------|--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|--------|
	   KC_TAB,_C(PT_A),_S(PT_S),_G(PT_D),_A(PT_F),    PT_G,                         PT_H,_A(PT_J),_G(PT_K),_S(PT_L),_C(PT_P), PT_CCED,
	//-------|--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|--------|
	  KC_LCTL,    PT_Z,    PT_X,    PT_C,    PT_V,    PT_B,                         PT_N,    PT_M, PT_COMM,  PT_DOT, PT_DQUO, PT_ACUT,
	//-------|--------'--------|--------'--------|--------'--------,  ,--------'--------|--------'--------|--------'--------|--------'
	          LT(L_CMD,KC_BSPC), LT(L_NUM,KC_SPC),       OSL(L_SYM),   LT(L_NAV,KC_BSPC),    OSM(MOD_LSFT),   ALGR_T(KC_ENT)
	        //-----------------'-----------------'-----------------'  '-----------------'-----------------'-----------------'
	),
	           // LT(L_CMD,KC_DEL), LT(L_SYM,KC_SPC), LT(L_NUM,KC_TAB),    LT(L_NAV,KC_ENT),LT(L_SYM,KC_BSPC),           KC_ESC

	[L_NAV] = LAYOUT_split_3x6_3(
	//-------,--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,--------,
	  XXXXXXX, _______, _______, _______, _______, _______,                      KC_PGUP, KC_HOME,   KC_UP,  KC_END, KC_MPRV, XXXXXXX,
	//-------|--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|--------|
	  XXXXXXX, _______, _______, _______, _______, _______,                      KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_MPLY, XXXXXXX,
	//-------|--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|--------|
	  XXXXXXX, _______, _______, _______, _______, _______,                      KC_PSCR, KC_MUTE, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX,
	//-------|--------'--------|--------'--------|--------'--------,  ,--------'--------|--------'--------|--------'--------|--------'
	                    _______,          _______,        MO(L_CMD),             _______,         _______,          _______
	        //-----------------'-----------------'-----------------'  '-----------------'-----------------'-----------------'
	),

	[L_SYM] = LAYOUT_split_3x6_3(
	//-------,--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,--------,
	  XXXXXXX, PT_QUOT, PT_LABK, PT_RABK, PT_DQUO,  PT_DOT,                      PT_AMPR,  M_DCLN, PT_LBRC,  KC_END, KC_MPRV, XXXXXXX,
	//-------|--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|--------|
	  XXXXXXX, _______, _______, _______, _______, _______,                      KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_MPLY, XXXXXXX,
	//-------|--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|--------|
	  XXXXXXX, _______, _______, _______, _______, _______,                      KC_PSCR, KC_MUTE, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX,
	//-------|--------'--------|--------'--------|--------'--------,  ,--------'--------|--------'--------|--------'--------|--------'
	                    _______,          _______,          _______,             _______,         _______,          _______
	        //-----------------'-----------------'-----------------'  '-----------------'-----------------'-----------------'
	),

	[L_NUM] = LAYOUT_split_3x6_3(
	//-------,--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,--------,
	  XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                         PT_C,    PT_7,    PT_8,    PT_9,    PT_F, XXXXXXX,
	//-------|--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|--------|
	  XXXXXXX,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                         PT_B,_A(PT_4),_G(PT_5),_S(PT_6),_C(PT_E), XXXXXXX,
	//-------|--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|--------|
	  XXXXXXX,  KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,                         PT_A,    PT_1,    PT_2,    PT_3,    PT_D, XXXXXXX,
	//-------|--------'--------|--------'--------|--------'--------,  ,--------'--------|--------'--------|--------'--------|--------'
	                    _______,          _______,          _______,                M_0X,             PT_0,             M_0B
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


	[L_CMD] = LAYOUT_split_3x6_3(
	//-------,--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,--------,
	  XXXXXXX, RM_TOGG, XXXXXXX, XXXXXXX, KC_BRID, KC_BRIU,                      KC_SLEP, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT, XXXXXXX,
	//-------|--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|--------|
	  XXXXXXX, RM_SPDU, RM_VALU, RM_SATU, RM_HUEU, RM_NEXT,                      KC_WAKE, XXXXXXX, XXXXXXX, XXXXXXX,  EE_CLR, XXXXXXX,
	//-------|--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|--------|
	  XXXXXXX, RM_SPDD, RM_VALD, RM_SATD, RM_HUED, RM_PREV,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DB_TOGG, XXXXXXX,
	//-------|--------'--------|--------'--------|--------'--------,  ,--------'--------|--------'--------|--------'--------|--------'
	                    _______,          _______,          _______,             _______,          _______,          _______
	        //-----------------'-----------------'-----------------'  '-----------------'-----------------'-----------------'
	),




	[L_GAME] = LAYOUT_split_3x6_3(
	//-------,--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,--------,
	   KC_TAB,    PT_Q,    PT_W,    PT_E,    PT_R,    PT_T,                         PT_Y,    PT_U,    PT_I,    PT_O,  PT_P,TO(L_BASE),
	//-------|--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|--------|
	  KC_LSFT,    PT_A,    PT_S,    PT_D,    PT_F,    PT_G,                         PT_H,    PT_J,    PT_K,    PT_L, PT_QUOT,  KC_ENT,
	//-------|--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|--------|
	  KC_LCTL,    PT_Z,    PT_X,    PT_C,    PT_V,    PT_B,                         PT_N,    PT_M, PT_COMM,  PT_DOT, PT_MINS, PT_PLUS,
	//-------|--------'--------|--------'--------|--------'--------,  ,--------'--------|--------'--------|--------'--------|--------'
	                     KC_ESC,           KC_SPC,           KC_TAB,             _______,          _______,          _______
	        //-----------------'-----------------'-----------------'  '-----------------'-----------------'-----------------'
	),

	[L_ALT] = LAYOUT_split_3x6_3(

#ifdef ALT_DEC_HNIOP1
	//-------,--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,--------,
	  _______,    PT_Q,    PT_W,    PT_D,    PT_R,    PT_F,                         PT_Y,    PT_U,    PT_K,    PT_L, _______, _______,
	//-------|--------|--------|--------|--------|--------|     DEC-HNIOP1     |--------|--------|--------|--------|--------|--------|
	  _______,_C(PT_A),_S(PT_S),_G(PT_E),_A(PT_T),    PT_G,                         PT_H,_A(PT_N),_G(PT_I),_S(PT_O),_C(PT_P), _______,
	//-------|--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|--------|
	TO(L_BASE),   PT_Z,    PT_X,    PT_C,    PT_V,    PT_B,                         PT_J,    PT_M, _______, _______, _______, _______,
	//-------|--------'--------|--------'--------|--------'--------,  ,--------'--------|--------'--------|--------'--------|--------'
	                    _______,          _______,          _______,             _______,          _______,          _______
	        //-----------------'-----------------'-----------------'  '-----------------'-----------------'-----------------'
#endif

#ifdef ALT_COLEMAK_DH
	//-------,--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,--------,
	  _______,    PT_Q,    PT_W,    PT_F,    PT_P,    PT_B,                         PT_J,    PT_L,    PT_U,    PT_Y, _______, _______,
	//-------|--------|--------|--------|--------|--------|     COLEMAK-DH     |--------|--------|--------|--------|--------|--------|
	  _______,_C(PT_A),_S(PT_R),_G(PT_S),_A(PT_T),    PT_G,                         PT_M,_A(PT_N),_G(PT_E),_S(PT_I),_C(PT_O), _______,
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
	  _______,_C(PT_A),_S(PT_R),_G(PT_S),_A(PT_T),    PT_D,                         PT_H,_A(PT_N),_G(PT_E),_S(PT_I),_C(PT_O), _______,
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
	  _______,_C(PT_C),_S(PT_I),_G(PT_E),_A(PT_A), PT_COMM,                       PT_DOT,_A(PT_H),_G(PT_T),_S(PT_S),_C(PT_N), _______,
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
	  _______,_C(PT_A),_S(PT_E),_G(PT_O),_A(PT_I), PT_COMM,                       PT_DOT,_A(PT_R),_G(PT_T),_S(PT_S),_C(PT_N), _______,
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
	  _______,_C(PT_R),_S(PT_S),_G(PT_T),_A(PT_H),    PT_K,                         PT_J,_A(PT_N),_G(PT_E),_S(PT_A),_C(PT_I), _______,
	//-------|--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|--------|
	  _______,    PT_X,    PT_C,    PT_M,    PT_P,    PT_V,                         PT_Z, PT_QUOT, PT_COMM,  PT_DOT, PT_DQUO, _______,
	//-------|--------'--------|--------'--------|--------'--------,  ,--------'--------|--------'--------|--------'--------|--------'
	                    _______,          _______,          _______,             _______,          _______,          _______
	        //-----------------'-----------------'-----------------'  '-----------------'-----------------'-----------------'
#endif

	),



// old shared symbols + numpad
//	[L_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
//	  PT_PERC, PT_LABK, PT_AMPR, PT_RABK, PT_LBRC, PT_RBRC,                      PT_EXLM,    PT_7,    PT_8,    PT_9, PT_MINS, AG_CENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//		PT_AT, PT_HASH, PT_PIPE,  PT_EQL, PT_LPRN, PT_RPRN,                      PT_QUES,    PT_4,    PT_5,    PT_6, PT_PLUS, PT_EURO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//	  QK_LLCK, PT_BSLS,  PT_DLR, PT_SLSH, PT_LCBR, PT_RCBR,                       PT_DOT,    PT_1,    PT_2,    PT_3, PT_ASTR,  PT_PND,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
//										  _______, _______, _______,       PT_0,    M_0X,    M_0B
									  //`--------------------------|  |--------------------------'
//	),

	// The symbol was implemented as chords
	// [L_SYM] = LAYOUT_split_3x6_3(
	// //-------,--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,--------,
	//   _______, PT_QUOT, PT_LABK, PT_RABK, PT_DQUO,  PT_DOT,                      PT_AMPR,  M_DCLN, PT_LBRC, PT_RBRC, PT_PERC, QK_LLCK,
	// //-------|--------|--------|--------|--------|--------,                    |--------|--------|--------|--------|--------|--------|
	//   _______, PT_EXLM, PT_MINS, PT_PLUS,  PT_EQL, PT_HASH,                      PT_PIPE, PT_COLN, PT_LPRN, PT_RPRN, PT_QUES, XXXXXXX,
	// //-------|--------|--------|--------|--------|--------,                    |--------|--------|--------|--------|--------|--------|
	//   _______, PT_CIRC, PT_SLSH, PT_ASTR, PT_BSLS,  M_PDIR,                      PT_TILD,  PT_DLR, PT_LCBR, PT_RCBR,   PT_AT, XXXXXXX,
	// //-------|--------'--------|--------'--------|--------'--------,  ,--------'--------|--------'--------|--------'--------|--------'
	//                     _______,          _______,          _______,            _______,LT(QK_LLCK,KC_BSPC),         _______
	//         //-----------------'-----------------'-----------------'  '-----------------'-----------------'-----------------'
	// ),

	// ambidextrous number layer
	// [L_NUM] = LAYOUT_split_3x6_3(
	// //-------,--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,--------,
	//   QK_LLCK, PT_SLSH,    PT_7,    PT_8,    PT_9, PT_ASTR,                      PT_EXLM,    PT_7,    PT_8,    PT_9, PT_ASTR, QK_LLCK,
	// //-------|--------|--------|--------|--------|--------,                    |--------|--------|--------|--------|--------|--------|
	//   _______,    PT_0,    PT_4,    PT_5,    PT_6, PT_MINS,                         PT_0,    PT_4,    PT_5,    PT_6, PT_MINS, XXXXXXX,
	// //-------|--------|--------|--------|--------|--------,                    |--------|--------|--------|--------|--------|--------|
	//   _______,  PT_DOT,    PT_1,    PT_2,    PT_3, PT_PLUS,                       PT_DOT,    PT_1,    PT_2,    PT_3, PT_PLUS, XXXXXXX,
	// //-------|--------'--------|--------,--------|--------'--------,  ,--------'--------|--------'--------|--------'--------|--------'
	//                     _______,LT(QK_LLCK,KC_TAB),         _______,             _______,          _______,          _______
	//         //-----------------'-----------------'-----------------'  '-----------------'-----------------'-----------------'
	// ),

// 	[R_A] = LAYOUT_split_3x6_3(
// 		//-------,--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,--------,
// 		  XXXXXXX, XXXXXXX,    PT_B,    PT_M,    PT_G, XXXXXXX,                      XXXXXXX,    PT_L,    PT_O,    PT_U, XXXXXXX,TO(L_BASE),
// 		//-------|--------|--------|--------|--------|--------,                    |--------|--------|--------|--------|--------|--------|
// 		  XXXXXXX,_C(PT_D),_S(PT_N),_G(PT_S),_A(PT_T), XXXXXXX,                      XXXXXXX,_A(PT_R),_G(PT_A),_S(PT_E),_C(PT_I), XXXXXXX,
// 		//-------|--------|--------|--------|--------|--------,                    |--------|--------|--------|--------|--------|--------|
// 		  XXXXXXX, XXXXXXX,    PT_F,    PT_C,    PT_P, XXXXXXX,                      XXXXXXX,    PT_H, PT_COMM,  PT_DOT, XXXXXXX, XXXXXXX,
// 		//-------|--------'--------|--------'--------|--------'--------,  ,--------'--------|--------'--------|--------'--------|--------'
// 		                    XXXXXXX, LT(L_NUM,KC_SPC),  LT(R_A2,KC_TAB),    LT(L_NAV,KC_ENT),          KC_BSPC,          XXXXXXX
// 		        //-----------------'-----------------'-----------------'  '-----------------'-----------------'-----------------'
// 	),
// 
// 	[R_A2] = LAYOUT_split_3x6_3(
// 		//-------,--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,--------,
// 		  XXXXXXX, XXXXXXX,    PT_B,    PT_M,    PT_G, XXXXXXX,                      XXXXXXX,    PT_L,    PT_O,    PT_U, XXXXXXX,TO(L_BASE),
// 		//-------|--------|--------|--------|--------|--------,                    |--------|--------|--------|--------|--------|--------|
// 		  XXXXXXX,_C(PT_D),_S(PT_N),_G(PT_S),_A(PT_T), XXXXXXX,                      XXXXXXX,_A(PT_R),_G(PT_A),_S(PT_E),_C(PT_I), XXXXXXX,
// 		//-------|--------|--------|--------|--------|--------,                    |--------|--------|--------|--------|--------|--------|
// 		  XXXXXXX, XXXXXXX,    PT_F,    PT_C,    PT_P, XXXXXXX,                      XXXXXXX,    PT_H, PT_COMM,  PT_DOT, XXXXXXX, XXXXXXX,
// 		//-------|--------'--------|--------'--------|--------'--------,  ,--------'--------|--------'--------|--------'--------|--------'
// 		                    XXXXXXX, LT(L_NUM,KC_SPC),           KC_TAB,    LT(L_NAV,KC_ENT),          KC_BSPC,          XXXXXXX
// 		        //-----------------'-----------------'-----------------'  '-----------------'-----------------'-----------------'
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



void keyboard_post_init_user(void) {
	// Set a specific RGB lighting mode
	// rgblight_mode(RGBLIGHT_MODE_BREATHING); // Replace with your desired mode
	// rgb_matrix_set_color(0, 0x00, 0x00, 0xff);
	// transaction_register_rpc(USER_SYNC_LOCK, user_sync_lock_slave_handler);
	#ifdef COMMAND_ENABLE
	debug_enable=true;
	debug_matrix=true;
	#endif // COMMAND_ENABLE
	

	// for (uint8_t i = 7; i <= 9; i++)
	// 	g_led_config.flags[i] = LED_FLAG_MODIFIER;
	// for (uint8_t i = 28; i < 30; i++)
	// 	g_led_config.flags[i] = LED_FLAG_MODIFIER;

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
		[L_NUM] = MOD_6,
		[L_FUN] = MOD_4,
		[L_CMD] = MOD_3,
	};
	for (uint8_t i = 1; i < 6; i++) {
		if (layer_state_is(i))
			RGB_MATRIX_INDICATOR_SET_COLOR(layer_leds[i], rgb.r, rgb.g, rgb.b);
	}

	return false;
}
#endif //RGB_MATRIX_ENABLE

