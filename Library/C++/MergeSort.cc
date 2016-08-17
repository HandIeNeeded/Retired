template<class T>
void MergeSort(T first, T last) {
  if (last - first > 1) {
    auto middle = first + (last - first) / 2;
    MergeSort(first, middle);
    MergeSort(middle, last);
    std::inplace_merge(first, middle, last);
  }
}

