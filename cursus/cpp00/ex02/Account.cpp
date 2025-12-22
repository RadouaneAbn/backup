#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp( void ) {
    time_t now = time(0);
    struct tm* local_time = localtime(&now);
    char buffer[80];

    strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", local_time);
    std::cout << "[" << buffer << "] ";
}

Account::Account( int initial_deposit ) {
    _accountIndex = Account::_nbAccounts++;
    _amount = initial_deposit;
    Account::_totalAmount += checkAmount();
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << checkAmount() << ";created" << std::endl;
}

Account::Account( void ) {
    _accountIndex = Account::_nbAccounts++;
    _amount = 0;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << checkAmount() << ";created" << std::endl;
}

Account::~Account( void ) {
    Account::_nbAccounts--;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << checkAmount() << ";closed" << std::endl;
}

int Account::getNbAccounts( void ) {
    return (Account::_nbAccounts);
}

int Account::getTotalAmount( void ) {
    return (Account::_totalAmount);
}

int Account::getNbDeposits( void ) {
    return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals( void ) {
    return (Account::_totalNbWithdrawals);
}

void Account::displayAccountsInfos( void ) {
    _displayTimestamp();
    std::cout << " accounts:" << Account::getNbAccounts()
        << ";total:" << Account::getTotalAmount()
        << ";deposits:" << Account::getNbDeposits()
        << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void Account::makeDeposit( int deposit ) {
    int oldAmount;
    if (deposit <= 0)
        return ;
    oldAmount = checkAmount();
    _amount += deposit;
    _nbDeposits++;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits++;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex
        << ";p_amount:" << oldAmount
        << ";deposit:" << deposit
        << ";amount:" << checkAmount()
        << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal( int withdrawal ) {
    int oldAmount;

    oldAmount = checkAmount();
    if (withdrawal <= 0 || withdrawal > oldAmount)
    {
        _displayTimestamp();
        std::cout << " index:" << _accountIndex
            << ";p_amount:" << oldAmount
            << ";withdrawal:" << "refused" << std::endl;
        return (false);
    }
    _amount -= withdrawal;
    _nbWithdrawals++;
    Account::_totalAmount -= withdrawal;
    Account::_totalNbWithdrawals++;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex
        << ";p_amount:" << oldAmount
        << ";withdrawal:" << withdrawal
        << ";amount:" << checkAmount()
        << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return (true);
}

int Account::checkAmount( void ) const {
    return (_amount);
}

void Account::displayStatus( void ) const {
    _displayTimestamp();
    std::cout << " index:" << _accountIndex
        << ";amount:" << checkAmount()
        << ";deposits:" << _nbDeposits
        << ";withdrawals:" << _nbWithdrawals << std::endl;
}