#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> // ������������ ����������� ��������
using namespace std;
enum Tovars{};
struct Tovar
{
	string nazva;
	string magazin;
	string kilkist;
	unsigned vartist;
};
void Create(Tovar* p, const int N);
void Print(Tovar* p, const int N);
void Remove(int* &p, int& N);
double LineSearch(Tovar* p, const int N);
void Sort(Tovar* p, const int N);
int BinSearch(Tovar* p, const int N, const string prizv, const string magazin);
int* IndexSort(Tovar* p, const int N);
void PrintIndexSorted(Tovar* p, int* I, const int N);
int main()
{
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251); 
	srand((unsigned)time(NULL));
	
	int N;
	cout << "Enter size: "; cin >> N;
	int* a = new int[N];
	cout << "������ �������  N: "; cin >> N;

	Tovar* p = new Tovar[N];
	double proc;
	string nazva;
	string magazin;
	string kilkist;
	int vartist;
	int found;
	int menuItem;
	do {
		cout << endl << endl << endl;
		cout << "������� ��:" << endl << endl;
		cout << " [1] - �������� ����� � ���������" << endl;
		cout << " [2] - ���� ����� �� �����" << endl;
		cout << " [3] - ����� ����� 10000: " << endl;
		
		cout << " [4] - ������� ������������� �����" << endl;
		cout << " [5] - ������� ����� ���������� �� ������� �� ��������" << endl;
		cout << " [6] - �������� ������������� �� ���� �����"
			<< endl << endl;
		cout << " [0] - ����� �� ���������� ������ ��������" << endl << endl;
		cout << "������ ��������: "; cin >> menuItem;
		cout << endl << endl << endl;
		switch (menuItem)
		{
		case 1:
			Create(p, N);
			break;
		case 2:
			Print(p, N);
			break;
		case 3:
			proc = LineSearch(p, N);
			cout << "����� ����� 10000:" << endl;
			cout << proc << "%" << endl;
			break;
			break;
		case 4:
				Sort(p, N);
			break;
		case 5:
			cout << "������ ����� ������:" << endl;
			cout << " ����� ������: "; getline(cin, nazva);
			cout << endl;
			if ((found = BinSearch(p, N, nazva, magazin)) != -1)
				cout << "�������� ����� � ������� " << found + 1 << endl;
			else
				cout << "�������� ������ �� ��������" << endl;
			break;
		case 6:
			PrintIndexSorted(p, IndexSort(p, N), N);
			break;

		
		case 0:
			break;
		default:
			cout << "�� ����� ��������� ��������! "
				"��� ������ ����� - ����� ��������� ������ ����" << endl;
		}
	} while (menuItem != 0);
	return 0;
}
void Create(int* p, const int N)
{
	for (int i = 0; i < N; i++)
		p[i] = -10 + rand() % 21;
}
void Print(int* p, const int N)
{
	for (int i = 0; i < N; i++)
		cout << "p[" << setw(2) << i << "] = " << p[i] << endl;
	cout << endl;
}
void Create(Tovar* p, const int N)
{
	int posada;
	for (int i = 0; i < N; i++)
	{
		cout << "����� � " << i + 1 << ":" << endl;
		cin.get(); // ������� ����� ��������� � �� ����������� �������
		cin.sync(); // "����� �����", �� �� ����� ������ ��������� ������� �����

		cout << " ����� ������: "; getline(cin, p[i].nazva);
		cout << " �������: "; cin >> p[i].magazin;
		cout << " �������: "; cin >> p[i].vartist;
		cout << " ʳ������: "; cin >> p[i].kilkist;
		cout << endl;
	}
}
void Print(Tovar* p, const int N)
{
	cout << "========================================================================="
		<< endl;
	cout << "| � | ����� ������ | ������� | ������� | ʳ������ |"
		<< endl;
	cout << "-------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(3) << right << i + 1 << " ";
		cout << "| " << setw(13) << right << p[i].nazva
			<< "| " << setw(8) << right << p[i].magazin
			<< "| " << setw(4) << right << p[i].vartist;
	
		
	}
	cout << "========================================================================="
		<< endl;
	cout << endl;
}
double LineSearch(Tovar* p, const int N)
{
	cout << "����� ����� 10000:" << endl;
	int k = 0, n = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].vartist < 10000)
		{
			k++; n++;
			cout << setw(3) << right << k
				<< " " << p[i].nazva << endl;
		}
	
	}
	return 100.0 * k / n;
}
void Sort(Tovar* p, const int N)
{
	Tovar tmp;
	for (int i0 = 0; i0 < N - 1; i0++) // ����� "���������"
		for (int i1 = 0; i1 < N - i0 - 1; i1++)
			if ((p[i1].magazin > p[i1 + 1].magazin)
				||
				(p[i1].magazin == p[i1 + 1].magazin &&
					p[i1].nazva > p[i1 + 1].nazva))
			{
				tmp = p[i1];
					p[i1] = p[i1 + 1];
				p[i1 + 1] = tmp;
			}
}
int BinSearch(Tovar* p, const int N, const string nazva, const string magazin)
{ // ������� ������ ���������� �������� ��� -1, ���� ������� ������� �������
	int L = 0, R = N - 1, m;
	do {
		m = (L + R) / 2;
		if (p[m].nazva == nazva && p[m].magazin == magazin)
			return m;
		if ((p[m].magazin < magazin)
			||
			(p[m].magazin == magazin &&
				p[m].nazva < nazva))
		{
			L = m + 1;
		}
		else
		{
			R = m - 1;
		}
	} while (L <= R);
	return -1;
}
int* IndexSort(Tovar* p, const int N)
{ 
	int* I = new int[N]; 
	for (int i = 0; i < N; i++)
		I[i] = i; 
	int i, j, value; 
	for (i = 1; i < N; i++)
	{
		value = I[i];
		for (j = i - 1;
			j >= 0 && ((p[I[j]].magazin > p[value].magazin) ||
				(p[I[j]].magazin == p[value].magazin &&
					p[I[j]].nazva > p[value].nazva));
			j--)
		{
			I[j + 1] = I[j];
		}
		I[j + 1] = value;
	}
	return I;
}

void PrintIndexSorted(Tovar * p, int* I, const int N)
{ // ��������� ������� Print(), ��� ������ ��������� p[i]...
 // ������������� ������ �� ��������� ���������� ������ �: p[I[i]]...
	cout << "========================================================================="
		<< endl;
	cout << "| � | ����� ������ | ������� | ������� | ʳ������ |"
		<< endl;
	cout << "-------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(3) << right << i + 1 << " ";
		cout << "| " << setw(13) << right << p[i].nazva
			<< "| " << setw(8) << right << p[i].magazin
			<< "| " << setw(4) << right << p[i].vartist;
		
	}
	cout << "========================================================================="
		<< endl;
	cout << endl;
}void Remove(int*& p, int& N)
{
	int K = 0; // ������� ��������, �� ������� ��������
	for (int i = 0; i < N; i++) // ������� ������� ����� �
		if (p[i] >= 0) // ���������� ������� ��������,
			K++; // �� ������� ��������
	int* t = new int[K]; // ���������� �����
	int j = 0; // ������ � ����������� �����
	for (int i = 0; i < N; i++) // ������� ������� �����
		if (p[i] >= 0) // � ������� ��������,
			t[j++] = p[i]; // �� ������� ��������
	delete[] p; // ������� ������� �����
	p = t; // ����������� �������� �� ���������� �����
	N = K; // ������� �������� ������� ��������
}