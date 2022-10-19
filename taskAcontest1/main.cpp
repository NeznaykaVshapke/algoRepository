#include <iostream>
bool BinarySearch(const int* begin, const int* end, int target) {
  int left = 0;
  int right = end - begin;
  while (right >= left + 2) {
    int centre = (left + right) / 2;
    if (*(centre + begin) > target) {
      right = centre;
    } else {
      left = centre;
    }
  }
  return (target == *(left + begin));
}
int main() {
  int long_arr;
  std::cin >> long_arr;
  int* arr = new int[long_arr];
  for (int i = 0; i < long_arr; ++i) {
    std::cin >> arr[i];
  }
  int q;
  std::cin >> q;
  int begin;
  int end;
  int target;
  for (int i = 0; i < q; ++i) {
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
