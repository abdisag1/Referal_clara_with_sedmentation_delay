#ifndef MY_CLARA_H
#define MY_CLARA_H
#include "Arduino.h"



using namespace std;

class Clara {

  private:
    byte state =4;
    
    double flow;
    byte   eflow;
    float batterypercentage;
    byte button_pressed;
    bool waiting;
    unsigned long start_waiting;
    int updatesms;
    int statsms;



  public:
    // init-methods
    Clara();
    void init();
    String        Master_Nr = "";
    boolean       stat       = 0;
    boolean       UpdateSMS = 0;
    String        StatusString;
    int           alarm = 0;
    int           liquidlevel_1 = 0;
    int           liquidlevel_2 = 1;
    int            wa_state;
    int            v_state;
    float        voltage ;
    long          watamin = 120000;
    int           pin;
    int          timer = 0;
    boolean     wata_ready=0;
    boolean     ready_to_settle =0;


    // state-methods





    // flow-methods
    // flow in [l/min] in here
    double get_flow();
    void set_flow(double flow);
     int get_state();
    void set_state(int state);
    byte  get_eflow();
    void set_eflow(byte eflow);

    // button_pressed-methods
    byte get_button_pressed();
    void set_button_pressed(byte button_pressed);


    int pump_count = 0;
    float volume_per_pump = 0.04;
    void set_liquidlevel(int liquidlevel);
    int  get_liquidlevel();
    float  get_voltage();
    void  set_voltage(float voltage);
    float get_batterypercentage();
    void set_batterypercentage(float batterypercentage);
    int     get_liquidlevel_1();
    void  set_liquidlevel_1(int liquidlevel_1);
    int     get_liquidlevel_2();
    void  set_liquidlevel_2(int liquidlevel_2);

    void Start_wata(int wa_state, int pin);
    void  Stop_wata(int wa_state, int pin);
    void  Open_Valve(int v_state, int pin);
    void  Close_Valve(int v_state, int pin);
    void  Disinfection();
    void timerCallback();

};
#endif
