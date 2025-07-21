#include "Account.hpp"
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void) { return _nbAccounts; }
int	Account::getTotalAmount(void) { return _totalAmount; }
int	Account::getNbDeposits(void) { return _totalNbDeposits; }
int	Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }

void	Account::displayAccountsInfos(void) {
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::Account(void) : _accountIndex(0), _amount(0), _nbDeposits(0), _nbWithdrawals(0) {
    _nbAccounts++;
}

Account::Account(int initial_deposit) : _amount(initial_deposit) {
    _accountIndex = _nbAccounts++;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
}

Account::~Account(void) {
    _nbAccounts--;
}

void	Account::makeDeposit(int deposit) {
    _amount += deposit;
    _nbDeposits++;
    _totalNbDeposits++; 
    _totalAmount += deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount - deposit << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal) {
    if (withdrawal > checkAmount()) {
        _displayTimestamp();
        std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused" << std::endl;
        return false;
    }
    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    _totalAmount -= withdrawal;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true;
}

int	Account::checkAmount(void) const {
    return _amount;
}

void	Account::displayStatus(void) const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp(void) {
    std::cout << "[" << std::time(NULL) << "] ";
}
