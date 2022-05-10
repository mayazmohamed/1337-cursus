/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 20:51:45 by momayaz           #+#    #+#             */
/*   Updated: 2022/04/28 23:36:54 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::	_nbAccounts = 0;
int Account::	_totalAmount = 0;
int Account::	_totalNbDeposits = 0;
int Account::	_totalNbWithdrawals = 0;

Account:: Account(int initial_deposit){
	_displayTimestamp();
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	std::cout << "index: "<<_accountIndex << ";";
	std::cout << "amount:" << _amount << ";" << "created" << std::endl;
}

Account:: ~Account(){
	_nbAccounts--;
	_displayTimestamp();
	std::cout << "index: "<<_accountIndex << ";";
	std::cout << "amount:" << _amount << ";" << "closed" << std::endl;
}

void Account::_displayTimestamp(){
	time_t curr_time;
	tm * curr_tm;
	char date_string[100];
	char time_string[100];

	time(&curr_time);
	curr_tm = localtime(&curr_time);

	strftime(date_string, 50, "[%Y%m%d_", curr_tm);
	strftime(time_string, 50, "%H%M%S] ", curr_tm);
	std::cout << date_string << time_string;
}

int Account:: getNbAccounts( void ){
	return (_nbAccounts);
}

int Account:: getTotalAmount( void ){
	return (_totalAmount);
}

int Account:: getNbDeposits( void ){
	return (_totalNbDeposits);
}

int Account:: getNbWithdrawals( void ){
	return (_totalNbWithdrawals);
}

void Account::	displayStatus( void ) const{
	_displayTimestamp();
	std::cout << "index: "<<_accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits: " << _nbDeposits << ";";
	std::cout << "withdrawals: " << _nbWithdrawals;
	std::cout << std::endl;
}

void Account::	makeDeposit( int deposit ){
	_displayTimestamp();
	std::cout << "index: "<<_accountIndex << ";" << "p_amount: " << _amount << ";" << "deposit: " << deposit << ";";
	this->_totalAmount += deposit;
	this->_totalNbDeposits++;
	_nbDeposits++;
	_amount += deposit;
	std::cout << "amount: " << _amount << ";" << "nb_deposits: " << _nbDeposits << std::endl;
}

bool Account::	makeWithdrawal( int withdrawal ){
	if (withdrawal <= _amount){
		_displayTimestamp();
		std::cout << "index: "<<_accountIndex << ";" << "p_amount: " << _amount << ";" << "withdrawal: " << withdrawal << ";";
		this->_totalNbWithdrawals++;
		_amount -= withdrawal;
		_nbWithdrawals++;
		std::cout << "amount: " << _amount << ";" << "nb_withdrawals: " << _nbWithdrawals << std::endl;
		return(1);
	}
	else{
		_displayTimestamp();
		std::cout << "index: "<<_accountIndex << "p_amount: " << _amount << ";" << "withdrawal:refused" << std::endl;
		return (0);
	}
}

int Account::	checkAmount( void ) const{
	return(_amount);
}

void Account::	displayAccountsInfos( void ){
	_displayTimestamp();
	std::cout << "accounts: "<<_nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits: " << _totalNbDeposits << ";";
	std::cout << "withdrawals: " << _totalNbWithdrawals;
	std::cout << std::endl;
}