char key = '0' ;

void setup() {
  Serial.begin(9600);
}

void loop() {
  key = Serial.read();
  Serial.println(key);
  delay(1000);

  if(Serial.available() > 0){
    if(key == 48){
      Serial.println("Press!!!");
    }
  }

  if(key == 49){
    Serial.println("Press!!!");
  }

  if(key == 50){
    Serial.println("Press!!!");
  }

  if(key == 51){
    Serial.println("Press!!!");
  }

  if(key == 52){
    Serial.println("Press!!!");
  }
}
