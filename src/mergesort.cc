#include "mergesort.h"

namespace sort {

std::vector<int> buf1 = std::vector<int>(), buf2 = std::vector<int>();

void MergeSort(std::vector<int>& arr, int l, int r) {
  if (l >= r) return;

  // Initialize buffer
  if (buf1.size() != arr.size()) {
    buf1 = std::vector<int>(arr);
  }
  if (buf2.size() != arr.size()) {
    buf2 = std::vector<int>(arr);
  }

  int mid = (l+r)/2;
  MergeSort(arr, l, mid);
  MergeSort(arr, mid+1, r);
    
  for (int i = l; i <= mid; i++) buf1[i] = arr[i];
  for (int i = mid+1; i <= r; i++) buf2[i] = arr[i];

  int p = l, q = mid+1;
  int disp = 0;
  while (p!=mid+1&&q!=r+1) {
    if (buf1[p] < buf2[q]) {
      arr[l+disp] = buf1[p];
      ++p;
    }
    else {
      arr[l+disp] = buf2[q];
      ++q;
    }
    ++disp;
  }
  while (p != mid+1) {
    arr[l+disp] = buf1[p];
    ++p;
    ++disp;
  }
  while (q != r+1) {
    arr[l+disp] = buf2[q];
    ++q;
    ++disp;
  }
}

} // namespace sort