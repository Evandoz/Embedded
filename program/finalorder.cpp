#include "finalorder.h"
#include "myorder.h"
#include "connection.h"
#include "menu.h"
#include <QTableView>
#include <QMessageBox>
#include <QHeaderView>
#include <QDesktopWidget>
#include <QLineEdit>
#include <QString>
#include "driver_keyboard.h"

finalorder::finalorder(QWidget *parent):QWidget(parent)
{
  ui.setupUi(this);
  this->setFont(QFont("unifont",QFont::Normal));

  QDesktopWidget *deskdop = QApplication::desktop();
  move((deskdop->width() - this->width())/2, (deskdop->height() - this->height())/2);
  ui.pushButton_2->hide();
  QString str=ui.label_deskno->text();
  QSqlQueryModel *model = new QSqlQueryModel();
  model->setQuery("select Name,Price,Num from myorder,menu where menu.ID=myorder.ID AND DeskNo='"+str+"'");
  ui.tableView->setModel(model);
  ui.tableView->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
  double sum=0;
  QSqlQuery query;
  query.exec("select Price,Num from myorder,menu where myorder.ID=menu.ID AND DeskNo='"+str+"'");
  while(query.next())
  {
    sum = sum + query.value(0).toDouble() * query.value(1).toInt();
  }
  QString total=QString("%1").arg(sum);
  ui.label_total->setText(total);

  connect(ui.pushButton,SIGNAL(clicked()),this,SLOT(Button_pay()));
  connect(ui.pushButton_2,SIGNAL(clicked()),this,SLOT(Button_end()));  
  QObject::connect(BDDriver::getInstance(),SIGNAL(getKey(char)),this,SLOT(onBDGetKey(char)));
}

void finalorder::onBDGetKey(char mKey){
	printf("in addDlg getkey:%c\n",mKey);
	QLineEdit *lineEdit=ui.lineEdit;
	if(!lineEdit->hasFocus()){
		return;//current not focus 
	}
	//current focus 	
	QString str=lineEdit->text();
 	if(mKey>='0' && mKey<='9')
	{
		str+=QString(mKey);
		lineEdit->setText(str);
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
		lineEdit->setText(str);
	}
	else if (mKey=='-')
	{	
		int tmp = str.toInt();
		if (tmp>=1)
		{
			str = QString::number(tmp-1);
			lineEdit->setText(str);
		}
		else 
		{	
			QMessageBox::information(this,"Notice","Invalid Operation!");
		}
	}
	else if (mKey==13)
	{
		Button_pay();
	}
	else
	{
		QMessageBox::information(this,"Notice","Invalid Operation!");
	}
}

void finalorder::Button_pay()
{
  bool ok;
  // ui.pushButton_2->show();
  QString str=ui.lineEdit->text();
  double s = str.toDouble(&ok);
  if(s==0)
  {
    QMessageBox::information(this,"Notice","Please input the Cash Text first!");
  }
  else
  {
    // ui.pushButton_2->show();
    QString total=ui.label_total->text();
    double d = total.toDouble(&ok);
    // double s = str.toDouble(&ok);
    if(s>d)
    {
      double left = s - d;
      QString change = QString("%1").arg(left);
      ui.label_change->setText(change);
      ui.pushButton_2->show();
    }
    else
    {
      QMessageBox::information(this,"Notice","Please input the right Cash!");
    }
  }
}

void finalorder::Button_end()
{
  QSqlQuery query;
  QString deskno=ui.label_deskno->text();
  query.exec("delete from myorder where DeskNo='"+deskno+"'");
  QMessageBox::information(this,"Thank You","Have a nice day!");
  this->close();
  menu *w = new menu();
  w->show();
}

finalorder::~finalorder()
{

}
