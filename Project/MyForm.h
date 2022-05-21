#pragma once

namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Ñâîäêà äëÿ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: äîáàâüòå êîä êîíñòğóêòîğà
			//
		}

	protected:
		/// <summary>
		/// Îñâîáîäèòü âñå èñïîëüçóåìûå ğåñóğñû.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	protected:
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ ìåíşToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ïîáóäóâàòèÃğàô³êToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ âõ³äí³Äàí³ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ğåãğåñ³éíàÌîäåëüToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ âèäàëèòèÃğàô³êToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ âèõ³äToolStripMenuItem;

	private:
		/// <summary>
		/// Îáÿçàòåëüíàÿ ïåğåìåííàÿ êîíñòğóêòîğà.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Òğåáóåìûé ìåòîä äëÿ ïîääåğæêè êîíñòğóêòîğà — íå èçìåíÿéòå 
		/// ñîäåğæèìîå ıòîãî ìåòîäà ñ ïîìîùüş ğåäàêòîğà êîäà.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->ìåíşToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ïîáóäóâàòèÃğàô³êToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âõ³äí³Äàí³ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ğåãğåñ³éíàÌîäåëüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âèäàëèòèÃğàô³êToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âèõ³äToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// chart1
			// 
			this->chart1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(80, 45);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series1->Legend = L"Legend1";
			series1->LegendText = L"Êîğåëÿö³éíå ïîëå";
			series1->MarkerColor = System::Drawing::Color::Red;
			series1->MarkerSize = 9;
			series1->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Circle;
			series1->Name = L"Series1";
			series1->YValuesPerPoint = 2;
			series2->BorderWidth = 4;
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series2->Color = System::Drawing::Color::DodgerBlue;
			series2->Legend = L"Legend1";
			series2->LegendText = L"Ğåãğåñ³éíà ìîäåëü";
			series2->MarkerColor = System::Drawing::Color::DodgerBlue;
			series2->MarkerSize = 0;
			series2->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Circle;
			series2->Name = L"Series2";
			this->chart1->Series->Add(series1);
			this->chart1->Series->Add(series2);
			this->chart1->Size = System::Drawing::Size(995, 574);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->ìåíşToolStripMenuItem,
					this->âèõ³äToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1162, 28);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ìåíşToolStripMenuItem
			// 
			this->ìåíşToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->ïîáóäóâàòèÃğàô³êToolStripMenuItem,
					this->âèäàëèòèÃğàô³êToolStripMenuItem
			});
			this->ìåíşToolStripMenuItem->Name = L"ìåíşToolStripMenuItem";
			this->ìåíşToolStripMenuItem->Size = System::Drawing::Size(65, 24);
			this->ìåíşToolStripMenuItem->Text = L"Ìåíş";
			// 
			// ïîáóäóâàòèÃğàô³êToolStripMenuItem
			// 
			this->ïîáóäóâàòèÃğàô³êToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->âõ³äí³Äàí³ToolStripMenuItem,
					this->ğåãğåñ³éíàÌîäåëüToolStripMenuItem
			});
			this->ïîáóäóâàòèÃğàô³êToolStripMenuItem->Name = L"ïîáóäóâàòèÃğàô³êToolStripMenuItem";
			this->ïîáóäóâàòèÃğàô³êToolStripMenuItem->Size = System::Drawing::Size(222, 26);
			this->ïîáóäóâàòèÃğàô³êToolStripMenuItem->Text = L"Ïîáóäóâàòè ãğàô³ê";
			// 
			// âõ³äí³Äàí³ToolStripMenuItem
			// 
			this->âõ³äí³Äàí³ToolStripMenuItem->Name = L"âõ³äí³Äàí³ToolStripMenuItem";
			this->âõ³äí³Äàí³ToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->âõ³äí³Äàí³ToolStripMenuItem->Text = L"Êîğåëÿö³éíå ïîëå";
			this->âõ³äí³Äàí³ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::âõ³äí³Äàí³ToolStripMenuItem_Click);
			// 
			// ğåãğåñ³éíàÌîäåëüToolStripMenuItem
			// 
			this->ğåãğåñ³éíàÌîäåëüToolStripMenuItem->Name = L"ğåãğåñ³éíàÌîäåëüToolStripMenuItem";
			this->ğåãğåñ³éíàÌîäåëüToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->ğåãğåñ³éíàÌîäåëüToolStripMenuItem->Text = L"Ğåãğåñ³éíà ìîäåëü";
			this->ğåãğåñ³éíàÌîäåëüToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ğåãğåñ³éíàÌîäåëüToolStripMenuItem_Click);
			// 
			// âèäàëèòèÃğàô³êToolStripMenuItem
			// 
			this->âèäàëèòèÃğàô³êToolStripMenuItem->Name = L"âèäàëèòèÃğàô³êToolStripMenuItem";
			this->âèäàëèòèÃğàô³êToolStripMenuItem->Size = System::Drawing::Size(222, 26);
			this->âèäàëèòèÃğàô³êToolStripMenuItem->Text = L"Âèäàëèòè ãğàô³ê";
			this->âèäàëèòèÃğàô³êToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::âèäàëèòèÃğàô³êToolStripMenuItem_Click);
			// 
			// âèõ³äToolStripMenuItem
			// 
			this->âèõ³äToolStripMenuItem->Name = L"âèõ³äToolStripMenuItem";
			this->âèõ³äToolStripMenuItem->Size = System::Drawing::Size(60, 24);
			this->âèõ³äToolStripMenuItem->Text = L"Âèõ³ä";
			this->âèõ³äToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::âèõ³äToolStripMenuItem_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1162, 673);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
		
	private: System::Void âõ³äí³Äàí³ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ğåãğåñ³éíàÌîäåëüToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void âèõ³äToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void âèäàëèòèÃğàô³êToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
};
}
