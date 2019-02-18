

/*

void L_MOTOR(int pwm) {

  if (pwm < 0 ) {
    direct = CCW ;
    pwm = pwm * -1 ;
  }
  else {
    direct == CW ;
  }


  if (direct == CW)
  {
    digitalWrite(MOTOR_A1_PIN, LOW) ;
    digitalWrite(MOTOR_B1_PIN, HIGH) ;
  }
  else if (direct == CCW)
  {
    digitalWrite(MOTOR_A1_PIN, HIGH) ;
    digitalWrite(MOTOR_B1_PIN, LOW) ;
  }
  analogWrite(PWM_MOTOR_1, pwm);

}



void R_MOTOR(int pwm) {
  
  direct == CW ;
  
  if (pwm < 0 ) {
    direct = CCW ;
    pwm = pwm * -1 ;
  }
  else {
    direct == CW ;
  }


  if (direct == CW)
  {
    digitalWrite(MOTOR_A2_PIN, LOW);
    digitalWrite(MOTOR_B2_PIN, HIGH);
  }
  else if (direct == CCW)
  {
    digitalWrite(MOTOR_A2_PIN, HIGH);
    digitalWrite(MOTOR_B2_PIN, LOW);
  }
  analogWrite(PWM_MOTOR_2, pwm);
}
*/
 void enableMotors(){
    digitalWrite(EN_PIN_1, HIGH);
    digitalWrite(EN_PIN_2, HIGH); 
 }





void drive(int speed_a, int speed_b) {

  // Limit speed between -255 and 255
  speed_a = constrain(speed_a, -255, 255);
  speed_b = constrain(speed_b, -255, 255);

  // Set direction for motor A
  if ( speed_a == 0 ) {
     digitalWrite(MOTOR_A2_PIN, LOW);
    digitalWrite(MOTOR_B2_PIN, LOW);
  } else if ( speed_a > 0 ) {
    digitalWrite(MOTOR_A2_PIN, LOW);
    digitalWrite(MOTOR_B2_PIN, HIGH);
  } else {
    digitalWrite(MOTOR_A2_PIN, HIGH);
    digitalWrite(MOTOR_B2_PIN, LOW);
  }

  // Set direction for motor B
  if ( speed_b == 0 ) {
    digitalWrite(MOTOR_A1_PIN, LOW) ;
    digitalWrite(MOTOR_B1_PIN, LOW) ;
  } else if ( speed_b > 0 ) {
     digitalWrite(MOTOR_A1_PIN, LOW) ;
    digitalWrite(MOTOR_B1_PIN, HIGH) ;
  } else {
    digitalWrite(MOTOR_A1_PIN, HIGH) ;
    digitalWrite(MOTOR_B1_PIN, LOW) ;
  }

  // Set speed
  analogWrite(PWM_MOTOR_2, abs(speed_a));
  analogWrite(PWM_MOTOR_1, abs(speed_b));
}
