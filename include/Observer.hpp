#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <cstdlib>

class Membre;

class Observer{

private:
  Observer* _suiv;
  Observer* _prec;

public:
  virtual void traiter(Membre m)=0;
  virtual void passer(Membre m);


};

#endif //OBSERVER_HPP
