

#include QMK_KEYBOARD_H
#include "keymap_portuguese.h"

enum layers {
	L_BASE,
	L_GAME,
	L_ALT,
	L_PT,
	L_FUN,
	L_NUM,
	L_SYM,
	L_NAV,
	L_MSE,
};

#define DF_BASE DF(L_BASE)
#define DF_GAME DF(L_GAME)
#define DF_ALT DF(L_ALT)

// #define ALT_COLEMAK_DH
// #define ALT_COLEMAK
// #define ALT_COLEMAK_VM
#define ALT_COLEMIGUEL
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


// const key_override_t cedilla_ko = ko_make_basic(MOD_BIT(KC_ALGR), HRM_QT, PT_CCED);
// const key_override_t quote_ko = ko_make_basic(MOD_MASK_SHIFT, HRM_QT, PT_DQUO);
// const key_override_t spc_bsps_ko = ko_make_basic(MOD_MASK_SHIFT, LT(L_NUM,KC_SPC), LT(L_NUM,KC_BSPC));
// const key_override_t bsps_del_ko = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
// const key_override_t tab_ent_ko = ko_make_basic(MOD_MASK_SHIFT, KC_TAB, KC_ENT);

//const key_override_t comm_quot_ko = ko_make_basic(MOD_BIT(KC_LSFT), PT_COMM, PT_QUOT);
//const key_override_t quot_quot_ko = ko_make_basic(MOD_BIT(KC_LSFT), PT_QUOT, PT_QUOT);
//const key_override_t dot_dquo_ko = ko_make_basic(MOD_BIT(KC_LSFT), PT_DOT, PT_DQUO);
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
	//&quot_dquo_ko,
	//&comm_quot_ko,
	//&quot_quot_ko,
	//&dot_dquo_ko,
	// &shift_caps_ko,
};

#define _CB(cb,kc) COMBO(cb,kc)
#define _DC(name,k1,k2) const uint16_t PROGMEM (name)[] = {(k1),(k2),COMBO_END};
#define _TC(name,k1,k2,k3) const uint16_t PROGMEM (name)[] = {(k1),(k2),(k3),COMBO_END};

// Combos definitions
_DC(cb_esc, PT_Q, PT_W)
_DC(cb_tab, PT_Z, PT_X)
_DC(cb_del, PT_F, PT_K)
_DC(cb_bsp, _A(PT_T), PT_G)
_DC(cb_enter, PT_V, PT_B)
_DC(cb_quote, M_COMUS, PT_DOT)

// _DC(cb_qw, PT_Q, PT_W) _DC( cb_we, PT_W,    PT_E) _DC(  cb_er,    PT_E,   PT_R) _DC(  cb_rt,   PT_R,    PT_T)
// _DC(cb_as, PT_A, PT_S) _DC( cb_sd, PT_S,    PT_D) _DC(  cb_df,    PT_D,   PT_F) _DC(  cb_fg,   PT_F,    PT_G)
// _DC(cb_zx, PT_Z, PT_X) _DC( cb_xc, PT_X,    PT_C) _DC(  cb_cv,    PT_C,   PT_V) _DC(  cb_vb,   PT_V,    PT_B)
// 
// _DC(cb_yu, PT_Y, PT_U) _DC( cb_ui, PT_U,    PT_I) _DC(  cb_io,    PT_I,   PT_O) _DC( cb_odq,   PT_O, PT_DQUO)
// _DC(cb_hj, PT_H, PT_J) _DC( cb_jk, PT_J,    PT_K) _DC(  cb_kl,    PT_K,   PT_L) _DC(  cb_lp,   PT_L,    PT_P)
// _DC(cb_nm, PT_N, PT_M) _DC(cb_mcm, PT_M, PT_COMM) _DC(cb_cmdt, PT_COMM, PT_DOT) _DC(cb_dtqt, PT_DOT, PT_QUOT)
// 
// _DC(cb_sl, PT_S, PT_L)
// 
// _TC(cb_wer, PT_W, PT_E, PT_R)
// _TC(cb_sdf, PT_S, PT_D, PT_F)
// 

combo_t key_combos[] = {
// 	// left half
// 	//-------------------,--------------------,--------------------,--------------------,
// 	  _CB(cb_qw, PT_RABK), _CB(cb_we, PT_SLSH), _CB(cb_er, PT_LABK), _CB(cb_rt, PT_COLN),
// 	//-------------------|--------------------|--------------------|--------------------|
// 	  _CB(cb_as, PT_BSLS), _CB(cb_sd, PT_MINS), _CB(cb_df,  PT_EQL), _CB(cb_fg, PT_SCLN),
// 	//-------------------|--------------------|--------------------|--------------------|
// 	  _CB(cb_zx, ND_TICK), _CB(cb_xc, PT_PLUS), _CB(cb_cv, PT_ASTR), _CB(cb_vb, ND_CIRC),
// 	//-------------------'--------------------'--------------------'--------------------'
// 
// 	// right half
// 	//-------------------,---------------------,----------------------,----------------------,
// 	  _CB(cb_yu, PT_AMPR), _CB( cb_ui, PT_LBRC), _CB(  cb_io, PT_QUES), _CB( cb_odq, PT_RBRC),
// 	//-------------------|---------------------|----------------------|----------------------|
// 	  _CB(cb_hj, PT_PIPE), _CB( cb_jk, PT_LPRN), _CB(  cb_kl, PT_EXLM), _CB(  cb_lp, PT_RPRN),
// 	//-------------------|---------------------|----------------------|----------------------|
// 	  _CB(cb_nm, ND_TILD), _CB(cb_mcm, PT_LCBR), _CB(cb_cmdt, PT_UNDS), _CB(cb_dtqt, PT_RCBR),
// 	//-------------------'---------------------'----------------------'----------------------'
// 
// 	_CB(cb_sl, KC_CAPS),
// 	
// 	_CB(cb_wer, KC_DEL),
// 	_CB(cb_sdf, KC_BSPC),
	_CB(cb_esc, KC_ESC),
	_CB(cb_tab, KC_TAB),
	_CB(cb_del, KC_DEL),
	_CB(cb_bsp, KC_BSPC),
	_CB(cb_enter, KC_ENT),
	_CB(cb_quote, PT_QUOT),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[L_BASE] = LAYOUT_split_3x5_2(
	//--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,
          PT_Q,    PT_W,    PT_E,    PT_R,    PT_T,                         PT_Y,    PT_U,    PT_I,    PT_O, PT_CCED,
	//--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|
	  _C(PT_A),_S(PT_S),_G(PT_D),_A(PT_F),    PT_G,                         PT_H,_A(PT_J),_G(PT_K),_S(PT_L),_C(PT_P),
	//--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|
	      PT_Z,    PT_X,    PT_C,    PT_V,    PT_B,                         PT_N,    PT_M, M_COMUS,  PT_DOT,  KC_DEL,
	//--------'--------|--------'--------|--------'--------,  ,--------'--------|--------'--------|--------'--------'
	                     LT(L_NUM,KC_SPC), LT(L_MSE,KC_TAB),    LT(L_NAV,KC_ENT),LT(L_SYM,KC_BSPC)
	                 //------------------'-----------------'  '-----------------'-----------------'
	),

	[L_NAV] = LAYOUT_split_3x5_2(
	//--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,
	    KC_NUM, KC_CAPS, DF_BASE,  DF_ALT, DF_GAME,                      KC_PGUP, KC_HOME,   KC_UP,  KC_END, KC_MPRV,
	//--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|
	   KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, KC_BRIU,                      KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_MPLY,
	//--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|
	   _______, _______, _______, _______, KC_BRID,                      KC_PSCR, KC_VOLD, KC_MUTE, KC_VOLU, KC_MNXT,
	//--------'--------|--------'--------|--------'--------,  ,--------'--------|--------'--------|--------'--------'
	                              _______,          _______,             _______,          _______
	                  //-----------------'-----------------'  '-----------------'-----------------'
	),

	[L_MSE] = LAYOUT_split_3x5_2(
	//--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,
	   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      MS_WHLU, MS_WHLL,   MS_UP, MS_WHLR, MS_ACL0,
	//--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|
	   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      MS_WHLD, MS_LEFT, MS_DOWN, MS_RGHT, MS_ACL1,
	//--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|
	   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      MS_BTN6, MS_BTN4, MS_BTN3, MS_BTN5, MS_ACL2,
	//--------'--------|--------'--------|--------'--------,  ,--------'--------|--------'--------|--------'--------'
	                              _______,          _______,             MS_BTN1,          MS_BTN2
	                  //-----------------'-----------------'  '-----------------'-----------------'
	),

	[L_NUM] = LAYOUT_split_3x5_2(
	//--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,
	   XXXXXXX,    PT_7,    PT_8,    PT_9,    M_0X,                         PT_C,   KC_P7,   KC_P8,   KC_P9,    PT_F,
	//--------|--------|--------|--------|--------,                    |--------|--------|--------|--------|--------|
	_C(PT_DOT),_S(PT_4),_G(PT_5),_A(PT_6),    PT_0,                         PT_B,   KC_P4,   KC_P5,   KC_P6,    PT_E,
	//--------|--------|--------|--------|--------,                    |--------|--------|--------|--------|--------|
	   PT_COMM,    PT_1,    PT_2,    PT_3,    M_0B,                         PT_A,   KC_P1,   KC_P2,   KC_P3,    PT_D,
	//--------'--------|--------,--------|--------'--------,  ,--------'--------|--------'--------|--------'--------'
	                              _______,          _______,              KC_ENT,            KC_P0
	                  //-----------------'-----------------'  '-----------------'-----------------'
	),

	[L_SYM] = LAYOUT_split_3x5_2(
	//-------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,
	  PT_EURO, PT_LABK, PT_SLSH, PT_RABK, PT_COLN,                      PT_AMPR, PT_LBRC, PT_QUES, PT_RBRC, PT_PERC,
	//-------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|
	   M_PDIR, PT_BSLS, PT_MINS,  PT_EQL, PT_SCLN,                      PT_PIPE, PT_LPRN, PT_EXLM, PT_RPRN, PT_HASH,
	//-------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|
	   PT_DLR, ND_TICK, PT_PLUS, PT_ASTR, ND_CIRC,                      ND_TILD, PT_LCBR, PT_UNDS, PT_RCBR,   PT_AT,
	//-------'--------|--------'--------|--------'--------,  ,--------'--------|--------'--------|--------'--------''
	                             _______,          _______,             _______,          _______
	                 //-----------------'-----------------'  '-----------------'-----------------'
	),

	[L_FUN] = LAYOUT_split_3x5_2(
	//--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,
	   QK_BOOT,   KC_F7,   KC_F8,   KC_F9,  KC_F12,                      _______, _______, _______, _______, _______,
	//--------|--------|--------|--------|--------,                    |--------|--------|--------|--------|--------|
	    EE_CLR,   KC_F4,   KC_F5,   KC_F6,  KC_F11,                      _______, _______, _______, _______, _______,
	//--------|--------|--------|--------|--------,                    |--------|--------|--------|--------|--------|
	   XXXXXXX,   KC_F1,   KC_F2,   KC_F3,  KC_F10,                      _______, _______, _______, _______, _______,
	//--------'--------|--------'--------|--------'--------,  ,--------'--------|--------'--------|--------'--------'
	                              _______,          _______,             _______,          _______
	                  //-----------------'-----------------'  '-----------------'-----------------'
	),

	[L_PT] = LAYOUT_split_3x5_2(
	//-------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,
	   PT_GRV, PT_ACUT, PT_CIRC, PT_TILD, PT_DIAE,                      XXXXXXX, XXXXXXX, MPT_UAC, MPT_OAC, XXXXXXX,
	//-------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|
	  MPT_ATL, MPT_AAC, PT_CCED,  MPT_AO, XXXXXXX,                      XXXXXXX, MPT_NTL, MPT_EAC, MPT_IAC, XXXXXXX,
	//-------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|
	  MPT_ACR, MPT_AGR, XXXXXXX, MPT_OES, XXXXXXX,                      XXXXXXX, XXXXXXX, MPT_ECR, MPT_OCR, XXXXXXX,
	//-------'--------|--------'--------|--------'--------,  ,--------'--------|--------'--------|--------'--------'
	                             _______,          _______,             _______,          _______
	                 //-----------------'-----------------'  '-----------------'-----------------'
	),

/*
` ´ ^ ~   ¨ | _ _ ú ó _
ã á ç ão  _ | _ ñ é í _
â à _ ões _ | _ _ ê ô _
*/

	// [L_] = LAYOUT_split_3x5_2(
	// //--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,
	//    _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______,
	// //--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|
	//    _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______,
	// //--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|
	//    _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______,
	// //--------'--------|--------'--------|--------'--------,  ,--------'--------|--------'--------|--------'--------'
	//                               _______,          _______,             _______,         _______, 
	//                   //-----------------'-----------------'  '-----------------'-----------------'
	// ),



	[L_GAME] = LAYOUT_split_3x5_2(
	//-------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,
	   KC_TAB,    PT_Q,    PT_W,    PT_E,    PT_R,                         PT_T,    PT_Y,    PT_U,    PT_I,    PT_O,
	//-------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|
	  KC_LSFT,    PT_A,    PT_S,    PT_D,    PT_F,                         PT_G,    PT_H,    PT_J,    PT_K,    PT_L,
	//-------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|
	  KC_LCTL,    PT_Z,    PT_X,    PT_C,    PT_V,                         PT_B,    PT_N,    PT_M, PT_COMM,  PT_DOT,
	//-------'--------|--------'--------|--------'--------,  ,--------'--------|--------'--------|--------'--------|
	                              KC_SPC, LT(L_NUM,KC_ESC),             _______,          _______
	                 //-----------------'-----------------'  '-----------------'-----------------'
	),

	[L_ALT] = LAYOUT_split_3x5_2(
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
	//--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,
	      PT_Q,    PT_W,    PT_F,    PT_P,    PT_G,                         PT_J,    PT_L,    PT_U,    PT_Y, _______,
	//--------|--------|--------|--------|--------|      COLEMAK       |--------|--------|--------|--------|--------|
	      PT_A,    PT_R,    PT_S,    PT_T,    PT_D,                         PT_H,    PT_N,    PT_E,    PT_I,    PT_O,
	//--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|
	      PT_Z,    PT_X,    PT_C,    PT_V,    PT_B,                         PT_K,    PT_M, M_COMUS, M_DOTDQ,OSL(L_PT),
	//--------'--------|--------'--------|--------'--------,  ,--------'--------|--------'--------|--------'--------'
	                              _______,          _______,             _______,          _______
	                  //-----------------'-----------------'  '-----------------'-----------------'
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
#ifdef ALT_COLEMIGUEL
	//--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,
	      PT_Q,    PT_W,    PT_R,    PT_F,    PT_K,                         PT_J,    PT_L,    PT_U,    PT_O,    PT_Y,
	//--------|--------|--------|--------|--------,     COLEMIGUEL     |--------|--------|--------|--------|--------|
	  _C(PT_A),_S(PT_S),_G(PT_D),_A(PT_T),    PT_G,                         PT_H,_A(PT_N),_G(PT_E),_S(PT_I),_C(PT_P),
	//--------|--------|--------|--------|--------,                    |--------|--------|--------|--------|--------|
	LT(L_FUN,PT_Z),PT_X,    PT_C,    PT_V,    PT_B,                      PT_DQUO,    PT_M, M_COMUS,  PT_DOT,OSL(L_PT),
	//--------'--------|--------'--------|--------'--------,  ,--------'--------|--------'--------|--------'--------'
	                              _______,          _______,             _______,          _______
	                  //-----------------'-----------------'  '-----------------'-----------------'
#endif
#ifdef ALT_COLEMAK_VM
	//-------,--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,--------,
	  _______,    PT_Q,    PT_W,    PT_R,    PT_P,    PT_F,                         PT_J,    PT_L,    PT_U,    PT_Y, _______, _______,
	//-------|--------|--------|--------|--------|--------,     COLEMAK-VM   |--------|--------|--------|--------|--------|--------|
	  _______,_C(PT_A),_S(PT_S),_G(PT_D),_A(PT_T),    PT_G,                         PT_H,_A(PT_N),_G(PT_E),_S(PT_I),_C(PT_O), _______,
	//-------|--------|--------|--------|--------|--------,                    |--------|--------|--------|--------|--------|--------|
	_______,LT(L_FUN,PT_Z),PT_X,    PT_C,    PT_V,    PT_B,                         PT_K,    PT_M, _______, _______, _______, _______,
	//-------|--------'--------|--------'--------|--------'--------,  ,--------'--------|--------'--------|--------'--------|--------'
	                    _______,          _______,          _______,             _______,          _______,          _______
	        //-----------------'-----------------'-----------------'  '-----------------'-----------------'-----------------'
#endif
	),
};

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
