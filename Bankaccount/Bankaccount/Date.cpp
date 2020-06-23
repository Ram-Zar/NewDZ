#include <iostream>
//#include "string.h"
#include "Date.h"
using namespace std;
int Date::month_info(int mv)//calculates amount of days in given month
{
	int mon_info, year_info;
	if (mv < 0)
	{
		mon_info = (12 + m_month + mv) % 12;
		if ((13 - m_month - mv) % 12 == 0)//reverse for easy calculating 
		{
			year_info = (13 - m_month - mv) / 12 - 1;
		}
		else
		{
			year_info = (13 - m_month - mv) / 12;
		}
	}
	else
	{
		mon_info = (m_month + mv) % 12;
		year_info = (m_month + mv) / 12;
	}
	if (mon_info == 0)
	{
		mon_info = 12;
	}
	if (mon_info == 2)
	{
		if (Leap_year(year_info))
		{
			mon_info = 29;
		}
		else
		{
			mon_info = 28;
		}
	}
	else
	{
		if (mon_info < 8)
		{
			if (mon_info % 2 == 0)
			{
				mon_info = 30;
			}
			else
			{
				mon_info = 31;
			}
		}
		else
		{
			if (mon_info % 2 == 0)
			{
				mon_info = 31;
			}
			else
			{
				mon_info = 30;
			}
		}
	}
	return mon_info;
}

// d НАДО ПЕРЕДАВАТЬ ПО КОНСТАНТНОЙ ССЫЛКЕ
// ВООБЩЕ, ВСЁ, ЧТО НЕ ДОЛЖНО ИЗМЕНИТЬСЯ ВНУТРИ ФУНКЦИИ,
// ПЕРЕДАЁТСЯ ПО КОНСТАНТНОЙ ССЫЛКЕ, НУ ИЛИ ПО ЗНАЧЕНИЮ
// (НО ПО ЗНАЧЕНИЮ МОЖЕТ БЫТЬ ДОЛГО, ЕСЛИ ОБЪЕКТ БОЛЬШОЙ, ТАК КАК
// ВЫПОЛНЯЕТСЯ КОПИРОВАНИЕ),
// ВЫЗЫВАЮЩАЯ СТОРОНА ДОЛЖНА ПОНИМАТЬ БЕЗ ИЗУЧЕНИЯ КОДА ФУНКЦИИ, БУДЕТ
// ИЗМЕНЁН ПЕРЕДАВАЕМЫЙ ПАРАМЕТ ИЛИ НЕТ?
// В ДАННОМ СЛУЧАЕ ПАРАМЕТР НЕ МЕНЯЕТСЯ, НО ССЫЛКА ПОЗВОЛЯЕТ ЭТО СДЕЛАТЬ
// И ПРИДЁТСЯ ВЧИТЫВАТЬСЯ В КОД
Date operator+( Date& d, int days)
{
	int mon_info = d.month_info(), sum = d.m_day + days, i = 1;
	int Y = d.m_year, M = d.m_month, D = d.m_day;
	if (sum < mon_info)
	{
		D = sum;
	}
	while (sum > mon_info)
	{
		++M;
		if (M > 12)
		{
			++Y;
			M = M % 12;
		}
		sum -= mon_info;
		mon_info = d.month_info(i);
		if (sum <= mon_info)
		{
			D = sum;
			sum = mon_info;
		}
		++i;
	}
	return Date(Y, M, D);
}

Date operator-(Date& d, int days)
{
	int mon_info = d.month_info(), sum = d.m_day - days, i = -1;
	int Y = d.m_year, M = d.m_month, D = d.m_day;
	if (sum > 0)
	{
		D = sum;
	}
	while (sum <= 0)
	{
		--M;
		if (M == 0)
		{
			--Y;
			M = 12;
		}
		mon_info = d.month_info(i);
		sum = mon_info + sum;
		if (sum > 0)
		{
			D = sum;
			sum = 1;
		}
		--i;
	}
	return Date(Y, M, D);
}
