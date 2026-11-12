#include "keycodes.h"
#include QMK_KEYBOARD_H

#include "print.h"

#include "password.h"
#ifndef MY_PASSWORD
#define MY_PASSWORD "password"
#endif

enum layers {
    L_BASE,
    L_GAME,
    L_GALT,
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
#define DF_ALT  DF(L_ALT)
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
    ND_TILD,
    ND_CIRC, // ^ -> as a define
    ND_TICK,

    M_ATL, // ã
    M_ACR, // â
//  M_AAC, // á -> as a define
    M_AGR, // à
//  M_EAC, // é -> as a define
    M_ECR, // ê
//  M_IAC, // í -> as a define
//  M_OAC, // ó -> as a define
    M_OCR, // ô
//  M_UAC, // ú -> as a define
//  M_NTL, // ñ -> as a define
    M_AO, // ão
    M_OES, // ões
//  M_CCED, // ç -> as a define
    M_QUE, // que

    M_COMUS, // ,_
    //M_COMMN, // ,-
    //M_COMQT, // ,'
    //M_DOTUS, // ._
    M_DOTDQ, // ."
    //M_QTDQT, // '"
    M_QTIQT, // ' I'
    //M_IQUOT, // I'
    M_MNPL,  // - +
    //M_REP,
    //M_OSSFT,

    M_SWJ,

    //CB_BSLS,
    //CB_MINS,
    //CB_EQL,
    //CB_LPRN,
    //CB_EXLM,
    //CB_RPRN,
};

// #define ND_CIRC ALGR(S(KC_6))
#define M_NTL ALGR(KC_N)
#define M_CCED ALGR(KC_COMM)
#define M_AAC ALGR(KC_A)
#define M_EAC ALGR(KC_E)
#define M_IAC ALGR(KC_I)
#define M_OAC ALGR(KC_O)
#define M_UAC ALGR(KC_U)

#define M_EUR ALGR(KC_5)
#define M_QUOT ALGR(KC_QUOT)
#define M_DQUO ALGR(KC_DQUO)
#define M_ACUT KC_QUOT
#define M_DIAE KC_DQUO

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
_DC(cb_esc, KC_W, KC_G)
_DC(cb_tab, LT(L_FUN,KC_X),KC_C)
_DC(cb_del, KC_F, KC_K)
_DC(cb_bsp, _A(KC_H), KC_B)
_DC(cb_enter, KC_P, KC_V)
_DC(cb_quote, M_COMUS, M_DOTDQ)

combo_t key_combos[] = {
    _CB(cb_esc, KC_ESC),
    _CB(cb_tab, KC_TAB),
    _CB(cb_del, KC_DEL),
    _CB(cb_bsp, KC_BSPC),
    _CB(cb_enter, KC_ENT),
    _CB(cb_quote, M_QTIQT),
};

#define MY_ESC SH_T(KC_ESC)
#define MY_SPC LT(L_NUM, KC_SPC)
#define MY_TAB LT(L_MSE, KC_TAB)

#define MY_BSPC LT(L_SYM, KC_BSPC)
#define MY_ENT LT(L_NAV, KC_ENT)
#define MY_DEL LT(L_RGB, KC_DEL)

//#define MY_SHFT LT(L_RGB, M_OSSFT)
//#define MY_SHFT LT(L_NAV, M_OSSFT)
//#define MY_REP LT(L_RGB, M_REP)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[L_BASE] = LAYOUT_Swoopiest(
//--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,
      KC_W,    KC_G,    KC_D,    KC_F,    KC_K,                         KC_J,    KC_L,    KC_U,    KC_O,    KC_Y,
//--------|--------|--------|--------|--------|       APTvMR       |--------|--------|--------|--------|--------|
  _C(KC_R),_S(KC_S),_G(KC_T),_A(KC_H),    KC_B,                         KC_Q,_A(KC_N),_G(KC_E),_S(KC_A),_C(KC_I),
//--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|
LT(L_FUN,KC_X),KC_C,    KC_M,    KC_P,    KC_V,                        KC_Z,OSL(L_PT), M_COMUS, M_DOTDQ,  M_MNPL,
//--------'--------'--------'--------|--------|--------,  ,--------|--------|--------'--------'--------'--------'
                                        KC_ESC, XXXXXXX,    XXXXXXX, XXXXXXX,
                  //--------,--------|--------|--------|  |--------|--------|--------,--------,
                     KC_MPLY,  MY_ESC,  MY_SPC,  MY_TAB,     MY_ENT, MY_BSPC, OS_LSFT, DF_GAME
                  //--------'--------'--------'--------'  '-----------------'-----------------'
),

[L_NAV] = LAYOUT_Swoopiest(
//--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,
    KC_NUM, KC_CAPS, DF_BASE,  KC_INS, DF_GAME,                      KC_PGUP, KC_HOME,   KC_UP,  KC_END, KC_MPRV,
//--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|
   KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, KC_BRIU,                      KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_MPLY,
//--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|
   DM_REC1, DM_REC2, DM_PLY1, DM_PLY2, KC_BRID,                      KC_PSCR, KC_VOLD, KC_MUTE, KC_VOLU, KC_MNXT,
//--------'--------'--------'--------|--------|--------,  ,--------|--------|--------'--------'--------'--------'
                                       _______, _______,    _______, _______,
                  //--------,--------|--------|--------|  |--------|--------|--------,--------,
                     _______, _______, _______, _______,    _______, _______, _______, _______
                  //--------'--------'--------'--------'  '-----------------'-----------------'
),

[L_MSE] = LAYOUT_Swoopiest(
//--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,
   C(KC_Q), C(KC_W), C(KC_E), C(KC_R), C(KC_A),                      MS_WHLU, MS_WHLL,   MS_UP, MS_WHLR, MS_ACL0,
//--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|
   C(KC_Z), C(KC_X), C(KC_C), C(KC_V), C(KC_Y),                      MS_WHLD, MS_LEFT, MS_DOWN, MS_RGHT, MS_ACL1,
//--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|
   LCS(KC_Z),LCS(KC_X),LCS(KC_C),LCS(KC_V),C(KC_S),                  MS_BTN6, MS_BTN4, KC_MENU, MS_BTN5, MS_ACL2,
//--------'--------'--------'--------|--------|--------,  ,--------|--------|--------'--------'--------'--------'
                                       _______, _______,    _______, _______,
                  //--------,--------|--------|--------|  |--------|--------|--------,--------,
                     _______, _______, _______, _______,    MS_BTN1, MS_BTN2, MS_BTN3, _______
                  //--------'--------'--------'--------'  '-----------------'-----------------'
),

[L_NUM] = LAYOUT_Swoopiest(
//--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,
      M_0X,    KC_7,    KC_8,    KC_9, KC_MINS,                         KC_F,   KC_P7,   KC_P8,   KC_P9,    KC_C,
//--------|--------|--------|--------|--------,                    |--------|--------|--------|--------|--------|
  _C(KC_0),_S(KC_4),_G(KC_5),_A(KC_6),  KC_DOT,                         KC_E,   KC_P4,   KC_P5,   KC_P6,    KC_B,
//--------|--------|--------|--------|--------,                    |--------|--------|--------|--------|--------|
      M_0B,    KC_1,    KC_2,    KC_3, KC_COMM,                         KC_D,   KC_P1,   KC_P2,   KC_P3,    KC_A,
//--------'--------'--------'--------|--------|--------,  ,--------|--------|--------'--------'--------'--------'
                                       _______, _______,    _______, _______,
                  //--------,--------|--------|--------|  |--------|--------|--------,--------,
                     _______, _______, _______, _______,    _______,   KC_P0, KC_BSPC, _______
                  //--------'--------'--------'--------'  '-----------------'-----------------'
),

[L_SYM] = LAYOUT_Swoopiest(
//--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,
   ND_CIRC, KC_LABK, KC_RABK, KC_MINS, KC_BSLS,                      KC_AMPR, KC_LCBR, KC_QUES, KC_RCBR,  KC_DLR,
//--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|
   KC_COLN, KC_ASTR, KC_SLSH,  KC_EQL, KC_HASH,                      KC_PIPE, KC_LPRN, KC_EXLM, KC_RPRN, KC_SCLN,
//--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|
   ND_TILD, KC_PLUS, ND_TICK,  M_PDIR, KC_PERC,                        KC_AT, KC_LBRC, KC_UNDS, KC_RBRC,   M_EUR,
//--------'--------'--------'--------|--------|--------,  ,--------|--------|--------'--------'--------'--------'
                                       _______, _______,    _______, _______,
                  //--------,--------|--------|--------|  |--------|--------|--------,--------,
                     _______, _______, _______, _______,    _______, _______, _______, _______
                  //--------'--------'--------'--------'  '-----------------'-----------------'
),

[L_FUN] = LAYOUT_Swoopiest(
//--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,
 QK_REBOOT,   KC_F7,   KC_F8,   KC_F9,  KC_F12,                      _______, _______, _______, _______, _______,
//--------|--------|--------|--------|--------,                    |--------|--------|--------|--------|--------|
   QK_BOOT,   KC_F4,   KC_F5,   KC_F6,  KC_F11,                      _______, _______, _______, _______, _______,
//--------|--------|--------|--------|--------,                    |--------|--------|--------|--------|--------|
   XXXXXXX,   KC_F1,   KC_F2,   KC_F3,  KC_F10,                      _______, _______, _______, _______,MO(L_RGB),
//--------'--------'--------'--------|--------|--------,  ,--------|--------|--------'--------'--------'--------'
                                       _______, _______,    _______, _______,
                  //--------,--------|--------|--------|  |--------|--------|--------,--------,
                     _______, _______, _______, _______,    _______, _______, _______, _______
                  //--------'--------'--------'--------'  '-----------------'-----------------'
),

[L_PT] = LAYOUT_Swoopiest(
//--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,
    KC_GRV,  M_ACUT, KC_CIRC, KC_TILD,  M_DIAE,                      XXXXXXX, XXXXXXX,   M_UAC,   M_OAC,   M_OCR,
//--------|--------|--------|--------|--------|                    |--------|--------| -------|--------|--------|
   XXXXXXX,   M_AGR,  M_CCED,    M_AO, XXXXXXX,                        M_QUE,   M_NTL,   M_EAC,   M_AAC,   M_IAC,
//--------|--------|--------|--------|--------|                    |--------|--------| -------|--------|--------|
     M_SWJ, XXXXXXX, XXXXXXX,   M_OES, XXXXXXX,                      XXXXXXX, XXXXXXX,   M_ECR,   M_ATL,   M_ACR,
//--------'--------'--------'--------|--------|--------,  ,--------|--------|--------'--------'--------'--------'
                                       _______, _______,    _______, _______,
                  //--------,--------|--------|--------|  |--------|--------|--------,--------,
                     _______, _______, _______, _______,    _______, _______, _______, _______
                  //--------'--------'--------'--------'  '-----------------'-----------------'
),

[L_RGB] = LAYOUT_Swoopiest(
//--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,
   RM_TOGG, XXXXXXX, XXXXXXX, KC_BRID, KC_BRIU,                      KC_SLEP, XXXXXXX, XXXXXXX, DB_TOGG,  EE_CLR,
//--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|
   RM_SPDU, RM_VALU, RM_SATU, RM_HUEU, RM_NEXT,                      KC_WAKE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|
   RM_SPDD, RM_VALD, RM_SATD, RM_HUED, RM_PREV,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//--------'--------'--------'--------|--------|--------,  ,--------|--------|--------'--------'--------'--------'
                                       _______, _______,    _______, _______,
                  //--------,--------|--------|--------|  |--------|--------|--------,--------,
                     _______, _______, _______, _______,    _______, _______, _______, _______
                  //--------'--------'--------'--------'  '-----------------'-----------------'
),

/*
` ´ ^ ~   ¨ | _ _ ú ó ô
_ á ç ão  _ | _ ñ é á í
â à _ ões _ | _ _ ê ã â
*/

[L_GAME] = LAYOUT_Swoopiest(
//--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,
    KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,                      _______, _______, _______, _______, _______,
//--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|
   KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,                      _______, _______, _______, _______, _______,
//--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|
   KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,                      _______, _______, _______, _______, _______,
//--------'--------'--------'--------|--------|--------,  ,--------|--------|--------'--------'--------'--------'
                                       KC_ENT,MO(L_GALT),   _______, _______,
                  //--------,--------|--------|--------|  |--------|--------|--------,--------,
                      KC_ENT, KC_LALT,KC_SPC,MO(L_GNUM),    _______, _______, _______, DF_BASE
                  //--------'--------'--------'--------'  '-----------------'-----------------'
),

[L_GALT] = LAYOUT_Swoopiest(
//--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,
      KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,                      _______, _______, _______, _______, _______,
//--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|
      KC_G,    KC_H,    KC_J,    KC_K,    KC_L,                      _______, _______, _______, _______, _______,
//--------|--------|--------|--------|--------|                    |--------|--------|--------|--------|--------|
      KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT,                      _______, _______, _______, _______, _______,
//--------'--------'--------'--------|--------|--------,  ,--------|--------|--------'--------'--------'--------'
                                       _______, _______,    _______, _______,
                  //--------,--------|--------|--------|  |--------|--------|--------,--------,
                     _______, _______, _______, _______,    _______, _______, _______, _______
                  //--------'--------'--------'--------'  '-----------------'-----------------'
),

[L_GNUM] = LAYOUT_Swoopiest(
//--------,--------,--------,--------,--------,                    ,--------,--------,--------,--------,--------,
      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                      _______, _______, _______, _______, _______,
//--------|--------|--------|--------|--------,                    |--------|--------|--------|--------|--------|
      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      _______, _______, _______, _______, _______,
//--------|--------|--------|--------|--------,                    |--------|--------|--------|--------|--------|
   KC_LGUI,  KC_DEL, KC_SLSH, KC_SCLN,    KC_P,                      _______, _______, _______, _______, _______,
//--------'--------'--------'--------|--------|--------,  ,--------|--------|--------'--------'--------'--------'
                                       _______, _______,    _______, _______,
                  //--------,--------|--------|--------|  |--------|--------|--------,--------,
                     _______, _______, _______, _______,    _______, _______, _______, _______
                  //--------'--------'--------'--------'  '-----------------'-----------------'
),

};
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [L_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLU, MS_WHLD) },
    [L_GAME] = { ENCODER_CCW_CW(   KC_1,    KC_2), ENCODER_CCW_CW(MS_WHLU, MS_WHLD) },
    [L_GALT] = { ENCODER_CCW_CW(   KC_1,    KC_2), ENCODER_CCW_CW(MS_WHLU, MS_WHLD) },
    [L_GNUM] = { ENCODER_CCW_CW(   KC_1,    KC_2), ENCODER_CCW_CW(MS_WHLU, MS_WHLD) },
      [L_PT] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLU, MS_WHLD) },
     [L_FUN] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLU, MS_WHLD) },
     [L_NUM] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLU, MS_WHLD) },
     [L_SYM] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLU, MS_WHLD) },
     [L_NAV] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLU, MS_WHLD) },
     [L_MSE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLU, MS_WHLD) },
     [L_RGB] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLU, MS_WHLD) },
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
    uint8_t os_mods = get_oneshot_mods();
    uint8_t mods = get_mods();
    bool l_shift_held = mods & MOD_BIT(KC_LSFT);
    bool r_shift_held = mods & MOD_BIT(KC_RSFT);
    del_oneshot_mods(MOD_BIT(KC_LSFT));
    if (l_shift_held) unregister_code(KC_LSFT);
    if (r_shift_held) unregister_code(KC_RSFT);

    tap_code16(keycode);

    // pop shift status
    if (l_shift_held) register_code(KC_LSFT);
    if (r_shift_held) register_code(KC_RSFT);
    set_oneshot_mods(os_mods);
}

//static void tap_code_shifted(uint16_t keycode) {
//    // push shift status
//    uint8_t os_mods = get_oneshot_mods();
//    uint8_t mods = get_mods();
//    bool l_shift_held = mods & MOD_BIT(KC_LSFT);
//    del_oneshot_mods(MOD_BIT(KC_LSFT));
//    register_code(KC_LSFT);
//
//    tap_code16(keycode);
//
//    // pop shift status
//    if (!l_shift_held) unregister_code(KC_LSFT);
//    set_oneshot_mods(os_mods);
//}

static inline bool get_os_shift(void) {
    return get_oneshot_mods() & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));
}

static bool get_shift(void) {
    uint8_t mods = get_mods() | get_oneshot_mods();
    uint8_t sft_bits = (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));
    return mods & sft_bits;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    //static bool my_shft_hold = false;

    // static uint16_t next_keycode = 0;
    // uint16_t last_keycode = next_keycode;
    // next_keycode = keycode;

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
            if (record->event.pressed) SEND_STRING("../"); // equiv to ../ in us ansi
            return false;

        case ND_TILD:
            if (record->event.pressed) SEND_STRING("~ ");
            return false;
        case ND_TICK:
            if (record->event.pressed) SEND_STRING("` ");
            return false;

        case M_ATL: // ã
            if (record->event.pressed) {
                tap_code_unshifted(KC_TILD);
                tap_code(KC_A);
            }
            return false;
        case M_ACR: // â
            if (record->event.pressed) {
                tap_code_unshifted(KC_CIRC);
                tap_code(KC_A);
            }
            return false;
        case M_AGR: // à
            if (record->event.pressed) {
                tap_code_unshifted(KC_GRV);
                tap_code(KC_A);
            }
            return false;
        case M_ECR: // ê
            if (record->event.pressed) {
                tap_code_unshifted(KC_CIRC);
                tap_code(KC_E);
            }
            return false;
        case M_OCR: // ô
            if (record->event.pressed) {
                tap_code_unshifted(KC_CIRC);
                tap_code(KC_O);
            }
            return false;
        case M_AO: // ão
            if (record->event.pressed) {
                tap_code_unshifted(KC_TILD);
                tap_code(KC_A);
                tap_code(KC_O);
            }
            return false;
        case M_OES: // ões
            if (record->event.pressed) {
                tap_code_unshifted(KC_TILD);
                tap_code(KC_O);
                tap_code(KC_E);
                tap_code(KC_S);
            }
            return false;
        case M_COMUS: // ,_
            if (record->event.pressed) {
                if (get_shift())
                    tap_code_unshifted(KC_UNDS);
                else
                    tap_code_unshifted(KC_COMM);
            }
            return false;
        case M_MNPL: // -+
            if (record->event.pressed) {
                if (get_shift())
                    tap_code_unshifted(KC_PLUS);
                else
                    tap_code_unshifted(KC_MINS);
            }
            return false;
        case M_DOTDQ: // ."
            if ( record->event.pressed ) {
                if (get_shift()) {
                    tap_code_unshifted(KC_DQUO);
                    tap_code(KC_SPACE);
                } else {
                    tap_code_unshifted(KC_DOT);
                }
            }
            return false;
        case M_QTIQT: // ' I'
            if ( record->event.pressed ) {
                if ( get_shift() ) {
                    tap_code(KC_I);
                    tap_code_unshifted(KC_QUOT);
                    tap_code(KC_SPACE);
                } else {
                    tap_code_unshifted(KC_QUOT);
                    tap_code(KC_SPACE);
                }
            }
            return false;
        case ND_CIRC: // ^
            if (record->event.pressed) {
                tap_code_unshifted(KC_DQUO);
                tap_code(KC_SPACE);
            }
            return false;

        //case _C(PT_A):
        //case _G(KC_E):
        //case _S(PT_I):
        //case _S(PT_A):
        //case _C(PT_I):

        //    if ( !record->tap.count )
        //        return true;
            /* fall through */
        //case PT_O:
        //    if ( record->event.pressed && last_keycode == KC_Q )
        //        tap_code(KC_U);
        //    return true;
        case M_QUE:
            if (record->event.pressed) {
                tap_code(KC_Q);
                tap_code(KC_U);
                tap_code(KC_E);
            }
            return false;
        case OS_LSFT:
            if (record->event.pressed && get_os_shift()) {
                clear_oneshot_mods();
                tap_code(KC_CAPS);
                return false;
            }
            return true;

        case M_SWJ:
            if (record->event.pressed) SEND_STRING(MY_PASSWORD);
            return false;

    }

    return true;
}


//void process_combo_event(uint16_t combo_index, bool pressed) {
//    if (pressed && !(default_layer_state & (1 << L_GAME))) {
//        tap_code16(key_combos[combo_index].keycode);
//    }
//}


void keyboard_post_init_user(void) {
    #ifdef COMMAND_ENABLE
    debug_enable=true;
    debug_matrix=true;
    #endif // COMMAND_ENABLE
}
#if defined(SWAP_HANDS_ENABLE)
const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
  {{0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4}},
  {{0, 5}, {1, 5}, {2, 5}, {3, 5}, {4, 5}, {5, 5}},
  {{0, 6}, {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6}},
  {{0, 7}, {1, 7}, {2, 7}, {3, 7}, {4, 7}, {5, 7}},

  {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}},
  {{0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1}},
  {{0, 2}, {1, 2}, {2, 2}, {3, 2}, {4, 2}, {5, 2}},
  {{0, 3}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 3}},
};
#endif

#if defined(SWAP_HANDS_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint8_t PROGMEM encoder_hand_swap_config[NUM_ENCODERS] = { 1, 0 };
#endif
