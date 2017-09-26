#include "ejemplo1.h"

 
ejemplo1::ejemplo1(): Ui_Counter()
{
  setupUi(this);
  show();
  num=0;
  periodo = 1000000;
  
  mythread = std::move(std::thread(&hebra::run, hebra(),std::bind(&ejemplo1::tick,this)));
  connect(button, SIGNAL(clicked()),this,SLOT(doButton()));
  connect(restart, SIGNAL(clicked()),this,SLOT(restartContador()));
  
  connect(horizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(actualizarSlider()));
  connect(horizontalSlider, SIGNAL(sliderReleased()), this, SLOT(setPeriodo()));
}

ejemplo1::~ejemplo1(){
  mythread.detach();
}

void ejemplo1::doButton()
{
	
  if(!hilo.getparar()){
    hilo.setparar(true);
    button->setText("START");
  }
  else{
   hilo.setparar(false);
  button->setText("STOP");
  cv.notify_all();
  }
  
}

void ejemplo1::restartContador()
{
  num=0;
  lcdNumber->display(num);

}

void ejemplo1::actualizarSlider()
{
  lcdNumber_2->display(horizontalSlider->value());
}

void ejemplo1::setPeriodo()
{
  
  periodo = horizontalSlider->value() * 20000;
 
}


 void ejemplo1::tick()
{
    
   std::unique_lock<std::mutex> lk(cv_m); 
   
   while(hilo.getparar())
      cv.wait(lk);
   
   usleep(periodo);
   num++;
   lcdNumber->display(num);
    
}  




