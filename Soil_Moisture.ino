#define AOUT_PIN A6 // The Arduino Nano pin that connects to AOUT pin of moisture sensor
#define THRESHOLD 530 // CHANGE YOUR THRESHOLD HERE

void setup() {
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(AOUT_PIN); // read the analog value from sensor

  if (value > THRESHOLD)
    Serial.print("The soil is DRY: ");
  else
    Serial.print("The soil is WET: ");

  Serial.print(value);
  delay(500);
}

