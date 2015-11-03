#include <string>

#ifndef ARME_HPP
#define ARME_HPP

using namespace std;

class Arme{
private:
  string _nom;
  int _type;
  int _mains;
  double _vitesse;
  int _dmgmin;
  int _dmgmax;
  int _penetration;
  bool _contondant;

public:
  //Constructeur
  Arme();
  Arme(string nom, int type, int mains, double vitesse, int dmgmin, int dmgmax, int penetration, bool contondant);

  //Getters
  string getNom();
  int getType();
  int getMains();
  double getVitesse();
  int getDmgmin();
  int getDmgmax();
  int getPene();
  bool getContondance();

  //Setters
  void setNom(string nom);
  void setType(int type);
  void setMains(int mains);
  void setVitesse(double vitesse);
  void setDmgmin(int dmgmin);
  void setDmgmax(int dmgmax);
  void setPene(int penetration);
  void setContondance(bool contondance);

};


#endif //ARME_HPP
