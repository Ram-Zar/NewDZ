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
		static time_t prev_t = reg_time;
		time_t t = time(NULL);
		time_t delta = t - prev_t;
		prev_t = t;
		return delta;
	}
public:
	Account()
	{
	}
	void AccView();
	bool GetCash(int R, int K);
	friend istream& operator>>(istream& in, Account& a);
	bool PutCash(int R, int K)
	{
		Money temp(R, K);
		if (double(temp) > 0)
		{
			m_balance = m_balance+temp;
			cout << "\nВведенная сумма: " << R << "," << K << "\nБалансе: ";
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
		long long t = time(NULL);
		long long delta = ProcSec()/30;
		if (delta >= 2)
		{
			m_per_cent += delta * 0.01;
		    long R = long(m_balance.m_main * (1 + m_per_cent/100.0));
		    unsigned char K = unsigned char(m_balance.m_k * (1 + m_per_cent));
		    m_balance.SetAcc(R, K);
		}	
		if ((t-reg_time)/30 >= 5)
		{
			cout << "\nАккаунт зарегистрирован "<<t-reg_time<< " дней назад";
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
