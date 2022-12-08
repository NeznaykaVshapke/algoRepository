#include <iostream>
#include <optional>
#include <vector>
template <typename T>
class MinHeap {
 public:
  MinHeap() : data_(kCapacity), size_(0) {}
  std::optional<T> ExtractMin();

  void Insert(T);

  bool Empty() const { return size_ == 0; }

 private:
  void SiftUp(size_t);

  void SiftDown(size_t);

  static constexpr size_t kCapacity = 8;
  std::vector<T> data_;
  size_t size_;
};
template <typename T>
std::optional<T> MinHeap<T>::ExtractMin() {
  if (size_ == 0) {
  return std::nullopt;
  }
  std::swap(data_[0], data_[size_ - 1]);
  --size_;
  SiftDown(0);
  return data_[size_];
}

template <typename T>
void MinHeap<T>::Insert(T value){
  if (size_ == data_.size()) {
  data_.resize(2 * size_);
  }
  data_[size_++] = value;
  SiftUp(size_ - 1);
}

template <typename T>
void MinHeap<T>::SiftUp(size_t index) {
  if (index > 0) {
    size_t parent = (index - 1) / 2;
    if (data_[index] < data_[parent]) {
      std::swap(data_[index], data_[parent]);
      SiftUp(parent);
    }
  }
}

template <typename T>
void MinHeap<T>::SiftDown(size_t index) {
  size_t i_min = index;
  size_t i_left_child = index * 2 + 1;
  size_t i_right_child = index * 2 + 2;
  if (i_left_child < size_ && data_[i_left_child] < data_[i_min]) {
  i_min = i_left_child;
  }
  if (i_right_child < size_ && data_[i_right_child] < data_[i_min]) {
  i_min = i_right_child;
  }
  if (index != i_min) {
  std::swap(data_[i_min], data_[index]);
  SiftDown(i_min);
  }
}

template <typename T>
std::vector<T> Merge(const std::vector<std::vector<T>>& matrix) {
  size_t size_matrix = 0;
  std::vector<size_t> indexes(matrix.size(), 0);
  MinHeap<std::pair<T, size_t>> kucha;
  std::vector<T> new_mass;
  for (size_t i = 0; i < matrix.size();
       ++i) {  //заполняем кучу нулевыми элементами каждого массива
    if (!matrix[i].empty()) {
      kucha.Insert({matrix[i][0], i});
    }
    size_matrix += matrix[i].size();
  }
  new_mass.reserve(size_matrix);  //отсортированный массив
  while (!kucha.Empty()) {
    auto[value, value_ind] = *kucha.ExtractMin();
    new_mass.push_back(value);
    ++indexes[value_ind];
    if (indexes[value_ind] < matrix[value_ind].size()) {
      kucha.Insert({matrix[value_ind][indexes[value_ind]], value_ind});
    }
  }
  return new_mass;
}

void Input(std::vector<std::vector<int>>& matrix, size_t len) {
  size_t len_arr, s = 0;
  int k;
  for (size_t i = 0; i < len; i++) {
    std::cin >> len_arr;
    s += len_arr;
    matrix.push_back(std::vector<int>());
    for (size_t j = 0; j < len_arr; ++j) {
      std::cin >> k;
      matrix[i].push_back(k);
    }
  }
}

void Output(auto new_mass) {
  for (size_t i = 0; i < new_mass.size(); ++i) {
    std::cout << new_mass[i] << " ";
  }
}
int main() {
  std::vector<std::vector<int>> matrix;
  size_t len;
  std::cin >> len;
  Input (matrix, len);
  auto new_mass = Merge(matrix);
  Output(new_mass);
}
