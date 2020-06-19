#pragma once
#include <iostream>
using namespace std;
class Money
{

	long m_main = 0;//Rubles
	unsigned char m_k = 0;//kopeyki
	//amount of bank_notes
	unsigned char C5000 = 0;
	unsigned char C1000 = 0;
	unsigned char C500 = 0;
	unsigned char C100 = 0;
	unsigned char C50 = 0;
	unsigned char C10 = 0;
	unsigned char C5 = 0;
	unsigned char C2 = 0;
	unsigned char C1 = 0;
	unsigned char C001 = 0;
	unsigned char C005 = 0;
	unsigned char C01 = 0;
	unsigned char C05 = 0;

	void distributor();//calculates an anmount of bank_notes
	
public:
	Money() {};
	Money(long R, int k)
	{
		m_main = R;
		m_k = (unsigned char)k;
		distributor();
	}
	void print()
	{
		cout <<m_main << "," << (int)m_k;
	}
	
	int SetAcc(long R, int K)
	{
		if ((K < 0) || (R < 0))
		{
			return 1;
		}
		if (K >= 100)
		{
			m_k = K%100;
			m_main = R+K/100;
		}
		else
		{
			m_k = K;
			m_main = R;
		}	
		distributor();
		return 0;
	}
	friend Money operator+(const Money& m, const Money& n)
	{
		unsigned char K = m.m_k + n.m_k;
		long R = m.m_main + n.m_main + K / 100;
		K = K % 100;
		return Money(R, K);
	}
	friend Money operator-(const Money& m, const Money& n)
	{
		int total = (m.m_main * 100 + m.m_k) - (n.m_main * 100 + n.m_k);
		long R = total / 100;
		unsigned char K = total % 100;
		return Money(R, K);
	}
	friend Money operator/(const Money& m, const Money& n)
	{
		double total = ((double)m.m_main * 100 + m.m_k) / ((double)n.m_main * 100 + n.m_k);
		long R = int(total);
		unsigned char K = (int)(total * 100.0) % 100;
		return Money(R, K);
	}
	Money operator/(double n)
	{
		double total = ((double)m_main * 100 + m_k) / (n * 100);
		long R = int(total);
		unsigned char K = (int)(total * 100.0) % 100;
		return Money(R, K);
	}
	friend Money operator*(const Money& m, double n)
	{
		double total = ((double)m.m_main * 100 + m.m_k) * n / 100;
		long R = int(total);
		unsigned char K = (int)(total * 100) % 100;
		return Money(R, K);
	}
	friend Money operator*(double n, const Money& m)
	{
		double total = ((double)m.m_main * 100 + m.m_k) * n / 100;
		long R = int(total);
		unsigned char K = (int)(total * 100) % 100;
		return Money(R, K);
	}
	bool operator>(const Money& m)
	{
		return (m_main * 100 + m_k > m.m_main * 100 + m.m_k);
	}
	bool operator<(const Money& m)
	{
		return (m_main * 100 + m_k < m.m_main * 100 + m.m_k);
	}
	bool operator>=(const Money& m)
	{
		return (m_main * 100 + m_k >= m.m_main * 100 + m.m_k);
	}
	bool operator<=(const Money& m)
	{
		return (m_main * 100 + m_k <= m.m_main * 100 + m.m_k);
	}
	bool operator!=(const Money& m)
	{
		return (m_main * 100 + m_k != m.m_main * 100 + m.m_k);
	}
	bool operator==(const Money& m)
	{
		return (m_main * 100 + m_k == m.m_main * 100 + m.m_k);
	}
	operator double()
	{
		return (double(m_main) * 100.0 + double(m_k)) / 100.0;
	}
	bool operator==(double n)
	{
		return (double(*this) == n);
	}
	bool operator==(int n)
	{
		return (double(*this) == n);
	}
	friend class Account;
};
