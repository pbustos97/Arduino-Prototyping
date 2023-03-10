#include <pitches.h>

#include "pitches.h"

#define LED_BUILTIN 13

#define USE_BUTTON 0
#define BUTTON1 4
#define BUTTON2 6

#define BUZZER_ACTIVE 0
#define buzzer 3

int melody[] = {
  NOTE_F5, NOTE_F5, NOTE_F5, NOTE_E5, NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5, NOTE_E5, NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5 };
int duration[] = 
  {360, 240, 120, 120, 240, 240, 480, 120, 120, 240, 240, 240, 1000};

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
#if !USE_BUTTONS
  // put your main code here, to run repeatedly:
  unsigned char i;
  while(1)
  {
#if BUZZER_ACTIVE
    for (i=0; i < 80; i++)
    {
      digitalWrite(buzzer, HIGH);
      delay(1);
      digitalWrite(buzzer, LOW);
      delay(1);
    }

    for (i=0; i< 100; i++)
    {
      digitalWrite(buzzer, HIGH);
      delay(2);
      digitalWrite(buzzer, LOW);
      delay(2);
    }
#endif
#if !BUZZER_ACTIVE
    for (int thisNote = 0; thisNote < 13; thisNote++)
    {
      tone(buzzer, melody[thisNote], 120);

      delay(duration[thisNote]);
    }
    delay(2000);
#endif
  }
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
