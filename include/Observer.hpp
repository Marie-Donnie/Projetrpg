#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <cstdlib>

class Membre;

class Observer{

protected:
  Observer* suiv;

public:
  virtual void traiter(Membre& m, int pv)=0;
  virtual void passer(Membre& m);


};

#endif //OBSERVER_HPP
