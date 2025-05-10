#include "MainWindow.h"
#include "MyWindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <algorithm>
#include <random>

void Window::open_folder()
{
    dirName = QFileDialog::getExistingDirectory(this, "选择文件夹", "");
    try
    {
        if (dirName.isEmpty())
        {
            throw QString("未选择文件夹！");
        }
        QDir dir(dirName);
        QStringList filters;
        filters << "*.png" << "*.jpg" << "*.jpeg" << "*.bmp" << "*.svg" << "*.webp" 
            << "*.wbmp" << "*.icns" << "*.ico" << "*.gif" << "*.tiff" << "*.tif" << "*.tga";
        dir.setNameFilters(filters);
        if ((pictures=dir.entryList()).isEmpty())
        {
            throw QString("文件夹中无有效图片文件！");
        };
        copy_pictures = pictures;
        statusbar->showMessage(QString("已选择文件夹：%1").arg(dirName) + QString("，共 %1 张图片").arg(pictures.size()), 0);
        ControlButton->setEnabled(true);
        actionclear->setEnabled(true);
        ModeBox->setEnabled(true);
        AutoBox->setEnabled(true);
        KeepBox->setEnabled(true);
    }
    catch (const QString & e) {
        QMessageBox::critical(this, "错误", e);
    }
}

void Window::close_folder()
{
    pictures.clear();
    copy_pictures.clear();
    ControlButton->setEnabled(false);
    ControlButton->setText("开始");
    NextButton->setEnabled(false);
    BackButton->setEnabled(false);
    CountLabel->setText("");
    actionclear->setEnabled(false);
    statusbar->clearMessage();
    ModeBox->setEnabled(false);
    AutoBox->setEnabled(false);
    AutoBox->setChecked(false);
    KeepBox->setChecked(false);
    KeepBox->setEnabled(false);
}

void Window::about()
{
    about_dialog->exec();
}

void Window::initialize()
{
    set_action(false);
    if (auto_timer->interval() == 0 && AUTO) 
    {
        QMessageBox::critical(this, "错误", "未设定时间！");
        return;
    }
    if (pictures.size() > static_cast<qsizetype>(1) && !AUTO) NextButton->setEnabled(true);
    ControlButton->setText(QString("结束"));
    ModeBox->setEnabled(false);
    AutoBox->setEnabled(false);
    if (!(KeepBox->isChecked())) FilenameButton->setEnabled(true);
    disconnect(ControlButton, &QPushButton::clicked, this, &Window::initialize);
    connect(ControlButton, &QPushButton::clicked, this, &Window::stop);
    switch (MODE)
    {
        case 0:
            {
                std::random_device rd;
                std::mt19937 g(rd());
                std::shuffle(pictures.begin(), pictures.end(), g);
                break;
            }
        case 1:
            {
                pictures = copy_pictures;
                break;
            }
    }
    it = pictures.begin();
    show_picture(dirName+'/'+(*it));
    CountLabel->setText(QString("进度：%1/%2").arg(count=1).arg(pictures.size()));
    if (KeepBox->isChecked()) FilenameLabel->setText(pictures[count-1]);
    if (AUTO)
    {
        TimeBox->setEnabled(false);
        if (ALLOW_PAUSE) PauseButton->setVisible(true);
        auto_timer->start();
    }
}

void Window::next()
{
    if (!AUTO || (AUTO && !auto_timer->isActive())) BackButton->setEnabled(true);
    ++it;
    if (it == pictures.end()) 
    {
        --it;
        stop();
        return;
    }
    show_picture(dirName+'/'+(*it));
    CountLabel->setText(QString("进度：%1/%2").arg(++count).arg(pictures.size()));
    if (KeepBox->isChecked()) FilenameLabel->setText(pictures[count-1]);
    if ((it+1)==pictures.end()) 
    {
        NextButton->setEnabled(false);          
    }
}

void Window::back()
{
    if (!AUTO || (AUTO && !auto_timer->isActive())) NextButton->setEnabled(true);
    show_picture(dirName+'/'+(*(--it)));
    CountLabel->setText(QString("进度：%1/%2").arg(--count).arg(pictures.size()));
    if (KeepBox->isChecked()) FilenameLabel->setText(pictures[count-1]);
    if (it==pictures.begin()) BackButton->setEnabled(false);
}

void Window::stop()
{
    set_action(true);
    disconnect(ControlButton, &QPushButton::clicked, this, &Window::stop);
    connect(ControlButton, &QPushButton::clicked, this, &Window::initialize);
    ControlButton->setText(QString("开始"));
    NextButton->setEnabled(false);
    BackButton->setEnabled(false);
    ModeBox->setEnabled(true);
    AutoBox->setEnabled(true);
    FilenameButton->setEnabled(false);
    FilenameLabel->setText("");
    CountLabel->setText("");
    graphicsView->resetImage();
    if (AUTO)
    {
        auto_timer->stop();
        TimeBox->setEnabled(true);
        PauseButton->setText("暂停");
        disconnect(PauseButton, &QPushButton::clicked, this, &Window::auto_continue);
        connect(PauseButton, &QPushButton::clicked, this, &Window::pause);
        PauseButton->setVisible(false);
    }
}

void Window::mode_change()
{
    switch(ModeBox->currentIndex())
    {
    case 0:
        {
            MODE = 0;
            break;
        }
    case 1:
        {
            MODE = 1;
            break;
        }
    }
}

void Window::auto_change(int state)
{
    if (state == 2) 
    {
        TimeBox->setVisible(true);
        AUTO = 1;
    }
    else {
        TimeBox->setVisible(false);
        AUTO = 0;
    }
}

void Window::keep_filename(int state)
{
    if (ControlButton->text()== "结束")
    {
        if (state == 2) 
        {
            FilenameButton->setEnabled(false);
            FilenameLabel->setText(pictures[count-1]);
        }
        else 
        {
            FilenameButton->setEnabled(true);
            FilenameLabel->setText("");
        }
    }
}

void Window::set_timer(int value)
{
    auto_timer->setInterval(value*1000);
}

void Window::pause()
{
    auto_timer->stop();
    PauseButton->setText("继续");
    disconnect(PauseButton, &QPushButton::clicked, this, &Window::pause);
    connect(PauseButton, &QPushButton::clicked, this, &Window::auto_continue);
    if (count < pictures.size()) NextButton->setEnabled(true);
    if (count > 1) BackButton->setEnabled(true);
}

void Window::auto_continue()
{
    auto_timer->start();
    PauseButton->setText("暂停");
    disconnect(PauseButton, &QPushButton::clicked, this, &Window::auto_continue);
    connect(PauseButton, &QPushButton::clicked, this, &Window::pause);
    NextButton->setEnabled(false);
    BackButton->setEnabled(false);
}

void Window::set_pause(bool checked)
{
    if (checked) ALLOW_PAUSE = 1;
    else ALLOW_PAUSE = 0;
}

void Window::set_showname(bool checked)
{
    FilenameButton->setVisible(checked);
    KeepBox->setVisible(checked);
    FilenameLabel->setVisible(checked);
}

void Window::show_filename()
{
    FilenameLabel->setText(pictures[count-1]);
}

void Window::hide_filename()
{
    FilenameLabel->setText("");
}

void Window::show_picture(QString picture_name)
{
    QPixmap mapImg(picture_name);
    graphicsView->setPixmap(mapImg);
}

void Window::set_action(bool enable)
{
    actionclear->setEnabled(enable);
    actionpause->setEnabled(enable);
    actionshow->setEnabled(enable);
    actionopen->setEnabled(enable);
}