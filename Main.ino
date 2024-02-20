#include "StepMotorFunction.h"
#include <LCD_I2C.h>

LCD_I2C lcd(0x27, 16, 2);

#define BUTTON_SET 26
#define BUTTON_UP 4
#define BUTTON_DOWN 2
#define BUTTON_EXIT 13
#define DC_Motor 33

int amountPlayer = 0;

void setup() {

  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();

  pinMode(DC_Motor, OUTPUT);

  pinMode(BUTTON_SET,INPUT_PULLUP);
  pinMode(BUTTON_UP,INPUT_PULLUP);
  pinMode(BUTTON_DOWN,INPUT_PULLUP);
  pinMode(BUTTON_EXIT,INPUT_PULLUP);

  pinMode(PHASE_A1_PLUS, OUTPUT);
  pinMode(PHASE_B3_PLUS, OUTPUT);
  pinMode(PHASE_A2_MINUS, OUTPUT);
  pinMode(PHASE_B4_MINUS, OUTPUT);
}

void loop() {

  static boolean Display = true;
  static boolean ButtonSet = false;

  if(Display == true){
    Display = false;
    lcd.setCursor(0,0);
    lcd.print(" Welcome to Our ");
    lcd.setCursor(0,1);
    lcd.print(" Embeded Project");
  }

  if(digitalRead(BUTTON_SET) == 0){
    delay(50);
    if(digitalRead(BUTTON_SET) == 0){
      if(ButtonSet == false){
        ButtonSet = true;
        SelectAmountPlayer();
        Display = true;
      }
    }
  }else{
    ButtonSet = false;
  }

  //Serial.println(amountPlayer);

}

void SelectAmountPlayer (void){
  boolean Display = true;
  boolean Exit = false;
  static boolean ButtonSet = true;
  static boolean ButtonUp = false;
  static boolean ButtonDown = false;
  static boolean ButtonExit = false;

  byte Menu = 0;
  const char MenuText[9][17] = {" 1: 2 Player    ",
                                " 2: 3 Player    ",
                                " 3: 4 Player    ",
                                " 4: 5 Player    ",
                                " 5: 6 Player    ",
                                " 6: 7 Player    ",
                                " 7: 8 Player    ",
                                " 8: 9 Player    ",
                                " 9: 10 Player   "};
  while(Exit == false){

    if(Display == true){
      Display = false;
      lcd.setCursor(0,0);
      lcd.print(" Amount Player  ");
      lcd.setCursor(0,1);
      lcd.print(MenuText[Menu]);
    }

    if(digitalRead(BUTTON_SET) == 0){
      delay(50);
      if(digitalRead(BUTTON_SET) == 0){
        if(ButtonSet == false){
          ButtonSet = true;
          switch(Menu){
            case 0 : SelectAmountCardPerPlayer(); amountPlayer = 2; break;
            case 1 : SelectAmountCardPerPlayer(); amountPlayer = 3; break;
            case 2 : SelectAmountCardPerPlayer(); amountPlayer = 4; break;
            case 3 : SelectAmountCardPerPlayer(); amountPlayer = 5; break;
            case 4 : SelectAmountCardPerPlayer(); amountPlayer = 6; break;
            case 5 : SelectAmountCardPerPlayer(); amountPlayer = 7; break;
            case 6 : SelectAmountCardPerPlayer(); amountPlayer = 8; break;
            case 7 : SelectAmountCardPerPlayer(); amountPlayer = 9; break;
            case 8 : SelectAmountCardPerPlayer(); amountPlayer = 10; break;
          }
        }
      }
    }else{
      ButtonSet = false;
    }

    if(digitalRead(BUTTON_UP) == 0){
      delay(50);
      if(digitalRead(BUTTON_UP) == 0){
        if(ButtonUp == false){
          ButtonUp = true;
          if(Menu > 0){
            Menu--;
          }else{
            Menu = 9;
          }
          Display = true;
        }
      }
    }else{
      ButtonUp = false;
    }

    if(digitalRead(BUTTON_DOWN) == 0){
      delay(50);
      if(digitalRead(BUTTON_DOWN) == 0){
        if(ButtonDown == false){
          ButtonDown = true;
          if(Menu < 9){
            Menu++;
          }else{
            Menu = 0;
          }
          Display = true;
        }
      }
    }else{
      ButtonDown = false;
    }

    if(digitalRead(BUTTON_EXIT) == 0){
      delay(50);
      if(digitalRead(BUTTON_EXIT) == 0){
        if(ButtonExit == false){
          ButtonExit = true;
          Exit = true;
        }
      }
    }else{
      ButtonExit = false;
    }
  }
}

void SelectAmountCardPerPlayer (void){
  boolean Display = true;
  boolean Exit = false;
  static boolean ButtonSet = true;
  static boolean ButtonUp = false;
  static boolean ButtonDown = false;
  static boolean ButtonExit = false;
  byte Menu = 0;
  const char AmountCard[25][17] = {" 1: 1 Card      ",
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
                                   " 25: 25 Card    "};
  while(Exit == false){

    if(Display == true){
      Display = false;
      lcd.setCursor(0,0);
      lcd.print(" Amount of Card ");
      lcd.setCursor(0,1);
      lcd.print(AmountCard[Menu]);
    }

    if(digitalRead(BUTTON_SET) == 0){
      delay(50);
      if(digitalRead(BUTTON_SET) == 0){
        if(ButtonSet == false){
          ButtonSet = true;
          switch(Menu){
            case 0: Serial.println("You Select Menu 1"); dealing(amountPlayer, 1); break;
            case 1: Serial.println("You Select Menu 2"); dealing(amountPlayer, 2); break;
            case 2: Serial.println("You Select Menu 3"); dealing(amountPlayer, 3); break;
            case 3: Serial.println("You Select Menu 4"); dealing(amountPlayer, 4); break;
            case 4: Serial.println("You Select Menu 5"); dealing(amountPlayer, 5); break;
            case 5: Serial.println("You Select Menu 6"); dealing(amountPlayer, 6); break;
            case 6: Serial.println("You Select Menu 7"); dealing(amountPlayer, 7); break;
            case 7: Serial.println("You Select Menu 8"); dealing(amountPlayer, 8); break;
            case 8: Serial.println("You Select Menu 9"); dealing(amountPlayer, 9); break;
            case 9: Serial.println("You Select Menu 0"); dealing(amountPlayer, 10); break;
          }
        }
      }
    }else{
      ButtonSet = false;
    }

    if(digitalRead(BUTTON_UP) == 0){
      delay(50);
      if(digitalRead(BUTTON_UP) == 0){
        if(ButtonUp == false){
          ButtonUp = true;
          if(Menu > 0){
            Menu--;
          }else{
            Menu = 24;
          }
          Display = true;
        }
      }
    }else{
      ButtonUp = false;
    }

    if(digitalRead(BUTTON_DOWN) == 0){
      delay(50);
      if(digitalRead(BUTTON_DOWN) == 0){
        if(ButtonDown == false){
          ButtonDown = true;
          if(Menu < 24){
            Menu++;
          }else{
            Menu = 0;
          }
          Display = true;
        }
      }
    }else{
      ButtonDown = false;
    }

    if(digitalRead(BUTTON_EXIT) == 0){
      delay(50);
      if(digitalRead(BUTTON_EXIT) == 0){
        if(ButtonExit == false){
          ButtonExit = true;
          Exit = true;
        }
      }
    }else{
      ButtonExit = false;
    }
  }
}

void dealing(int player, int card){

  int angle = 0;
  angle = 2048/player;

  for(int cardIndex = 0; cardIndex < card; cardIndex++){
    for(int playerIndex = 0; playerIndex < player; playerIndex++){
      for(int stepIndex = 0; stepIndex < angle; stepIndex++){
        //OneStep2Phase(CCW);
        OneStep(CCW);
        delay(step_delay);
      }
      digitalWrite(DC_Motor, HIGH);
      delay(1000);
      digitalWrite(DC_Motor, LOW);
    }
  }
  stopMotor();
  delay(500);

  Serial.println(player);
}
