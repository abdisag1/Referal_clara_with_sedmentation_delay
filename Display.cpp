#include "Display.h"
#include <LiquidCrystal_I2C.h>

using namespace std;
int timer_1 = 0;
int timer_w = 0;
int timer_c=0;
int timer_b=0;
int timer_2=0;
int state = 2;
Display::Display(byte pin) {
  this-> pin = pin;
  this-> text = "";
  
  init();

}



void Display::init() { // put your setup code here, to run once:

  Serial.begin(9600);

}

void Display::run(Clara &clara,LiquidCrystal_I2C &lcd) { // Has to be passed as a reference! See p. 255 in "Grundkurs C++"

    state = clara.get_state();
   

 
   
  
      if(state == 1){      
      int Begin_time =  5000;

  while (Begin_time>0){
     String BTime = String(Begin_time/1000);
      if (clara.timer >= 4000) {
    timer_b++;
    timer_1 = 0;
// Serial.println(BTime);
  if (BTime==("1")){
   
       clara.set_state(2);
  //     Serial.print("State=");
    //     Serial.println(clara.get_state());
  
    
  LCDWrite("Wata production","Begins",lcd);   
    // LCD-Display-Stop

    
      }

    
    Begin_time = Begin_time - 4000;
  
   // delay(1000);

  }
      }}
    
    
    else if(state == 2){

  String flow_string = String(clara.get_flow())+" l/min";
 LCDWrite("In Production","Flow: "+flow_string,lcd);
      
     /*  int RestTime =  watamin;
  while (RestTime>0){

    
 // LCD-Display-Start
    String DisTime = String(RestTime/1000);
    int countdownhour=RestTime/(1000*3600);
    String countdown_hour=String(countdownhour);
    //Serial.println(countdownhour);
    int countdownmin=(RestTime/1000/60)%60;
    String countdown_min=String(countdownmin);
    //Serial.println(countdownmin);
   
    
   String flow_string = String(clara.get_flow())+" l/min"; 
    if (timer_1 >= 1000) {
    timer_w++;
    timer_1 = 0;
 
    //Serial.println(DisTime);
   LCDWrite("Wata time:"+countdown_hour+"hr:"+countdown_min,"Flow: "+flow_string,lcd);
    if (DisTime==("0")){
     // Serial.println("time is done");
      // clara.set_state(3);
  
    
      }
   //Serial.println(DisTime);   
    // LCD-Display-Stop
    RestTime = RestTime - 1000;
   // delay(1000);
  

  }
  
    
    }*/
    
    }
    
  else if(state ==3){
   
  String flow_strings = String(clara.get_flow())+" l/min";
 LCDWrite("Ready for Production","Flow: "+flow_strings,lcd);
         
      
  }

 
     else if(state == 4){
   
    
        float cl_pumped=clara.pump_count * clara.volume_per_pump;
        String flow_string = String(clara.get_flow())+" l/min"; // Has to be replaced of course
        String chlorine_left = String(cl_pumped); // Has to be replaced of course
        LCDWrite("Flow: "+flow_string,"Volume: "+chlorine_left+" L",lcd);
       

      }
       else if(state == 5){

  String flow_string = String(clara.get_flow())+" l/min";
 LCDWrite("Setling","Flow: "+flow_string,lcd);
      }
      
     
}

void Display::LCDWrite(String text1, String text2, LiquidCrystal_I2C &lcd) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(text1);
    lcd.setCursor(0, 1);
    lcd.print(text2); 
}
