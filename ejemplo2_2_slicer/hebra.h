#ifndef HEBRA_H
#define HEBRA_H
#include <unistd.h>
#include <functional>

class hebra
{
 
private:
  bool parar;
  
public:
  
  
  void run(std::function<void()> tick );

  bool getparar();
  void setparar(bool stop);
  hebra();
  
  ~hebra();

  
};

#endif // HEBRA_H
