#ifndef ejemplo1_H
#define ejemplo1_H

#include <QtGui>
#include "ui_counterDlg.h"

#include <QTimer>

class ejemplo1 : public QWidget, public Ui_Counter
{
  Q_OBJECT
  public:
    
    QTimer *timer;
    int contador;
    
    ejemplo1();
    virtual ~ejemplo1();
      
  public slots:
    void doButton();
    void doContador();
    
};

#endif // ejemplo1_H
