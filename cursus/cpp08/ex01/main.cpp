#include "Span.hpp"
#include <iostream>
#include <ctime>

#define SIZE 500

int rnd(void)
{
    return std::rand();
}

int main()
{
    {
        std::cout << "Test subject test:" << std::endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    // {

    //     Span sp = Span(SIZE);
    //     while (sp.getNumberOfElements() < SIZE)
    //     {
    //         try {
    //             sp.addNumber(rnd());
    //         } catch (const std::exception& e) {
    //             std::cerr << e.what() << std::endl;
    //         }
    //     }

    //     std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    //     std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    // }

    {
        std::cout << "\nTest with range addition:" << std::endl;
        std::vector<int> arr(SIZE);
        std::generate(arr.begin(), arr.end(), rnd);
        Span sp = Span(SIZE);
        sp.addNumbers(arr.begin(), arr.end());
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    {
        std::cout << "\nTest throw with range addition:" << std::endl;
        unsigned int arr_size = 100;
        std::vector<int> arr(arr_size);
        std::generate(arr.begin(), arr.end(), rnd);
        Span sp = Span(arr_size / 2);
        try {
            sp.addNumbers(arr.begin(), arr.end());
        } catch (const Span::NotEnoughSpaceLeftInSpan& e) {
            std::cerr << e.what() << std::endl;
        }
    }

    return 0;
}
