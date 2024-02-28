#define DC_Motor1 4
#define DC_Motor2 15

void dc_rotate(){
  digitalWrite(DC_Motor1, HIGH);
  digitalWrite(DC_Motor2, LOW);
  delay(100);
  digitalWrite(DC_Motor1, LOW);
  digitalWrite(DC_Motor2, LOW);
}