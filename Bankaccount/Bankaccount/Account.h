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
	void AccView();
	bool GetCash(int R, int K);
    // ÂÌÅÑÒÎ ÝÒÎÃÎ ÎÏÅÐÀÒÎÐÀ ÄÎËÆÅÍ ÁÛÒÜ ÊÎÍÑÒÐÓÊÒÎÐ, ÊÎÒÎÐÛÉ ÈÍÈÖÈÀËÈÇÈÐÓÅÒ
    // ÂÑÅ ×ËÅÍÛ ÊËÀÑÑÀ, ÒÎ ÅÑÒÜ Â ÔÓÍÊÖÈÈ, ÊÎÒÎÐÀß ÈÑÏÎËÜÇÓÅÒ ÊËÀÑÑ Account,
    // ÑÍÀ×ÀËÀ Ó ÏÎËÜÇÎÂÀÒÅËß ÇÀÏÐÀØÈÂÀÞÒÑß ÄÀÍÍÛÅ m_surname, m_per_cent, m_balance,
    // È Ò.Ä., À ÏÎÒÎÌ ÂÑÅ ÎÍÈ ÏÅÐÅÄÀÞÒÑß Â ÊÎÍÑÒÐÓÊÒÎÐ È ÑÎÇÄÀ¨ÒÑß ÎÁÚÅÊÒ Account
    // ÌÅÍßÒÜ ÂÍÓÒÐÅÍÍÅ ÑÎÄÅÐÆÈÌÎÅ ÊËÀÑÑÀ ÏÐÈ ÏÎÌÎÙÈ operator>> ÍÅ ÑÀÌÀß
    // ÕÎÐÎØÀß ÈÄÅß. ÝÒÎ ÄÎËÆÍÛ ÄÅËÀÒÜ ÑÏÅÖÈÀËÜÍÛÅ ÔÓÍÊÖÈÈ Ñ ÃÎÂÎÐßÙÈÌÈ ÈÌÅÍÀÌÈ,
    // ÍÀÏÐÈÌÅÐ, void SetName(std::string), void SetBalance(double), void SetPercent(double)
    // À ÂÎÒ ÄËß ÂÛÂÎÄÀ ÓÄÎÁÍÎ ÈÑÏÎËÜÇÎÂÀÒÜ ÎÏÅÐÀÒÎÐ È ÏÐÈ ÝÒÎÌ
    // ÎÍ ÍÅ ÁÓÄÅÒ ÍÀÐÓØÀÒÜ ÂÍÓÒÐÅÍÍÅÉ ÑÒÐÓÊÒÓÐÛ ÎÁÚÅÊÒÀ
	friend istream& operator>>(istream& in, Account& a);
	bool PutCash(int R, int K)
	{
		Money temp(R, K);
		if (double(temp) > 0)
		{
			m_balance = m_balance+temp;
			cout << "\nÂâåäåííàÿ ñóììà: " << R << "," << K << "\nÁàëàíñå: ";
			m_balance.print();
			return 0;
		}
		else
		{
			cout << "\nÎòìåíà îïåðàöèè. Íåêîððåêòíàÿ ñóììà";
			return 1;
		}
	}
	void DolConvert()
	{
		cout << "\nÁàëàíñ â äîëëàðàõ: ";
		Money(m_balance / 65.0).print();
	}
	void EuroConvert()
	{
		cout << "\nÁàëàíñ â åâðî: ";
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
		m_balance.SetAcc(R, K);
		if (delta/20>1)
		{
			cout << "\nÀêêàóíò çàðåãèñòðèðîâàí "<<delta/20<< " ìåñÿöà(öåâ) íàçàä";
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
