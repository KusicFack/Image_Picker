#include "MainWindow.h"
#include "MyWindow.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    Window window(0,0,1);
    window.show();
    return app.exec();
}