// GUItry.cpp: 主要專案檔。

#include "stdafx.h"
#include "MainPanel.h"

using namespace System;
using namespace GUItry;

int main(array<System::String ^> ^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MainPanel());
    return 0;
}
