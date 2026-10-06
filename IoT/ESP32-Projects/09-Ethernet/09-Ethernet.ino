#include <ETH.h>
void setup(){
  Serial.begin(115200);
  ETH.begin();
}
void loop(){
  if(ETH.linkUp()){
    Serial.print("Ethernet IP: "); Serial.println(ETH.localIP());
  } else Serial.println("Ethernet link down");
  delay(2000);
}
