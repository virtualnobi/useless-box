// ---- functions to switch off again ------------------------------------------
void off_1() {
  for(int i = 50; i <= 130; i++){
    servoLid.write(i);
    delay(20);          
  }
  for(int i = 80; i >= 0; i--){
    servoFinger.write(i);
    delay(20);          
  }
  delay(100);
}

void off_2() {
  for(int i= 50; i<=130; i++){
    servoLid.write(i);
    delay(6);          
  }
  delay(550);
  servoFinger.write(10);
  delay(200);
  servoFinger.write(50);
  delay(250);
  servoFinger.write(5);
  delay(250);
  servoFinger.write(50);
  delay(250);
  servoFinger.write(0);
  delay(250);
}

void off_3() {
  for(int i= 50; i<=130; i++){
    servoLid.write(i);
    delay(6);          
  }
  delay(1550);
  servoLid.write(50);
  delay(1550);
  for(int i= 50; i<=130; i++){
    servoLid.write(i);
    delay(13);          
  }  
  delay(550);
  servoFinger.write(10);
  delay(550);
  servoFinger.write(0);
  delay(550);
}

void off_4() {
  for(int i= 50; i<=130; i++){
    servoLid.write(i);
    delay(50);          
  }
  delay(50);
  servoFinger.write(20);
  delay(550);
  servoFinger.write(MAX_ANGLE_FINGER);
  delay(550);
  servoFinger.write(0);
  delay(550);
}

void off_5() {
  for(int i= 50; i<=100; i++){
    servoLid.write(i);
    delay(20);          
  }
  delay(2000);
  for(int i= 100; i<=130; i++){
    servoLid.write(i);
    delay(10);          
  }      
  servoFinger.write(0);
  delay(550);
}

void off_6() {
  for(int i= 50; i<=80; i++){
    servoLid.write(i);
    delay(30);          
  }
  delay(3000);
  for(int i= 80; i<=100; i++){
    servoLid.write(i);
    delay(20);          
  }
  for(int i= 80; i>=20; i--){
    servoFinger.write(i);
    delay(30);          
  }
  delay(1550);
  for(int i= 20; i>=0; i--){
    servoFinger.write(i);
    delay(10);          
  }
  delay(50);
  for(int i= 0; i<=80; i++){
    servoFinger.write(i);
    delay(5);          
  }
  delay(50);
  for(int i= 100; i>=80; i--){
    servoLid.write(i);
    delay(20);          
  }
  delay(2550);    
}

void off_7() {
  for(int i= 50; i<=75; i++){
    servoLid.write(i);
    delay(50);          
  }
  delay(2000);
  for(int i= 75; i<=100; i++){
    servoLid.write(i);
    delay(20);          
  }
  for(int i= 80; i>=10; i--){
    servoFinger.write(i);
    delay(30);          
  }
  delay(2550);
  for(int i= 10; i>=0; i--){
    servoFinger.write(i);
    delay(8);          
  }
  delay(100);
  for(int i= 0; i<=80; i++){
    servoFinger.write(i);
    delay(5);          
  }
  delay(50);
  for(int i= 100; i>=80; i--){
    servoLid.write(i);
    delay(20);          
  }
  delay(2550);    
}

// ---- initialize list of functions

#define MAX_FUNCTION 7
offFunction offFunctions[MAX_FUNCTION] = {off_1, off_2, off_3, off_4, off_5, off_6, off_7};


