#ifndef MENU_H
#define MENU_H

#include <QtGui/QWidget>
#include <QSqlQueryModel>
#include "ui_menu.h"

#include "driver.h"

class menu:public QWidget{
  Q_OBJECT
public:
  menu(QWidget *parent=0);
  ~menu();
  QSqlQueryModel *model;

private:
  Ui::menu ui;
  MyDriver *driver;

private slots:
  void timerUpDate(); 
  void search();  
  void Button_my_clicked();
  void Button_add_clicked();
};
#endif
