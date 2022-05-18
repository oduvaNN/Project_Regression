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

	System::Void Project2::MyForm::âõ³äí³Äàí³ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		std::ifstream input("Input.txt");

		int  n;
		input >> n;


		double* matrixx = new double[n];
		double* matrixy = new double[n];


		for (int j = 0; j < n; j++)
		{
			input >> matrixx[j];
		}

		for (int j = 0; j < n; j++)
		{
			input >> matrixy[j];
		}

		input.close();
		this->chart1->Series[0]->Points->Clear();
		for (int i = 0; i < n; i++)
		{
			this->chart1->Series[0]->Points->AddXY(matrixx[i], matrixy[i]);
		}

	}

	System::Void Project2::MyForm::ðåãðåñ³éíàÌîäåëüToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{

		double X1 = 3.4, Xn = 6.5, a1, a0, y;
		int type;
		regression_model(a1, a0, type);
		this->chart1->Series[1]->Points->Clear();

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

	System::Void Project2::MyForm::âèõ³äToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (MessageBox::Show("Âèéòè?", "Óâàãà!", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes) {
			Application::Exit();
		}
	}

	System::Void Project2::MyForm::âèäàëèòèÃðàô³êToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->chart1->Series[0]->Points->Clear();
		this->chart1->Series[1]->Points->Clear();
	}
}
