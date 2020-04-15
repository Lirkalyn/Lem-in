/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** all functions
*/

#ifndef __MY_H__
#define __MY_H__

//Headers
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdarg.h>

//Header file
#include "print.h"

int my_isneg(int nb);
int my_putchar_ls(int nb);
void bad_usage(void);
void bad_malloc(void);
void bad_syntax(void);
void my_put_nbr(int nb);
void my_putchar(char c);
void my_putchar_in(char c);
void my_octal(int nb);
void hexa_long(long long nb);
void char_printable(char *str);
void binary(unsigned int nb);
void octal(unsigned int nb);
void hexa(unsigned int nb);
void hexa_upper(unsigned int nb);
void pointer(long long nb);
void string(char *str);
void decimal(int nb);
int my_is_prime (int nb);
int my_put_nbr_ls(int nb);
char *my_revstr(char *str);
void *my_strdel(char **str);
void my_swap(int *a, int *b);
char *my_strconfig(int size);
void report(char const *str);
void my_put_nbr_long(long long nb);
int my_atoi(char const *str);
char *my_strupcase(char *str);
void my_putchar_error(char c);
char *my_strlowcase(char *str);
int my_strlen(char const *str);
void to_str(char str[], int nb);
int my_find_prime_sup (int nb);
int my_getnbr (char *str);
int my_printf(char *str, ...);
int my_delim(char s, char *lim);
void my_putstr(char const *str);
void my_putstr_in(char const *str);
char *my_strdup(char *str);
void my_showstr(char const *str);
char *my_strcapitalize(char *str);
int my_str_isnum(char const *str);
void my_put_nbr_u(unsigned int nb);
void my_put_nbr_long(long long nb);
int my_compute_square_root (int nb);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
void my_putstr_error(char const *str);
void my_put_nbr_base(int nb, char *base);
int my_showmem(char const *str, int size);
int word_size(char *str, int i, char *lim);
int my_compute_power_rec(int nb, int power);
char *my_strcat(char *dest, char *src);
void my_sort_int_array(int *tab, int size);
char *my_strcpy(char *dest, char const *src);
int count_words(char const *str, char *limit);
int my_strcmp(char *s1, char *s2);
char *my_strstr(char *str, char const *to_find);
char **my_str_to_word_array(char *str, char *lim);
int while_delim(char const *str, int a, char *lim);
char *my_strncpy (char *dest, char const *src, int n);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strsub(char const *str, unsigned int start, int len);
#endif /*__MY_H__*/
