// 
// Arduino as Master to DM164130-3 28-PIN LIN DEMO BOARD (slave)
// connect Arduino Nano 5V and GND to Output of MCP2025-500 
// Arduino TX => LIN Tx 
// reception not yet implemented in this demo

void setup() 
{
// nothing in here
}




void loop() 
{

// Wakepulse 
pinMode(1, OUTPUT);  
digitalWrite(1, LOW);   // turn the LED on (HIGH is the voltage level)
delayMicroseconds(1247); // wake pulse is at least 13 bit 
digitalWrite(1, HIGH);    // turn the LED off by making the voltage LOW
;
delayMicroseconds(200);// eigentlich 96, umschalten dauert deshalb sind 82 genau 1 bit

Serial.begin(9600);  
  while (!Serial)   {;} // necessary ?
Serial.write(0x55);     // Sync
Serial.flush();         // wait until transmission has finished 
delayMicroseconds(100); // insert interbyte space
Serial.write(0x6F); // Microchip Board answers to PID 2F =>> Frame ID = 6F
delay(100);
Serial.end();  

}
