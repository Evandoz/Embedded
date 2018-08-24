/********************************************************************************
** Form generated from reading ui file 'menu.ui'
**
** Created: Thu Jul 13 08:32:30 2017
**      by: Qt User Interface Compiler version 4.4.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTableView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_menu
{
public:
    QLabel *label_1;
    QComboBox *comboBox;
    QLabel *label_2;
    QTableView *tableView;
    QLabel *label_5;
    QLineEdit *lineEdit_1;
    QLabel *label_7;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton;
    QLabel *label_8;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QLabel *label_6;
    QLabel *label_3;

    void setupUi(QWidget *menu)
    {
    if (menu->objectName().isEmpty())
        menu->setObjectName(QString::fromUtf8("menu"));
    menu->resize(640, 480);
    QFont font;
    font.setPointSize(10);
    menu->setFont(font);
    label_1 = new QLabel(menu);
    label_1->setObjectName(QString::fromUtf8("label_1"));
    label_1->setGeometry(QRect(260, 5, 120, 41));
    QFont font1;
    font1.setFamily(QString::fromUtf8("Bitstream Charter"));
    font1.setPointSize(24);
    label_1->setFont(font1);
    label_1->setAlignment(Qt::AlignCenter);
    comboBox = new QComboBox(menu);
    comboBox->setObjectName(QString::fromUtf8("comboBox"));
    comboBox->setGeometry(QRect(30, 75, 120, 30));
    QFont font2;
    font2.setPointSize(12);
    comboBox->setFont(font2);
    comboBox->setEditable(false);
    label_2 = new QLabel(menu);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setGeometry(QRect(180, 45, 280, 25));
    QFont font3;
    font3.setPointSize(12);
    font3.setItalic(true);
    label_2->setFont(font3);
    label_2->setAlignment(Qt::AlignCenter);
    tableView = new QTableView(menu);
    tableView->setObjectName(QString::fromUtf8("tableView"));
    tableView->setGeometry(QRect(30, 120, 580, 230));
    label_5 = new QLabel(menu);
    label_5->setObjectName(QString::fromUtf8("label_5"));
    label_5->setGeometry(QRect(30, 365, 41, 30));
    QFont font4;
    font4.setPointSize(12);
    font4.setItalic(false);
    font4.setUnderline(false);
    label_5->setFont(font4);
    lineEdit_1 = new QLineEdit(menu);
    lineEdit_1->setObjectName(QString::fromUtf8("lineEdit_1"));
    lineEdit_1->setGeometry(QRect(80, 365, 65, 30));
    lineEdit_1->setFont(font2);
    label_7 = new QLabel(menu);
    label_7->setObjectName(QString::fromUtf8("label_7"));
    label_7->setGeometry(QRect(495, 365, 35, 30));
    label_7->setFont(font4);
    lineEdit_3 = new QLineEdit(menu);
    lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
    lineEdit_3->setGeometry(QRect(545, 365, 65, 30));
    lineEdit_3->setFont(font2);
    lineEdit_3->setFrame(true);
    lineEdit_3->setReadOnly(true);
    pushButton = new QPushButton(menu);
    pushButton->setObjectName(QString::fromUtf8("pushButton"));
    pushButton->setGeometry(QRect(200, 410, 240, 40));
    QFont font5;
    font5.setPointSize(11);
    pushButton->setFont(font5);
    label_8 = new QLabel(menu);
    label_8->setObjectName(QString::fromUtf8("label_8"));
    label_8->setGeometry(QRect(580, 75, 30, 30));
    QFont font6;
    font6.setPointSize(14);
    font6.setBold(true);
    font6.setItalic(true);
    font6.setWeight(75);
    label_8->setFont(font6);
    label_4 = new QLabel(menu);
    label_4->setObjectName(QString::fromUtf8("label_4"));
    label_4->setEnabled(true);
    label_4->setGeometry(QRect(540, 75, 31, 30));
    QFont font7;
    font7.setPointSize(12);
    font7.setItalic(true);
    font7.setUnderline(false);
    label_4->setFont(font7);
    lineEdit_2 = new QLineEdit(menu);
    lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
    lineEdit_2->setGeometry(QRect(260, 365, 160, 30));
    lineEdit_2->setFont(font2);
    label_6 = new QLabel(menu);
    label_6->setObjectName(QString::fromUtf8("label_6"));
    label_6->setGeometry(QRect(210, 365, 45, 30));
    label_6->setFont(font2);
    label_3 = new QLabel(menu);
    label_3->setObjectName(QString::fromUtf8("label_3"));
    label_3->setGeometry(QRect(180, 75, 280, 30));
    label_3->setFont(font2);
    label_3->setAlignment(Qt::AlignCenter);

    retranslateUi(menu);

    QMetaObject::connectSlotsByName(menu);
    } // setupUi

    void retranslateUi(QWidget *menu)
    {
    menu->setWindowTitle(QApplication::translate("menu", "menu", 0, QApplication::UnicodeUTF8));
    label_1->setText(QApplication::translate("menu", "\350\217\234\345\215\225", 0, QApplication::UnicodeUTF8));
    comboBox->insertItems(0, QStringList()
     << QApplication::translate("menu", "Type all", 0, QApplication::UnicodeUTF8)
    );
    label_2->setText(QApplication::translate("menu", "\346\254\242\350\277\216\345\205\211\344\270\264\357\274\214\347\245\235\346\202\250\347\224\250\351\244\220\346\204\211\345\277\253\357\274\201", 0, QApplication::UnicodeUTF8));
    label_5->setText(QApplication::translate("menu", "\347\274\226\345\217\267", 0, QApplication::UnicodeUTF8));
    label_7->setText(QApplication::translate("menu", "\346\225\260\351\207\217", 0, QApplication::UnicodeUTF8));
    lineEdit_3->setText(QString());
    pushButton->setText(QApplication::translate("menu", "\350\256\242\345\215\225\351\242\204\350\247\210", 0, QApplication::UnicodeUTF8));
    label_8->setText(QApplication::translate("menu", "1", 0, QApplication::UnicodeUTF8));
    label_4->setText(QApplication::translate("menu", "No", 0, QApplication::UnicodeUTF8));
    label_6->setText(QApplication::translate("menu", "\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
    label_3->setText(QString());
    Q_UNUSED(menu);
    } // retranslateUi

};

namespace Ui {
    class menu: public Ui_menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
