#include <Conceptinetics.h>

// Numero di canali
#define DMX_MASTER_CHANNELS   9 

// Pin number to change read or write mode on the shield
#define RXEN_PIN                2


// Configure a DMX master controller, the master controller
// will use the RXEN_PIN to control its write operation 
// on the bus
DMX_Master        dmx_master ( DMX_MASTER_CHANNELS, RXEN_PIN );


// the setup routine runs once when you press reset:
void setup() {             
  
  // Enable DMX master interface and start transmitting
  dmx_master.enable ();  
  
  // Set channel 1 - 50 @ 50%
  dmx_master.setChannelRange ( 1, 25, 127 );
  dmx_master.setChannelValue ( 3, 100 );
}

// the loop routine runs over and over again forever:
void loop() 
{  

  dmx_master.setChannelValue ( 3, 134 );
  for(int i = 1; i <= 2;i++){
    for(int j = 0; j < 256;j= j+10){
      dmx_master.setChannelValue ( i, j );
      dmx_master.setChannelValue ( 4+i, 200 );
      delay(400);
      dmx_master.setChannelValue ( 4+i, 0 );
    }
    dmx_master.setChannelValue ( i, 0 );
    delay(700);
  }

  dmx_master.setChannelValue(2,125);
  for(int i = 4; i <= 8;i++){
    for(int j = 0; j < 256;j= j+10){
      dmx_master.setChannelValue ( i, j );
      delay(400);
    }
    dmx_master.setChannelValue ( i, 0 );
    delay(400);
  }
  dmx_master.setChannelValue ( 3, 0 );
   dmx_master.setChannelValue(2,0);
}
