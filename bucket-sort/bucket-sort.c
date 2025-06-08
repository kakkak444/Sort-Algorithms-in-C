#include <stdio.h>

#define UTIL_MIN_RAND  0
#define UTIL_MAX_RAND 10

#include "util/util.h"
#include "util/queue.h"

#define BUCKET_LEN 10
#define N 10

typedef struct {
    Queue queues[BUCKET_LEN];
} Bucket;

void init_bucket(Bucket* bucket);
void deinit_bucket(Bucket* bucket);


void bucket_sort(const size_t n, int arr[]);

int main(void) {
    init_random();

    int arr[N];
    generate_arr(get_random, N, arr);

    print_arr(N, arr);
    bucket_sort(N, arr);
    print_arr(N, arr);

    printf("Properly Sorted?: %d\n", is_sorted(N, arr));

    return 0;
}

void bucket_sort(const size_t n, int arr[]) {
    Bucket bucket;
    init_bucket(&bucket);

    for (size_t i = 0;i < n;++i) {
        int k = arr[i];
        enqueue(&(bucket.queues[k]), k);
    }

    int arr_idx = 0;
    for (int i = 0;i < BUCKET_LEN;++i) {
        size_t length = bucket.queues[i].length;
        for (size_t j = 0;j < length;++j) {
            dequeue(&bucket.queues[i], arr + (arr_idx++));
        }
    }

    deinit_bucket(&bucket);
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
