#include <LCD_I2C.h>

LCD_I2C lcd(0x27, 16, 2);

char key = '0' ;

void setup() {
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
}

void loop() {
  key = Serial.read();
  static boolean Display = true;
  static boolean ButtonSet = false;

  if(Display == true){
    Display = false;
    lcd.setCursor(0,0);
    lcd.print(" Hello Lcd 16x2 ");
    lcd.setCursor(0,1);
    lcd.print(" By Earth       ");
  }

  if(key == 48){
      if(ButtonSet == false){
        ButtonSet = true;
        SelectMenu();
        Display = true;
    }
  }else{
    ButtonSet = false;
  }
}

void SelectMenu (void){
  boolean Display = true;
  boolean Exit = false;
  boolean ButtonSet = false;
  boolean ButtonUp = false;
  boolean ButtonDown = false;
  boolean ButtonExit = false;

  byte Menu = 0;
  const char MenuText[4][17] = {" 1: Menu 1      "," 2: Menu 2      "," 3: Menu 3      "," 4: Menu 4      "};

  while(Exit == false){
    if(Display == true){
      Display = false;
      lcd.setCursor(0,0);
      lcd.print(" Select Menu 1-4 ");
      lcd.setCursor(0,1);
      lcd.print(MenuText[Menu]);
    }

    if(Serial.available() > 0){
      if(key == 49){
        if(ButtonSet == false){
          ButtonSet = true;
          switch(Menu){
            case 0: Serial.print("You Select Menu 1"); break;
            case 1: Serial.print("You Select Menu 2"); break;
            case 2: Serial.print("You Select Menu 3"); break;
            case 3: Serial.print("You Select Menu 4"); break;
          }
        }
      }
    }else{
      ButtonSet = false;
    }

    if(Serial.available() > 0){
      if(key == 50){
        if(ButtonUp == false){
          ButtonUp = true;
          if(Menu < 3){
            Menu++;
          }else{
            Menu = 0;
          }
          Display = true;
        }
      }
    }else{
      ButtonUp = false;
    }

    if(Serial.available() > 0){
      if(key == 51){
        if(ButtonDown == false){
          ButtonDown = true;
          if(Menu > 0){
            Menu--;
          }else{
            Menu = 3;
          }
          Display = true;
        }
      }
    }else{
      ButtonDown = false;
    }

    if(Serial.available() > 0){
      if(key == 52){
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
