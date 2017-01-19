/* This sample code demonstrates the normal way to get data from GPS without library.
   Creat for TIVA C Launchpad by hocARM.org
   It requires the use of Serial1, and assumes that you have a
   9600-baud serial Neo 6M GPS device hooked up on pins rx and tx.
   Circuits:
	GPS       TIVA
	---------------
	VCC    |   VBUS
	RX     |   PB1
	TX     |   PB0
	GND    |   GND
*/

#define GPSSerial Serial1

void setup() {
  // wait for hardware serial to appear
  while (!Serial);

  // make this baud rate fast enough to we aren't waiting on it
  Serial.begin(115200);

  // 9600 baud is the default rate for the Ultimate GPS
  GPSSerial.begin(9600);
}

void loop() {

  if (GPSSerial.available()) {
    char c = GPSSerial.read();
    Serial.write(c);
  }
}
