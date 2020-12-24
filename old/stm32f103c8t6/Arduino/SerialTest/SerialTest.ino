// These variables will change:
int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM

void setup() {
	Serial.begin(115200); // Ignored by Maple. But needed by boards using Hardware serial via a USB to Serial Adaptor
  Serial1.begin(9600);
}

void loop() {

    // print the results to the serial monitor:
    Serial1.print("sensor = " );
    Serial1.print(sensorValue);
    Serial1.print("\t output = ");
    Serial1.println(outputValue);
}
