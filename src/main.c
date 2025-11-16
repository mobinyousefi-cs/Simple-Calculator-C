/*
 * Project: Simple Calculator in C
 * File: main.c
 * Author: Mobin Yousefi (GitHub: github.com/mobinyousefi-cs)
 * Created: 2025-11-16
 * Updated: 2025-11-16
 * License: MIT License (see LICENSE file for details)
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "calculator.h"

#define INPUT_BUFFER_SIZE 256

static void print_banner(void)
{
    printf("=============================\n");
    printf("  Simple Calculator (C11)\n");
    printf("  Author: Mobin Yousefi\n");
    printf("=============================\n\n");

    printf("Enter an expression (e.g., 3 + 4) or 'q' to quit.\n\n");
}

int main(void)
{
    char buffer[INPUT_BUFFER_SIZE];

    print_banner();

    while (1)
    {
        double a = 0.0;
        double b = 0.0;
        char op_char = '\0';
        int parsed = 0;

        printf("> ");

        if (fgets(buffer, sizeof buffer, stdin) == NULL)
        {
            /* End of input (Ctrl+D / Ctrl+Z), exit gracefully. */
            printf("\nEnd of input detected. Exiting.\n");
            break;
        }

        /* Allow quick exit if the first non-whitespace character is 'q' or 'Q'. */
        {
            char *p = buffer;
            while (*p == ' ' || *p == '\t')
            {
                ++p;
            }
            if (*p == 'q' || *p == 'Q')
            {
                printf("Goodbye!\n");
                break;
            }
        }

        parsed = sscanf(buffer, "%lf %c %lf", &a, &op_char, &b);
        if (parsed != 3)
        {
            printf("Input error: please enter in the form: number operator number (e.g., 3 + 4).\n");
            continue;
        }

        Operation op;
        int op_err = parse_operation(op_char, &op);
        if (op_err != CALC_SUCCESS)
        {
            printf("Error: unsupported operator '%c'. Use one of: + - * /\n", op_char);
            continue;
        }

        int calc_err = CALC_SUCCESS;
        double result = calculate(a, b, op, &calc_err);

        if (calc_err == CALC_ERR_DIV_BY_ZERO)
        {
            printf("Error: Division by zero is not allowed.\n");
            continue;
        }
        else if (calc_err == CALC_ERR_UNKNOWN_OP)
        {
            printf("Error: unknown calculation error.\n");
            continue;
        }

        printf("Result: %.10g\n", result);
    }

    return EXIT_SUCCESS;
}
