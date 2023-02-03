#include	"Account.hpp"
#include	<iostream>

Account::Account(int initial_deposit)
{
	makeDeposit(initial_deposit);
}

Account::~Account(void)
{
	;
}

int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void	Account::_displayTimestamp(void)
{
	;
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << " accounts:" << Account::getNbAccounts();
	std::cout << ";total:" << Account::getTotalAmount();
	std::cout << ";deposits:" << Account::getNbDeposits();
	std::cout << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

//void	makeDeposit(int deposit)
//{
//	this->_amount += deposit;
//}

//void	makeWithdrawal(int withdrawal)
//{
//	this->_amount -= withdrawal;
//}
