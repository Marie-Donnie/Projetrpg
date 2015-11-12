#ifndef MEMBRE_HPP
#define MEMBRE_HPP

#include <string>
#include <vector>

using namespace std;

class Membre{
private :
  int _pv;
  int _pvmax;
  string _nom;
  vector<Membre> _sousMembre;
public :
  //Constructeur
  Membre(int pv, int pvmax, string nom, vector<Membre> sousm);
  Membre(int pv, int pvmax, string nom);
  Membre();
  //Setters
  void setPv(int pv);
  void setPvMax(int pv);
  void setNom(string nom);
  void changerPv(int pv);
  void changerMembre(Membre& m, int loca);
  //Getters
  int getPv();
  int getPvMax();
  string getNom();
  vector<Membre>& getMembres();
  Membre& getMembre(int loca);
};

#endif //MEMBRE_HPP
