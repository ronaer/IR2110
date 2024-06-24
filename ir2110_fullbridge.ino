/*
    ____       __________              _ __  
   / __ \_____/_  __/ __ \____  ____  (_) /__
  / / / / ___/ / / / /_/ / __ \/ __ \/ / //_/
 / /_/ / /  _ / / / _, _/ /_/ / / / / / ,<   
/_____/_/  (_)_/ /_/ |_|\____/_/ /_/_/_/|_|  

 Schematic:https://github.com/ronaer/IR2110/blob/main/IR2110_final.pdf
                                             
 Modified from:____________________________
 Driver demo routine for IR2110 h-bridge.
 2 NO pushbutton switches connected D2, D3 to GND.
 by Lewis Loflin lewis@bvu.net
 http://www.bristolwatch.com/ele4/IR2110.htm
*/

#define U1HIN 5  // pwm U1 HI MOSFET Q1
#define U2HIN 6  // pwm U2 HI MOSFET Q3
#define U1LIN 7  // input U1 LO MOSFET Q2
#define U2LIN 8  // input U2 LO MOSFET Q4

#define POT 0

#define SW1 2
#define SW2 3

int val;

void setup() {
  pinMode(U1HIN, OUTPUT);
  pinMode(U2HIN, OUTPUT);
  pinMode(U1LIN, OUTPUT);
  pinMode(U2LIN, OUTPUT);

  digitalWrite(U1HIN, LOW);
  digitalWrite(U2HIN, LOW);
  digitalWrite(U1LIN, LOW);
  digitalWrite(U2LIN, LOW);

  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);
}

void loop() {

  analogWrite(U1HIN, 0);
  analogWrite(U2HIN, 0);

  // U1HIN HIGH and U2LIN HIGH
  // U1LIN LOW and U2HIN LOW
  while (!digitalRead(SW1)) {
    digitalWrite(U1LIN, LOW);
    digitalWrite(U2HIN, LOW);
    val = analogRead(POT) / 4;
    analogWrite(U1HIN, val);
    digitalWrite(U2LIN, HIGH);
  }

  // U1HIN LOW and U2LIN LOW
  // U1LIN HIGH and U2HIN HIGH
  while (!digitalRead(SW2)) {
    digitalWrite(U1HIN, LOW);
    digitalWrite(U2LIN, LOW);
    val = analogRead(POT) / 4;
    analogWrite(U2HIN, val);
    digitalWrite(U1LIN, HIGH);
  }
}
