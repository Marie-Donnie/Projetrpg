  /**
   * @name  traiter
   * @brief Méthode passer de l'observer
   * @param m une référence vers le membre
   * Passe le membre à son suivant dans la chaîne
   */

  /**
   * @name  passer
   * @brief Méthode passer de l'observer
   * @param m une référence vers le membre
   * Passe le membre à son suivant dans la chaîne
   */



//include guard
#ifndef OBSERVER_HPP
#define OBSERVER_HPP

//forward declaration
class Membre;
class PNJ;

//included dependencies
#include <cstdlib>

class Observer{

protected:
  Observer* suiv;

public:
  virtual void traiter(Membre& m, int pv)=0;
  virtual void passer(Membre& m);
  virtual void personnageMort();
  virtual void pnjMort(PNJ& p);

};

#endif //OBSERVER_HPP
