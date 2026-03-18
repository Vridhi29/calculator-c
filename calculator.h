#ifndef CALCULATOR_H
#define CALCULATOR_H

/* ============================================================
 * calculator.h — Public API for the menu-driven calculator
 * ============================================================ */

/* Return codes */
#define CALC_OK          0
#define CALC_ERR_DIVZERO 1
#define CALC_ERR_DOMAIN  2

/* Supported operations */
typedef enum {
    OP_ADD = 1,
    OP_SUB,
    OP_MUL,
    OP_DIV,
    OP_MOD,
    OP_POW,
    OP_SQRT,
    OP_ABS,
    OP_EXIT = 0
} Operation;

/* Result container */
typedef struct {
    double  value;
    int     status;       /* CALC_OK or an error code */
    char    message[64];  /* human-readable status message */
} CalcResult;

/* Core arithmetic */
CalcResult calc_add  (double a, double b);
CalcResult calc_sub  (double a, double b);
CalcResult calc_mul  (double a, double b);
CalcResult calc_div  (double a, double b);
CalcResult calc_mod  (double a, double b);
CalcResult calc_pow  (double a, double b);
CalcResult calc_sqrt (double a);
CalcResult calc_abs  (double a);

/* UI helpers */
void display_menu   (void);
void display_result (CalcResult res);
int  get_operation  (void);
int  get_operands   (double *a, double *b, int needs_two);

#endif /* CALCULATOR_H */
