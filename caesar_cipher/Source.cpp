#include "c_cipher.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace caesarciphergui;

[STAThread]
int main()
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew caesar());

    return 0;







}