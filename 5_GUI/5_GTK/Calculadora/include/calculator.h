// include/calculator.h    ← new or rename grid.h
#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <gtk/gtk.h>

typedef struct
{
    char *expression;       // current input being built "2*(3+4"
    char *result_str;       // last computed result or error
    double memory;          // M+, M-, MR, MC
    gboolean decimal_point; // prevent multiple dots
    int paren_count;        // track open parentheses
    // ... history, angle mode (deg/rad), etc. later
} CalculatorState;

extern CalculatorState calc_state;

void calculator_init(void);
void calculator_reset(void);
void calculator_append_digit(const char *digit);
void calculator_append_operator(const char *op);
void calculator_append_function(const char *func); // sin, cos, √, etc.
void calculator_evaluate(void);
void calculator_backspace(void);
void calculator_toggle_sign(void);

#endif
