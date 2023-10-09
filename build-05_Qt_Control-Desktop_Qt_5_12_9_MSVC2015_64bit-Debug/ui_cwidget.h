/********************************************************************************
** Form generated from reading UI file 'cwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CWIDGET_H
#define UI_CWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CWidget
{
public:
    QPushButton *pushButton;
    QToolButton *toolButton;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *rBtnMan;
    QRadioButton *rBtnWoman;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;

    void setupUi(QWidget *CWidget)
    {
        if (CWidget->objectName().isEmpty())
            CWidget->setObjectName(QString::fromUtf8("CWidget"));
        CWidget->resize(553, 522);
        pushButton = new QPushButton(CWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(72, 110, 131, 28));
        toolButton = new QToolButton(CWidget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(10, 180, 111, 51));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Snipaste_2023-10-09_18-48-50.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(80, 80));
        toolButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        groupBox = new QGroupBox(CWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(90, 380, 91, 111));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        rBtnMan = new QRadioButton(groupBox);
        rBtnMan->setObjectName(QString::fromUtf8("rBtnMan"));

        verticalLayout->addWidget(rBtnMan);

        rBtnWoman = new QRadioButton(groupBox);
        rBtnWoman->setObjectName(QString::fromUtf8("rBtnWoman"));

        verticalLayout->addWidget(rBtnWoman);

        groupBox_2 = new QGroupBox(CWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(280, 390, 111, 101));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        radioButton_3 = new QRadioButton(groupBox_2);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));

        verticalLayout_2->addWidget(radioButton_3);

        radioButton_4 = new QRadioButton(groupBox_2);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));

        verticalLayout_2->addWidget(radioButton_4);

        groupBox_3 = new QGroupBox(CWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(320, 100, 191, 241));
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        checkBox = new QCheckBox(groupBox_3);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        verticalLayout_3->addWidget(checkBox);

        checkBox_2 = new QCheckBox(groupBox_3);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        verticalLayout_3->addWidget(checkBox_2);

        checkBox_3 = new QCheckBox(groupBox_3);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));

        verticalLayout_3->addWidget(checkBox_3);

        checkBox_4 = new QCheckBox(groupBox_3);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setTristate(false);

        verticalLayout_3->addWidget(checkBox_4);


        retranslateUi(CWidget);

        QMetaObject::connectSlotsByName(CWidget);
    } // setupUi

    void retranslateUi(QWidget *CWidget)
    {
        CWidget->setWindowTitle(QApplication::translate("CWidget", "CWidget", nullptr));
        pushButton->setText(QApplication::translate("CWidget", "PushButton", nullptr));
        toolButton->setText(QApplication::translate("CWidget", "\346\265\267\350\264\274\346\227\227", nullptr));
        groupBox->setTitle(QApplication::translate("CWidget", "\346\200\247\345\210\253", nullptr));
        rBtnMan->setText(QApplication::translate("CWidget", "\347\224\267", nullptr));
        rBtnWoman->setText(QApplication::translate("CWidget", "\345\245\263", nullptr));
        groupBox_2->setTitle(QApplication::translate("CWidget", "\345\251\232\345\247\273", nullptr));
        radioButton_3->setText(QApplication::translate("CWidget", "\345\267\262\345\251\232", nullptr));
        radioButton_4->setText(QApplication::translate("CWidget", "\346\234\252\345\251\232", nullptr));
        groupBox_3->setTitle(QApplication::translate("CWidget", "\351\227\256\345\215\267\350\260\203\346\237\245", nullptr));
        checkBox->setText(QApplication::translate("CWidget", "\344\273\267\346\240\274\345\256\236\346\203\240", nullptr));
        checkBox_2->setText(QApplication::translate("CWidget", "\345\217\243\346\204\237\345\245\275", nullptr));
        checkBox_3->setText(QApplication::translate("CWidget", "\346\234\215\345\212\241\345\210\260\344\275\215", nullptr));
        checkBox_4->setText(QApplication::translate("CWidget", "\350\200\201\346\235\277\345\250\230\345\245\275", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CWidget: public Ui_CWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CWIDGET_H
