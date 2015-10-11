#include <iostream>
#include "Personnage.hpp"

using namespace std;

int main(){
  Personnage lol = Personnage("Mario", 42, 1.45, 90.2);
  lol.afficher();

}
