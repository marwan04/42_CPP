#include "iter.hpp"

template <typename T>
void printElement(T const &x) {
    std::cout << x << " ";
}

void increment(int &x) {
    x++;
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    std::string strArr[3] = {"Hello", "World", "C++"};

    std::cout << "Original int array: ";
    iter(arr, 5, printElement<int>);
    std::cout << std::endl;

    iter(arr, 5, increment);

    std::cout << "After increment: ";
    iter(arr, 5, printElement<int>);
    std::cout << std::endl;

    std::cout << "String array: ";
    iter(strArr, 3, printElement<std::string>);
    std::cout << std::endl;

    return 0;
}
