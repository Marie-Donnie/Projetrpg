//include guard
#ifndef MEMBRE_HPP
#define MEMBRE_HPP

//forward declared dependencies
class Observer;

//included dependencies
#include <string>
#include <vector>


using namespace std;

class Membre{
private :
  int _pv;
  int _pvmax;
  string _nom;
  vector<Membre> _sousMembre;
  Observer* _corps;
public :
  //Constructeur
  Membre(int pv, int pvmax, string nom, vector<Membre> sousm, Observer* o);
  Membre(int pv, int pvmax, string nom, Observer* o);
  Membre(int pv, int pvmax, string nom);
  Membre();
  //Getters
  int getPv();
  int getPvMax();
  string getNom();
  vector<Membre>& getMembres();
  Membre& getMembre(int loca);
  //Setters
  void setPv(int pv);
  void setPvMax(int pv);
  void setNom(string nom);
  void setObs(Observer* o);
  void changerPv(int pv);
  void changerMembre(Membre& m, int loca);

  void checkPv();
};

#endif //MEMBRE_HPP
