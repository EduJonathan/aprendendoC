#ifndef PRINTLN_H
#define PRINTLN_H

#include <stdio.h>
#include <stdarg.h>

// Declaração da nossa função (interface)
int println(const char *format, ...);

// Declaração da função interna que usará assembly
int _println_internal(const char *str);

#endif
