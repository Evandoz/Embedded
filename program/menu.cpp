#include "menu.h"
#include "connection.h"
#include "myorder.h"
#include <QTableView>
#include <QMessageBox>
#include <QHeaderView>
#include <QDesktopWidget>

#include "driver.h"

menu::menu(QWidget *parent):QWidget(parent)
{
  ui.setupUi(this);
  this->setFont(QFont("unifont",QFont::Normal));
  
  QDesktopWidget *deskdop = QApplication::desktop();
  move((deskdop->width() - this->width())/2, (deskdop->height() - this->height())/2);

  QTimer *timer = new QTimer(this);
  connect(timer,SIGNAL(timeout()),this,SLOT(timerUpDate()));
  timer->start(1000);

  QSqlQueryModel *model=new QSqlQueryModel();
  model->setQuery("SELECT * FROM menu");
  model->insertColumn(4);
  model->setHeaderData(4,Qt::Horizontal,QObject::tr("Add"));
  /*model->insertColumn(5);
  model->setHeaderData(5,Qt::Horizontal,QObject::tr("Del"));*/

  ui.tableView->setModel(model);

  for(int i=0;i<model->rowCount();i++)
  {
    QPushButton *addButton = new QPushButton(QObject::tr("Add"), this);
    //QPushButton *delButton = new QPushButton(QObject::tr("Del"), this);
    ui.tableView->setIndexWidget(model->index(i, 4), addButton);
    //ui.tableView->setIndexWidget(model->index(i, 5), delButton);

    connect(addButton,SIGNAL(clicked()),this,SLOT(Button_add_clicked()));
    //connect(delButton,SIGNAL(clicked()),this,SLOT(search()));
  }

  ui.tableView->horizontalHeader()->setResizeMode(QHeaderView::Stretch);

  connect(ui.comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(search()));

  connect(ui.pushButton,SIGNAL(clicked()),this,SLOT(Button_my_clicked()));

  QString value;
  QSqlQuery query;
  query.exec("SELECT DISTINCT Type FROM menu");
  while(query.next())
  {
    value =  query.value(0).toString();
    ui.comboBox->addItem(value);
  }
   driver=new MyDriver();
}


void menu::timerUpDate(){
  QDateTime time=QDateTime::currentDateTime();
  QString str=time.toString("yyyy-MM-dd hh:mm:ss dddd");
  ui.label_3->setText(str);
}


void menu::search(){
  QString s_type;
  s_type=ui.comboBox->currentText();
  model=new QSqlQueryModel();
  if(s_type=="Type all")
  {
    model->setQuery("select * from menu");
  }
  else
  {
    model->setQuery("select * from menu where Type='"+s_type+"'");
  }
  model->insertColumn(4);
  model->setHeaderData(4,Qt::Horizontal,QObject::tr("Add"));
  //model->insertColumn(5);
  //model->setHeaderData(5,Qt::Horizontal,QObject::tr("Del"));
  ui.tableView->setModel(model);

  for(int i=0;i<model->rowCount();i++)
  {
    QPushButton *addButton = new QPushButton(QObject::tr("Add"), this);
    //QPushButton *delButton = new QPushButton(QObject::tr("Del"), this);
    ui.tableView->setIndexWidget(model->index(i, 4), addButton);
    //ui.tableView->setIndexWidget(model->index(i, 5), delButton);

    connect(addButton,SIGNAL(clicked()),this,SLOT(Button_add_clicked()));
    //connect(delButton,SIGNAL(clicked()),this,SLOT(search()));
 }
}

void menu::Button_my_clicked()
{
  myorder *my_order=new myorder();
  my_order->show();
  // QLabel *label_deskno;
  // label_deskno=new QLabel(my_order);
  // QString deskno= ui.lineEdit->text();
  // my_order->label_deskno->setText(deskno);
  // my_order->show();
  this->close();
}

void menu::Button_add_clicked()
{
  QPushButton *addButton = qobject_cast<QPushButton *>(sender());
  int y = addButton->property("y").toInt();
  int row = ui.tableView->rowAt(y);
  QModelIndex id_index = ui.tableView->model()->index(row,0);
  QModelIndex name_index = ui.tableView->model()->index(row,1);
  QVariant data_id = ui.tableView->model()->data(id_index);
  QVariant data_name = ui.tableView->model()->data(name_index);
  QString id = data_id.toString();
  QString name = data_name.toString();

  int led = data_id.toInt();
     driver->toggleDigLed(led);

  ui.lineEdit_1->setText(id);
  ui.lineEdit_2->setText(name);

  QString num,deskno,flag;
  QSqlQuery query;

  deskno=ui.label_8->text();

  query.exec("SELECT Num FROM myorder WHERE DeskNo = '"+deskno+"' AND ID = '"+id+"'");

  if(query.next())
  {
  	int value = query.value(0).toInt();
    num = QString::number((++value), 10);
    ui.lineEdit_3->setText(num);
    query.exec("UPDATE myorder SET Num='"+num+"' WHERE DeskNo = '" + deskno + "' AND ID = '" + id+"'");
  }
  else
  {
    num = "1";
    ui.lineEdit_3->setText(num);
    query.exec("INSERT INTO myorder (Num,DeskNo,ID) VALUES ('"+num+"','"+deskno+"','"+id+"')");
  }

  /*if(value)
  {
    QMessageBox::information(this,"Notice","Added!");
  }
  else
  {
    QMessageBox::information(this,"Notice","Ordered!");
  }*/
}

menu::~menu()
{

}

