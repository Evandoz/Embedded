/********************************************************************************
** Form generated from reading ui file 'finalorder.ui'
**
** Created: Thu Jul 13 08:32:55 2017
**      by: Qt User Interface Compiler version 4.4.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_FINALORDER_H
#define UI_FINALORDER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTableView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_finalorder
{
public:
    QLabel *label;
    QTableView *tableView;
    QLabel *label_2;
    QLabel *label_total;
    QPushButton *pushButton;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QLabel *label_5;
    QLabel *label_change;
    QLabel *label_7;
    QLabel *label_deskno;

    void setupUi(QWidget *finalorder)
    {
    if (finalorder->objectName().isEmpty())
        finalorder->setObjectName(QString::fromUtf8("finalorder"));
    finalorder->resize(380, 480);
    label = new QLabel(finalorder);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(100, 10, 180, 30));
    QFont font;
    font.setPointSize(24);
    font.setUnderline(false);
    label->setFont(font);
    label->setAlignment(Qt::AlignCenter);
    tableView = new QTableView(finalorder);
    tableView->setObjectName(QString::fromUtf8("tableView"));
    tableView->setGeometry(QRect(30, 50, 320, 250));
    QFont font1;
    font1.setPointSize(10);
    tableView->setFont(font1);
    label_2 = new QLabel(finalorder);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setGeometry(QRect(30, 320, 40, 30));
    QFont font2;
    font2.setPointSize(12);
    label_2->setFont(font2);
    label_total = new QLabel(finalorder);
    label_total->setObjectName(QString::fromUtf8("label_total"));
    label_total->setGeometry(QRect(80, 320, 80, 30));
    label_total->setFont(font2);
    pushButton = new QPushButton(finalorder);
    pushButton->setObjectName(QString::fromUtf8("pushButton"));
    pushButton->setGeometry(QRect(250, 365, 100, 36));
    pushButton->setFont(font2);
    label_4 = new QLabel(finalorder);
    label_4->setObjectName(QString::fromUtf8("label_4"));
    label_4->setGeometry(QRect(30, 370, 40, 30));
    label_4->setFont(font2);
    lineEdit = new QLineEdit(finalorder);
    lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
    lineEdit->setGeometry(QRect(80, 368, 80, 36));
    lineEdit->setFont(font2);
    pushButton_2 = new QPushButton(finalorder);
    pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
    pushButton_2->setGeometry(QRect(250, 415, 100, 36));
    pushButton_2->setFont(font2);
    label_5 = new QLabel(finalorder);
    label_5->setObjectName(QString::fromUtf8("label_5"));
    label_5->setGeometry(QRect(30, 420, 40, 30));
    label_5->setFont(font2);
    label_change = new QLabel(finalorder);
    label_change->setObjectName(QString::fromUtf8("label_change"));
    label_change->setGeometry(QRect(80, 420, 80, 30));
    label_change->setFont(font2);
    label_7 = new QLabel(finalorder);
    label_7->setObjectName(QString::fromUtf8("label_7"));
    label_7->setGeometry(QRect(300, 20, 31, 20));
    QFont font3;
    font3.setPointSize(12);
    font3.setItalic(true);
    font3.setUnderline(false);
    label_7->setFont(font3);
    label_deskno = new QLabel(finalorder);
    label_deskno->setObjectName(QString::fromUtf8("label_deskno"));
    label_deskno->setGeometry(QRect(335, 20, 20, 20));
    QFont font4;
    font4.setPointSize(14);
    font4.setBold(true);
    font4.setItalic(true);
    font4.setWeight(75);
    label_deskno->setFont(font4);

    retranslateUi(finalorder);

    QMetaObject::connectSlotsByName(finalorder);
    } // setupUi

    void retranslateUi(QWidget *finalorder)
    {
    finalorder->setWindowTitle(QApplication::translate("finalorder", "Form", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("finalorder", "\346\270\205\345\215\225", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("finalorder", "\346\200\273\350\256\241", 0, QApplication::UnicodeUTF8));
    label_total->setText(QString());
    pushButton->setText(QApplication::translate("finalorder", "\344\273\230\346\254\276", 0, QApplication::UnicodeUTF8));
    label_4->setText(QApplication::translate("finalorder", "\345\256\236\344\273\230", 0, QApplication::UnicodeUTF8));
    pushButton_2->setText(QApplication::translate("finalorder", "\345\256\214\346\210\220", 0, QApplication::UnicodeUTF8));
    label_5->setText(QApplication::translate("finalorder", "\346\211\276\351\233\266", 0, QApplication::UnicodeUTF8));
    label_change->setText(QString());
    label_7->setText(QApplication::translate("finalorder", "No", 0, QApplication::UnicodeUTF8));
    label_deskno->setText(QApplication::translate("finalorder", "1", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(finalorder);
    } // retranslateUi

};

namespace Ui {
    class finalorder: public Ui_finalorder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINALORDER_H
