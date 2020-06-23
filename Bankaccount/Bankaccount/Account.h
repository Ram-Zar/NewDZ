#pragma once
#include "Money.h"
#include "Date.h"
#include "StrNumData.h"
#include <cstring>
#include <iostream>
#include "stdio.h"
#include "time.h"
#include <iomanip>

using namespace std;
class Account
{
private:
	string m_surname="";
	double m_per_cent=0;
	Money m_balance;
	int m_AcNum=-1;
	Date m_date;//current date
	static int s_AcNum;
	time_t reg_time=0;//time of registration

	long long ProcSec()
	{
		time_t t = time(NULL);
		return t-reg_time;
	}
public:
	Account()
	{
	}
	Account(string surname, double per_cent, long R, unsigned char K, string date)//ДОБАВЛЕНО
	{
		m_surname = surname;
		m_per_cent = per_cent;
		m_balance.SetSum(R, K);
		m_date(date.c_str());
		reg_time = time(NULL);	
		m_AcNum=++s_AcNum;
	}
	//void SetAccount
	void AccView();
	bool GetCash(int R, int K);
	bool PutCash(int R, int K)
	{
		Money temp(R, K);
		if (double(temp) > 0)
		{
			m_balance = m_balance+temp;
			cout << "\nВведенная сумма: " << R << "," << K << "\nБаланс: ";
			m_balance.print();
			return 0;
		}
		else
		{
			cout << "\nОтмена операции. Некорректная сумма";
			return 1;
		}
	}
	void DolConvert()
	{
		cout << "\nБаланс в долларах: ";
		Money(m_balance / 65.0).print();
	}
	void EuroConvert()
	{
		cout << "\nБаланс в евро: ";
		Money(m_balance / 70.0).print();
	}
	void RmOwner(string NOwner)
	{
		m_surname.clear();
		m_surname.append(NOwner);
		AccView();
	}
	void Per_cent_plus()
	{
		long long delta = ProcSec();
		m_per_cent += delta/20 * 0.01;
		unsigned char _value_ = unsigned char(m_balance.m_k * (1 + m_per_cent / 100.0));
		unsigned char K = _value_%100;
		long R = long(m_balance.m_main * (1 + m_per_cent/100.0))+_value_/100;
		m_balance.SetSum(R, K);
		if (delta/20>1)
		{
			cout << "\nАккаунт зарегистрирован "<<delta/20<< " месяца(цев) назад";
		}
	}
	void Print_Num()
	{
		string buff[15];
		StrNumData s;
		s.Print(buff, m_balance.m_main,m_balance.m_k);
	}
	friend class Money;
};
