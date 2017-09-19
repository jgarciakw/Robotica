#ifndef ejemplo1_H
#define ejemplo1_H

#include <QtGui>
#include "ui_counterDlg.h"

#include <QTimer>

class Hilo : public QThread
{
    Q_OBJECT
    
    bool contando = true;
    
    void run() {
      while(true){
	sleep(1);
	if (contando ==true){
	  emit SenalHilo();
	}
      }
    }
    
public:
    void parar(){
      contando = false;
    }
    
    void arrancar(){
      contando = true;
    }
    
    bool estaContando(){
      return contando;
    }
    
signals:
    void SenalHilo();
};

class ejemplo1 : public QWidget, public Ui_Counter
{
  Q_OBJECT
  public:
    
    Hilo *hilo;
    int contador;
    
    ejemplo1();
    virtual ~ejemplo1();
      
  public slots:
    void doButton();
    void doContador();
    
};

#endif // ejemplo1_H
