/********************************************************************************
** Form generated from reading UI file 'About.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef ABOUT_H
#define ABOUT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AboutDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *Text;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AboutDialog)
    {
        if (AboutDialog->objectName().isEmpty())
            AboutDialog->setObjectName("AboutDialog");
        AboutDialog->resize(572, 284);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AboutDialog->sizePolicy().hasHeightForWidth());
        AboutDialog->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(10);
        AboutDialog->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/window.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        AboutDialog->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(AboutDialog);
        verticalLayout->setObjectName("verticalLayout");
        Text = new QLabel(AboutDialog);
        Text->setObjectName("Text");
        Text->setTextFormat(Qt::TextFormat::MarkdownText);
        Text->setMargin(15);
        Text->setOpenExternalLinks(true);

        verticalLayout->addWidget(Text);

        buttonBox = new QDialogButtonBox(AboutDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(AboutDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AboutDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AboutDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AboutDialog);
    } // setupUi

    void retranslateUi(QDialog *AboutDialog)
    {
        AboutDialog->setWindowTitle(QCoreApplication::translate("AboutDialog", "\345\205\263\344\272\216 Image_Picker", nullptr));
        Text->setText(QCoreApplication::translate("AboutDialog", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700;\">\345\233\276\347\211\207\346\212\275\345\217\226\345\231\250 v2.0</span></p><p><span style=\" font-size:10pt;\">\345\212\237\350\203\275\350\257\264\346\230\216\357\274\232</span></p><p><span style=\" font-size:10pt;\">\342\200\242 \346\224\257\346\214\201\351\232\217\346\234\272\346\212\275\345\217\226\345\222\214\351\241\272\345\272\217\346\212\275\345\217\226\344\270\244\347\247\215\346\250\241\345\274\217\346\212\275\345\217\226\345\233\276\347\211\207</span></p><p><span style=\" font-size:10pt;\">\342\200\242 \346\224\257\346\214\201\346\273\232\350\275\256\346\224\276\345\244\247/\347\274\251\345\260\217\345\233\276\347\211\207\357\274\214\350\260\203\346\225\264\345\233\276\347\211\207\345\244\247\345\260\217</span></p><p><span style=\" font-size:10pt;\">\342\200\242 \346\224\257\346\214\201\350\207\252\345\256\232\344\271\211\351\227\264\351\232\224\350\207\252\345\212\250\346\222\255\346\224\276\357\274\214\345\217\257\351\200\211"
                        "\346\222\255\346\224\276\344\270\255\346\232\202\345\201\234</span></p><p><span style=\" font-size:10pt;\">\346\255\244\351\241\271\347\233\256\345\237\272\344\272\216 </span><a href=\"https://www.qt.io/download-open-source\"><span style=\" text-decoration: underline; color:#003e92;\">Qt for Open Source</span></a><span style=\" font-size:10pt;\"> \344\273\245\345\217\212\345\205\266\344\273\226 </span><a href=\"https://blog.csdn.net/xiaohuihuihuige/article/details/128165275\"><span style=\" text-decoration: underline; color:#003e92;\">\344\272\222\350\201\224\347\275\221\345\274\200\346\272\220\344\273\243\347\240\201\357\274\210\347\211\210\346\235\203\345\275\222\345\216\237\344\275\234\350\200\205\346\211\200\346\234\211\357\274\211</span></a><span style=\" font-size:10pt;\"> \345\274\200\345\217\221</span></p><p><span style=\" font-size:10pt;\">\351\241\271\347\233\256 GitHub \345\234\260\345\235\200\357\274\232</span><a href=\"https://github.com/KusicFack/Image_Picker\"><span style=\" text-decoration: und"
                        "erline; color:#003e92;\">KusicFack/Image_Picker</span></a></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AboutDialog: public Ui_AboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // ABOUT_H
