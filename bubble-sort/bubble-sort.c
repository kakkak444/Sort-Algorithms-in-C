#include <stdio.h>

#include "util/util.h"

#define N 10

void bubble_sort(const size_t n, int arr[]);

int main(void) {
    init_random();

    int arr[N];
    generate_arr(get_random, N, arr);

    print_arr(N, arr);
    bubble_sort(N, arr);
    print_arr(N, arr);

    printf("Sorted Correctly?: %d\n", is_sorted(N, arr));

    return 0;
}

void bubble_sort(const size_t n, int arr[]) {
    for (size_t i = 0;i < n;++i) {
        for (size_t j = 0;j < n - i;++j) {
            if (arr[j - 1] > arr[j]) {
                swap(&arr[j - 1], &arr[j]);
            }
        }
    }
}
