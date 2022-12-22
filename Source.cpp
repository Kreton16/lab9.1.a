#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 
using namespace std;

struct Student
{
	string prizv;
	unsigned kurs{};
	string specialnist;
	int fizyka{};
	int matematyka{};
	int informatyka{};
};
void Create(Student* p, const int N);
void Print(Student* p, const int N);
double Amount(Student* p, const int N);
double Counter(Student* p, const int N);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int N;

	cout << "������ N: "; cin >> N;
	Student* p = new Student[N];
	Create(p, N);
	Print(p, N);
	double amount = Amount(p, N);
	cout << "³������ ��������, �� �������� � � ������ � � ���������� ������ 5 = " << amount << " %";
	cout << endl;
	double count = Counter(p, N);
	cout << "ʳ������ ������ ������ � ������� �������� = " << count;
	return 0;

}

void Create(Student* p, const int N)
{
	int posada = 0;
	for (int i = 0; i < N; i++)
	{
		cout << "������� � " << i + 1 << ":" << endl;
		cin.get();
		cin.sync();
		cout << " �������: "; getline(cin, p[i].prizv);
		cout << " ����: "; cin >> p[i].kurs;
		cout << " ������������ "; cin >> p[i].specialnist;
		cout << " ������ � ������ : "; cin >> p[i].fizyka;
		cout << endl;
		cout << " ������ � ���������� : "; cin >> p[i].matematyka;
		cout << endl;
		cout << " ������ � �����������: "; cin >> p[i].informatyka;

		cout << endl;
	}
}


double Counter(Student* p, const int N) {
	double k = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].fizyka == 4)
			k++;
		if (p[i].matematyka == 4)
			k++;
		if (p[i].informatyka == 4)
			k++;
	}


	return k;
}

double Amount(Student* p, const int N)
{


	int k = 0, n = 0;
	int nloc = 0;
	for (int i = 0; i < N; i++)
	{
		if (true)
		{
			n++;
			if (p[i].fizyka == 5 && p[i].matematyka == 5)
			{
				k++;
				nloc += k;
			}
		}
	}

	return 100.0 * k / n;
}


void Print(Student* p, const int N)
{
	cout << "==================================================================================="
		<< endl;
	cout << "__________________________________________|               ����                   |"
		<< endl;
	cout << "|  �  |  �������  | ���� | ������������ |  Գ����  |  ����������  | ����������� |"
		<< endl;
	cout << "-----------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(3) << right << i + 1 << " ";
		cout << "| " << setw(1) << left << p[i].prizv
			<< "| " << setw(4) << right << p[i].kurs << " "
			<< "| " << setw(11) << left << p[i].specialnist
			<< "| " << setw(4) << right << p[i].fizyka << " "
			<< "| " << setw(4) << right << p[i].matematyka << " "
			<< "| " << setw(4) << right << p[i].informatyka << " |" << endl;

	}
	cout << "==================================================================================="

		<< endl;
	cout << endl;
}