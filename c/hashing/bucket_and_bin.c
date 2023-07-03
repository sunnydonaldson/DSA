#include<stdio.h>
#include<stdlib.h>

#define SIZE 1020000
#define BOUNDS_SIZE 7


int main() {
  int buckets[SIZE] = {0};
  for (int i = 0; i < SIZE; i++) {
    buckets[rand() % SIZE] += 1;
  }

  int visited[SIZE] = {0};
  int bounds[BOUNDS_SIZE] = {100, 50, 25, 10, 5, 1, 0};
  int buckets_within_bound[BOUNDS_SIZE] = {0};
  for (int i = 0; i < BOUNDS_SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      if (visited[j]) {
        continue;
      }
      if (buckets[j] >= bounds[i]) {
        buckets_within_bound[i] += 1;
        visited[i]++;
      }
    }
  }

  for (int i = 0; i < BOUNDS_SIZE; i++) {
    printf("%d: %d\n", bounds[i], buckets_within_bound[i]);
  }    
  return 0;
}
