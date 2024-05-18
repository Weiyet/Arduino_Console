void setup() {
  Serial.begin(9600);
  btnUP1.begin();
  btnDOWN1.begin();
  btnLEFT1.begin();
  btnRIGHT1.begin();
  btnA1.begin();
  pinMode(btnHOME, INPUT_PULLUP);
  pinMode(btnUP_P2, INPUT_PULLUP);
  pinMode(btnDOWN_P2, INPUT_PULLUP);
  pinMode(btnLEFT_P2, INPUT_PULLUP);
  pinMode(btnRIGHT_P2, INPUT_PULLUP);
   attachInterrupt(digitalPinToInterrupt(btnHOME),btnhome, FALLING);

  randomSeed(analogRead(0));
  myGLCD.InitLCD();
  myTouch.InitTouch();
  myTouch.setPrecision(PREC_HI);
  welcome();
  game=0;


}
void loop() {
  consoleState();
}
