// Ultrasonic Module HC-SR04 Distance Sensor
// Detection Region: 196 in = 16.3 ft
// Precision: Up to .12 in
// Effectual Angle: < 15 in

// Plug and Play: pin assignments
#define VCC_PIN 4
#define TRIG_PIN 5
#define ECHO_PIN 6
#define GND_PIN 7

// microseconds required to travel 1 inch
#define INCH_USEC 74.05
// self imposed limit
#define MAX_INCHES 196

const unsigned long TIMEOUT = MAX_INCHES * INCH_USEC;

double ranging()
{
  unsigned long duration;
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN,HIGH,TIMEOUT);
  if ( duration == 0 ) 
    return MAX_INCHES; 
  return ((double)duration) / INCH_USEC / 2;
}

void setup() {
  Serial.begin(9600);
  pinMode(VCC_PIN, OUTPUT); // VCC pin
  pinMode(TRIG_PIN,OUTPUT);
  pinMode(ECHO_PIN,INPUT);
  pinMode(GND_PIN, OUTPUT); // GND ping
  digitalWrite(4, HIGH); // VCC +5V mode  
  digitalWrite(7, LOW);  // GND mode
}

void loop()
{
  Serial.print(ranging(),2);
  Serial.print("," );
  delay(1000);
}
