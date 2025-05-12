#pragma once

#include <stdio.h>

void print_array(const size_t n, const int arr[]) {
    printf("[ ");

    if (n > 0) {
        printf("%d", arr[0]);
        for (size_t i = 1;i < n;++i) {
            printf(", %d", arr[i]);
        }
    }

    printf("]\n");
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
