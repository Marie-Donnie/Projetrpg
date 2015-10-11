#include <string>
#include "Stat.hpp"

#ifndef PERSONNAGE_HPP
#define PERSONNAGE_HPP

using namespace std;

class Personnage {
private :
  string _nom;
  int _age;
  double _taille;
  double _poids;
  Stat _stats;


public :
  Personnage(string nom, int age, double taille, double poids); //Constructeur

  void afficher();
};

#endif //PERSONNAGE_HPP
