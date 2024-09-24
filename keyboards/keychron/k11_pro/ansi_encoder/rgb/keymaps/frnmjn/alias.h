#define NO		KC_NO
#define TRNS	KC_TRNS
#define SFT		KC_LSFT
#define CTL		KC_LCTL
#define ALT		KC_LALT
#define CMD		KC_LCMD
#define _MEH	KC_MEH
#define ENT		KC_ENT
#define ESC		KC_ESC
#define SPC		KC_SPC
#define BSPC	KC_BSPC
#define DEL		KC_DEL
#define TAB		KC_TAB
#define _SX 	KC_LEFT
#define _UP		KC_UP
#define _DN	    KC_DOWN
#define _DX 	KC_RIGHT
#define BT		BT_HST1
#define PGUP    KC_PGUP
#define PGDN	KC_PGDN

#define COLN	IT_COLN
#define COMM 	IT_COMM
#define DOT 	IT_DOT
#define SLSH 	IT_SLSH
#define SCLN 	IT_SCLN
#define QUOT 	IT_QUOT
#define DQT     IT_DQUO
#define BSLS 	IT_BSLS
#define SLS     IT_SLSH
#define AST 	IT_ASTR
#define MINS    IT_MINS
#define PLUS    IT_PLUS
#define EQL 	IT_EQL
#define UNDS    IT_UNDS
#define AMPR    IT_AMPR
#define GRV     IT_GRV
#define PIPE	IT_PIPE
#define DLR     IT_DLR
#define EXLM    IT_EXLM
#define ASTR    IT_ASTR
#define PERC    IT_PERC
#define CIRC	IT_CIRC

#define HR_1  	LCMD_T(KC_A)
#define HR_2  	LALT_T(KC_S)
#define HR_3  	LCTL_T(KC_D)
#define HR_4  	LSFT_T(KC_F)

#define HR_7  	RSFT_T(KC_J)
#define HR_8  	RCTL_T(KC_K)
#define HR_9  	LALT_T(KC_L)
#define HR_10   RCMD_T(SCLN)

#define SRC		LCTL(KC_R)
#define CUT		LCMD(KC_X)
#define COPY	LCMD(KC_C)
#define PASTE	LCMD(KC_V)
#define UNDO	LCMD(KC_Z)
#define REDO	SCMD(KC_Z)
#define HOME	LCMD(KC_LEFT)
#define END		LCMD(KC_RIGHT)
#define CRTLW	LCTL(KC_W)
#define CRTLE	LCTL(KC_E)
#define CRTLB	LCTL(KC_B)

#define T_RB	TD(TD_RB)
#define T_SB	TD(TD_SB)
#define T_CB	TD(TD_CB)
#define T_E		TD(TD_E)
#define T_SLSH	TD(TD_SLSH)
#define T_QT	TD(TD_QT)
#define T_DQT	TD(TD_DQT)
#define T_PIPE	TD(TD_PIPE)
#define T_PERC 	TD(TD_PERC)
#define T_HOME  TD(TD_HOME)

#define GONOR	LT(NOR, SPC)
#define GONUM	LT(NUM, BSPC)

enum layers {
	 INS,
	 NOR,
	 NUM,
};
