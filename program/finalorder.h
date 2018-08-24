#ifndef FINALORDER_H
#define FINALORDER_H
                                                                                
#include<QtGui/QWidget>
#include<QSqlQueryModel>
#include"ui_myorder.h"
#include"ui_menu.h"
#include"ui_finalorder.h"

#include "driver_keyboard.h"

class finalorder:public QWidget{
  Q_OBJECT
  public:
    finalorder(QWidget *parent=0);
    ~finalorder();
    QSqlQueryModel *model;
  private:
    Ui::finalorder ui;
  //  Ui_menu menu;
  private slots:
    void Button_pay();
    void Button_end();
    void onBDGetKey(char mKey);
};
                                                                                
#endif

