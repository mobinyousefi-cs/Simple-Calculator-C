/*
 * Project: Simple Calculator in C
 * File: calculator.h
 * Author: Mobin Yousefi (GitHub: github.com/mobinyousefi-cs)
 * Created: 2025-11-16
 * Updated: 2025-11-16
 * License: MIT License (see LICENSE file for details)
 * ============================================================================
 */

#ifndef SIMPLE_CALCULATOR_CALCULATOR_H
#define SIMPLE_CALCULATOR_CALCULATOR_H

/**
 * @file calculator.h
 * @brief Public API for basic arithmetic operations.
 */

/**
 * @enum Operation
 * @brief Supported arithmetic operations.
 */
typedef enum
{
    OP_ADD,
    OP_SUBTRACT,
    OP_MULTIPLY,
    OP_DIVIDE
} Operation;

/**
 * @def CALC_SUCCESS
 * @brief No error occurred.
 */
#define CALC_SUCCESS 0

/**
 * @def CALC_ERR_DIV_BY_ZERO
 * @brief Division by zero error.
 */
#define CALC_ERR_DIV_BY_ZERO 1

/**
 * @def CALC_ERR_UNKNOWN_OP
 * @brief Unknown/unsupported operator.
 */
#define CALC_ERR_UNKNOWN_OP 2

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Convert an operator character to an Operation enum value.
 *
 * @param op_char Input operator character (e.g., '+', '-', '*', '/').
 * @param out_op Pointer to Operation to store the result.
 * @return int CALC_SUCCESS on success, CALC_ERR_UNKNOWN_OP on failure.
 */
int parse_operation(char op_char, Operation *out_op);

/**
 * @brief Perform the specified arithmetic operation on two operands.
 *
 * @param a First operand.
 * @param b Second operand.
 * @param op Operation to perform.
 * @param error Optional pointer to receive an error code.
 *             - CALC_SUCCESS          on success
 *             - CALC_ERR_DIV_BY_ZERO  if division by zero is attempted
 *             - CALC_ERR_UNKNOWN_OP   if the operation is not supported
 * @return double Result of the arithmetic operation (undefined if error != CALC_SUCCESS).
 */
double calculate(double a, double b, Operation op, int *error);

#ifdef __cplusplus
}
#endif

#endif /* SIMPLE_CALCULATOR_CALCULATOR_H */
