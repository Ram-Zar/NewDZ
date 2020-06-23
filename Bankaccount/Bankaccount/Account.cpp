#include "Account.h"
#include <clocale>
int Account::s_AcNum = 0;
void Account::AccView()
{
	static int i = -1;
	++i;
	if (i != 0)
	{
		Per_cent_plus();
	}	
	cout << "\n////INFORMATION////\n";
	cout << "Фамилия владельца счёта: " << m_surname << "\nНомер счёта: " << m_AcNum << "\nПроцент: " << setprecision(3) << m_per_cent << "%\nБаланс: ";
	m_balance.print();
	cout << " (";
	Print_Num();
	cout << ")";
	cout << "\nДата регистрации: ";
	m_date.printDate();		
}
 bool Account::GetCash(int R, int K)
{
	Money temp(R, K);
	if (m_balance < temp)
	{
		cout << "\nОтменено.У вас недостаточно средств на счету";
		return 1;
	}
	else
	{
		m_balance = m_balance - temp;
		cout << "\nВведенная сумма: " << R << "," << K << "\nБаланс: ";
		m_balance.print();
		return 0;
	}
}