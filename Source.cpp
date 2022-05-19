#include "MyForm.h"
#include <cmath>
#include <fstream>

#define CountOfModels 6
#define Tstudent 3.5

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace Project2
{

	struct Model//структура, яка описує модель
	{
		int type;//тип моделі
		int n;//кількість змінних
		double averagex, averagey;//середні значення х, у
		double* valx;//масив значень х
		double* valy;//масив значень у
		long double DispX; //дисперсія х
		double DispY;//дисперсія у
		double Radj, Radj2;//коеф. кореляції та детермінації
		double a1, a0;//справжні значення а0 і а1

		Model()//конструктор
		{
			type = 0;//
			n = 0;//
			averagex = 0;//
			averagey = 0;//
			valx = nullptr;//
			valy = nullptr;//
			DispX = 0;
			DispY = 0;
			Radj = 0;
			Radj2 = 0;

		}

		void enterInformation(int type1, double* matrixx, double* matrixy, int colsCount)//функція вводу інформації в модель
		{
			type = type1;
			n = colsCount;
			valx = new double[n];
			valy = new double[n];
			double sumx = 0, sumy = 0;
			if (type == 1)
			{
				for (int j = 0; j < colsCount; j++)
				{
					double value = 1 / matrixx[j];
					valx[j] = round(value * 100000) / 100000;
					sumx += valx[j];
				}
				for (int j = 0; j < colsCount; j++)
				{
					valy[j] = matrixy[j];
					sumy += matrixy[j];
				}
				averagex = round((sumx / n) * 100000) / 100000;
				averagey = sumy / n;
			}
			else if (type == 2)
			{
				for (int j = 0; j < colsCount; j++)
				{
					double value = 1 / (matrixx[j] * matrixx[j]);
					valx[j] = round(value * 100000) / 100000;
					sumx += valx[j];
				}
				for (int j = 0; j < colsCount; j++)
				{
					valy[j] = matrixy[j];
					sumy += matrixy[j];
				}
				averagex = round((sumx / n) * 100000) / 100000;
				averagey = sumy / n;
			}
			else if (type == 3)
			{
				for (int j = 0; j < colsCount; j++)
				{
					double value = 1 / ((matrixx[j] * matrixx[j]) * matrixx[j]);
					valx[j] = round(value * 100000) / 100000;
					sumx += valx[j];
				}
				for (int j = 0; j < colsCount; j++)
				{
					valy[j] = matrixy[j];
					sumy += matrixy[j];
				}
				averagex = round((sumx / n) * 100000) / 100000;
				averagey = sumy / n;
			}
			else if (type == 4)
			{
				double value;
				for (int j = 0; j < colsCount; j++)
				{
					value = 1 / (matrixx[j]);
					valx[j] = round(value * 100000) / 100000;
					sumx += valx[j];
				}
				for (int j = 0; j < colsCount; j++)
				{
					value = 1 / (matrixy[j]);
					valy[j] = round(value * 100000) / 100000;
					sumy += valy[j];
				}
				averagex = round((sumx / n) * 100000) / 100000;
				averagey = round((sumy / n) * 100000) / 100000;
			}
			else if (type == 5)
			{
				double value;
				for (int j = 0; j < colsCount; j++)
				{
					double value = 1 / (matrixx[j] * matrixx[j]);
					valx[j] = round(value * 100000) / 100000;
					sumx += valx[j];
				}
				for (int j = 0; j < colsCount; j++)
				{
					value = 1 / matrixy[j];
					valy[j] = round(value * 100000) / 100000;
					sumy += valy[j];
				}
				averagex = round((sumx / n) * 100000) / 100000;
				averagey = round((sumy / n) * 100000) / 100000;
			}
			else if (type == 6)
			{
				double value;
				for (int j = 0; j < colsCount; j++)
				{
					value = 1 / ((matrixx[j] * matrixx[j]) * matrixx[j]);
					valx[j] = round(value * 100000) / 100000;
					sumx += valx[j];
				}
				for (int j = 0; j < colsCount; j++)
				{
					value = 1 / matrixy[j];
					valy[j] = round(value * 100000) / 100000;
					sumy += valy[j];
				}
				averagex = round((sumx / n) * 100000) / 100000;
				averagey = round((sumy / n) * 100000) / 100000;
			}



		}
		void Dispersion()//функція знаходження дисперсії
		{
			double sum_dispx = 0.0;
			double sum_dispy = 0.0;

			for (int j = 0; j < n; j++)
			{

				sum_dispx += round(((valx[j] - averagex) * (valx[j] - averagex)) * 100000) / 100000;

			}
			DispX = round((sum_dispx / (n * 1.0 - 1)) * 100000) / 100000;

			for (int j = 0; j < n; j++)
			{
				sum_dispy += round(((valy[j] - averagey) * (valy[j] - averagey)) * 100000) / 100000;
			}
			DispY = round((sum_dispy / (n * 1.0 - 1)) * 100000) / 100000;
		}

		void correlation_coeff()//функція знаходження кореляційного коеф. та коеф. детермінації
		{
			double sum_dispx = 0.0;
			double sum_dispy = 0.0;
			double sum_x_y = 0;

			for (int j = 0; j < n; j++)
			{

				sum_dispx = valx[j] - averagex;
				sum_dispy = valy[j] - averagey;
				sum_x_y += round((sum_dispx * sum_dispy) * 100000) / 100000;
			}
			Radj = (sum_x_y / (n * 1.0 - 1));
			Radj /= round((sqrt(DispX) * sqrt(DispY)) * 100000) / 100000;
			Radj = round((Radj) * 100000) / 100000;
			Radj2 = round((Radj * Radj) * 100000) / 100000;

		}
		void Distruct()
		{
			if (valx != nullptr)
				delete[] valx;

			if (valx != nullptr)
				delete[] valy;
		}
	};
	void mod_sort(Model* model)//функція знаходження найбільшого коефіцієнта детермінації з усіх моделей
	{

		Model temp;
		for (int i = 0; i < CountOfModels - 1; i++)
		{
			for (int j = 0; j < CountOfModels - i - 1; j++) {

				if (model[j].Radj2 < model[j + 1].Radj2) {
					temp = model[j];
					model[j] = model[j + 1];
					model[j + 1] = temp;
				}
			}

		}

	}
	double** create_matrix_x(double* x, int n)//створення матриці потрібного виду для іксів
	{
		double** matrix = new double* [n];

		for (int i = 0; i < n; i++)
		{

			matrix[i] = new double[2];
			for (int j = 0; j < 2; j++)
			{
				if (j == 0)
					matrix[i][j] = 1;
				else
					matrix[i][j] = x[i];
			}
		}
		return matrix;
	}
	double** transpose_matrix(double** x, int n)//функція транспонування матриці
	{

		double** matrix = new double* [2];
		for (int i = 0; i < 2; i++)
		{
			matrix[i] = new double[n];

			for (int j = 0; j < n; j++)
			{

				matrix[i][j] = x[j][i];

			}

		}
		return matrix;



	}
	double** multiply_matrix(double** x, int row1, int col1, double** y, int row2, int col2)//функція множення двумірних матриць
	{
		if (col1 != row2)
			return nullptr;
		double sum = 0;
		double** matrix = new double* [row1];
		for (int i = 0; i < row1; i++)
		{
			matrix[i] = new double[col2];
			for (int j = 0; j < col2; j++)
			{
				matrix[i][j] = 0;
				for (int k = 0; k < col1; k++)
					matrix[i][j] += round((x[i][k] * y[k][j]) * 100000) / 100000;
			}

		}

		return matrix;

	}
	double* multiply_matrix(double** x, int row1, int col1, double* y, int row2)//функція множення двумірної матриці на одномірну
	{
		int cols2 = 1;

		if (col1 != row2)
			return nullptr;
		double sum = 0;

		double* matrix = new double[row1];

		for (int i = 0; i < row1; i++)
		{


			matrix[i] = 0;
			for (int k = 0; k < col1; k++)
			{

				matrix[i] += round((x[i][k] * y[k]) * 100000) / 100000;

			}
		}

		return matrix;

	}
	double** inversion(double** A, int N)//функція знаходження зовортної матриці
	{
		double temp;

		double** E = new double* [N];

		for (int i = 0; i < N; i++)
			E[i] = new double[N];

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				E[i][j] = 0.0;

				if (i == j)
					E[i][j] = 1.0;
			}

		for (int k = 0; k < N; k++)
		{
			temp = A[k][k];

			for (int j = 0; j < N; j++)
			{
				A[k][j] /= temp;
				E[k][j] /= temp;
			}

			for (int i = k + 1; i < N; i++)
			{
				temp = A[i][k];

				for (int j = 0; j < N; j++)
				{
					A[i][j] -= A[k][j] * temp;
					E[i][j] -= E[k][j] * temp;
				}
			}
		}

		for (int k = N - 1; k > 0; k--)
		{
			for (int i = k - 1; i >= 0; i--)
			{
				temp = A[i][k];

				for (int j = 0; j < N; j++)
				{
					A[i][j] -= A[k][j] * temp;
					E[i][j] -= E[k][j] * temp;
				}
			}
		}

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				A[i][j] = round((E[i][j]) * 100000) / 100000;

		for (int i = 0; i < N; i++)
			delete[] E[i];

		delete[] E;

		return A;
	}
	double residual_dispersion(int n, double* x, double* y, double* A)//знаходження залишкової дисперсії
	{
		double* y_estimated = new double[n];
		double sum = 0;
		for (int i = 0; i < n; i++)
		{
			y_estimated[i] = round((A[0] + A[1] * x[i]) * 100000) / 100000;
		}
		for (int i = n - 3; i < n; i++)
		{
			sum += round(((y[i] - y_estimated[i]) * (y[i] - y_estimated[i])) * 100000) / 100000;

		}
		sum /= (n * 1.0 - 2);
		sum = round((sum) * 100000) / 100000;
		delete[]y_estimated;
		return sum;
	}
	double standart_mistake_S0(double residual_dispersion, double DispersionX, int n)//стандартна похибка вільного члена а0
	{
		double S0 = (residual_dispersion / (n * DispersionX));
		S0 = round((sqrt(S0)) * 100000) / 100000;
		return S0;
	}
	double standart_mistake_S1(double residual_dispersion, double DispersionX, int n, double averagex)//стандартна похибка вільного члена а1
	{
		double S1 = round((DispersionX + (averagex * averagex)) * 100000) / 100000;
		S1 = (residual_dispersion * S1);
		S1 /= (n * DispersionX);
		S1 = round((sqrt(S1)) * 100000) / 100000;
		return S1;
	}
	void find_interval(double arr_a[], double* A, double S, int type)//функція знаходження довірчого интервалу
	{
		if (type == 0)
		{
			arr_a[0] = round(((A[0] - Tstudent * S)) * 100000) / 100000;
			arr_a[1] = round(((A[0] + Tstudent * S)) * 100000) / 100000;;
		}
		else
		{
			arr_a[0] = round(((A[1] - Tstudent * S)) * 100000) / 100000;
			arr_a[1] = round(((A[1] + Tstudent * S)) * 100000) / 100000;
		}

	}
	int Sign(double Val) {//функція знаходження знаку змінних
		if (Val == 0)  return 0;
		if (Val > 0)  return 1;
		else return -1;
	}
	void delete_all(double** matrix_x, double** matrix_t, double** mult_matrix, double* matrix_y, double** inversed_matrix, double* matrixA, int colsCount)//функція видалення усіх масивів
	{
		for (int i = 0; i < colsCount; i++)
			delete[] matrix_x[i];

		delete[] matrix_x;

		for (int i = 0; i < 2; i++)
			delete[] matrix_t[i];

		delete[] matrix_t;

		for (int i = 0; i < 2; i++)
			delete[] mult_matrix[i];

		delete[] mult_matrix;

		delete[] matrix_y;

		for (int i = 0; i < 2; i++)
			delete[] inversed_matrix[i];

		delete[] inversed_matrix;
		delete[] matrixA;

		//delete[] valx;
		//delete[] valy;
	}

	void regression_model(double &a1, double &a0,int &type)//функція знаходження справжніх коефіцієнтів а0 і а1
	{
		

		std::ifstream input("Input.txt");
		if (!input.is_open())
		{
		//	if (MessageBox::Show("Error", "Attention!") == Windows::Forms::DialogResult::Yes) {
				Application::Exit();
			//}
		}
		// если не открылся
	//	else if (input.peek() == EOF) Application::Exit(); // если первый символ конец файла
	//	{
		//	if (MessageBox::Show("Error", "Attention!") == Windows::Forms::DialogResult::Yes) {
		//		Application::Exit();
			//}
		//}

		int  colsCount;
		input >> colsCount;

		double* matrixx = new double[colsCount];
		double* matrixy = new double[colsCount];

		for (int j = 0; j < colsCount; j++)
		{
			input >> matrixx[j];

		}

		for (int j = 0; j < colsCount; j++)
		{
			input >> matrixy[j];

		}

		input.close();


		Model hyperbolic1, hyperbolic2, hyperbolic3, mod_hyperbolic1, mod_hyperbolic2, mod_hyperbolic3;

		Model models[CountOfModels] = { hyperbolic1, hyperbolic2, hyperbolic3, mod_hyperbolic1, mod_hyperbolic2, mod_hyperbolic3 };


		for (int i = 0; i < CountOfModels; i++)
		{
			models[i].enterInformation(i + 1, matrixx, matrixy, colsCount);
			models[i].Dispersion();
			models[i].correlation_coeff();
		}

		mod_sort(models);

		for (int i = 0; i < CountOfModels; i++)
		{
			double** matrix_x = create_matrix_x(models[i].valx, colsCount);//матриця іксів
			double** matrix_t = transpose_matrix(matrix_x, colsCount);//транспонована матриця х
			double* matrix_y = models[i].valy;
			double** mult_matrix = multiply_matrix(matrix_t, 2, colsCount, matrix_x, colsCount, 2);//матриця множення Хт на Х

			double** inversed_matrix = inversion(mult_matrix, 2);//обернена матриця
			mult_matrix = multiply_matrix(inversed_matrix, 2, 2, matrix_t, 2, colsCount);//інверсія транспонованної матриці

			double* matrixA = multiply_matrix(mult_matrix, 2, colsCount, matrix_y, colsCount);//помножили результат на У, отримали матрицю значень а0 и а1
			double res_dispersion = residual_dispersion(colsCount, models[i].valx, models[i].valy, matrixA);//знаходження залишкової дисперсії
			double S0 = standart_mistake_S0(res_dispersion, models[i].DispX, colsCount);//стандартна похибка вільного члена а0
			double S1 = standart_mistake_S1(res_dispersion, models[i].DispX, colsCount, models[i].averagex);//стандартна похибка вільного члена а0

			double interval_a0[2];//довірчий інтервал ао
			find_interval(interval_a0, matrixA, S0, 0);//знаходимо довірчий інтервал ао
			double interval_a1[2];//довірчий інтервал а1
			find_interval(interval_a1, matrixA, S1, 1);//знаходимо довірчий інтервал а1

			if (Sign(interval_a0[0]) == Sign(interval_a0[1]) && (Sign(interval_a1[0]) == Sign(interval_a1[1])))
			{

				models[i].a1 = round((1 / matrixA[0]) * 100000) / 100000;//знаходимо справжнє значение а1
				models[i].a0 = round((models[i].a1 * matrixA[1]) * 100000) / 100000;//знаходимо справжнє значение а0
		
				a1 = models[i].a1;
				a0 = models[i].a0;
				type = models[i].type;
				
				break;

			}
			
			for (auto i : models)
				i.Distruct();

			delete_all(matrix_x, matrix_t, mult_matrix, matrix_y, inversed_matrix, matrixA, colsCount);//видалення всіх масивів з пам'яті


		}

		delete[] matrixx;
		delete[] matrixy;
	
	}

}
