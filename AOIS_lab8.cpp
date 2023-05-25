#include"Proc.h"

int main()
{
	setlocale(LC_ALL, "ru");
	Memory m;
	vector<int> V = { 0,1,0 };
	m.getRandomMass();
	cout << "Начальная матрица: " << endl << m << endl;
	Memory a = m.getNormalMatrix();
	cout << "Нормальная матрица: " << endl << a << endl;
	Memory d = a.getDiagonalMatrix(a.getMassive());
	cout << "Диагональная матрица из нормальной: " << endl << d << endl;
	vector<int> word = m.getWord(4);
	cout << "Слово под номером 4" << endl << word << endl;
	m.sum(V);
	Memory e = m.getNormalMatrix();
	cout << "Нормальная матрица поckе суммы для V =  " << V << endl << e << endl;
	m.sortDescending();
	Memory b = m.getNormalMatrix();
	cout << "Отсортированная по убыванию нормальная матрица: " << endl << b << endl;
	cout << "Функция 4 для номеров 2, 3, 0 " << endl << m.fun_4(2, 3, 0) << endl;
	cout << "Функция 6 для номеров 5, 7, 8 " << endl << m.fun_4(5, 7, 8) << endl;
	cout << "Функция 9 для номеров 10, 12, 4 " << endl << m.fun_4(10, 12, 4) << endl;
	cout << "Функция 11 для номеров 7, 14, 9 " << endl << m.fun_4(7, 14, 9) << endl;
	Memory v = m.getNormalMatrix();
	cout << "Нормальная матрица после преобразований: " << endl << v << endl;
}
