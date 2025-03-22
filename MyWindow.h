#ifndef MYWINDOW_H
#define MYWINDOW_H

#include "MainWindow.h"
#include "About.h"
#include <QtCore/QTimer>

using Ui::MainWindow;
using Ui::AboutDialog;

class MyDialog : public AboutDialog, public QDialog
{
public:
    MyDialog(QWidget *parent = nullptr) : QDialog(parent)
    {
        setupUi(this);
        setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint & ~Qt::WindowMinimizeButtonHint);
    }
};

class Window : public QMainWindow, public MainWindow
{
private:
    QStringList pictures;
    QStringList copy_pictures;
    int MODE;
    int AUTO;
    QStringList::iterator it;
    int count;
    int ALLOW_PAUSE;
    QTimer * auto_timer;
    MyDialog *about_dialog;
public:
    Window(int mode, int Auto, int ap) : MainWindow(), about_dialog(new MyDialog(this)), auto_timer(new QTimer(this)), MODE(mode), AUTO(Auto), ALLOW_PAUSE(ap)
    {
        setupUi(this);
        PauseButton->setVisible(false);
        TimeBox->setVisible(false);
        connect(actionpause, &QAction::toggled, this, &Window::set_pause);
        connect(actionopen, &QAction::triggered, this, &Window::open_folder);
        connect(actionclear, &QAction::triggered, this, &Window::close_folder);
        connect(actionabout, &QAction::triggered, this, &Window::about);
        connect(ControlButton, &QPushButton::clicked, this, &Window::initialize);
        connect(NextButton, &QPushButton::clicked, this, &Window::next);
        connect(BackButton, &QPushButton::clicked, this, &Window::back);
        connect(ModeBox, &QComboBox::currentIndexChanged, this, &Window::mode_change);
        connect(AutoBox, &QCheckBox::stateChanged, this, &Window::auto_change);
        connect(TimeBox, &QSpinBox::valueChanged, this, &Window::set_timer);
        connect(auto_timer, &QTimer::timeout, this, &Window::next);
        connect(PauseButton, &QPushButton::clicked, this, &Window::pause);
    }
private slots:
    void open_folder();
    void close_folder();
    void about();
    void initialize();
    void stop();
    void next();
    void back();
    void mode_change();
    void auto_change(int);
    void set_timer(int);
    void pause();
    void auto_continue();
    void set_pause(bool);
private:
    void show_picture(QStringList::iterator);
    void set_action(bool);
};

#endif //MYWINDOW_H
