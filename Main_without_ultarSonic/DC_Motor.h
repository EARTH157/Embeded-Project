int DC_Motor1 = 4;
int DC_Motor2 = 16;
int ENA = 25;


void dc_rotate(){
  // เดินหน้า 5 วินาที ด้วยความเร็วสูงสุด
  // set PWM speed เป็น 255
  analogWrite(ENA, 255);
  // มอเตอร์ 1 เดินหน้า
  digitalWrite(DC_Motor1, HIGH);
  digitalWrite(DC_Motor2, LOW);
  delay(300);
  // มอเตอร์ 1 ถอยหลัง
  digitalWrite(DC_Motor1, LOW);
  digitalWrite(DC_Motor2, HIGH);
  delay(300);
  digitalWrite(DC_Motor1, LOW);
  digitalWrite(DC_Motor2, LOW);
}