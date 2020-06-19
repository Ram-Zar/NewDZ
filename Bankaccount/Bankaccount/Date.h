#pragma once
#include <iostream>
#include "string.h"
using namespace std;
class Date
{
	unsigned int m_year=0;
	unsigned int m_month=0;
	unsigned int m_day=0;
	const static int s_v_year = 2020;//for finding a leap-year
	int month_info(int mv = 0);//calculates amount of days in given month
public:
	Date(){}
	Date(int y, int m, int d)
	{
		m_year = y;
		m_month = m;
		m_day = d;
	}
	Date(char* D)
	{
		this->operator()(D);
	}
	Date(const Date& D)
	{
		m_year = D.m_year;
		m_month = D.m_month;
		m_day = D.m_day;
	}
	bool operator()(const char* D)
	{
		m_year = atoi(D);
		m_month = atoi(D + 5);
		m_day = atoi(D + 8);
		if ((m_day >0)&&(m_day<=31)&& (m_month > 0)&&(m_month<=12))
		{
			return 1;
		}
		else
		{
			char temp[15];
			cout << "\nНекорректная дата. Повторите ввод: ";
			cin >> temp;
			while (!this->operator()(temp))
			{
				cout << "\nНекорректная дата. Повторите ввод: ";
				cin >> temp;
			}
			return 1;
		}
	}
	bool operator()(int y, int m, int d)
	{
		m_year = y;
		m_month = m;
		m_day = d;
		if ((y < 0) || (m < 1) || (m > 12) || (d < 1) || (d > 31))
		{
			return 0;
		}
		return 1;
	}
	bool operator()(Date&& D)
	{
		m_year = D.m_year;
		m_month =D.m_month;
		m_day = D.m_day;
		return 1;
	}
	void printDate()
	{
		cout << "\"" << m_year << ".";
		if (m_month < 10)
		{
			cout << "0" << m_month << ".";
		}
		else
		{
			cout << m_month << ".";
		}
		if (m_day < 10)
		{
			cout << "0" << m_day << "\"";
		}
		else
		{
			cout << m_day << "\"";
		}
	}
	/*bool Leap_year()
	{
		return ((m_year - s_v_year) % 4 == 0);
	}*/
	 bool Leap_year(int Year=0)//Year is needed for definition if m_year+Year is leap-year
	{
		return ((Year+m_year - s_v_year) % 4 == 0);
	}
	 friend Date operator+( Date& d, int days);
	 friend Date operator-( Date& d, int days);
};