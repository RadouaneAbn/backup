#include "BitcoinExchange.hpp"

time_t get_time_stamp(std::string &date);
std::string timestamp_to_date(time_t timestamp);
void print_date_exchange(time_t ts, double rate);

int main(int ac, char *av[])
{
    BitCoinExchange btx;

    if (ac != 2)
        return (1);

    btx.eval(std::string(av[1]));
}