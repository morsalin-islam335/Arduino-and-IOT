int speakerPin = 12;
int length = 28;
char notes[] = {"GGAGcB GGAGdc GGxeBA yyecdc"};
char beats[] = {2,2,8,8,8,16,1,2,2,8,8,8,16,1,2,2,8,8,8,8,16,1,2,2,8,8,8,16};

int tempo = 150;

void playTone(int tone, int duration)
{
  for (long i = 0; i < duration * 1000L; i+= tone * 2)
  {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration)
{
  char names[] = {'C', 'D','F', 'G','A','B','c', 'd','e', 'f', 'g', 'a', 'b', 'x', 'y'};
  int tones[] = {1915, 1700, 1519, 1432, 1275, 1136, 1014, 956, 834, 765, 593, 468, 346, 224, 655, 715};
  int SPEE = 5;

  for (int i = 0; i < 17; i ++)
  {
    if(names[i] == note)
    {
      int newDuration = duration / SPEE;
      playTone(tones[i], newDuration);
    }
  }
}
void setup() {
  // put your setup code here, to run once:
  pinMode(speakerPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < length; i++)
  {
    if(notes[i] == ' ')
    {
      delay(beats[i] * tempo); // take rest

    }
    else
    {
      playNote(notes[i], beats[i] * tempo);
      delay(tempo);
    }
  }

}
