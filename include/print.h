/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** print.h
*/

#ifndef __PRINT_H__
#define __PRINT_H__

//Headers
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdbool.h>

//Header file
#include "my.h"

typedef struct print
{
    int a;
    int err;
    va_list ap;
    void (*conversions[11])();
} print_t;

//char_functions
void string(char *str);
void my_octal(int nb);
void char_printable(char *str);
void characters(char c);

//nb_converter
void binary(unsigned int nb);
void octal(unsigned int nb);
void hexa(unsigned int nb);
void hexa_upper(unsigned int nb);
void pointer(long long nb);

//decimal
void decimal(int nb);
void unsigned_int(unsigned int nb);

//hexa_long
void hexa_long(long long nb);

//my_printf
int flags(char c);
void init_conv(void (**conversion)());
void flag_call(char c, void (**conversion)(), va_list ap);
void init_struct(print_t *print, char *str);
int my_printf(char *str, ...);
#endif
