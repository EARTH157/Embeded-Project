//Written By Saroj Meesook - www.arduino108.com
#define PHASE_A1_PLUS  17
#define PHASE_B3_PLUS 5
#define PHASE_A2_MINUS 18
#define PHASE_B4_MINUS  19

int step_number = 0;
int step_delay =2;

LCD_I2C lcd(0x27, 16, 2); // Default address of most PCF8574 modules, change according

void setup() {
  pinMode(PHASE_A1_PLUS, OUTPUT);
  pinMode(PHASE_B3_PLUS, OUTPUT);
  pinMode(PHASE_A2_MINUS, OUTPUT);
  pinMode(PHASE_B4_MINUS, OUTPUT);
}

bool CW=true;
bool CCW=false;

void loop() {

  for(int i=0; i<1024; i++){
    //OneStep2Phase(CW);
    OneStep(CW);
    delay(step_delay);
  }
  stopMotor();
  delay(1000);
 
  for(int i=0; i<1024; i++){
    //OneStep2Phase(CCW);
    OneStep(CCW);
    delay(step_delay);
  } 
  stopMotor();
  delay(1000);

}

void stopMotor(){
  digitalWrite(PHASE_A1_PLUS, LOW);
  digitalWrite(PHASE_B3_PLUS, LOW);
  digitalWrite(PHASE_A2_MINUS, LOW);
  digitalWrite(PHASE_B4_MINUS, LOW);
}

void OneStep2Phase(bool dir){
  switch(step_number){
  case 0:
     digitalWrite(PHASE_A1_PLUS, HIGH);
     digitalWrite(PHASE_B3_PLUS, HIGH);
     digitalWrite(PHASE_A2_MINUS, LOW);
     digitalWrite(PHASE_B4_MINUS, LOW);
     break;
  case 1:
     digitalWrite(PHASE_A1_PLUS, LOW);
     digitalWrite(PHASE_B3_PLUS, HIGH);
     digitalWrite(PHASE_A2_MINUS, HIGH);
     digitalWrite(PHASE_B4_MINUS, LOW);
     break;
  case 2:
     digitalWrite(PHASE_A1_PLUS, LOW);
     digitalWrite(PHASE_B3_PLUS, LOW);
     digitalWrite(PHASE_A2_MINUS, HIGH);
     digitalWrite(PHASE_B4_MINUS, HIGH);
     break;
  case 3:
     digitalWrite(PHASE_A1_PLUS, HIGH);
     digitalWrite(PHASE_B3_PLUS, LOW);
     digitalWrite(PHASE_A2_MINUS, LOW);
     digitalWrite(PHASE_B4_MINUS, HIGH);
     break;
  } 
  if(dir){   //1= CW
    step_number++;
    if(step_number > 3){
      step_number = 0;
    }
  }else {  // CCW
    step_number--;
    if(step_number<0){
      step_number=3;
    }
  }
}

void OneStep(bool dir){
  switch(step_number){
    case 0:
      digitalWrite(PHASE_A1_PLUS, HIGH);
      digitalWrite(PHASE_B3_PLUS, LOW);
      digitalWrite(PHASE_A2_MINUS, LOW);
      digitalWrite(PHASE_B4_MINUS, LOW);
    break;
    case 1:
      digitalWrite(PHASE_A1_PLUS, LOW);
      digitalWrite(PHASE_B3_PLUS, HIGH);
      digitalWrite(PHASE_A2_MINUS, LOW);
      digitalWrite(PHASE_B4_MINUS, LOW);
      break;
    case 2:
      digitalWrite(PHASE_A1_PLUS, LOW);
      digitalWrite(PHASE_B3_PLUS, LOW);
      digitalWrite(PHASE_A2_MINUS, HIGH);
      digitalWrite(PHASE_B4_MINUS, LOW);
      break;
    case 3:
      digitalWrite(PHASE_A1_PLUS, LOW);
      digitalWrite(PHASE_B3_PLUS, LOW);
      digitalWrite(PHASE_A2_MINUS, LOW);
      digitalWrite(PHASE_B4_MINUS, HIGH);
      break;
  } 

  if(dir){   //1= CW
    step_number++;
    if(step_number > 3){
      step_number = 0;
    }
  }else {  // CCW
    step_number--;
    if(step_number<0){
      step_number=3;
    }
  }
}