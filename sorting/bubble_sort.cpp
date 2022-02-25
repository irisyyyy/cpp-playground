#include <iostream>
#include <vector>

void bubbleSort(std::vector<int>& nums);
void printList(std::vector<int>& list);
void swap(int& a, int& b);

int main() {
    std::vector<int> numbers{ 65, 41, 9, 28, 55, 12, 11, 30, 79, 56, 17};
    
    std::cout << "Before sorting:\n";
    printList(numbers);

    bubbleSort(numbers);

    std::cout << "After sorting:\n";
    printList(numbers);
}

//the largest number will be swap to the right most position, therfore we can do less in the inner loop

void bubbleSort(std::vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (nums[j] > nums[j + 1]) 
                swap(nums[j], nums[j + 1]);
        }
    }
}

void printList(std::vector<int>& list) {
    for (int i: list) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}


void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}