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
istream& operator>>(istream& in, Account& a)
{
	cout << "Введите фамилию:";
	in >> a.m_surname;
	while (a.m_surname[0] == '\0')
	{
		cout << "Введите фамилию:";
		in >> a.m_surname;
	}
	cout << "\nВведите назначенный процент начисления\nПроцент=";//нужно обработать некорректный польз. ввод
	in >> a.m_per_cent;
	cout << "\nВведите сумму в рублях. Формат: 00,00\nСумма=";//и тут тоже
	long R;
	int K;
	scanf_s("%ld%*c%d", &R, &K);
	if (a.m_balance.SetAcc(R, K))
	{
		cout << "\nНеккоректная сумма";
		cout << "\nВведите сумму в рублях. Формат: 00,00\nСумма=";
		scanf_s("%ld%*c%d", &R, &K);
	}
	while (a.m_balance == 0.0)
	{
		cout << "\nВведите сумму в рублях. Формат: 00,00\nСумма=";//и тут тоже
		long R;
		int K;
		scanf_s("%ld%*c%d", &R, &K);
		a.m_balance.SetAcc(R, K);
	}
	cout << "\nВведите сегодняшнюю дату. Формат:ГГГГ.MM.ДД: ";
	char date[11];
	cin >> date;
	a.m_date(date);
	++a.s_AcNum;
	a.m_AcNum = a.s_AcNum;
	a.reg_time = time(NULL);
	return in;
}