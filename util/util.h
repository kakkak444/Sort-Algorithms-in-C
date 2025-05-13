#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef UTIL_MIN_RAND
    #define UTIL_UTIL_H_LOCALLY_DEFINED_MIN_RAND
    #define UTIL_MIN_RAND 0
#endif

#ifndef UTIL_MAX_RAND
    #define UTIL_UTIL_H_LOCALLY_DEFINED_MAX_RAND
    #define UTIL_MAX_RAND 10
#endif


void print_arr(const size_t n, const int arr[]) {
    printf("[ ");

    if (n > 0) {
        printf("%d", arr[0]);
        for (size_t i = 1;i < n;++i) {
            printf(", %d", arr[i]);
        }
    }

    printf(" ]\n");
}

int is_sorted(const size_t n, const int arr[]) {
    int a = arr[0];
    for (size_t i = 0;i < n;++i) {
        if (arr[i] < a) {
            return 0;
        }

        a = arr[i];
    }

    return 1;
}

void swap(int* const x, int* const y) {
    if (x == y) {
        return;
    }

    int t;

    t = *x;
    *x = *y;
    *y = t;
}

void generate_arr(int (*const gen)(void), const size_t n, int arr[]) {
    for (size_t i = 0;i < n;++i) {
        arr[i] = gen();
    }
}

void init_random(void) {
    srand(time(NULL));
}

int get_random(void) {
    return UTIL_MIN_RAND + (rand() % (UTIL_MAX_RAND - UTIL_MIN_RAND));
}


#ifdef UTIL_UTIL_H_LOCALLY_DEFINED_MIN_RAND
    #undef UTIL_MIN_RAND
#endif

#ifdef UTIL_UTIL_H_LOCALLY_DEFINED_MAX_RAND
    #undef UTIL_MAX_RAND
#endif
