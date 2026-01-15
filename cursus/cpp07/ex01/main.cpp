#include "iter.hpp"
#include <iostream>
#include <string>

template<typename T>
void prints(const T &value)
{
    std::cout << "v: " << value << std::endl;
}

// A function that takes a const reference, for printing
template<typename T>
void printElement(const T& element) {
    std::cout << element << " ";
}

// A function that takes a non-const reference, for modification
template<typename T>
void incrementElement(T& element) {
    element++;
}

int main() {
    // --- Test with an array of integers ---
    std::cout << "--- Testing with integers ---" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArrayLength = sizeof(intArray) / sizeof(int);

    std::cout << "Original integer array: ";
    iter(intArray, intArrayLength, printElement<int>);
    std::cout << std::endl;

    std::cout << "Incrementing integer array..." << std::endl;
    iter(intArray, intArrayLength, incrementElement<int>);

    std::cout << "Modified integer array: ";
    iter(intArray, intArrayLength, printElement<int>);
    std::cout << std::endl << std::endl;


    // --- Test with an array of strings ---
    std::cout << "--- Testing with strings ---" << std::endl;
    std::string stringArray[] = {"one", "two", "three"};
    size_t stringArrayLength = sizeof(stringArray) / sizeof(std::string);

    std::cout << "Original string array: ";
    iter(stringArray, stringArrayLength, printElement<std::string>);
    std::cout << std::endl;

    // --- Test with an array of floats ---
    std::cout << "--- Testing with floats ---" << std::endl;
    float floatArray[] = {1.1f, 2.2f, 3.3f};
    size_t floatArrayLength = sizeof(floatArray) / sizeof(float);

    std::cout << "Original float array: ";
    iter(floatArray, floatArrayLength, printElement<float>);
    std::cout << std::endl;

    std::cout << "Incrementing float array..." << std::endl;
    iter(floatArray, floatArrayLength, incrementElement<float>);

    std::cout << "Modified float array: ";
    iter(floatArray, floatArrayLength, printElement<float>);
    std::cout << std::endl;

    return 0;
}