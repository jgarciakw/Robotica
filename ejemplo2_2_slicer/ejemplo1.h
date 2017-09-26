#ifndef ejemplo1_H
#define ejemplo1_H
#include <QtGui>
#include "ui_counterDlg.h"
#include "hebra.h"
#include <thread>
#include <functional>
#include <condition_variable>


class ejemplo1 : public QWidget, public Ui_Counter
{
Q_OBJECT

private:
  hebra hilo;
  std::thread mythread;
  std::condition_variable cv;
  std::mutex cv_m;
  int periodo;
  int num;
    
public:
    
  ejemplo1();
  virtual ~ejemplo1();
    
public slots:
  void doButton();
  void tick();
  void restartContador();
  void actualizarSlider();
  void setPeriodo(); 
};

#endif // ejemplo1_H
