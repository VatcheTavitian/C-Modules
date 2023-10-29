#include "Account.hpp"
#include <iostream>
#include <time.h>
#define  PINK "\x1b[95m\x1b[3m"
#define COLOR_RESET   "\x1b[0m"
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	this->_displayTimestamp();
	this->_accountIndex = this->_nbAccounts;
	std::cout << "index:" << PINK << this->_nbAccounts << COLOR_RESET << ";" ;
	std::cout << "amount:" << PINK << this->_amount << COLOR_RESET << ";" ;
	std::cout << "created"  << std::endl;
	this->_nbAccounts++;
	this->_totalAmount += _amount;
}

void	Account::_displayTimestamp( void ) {
	time_t raw_time = time(NULL);
	struct tm* timeinfo = localtime(&raw_time);
	char current[16];
	strftime(current, 15, "%Y%d%m_%H%M%S", timeinfo);
	std::cout << "[" <<   current << "] ";
}

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << "accounts:" << PINK << _nbAccounts << COLOR_RESET << ";" ;
	std::cout << "total:" << PINK << _totalAmount << COLOR_RESET << ";" ;
	std::cout << "deposits:" << PINK << _totalNbDeposits << COLOR_RESET << ";" ;
	std::cout << "withdrawals:" << PINK << _totalNbWithdrawals << COLOR_RESET << std::endl; ;
};

void	Account::displayStatus( void ) const {
	this->_displayTimestamp();
	std::cout << "index:" << PINK << this->_accountIndex << COLOR_RESET << ";" ;
	std::cout << "amount:" << PINK << this->_amount << COLOR_RESET << ";" ;
	std::cout << "deposits:" << PINK << this->_nbDeposits << COLOR_RESET << ";" ;
	std::cout << "withdrawals:" << PINK << this->_nbWithdrawals << COLOR_RESET << std::endl ;
}

void	Account::makeDeposit( int deposit ) {
	this->_nbDeposits++;
	this->_displayTimestamp();
	std::cout << "index:" << PINK << this->_accountIndex << COLOR_RESET << ";" ;
	std::cout << "p_amount:" << PINK << this->_amount << COLOR_RESET << ";" ;
	std::cout << "deposit:" << PINK << deposit << COLOR_RESET << ";" ;
	this->_amount += deposit;
	std::cout << "amount:" << PINK << this->_amount << COLOR_RESET << ";" ;
	std::cout << "nb_deposits:" << PINK << this->_nbDeposits << COLOR_RESET << std::endl;
	this->_totalAmount += deposit;
	this->_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal) {
	this->_displayTimestamp();
	if (withdrawal < this->_amount) {
		this->_nbWithdrawals++;
		std::cout << "index:" << PINK << this->_accountIndex << COLOR_RESET << ";" ;
		std::cout << "p_amount:" << PINK << this->_amount << COLOR_RESET << ";" ;
		std::cout << "withdrawal:" << PINK << withdrawal << COLOR_RESET << ";" ;
		this->_amount -= withdrawal;
		std::cout << "amount:" << PINK << this->_amount << COLOR_RESET << ";" ;
		std::cout << "nb_withdrawals:" << PINK << this->_nbWithdrawals << COLOR_RESET << std::endl;
		this->_totalAmount -= withdrawal;
		this->_totalNbWithdrawals++;
		return (true);
	}
	std::cout << "index:" << PINK << this->_accountIndex << COLOR_RESET << ";" ;
	std::cout << "p_amount:" << PINK << this->_amount << COLOR_RESET << ";" ;
	std::cout << "withdrawal:refused" << std::endl;
	return (false);
}


Account::~Account() {
	this->_displayTimestamp();
	std::cout << "index:" << PINK << this->_accountIndex << COLOR_RESET << ";" ;
	std::cout << "amount:" << PINK << this->_amount << COLOR_RESET << ";" ;
	std::cout << "closed"  << std::endl ;
};