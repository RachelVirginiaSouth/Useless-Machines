void setup() {
  // put your setup code here, to run once:
pinMode (0, INPUT); // Pin 0 as input for pressure-sensitive resistor 
pinMode (11, OUTPUT); // Pins 11 and 12 as output for L1190 (to vacuum pump)
pinMode (12, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(analogRead(0)); //read values of analog input
//conditional statement that checks whether pressure pad checks anything
if (analogRead(0) <= 1000){ //if pressure is sensed
digitalWrite(11, HIGH); //run motor forwards for 20 seconds
digitalWrite(12, LOW);
delay(20000);
digitalWrite(11,LOW); //run motor backwards for 20 seconds 
digitalWrite(12, HIGH); 
delay(20000);
} else { //if no pressure is sensed
digitalWrite (11, LOW); //stop motor
digitalWrite (12, LOW);
}
}
