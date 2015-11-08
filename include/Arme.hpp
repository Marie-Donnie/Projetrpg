#include <string>
#include <stdlib.h>
#include <iostream>

#ifndef ARME_HPP
#define ARME_HPP

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
