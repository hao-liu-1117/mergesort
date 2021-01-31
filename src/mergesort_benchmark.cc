#include <benchmark/benchmark.h>

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "mergesort.h"

static void BM_MergeSort(benchmark::State& state) {

  auto length = state.range(0);

  std::vector<int> arr(length, 0);
  std::srand(std::time(nullptr));
  for (int i = 0; i < length; i++) {
    arr[i] = std::rand();
  }

  while (state.KeepRunning()) {
    sort::MergeSort(arr, 0, arr.size()-1);
  }
  state.SetItemsProcessed(state.iterations());
  state.SetComplexityN(state.range(0));
};

BENCHMARK(BM_MergeSort)
  ->Args({1<<2})
  ->Args({1<<3})
  ->Args({1<<4})
  ->Args({1<<5})
  ->Args({1<<6})
  ->Args({1<<7})
  ->Args({1<<8})
  ->Args({1<<9})
  ->Args({1<<10})
  ->Args({1<<11})
  ->Args({1<<12})
  ->Args({1<<13})
  ->Args({1<<14})
  ->Args({1<<15})
  ->Complexity();

BENCHMARK_MAIN();