/* ============================================================
 * main.c — Entry point for the menu-driven calculator
 *
 * Build:  make
 * Run:    ./calculator
 * ============================================================ */

#include <stdio.h>
#include "calculator.h"

int main(void)
{
    int    choice;
    double a = 0.0, b = 0.0;

    printf("\n  Welcome to C Menu Calculator!\n");
    printf("  Compile date: %s %s\n", __DATE__, __TIME__);

    do {
        display_menu();
        choice = get_operation();

        /* invalid read */
        if (choice == -1) {
            printf("  Please enter a number between 0 and 8.\n");
            continue;
        }

        /* exit */
        if (choice == OP_EXIT) {
            printf("\n  Goodbye!\n\n");
            break;
        }

        /* operations needing only one operand */
        if (choice == OP_SQRT || choice == OP_ABS) {
            if (!get_operands(&a, &b, 0)) continue;
        }
        /* operations needing two operands */
        else if (choice >= OP_ADD && choice <= OP_POW) {
            if (!get_operands(&a, &b, 1)) continue;
        }
        else {
            printf("  Invalid choice. Please select 0–8.\n");
            continue;
        }

        /* dispatch */
        CalcResult res;

        switch ((Operation)choice) {
            case OP_ADD:  res = calc_add(a, b);  break;
            case OP_SUB:  res = calc_sub(a, b);  break;
            case OP_MUL:  res = calc_mul(a, b);  break;
            case OP_DIV:  res = calc_div(a, b);  break;
            case OP_MOD:  res = calc_mod(a, b);  break;
            case OP_POW:  res = calc_pow(a, b);  break;
            case OP_SQRT: res = calc_sqrt(a);    break;
            case OP_ABS:  res = calc_abs(a);     break;
            default:      continue;
        }

        display_result(res);

    } while (1);

    return 0;
}
