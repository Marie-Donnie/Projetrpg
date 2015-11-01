#include <string>
#include <vector>

#ifndef MEMBRE_HPP
#define MEMBRE_HPP

using namespace std;

class Membre{
private :
  string _nom;
  int _pv;
  vector<Membre> _sousMembre;
public :
  //Constructeur
  Membre(int pv, string nom, vector<Membre> sousm);
  Membre(int pv, string nom);
  Membre();
  //Setters
  void setPv(int pv);
  void setNom(string nom);
  void changerPv(int pv);
  void changerMembre(Membre m, int loca);
  //Getters
  int getPv();
  string getNom();
  vector<Membre> getMembres();
  Membre getMembre(int loca);
};

#endif //MEMBRE_HPP
