#include <iostream>
#include <vector>
#include <fstream>
#include "MyForm.h"
#include "Item.cpp"

using namespace System;
using namespace System::Windows::Forms;
using namespace std;

[STAThread]

void main() {
	Application::EnableVisualStyles();

	Application::SetCompatibleTextRenderingDefault(false);

	POS::MyForm form;

	Application::Run(% form);
}

