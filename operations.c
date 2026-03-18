/* ============================================================
 * operations.c — Implementation of all arithmetic operations
 * ============================================================ */

#include <math.h>
#include <stdio.h>
#include <string.h>
#include "calculator.h"

/* ── helpers ──────────────────────────────────────────────── */

static CalcResult make_result(double val, int status, const char *msg)
{
    CalcResult r;
    r.value  = val;
    r.status = status;
    strncpy(r.message, msg, sizeof(r.message) - 1);
    r.message[sizeof(r.message) - 1] = '\0';
    return r;
}

/* ── arithmetic ───────────────────────────────────────────── */

CalcResult calc_add(double a, double b)
{
    return make_result(a + b, CALC_OK, "OK");
}

CalcResult calc_sub(double a, double b)
{
    return make_result(a - b, CALC_OK, "OK");
}

CalcResult calc_mul(double a, double b)
{
    return make_result(a * b, CALC_OK, "OK");
}

CalcResult calc_div(double a, double b)
{
    if (b == 0.0)
        return make_result(0.0, CALC_ERR_DIVZERO, "Error: Division by zero");

    return make_result(a / b, CALC_OK, "OK");
}

CalcResult calc_mod(double a, double b)
{
    if ((long long)b == 0)
        return make_result(0.0, CALC_ERR_DIVZERO, "Error: Modulus by zero");

    /* fmod preserves sign of dividend — matches C standard behaviour */
    return make_result(fmod(a, b), CALC_OK, "OK");
}

CalcResult calc_pow(double base, double exp)
{
    /* Catch 0^(negative) — mathematically undefined */
    if (base == 0.0 && exp < 0.0)
        return make_result(0.0, CALC_ERR_DOMAIN,
                           "Error: 0 raised to negative exponent");

    return make_result(pow(base, exp), CALC_OK, "OK");
}

CalcResult calc_sqrt(double a)
{
    if (a < 0.0)
        return make_result(0.0, CALC_ERR_DOMAIN,
                           "Error: Square root of negative number");

    return make_result(sqrt(a), CALC_OK, "OK");
}

CalcResult calc_abs(double a)
{
    return make_result(fabs(a), CALC_OK, "OK");
}
