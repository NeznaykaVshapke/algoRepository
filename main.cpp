#include <iostream>
#include <vector>
using X = std::vector<uint64_t>;
using U = uint64_t;
const U kArr1 = (static_cast<U>(1) << 9) - 1;
inline void ZifrSort(X& massiv, int razr) {
  const U kArr2 = static_cast<U>(1) << ((razr - 1) * 8);
  int size_massiv = massiv.size();
  X cnt(kArr1 + 1, 0);
  X massiv2(size_massiv, 0);
  U t;
  U delta = (kArr1 << (razr - 1) * 8);
  for (int i = 0; i < size_massiv; ++i) {
    t = massiv[i] & delta;
    t /= kArr2;
    cnt[t]++;
    massiv2[i] = massiv[i];
  }
  X summ(kArr1 + 1, 0);
  for (size_t i = 1; i < summ.size(); ++i) {
    summ[i] = cnt[i - 1] + summ[i - 1];
  }
  for (int i = 0; i < size_massiv; ++i) {
    t = massiv2[i] & delta;
    t /= kArr2;
    massiv[summ[t]++] = massiv2[i];
  }
}

inline void LSD(X& massiv) {
  for (int i = 1; i <= 8; ++i) {
    ZifrSort(massiv, i);
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int n;
  std::cin >> n;
  X massiv(n);
  for (int i = 0; i < n; i++) {
    std::cin >> massiv[i];
  }
  LSD(massiv);
  for (auto x : massiv) {
    std::cout << x << "\n";
  }
  return 0;
}
