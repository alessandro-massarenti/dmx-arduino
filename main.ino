#include <DmxSimple.h>

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
String commandString = "";

boolean isConnected = false;

String c;
String v;
void setup() {

  Serial.begin(9600);

  digitalWrite(2, HIGH);
  DmxSimple.usePin(4);
  DmxSimple.maxChannel(32);

  /* Set channel 1 on the light (total dimmer) to max (255)
  ** so that values for channels R (2), G (3) and B (4) are visible.*/
  //DmxSimple.write(9, 200);
  DmxSimple.write(1, 0);
  DmxSimple.write(3, 134);
  DmxSimple.write(8, 0);
}


void loop() {

  if (stringComplete)
  {
    stringComplete = false;
    getCommand();

    if (commandString.equals("LIGH"))
    {
      c = inputString.substring(5, 8);
      v = inputString.substring(8, 11);
      DmxSimple.write(c.toInt(), v.toInt());
    }
    if (commandString.equals("STOP"))
    {
      DmxSimple.write(002, 0);
    }
    inputString = "";
  }

}

void getCommand()
{
  if (inputString.length() > 0)
  {
    commandString = inputString.substring(1, 5);
  }
}

void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
