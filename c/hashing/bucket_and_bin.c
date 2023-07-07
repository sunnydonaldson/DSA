#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define NUM_BOUNDS 7

static size_t NUM_BUCKETS = 150000000;


void zeroFill(int *arr, size_t size) {
  for (size_t i = 0; i < size; i++) {
    arr[i] = 0; }
}


int main() {
  int *buckets = malloc(NUM_BUCKETS * sizeof(int));
  int *visited = malloc(NUM_BUCKETS *sizeof(int));
  zeroFill(buckets, NUM_BUCKETS);

  for (int i = 0; i < NUM_BUCKETS; i++) {
    buckets[rand() % NUM_BUCKETS ] += 1;
  }

  int bounds[NUM_BOUNDS] = {100, 50, 25, 10, 5, 1, 0};
  int buckets_within_bound[NUM_BOUNDS] = {0};

  for (size_t i = 0; i < NUM_BOUNDS; i++) {
    for (size_t j = 0; j < NUM_BUCKETS; j++) {
      if (visited[j]) {
        continue;
      }
      if (buckets[j] >= bounds[i]) {
        buckets_within_bound[i] += 1;
        visited[i]++;
      }
    }
  }

  for (size_t i = 0; i < NUM_BOUNDS; i++) {
    printf("%d: %d\n", bounds[i], buckets_within_bound[i]);
  }
  free(buckets);   
  free(visited);
  return 0;
}
