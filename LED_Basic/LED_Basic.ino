#define LED_BUILTIN 13

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // digitalWrite(LED_BUILTIN, HIGH); // High voltage = LED On
  // delay(1000);
  digitalWrite(LED_BUILTIN, LOW);  // Low voltage = LED Off
  delay(1000);
}