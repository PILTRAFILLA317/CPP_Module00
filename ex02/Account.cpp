#include <vector>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <functional>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(void)
{
	return ;
}

Account::~Account()
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << "\n";
}

Account::Account(int initial_deposit)
{
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;
	Account::_totalAmount += _amount;
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";" << "created" << "\n";
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals() << "\n";
}

int	Account::getNbAccounts( void ){
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void ){
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void ){
	return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals( void ){
	return (Account::_totalNbWithdrawals);
}

void	Account::_displayTimestamp( void )
{
	std::time_t t_rn = std::time(nullptr);
	char buffer[80];
	std::strftime(buffer, 80, "[%Y%m%d_%H%M%S] ", std::localtime(&t_rn));
	std::cout << buffer;
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << "\n";
}

void	Account::makeDeposit( int deposit )
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "deposit:" << deposit << ";";
	_amount = _amount + deposit;
	_totalAmount += deposit;
	_nbDeposits ++;
	_totalNbDeposits ++;
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits << ";" << "\n";
}

bool	Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "withdrawal:" << withdrawal << ";";
	if (_amount < withdrawal){
		std::cout << "refused" << "\n";
		return (1);
	}
	_amount = _amount - withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals ++;
	_totalNbWithdrawals ++;
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_withdrawals:" << _nbWithdrawals << ";" << "\n";
	return (0);
}