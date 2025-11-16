/*
 * Project: Simple Calculator in C
 * File: test_calculator.c
 * Author: Mobin Yousefi (GitHub: github.com/mobinyousefi-cs)
 * Created: 2025-11-16
 * Updated: 2025-11-16
 * License: MIT License (see LICENSE file for details)
 * ============================================================================
 */

#include <assert.h>
#include <math.h>
#include <stdio.h>

#include "calculator.h"

static int double_equals(double x, double y)
{
    const double eps = 1e-9;
    return fabs(x - y) < eps;
}

static void test_addition(void)
{
    int err = CALC_SUCCESS;
    double result = calculate(1.0, 2.0, OP_ADD, &err);
    assert(err == CALC_SUCCESS);
    assert(double_equals(result, 3.0));
}

static void test_subtraction(void)
{
    int err = CALC_SUCCESS;
    double result = calculate(5.0, 3.0, OP_SUBTRACT, &err);
    assert(err == CALC_SUCCESS);
    assert(double_equals(result, 2.0));
}

static void test_multiplication(void)
{
    int err = CALC_SUCCESS;
    double result = calculate(4.0, 2.5, OP_MULTIPLY, &err);
    assert(err == CALC_SUCCESS);
    assert(double_equals(result, 10.0));
}

static void test_division(void)
{
    int err = CALC_SUCCESS;
    double result = calculate(10.0, 4.0, OP_DIVIDE, &err);
    assert(err == CALC_SUCCESS);
    assert(double_equals(result, 2.5));
}

static void test_division_by_zero(void)
{
    int err = CALC_SUCCESS;
    double result = calculate(10.0, 0.0, OP_DIVIDE, &err);
    (void)result; /* result value is undefined when error occurs */
    assert(err == CALC_ERR_DIV_BY_ZERO);
}

static void test_parse_operation(void)
{
    Operation op;
    int status;

    status = parse_operation('+', &op);
    assert(status == CALC_SUCCESS && op == OP_ADD);

    status = parse_operation('-', &op);
    assert(status == CALC_SUCCESS && op == OP_SUBTRACT);

    status = parse_operation('*', &op);
    assert(status == CALC_SUCCESS && op == OP_MULTIPLY);

    status = parse_operation('/', &op);
    assert(status == CALC_SUCCESS && op == OP_DIVIDE);

    status = parse_operation('%', &op);
    assert(status == CALC_ERR_UNKNOWN_OP);
}

int main(void)
{
    test_addition();
    test_subtraction();
    test_multiplication();
    test_division();
    test_division_by_zero();
    test_parse_operation();

    printf("All calculator tests passed successfully.\n");
    return 0;
}
