#define NO		KC_NO
#define TRNS	KC_TRNS
#define SFT		KC_LSFT
#define CTL		KC_LCTL
#define ALT		KC_LALT
#define CMD		KC_LCMD
#define ENT		KC_ENT
#define ESC		KC_ESC
#define SPC		KC_SPC
#define BSPC	KC_BSPC
#define DEL		KC_DEL
#define TAB		KC_TAB
#define _SX 	KC_LEFT
#define _UP		KC_UP
#define _DN	    KC_DOWN
#define _RT 	KC_RIGHT
#define BT		BT_HST1

#define HR_1  	LCMD_T(KC_A)
#define HR_2  	LCTL_T(KC_S)
#define HR_3  	LALT_T(KC_D)
#define HR_4  	LSFT_T(KC_F)

#define HR_7  	RSFT_T(KC_J)
#define HR_8  	RCTL_T(KC_K)
#define HR_9  	LALT_T(KC_L)
#define HR_10   RCMD_T(KC_SCLN)


#define T_F		TD(TD_F)
#define T_C		TD(TD_C)
#define T_D		TD(TD_D)
#define T_S		TD(TD_S)
#define T_RB	TD(TD_RB)
#define T_SB	TD(TD_SB)
#define T_CB	TD(TD_CB)
#define T_E		TD(TD_E)
#define T_SCLN	TD(TD_SCLN)
#define T_SLSH	TD(TD_SLSH)
#define T_COMM	TD(TD_COMM)
#define T_DOT	TD(TD_DOT)
#define T_QT	TD(TD_QT)
#define T_DQT	TD(TD_DQT)
#define T_PIPE	TD(TD_PIPE)

#define GONOR	LT(NOR, SPC)
#define GOSYM	MO(SYM)
#define GONUM	MO(NUM)

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
#define HASH    IT_HASH
#define TILD    IT_TILD
#define GRV     IT_GRV
#define PIPE	IT_PIPE
#define DLR     IT_DLR
#define EXLM    IT_EXLM
#define ASTR    IT_ASTR
#define AT		IT_AT
#define PERC    IT_PERC
#define CIRC	IT_CIRC

enum layers {
	 INS,
	 NOR,
	 SYM,
	 NUM,
};
