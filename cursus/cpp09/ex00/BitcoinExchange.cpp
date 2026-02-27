#include "BitcoinExchange.hpp"

/**
 * INFO: Helper functions
 */

bool date_isvalid(std::string &date)
{
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (date.length() != 10)
        return (false);
    if (date[4] != '-' || date[7] != '-')
        return (false);

    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (!isdigit(date[i]))
            return (false);
    }

    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());
    
    if (month < 1 || month > 12)
        return (false);
    if (day < 1 || day > 31)
        return (false);
    if (day > days_in_month[month - 1])
        return (false);

    /* validate day respecting leap year */
    if (month == 2)
    {
        bool is_leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (is_leap)
            days_in_month[1] = 29;
    }
    if (day > days_in_month[month - 1])
        return (false);
    return (true);
}

bool value_isvalid(std::string &value_str)
{
    char* endptr;
    double value = std::strtod(value_str.c_str(), &endptr);

    if (endptr == value_str.c_str() || *endptr != '\0')
        return (false);

    if (std::isnan(value) || std::isinf(value))
        return (false);

    return (true);
}

time_t get_time_stamp(std::string &date)
{
    std::tm timestamp;
    std::istringstream date_s(date);
    size_t location1, location2;

    location1 = date.find('-');
    location2 = date.find('-', location1 + 1);

    timestamp.tm_year = atoi(date.substr(0, 4).c_str()) - 1900;
    timestamp.tm_mon = atoi(date.substr(location1 + 1, 2).c_str()) - 1;
    timestamp.tm_mday = atoi(date.substr(location2 + 1, 2).c_str());
    timestamp.tm_hour = 0;
    timestamp.tm_min = 0;
    timestamp.tm_sec = 0;
    timestamp.tm_isdst = 0;

    return (std::mktime(&timestamp));
}

bool input_isvalid(std::string &in, std::string &sep)
{
    if (in.find(sep) == std::string::npos)
        return (false);
    return (true);
}

void validate_input(std::string &in, std::string sep)
{
    if (!input_isvalid(in, sep))
        throw BitCoinExchange::BadInput(in);

    size_t pos = in.find(sep);
    std::string date_str = in.substr(0, pos);
    std::string value_str = in.substr(pos + sep.length());

    if (!date_isvalid(date_str))
        throw BitCoinExchange::InvalidDate();

    if (!value_isvalid(value_str))
        throw BitCoinExchange::BadInput(in);

    double value = std::strtod(value_str.c_str(), NULL);
    if (value < 0)
        throw BitCoinExchange::NotPositiveNumber();
    if (value > 1000)
        throw BitCoinExchange::TooLargeNumber();
}

/**
 * INFO: BitCoinExchange class implementation
 */

BitCoinExchange::BitCoinExchange(void)
{
    load_exchange_rates();
}

BitCoinExchange::~BitCoinExchange(void) {}

std::string timestamp_to_date(time_t timestamp)
{
    std::tm* timeinfo = std::localtime(&timestamp);
    
    std::ostringstream oss;
    oss << (timeinfo->tm_year + 1900) << '-'
        << std::setfill('0') << std::setw(2) << (timeinfo->tm_mon + 1) << '-'
        << std::setfill('0') << std::setw(2) << timeinfo->tm_mday;
    
    return oss.str();
}

void BitCoinExchange::load_exchange_rates(void)
{
    std::ifstream database("data.csv");
    time_t ts;
    double d;

    if (!database.is_open())
        throw ExchangeDatabaseOpenError();
    
    std::string s;
    std::getline(database, s);
    while (std::getline(database, s))
    {
        ts = get_time_stamp(s);
        d = std::strtod(s.substr(s.find(',') + 1).c_str(), NULL);
        _db[ts] = d;
    }
    database.close();
}

void print_date_exchange(time_t ts, double rate)
{
    std::cout << std::fixed << std::setprecision(2) << timestamp_to_date(ts) << ": " << rate << std::endl;
}

void BitCoinExchange::print_db(void)
{
    for (std::map<time_t, double>::iterator current = _db.begin(); current != _db.end(); current++)
    {
        print_date_exchange(current->first, current->second);
    }
}

double BitCoinExchange::get_exchangerate(time_t ts)
{
    std::map<time_t, double>::iterator it = _db.lower_bound(ts);

    if (ts != it->first)
        it--;

    return (it->second);
}

void BitCoinExchange::eval(std::string db2_path)
{
    std::ifstream input_file(db2_path.c_str());

    if (!input_file.is_open())
        throw EvalDatabaseOpenError(db2_path);

    std::string s;
    std::getline(input_file, s);
    while (std::getline(input_file, s))
    {
        int pos = s.find(" | ");
        try
        {
            validate_input(s, std::string(" | "));
        }
        catch (const std::exception &e)
        {
            std::cout << "Error: " << e.what() << std::endl;
            continue;
        }
        time_t date = get_time_stamp(s);
        double value = std::strtod(s.substr(pos + 3).c_str(), NULL);
        std::cout << timestamp_to_date(date) << " => "
            << value << " = " << value * get_exchangerate(date)
            << std::endl;
    }
    input_file.close();
}


