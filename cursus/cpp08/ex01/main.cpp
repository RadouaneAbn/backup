#include "Span.hpp"
#include <iostream>
#include <ctime>

#define SIZE 500

int rnd(void);

int main()
{
    // {
    //     Span sp = Span(5);
    //     sp.addNumber(6);
    //     sp.addNumber(3);
    //     sp.addNumber(17);
    //     sp.addNumber(9);
    //     sp.addNumber(11);
    //     std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    //     std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    // }
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
        Span sp = Span(SIZE);
        sp.addNumbers(1, 100);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    {
        Span sp = Span(10);
        sp.addNumbers( 1, 100);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }

    return 0;
}
