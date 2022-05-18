#include "MyForm.h"
#include <Windows.h>


using namespace System;
using namespace System::Windows::Forms;


namespace Project2 {


	// Application entry point
	[STAThreadAttribute]
	void main(array<String^>^ args) {
		// Initial Application Parameters:
		Application::EnableVisualStyles();
		Application::SetCompatibleTextRenderingDefault(false);

		// ChartCPP - name of your project / namespace of your project
		// MyFormMyForm - name of the form to launch
		Project2::MyForm form;
		Application::Run(% form);
	


	}

	
}