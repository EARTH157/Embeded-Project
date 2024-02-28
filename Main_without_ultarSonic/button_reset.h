int timer_to_reset = 0;

void reset() {
  Serial.println(timer_to_reset);
  if (digitalRead(13) == 0) {
    delay(100);
    if (digitalRead(13) == 0) {
      Serial.write("Pin!!!");
      timer_to_reset++;
      if (timer_to_reset == 20){
        timer_to_reset = 0;
        delay(1000);
        ESP.restart();
      }
    }else if (digitalRead(13) != 0){
      timer_to_reset = 0;
    }
  }
}
