#include "PooldObjets.hpp"


PooldObjets::PooldObjets(){
  for (int i=0; i<41; ++i){
    Drap* drap = new Drap();
    _draps.push_back(drap);
  }
  for (int i=0; i<121; ++i){
    Bandage* bandage = new Bandage();
    _bandages.push_back(bandage);
  }
}


boost::ptr_vector<Drap>& PooldObjets::getDraps(){return _draps;}
boost::ptr_vector<Bandage>& PooldObjets::getBandages(){return _bandages;}


Drap& PooldObjets::sortirDrap(){

}

Bandage& PooldObjets::sortirBandage(){}

void PooldObjets::remettreDrap(Drap* drap){}

void PooldObjets::remettreBandage(Bandage* bandage){

}
