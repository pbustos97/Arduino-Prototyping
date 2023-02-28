#define LED_BUILTIN 13

#define RGB_RED 11
#define RGB_GREEN 8
#define RGB_BLUE 2

#define BUTTON1 4
#define BUTTON2 6

#define USE_BUTTONS 1

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(RGB_RED, OUTPUT);
  pinMode(RGB_GREEN, OUTPUT);
  pinMode(RGB_BLUE, OUTPUT);

  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);
}

void loop() {
#if !USE_BUTTONS
  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN, HIGH); // High voltage = LED On
  // delay(1000);

  // RGB LED LOGIC
  digitalWrite(RGB_RED, 255);
  digitalWrite(RGB_GREEN, 255);
  digitalWrite(RGB_BLUE, 255);
  delay(1000);

  // TURN OFF
  digitalWrite(LED_BUILTIN, LOW);  // Low voltage = LED Off
  digitalWrite(RGB_RED, LOW);  // Low voltage = LED Off
  digitalWrite(RGB_GREEN, LOW);  // Low voltage = LED Off
  digitalWrite(RGB_BLUE, LOW);  // Low voltage = LED Off
  delay(1000);

#endif

  // BUTTON LOGIC
#if USE_BUTTONS
  if (digitalRead(BUTTON1) == LOW)
  {
    digitalWrite(LED_BUILTIN, HIGH);
  }

  if (digitalRead(BUTTON2) == LOW)
  {
    digitalWrite(LED_BUILTIN, LOW);
  }
#endif

}
