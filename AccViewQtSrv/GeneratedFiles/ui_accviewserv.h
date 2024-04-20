/********************************************************************************
** Form generated from reading UI file 'accviewserv.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCVIEWSERV_H
#define UI_ACCVIEWSERV_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AccViewServClass
{
public:
    QPushButton *m_send;
    QListWidget *m_txt;

    void setupUi(QDialog *AccViewServClass)
    {
        if (AccViewServClass->objectName().isEmpty())
            AccViewServClass->setObjectName(QString::fromUtf8("AccViewServClass"));
        AccViewServClass->resize(342, 324);
        m_send = new QPushButton(AccViewServClass);
        m_send->setObjectName(QString::fromUtf8("m_send"));
        m_send->setGeometry(QRect(10, 180, 321, 141));
        m_txt = new QListWidget(AccViewServClass);
        m_txt->setObjectName(QString::fromUtf8("m_txt"));
        m_txt->setGeometry(QRect(10, 0, 321, 171));

        retranslateUi(AccViewServClass);

        QMetaObject::connectSlotsByName(AccViewServClass);
    } // setupUi

    void retranslateUi(QDialog *AccViewServClass)
    {
        AccViewServClass->setWindowTitle(QApplication::translate("AccViewServClass", "AccViewServ", 0, QApplication::UnicodeUTF8));
        m_send->setText(QApplication::translate("AccViewServClass", "Send", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AccViewServClass: public Ui_AccViewServClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCVIEWSERV_H
