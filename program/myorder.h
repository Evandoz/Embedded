#ifndef MYORDER_H
#define MYORDER_H

#include <QtGui/QWidget>
#include <QSqlQueryModel>
#include <QModelIndex>
#include "ui_myorder.h"
#include "ui_menu.h"

#include "driver_keyboard.h"

class myorder:public QWidget{
  Q_OBJECT
  public:
    myorder(QWidget *parent=0);
    ~myorder();
    QSqlQueryModel *model;
    QString str;
 
 private:
    Ui::myorder ui;
    //  Ui_menu menu;

  private slots:
    void Button_return_clicked();
    void search();
    void Button_delete();
    void Button_modify();
    void Button_refresh();
    void Button_clear();
    void Button_submit();
    void onBDGetKey(char mKey);
	 void RowClicked(const QModelIndex &index);
};

#endif
