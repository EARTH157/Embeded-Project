#define trig 33
#define echo 25

long duration, distance;

boolean kor_card = false;
boolean pass_card = false;
boolean check_again = false;

int time_card1 = 0;
int time_card2 = 0;
int val1 = 0;

void ultrasonic() {
  boolean Exit = false;

  while (Exit == false) {
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);

    duration = pulseIn(echo, HIGH);
    distance = duration * 0.034 / 2;

    if (distance <= 5) {
      time_card1++;
    } else if (time_card1 <= 10) {
      time_card1 = 0;
    }

    if (distance <= 10 && distance >= 5) {
      time_card2++;
    } else if (time_card2 <= 100) {
      time_card2 = 0;
    }

    if (distance <= 5) {
      if (time_card1 == 10) {
        pass_card = true;
        Exit = true;
        time_card1 = 0;
        break;
      }
    }

    if (distance <= 10) {
      if (time_card2 == 10) {
        kor_card = true;
        time_card2 = 0;
        dc_rotate();
        delay(500);
        break;
      }
    }

    Serial.print("Time 1 :");
    Serial.println(time_card1);
    Serial.print("Time 2 :");
    Serial.println(time_card2);
    Serial.print(distance);
    Serial.println(" cm\n");

    delay(100);
  }
}
