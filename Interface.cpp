#include "MyForm.h"
#include <fstream>
#include <cmath>


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace Project2
{
	void regression_model(double& a1, double& a0, int& type);

	System::Void Project2::MyForm::вхідніДаніToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		//1.Відкриття файлу на запис
		std::ifstream input("Input.txt");
		int  n;
		input >> n;
		double* matrixx = new double[n];
		double* matrixy = new double[n];
		//2.Запис інформації з файлу
		for (int j = 0; j < n; j++)
		{
			input >> matrixx[j];
		}
		for (int j = 0; j < n; j++)
		{
			input >> matrixy[j];
		}
		//3.Закрити файл
		input.close();
		//4.Функція очищення графіку
		this->chart1->Series[0]->Points->Clear();
		for (int i = 0; i < n; i++)
		{
			//5.Функція побудови кореляційного поля даних
			this->chart1->Series[0]->Points->AddXY(matrixx[i], matrixy[i]);
		}


	}

	System::Void Project2::MyForm::регресійнаМодельToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		//1.Ініціалізація параметрів
		double X1, Xn = 0, a1, a0, y, i;
		int type;
		//2.Відкриття файлу для зчитування
		std::ifstream input("Input.txt");
		int  n;
		input >> n;
		//3.Знаходження мінімального та максимального значень параметра х
		for (int j = 0; j < n; j++)
		{
			input >> i;
			if (j == 0) X1 = i;
			if (i < X1)	X1 = i;
			if (i > Xn) Xn = i;
		}
		//4.Закриття файлу
		input.close();
		//5. Отримання даних з функції regression_model() для побудови графіку регресії 
		regression_model(a1, a0, type);
		//6.Функція очищення графіку
		this->chart1->Series[1]->Points->Clear();
		//7.Побудова графіку залежно від типу моделі
		if (type == 1)
		{
			while (X1 <= Xn)
			{

				y = round(((a0 + (a1 / X1))) * 100000) / 100000;
				this->chart1->Series[1]->Points->AddXY(X1, y);
				X1 += 0.1;
			}
		}
		else if (type == 2)
		{
			while (X1 <= Xn)
			{

				y = round(((a0 + (a1 / (X1 * X1)))) * 100000) / 100000;
				this->chart1->Series[1]->Points->AddXY(X1, y);
				X1 += 0.1;
			}
		}
		else if (type == 3)
		{
			while (X1 <= Xn)
			{

				y = round(((a0 + (a1 / (X1 * X1 * X1)))) * 100000) / 100000;
				this->chart1->Series[1]->Points->AddXY(X1, y);
				X1 += 0.1;
			}
		}
		else if (type == 4)
		{
			while (X1 <= Xn)
			{

				y = round(((a1 * X1)) * 100000) / 100000;
				y /= round((a0 + X1) * 100000) / 100000;
				this->chart1->Series[1]->Points->AddXY(X1, y);
				X1 += 0.1;
			}
		}
		else if (type == 5)
		{
			while (X1 <= Xn)
			{

				y = round(((a1 * (X1 * X1))) * 100000) / 100000;
				y /= round((a0 + (X1 * X1)) * 100000) / 100000;
				this->chart1->Series[1]->Points->AddXY(X1, y);
				X1 += 0.1;
			}

		}
		else if (type == 6)
		{
			while (X1 <= Xn)
			{

				y = round(((a1 * (X1 * X1 * X1))) * 100000) / 100000;
				y /= round((a0 + (X1 * X1 * X1)) * 100000) / 100000;
				this->chart1->Series[1]->Points->AddXY(X1, y);
				X1 += 0.1;
			}
		}

	}

	System::Void Project2::MyForm::вихідToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		//1.Реалізація кнопок виходу з програми
		if (MessageBox::Show("Вийти?", "Увага!", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes) {
			Application::Exit();
		}

	}

	System::Void Project2::MyForm::видалитиГрафікToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		//1.Очищення графіку кореляційного поля даних
		this->chart1->Series[0]->Points->Clear();
		//2.Очищення графіку регресії
		this->chart1->Series[1]->Points->Clear();

	}
}
