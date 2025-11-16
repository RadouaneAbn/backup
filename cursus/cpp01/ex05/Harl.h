#pragma once

#include "Harl.hpp"

#define DEBUG_MSG "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!";
#define INFO_MSG "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!";
#define WARNING_MSG "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.";
#define ERROR_MSG "This is unacceptable! I want to speak to the manager now."

#define DDEBUG_MSG "DEBUG MSG"
#define DINFO_MSG "INFO MSG"
#define DWARNING_MSG "WARNING MSG"
#define DERROR_MSG "ERROR MSG"

typedef void (Harl::*t_func)(void);

typedef struct s_pair {
    std::string level;
    t_func function;
} t_pair;

