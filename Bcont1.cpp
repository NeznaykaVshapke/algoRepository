#include <iostream>
void Input(int* arr, size_t long_arr) {
  for (size_t i = 0; i < long_arr; ++i) {
    std::cin >> arr[i];
  }
}
int CyclicShift(int* arr, size_t long_arr) {
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
  return right;
}
int main() {
  size_t long_arr;
  std::cin >> long_arr;
  int* arr = new int[long_arr];
  Input(arr, long_arr);
  int answer;
  answer = CyclicShift(arr, long_arr);
  std::cout << ans;
  delete[] arr;
  return 0;
}
