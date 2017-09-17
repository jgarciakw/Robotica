#include "ejemplo1.h"

ejemplo1::ejemplo1(): Ui_Counter()
{
  setupUi(this);
  show();
  connect(button, SIGNAL(clicked()), this, SLOT(doButton()) );
  
  timer = new QTimer();
  connect(timer, SIGNAL(timeout()), this, SLOT(doContador()));
  
  contador = 0;
  timer->start(1000);
}

ejemplo1::~ejemplo1()
{
  delete timer;
}

void ejemplo1::doButton()
{
  if (timer->isActive()){
    timer->stop();
    button->setText("Start");
  }
  else{
    timer->start(1000);
    button->setText("Stop");
  }
}

void ejemplo1::doContador()
{
  contador++;
  lcdNumber->display(contador);
}