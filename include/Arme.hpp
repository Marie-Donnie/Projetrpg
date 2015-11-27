  /**
   * @name  Constructeur complet
   * @brief Créé une arme prenant les paramètres donnés.
   * @param nom le nom qu'on veut donner à l'arme
   * @param type le type de l'arme (0 : épée, 1 : masse, 2 :
   * hallebarde/dague selon mains)
   * @param mains le nombre de mains nécessaire pour la porter
   * @param portée sa portée
   * @param vitesse sa vitesse
   * @param dmgmin ses dommages minimum
   * @param dmgmax ses dommages maximum
   * @param penetration indique la pénétration qu'aura l'arme sur l'armure
   * @param contondant booléen indiquant si on peut assomer l'ennemi
   * (pas encore implémenté)
   * @return Une arme selon les paramètres
   */

  /**
   * @name  Constructeur partiel
   * @brief Créé une arme prenant les paramètres donnés et calculant
   * le reste au hasard, le nom étant obtenu par concatenation
   * @param type le type de l'arme (0 : épée, 1 : masse, 2 :
   * hallebarde/dague selon mains)
   * @param mains le nombre de mains nécessaire pour la porter
   * @return Une arme selon les paramètres
   */

  /**
   * @name  Constructeur partiel
   * @brief Créé une arme par défaut (mains nues ou mains de zombie,
   * dans ce code) qui n'a pas d'avantage
   * @param nom le nom de l'arme
   * @return Une arme selon les paramètres
   */

  /**
   * @name  Constructeur par défaut
   * @brief Créé une arme de test
   * @return Une arme de test
   */

  /**
   * @name  Afficher
   * @brief Affiche les détails de l'arme
   */

//include guard
#ifndef ARME_HPP
#define ARME_HPP

//included dependencies
#include <string>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Arme{
private:
  string _nom;
  int _type;
  int _mains;
  int _portee;
  double _vitesse;
  int _dmgmin;
  int _dmgmax;
  int _penetration;
  bool _contondant;

public:
  //Constructeur
  Arme();
  Arme(string nom, int type, int mains, int portee, double vitesse, int dmgmin, int dmgmax, int penetration, bool contondant);
  Arme(int type, int mains);
  Arme(string nom);

  //Getters
  string getNom();
  int getType();
  int getMains();
  int getPortee();
  double getVitesse();
  int getDmgmin();
  int getDmgmax();
  int getPene();
  bool getContondance();

  //Setters
  void setNom(string nom);
  void setType(int type);
  void setMains(int mains);
  void setPortee(int portee);
  void setVitesse(double vitesse);
  void setDmgmin(int dmgmin);
  void setDmgmax(int dmgmax);
  void setPene(int penetration);
  void setContondance(bool contondance);


  //Autres méthodes
  void afficher();
};



#endif //ARME_HPP
