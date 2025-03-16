#include "MainWindow.h"
#include "MyWindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <algorithm>
#include <random>

void Window::openfolder()
{
    QString dirName = QFileDialog::getExistingDirectory(this, "选择文件夹", "");
    try
    {
        if (dirName.isEmpty())
        {
            throw QString("未选择文件夹！");
        }
        QDir dir(dirName);
        QStringList filters;
        filters << "*.png" << "*.jpg" << "*.jpeg" << "*.bmp" << "*.gif";
        dir.setNameFilters(filters);
        if ((pictures=dir.entryList()).isEmpty())
        {
            throw QString("文件夹中无有效图片文件！");
        };
        for (int i = 0; i < pictures.size(); ++i)
        {
            pictures[i]=dir.absoluteFilePath(pictures[i]);
        }
        copy_pictures = pictures;
        statusBar()->showMessage(QString("已选择文件夹：%1").arg(dirName) + QString("，共 %1 张图片").arg(pictures.size()));
        ControlButton->setEnabled(true);
        actionclear->setEnabled(true);
        ModeBox->setEnabled(true);
    }
    catch (const QString & e) {
        QMessageBox::critical(this, "错误", e);
    }
}

void Window::closefolder()
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
}

void Window::about()
{
    QMessageBox::information(this, "关于", "图片抽取器 v1.0\n\n功能说明：支持随机抽取和顺序抽取两种模式\n\n作者：KusicFack");
}

void Window::initialize(int mode)
{
    if (pictures.size() > static_cast<qsizetype>(1)) NextButton->setEnabled(true);
    ControlButton->setText(QString("结束"));
    ModeBox->setEnabled(false);
    disconnect(ControlButton, &QPushButton::clicked, this, initialize_mode);
    connect(ControlButton, &QPushButton::clicked, this, stop);
    switch (mode)
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
    showpicture(it);
    CountLabel->setText(QString("进度：%1/%2").arg(count=1).arg(pictures.size()));
}

void Window::next()
{
    BackButton->setEnabled(true);
    showpicture(++it);
    CountLabel->setText(QString("进度：%1/%2").arg(++count).arg(pictures.size()));
    if ((it+1)==pictures.end()) NextButton->setEnabled(false);
}

void Window::back()
{
    NextButton->setEnabled(true);
    showpicture(--it);
    CountLabel->setText(QString("进度：%1/%2").arg(--count).arg(pictures.size()));
    if (it==pictures.begin()) BackButton->setEnabled(false);
}

void Window::stop()
{
    disconnect(ControlButton, &QPushButton::clicked, this, stop);
    connect(ControlButton, &QPushButton::clicked, this, initialize_mode);
    ControlButton->setText(QString("开始"));
    NextButton->setEnabled(false);
    BackButton->setEnabled(false);
    ModeBox->setEnabled(true);
    CountLabel->setText("");
    graphicsView->scene()->clear();
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

void Window::showpicture(QStringList::iterator it)
{
    QPixmap pix(*it);
    if (!graphicsView->scene()) {
        graphicsView->setScene(new QGraphicsScene(this));
    } else {
        graphicsView->scene()->clear();
    }
    graphicsView->scene()->addPixmap(pix);
    graphicsView->setRenderHint(QPainter::SmoothPixmapTransform);
    graphicsView->setRenderHint(QPainter::Antialiasing);
    graphicsView->fitInView(graphicsView->scene()->itemsBoundingRect(), Qt::KeepAspectRatio);
}