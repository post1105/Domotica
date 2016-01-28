#define fsrPin  0
#define ledPin  4

int fsrVal = 0;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
pinMode(fsrPin, INPUT);
pinMode(ledPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
 fsrVal = analogRead(fsrPin);
 Serial.println(fsrVal);
if(fsrVal > 500)
{
  digitalWrite(ledPin,HIGH);
}
else{
  digitalWrite(ledPin,LOW);
}

}
