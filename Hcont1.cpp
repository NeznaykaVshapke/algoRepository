#include <cmath>
#include <iomanip>
#include <iostream>
inline void SrGeom(double* arr, int& longarr) {
  for (int i = 1; i < longarr; i++) {
    double srgeom = pow(arr[i], (1.0 / (i + 1.0)));
    double srgeom1 = pow(arr[i - 1], (i * 1.0) / (i + 1.0));
    arr[i] = srgeom * srgeom1;
  }
  int q;
  std::cin >> q;
  for (int i = 0; i < q; i++) {
    int begin;
    int end;
    std::cin >> begin;
    std::cin >> end;
    begin--;
    double ans = 0.0;
    if (begin != -1) {
      double st1 = pow(arr[begin], 1.0 / (1.0 * end - 1.0 * begin));
      double stend = pow(arr[end], 1.0 / (1.0 * end - 1.0 * begin));
      double stbegin = pow(st1, (begin + 1.0) / (end + 1.0));
      ans = stend / stbegin;
      ans = pow(ans, (end + 1.0));
    } else {
      ans = arr[end];
    }
    std::cout << std::fixed;
    std::cout << std::setprecision(9) << ans << "\n";
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int longarr;
  std::cin >> longarr;
  double* arr = new double[longarr];
  for (int i = 0; i < longarr; i++) {
    std::cin >> arr[i];
  }
  SrGeom(arr, longarr);
  delete[] arr;
  return 0;
}
