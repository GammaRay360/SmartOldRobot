
int p2 = 2;
int p3 = 3;
int p4 = 4;
int p5 = 5;
int p6 = 6;
int p7 = 7;
int p8 = 8;
int p9 = 9;
int p10 = 10;
int p11 = 11;
int p12 = 12;
int p13 = 13;


String	str;

void setup() {
	Serial.begin(9600);
	Serial1.begin(9600);
	Serial.println("start:");
	str = "";
	
	for (int i = 2;i <= 13;i++) {
		pinMode(i, OUTPUT);
		digitalWrite(i, LOW);
	}



}

void loop() {
  // listen to commends from usb
	if (Serial.available() > 0) {
		str = Serial.readString();
		setPinFromSerial(str);
	}
 // listen to commends from bluetooth
	else if (Serial1.available() > 0) {
		str = Serial1.readString();
		setPinFromSerial(str);
	}

	delay(10);
}


void setPinFromSerial(String str) {

	for (int i = 2;i <= 13;i++) {
		digitalWrite(i, LOW);
	}
	//Serial.println("got: " + str);
	if (!str.compareTo("s"))
		return;
	int p = str.toInt();
	if (p<2 || p> 13)
		return;
	if (p >= 4 && p <= 7) {
		switch (p) {
		case 4:
			analogWrite(4, 255);
			analogWrite(6, 255);
			break;
		case 5:
			analogWrite(5, 255);
			analogWrite(7, 255);
			break;
		case 6:
			analogWrite(4, 255);
			analogWrite(7, 255);
			break;
		case 7:
			analogWrite(5, 255);
			analogWrite(6, 255);
			break;

		}
	}
	else {
		analogWrite(p, 255);
	}
	//Serial.println("start pin " + str);


}

