#ifndef ejemplo1_H
#define ejemplo1_H

#include <QtGui>
#include "ui_counterDlg.h"

#include <QTimer>

class Hilo : public QThread
{
    Q_OBJECT
    void run() {
      while(true){
	sleep(1);
        emit SenalHilo();
      }
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
