#define h HIGH
#define l LOW

// Limit Switches
//
#define X_MIN_PIN           3
#define X_MAX_PIN           2
#define Y_MIN_PIN          14
#define Y_MAX_PIN          15
#define Z_MIN_PIN          18
#define Z_MAX_PIN          19

// Steppers
//
#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38
#define X_CS_PIN           53

#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56
#define Y_CS_PIN           49

#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62
#define Z_CS_PIN           40


//Zmienne globalne
int x, y, z;
int KrokiX = 0, KrokiY = 0, KrokiZ = 0;
bool flaga = true;
String s;
void setup() {
  // Krancowki
  Serial.begin(57600);
  pinMode(X_MAX_PIN, INPUT);
  digitalWrite(X_MAX_PIN, HIGH);

  pinMode(Y_MAX_PIN, INPUT);
  digitalWrite(Y_MAX_PIN, HIGH);

  pinMode(Z_MAX_PIN, INPUT);
  digitalWrite(Z_MAX_PIN, HIGH);

  //stepper

  pinMode(X_ENABLE_PIN, OUTPUT);
  digitalWrite(X_ENABLE_PIN, LOW);
  pinMode(X_DIR_PIN, l);
  pinMode(X_STEP_PIN, OUTPUT);

  pinMode(Y_ENABLE_PIN, OUTPUT);
  digitalWrite(Y_ENABLE_PIN, LOW);
  pinMode(Y_DIR_PIN, l);
  pinMode(Y_STEP_PIN, OUTPUT);

  pinMode(Z_ENABLE_PIN, OUTPUT);
  digitalWrite(Z_ENABLE_PIN, LOW);
  pinMode(Z_DIR_PIN, l);
  pinMode(Z_STEP_PIN, OUTPUT);

}

void loop() {
  //Czytanie Krancowek
  x = digitalRead(X_MAX_PIN);
  y = digitalRead(Y_MAX_PIN);
  z = digitalRead(Z_MAX_PIN);

  while (Serial.available() > 0)
  {
    s = Serial.readStringUntil('\n');
    sscanf(s.c_str(), "x %d y %d z %d \n", &KrokiX, &KrokiY, &KrokiZ);
    flaga = false;

    if (KrokiX < 0 )
    {
      KrokiX = -KrokiX;
      digitalWrite(X_DIR_PIN, HIGH);
    }
    else
    {
      digitalWrite(X_DIR_PIN, LOW);
    }
    if (KrokiY < 0 )
    {
      KrokiY = -KrokiY;
      digitalWrite(Y_DIR_PIN, HIGH);
    }
    else
    {
      digitalWrite(Y_DIR_PIN, LOW);
    }

    if (KrokiZ < 0 )
    {
      KrokiZ = -KrokiZ;
      digitalWrite(Z_DIR_PIN, HIGH);

    }
    else
    {
      digitalWrite(Z_DIR_PIN, LOW);
    }
  }


  //  Serial.print("X:");
  //  Serial.print(x);
  //  Serial.print("; Y:");
  //  Serial.print(y);
  //  Serial.print("; Z:");
  //  Serial.print(z);
  //  Serial.println();

  //poruszanie

  if (!x && KrokiX > 0)
  {
    digitalWrite(X_STEP_PIN, HIGH);
    KrokiX--;
  }
  if (!y && KrokiY > 0)
  {
    digitalWrite(Y_STEP_PIN, HIGH);
    KrokiY--;
  }
  if (!z && KrokiZ > 0)
  {
    digitalWrite(Z_STEP_PIN, HIGH);
    KrokiZ--;
  }
  //delayMicroseconds(500);
  digitalWrite(X_STEP_PIN, LOW);
  digitalWrite(Y_STEP_PIN, LOW);
  digitalWrite(Z_STEP_PIN, LOW);
  delayMicroseconds(500);

  if(KrokiX == 0 && KrokiY == 0 && KrokiZ == 0 && !flaga)
  {
  Serial.println("OK");
  flaga = true;  
  }

   

}
