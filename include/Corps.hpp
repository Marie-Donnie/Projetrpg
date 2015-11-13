#ifndef CORPS_HPP
#define CORPS_HPP


#include <string>
#include <vector>

class Membre;

using namespace std;


class Corps{
private:
  vector<Membre> _corps;


public:
  Corps();

  //Getters
  vector<Membre>& getLMembres();
  //int getSante();

  //Setters
  void changerMembre(Membre m, int loca);


  //Autre sméthodes
  void afficher();


};

#endif // CORPS_HPP
