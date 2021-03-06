#ifndef CONNECTION_H
#define CONNECTION_H

#include <QApplication>
#include <QtSql>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

static bool createConnection(){
  QSqlDatabase db= QSqlDatabase::addDatabase("QSQLITE");
  db.setDatabaseName("/mnt/nfs/boa/cgi-bin/sqlite/menu.db");
  
  if(!db.open()){
    QMessageBox::critical(0,qApp->tr("Cannot open database"),qApp->tr("Unable to establish a database connection.\n"),QMessageBox::Cancel);
  return false;
  }

  return true;  
}
#endif
