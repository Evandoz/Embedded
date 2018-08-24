/********************************************************************************
** Form generated from reading ui file 'myorder.ui'
**
** Created: Thu Jul 13 08:32:44 2017
**      by: Qt User Interface Compiler version 4.4.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MYORDER_H
#define UI_MYORDER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTableView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_myorder
{
public:
    QLabel *label_1;
    QTableView *tableView;
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_3;
    QWidget *horizontalLayout;
    QHBoxLayout *hboxLayout;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_3;
    QLabel *label_total;
    QPushButton *pushButton_4;
    QLabel *label_2;
    QLabel *label_deskno;

    void setupUi(QWidget *myorder)
    {
    if (myorder->objectName().isEmpty())
        myorder->setObjectName(QString::fromUtf8("myorder"));
    myorder->resize(640, 480);
    label_1 = new QLabel(myorder);
    label_1->setObjectName(QString::fromUtf8("label_1"));
    label_1->setGeometry(QRect(200, 12, 240, 32));
    QFont font;
    font.setFamily(QString::fromUtf8("Bitstream Charter"));
    font.setPointSize(24);
    label_1->setFont(font);
    label_1->setAlignment(Qt::AlignCenter);
    tableView = new QTableView(myorder);
    tableView->setObjectName(QString::fromUtf8("tableView"));
    tableView->setGeometry(QRect(30, 90, 580, 230));
    QFont font1;
    font1.setPointSize(10);
    tableView->setFont(font1);
    comboBox = new QComboBox(myorder);
    comboBox->setObjectName(QString::fromUtf8("comboBox"));
    comboBox->setGeometry(QRect(30, 45, 120, 30));
    QFont font2;
    font2.setPointSize(12);
    comboBox->setFont(font2);
    lineEdit = new QLineEdit(myorder);
    lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
    lineEdit->setGeometry(QRect(295, 345, 70, 36));
    lineEdit->setFont(font2);
    lineEdit_3 = new QLineEdit(myorder);
    lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
    lineEdit_3->setGeometry(QRect(440, 345, 70, 36));
    lineEdit_3->setFont(font2);
    horizontalLayout = new QWidget(myorder);
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    horizontalLayout->setGeometry(QRect(-10, 110, 2, 2));
    hboxLayout = new QHBoxLayout(horizontalLayout);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    hboxLayout->setContentsMargins(0, 0, 0, 0);
    pushButton_3 = new QPushButton(myorder);
    pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
    pushButton_3->setGeometry(QRect(530, 345, 80, 36));
    pushButton_3->setFont(font2);
    pushButton_5 = new QPushButton(myorder);
    pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
    pushButton_5->setGeometry(QRect(490, 400, 120, 36));
    QFont font3;
    font3.setPointSize(13);
    pushButton_5->setFont(font3);
    pushButton_6 = new QPushButton(myorder);
    pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
    pushButton_6->setGeometry(QRect(30, 400, 120, 36));
    pushButton_6->setFont(font2);
    pushButton_7 = new QPushButton(myorder);
    pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
    pushButton_7->setGeometry(QRect(180, 400, 120, 36));
    pushButton_7->setFont(font2);
    label_5 = new QLabel(myorder);
    label_5->setObjectName(QString::fromUtf8("label_5"));
    label_5->setGeometry(QRect(240, 345, 40, 36));
    label_5->setFont(font2);
    label_5->setAlignment(Qt::AlignCenter);
    label_6 = new QLabel(myorder);
    label_6->setObjectName(QString::fromUtf8("label_6"));
    label_6->setGeometry(QRect(385, 345, 40, 36));
    label_6->setFont(font2);
    label_6->setAlignment(Qt::AlignCenter);
    label_3 = new QLabel(myorder);
    label_3->setObjectName(QString::fromUtf8("label_3"));
    label_3->setGeometry(QRect(36, 345, 36, 36));
    label_3->setFont(font2);
    label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
    label_total = new QLabel(myorder);
    label_total->setObjectName(QString::fromUtf8("label_total"));
    label_total->setGeometry(QRect(90, 345, 120, 36));
    label_total->setFont(font2);
    pushButton_4 = new QPushButton(myorder);
    pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
    pushButton_4->setGeometry(QRect(340, 400, 120, 36));
    pushButton_4->setFont(font2);
    label_2 = new QLabel(myorder);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setGeometry(QRect(530, 50, 40, 30));
    QFont font4;
    font4.setPointSize(12);
    font4.setItalic(true);
    font4.setUnderline(false);
    label_2->setFont(font4);
    label_2->setAlignment(Qt::AlignCenter);
    label_deskno = new QLabel(myorder);
    label_deskno->setObjectName(QString::fromUtf8("label_deskno"));
    label_deskno->setGeometry(QRect(580, 50, 30, 30));
    QFont font5;
    font5.setPointSize(14);
    font5.setBold(true);
    font5.setItalic(true);
    font5.setWeight(75);
    label_deskno->setFont(font5);

    retranslateUi(myorder);

    QMetaObject::connectSlotsByName(myorder);
    } // setupUi

    void retranslateUi(QWidget *myorder)
    {
    myorder->setWindowTitle(QApplication::translate("myorder", "My order", 0, QApplication::UnicodeUTF8));
    label_1->setText(QApplication::translate("myorder", "\347\241\256\350\256\244\350\256\242\345\215\225", 0, QApplication::UnicodeUTF8));
    comboBox->insertItems(0, QStringList()
     << QApplication::translate("myorder", "Type all", 0, QApplication::UnicodeUTF8)
    );
    pushButton_3->setText(QApplication::translate("myorder", "\344\277\256\346\224\271", 0, QApplication::UnicodeUTF8));
    pushButton_5->setText(QApplication::translate("myorder", "\346\217\220\344\272\244", 0, QApplication::UnicodeUTF8));
    pushButton_6->setText(QApplication::translate("myorder", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
    pushButton_7->setText(QApplication::translate("myorder", "\346\270\205\347\251\272", 0, QApplication::UnicodeUTF8));
    label_5->setText(QApplication::translate("myorder", "\347\274\226\345\217\267", 0, QApplication::UnicodeUTF8));
    label_6->setText(QApplication::translate("myorder", "\346\225\260\351\207\217", 0, QApplication::UnicodeUTF8));
    label_3->setText(QApplication::translate("myorder", "\346\200\273\350\256\241", 0, QApplication::UnicodeUTF8));
    label_total->setText(QString());
    pushButton_4->setText(QApplication::translate("myorder", "\345\210\267\346\226\260", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("myorder", "No", 0, QApplication::UnicodeUTF8));
    label_deskno->setText(QApplication::translate("myorder", "1", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(myorder);
    } // retranslateUi

};

namespace Ui {
    class myorder: public Ui_myorder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYORDER_H
