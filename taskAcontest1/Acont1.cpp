#include <iostream>
bool BinarySearch(const size_t* begin, const size_t* end, int target) {
  size_t left = 0;
  size_t right = end - begin;
  while (right >= left + 2) {
    size_t centre = (left + right) / 2;
    if (*(centre + begin) > target) {
      right = centre;
    } else {
      left = centre;
    }
  }
  return (target == *(left + begin));
}
int main() {
  size_t long_arr;
  std::cin >> long_arr;
  int* arr = new int[long_arr];
  for (size_t i = 0; i < long_arr; ++i) {
    std::cin >> arr[i];
  }
  size_t q;
  std::cin >> q;
  size_t begin;
  size_t end;
  int target;
  for (size_t i = 0; i < q; ++i) {
    std::cin >> begin >> end >> target;
    int* old_arr = arr;
    bool ans = BinarySearch(old_arr + begin, old_arr + end, target);
    if (ans) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
    }
  }
  delete[] arr;
  return 0;
}
