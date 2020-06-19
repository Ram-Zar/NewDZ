#include <iostream>
#include "Money.h"
using namespace std;
void Money::distributor()//calculates an anmount of bank_notes
{
	C5000 = unsigned char(m_main / 5000);
	long delta = m_main - 5000 * C5000;
	C1000 = unsigned char(delta / 1000);
	delta = delta - 1000 * C1000;
	C500 = unsigned char(delta / 500);
	delta = delta - 500 * C500;
	C100 = unsigned char(delta / 100);
	delta = delta - 100 * C100;
	C50 = unsigned char(delta / 50);
	delta = delta - 50 * C50;
	C10 = unsigned char(delta / 10);
	delta = delta - 10 * C10;
	C5 = unsigned char(delta / 5);
	delta = delta - 5 * C5;
	C2 = unsigned char(delta / 2);
	delta = delta - 2 * C2;
	C1 = unsigned char(delta / 1);
	delta = delta - 1 * C1;
	C05 = m_k / 50;
	delta = m_k - 50 * C05;
	C01 = unsigned char(delta / 10);
	delta = delta - 10 * C01;
	C005 = unsigned char(delta / 5);
	delta = delta - 5 * C005;
	C001 = unsigned char(delta / 1);
	delta = delta - 1 * C001;
}
