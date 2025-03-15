#include "MainWindow.h"

using Ui::MainWindow;

class Window : public QMainWindow, public Ui_MainWindow
{
    public:
    Window() : Ui_MainWindow()
    {
        setupUi(this);
    }
};

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    Window window;
    window.show();
    return app.exec();
}