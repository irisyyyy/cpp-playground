#include <iostream>
#include <vector>

void quick_sort(std::vector<int>& numbers, int first, int last);
int partition(std::vector<int>& numbers, int first, int last);
void swap(int& a, int& b);
void printList(std::vector<int>& list);

int main() {
    std::vector<int> numbers{ 65, 41, 9, 28, 55, 12, 11, 30, 79, 56, 17};
    
    std::cout << "Before sorting:\n";
    printList(numbers);

    quick_sort(numbers, 0, numbers.size() - 1);

    std::cout << "After sorting:\n";
    printList(numbers);
}

void quick_sort(std::vector<int>& numbers, int first, int last) {
    if (last > first) {
        int p_index = partition(numbers, first, last);
        quick_sort(numbers, first, p_index - 1);
        quick_sort(numbers, p_index + 1, last);
    }
}

int partition(std::vector<int>& numbers, int first, int last) {
    int pivot = numbers[first];
    int low = first + 1;
    int high = last;

    while (high > low) {
        while (high >= low && numbers[low] <= pivot) {
            low++;
        }
        while (high >= low && numbers[high] > pivot) {
            high--;
        }
        if (high > low) {
            swap(numbers[low], numbers[high]);
        }
    }
    
    while (high > first && numbers[high] >= pivot) {
        high--;
    }

    if (pivot > numbers[high]) {
        numbers[first] = numbers[high];
        numbers[high] = pivot;
        return high;
    } else {
        return first;
    }
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void printList(std::vector<int>& list) {
    for (int i: list) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}