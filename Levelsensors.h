#ifndef MY_LEVELSENSORS__H
#define MY_LEVELSENSORS_H

#include "Clara.h"
using namespace std;

class Levelsensors {

  private:
   int pinA0;
   int pinA1;  
   
   int muniute=60000;
   int l_delay = 1000;
   int time_now=0;
   int Liquid_level_1=1;
   int Liquid_level_2=0;
  
   

  public:
    Levelsensors(byte pinA0, byte pinA1);
    void init();
    void run(Clara &clara); // Has to be passed as a reference! See p. 255 in "Grundkurs C++"
    

};
#endif
