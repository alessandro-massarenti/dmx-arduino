#include <DmxSimple.h>

int v;

void setup() {

  Serial.begin(9600);
  Serial.setTimeout(10);

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

  if (Serial.available()) {
    v = Serial.parseInt();
    Serial.println(v);
    DmxSimple.write(1, v);
    DmxSimple.write(2, v);
    DmxSimple.write(4, v);
    DmxSimple.write(5, v);
    DmxSimple.write(6, v);
    DmxSimple.write(7, v);
  }
}
