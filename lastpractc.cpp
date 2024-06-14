#include <iostream>
#include <thread>
#include <vector>

class MergeSort {
public:
    void Sortirovka(std::vector<int>& arr) {
        if (arr.size() <= 1) {
            return;
        }

        int mid = arr.size() / 2;
        std::vector<int> left(arr.begin(), arr.begin() + mid);
        std::vector<int> right(arr.begin() + mid, arr.end());

        Sortirovka(left);
        Sortirovka(right);

        Merge(arr, left, right);
    }

private:
    void Merge(std::vector<int>& arr, const std::vector<int>& left, const std::vector<int>& right) {
        int i = 0, j = 0, k = 0;

        while (i < left.size() && j < right.size()) {
            if (left[i] < right[j]) {
                arr[k] = left[i];
                i++;
            }
            else {
                arr[k] = right[j];
                j++;
            }
            k++;
        }

        while (i < left.size()) {
            arr[k] = left[i];
            i++;
            k++;
        }

        while (j < right.size()) {
            arr[k] = right[j];
            j++;
            k++;
        }
    }
};


int main() {
    std::vector<int> array(10);

    std::cout << "Vvedite 10 celih chisel: ";
    for (int i = 0; i < 10; ++i) {
        std::cin >> array[i];
    }

    MergeSort mergeSort;
    auto sortFunc = [&mergeSort, &array]() {
        mergeSort.Sortirovka(array);
        };

    std::thread mergeSortThread(sortFunc);

    mergeSortThread.join();

    std::cout << "Otsortirovannit massiv: ";
    for (int num : array) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}