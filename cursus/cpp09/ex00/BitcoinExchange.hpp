#ifndef BIT_H
#define BIT_H

#include <iostream>
#include <exception>
#include <fstream>
#include <map>
#include <ctime>
#include <sstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cmath>

struct pair
{
    std::size_t date;
    double exchange_rate;
};


class BitCoinExchange
{
private:
    std::map<time_t, double> _db;
public:
    BitCoinExchange(void);
    ~BitCoinExchange(void);

    void load_exchange_rates(void);
    double get_exchangerate(time_t ts);
    void eval(std::string db2_path);

    void print_db(void);

    class ExchangeDatabaseOpenError: public std::exception
    {
        public:
        virtual const char *what(void) throw()
        {
            return "Can't open data.csv";
        }
    };

    class EvalDatabaseOpenError: public std::exception
    {
        std::string _message;
        public:
        EvalDatabaseOpenError(std::string &path)
            : _message("Can't open: " + path) {}
        virtual ~EvalDatabaseOpenError() throw() {}
        virtual const char *what(void) const throw()
        {
            return _message.c_str();
        }
    };

    class BadInput : public std::exception
    {
        std::string _message;
        public:
        BadInput(std::string &msg)
            : _message("Bad input => " + msg) {}
        virtual ~BadInput() throw() {}
        virtual const char *what(void) const throw()
        {
            return _message.c_str();
        }
    };

    class TooLargeNumber : public std::exception
    {
        public:
        virtual const char *what(void) const throw()
        {
            return "too large number";
        }
    };

    class NotPositiveNumber : public std::exception
    {
        public:
        virtual const char *what(void) const throw()
        {
            return "not a positive number";
        }
    };

    class InvalidDate : public std::exception
    {
        public:
        virtual const char *what(void) const throw()
        {
            return "invalid date";
        }
    };
};

#endif