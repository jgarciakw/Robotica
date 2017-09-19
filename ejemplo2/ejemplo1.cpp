#include "ejemplo1.h"



ejemplo1::ejemplo1(): Ui_Counter()
{
  
  setupUi(this);
  show();
  connect(button, SIGNAL(clicked()), this, SLOT(doButton()) );
  
  contador = 0;
  
  hilo = new Hilo();
  hilo->start();
  
  connect(hilo, SIGNAL(SenalHilo()), this, SLOT(doContador()));
  
}

ejemplo1::~ejemplo1()
{
   delete hilo;
}

void ejemplo1::doButton()
{
  if (hilo->estaContando()){
    hilo->parar();
    button->setText("Start");
  }
  else{
    hilo->arrancar();
    button->setText("Stop");
  }
}

void ejemplo1::doContador()
{
  contador++;
  lcdNumber->display(contador);
}