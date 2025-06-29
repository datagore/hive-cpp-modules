#include <chrono>
#include <iomanip>
#include <iostream>

#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int Account::getTotalAmount(void)
{
	return _totalAmount;
}

int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << "\n";
}

Account::Account(int initialDeposit)
	: _accountIndex(_nbAccounts++),
	  _amount(initialDeposit),
	  _nbDeposits(0),
	  _nbWithdrawals(0)
{
	_displayTimestamp();
	_totalAmount += initialDeposit;
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << initialDeposit << ";";
	std::cout << "created\n";
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed\n";
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << (_amount += deposit) << ";";
	std::cout << "nb_deposits:" << ++_nbDeposits << "\n";
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	if (withdrawal <= _amount) {
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout << "withdrawal:" << withdrawal << ";";
		std::cout << "amount:" << _amount << ";";
		std::cout << "nb_withdrawals:" << _nbWithdrawals << "\n";
		return true;
	}
	std::cout << "withdrawal:refused\n";
	return false;
}

int Account::checkAmount(void) const
{
	return _amount;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << "\n";
}

void Account::_displayTimestamp(void)
{
	auto now = std::chrono::system_clock::now();
	time_t time = std::chrono::system_clock::to_time_t(now);
	std::cout << std::put_time(localtime(&time), "[%Y%m%d_%H%M%S] ");
}

Account::Account(void)
	: _accountIndex(_nbAccounts++),
	  _amount(0),
	  _nbDeposits(0),
	  _nbWithdrawals(0)
{
}
