#include "StepMotorFunction.h"
#include <LCD_I2C.h>
#include "DC_Motor.h"
#include "ultrasonic.h"
#include "buzzer.h"
#include <ESP32Servo.h>
Servo myservo;

LCD_I2C lcd(0x27, 16, 2);

#define BUTTON_SET 26
#define BUTTON_UP 27
#define BUTTON_DOWN 14
#define BUTTON_EXIT 12

//dealing function
int amountPlayer = 0;
int amountCard = 0;

//infrared
int digitalPin = 32;
int val = 0;

//servo
int servoPin = 13;
int pos = 0;

boolean Exit_dealing = false;
boolean rotate_again = false;

void setup() {

  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();

  pinMode(DC_Motor1, OUTPUT);
  pinMode(DC_Motor2, OUTPUT);

  pinMode(BUTTON_SET, INPUT_PULLUP);
  pinMode(BUTTON_UP, INPUT_PULLUP);
  pinMode(BUTTON_DOWN, INPUT_PULLUP);
  pinMode(BUTTON_EXIT, INPUT_PULLUP);

  pinMode(PHASE_A1_PLUS, OUTPUT);
  pinMode(PHASE_B3_PLUS, OUTPUT);
  pinMode(PHASE_A2_MINUS, OUTPUT);
  pinMode(PHASE_B4_MINUS, OUTPUT);

  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);

  pinMode(digitalPin, INPUT);

  pinMode(buzzer, OUTPUT);

  myservo.attach(servoPin);
  myservo.write(0);
}

void loop() {

  static boolean Display = true;
  static boolean ButtonSet = false;

  if (Display == true) {
    Display = false;
    lcd.setCursor(0, 0);
    lcd.print(" Welcome to Our ");
    lcd.setCursor(0, 1);
    lcd.print(" Embeded Project");
  }

  if (digitalRead(BUTTON_SET) == 0) {
    delay(50);
    if (digitalRead(BUTTON_SET) == 0) {
      if (ButtonSet == false) {
        ButtonSet = true;
        SelectAmountPlayer();
        Display = true;
      }
    }
  } else {
    ButtonSet = false;
  }

  //Serial.println(amountPlayer);
}

void SelectAmountPlayer(void) {
  boolean Display = true;
  boolean Exit = false;
  static boolean ButtonSet = true;
  static boolean ButtonUp = false;
  static boolean ButtonDown = false;
  static boolean ButtonExit = false;

  byte Menu = 0;
  const char MenuText[9][17] = { " 1: 2 Player    ",
                                 " 2: 3 Player    ",
                                 " 3: 4 Player    ",
                                 " 4: 5 Player    ",
                                 " 5: 6 Player    ",
                                 " 6: 7 Player    ",
                                 " 7: 8 Player    ",
                                 " 8: 9 Player    ",
                                 " 9: 10 Player   " };
  while (Exit == false) {

    if (Display == true) {
      Display = false;
      lcd.setCursor(0, 0);
      lcd.print(" Amount Player  ");
      lcd.setCursor(0, 1);
      lcd.print(MenuText[Menu]);
    }

    if (digitalRead(BUTTON_SET) == 0) {
      delay(50);
      if (digitalRead(BUTTON_SET) == 0) {
        if (ButtonSet == false) {
          ButtonSet = true;
          amountPlayer = Menu + 2;  // ค่า Menu เริ่มจาก 0 และเพิ่มจำนวนผู้เล่น 2
          SelectAmountCardPerPlayer();
          Exit = true;
        }
      }
    } else {
      ButtonSet = false;
    }

    if (digitalRead(BUTTON_UP) == 0) {
      delay(50);
      if (digitalRead(BUTTON_UP) == 0) {
        if (ButtonUp == false) {
          ButtonUp = true;
          if (Menu > 0) {
            Menu--;
          } else {
            Menu = 8;  // เมื่อถึงขั้นต่ำของเมนูให้วนกลับไปที่ขั้นสูงสุด
          }
          Display = true;
        }
      }
    } else {
      ButtonUp = false;
    }

    if (digitalRead(BUTTON_DOWN) == 0) {
      delay(50);
      if (digitalRead(BUTTON_DOWN) == 0) {
        if (ButtonDown == false) {
          ButtonDown = true;
          if (Menu < 8) {
            Menu++;
          } else {
            Menu = 0;  // เมื่อถึงขั้นสูงสุดของเมนูให้วนกลับไปที่ขั้นต่ำ
          }
          Display = true;
        }
      }
    } else {
      ButtonDown = false;
    }

    if (digitalRead(BUTTON_EXIT) == 0) {
      delay(50);
      if (digitalRead(BUTTON_EXIT) == 0) {
        if (ButtonExit == false) {
          ButtonExit = true;
          Exit = true;
        }
      }
    } else {
      ButtonExit = false;
    }
  }
}

void SelectAmountCardPerPlayer(void) {
  boolean Display = true;
  boolean Exit = false;
  static boolean ButtonSet = true;
  static boolean ButtonUp = false;
  static boolean ButtonDown = false;
  static boolean ButtonExit = false;
  byte Menu = 0;
  const char AmountCard[25][17] = { " 1: 1 Card      ",
                                    " 2: 2 Card      ",
                                    " 3: 3 Card      ",
                                    " 4: 4 Card      ",
                                    " 5: 5 Card      ",
                                    " 6: 6 Card      ",
                                    " 7: 7 Card      ",
                                    " 8: 8 Card      ",
                                    " 9: 9 Card      ",
                                    " 10: 10 Card    ",
                                    " 11: 11 Card    ",
                                    " 12: 12 Card    ",
                                    " 13: 13 Card    ",
                                    " 14: 14 Card    ",
                                    " 15: 15 Card    ",
                                    " 16: 16 Card    ",
                                    " 17: 17 Card    ",
                                    " 18: 18 Card    ",
                                    " 19: 19 Card    ",
                                    " 20: 20 Card    ",
                                    " 21: 21 Card    ",
                                    " 22: 22 Card    ",
                                    " 23: 23 Card    ",
                                    " 24: 24 Card    ",
                                    " 25: 25 Card    " };
  while (Exit == false) {
    if (Display == true) {
      Display = false;
      lcd.setCursor(0, 0);
      lcd.print(" Amount of Card ");
      lcd.setCursor(0, 1);
      lcd.print(AmountCard[Menu]);
    }
    if (digitalRead(BUTTON_SET) == 0) {
      delay(50);
      if (digitalRead(BUTTON_SET) == 0) {
        if (ButtonSet == false) {
          ButtonSet = true;
          process();
          amountCard = Menu + 1;
          dealing(amountPlayer, amountCard);
          Exit = true;
        }
      }
    } else {
      ButtonSet = false;
    }
    if (digitalRead(BUTTON_UP) == 0) {
      delay(50);
      if (digitalRead(BUTTON_UP) == 0) {
        if (ButtonUp == false) {
          ButtonUp = true;
          if (Menu > 0) {
            Menu--;
          } else {
            Menu = 24;
          }
          Display = true;
        }
      }
    } else {
      ButtonUp = false;
    }
    if (digitalRead(BUTTON_DOWN) == 0) {
      delay(50);
      if (digitalRead(BUTTON_DOWN) == 0) {
        if (ButtonDown == false) {
          ButtonDown = true;
          if (Menu < 24) {
            Menu++;
          } else {
            Menu = 0;
          }
          Display = true;
        }
      }
    } else {
      ButtonDown = false;
    }
    if (digitalRead(BUTTON_EXIT) == 0) {
      delay(50);
      if (digitalRead(BUTTON_EXIT) == 0) {
        if (ButtonExit == false) {
          ButtonExit = true;
          Exit = true;
        }
      }
    } else {
      ButtonExit = false;
    }
  }
}

void process() {
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("Processing");
  lcd.setCursor(3, 1);
  lcd.print("Processing");
}

void dealing(int player, int card) {

  // Ensure positive values for player and card
  if (player <= 0 || card <= 0) {
    Serial.println("Invalid player or card amount.");
    return;
  }

  int angle = 2048 / player;

  for (int cardIndex = 0; cardIndex < card; cardIndex++) {
    for (int playerIndex = 0; playerIndex < player; playerIndex++) {
      for (int stepIndex = 0; stepIndex < angle; stepIndex++) {
        OneStep(CCW);
        delay(step_delay);
      }

      check_card_dealing();

      if(rotate_again == false){
        dc_rotate();
      }

      check_card_dealing();

      check_yes();

      process();

    }
  }
  stopMotor();
  delay(500);

  myservo.write(45);

  pass_card = true;

  while (Exit_dealing == false) {

    lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print("Kor Card");

    check_card();

    myservo.attach(servoPin);

    if(check_again == false && pass_card == true){
      for (int stepIndex = 0; stepIndex < angle; stepIndex++) {
        myservo.write(0);
        OneStep(CCW);
        delay(step_delay);
        myservo.write(45);
      }
      pass_card = false;
    }

    check_card();

    if(check_again == true){
      myservo.attach(servoPin);
      myservo.write(45);
    }

    ultrasonic();

    if(check_again == true){
      check_again = false;
    }

    if (kor_card == true) {
      lcd.setCursor(5, 1);
      lcd.print("1 Card");
      delay(1000);
      lcd.clear();
      kor_card = false;
      pass_card = false;
    }

    if (pass_card == true) {
      lcd.setCursor(5, 1);
      lcd.print(" pass ");
      delay(1000);
      lcd.clear();
    }

    check_card();

  }
  stopMotor();
  delay(500);

  Serial.println(player);
  Serial.print("Kor Card ");
  Serial.print(kor_card);
}

void check_card() {
  val = digitalRead(digitalPin);
  if (val == 0) {
    lcd.setCursor(2, 0);
    lcd.print("Card Empty!!");
    lcd.setCursor(2, 1);
    lcd.print("Card Empty!!");
    beep_beep();
    choose_card();
  }
}

void check_card_dealing() {
  val = digitalRead(digitalPin);
  if (val == 0) {
    lcd.setCursor(2, 0);
    lcd.print("Card Empty!!");
    lcd.setCursor(2, 1);
    lcd.print("Card Empty!!");
    beep_beep();
    choose_card();
  }
}

void choose_card() {
  boolean Display = true;
  boolean Exit = false;
  static boolean ButtonSet = true;
  static boolean ButtonUp = false;
  static boolean ButtonDown = false;
  static boolean ButtonExit = false;

  byte Menu = 0;
  const char MenuText[][17] = { " Yes            ", " No             " };

  while (Exit == false) {

    if (Display == true) {
      Display = false;
      lcd.setCursor(0, 0);
      lcd.print("   Continue?    ");
      lcd.setCursor(0, 1);
      lcd.print(MenuText[Menu]);
    }

    if (digitalRead(BUTTON_SET) == 0) {
      delay(50);
      if (digitalRead(BUTTON_SET) == 0) {
        if (ButtonSet == false) {
          ButtonSet = true;
          if (Menu == 1) {
            Exit_dealing = true;
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("  Game Done!!!  ");
            lcd.setCursor(0, 1);
            lcd.print("  Game Done!!!  ");
            delay(500);
            ESP.restart();
          } else {
            check_again = true;
          }
          Exit = true;
        }
      }
    } else {
      ButtonSet = false;
    }

    if (digitalRead(BUTTON_UP) == 0) {
      delay(50);
      if (digitalRead(BUTTON_UP) == 0) {
        if (ButtonUp == false) {
          ButtonUp = true;
          if (Menu > 0) {
            Menu--;
          } else {
            Menu = 1;  // เมื่อถึงขั้นต่ำของเมนูให้วนกลับไปที่ขั้นสูงสุด
          }
          Display = true;
        }
      }
    } else {
      ButtonUp = false;
    }

    if (digitalRead(BUTTON_DOWN) == 0) {
      delay(50);
      if (digitalRead(BUTTON_DOWN) == 0) {
        if (ButtonDown == false) {
          ButtonDown = true;
          if (Menu < 1) {
            Menu++;
          } else {
            Menu = 0;  // เมื่อถึงขั้นสูงสุดของเมนูให้วนกลับไปที่ขั้นต่ำ
          }
          Display = true;
        }
      }
    } else {
      ButtonDown = false;
    }

    if (digitalRead(BUTTON_EXIT) == 0) {
      delay(50);
      if (digitalRead(BUTTON_EXIT) == 0) {
        if (ButtonExit == false) {
          ButtonExit = true;
        }
      }
    } else {
      ButtonExit = false;
    }
  }
}

void choose_card_dealing() {
  boolean Display = true;
  boolean Exit = false;
  static boolean ButtonSet = true;
  static boolean ButtonUp = false;
  static boolean ButtonDown = false;
  static boolean ButtonExit = false;

  byte Menu = 0;
  const char MenuText[][17] = { " Yes            ", " No             " };
  while (Exit == false) {

    if (Display == true) {
      Display = false;
      lcd.setCursor(0, 0);
      lcd.print("   Continue?    ");
      lcd.setCursor(0, 1);
      lcd.print(MenuText[Menu]);
    }

    if (digitalRead(BUTTON_SET) == 0) {
      delay(50);
      if (digitalRead(BUTTON_SET) == 0) {
        if (ButtonSet == false) {
          ButtonSet = true;
          if (Menu == 1) {
            Exit_dealing = true;
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("  Game Done!!!  ");
            lcd.setCursor(0, 1);
            lcd.print("  Game Done!!!  ");
            delay(500);
            ESP.restart();
          } else {
            rotate_again = true;
            lcd.clear();
          }
          Exit = true;
        }
      }
    } else {
      ButtonSet = false;
    }

    if (digitalRead(BUTTON_UP) == 0) {
      delay(50);
      if (digitalRead(BUTTON_UP) == 0) {
        if (ButtonUp == false) {
          ButtonUp = true;
          if (Menu > 0) {
            Menu--;
          } else {
            Menu = 1;  // เมื่อถึงขั้นต่ำของเมนูให้วนกลับไปที่ขั้นสูงสุด
          }
          Display = true;
        }
      }
    } else {
      ButtonUp = false;
    }

    if (digitalRead(BUTTON_DOWN) == 0) {
      delay(50);
      if (digitalRead(BUTTON_DOWN) == 0) {
        if (ButtonDown == false) {
          ButtonDown = true;
          if (Menu < 1) {
            Menu++;
          } else {
            Menu = 0;  // เมื่อถึงขั้นสูงสุดของเมนูให้วนกลับไปที่ขั้นต่ำ
          }
          Display = true;
        }
      }
    } else {
      ButtonDown = false;
    }

    if (digitalRead(BUTTON_EXIT) == 0) {
      delay(50);
      if (digitalRead(BUTTON_EXIT) == 0) {
        if (ButtonExit == false) {
          ButtonExit = true;
        }
      }
    } else {
      ButtonExit = false;
    }
  }
}

void check_yes() {
  if (rotate_again == true) {
    dc_rotate();
    rotate_again = false;
  }
}