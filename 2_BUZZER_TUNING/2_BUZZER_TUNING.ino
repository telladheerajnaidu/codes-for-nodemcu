
  // put your setup code here, to run once:
int frequency=21; //Specified in Hz
int buzzer1=2;
int buzzer2=12; 
void setup()
{
pinMode(buzzer1,OUTPUT);
pinMode(buzzer2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
tone(buzzer1, frequency);
delay(1000);
noTone(buzzer1);
delay(1000); 
tone(buzzer2, frequency);
delay(1000);
noTone(buzzer2);
delay(1000); 
}
