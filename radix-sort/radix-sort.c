#include <stdio.h>

#define UTIL_MIN_RAND     0
#define UTIL_MAX_RAND 65536
// #define UTIL_MAX_RAND 100

#include "util/util.h"
#include "util/queue.h"

// #define DBG

#define MOD 16
// #define MOD 10
#define BUCKET_LEN (MOD)

#define N 10

typedef struct {
    Queue queues[BUCKET_LEN];
} Bucket;

void init_bucket(Bucket* bucket);
void deinit_bucket(Bucket* bucket);


void radix_sort_helper(Bucket* bucket, const size_t n, int arr[], const int mod);
void radix_sort(const size_t n, int arr[], const int max);

int main(void) {
    init_random();

    int arr[N];
    generate_arr(get_random, N, arr);

    print_arr(N, arr);
    radix_sort(N, arr, UTIL_MAX_RAND - 1);
    print_arr(N, arr);

    printf("Sorted Correctly?: %d\n", is_sorted(N, arr));

    return 0;
}

void radix_sort(const size_t n, int arr[], const int max) {
    Bucket bucket;
    init_bucket(&bucket);

    for (int radix = 1;(int)(max / radix) != 0;radix *= MOD) {
        radix_sort_helper(&bucket, n, arr, radix);
    }

    deinit_bucket(&bucket);
}
void radix_sort_helper(Bucket* bucket, const size_t n, int arr[], const int radix) {
    for (size_t i = 0;i < n;++i) {
        int k = arr[i];
        enqueue(&(bucket->queues[(k / radix) % MOD]), k);
    }

    int arr_idx = 0;
    for (size_t i = 0;i < BUCKET_LEN;++i) {
        size_t length = bucket->queues[i].length;
        for (size_t j = 0;j < length;++j) {
            dequeue(&(bucket->queues[i]), arr + (arr_idx++));
        }
    }

#ifdef DBG
    printf("radix: %d\n", radix);
    print_arr(n, arr);
#endif
}


void init_bucket(Bucket* bucket) {
    for (int i = 0;i < BUCKET_LEN;++i) {
        init_queue( &(bucket->queues[i]) );
    }
}
void deinit_bucket(Bucket* bucket) {
    for (int i = 0;i < BUCKET_LEN;++i) {
        deinit_queue( &(bucket->queues[i]) );
    }
}
