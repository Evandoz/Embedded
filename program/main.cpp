#include <QtGui/QApplication>
#include "menu.h"
#include "connection.h"

#include "linuxpatch.h"
#include "driver_keyboard.h"

int main(int argc,char *argv[]){
  QApplication a(argc,argv);

  if(!createConnection())
    return 1;
  menu *w=new menu;
  w->show();
  BDDriver::getInstance()->start();
  return a.exec();
}
