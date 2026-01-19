#include "Span.hpp"

Span::Span(void) : _n(0) {}

Span::Span(unsigned int n) : _n(n) {}

Span::Span(const Span& other) : _n(other._n), _numbers(other._numbers) {}

Span::~Span(void) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _n = other._n;
        _numbers = other._numbers;
    }
    return *this;
}

void Span::addNumber(int number) {
    if (_numbers.size() >= _n) {
        throw SpanFullException();
    }
    _numbers.push_back(number);
}

void Span::addNumbers(
    std::vector<int>::iterator begin,
    std::vector<int>::iterator end
)
{
    if (std::distance(begin, end) + _numbers.size() > _n) {
        throw NotEnoughSpaceLeftInSpan();
    }

    _numbers.insert(_numbers.end(), begin, end);
}

int Span::getNumberOfElements(void) const
{
    return _numbers.size();
}

int Span::shortestSpan(void) const
{
    int shortest_span = std::numeric_limits<int>::max();

    if (getNumberOfElements() < 2)
        throw NoSpanFound();

    std::vector<int> tmp = _numbers;
    std::sort(tmp.begin(), tmp.end());
    
    size_t number_of_elements = tmp.size();
    for (size_t i = 0; i < number_of_elements - 1; i++)
    {
        int span = std::abs(tmp[i] - tmp[i + 1]);
        if (span < shortest_span)
            shortest_span = span;
    }
    return shortest_span;
}

int Span::longestSpan(void) const
{
    if (getNumberOfElements() < 2)
        throw NoSpanFound();

    std::vector<int> tmp = _numbers;
    std::sort(tmp.begin(), tmp.end());
    
    return std::abs(tmp.front() - tmp.back());
}