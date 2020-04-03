#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int Main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	YSACOKKATMAN::MyForm Form;
	Application::Run(%Form);

	return 0;
}