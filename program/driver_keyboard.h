#ifndef __DRIVER_KEYBOARD_H__
#define __DRIVER_KEYBOARD_H__

#include <QObject>
#include <QTimer>

class BDDriver:public QObject{
	Q_OBJECT
	public:
		static BDDriver* getInstance();
	private:
		static BDDriver* mInstance;//singleton
		BDDriver();// private access
		~BDDriver();
	signals:
		void getKey(char key);
	private slots:
		void onTimeOut();
	public:
		void start();

	private:
		QTimer *timer;
};
#endif

