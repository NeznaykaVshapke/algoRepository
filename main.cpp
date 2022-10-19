#include <iostream>

int main() {
  int long_arr;
  std::cin >> long_arr;
  int* arr = new int[long_arr];
  for (int i = 0; i < long_arr; ++i) {
    std::cin >> arr[i];
  }
  int right = long_arr - 1;
  int left = -1;
  const int kLast = arr[long_arr - 1];
  while (right > left + 1) {
    int centre = (right + left) / 2;
    if (arr[centre] > kLast) {
      left = centre;
    } else {
      right = centre;
    }
  }
  std::cout << right;
  delete[] arr;
  return 0;
}
