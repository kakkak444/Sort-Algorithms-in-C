#include <stdio.h>

#include <util/util.h>

#define N 10

/// Invariant : `to` <= `from`
void insert(int arr[], const size_t from, const size_t to);

void insertion_sort(const size_t n, int arr[]);

int main(void) {
    init_random();

    int arr[N];
    generate_arr(get_random, N, arr);

    print_arr(N, arr);
    insertion_sort(N, arr);
    print_arr(N, arr);

    printf("Successfully Sorted?: %d\n", is_sorted(N, arr));

    return 0;
}

void insertion_sort(const size_t n, int arr[]) {
    for (int i = 1;i < n;++i) {
        int insert_idx = i;

        for (int j = 0;j < i;++j) {
            if (arr[insert_idx] < arr[j]) {
                insert_idx = j;
                break;
            }
        }

        insert(arr, i, insert_idx);
    }
}

void insert(int arr[], const size_t from, const size_t to) {
    if (from == to) {
        return;
    }

    int tmp = arr[from];

    int i;
    for (i = from;i > to;--i) {
        arr[i] = arr[i-1];
    }

    arr[i] = tmp;
}
