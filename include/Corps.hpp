//include guard
#ifndef CORPS_HPP
#define CORPS_HPP

//forward declared dependencies
class Membre;

//included dependencies
#include <string>
#include <vector>

using namespace std;

class Corps{
private:
  vector<Membre> _corps;

public:
  Corps();

  //Getters
  vector<Membre>& getLMembres();
  int getPv();
  int getPvMax();

  //Setters
  void changerMembre(Membre m, int loca);

  //Autres méthodes
  void afficher();


};

#endif // CORPS_HPP
