#include "myorder.h"
#include "menu.h"
#include "connection.h"
#include "finalorder.h"
#include <QTableView>
#include <QMessageBox>
#include <QHeaderView>
#include <QDesktopWidget>
#include <QModelIndex>
#include <QLineEdit>
#include <QString>

#include "driver_keyboard.h"

myorder::myorder(QWidget *parent):QWidget(parent)
{
  ui.setupUi(this);
  this->setFont(QFont("unifont",QFont::Normal));
    ui.tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

  QDesktopWidget *deskdop = QApplication::desktop();
  move((deskdop->width() - this->width())/2, (deskdop->height() - this->height())/2);

  // menu *m=new menu;
  // QString str= m->lineEdit->text();
  // ui.label_deskno->setText(str);
  // QString str=ui.label_deskno->Text();

  str=ui.label_deskno->text();
  QSqlQueryModel *model=new QSqlQueryModel();
  model->setQuery("SELECT menu.ID,Name,Price,Num FROM myorder,menu WHERE DeskNo='"+str+"' AND myorder.ID=menu.ID");
  /*model->insertColumn(4);
  model->setHeaderData(4,Qt::Horizontal,QObject::tr("Add"));
  model->insertColumn(5);
  model->setHeaderData(5,Qt::Horizontal,QObject::tr("Sub"));*/
  model->insertColumn(4);
  model->setHeaderData(4,Qt::Horizontal,QObject::tr("Del"));
  ui.tableView->setModel(model);

  for(int i=0;i<model->rowCount();i++)
  {
    /*QPushButton *addButton = new QPushButton(QObject::tr("Add"), this);
    QPushButton *subButton = new QPushButton(QObject::tr("Sub"), this);*/
    QPushButton *delButton = new QPushButton(QObject::tr("Del"), this);
    /*ui.tableView->setIndexWidget(model->index(i, 4), addButton);
    ui.tableView->setIndexWidget(model->index(i, 5), subButton);*/
    ui.tableView->setIndexWidget(model->index(i, 4), delButton);

    //connect(addButton,SIGNAL(clicked()),this,SLOT(Button_add_clicked()));
    //connect(subButton,SIGNAL(clicked()),this,SLOT(search()));
    connect(delButton,SIGNAL(clicked()),this,SLOT(Button_delete()));
  }

  ui.tableView->horizontalHeader()->setResizeMode(QHeaderView::Stretch);

  connect(ui.pushButton_6,SIGNAL(clicked()),this,SLOT(Button_return_clicked()));
  connect(ui.comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(search()));

  QSqlQuery query;
  query.exec("select distinct Type from myorder,menu WHERE myorder.ID=menu.ID");
  while(query.next())
  {
    ui.comboBox->addItem(query.value(0).toString());
  }


  connect(ui.pushButton_3,SIGNAL(clicked()),this,SLOT(Button_modify()));
  connect(ui.pushButton_4,SIGNAL(clicked()),this,SLOT(Button_refresh()));

  Button_refresh();

  connect(ui.pushButton_7,SIGNAL(clicked()),this,SLOT(Button_clear()));
  connect(ui.pushButton_5,SIGNAL(clicked()),this,SLOT(Button_submit()));
  connect(ui.tableView,SIGNAL(clicked(QModelIndex)),this,SLOT(RowClicked(QModelIndex)));	
  QObject::connect(BDDriver::getInstance(),SIGNAL(getKey(char)),this,SLOT(onBDGetKey(char)));
}

void myorder::search()
{
  QString s_type;
  s_type=ui.comboBox->currentText();
  model=new QSqlQueryModel();
  if(s_type=="Type all")
  {
    model->setQuery("SELECT menu.ID,Name,Price,Num FROM myorder,menu WHERE DeskNo='"+str+"' AND myorder.ID=menu.ID");
  }
  else
  {
    model->setQuery("SELECT menu.ID,Name,Price,Num FROM myorder,menu WHERE DeskNo='"+str+"' AND Type='"+s_type+"'AND myorder.ID=menu.ID");
  }
  model->insertColumn(4);
  /*model->setHeaderData(4,Qt::Horizontal,QObject::tr("Add"));
  model->insertColumn(5);
  model->setHeaderData(5,Qt::Horizontal,QObject::tr("Sub"));
  model->insertColumn(6); */ 
  model->setHeaderData(4,Qt::Horizontal,QObject::tr("Del"));
  ui.tableView->setModel(model);
 
  for(int i=0;i<model->rowCount();i++)
  {
    /*QPushButton *addButton = new QPushButton(QObject::tr("Add"), this);
    QPushButton *subButton = new QPushButton(QObject::tr("Sub"), this);*/
    QPushButton *delButton = new QPushButton(QObject::tr("Del"), this);
   
    /*ui.tableView->setIndexWidget(model->index(i, 4), addButton);
    ui.tableView->setIndexWidget(model->index(i, 5), subButton);*/
    ui.tableView->setIndexWidget(model->index(i, 4), delButton);
    
    //connect(addButton,SIGNAL(clicked()),this,SLOT(Button_add_clicked()));
    //connect(subButton,SIGNAL(clicked()),this,SLOT(Button_add_clicked()));
    connect(delButton,SIGNAL(clicked()),this,SLOT(Button_delete()));
  }
  ui.tableView->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
}

void myorder::Button_delete()
{
  QPushButton *delButton = qobject_cast<QPushButton *>(sender());
  int y = delButton->property("y").toInt();
  int row = ui.tableView->rowAt(y);
  QModelIndex id_index = ui.tableView->model()->index(row,0);
  QVariant data_id = ui.tableView->model()->data(id_index);
 
  QString s_id = data_id.toString();
 
  QString flag;
  QSqlQuery query;
  query.exec("select * from myorder where ID='"+s_id+"'");
  while(query.next())
  {
    flag=query.value(1).toString();
  }
  if(flag==0)
  {
    QMessageBox::information(this,"notice","No such Dishes!");
  }
  else
  {
    bool value;
    value=query.exec("delete from myorder where ID='"+s_id+"'");
    if(value)
    {
      QMessageBox::information(this,"notice","Delete Succeed!");
    }
    model=new QSqlQueryModel();
    model->setQuery("SELECT menu.ID,Name,Price,Num FROM myorder,menu WHERE DeskNo='"+str+"' AND myorder.ID=menu.ID");
    model->insertColumn(4);
    /*model->setHeaderData(4,Qt::Horizontal,QObject::tr("Add"));
    model->insertColumn(5);
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Sub"));
    model->insertColumn(6);*/
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Del"));
    ui.tableView->setModel(model);

    for(int i=0;i<model->rowCount();i++)
    {
      /*QPushButton *addButton = new QPushButton(QObject::tr("Add"), this);
      QPushButton *subButton = new QPushButton(QObject::tr("Sub"), this);*/
      QPushButton *delButton = new QPushButton(QObject::tr("Del"), this);
      /*ui.tableView->setIndexWidget(model->index(i, 4), addButton);
      ui.tableView->setIndexWidget(model->index(i, 5), subButton);*/
      ui.tableView->setIndexWidget(model->index(i, 4), delButton);

      //connect(addButton,SIGNAL(clicked()),this,SLOT(Button_add_clicked()));
      //connect(delButton,SIGNAL(clicked()),this,SLOT(search()));
      connect(delButton,SIGNAL(clicked()),this,SLOT(Button_delete()));
    }
  }
}

void myorder::RowClicked(const QModelIndex &index){
	int row= index.row();
   QModelIndex ind = ui.tableView->model()->index(row,0);//选中行第一列的内容
   QVariant data = ui.tableView->model()->data(ind);
	QString id = data.toString();
	ui.lineEdit->setText(id);
}



void myorder::Button_modify()
{
  QString s_id,s_num,flag;
  QSqlQuery query;
  bool ok;
  s_id=ui.lineEdit->text();
  s_num=ui.lineEdit_3->text();
  int n = s_num.toInt(&ok);
  if(n==0)
  {
    QMessageBox::information(this,"notice","Not allowed!");
  }
  else
  {
    query.exec("select * from myorder where ID='"+s_id+"'");
    while(query.next())
    {
      flag=query.value(1).toString();
    }
    if(flag==0)
    {
      QMessageBox::information(this,"notice","No such Dishes!");
    }
    else
    {
      bool value;
      value=query.exec("UPDATE myorder SET Num='"+s_num+"' WHERE ID='"+s_id+"'");
      if(value)
      {
        QMessageBox::information(this,"notice","Modify Succeed!");
      }
    }
    model=new QSqlQueryModel();
    model->setQuery("SELECT menu.ID,Name,Price,Num FROM myorder,menu WHERE DeskNo='"+str+"' AND myorder.ID=menu.ID");
    model->insertColumn(4);
    /*model->setHeaderData(4,Qt::Horizontal,QObject::tr("Add"));
    model->insertColumn(5);
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Sub"));
    model->insertColumn(6);*/
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Del"));
    ui.tableView->setModel(model);
    
    for(int i=0;i<model->rowCount();i++)
    {
      /*QPushButton *addButton = new QPushButton(QObject::tr("Add"), this);
      QPushButton *subButton = new QPushButton(QObject::tr("Sub"), this);*/
      QPushButton *delButton = new QPushButton(QObject::tr("Del"), this);
    
      /*ui.tableView->setIndexWidget(model->index(i, 4), addButton);
      ui.tableView->setIndexWidget(model->index(i, 5), subButton);*/
      ui.tableView->setIndexWidget(model->index(i, 4), delButton);

      //connect(addButton,SIGNAL(clicked()),this,SLOT(Button_add_clicked()))    ;
      //connect(delButton,SIGNAL(clicked()),this,SLOT(search()));
      connect(delButton,SIGNAL(clicked()),this,SLOT(Button_delete()));
    }
  }
}

void myorder::onBDGetKey(char mKey){
	printf("in addDlg getkey:%c\n",mKey);
	QLineEdit *lineEdit1=ui.lineEdit_3;
	if(!lineEdit1->hasFocus()){
		return;//current not focus 
	}
	//current focus 	
	QString str=lineEdit1->text();
 	if(mKey>='0' && mKey<='9')
	{
		str+=QString(mKey);
		lineEdit1->setText(str);
	}
	else if (mKey==0x7F)
	{	
		int l=str.length();
		if(l>=1)
		{
			str=str.left(l-1);
		}
		else
		{
			QMessageBox::information(this,"Notice","Empty input!");
		}
	}
	else if (mKey=='+')
	{
		str = QString::number(str.toInt()+1);
		lineEdit1->setText(str);
	}
	else if (mKey=='-')
	{	
		int tmp = str.toInt();
		if (tmp>=1)
		{
			str = QString::number(tmp-1);
			lineEdit1->setText(str);
		}
		else 
		{	
			QMessageBox::information(this,"Notice","Invalid Operation!");
		}
	}
	else if (mKey==13)
	{
		Button_modify();
	}
	else
	{
		QMessageBox::information(this,"Notice","Invalid Operation!");
	}
}

void myorder::Button_refresh()
{
  double sum=0;
  QSqlQuery query;
  query.exec("select Price,Num from myorder,menu where menu.ID=myorder.ID AND DeskNo='"+str+"'");
  while(query.next())
  {
    sum = sum + query.value(0).toDouble() * query.value(1).toInt();
  }
  QString total=QString("%1").arg(sum);
  ui.label_total->setText(total);
}

void myorder::Button_clear()
{
  QSqlQuery query;
  QString s_no=ui.label_deskno->text();
  QMessageBox msgBox;
  msgBox.setText("This could clear all you have ordered!");
  msgBox.setInformativeText("Do you want to order again?");
  msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
  msgBox.setDefaultButton(QMessageBox::No);
  int ret = msgBox.exec();
  switch(ret)
  {
    case QMessageBox::Yes:
      {
        query.exec("delete from myorder where DeskNo='"+s_no+"'");
        Button_return_clicked();
      }
      break;
    case QMessageBox::No:
      break;
    default:
      break;
  }
}

void myorder::Button_submit()
{
  QMessageBox msgBox;
  msgBox.setText("This could lead to your final ordered!");
  msgBox.setInformativeText("Do you want to submit?");
  msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
  msgBox.setDefaultButton(QMessageBox::No);
  int ret = msgBox.exec();
  switch(ret)
  {
    case QMessageBox::Yes:
      {
        finalorder * final_order=new finalorder();
        final_order->show();
        this->close();
      }
      break;
    case QMessageBox::No:
      break;
    default:
      break;
  }
}

void myorder::Button_return_clicked()
{
  menu *w = new menu;
  w->show();
  this->close();
}

myorder::~myorder()
{

}
