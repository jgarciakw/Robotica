#include "hebra.h"

hebra::hebra()
{
  parar = false;
}

hebra::~hebra(){}


void hebra::run( std::function<void()> tick )
{
 
  while(true){
    tick();
  }
 
}

bool hebra::getparar()
{
  return parar;
}

void hebra::setparar(bool stop)
{
  parar = stop;
}




