#include "driver_keyboard.h"
extern "C"{
#include "get_key.h"
}

BDDriver* BDDriver::mInstance=new BDDriver();//init mInstance

BDDriver*  BDDriver::getInstance(){
	return mInstance;
}

BDDriver::BDDriver(){
	timer=new QTimer();
	timer->setInterval(200);
	QObject::connect(timer,SIGNAL(timeout()),this,SLOT(onTimeOut()));
}

BDDriver::~BDDriver(){
	timer->stop();
	delete timer;
	delete mInstance;
}

void BDDriver::start(){
	int res=kbd_init();
	if(res!=0){
		return;
	}
	timer->start();
}

void BDDriver::onTimeOut(){
	char mKey=get_key();
	if(mKey!=0){
		printf("get key:%c\n",mKey);
		emit getKey(mKey);
	}
}

