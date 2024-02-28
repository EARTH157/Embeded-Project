int time_reset = 0;

void setup(){
  Serial.begin(9600);
  pinMode(35, INPUT_PULLUP);
}

void loop(){
  Serial.println(digitalRead(35));
  Serial.print("Time : ");
  Serial.println(time_reset);

  if(digitalRead(35) == 0){
    time_reset ++;
  }else{
    time_reset = 0;
  }

  if(time_reset == 20){
    ESP.restart();
  }

  delay(100);
}