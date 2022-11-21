#include <iostream>
#include <vector>
const uint64_t kArr1 = (static_cast<uint64_t>(1) << 9) - 1;
inline void LSDSort(std::vector<uint64_t>& massiv, int razr) {
  const uint64_t kArr2 = static_cast<uint64_t>(1) << ((razr - 1) * 8);
  size_t size_massiv = massiv.size();
  std::vector<uint64_t> cnt(kArr1 + 1, 0);
  std::vector<uint64_t> massiv2(size_massiv, 0);
  uint64_t t;
  uint64_t delta = (kArr1 << (razr - 1) * 8);
  for (size_t i = 0; i < size_massiv; ++i) {
    t = massiv[i] & delta;
    t /= kArr2;
    cnt[t]++;
    massiv2[i] = massiv[i];
  }
  std::vector<uint64_t> summ(kArr1 + 1, 0);
  for (size_t i = 1; i < summ.size(); ++i) {
    summ[i] = cnt[i - 1] + summ[i - 1];
  }
  for (size_t i = 0; i < size_massiv; ++i) {
    t = massiv2[i] & delta;
    t /= kArr2;
    massiv[summ[t]++] = massiv2[i];
  }
}

inline void LSD(std::vector<uint64_t>& massiv) {
  for (size_t i = 1; i <= 8; ++i) {
    LSDSort(massiv, i);
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  size_t n;
  std::cin >> n;
  std::vector<uint64_t> massiv(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> massiv[i];
  }
  LSD(massiv);
  for (auto x : massiv) {
    std::cout << x << "\n";
  }
  return 0;
}
