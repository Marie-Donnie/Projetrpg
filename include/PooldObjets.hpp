//include guard
#ifndef POOLDOBJETS_HPP
#define POOLDOBJETS_HPP

//included dependencies
#include <string>
#include <boost/ptr_container/ptr_vector.hpp>
#include "Objet.hpp"
#include "Drap.hpp"
#include "Bandage.hpp"


using namespace std;

class PooldObjets {
private :
  boost::ptr_vector<Drap> _draps;
  boost::ptr_vector<Bandage> _bandages;

  public;
  PooldObjets();

  //getters
boost::ptr_vector<Drap>& getDraps();
boost::ptr_vector<Bandage>& getBandages();

  //Methodes de l'Object Pool

  Drap& sortirDrap();
  Bandage& sortirBandage();
  void remettreDrap(Drap* drap);
  void remettreBandage(Bandage* bandage);

};

#endif //POOLDOBJETS_HPP
