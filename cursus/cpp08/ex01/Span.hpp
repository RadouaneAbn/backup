#ifndef SPAN_HPP
#define SPAN_HPP

#include <set>
#include <vector>
#include <algorithm>
#include <limits>
#include <iostream>

class Span {
    private:
    unsigned int _n;
    std::vector<int> _numbers;
public:
    Span(void);
    Span(unsigned int n);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span(void);

    void addNumber(int number);
    void addNumbers(
        std::vector<int>::iterator begin,
        std::vector<int>::iterator end
    );
    int shortestSpan(void) const;
    int longestSpan(void) const;
    int getNumberOfElements(void) const;

    /* Tmp */
    std::vector<int>::iterator begin() { return _numbers.begin(); }
    std::vector<int>::iterator end() { return _numbers.end(); }
    int at(int index) const { return _numbers.at(index); }

    class SpanFullException : public std::exception {
        public:
        const char* what() const throw() {
            return "Span is full, cannot add more numbers.";
        }
    };

    class NotEnoughSpaceLeftInSpan : public std::exception {
        public:
        const char* what() const throw() {
            return "Not enough space left in Span to add the range of numbers.";
        }
    };

    class NoSpanFound : public std::exception {
        public:
        const char* what() const throw() {
            return "No span found (empty span)";
        }
    };
};

#endif