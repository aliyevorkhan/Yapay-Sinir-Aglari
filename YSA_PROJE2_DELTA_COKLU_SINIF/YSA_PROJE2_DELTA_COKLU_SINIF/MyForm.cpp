#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int Main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	YSAPROJE2DELTACOKLUSINIF::MyForm form;
	Application::Run(%form);

	return 0;
}