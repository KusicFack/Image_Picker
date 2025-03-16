/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "ImageViewer.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionopen;
    QAction *actionclear;
    QAction *actionabout;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *ControlButton;
    QComboBox *ModeBox;
    QLabel *CountLabel;
    QSpacerItem *horizontalSpacer;
    QPushButton *BackButton;
    QPushButton *NextButton;
    ImageViewer *graphicsView;
    QStatusBar *statusbar;
    QMenuBar *menuBar;
    QMenu *menufile;
    QMenu *menuhelp;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(823, 672);
        QFont font;
        font.setPointSize(10);
        MainWindow->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/window.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        MainWindow->setWindowIcon(icon);
        actionopen = new QAction(MainWindow);
        actionopen->setObjectName("actionopen");
        actionclear = new QAction(MainWindow);
        actionclear->setObjectName("actionclear");
        actionclear->setEnabled(false);
        actionabout = new QAction(MainWindow);
        actionabout->setObjectName("actionabout");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        ControlButton = new QPushButton(centralwidget);
        ControlButton->setObjectName("ControlButton");
        ControlButton->setEnabled(false);

        horizontalLayout->addWidget(ControlButton);

        ModeBox = new QComboBox(centralwidget);
        ModeBox->addItem(QString());
        ModeBox->addItem(QString());
        ModeBox->setObjectName("ModeBox");
        ModeBox->setEnabled(false);

        horizontalLayout->addWidget(ModeBox);

        CountLabel = new QLabel(centralwidget);
        CountLabel->setObjectName("CountLabel");

        horizontalLayout->addWidget(CountLabel);

        horizontalSpacer = new QSpacerItem(30, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        BackButton = new QPushButton(centralwidget);
        BackButton->setObjectName("BackButton");
        BackButton->setEnabled(false);
        BackButton->setCheckable(false);
        BackButton->setChecked(false);

        horizontalLayout->addWidget(BackButton);

        NextButton = new QPushButton(centralwidget);
        NextButton->setObjectName("NextButton");
        NextButton->setEnabled(false);

        horizontalLayout->addWidget(NextButton);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 2);
        horizontalLayout->setStretch(3, 6);
        horizontalLayout->setStretch(4, 1);
        horizontalLayout->setStretch(5, 1);

        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 1);

        graphicsView = new ImageViewer(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setEnabled(true);

        gridLayout->addWidget(graphicsView, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 823, 33));
        menufile = new QMenu(menuBar);
        menufile->setObjectName("menufile");
        menufile->setToolTipsVisible(false);
        menuhelp = new QMenu(menuBar);
        menuhelp->setObjectName("menuhelp");
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menufile->menuAction());
        menuBar->addAction(menuhelp->menuAction());
        menufile->addAction(actionopen);
        menufile->addAction(actionclear);
        menuhelp->addAction(actionabout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\345\233\276\347\211\207\346\212\275\345\217\226\345\231\250", nullptr));
        actionopen->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266\345\244\271", nullptr));
        actionclear->setText(QCoreApplication::translate("MainWindow", "\345\205\263\351\227\255\346\226\207\344\273\266\345\244\271", nullptr));
        actionclear->setIconText(QCoreApplication::translate("MainWindow", "\345\205\263\351\227\255\346\226\207\344\273\266\345\244\271", nullptr));
        actionabout->setText(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216", nullptr));
#if QT_CONFIG(tooltip)
        ControlButton->setToolTip(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\346\212\275\345\217\226(\342\206\265)", nullptr));
#endif // QT_CONFIG(tooltip)
        ControlButton->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213", nullptr));
#if QT_CONFIG(shortcut)
        ControlButton->setShortcut(QCoreApplication::translate("MainWindow", "Return", nullptr));
#endif // QT_CONFIG(shortcut)
        ModeBox->setItemText(0, QCoreApplication::translate("MainWindow", "\351\232\217\346\234\272\351\200\211\346\213\251", nullptr));
        ModeBox->setItemText(1, QCoreApplication::translate("MainWindow", "\351\241\272\345\272\217\351\200\211\346\213\251", nullptr));

        CountLabel->setText(QString());
#if QT_CONFIG(tooltip)
        BackButton->setToolTip(QCoreApplication::translate("MainWindow", "\344\270\212\344\270\200\345\274\240\345\233\276\347\211\207(\342\206\220)", nullptr));
#endif // QT_CONFIG(tooltip)
        BackButton->setText(QCoreApplication::translate("MainWindow", "\344\270\212\344\270\200\345\274\240", nullptr));
#if QT_CONFIG(shortcut)
        BackButton->setShortcut(QCoreApplication::translate("MainWindow", "Left", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        NextButton->setToolTip(QCoreApplication::translate("MainWindow", "\344\270\213\344\270\200\345\274\240\345\233\276\347\211\207(\342\206\222)", nullptr));
#endif // QT_CONFIG(tooltip)
        NextButton->setText(QCoreApplication::translate("MainWindow", "\344\270\213\344\270\200\345\274\240", nullptr));
#if QT_CONFIG(shortcut)
        NextButton->setShortcut(QCoreApplication::translate("MainWindow", "Right", nullptr));
#endif // QT_CONFIG(shortcut)
        menufile->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        menuhelp->setTitle(QCoreApplication::translate("MainWindow", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOW_H
