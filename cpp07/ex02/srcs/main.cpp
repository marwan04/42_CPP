#include "Array.hpp"

int main() {
    try {
        Array<int> arr1(5);
        for (unsigned int i = 0; i < arr1.size(); i++) {
            arr1[i] = i * 10;
        }

        std::cout << "arr1: ";
        for (unsigned int i = 0; i < arr1.size(); i++) {
            std::cout << arr1[i] << " ";
        }
        std::cout << std::endl;

        Array<int> arr2 = arr1;
        arr2[0] = 999;
        std::cout << "arr1 after arr2 modification: " << arr1[0] << std::endl;
        std::cout << "arr2: " << arr2[0] << std::endl;

        const Array<int> arr3 = arr1;
        std::cout << "arr3[1] = " << arr3[1] << std::endl;

        std::cout << arr1[10] << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
