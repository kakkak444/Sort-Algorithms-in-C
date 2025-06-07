#include <stdio.h>

#include "../util/util.h"

#define N 10

/// Invariant : 0 <= `l`, `r` <= `length(arr)`
void quick_sort_helper(int arr[], int pivot, int l, int r);
void quick_sort(const size_t n, int arr[]);

int main(void) {
    init_random();

    int arr[N];
    generate_arr(get_random, N, arr);

    print_arr(N, arr);
    quick_sort(N, arr);
    print_arr(N, arr);

    printf("Correctly Sorted?: %d\n", is_sorted(N, arr));

    return 0;
}

void quick_sort(const size_t n, int arr[]) {
    if (n == 0) {
        return;
    }

    int pivot = arr[n / 2];
    quick_sort_helper(arr, pivot, 0, n - 1);
}

void quick_sort_helper(int arr[], int pivot, int l, int r) {
    if (l >= r) {
        return;
    }

    int pl = l - 1, pr = r + 1;
    while (1) {
        do {
            ++pl;
        } while (arr[pl] < pivot);

        do {
            --pr;
        } while (arr[pr] > pivot);

        if (pl >= pr) {
            break;
        }

        swap(&arr[pr], &arr[pl]);
    }

    int partition = pr;

    int l_pivot = arr[(l + partition) / 2];
    int r_pivot = arr[(partition + 1 + r) / 2];

    quick_sort_helper(arr, l_pivot, l, partition);
    quick_sort_helper(arr, r_pivot, partition + 1, r);
}
