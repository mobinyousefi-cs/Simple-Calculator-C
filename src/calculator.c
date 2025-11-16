/*
 * Project: Simple Calculator in C
 * File: calculator.c
 * Author: Mobin Yousefi (GitHub: github.com/mobinyousefi-cs)
 * Created: 2025-11-16
 * Updated: 2025-11-16
 * License: MIT License (see LICENSE file for details)
 * ============================================================================
 */

#include "calculator.h"

int parse_operation(char op_char, Operation *out_op)
{
    if (out_op == (Operation *)0)
    {
        return CALC_ERR_UNKNOWN_OP;
    }

    switch (op_char)
    {
        case '+':
            *out_op = OP_ADD;
            return CALC_SUCCESS;
        case '-':
            *out_op = OP_SUBTRACT;
            return CALC_SUCCESS;
        case '*':
            *out_op = OP_MULTIPLY;
            return CALC_SUCCESS;
        case '/':
            *out_op = OP_DIVIDE;
            return CALC_SUCCESS;
        default:
            return CALC_ERR_UNKNOWN_OP;
    }
}

double calculate(double a, double b, Operation op, int *error)
{
    if (error != (int *)0)
    {
        *error = CALC_SUCCESS;
    }

    switch (op)
    {
        case OP_ADD:
            return a + b;
        case OP_SUBTRACT:
            return a - b;
        case OP_MULTIPLY:
            return a * b;
        case OP_DIVIDE:
            if (b == 0.0)
            {
                if (error != (int *)0)
                {
                    *error = CALC_ERR_DIV_BY_ZERO;
                }
                return 0.0;
            }
            return a / b;
        default:
            if (error != (int *)0)
            {
                *error = CALC_ERR_UNKNOWN_OP;
            }
            return 0.0;
    }
}
