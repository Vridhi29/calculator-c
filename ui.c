#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"

#define CLR_RESET  "\033[0m"
#define CLR_BOLD   "\033[1m"
#define CLR_CYAN   "\033[36m"
#define CLR_GREEN  "\033[32m"
#define CLR_RED    "\033[31m"
#define CLR_YELLOW "\033[33m"
#define CLR_DIM    "\033[2m"

void display_menu(void)
{
    printf("\n");
    printf(CLR_CYAN CLR_BOLD "  +==============================+\n" CLR_RESET);
    printf(CLR_CYAN CLR_BOLD "  |   C M E N U  CALCULATOR     |\n" CLR_RESET);
    printf(CLR_CYAN CLR_BOLD "  +==============================+\n" CLR_RESET);
    printf(CLR_DIM  "  ------------------------------\n" CLR_RESET);
    printf("  " CLR_YELLOW "[1]" CLR_RESET "  Addition         (a + b)\n");
    printf("  " CLR_YELLOW "[2]" CLR_RESET "  Subtraction      (a - b)\n");
    printf("  " CLR_YELLOW "[3]" CLR_RESET "  Multiplication   (a * b)\n");
    printf("  " CLR_YELLOW "[4]" CLR_RESET "  Division         (a / b)\n");
    printf("  " CLR_YELLOW "[5]" CLR_RESET "  Modulus          (a %% b)\n");
    printf("  " CLR_YELLOW "[6]" CLR_RESET "  Power            (a ^ b)\n");
    printf("  " CLR_YELLOW "[7]" CLR_RESET "  Square Root      (sqrt a)\n");
    printf("  " CLR_YELLOW "[8]" CLR_RESET "  Absolute Value   (|a|)\n");
    printf(CLR_DIM  "  ------------------------------\n" CLR_RESET);
    printf("  " CLR_RED "[0]" CLR_RESET "  Exit\n");
    printf(CLR_DIM  "  ------------------------------\n" CLR_RESET);
    printf("  Enter choice: ");
}

void display_result(CalcResult res)
{
    if (res.status != CALC_OK) {
        printf("\n  " CLR_RED "[!] %s\n" CLR_RESET, res.message);
    } else {
        printf("\n  " CLR_GREEN "[=] Result = %g\n" CLR_RESET, res.value);
    }
}

int get_operation(void)
{
    int choice;
    if (scanf("%d", &choice) != 1) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        return -1;
    }
    return choice;
}

int get_operands(double *a, double *b, int needs_two)
{
    printf("  Enter operand A: ");
    if (scanf("%lf", a) != 1) {
        printf(CLR_RED "  Invalid input.\n" CLR_RESET);
        int c; while ((c = getchar()) != '\n' && c != EOF);
        return 0;
    }
    if (needs_two) {
        printf("  Enter operand B: ");
        if (scanf("%lf", b) != 1) {
            printf(CLR_RED "  Invalid input.\n" CLR_RESET);
            int c; while ((c = getchar()) != '\n' && c != EOF);
            return 0;
        }
    }
    return 1;
}
