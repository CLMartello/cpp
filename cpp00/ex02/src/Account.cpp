
#include "../include/Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

//constructor
Account::Account( int initial_deposit ) {
    _accountIndex = _nbAccounts;
    _amount = initial_deposit;

    _nbAccounts++;
    _totalAmount += initial_deposit;

    _nbDeposits = 0;
	_nbWithdrawals = 0;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";created" << std::endl;
}


Account::~Account( void ) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";closed" << std::endl;  
} //destructor
// You must:
// print closing info


int	Account::getNbAccounts( void ) {
    return (_nbAccounts);    
}

int	Account::getTotalAmount( void ) {
    return (_totalAmount);
}

int	Account::getNbDeposits( void ) {
    return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ) {
    return (_totalNbWithdrawals);
}

void	Account::_displayTimestamp( void ) {
    std::time_t rawtime = std::time(0); //get all time in seconds
    std::tm* time = std::localtime(&rawtime);

    std::cout << "[" << std::setfill('0')
              << std::setw(4) << (time->tm_year + 1900)
              //tm_year contains years since 1900, so have to add
              << std::setw(2) << (time->tm_mon + 1)
              //months are range 0 to 11, so have to add +1
              << std::setw(2) << time->tm_mday << "_"
              << std::setw(2) << time->tm_hour
              << std::setw(2) << time->tm_min
              << std::setw(2) << time->tm_sec << "] ";
}
//[YYYYMMDD_HHMMSS]

void	Account::displayAccountsInfos( void ) {
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts
              << ";total:" << _totalAmount
              << ";deposits:" << _totalNbDeposits
              << ";withdrawals:" << _totalNbWithdrawals << std::endl;    
}
// Shows:
// total accounts
// total money
// total deposits
// total withdrawals



void	Account::makeDeposit( int deposit ) {
    _amount += deposit;
    _nbDeposits++;

    _totalAmount += deposit;
    _totalNbDeposits++;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";p_amount:" << (_amount - deposit)
              << ";deposit:" << deposit
              << ";amount:" << _amount
              << ";nb_deposits:" << _nbDeposits << std::endl;
}
// You must:
// update account amount
// increment deposit count
// update global stats
// print log

bool	Account::makeWithdrawal( int withdrawal ) {
    _displayTimestamp();
    if (_amount < withdrawal) {
        std::cout << "index:" << _accountIndex
                  << ";p_amount:" << _amount
                  << ";withdrawal:refused" << std::endl;
        return (false);
    }
    else {
        _amount -= withdrawal;
        _nbWithdrawals++;

        _totalAmount -= withdrawal;
        _totalNbWithdrawals++;

        std::cout << "index:" << _accountIndex
                  << ";p_amount:" << (_amount + withdrawal)
                  << ";withdrawal:" << withdrawal
                  << ";amount:" << _amount
                  << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    }
    return (true);
}
// You must:
// check if possible
// if not → print refused
// if yes → update everything

int		Account::checkAmount( void ) const {
    return (_amount);
}

void	Account::displayStatus( void ) const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals << std::endl;   
}
// Shows:
// index
// amount
// deposits
// withdrawals


