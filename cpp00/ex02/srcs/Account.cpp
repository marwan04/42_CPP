#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
    _accountIndex = _nbAccounts++;
    _totalAmount += _amount;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created\n";
}

Account::~Account() {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed\n";
}

void Account::makeDeposit(int deposit) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;
    std::cout << ";deposit:" << deposit << ";amount:" << _amount
              << ";nb_deposits:" << _nbDeposits << "\n";
}

bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
    if (_amount >= withdrawal) {
        _amount -= withdrawal;
        _nbWithdrawals++;
        _totalAmount -= withdrawal;
        _totalNbWithdrawals++;
        std::cout << ";withdrawal:" << withdrawal << ";amount:" << _amount
                  << ";nb_withdrawals:" << _nbWithdrawals << "\n";
        return true;
    } else {
        std::cout << ";withdrawal:refused\n";
        return false;
    }
}

int Account::checkAmount() const {
    return _amount;
}

void Account::displayStatus() const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount
              << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals << "\n";
}

void Account::displayAccountsInfos() {
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount
              << ";deposits:" << _totalNbDeposits
              << ";withdrawals:" << _totalNbWithdrawals << "\n";
}

void Account::_displayTimestamp() {
    std::time_t now = std::time(0);
    std::tm *ltm = std::localtime(&now);
    std::cout << "[" << 1900 + ltm->tm_year
              << std::setw(2) << std::setfill('0') << ltm->tm_mon + 1
              << std::setw(2) << std::setfill('0') << ltm->tm_mday << "_"
              << std::setw(2) << std::setfill('0') << ltm->tm_hour
              << std::setw(2) << std::setfill('0') << ltm->tm_min
              << std::setw(2) << std::setfill('0') << ltm->tm_sec << "] ";
}
