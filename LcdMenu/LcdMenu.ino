#include <LCD_I2C.h>
#include "RTClib.h"

RTC_DS1307 rtc;
char daysOfTheWeek[7][12] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

LCD_I2C lcd(0x27, 16, 2);

#define BUTTON_SET 32
#define BUTTON_UP 33
#define BUTTON_DOWN 25
#define BUTTON_EXIT 26

void setup() {
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();

  pinMode(BUTTON_SET,INPUT_PULLUP);
  pinMode(BUTTON_UP,INPUT_PULLUP);
  pinMode(BUTTON_DOWN,INPUT_PULLUP);
  pinMode(BUTTON_EXIT,INPUT_PULLUP);
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
    delay(5);
    if(digitalRead(BUTTON_SET) == 0){
      if(ButtonSet == false){
        ButtonSet = true;
        Select2Way();
        Display = true;
      }
    }
  }else{
    ButtonSet = false;
  }

}

void Select2Way (void){
  boolean Display = true;
  boolean Exit = false;
  static boolean ButtonSet = true;
  static boolean ButtonUp = false;
  static boolean ButtonDown = false;
  static boolean ButtonExit = false;

  byte Menu = 0;
  const char MenuText[2][17] = {" 1: Clock       ",
                                " 2: SelectPlayer"
  };

  while(Exit == false){

    if(Display == true){
      Display = false;
      lcd.setCursor(0,0);
      lcd.print(" Select Menu 1-2");
      lcd.setCursor(0,1);
      lcd.print(MenuText[Menu]);
    }

    if(digitalRead(BUTTON_SET) == 0){
      delay(5);
      if(digitalRead(BUTTON_SET) == 0){
        if(ButtonSet == false){
          ButtonSet = true;
          switch(Menu){
            case 0: Clock(); break;
            case 1: SelectAmountPlayer(); break;
          }
        }
      }
    }else{
      ButtonSet = false;
    }

    if(digitalRead(BUTTON_UP) == 0){
      delay(5);
      if(digitalRead(BUTTON_UP) == 0){
        if(ButtonUp == false){
          ButtonUp = true;
          if(Menu > 0){
            Menu--;
          }else{
            Menu = 1;
          }
          Display = true;
        }
      }
    }else{
      ButtonUp = false;
    }

    if(digitalRead(BUTTON_DOWN) == 0){
      delay(5);
      if(digitalRead(BUTTON_DOWN) == 0){
        if(ButtonDown == false){
          ButtonDown = true;
          if(Menu < 1){
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
      delay(5);
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

void Clock (void){
  boolean Display = true;
  boolean Exit = false;
  static boolean ButtonSet = true;
  static boolean ButtonUp = false;
  static boolean ButtonDown = false;
  static boolean ButtonExit = false;

  byte Menu = 0;
  const char MenuText[2][17] = {" 1: Clock       ",
                                " 2: SelectPlayer"
  };

  while(Exit == false){
    DateTime now = rtc.now();
    if(Display == true){
      Display = false;
      lcd.setCursor(0,0);
      lcd.print(MenuText[0]);
      lcd.setCursor(0,1);
      lcd.print(daysOfTheWeek[now.dayOfTheWeek()]);
    }

    if(digitalRead(BUTTON_SET) == 0){
      delay(5);
      if(digitalRead(BUTTON_SET) == 0){
        if(ButtonSet == false){
          ButtonSet = true;
        }
      }
    }else{
      ButtonSet = false;
    }

    if(digitalRead(BUTTON_UP) == 0){
      delay(5);
      if(digitalRead(BUTTON_UP) == 0){
        if(ButtonUp == false){
          ButtonUp = true;
        }
      }
    }else{
      ButtonUp = false;
    }

    if(digitalRead(BUTTON_DOWN) == 0){
      delay(5);
      if(digitalRead(BUTTON_DOWN) == 0){
        if(ButtonDown == false){
          ButtonDown = true;
        }
      }
    }else{
      ButtonDown = false;
    }

    if(digitalRead(BUTTON_EXIT) == 0){
      delay(5);
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
      delay(5);
      if(digitalRead(BUTTON_SET) == 0){
        if(ButtonSet == false){
          ButtonSet = true;
          switch(Menu){
            case 0 : SelectAmountCardPerPlayer(); break;
            case 1 : SelectAmountCardPerPlayer(); break;
            case 2 : SelectAmountCardPerPlayer(); break;
            case 3 : SelectAmountCardPerPlayer(); break;
            case 4 : SelectAmountCardPerPlayer(); break;
            case 5 : SelectAmountCardPerPlayer(); break;
            case 6 : SelectAmountCardPerPlayer(); break;
            case 7 : SelectAmountCardPerPlayer(); break;
            case 8 : SelectAmountCardPerPlayer(); break;
            case 9 : SelectAmountCardPerPlayer(); break;
          }
        }
      }
    }else{
      ButtonSet = false;
    }

    if(digitalRead(BUTTON_UP) == 0){
      delay(5);
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
      delay(5);
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
      delay(5);
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
      delay(5);
      if(digitalRead(BUTTON_SET) == 0){
        if(ButtonSet == false){
          ButtonSet = true;
          switch(Menu){
            case 0: Serial.println("You Select Menu 1"); break;
            case 1: Serial.println("You Select Menu 2"); break;
            case 2: Serial.println("You Select Menu 3"); break;
            case 3: Serial.println("You Select Menu 4"); break;
            case 4: Serial.println("You Select Menu 5"); break;
            case 5: Serial.println("You Select Menu 6"); break;
            case 6: Serial.println("You Select Menu 7"); break;
            case 7: Serial.println("You Select Menu 8"); break;
            case 8: Serial.println("You Select Menu 9"); break;
            case 9: Serial.println("You Select Menu 0"); break;
          }
        }
      }
    }else{
      ButtonSet = false;
    }

    if(digitalRead(BUTTON_UP) == 0){
      delay(5);
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
      delay(5);
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
      delay(5);
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
