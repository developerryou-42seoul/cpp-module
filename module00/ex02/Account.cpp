#include "Account.hpp"
#include <iostream>
#include <time.h>

// static
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// private
Account::Account(void)
{ 
	this->_accountIndex = 0;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
}

void	Account::_displayTimestamp(void)
{
    time_t nowTime = time(NULL);
    struct tm *local = localtime(&nowTime);
    std::cout<<'['
	<<local->tm_year + 1900 
	<<local->tm_mon
	<<local->tm_mday
	<<"_"
    <<local->tm_hour
	<<local->tm_min
	<<local->tm_sec
	<<"] ";
}

// public
Account::Account(int initial_deposit)
{
	this->_accountIndex = 0;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	// this
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	// static
	_nbAccounts++;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout<<"index:"<<this->_accountIndex<<";";
	std::cout<<"amount:"<<this->_amount<<";";
	std::cout<<"created"<<std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout<<"index:"<<this->_accountIndex<<";";
	std::cout<<"amount:"<<this->_amount<<";";
	std::cout<<"closed"<<std::endl;
}

int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}
int Account::getTotalAmount(void)
{
	return (_totalAmount);
}
int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}
int Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout<<"accounts:"<<_nbAccounts<<";";
	std::cout<<"total:"<<_totalAmount<<";";
	std::cout<<"deposits:"<<_totalNbDeposits<<";";
	std::cout<<"withdrawals:"<<_totalNbWithdrawals<<std::endl;
}
void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout<<"index:"<<this->_accountIndex<<";";
	std::cout<<"p_amount:"<<this->_amount<<";";
	std::cout<<"deposit:"<<deposit<<";";
	this->_amount += deposit;
	_totalAmount += deposit;
	std::cout<<"amount:"<<this->_amount<<";";
	this->_nbDeposits++;
	_totalNbDeposits++;
	std::cout<<"nb_deposits:"<<this->_nbDeposits<<std::endl;
}
bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout<<"index:"<<this->_accountIndex<<";";
	std::cout<<"p_amount:"<<this->_amount<<";";
	if (withdrawal > this->_amount)
	{
		std::cout<<"withdrawal:refused"<<std::endl;
		return (false);
	}
	else
	{
		std::cout<<"withdrawal:"<<withdrawal<<";";
		this->_amount -= withdrawal;
		_totalAmount -= withdrawal;
		std::cout<<"amount:"<<this->_amount<<";";
		this->_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout<<"nb_withdrawals:"<<this->_nbWithdrawals<<std::endl;
		return (true);
	}
}
int Account::checkAmount(void) const
{
	return (this->_amount);
}
void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout<<"index:"<<this->_accountIndex<<";";
	std::cout<<"amount:"<<this->_amount<<";";
	std::cout<<"deposits:"<<this->_nbDeposits<<";";
	std::cout<<"withdrawals:"<<this->_nbWithdrawals<<std::endl;
}
