#include "Membre.hpp"
#include <string>
#include <vector>

#ifndef CORPS_HPP
#define CORPS_HPP

using namespace std;


class Corps{
private:
  vector<Membre> _corps;




public:
  Corps();

  vector<Membre> getLMembres();
  void afficher();
  //int getSante();





};

#endif // CORPS_HPP
