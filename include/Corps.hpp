  /**
   * @name  Constructeur par défaut
   * @brief Créé un corps tel que décrit dans la fonction, membre par membre
   * @return Un corps entier (presque)
   */

  /**
   * @name  getPv
   * @brief Donne les pvs du corps entier
   * @return les points de vie du corps
   */

  /**
   * @name  getPvMax
   * @brief Donne les pvs au maximum du corps entier (ne peut pas changer)
   * @return les points de vie max du corps
   */

  /**
   * @name  soin
   * @brief Soigne tous les membres de tous leurs points de vie
   */

  /**
   * @name  bandage
   * @brief Soigne tous les membres d'un nombre de points de vie déterminé
   * @param niveau le niveau du personnage qui détermine les points de
   * vie rendus
   */

  /**
   * @name  afficher
   * @brief Parcours le corps en entier pour afficher tous les membres
   * et leurs points de vie
   */

//include guard
#ifndef CORPS_HPP
#define CORPS_HPP

//forward declared dependencies
class Membre;

//included dependencies
#include <string>
#include <vector>
#include "Observer.hpp"

using namespace std;

class Corps : public Observer{
private:
  vector<Membre> _corps;

public:
  Corps();

  Corps(const Corps& lautre);
  Corps& operator=(const Corps& lautre);

  //Getters
  vector<Membre>& getLMembres();
  int getPv();
  int getPvMax();

  //Setters
  void changerMembre(Membre m, int loca);

  //Méthodes de l'observer
  Observer* getSuiv();
  void setSuiv(Observer* o);
  void passer(Membre& m);
  void traiter(Membre& m, int pv);
  void updateObs();

  //Autres méthodes
  void soin();
  void bandage(int niveau);
  void afficher();


};

#endif // CORPS_HPP
