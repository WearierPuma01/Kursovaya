#include <iostream>
#include<fstream>
#include <string>
using namespace std;

bool in1 = 0, in2 = 0, in3=0,in=0;
int menu();
void consoli(int* v, int** matrix);
void consolo(int* v, int**matrix);
void filei(int* v, int** matrix, string locate);
int filecount(string locate);
void fileo(int* v, int** matrix);
void edit(int*v, int** matrix);
void multix(int v, int** matrix1, int** matrix2, int** matrix3);
void idz1(int v, int** matrix1, int** matrix2, int** matrix3);
int main()
{
	string locate;
	int i;
	int** matrix1=NULL, ** matrix2=NULL, ** matrix3=NULL;
	int v1 = 0, v2 = 0, v3 = 0;
	setlocale(LC_ALL, "ru");
	while (true)
	{
		int a = menu();

		if (a == 0)
			break;
		switch (a)
		{
		case 1:
			cout << "====================================================" << "\n";
			cout << "1. Ввести матрицу А" << endl
				<< "2. Ввести матрицу Б" << endl
				<< "3. Ввести матрицу В" << "\n"
				<< "4. Вывести на экран матрицу А" << "\n"
				<< "5. Вывести на экран матрицу Б" << "\n"
				<< "6. Вывести на экран матрицу В" << "\n";
			cout << "====================================================" << "\n";
			cin >> a;
			switch (a)
			{
			case (1):
				delete[]matrix1;
				cout << "Ввод матрицы А" << "\n" << "\n";
				cout << "Введите размер матрицы: ";
				cin >> v1;
				cout << "\n";
				matrix1 = new int* [v1];
				for (i = 0; i < v1; i++)
					matrix1[i] = new int[v1];
				consoli(&v1, matrix1);
				in1 = 1;
				consolo(&v1, matrix1);
				break;

			case (2):
					delete[]matrix2;
				cout << "Ввод матрицы Б" << "\n" << "\n";
				cout << "Введите размер матрицы: ";
				cin >> v2;
				cout << "\n";
				matrix2 = new int* [v2];
				for (i = 0; i < v2; i++)
					matrix2[i] = new int[v2];
				consoli(&v2, matrix2);
				in2 = 1;
				consolo(&v2, matrix2);
				break;

			case (3):
				delete[]matrix3;
				cout << "Ввод матрицы В" << "\n" << "\n";
				cout << "Введите размер матрицы: ";
				cin >> v3;
				cout << "\n";
				matrix3 = new int* [v3];
				for (i = 0; i < v3; i++)
					matrix3[i] = new int[v3];
				consoli(&v3, matrix3);
				in3 = 1;
				consolo(&v3, matrix3);
				break;

			case (4):
				if (in1 == 1)
				{
					cout << "Вывод матрицы А" << "\n" << "\n";
					consolo(&v1, matrix1);
				}
				else
					cout << "Для начала введите матрицу А" << "\n";
				break;

			case (5):
				if (in2 == 1)
				{
					cout << "Вывод матрицы Б" << "\n" << "\n";
					consolo(&v2, matrix2);
				}
				else 
					cout << "Для начала введите матрицу Б" << "\n";
				break;
			case 6:
				if (in3 == 1)
				{
					cout << "Вывод матрицы В" << "\n" << "\n";
					consolo(&v3, matrix3);
				}
				else
					cout << "Для начала введите матрицу В" << "\n";
				break;

			}
			break;

		case 2:
			cout << "====================================================" << "\n";
			cout << "1. Загрузить матрицу А" << endl 
				 << "2. Загрузить матрицу Б" << endl 
				 << "3. Загрузить матрицу В" << "\n"
				 << "4. Выгрузить матрицу А в файл" << "\n" 
				 << "5. Выгрузить матрицу Б в файл" << "\n"
				 << "6. Выгрузить матрицу В в файл" << "\n";
			cout << "====================================================" << "\n";
			cin >> a;
			switch (a)
			{
			case 1:
				cout << "Загрузка матрицы А" << "\n" << "\n";
				cout << "Введите путь до матрицы: ";
				cin >> locate;
				cout << "\n";
				v1 = filecount(locate);
				if (in == 0)
				{
					delete[]matrix1;
					matrix1 = new int* [v1];
					for (i = 0; i < v1; i++)
						matrix1[i] = new int[v1];
					filei(&v1, matrix1, locate);
					in1 = 1;
				}
				else
					in = 0;
				break;
			case 2:
				cout << "Загрузка матрицы Б" << "\n" << "\n";
				cout << "Введите путь до матрицы: ";
				cin >> locate;
				cout << "\n";
				v2 = filecount(locate);
				if (in == 0)
				{
					delete[]matrix2;
					matrix2 = new int* [v2];
					for (i = 0; i < v2; i++)
						matrix2[i] = new int[v2];
					filei(&v2, matrix2, locate);
					in2 = 1;
				}
				else
					in = 0;
				break;
			case 3:
				cout << "Загрузка матрицы В" << "\n" << "\n";
				cout << "Введите путь до матрицы: ";
				cin >> locate;
				cout << "\n";
				v1 = filecount(locate);
				if (in == 0)
				{
					delete[]matrix3;
					matrix3 = new int* [v3];
					for (i = 0; i < v3; i++)
						matrix3[i] = new int[v3];
					filei(&v3, matrix3, locate);
					in1 = 1;
				}
				else
					in = 0;
				break;
			case 4:
				if (in1 == 1)
				{
					cout << "Вывод матрицы А в файл" << "\n";
					fileo(&v1, matrix1);
				}
				else
					cout << "Для начала введите матрицу А" << "\n";
				break;
			case 5:
				if (in2 == 1)
				{
					cout << "Вывод матрицы Б в файл" << "\n";
					fileo(&v2, matrix2);
				}
				else
					cout << "Для начала введите матрицу Б" << "\n";
				break;
			case 6:
				if (in3 == 1)
				{
					cout << "Вывод матрицы В в файл" << "\n";
					fileo(&v3, matrix3);
				}
				else
					cout << "Для начала введите матрицу В" << "\n";
				break;







			}
			break;
		case 3:
			cout << "====================================================" << "\n";
			cout << "1. Редактировать матрицу А" << endl
				<< "2. Редактировать матрицу Б" << endl
				<< "3. Редактировать матрицу В" << "\n";
			cout << "====================================================" << "\n";
			cin >> a;
			switch (a)
			{
			case 1:
				if (in1 == 1)
				{
					edit(&v1, matrix1);
				}
				else
					cout << "Для начала введите матрицу А!" << "\n";
				break;
			case 2:
				if (in2 == 1)
				{
					edit(&v2, matrix2);
				}
				else
					cout << "Для начала введите матрицу Б!" << "\n";
				break;
			case 3:
				if (in3 == 1)
				{
					edit(&v3, matrix3);
				}
				else
					cout << "Для начала введите матрицу В!" << "\n";
				break;
			}
			break;
		case 4:
			cout << "====================================================" << "\n";
			cout << "1. А*Б=В" << endl
			 	 << "2. А*В=Б" << endl
				 << "3. Б*В=А" << "\n";
			cout << "====================================================" << "\n";
			cin >> a;
			switch (a)
			{
			case 1:
				if (v1 != v2)
				{
					cout << "Размеры матриц не совпадают!" << "\n";
					break;
				}
				if (in1 == 0)
				{
					cout << "Матрица А не введена" << "\n";
					break;
				}
				if (in2 == 0)
				{
					cout << "Матрица Б не введена" << "\n";
					break;
				}
				delete[]matrix3;
				matrix3 = new int* [v1];
				for (i = 0; i < v1; i++)
					matrix3[i] = new int[v1];
				multix(v1, matrix1, matrix2, matrix3);
				v3 = v1;
				in3 = 1;
				break;
			case 2:
				if (v1 != v3)
				{
					cout << "Размеры матриц не совпадают!" << "\n";
					break;
				}
				if (in1 == 0)
				{
					cout << "Матрица А не введена" << "\n";
					break;
				}
				if (in3 == 0)
				{
					cout << "Матрица В не введена" << "\n";
					break;
				}
				delete[]matrix2;
				matrix2 = new int* [v1];
				for (i = 0; i < v1; i++)
					matrix2[i] = new int[v1];
				multix(v1, matrix1, matrix3, matrix2);
				v2 = v1;
				in2 = 1;
				break;
			case 3:
				if (v2 != v3)
				{
					cout << "Размеры матриц не совпадают!" << "\n";
					break;
				}
				if (in2 == 0)
				{
					cout << "Матрица Б не введена" << "\n";
					break;
				}
				if (in3 == 0)
				{
					cout << "Матрица В не введена" << "\n";
					break;
				}
				delete[]matrix1;
				matrix1 = new int* [v2];
				for (i = 0; i < v2; i++)
					matrix1[i] = new int[v2];
				multix(v1, matrix2, matrix3, matrix1);
				v1 = v2;
				in1 = 1;
				break;
			}
			break;
		case 5:
			cout << "====================================================" << "\n";
			cout << "Результат задания 1 будет записан в матрицу В" << "\n";
			cout << "1. Задание 1" << endl
				<< "2. Задание 2" << endl;
			cout << "====================================================" << "\n";
			cin >> a;
			switch (a)
			{
			case 1:
				if (in1 == 0)
				{
					cout << "Матрица А не введена" << "\n";
					break;
				}
				if (in2 == 0)
				{
					cout << "Матрица Б не введена" << "\n";
					break;
				}
				if (v1 != v2)
				{
					cout << "Размеры матриц не совпадают!" << "\n";
					break;
				}
				
				if ((v1 % 2) == 1)
				{
					cout << "Размер матрицы нечетен!" << "\n";
					break;
				}
				else
				{
					delete[]matrix3;
					matrix3 = new int* [v1];
					for (i = 0; i < v1; i++)
						matrix3[i] = new int[v1];
					idz1(v1, matrix1, matrix2, matrix3);
					v3 = v1;
					in3 = 1;
					consolo(&v3, matrix3);
				}
				break;
			case 2:
				if (in1 == 0)
				{
					cout << "Матрица А не введена" << "\n";
					break;
				}
				if (in2 == 0)
				{
					cout << "Матрица Б не введена" << "\n";
					break;
				}
				if (v1 != v2)
				{
					cout << "Размеры матриц не совпадают!" << "\n";
					break;
				}

				if ((v1 % 2) == 1)
				{
					cout << "Размер матрицы нечетен!" << "\n";
					break;
				}
				else
				{
					delete[]matrix3;
					matrix3 = new int* [v1];
					for (i = 0; i < v1; i++)
						matrix3[i] = new int[v1];
				}
			}

		}
	}
	cout << "Программа завершает работу..." << "\n";
	delete[]matrix1;
	delete[]matrix2;
	delete[]matrix3;

}

int menu()
{
	int n;
	cout << "====================================================" << "\n";
	cout << "\t" << "\t" << "Меню" << "\n"
		<< "\t" << "1.Консольный ввод/вывод" << "\n"
		<< "\t" << "2.Файловый ввод/вывод" << "\n"
		<< "\t" << "3.Редактировать матрицы" << "\n"
		<< "\t" << "4.Перемножение матриц" << "\n"
		<< "\t" << "5.ИДЗ" << "\n"
		<< "\t" << "0.Закрыть программу" << "\n";
	cout << "====================================================" << "\n";
	cin >> n;
	cout << "\n";
	return n;
}

void consoli(int* v, int**matrix)
{
	int i, j;
	
	for (i = 0; i < *v; i++)
		for (j = 0; j < *v; j++)
		{
			cout << "Введите " << i + 1 << " " << j + 1 << " элемент матрицы: ";
			cin >> matrix[i][j];
			cout << "\n";
		}

}

void consolo(int* v, int**matrix)
{
	cout << "Размерность матрицы: " << *v << "\n" << "\n";
	int i, j;
	for (i = 0; i < *v; i++)
	{
		for (j = 0; j < *v; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
}

int filecount(string locate)
{
	ifstream fmatrix;
	fmatrix.open(locate);
	if (fmatrix.is_open())
	{
		int n = 0, tmp;
		cout << "Файл успешно открыт" << "\n" << "\n";
		while (!fmatrix.eof())
		{
			fmatrix >> tmp;
			n += 1;
		}
		n = sqrt(n);
		fmatrix.close();
		return n;
	}
	else
	{
		cout << "Ошибка открытия файла!" << "\n";
		in = 1;
		return 0;
	}
}

void filei(int* v, int** matrix, string locate)
{
	int i, j;
	ifstream fmatrix;
	fmatrix.open(locate);
	if (fmatrix.is_open())
	{
		for (i = 0; i < *v; i++)
			for (j = 0; j < *v; j++)
			{
				fmatrix >> matrix[i][j];
			}
		consolo(&*v, matrix);
		fmatrix.close();	
	}
}

void fileo(int* v, int** matrix)
{
	string locate;
	int i, j;
	cout << "Введите путь до файла: ";
	cin >> locate;
	cout << "\n";
	ofstream fmatrix;
	fmatrix.open(locate);
	if (fmatrix.is_open())
	{
		for (i = 0; i < *v; i++)
		{
			for (j = 0; j < *v; j++)
			{
				fmatrix << matrix[i][j] << " ";
			}
			fmatrix << "\n";
		}
		cout << "\n";
		cout << "Вывод закончен успешно" << "\n";
		cout << "\n";
	}
	fmatrix.close();
}

void edit(int*v,int** matrix)
{
	int i, j,t;
	while (1)
	{
		cout << "Введите номер i, j элемента который хотите редактировать (любой <1 для выхода): ";
		cin >> i >> j;
		cout << "\n";
		if ((i < 1) || (j < 1))
			break;
		if ((i > * v) || (j > * v))
			cout << "Некорректный номер!" << "\n";
		else
		{
			cout << "Текущее значение: " << matrix[i-1][j-1] << "\n" << "Новое значение: ";
			cin >> t;
			cout << "\n";
			matrix[i-1][j-1] = t;
		}

	}
}

void multix(int v, int** matrix1, int** matrix2, int** matrix3)
{
	int i, j, k, tmp=0;
	for (i = 0; i < v; i++) //Умножение матриц
		for (j = 0; j < v; j++)
		{
			for (k = 0; k < v; k++)
			{
				tmp = tmp + (matrix1[i][k] * matrix2[k][j]);
			}
			matrix3[i][j] = tmp;
			tmp = 0;
		}
}

void idz1(int v, int** matrix1, int** matrix2, int** matrix3)
{
	int i, j, k, tmp=0, vv;
	vv = v /2;
	for  (i = 0; i < v; i++)
	{
		for (j = 0; j < v; j++)
		{
			matrix3[i][j] = 0;
		}
	}
	for (i = 0; i < vv; i++) //Умножение матриц
		for (j = 0; j < vv; j++)
		{
			for (k = 0; k < vv; k++)
			{
				tmp = tmp + (matrix1[i][k] * matrix2[k][j]);
			}
			matrix3[i][j] = tmp;
			tmp = 0;
		}
	for (i = vv; i < v; i++) //Умножение матриц
		for (j = vv; j < v; j++)
		{
			for (k = vv; k < v; k++)
			{
				tmp = tmp + (matrix1[i][k] * matrix2[k][j]);
			}
			matrix3[i][j] = tmp;
			tmp = 0;
		}
}