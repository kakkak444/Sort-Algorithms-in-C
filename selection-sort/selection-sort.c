#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UTIL_MIN_RAND  0
#define UTIL_MAX_RAND 10

#include "util/util.h"

#define N 10

void selection_sort(size_t n, int arr[]);

int main(void) {
    srand(time(NULL));

    int arr[N];
    generate_arr(get_random, N, arr);

    print_arr(N, arr);

    selection_sort(N, arr);

    print_arr(N, arr);

    return 0;
}

void selection_sort(const size_t n, int arr[]) {
    for (size_t i = 0;i < n;++i) {
        int min_idx = i;

        for (size_t j = i + 1;j < n;++j) {
            if (arr[min_idx] > arr[j]) {
                min_idx = j;
            }
        }

        swap(&arr[min_idx], &arr[i]);
    }
}
