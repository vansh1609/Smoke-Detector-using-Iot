int redLed = 12;  //pin for red led light
int greenLed = 7; //pin for green led light
int buzzer = 10;  //pin for connecting buzzer
int smokeA0 = A5; //pin for taking input from smoke sensor

int Threshold = 150;  //thershold value that can be modified according to what we want.

void setup() {
  pinMode(redLed, OUTPUT);    //red light initialised for output
  pinMode(greenLed, OUTPUT);  //green light initialised for output
  pinMode(buzzer, OUTPUT);    //buzzer initialised for output
  pinMode(smokeA0, INPUT);    //smoke sensor initialised to take input
  Serial.begin(9600);         //used to establish serial communication
}

void loop() {
  int SensorReading = analogRead(smokeA0);  //reading from the sensor is taken and variable SensorReading is initialised with that value

  Serial.print("Pin A0: ");
  Serial.println(SensorReading);
                                        
  if (SensorReading > Threshold)  // Checks if it has reached the threshold value
  {
    digitalWrite(redLed, HIGH);   //red led is on
    digitalWrite(greenLed, LOW);  //green led is off
    tone(buzzer, 1000, 2000);     // buzzer beeps with the given frequency
  }
  else
  {
    digitalWrite(redLed, LOW);    // red led is off
    digitalWrite(greenLed, HIGH); //green led is on
    noTone(buzzer);               //buzzer stops beeping
  }
  delay(1000);                    //this whole process will repeat after every 1 sec.
}
