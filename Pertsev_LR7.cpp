#include <iostream>
using namespace std;

void Matrix42(); // Дана матриця розміру M × N. Знайти кількість її рядків, елементи яких
// впорядковані за зростанням.

void Matrix54(); // Дана матриця розміру M × N. Поміняти місцями стовпець з номером N і
// перший з стовпців, що містять тільки від’ємні елементи.Якщо необхідних
// стовпців немає, то вивести матрицю без змін.

const int M = 20, N = 20; // Mаксимальне кількість рядків стовпців
void get_mas(double a[M][N], int&, int&); // Функція введення елементів масиву
int res_mas42(double a[M][N], int&, int&); // Функція виведення елементів масиву для 42
int res_mas54(double a[M][N], int& n, int& m); // Функція пошуку потрібного стовпця
void show_mas54(double a[M][N], int&, int&); // Функція виведення елементів масиву для 54
void show_mas(double a[M][N], int&, int&); // Функція виведення елементів масиву

bool cor_main(int); // Допоміжнi функції

int main()
{ // Перемикання між завданнями
	setlocale(LC_ALL, "Ukrainian");
	int num; // Оголошення
	do
	{
		cout << "Введiть номер завдання (вихiд - 3)\n";
		cin >> num; // Введення даних
		if (cor_main(num))
		{
			switch (num)
			{
			case 1: Matrix42(); break; // Завдання 1
			case 2: Matrix54(); break; // Завдання 2
			case 3: cout << "Вихiд..."; break;
			}
		}
		else cout << "Помилка. Потрiбно ввести 1, 2\n"; // Повідомлення про помилку
	} while (num != 3);
}

bool cor_main(int n) // Допоміжна
{
	if (n == 1 || n == 2 || n == 3) return true;
	else return false;
}

void get_mas(double a[M][N], int& n, int& m) // Функція введення елементів масиву
{
	do
	{
		cout << "Введiть кiлькiсть стовпцiв (n)\n";
		cin >> n; // Введення кількості стовпців
		cout << "Введiть кiлькiсть рядкiв (m)\n";
		cin >> m; // Введення кількості рядків
	}
	// Доки некоректні вхід.дані
	while (n < 2 || n>N || m <2 || m>M);
	cout << "Введiть елементи масиву\n";
	for (int i = 0; i < m; i++) // Введення елементів
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
}

void Matrix42()
{
	int n, m; // Оголошення розмірів масиву
	double a[M][N]; // Оголошення масиву
	get_mas(a, n, m); // Функція введення елементів масиву
	cout << "Кiлькiсть рядкiв матрицi елементи яких впорядкованi за зростанням - " << res_mas42(a, n, m) << endl; // Виведення відповіді
}

int res_mas42(double a[M][N], int& n, int& m)
{
	int num = 0; // Змінна, яка потрібна для підрахунку рядків
	for (int k = 0; k < m; k++)
	{
		int count = 0; // Змінна, яка потрібна для підрахунку елементів в рядку, які впорядковані за зростанням
		for (int p = 0;p < n - 1; p++)
		{
			if (a[k][p] < a[k][p + 1]) count++;
		}
		if (count == n - 1) num++; // Перевірка, чи дорівнює кількість підрахованих елементів загальної кількості елементів у рядку
	}
	return num;
}

void Matrix54()
{
	int n, m; // Оголошення розмірів масиву
	double a[M][N]; // Оголошення масиву
	get_mas(a, n, m); // Функція введення елементів масиву
	show_mas54(a, n, m); // Виведення відповіді
}
int res_mas54(double a[M][N], int& n, int& m)
{
	int count = 0, num = -1; // count - рахує від'ємні елементи, num - визначає стовпець, temp - значення елемента
	bool tt = 1; // tt потрібне для закріплення номеру першого стовпця з від'ємними елементами
	for (int k = 0; k < n; k++) // Пошук потрібного стовпця
	{
		for (int p = 0; p < m; p++)
		{
			if (a[p][k] < 0) count++; // Підрахунок від'ємнних елементів
			if (count == m && tt == 1) { num = k; tt = 0; }
		}
	}
	return num;
}

void show_mas54(double a[M][N], int& n, int& m)
{
	int num = res_mas54(a, n, m);
	double temp;
	if (num != -1)
	{
		cout << "Новий масив\n";
		for (int k = 0; k < m; k++) // Виведення нового масиву
		{
			temp = a[k][n - 1]; // Присвоєння тимчасовим змінним значення елемента
			a[k][n - 1] = a[k][num]; 
			a[k][num] = temp; // Присвоєння елементам значення тимчасових змінних
			for (int p = 0; p < n; p++)
			{
				cout << a[k][p] << "  "; // Виведення масиву
				if (p == n - 1) cout << endl;
			}
		}
	}
	else
	{
		cout << "Стовпцiв з вiд'ємними елементами немає\n";
		show_mas(a, n, m);
	}
}

void show_mas(double a[M][N], int& n, int& m)
{
	for (int k = 0; k < m; k++) // Виведення масиву
	{
		for (int p = 0; p < n; p++)
		{
			cout << a[k][p] << "  "; // Виведення масиву
			if (p == n - 1) cout << endl;
		}
	}
}