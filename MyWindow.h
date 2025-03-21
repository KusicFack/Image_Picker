#ifndef MYWINDOW_H
#define MYWINDOW_H

#include "MainWindow.h"

using Ui::MainWindow;

class Window : public QMainWindow, public MainWindow
{
private:
    QStringList pictures;
    QStringList copy_pictures;
    int MODE;
    QStringList::iterator it;
    int count;
public:
    Window(int mode) : MainWindow(), MODE(mode)
    {
        setupUi(this);
        connect(actionopen, &QAction::triggered, this, &Window::openfolder);
        connect(actionclear, &QAction::triggered, this, &Window::closefolder);
        connect(actionabout, &QAction::triggered, this, &Window::about);
        connect(ControlButton, &QPushButton::clicked, this, &Window::initialize_mode);
        connect(NextButton, &QPushButton::clicked, this, &Window::next);
        connect(BackButton, &QPushButton::clicked, this, &Window::back);
        connect(ModeBox, &QComboBox::currentIndexChanged, this, &Window::mode_change);
    }
private slots:
    void openfolder();
    void closefolder();
    void about();
    void initialize(int);
    void initialize_mode() {initialize(MODE);}
    void stop();
    void next();
    void back();
    void mode_change();
private:
    void showpicture(QStringList::iterator);
};
#endif //MYWINDOW_H
