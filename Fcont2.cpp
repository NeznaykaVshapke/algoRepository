#include <iostream>
#include <vector>
const uint64_t kArr1 = (static_cast<uint64_t>(1) << 9) - 1;
inline void LSDSort(std::vector<uint64_t>& array, int digit) {
  const uint64_t kArr2 = static_cast<uint64_t>(1) << ((digit - 1) * 8);
  size_t size_array = array.size();
  std::vector<uint64_t> cnt(kArr1 + 1, 0);
  std::vector<uint64_t> array2(size_array, 0);
  uint64_t t;
  uint64_t delta = (kArr1 << (digit - 1) * 8);
  for (size_t i = 0; i < size_array; ++i) {
    t = array[i] & delta;
    t /= kArr2;
    cnt[t]++;
    array2[i] = array[i];
  }
  std::vector<uint64_t> summ(kArr1 + 1, 0);
  for (size_t i = 1; i < summ.size(); ++i) {
    summ[i] = cnt[i - 1] + summ[i - 1];
  }
  for (size_t i = 0; i < size_massiv; ++i) {
    t = array2[i] & delta;
    t /= kArr2;
    array[summ[t]++] = array2[i];
  }
}

inline void LSDSort(std::vector<uint64_t>& array) {
  for (size_t i = 1; i <= 8; ++i) {
    LSDSort(array, i);
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  size_t n;
  std::cin >> n;
  std::vector<uint64_t> array(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> array[i];
  }
  LSD(array);
  for (auto x : array) {
    std::cout << x << "\n";
  }
  return 0;
}
