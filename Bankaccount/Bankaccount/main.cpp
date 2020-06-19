#include "Bankomat.h"
#include "time.h"
#include <cstdlib>
#include "stdio.h"
#include <cstring>
#include <clocale>
#pragma warning (disable:4996)
int main()
{
	system("chcp 1251");
	Account* a=nullptr;
	char choice;
	setlocale(0, "russian");
	cout << "MENU:\n1 - открыть счёт в банке\n     2 - информация о вашем аккаунте\n     3 - конвертировать сумму на счету в доллары\n     4 - конвертировать сумму на счету в евро\n     5 - сменить владельца счёта\n";
	cout << "\n6 - банкомат:\n     7 - снять деньги со счёта\n     8 - положить деньги на счёт\n9 - удалить аккаунт\n0 - выйти из программы\ninput>>";
	cin >> choice;
	while (choice != '0')
	{
		switch (choice)
		{
		case '1':
		{
			a = new Account;
			cin >> *a;
		}break;
		case '2':
		{
			if (a != nullptr)
			{
				a->AccView();
			}
			else
			{
				cout << "\nВы не имеете аккаунт";
			}

		}break;
		case '3':
		{
			if (a != nullptr)
			{
				a->DolConvert();
			}
			else
			{
				cout << "\nВы не имеете аккаунт";
			}

		}break;
		case '4':
		{
			if (a != nullptr)
			{
				a->EuroConvert();
			}
			else
			{
				cout << "\nВы не имеете аккаунт";
			}
		}break;
		case '5':
		{
			if (a != nullptr)
			{
				string NewOwner;
				cout << "\nВведите фамилию нового владельца:\n";
				cin >> NewOwner;
				a->RmOwner(NewOwner);
			}
			else
			{
				cout << "\nВы не имеете аккаунт";
			}
		}break;
		case '6':
		{
			if (a != nullptr)
			{
				Bankomat b(a);
				cout << "\nИспользуйте под-меню\ninput>>";
				cin >> choice;
				switch (choice)
				{
				case '7':
				{
					int R, K;
					cout << "Введите сумму в формате РУБ,КОП:";
					scanf_s("%d%*c%d", &R, &K);
					b.GetCash(R, K);
				}break;
				case '8':
				{
					int R, K;
					cout << "Введите сумму в формате РУБ,КОП:";
					scanf_s("%d%*c%d", &R, &K);
					b.PutCash(R, K);
				}break;
				}
			}
			else
			{
				cout << "\nВы не имеете аккаунт";
			}
		}break;
		case '9':
		{
			delete a;
			a = nullptr;
		}break;
		
		default:break;
	    }
		cout<<"\ninput>>";
		cin >> choice;
	}
	if (a != 0)
	{
		delete a;
	}
	return 0;
}