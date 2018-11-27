#ifndef SUFFIX_H
#define SUFFIX_H

#include "str.h"

typedef struct {
    String *s;
    int index;
} Suffix;

Suffix* create_suffix(String *s, int index);

void destroy_suffix(Suffix *suf);

void print_suffix(Suffix *suf);

Suffix** create_suf_array(String *text, int N);

void destroy_suf_array(Suffix* *a, int N);

void print_suf_array(Suffix* *a, int N);

void sort_suf_array_sys(Suffix* *a, int N);

void sort_suf_array_msd(Suffix* *a, int N);

int rank(Suffix* *a, int N, String *query);

#endif
