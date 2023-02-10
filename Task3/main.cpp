#include <iostream>
#include <cmath>

const double* aver(const double* arr, size_t size, double& average) {
  double sum = 0;
  for (int i = 0; i < size; i++) {
    sum += arr[i];
  }
  average = sum / size;
  
  double closest = fabs(arr[0] - average);
  int closestIndex = 0;
  for (int i = 1; i < size; i++) {
    double diff = fabs(arr[i] - average);
    if (diff < closest) {
      closest = diff;
      closestIndex = i;
    }
  }
  
  return arr + closestIndex;
}

int main () {
    using std::cout; using std::endl;
    double arr[] = {1, 2, -1.5 , 3.25, 5.5, 7.75, -0.25, 5.75};
    size_t size = std::size(arr);
    double average = 0;
    const double* p = aver(arr, size, average);
    cout << *p << " " << average << endl;
}