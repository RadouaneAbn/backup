#include "RPN.hpp"

#include <iostream>
#include <stack>

typedef int (* t_func)(int, int); 

int add_f(int a, int b)
{
    return (a + b);
}

int sub_f(int a, int b)
{
    return (a - b);
}

int mul_f(int a, int b)
{
    return (a * b);
}

int div_f(int a, int b)
{
    return (a / b);
}

int get_op(char c)
{
    switch (c)
    {
    case '+':
        return (0);
    case '-':
        return (1);
    case '*':
        return (2);
    case '/':
        return (3);
    }
    return (-1);
}

int get_last_element(std::stack<int> &st)
{
    if (st.size() == 0)
        throw WrongInput();
    int n = st.top();
    st.pop();
    return (n);
}

int do_math(char *s)
{
    std::stack<int> st;
    int op, a, b, result;
    t_func functions[4] = {add_f, sub_f, mul_f, div_f}; 

    for (int i = 0; s[i]; i++)
    {
        while (s[i] == ' ')
            i++;
        if (std::isdigit(s[i]))
            st.push(s[i] - '0');
        else
        {
            op = get_op(s[i]);
            b = get_last_element(st);
            a = get_last_element(st);
            result = functions[op](a, b);
            st.push(result);
        }
    }

    if (st.size() != 1)
        throw WrongInput();
    return (st.top());
}