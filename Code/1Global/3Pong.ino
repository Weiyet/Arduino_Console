int paddle1X = 150;
int paddle1Y = 0;
int oldPaddle1X, oldPaddle1Y;
int paddle2X = 150;
int paddle2Y = 235;
int oldPaddle2X, oldPaddle2Y;
int ballDirectionX = 1;
int ballDirectionY = 1;
int score1=0;
int score2=0;
int Pong_old=0;
int Pong_new1=1;
int Pong_score=0;
int Pong_mode=0;
  
#define rectWidth 55
#define rectHeight 5

int ballSpeed = 1; 

int ballX, ballY, oldBallX, oldBallY;

void Pong_Select()
{
  if (btnUP1.pressed())
        {
          Pong_old = Pong_new1;
          Pong_new1 = Pong_old - 1;
          switch (Pong_old)
        {
          case 0:
            myGLCD.setColor(255, 255, 255);
            myGLCD.drawRect (20, 194, 305, 226);
            break;
          case 1:
            myGLCD.setColor(255, 255, 255);
            myGLCD.drawRect(20, 152, 305, 184);
            break;
          case 2:
            myGLCD.setColor(255, 255, 255);;
            myGLCD.drawRect(20, 194, 305, 226);
            break;
          case 3:
            myGLCD.setColor(255, 255, 255);
            myGLCD.drawRect (20, 152,305, 184);
            break;
          default:
            break;
        }



        switch (Pong_new1)
        {
          case 0:
            myGLCD.setColor(255, 0, 0);
            myGLCD.drawRect (20, 194, 305, 226);
            Pong_new1 = 2;
            break;
          case 1:
            myGLCD.setColor(255, 0, 0);
            myGLCD.drawRect(20, 152, 305, 184);
            break;
          case 2:
            myGLCD.setColor(255, 0, 0);
            myGLCD.drawRect(20, 194, 305, 226);
            break;
          case 3:
            myGLCD.setColor(255, 0, 0);
            myGLCD.drawRect (20, 152, 305, 184);
            Pong_new1 = 1;
            break;
          default:
            break;
        } 
        }
   
   if (btnDOWN1.pressed())
        {
          Pong_old = Pong_new1;
          Pong_new1 = Pong_old + 1;
          switch (Pong_old)
        {
          case 0:
            myGLCD.setColor(255, 255, 255);
            myGLCD.drawRect (20, 194, 305, 226);
            break;
          case 1:
            myGLCD.setColor(255, 255, 255);;
            myGLCD.drawRect(20, 152, 305, 184);
            break;
          case 2:
            myGLCD.setColor(255, 255, 255);
            myGLCD.drawRect (20, 194, 305, 226);
            break;
          case 3:
            myGLCD.setColor(255, 255, 255);
            myGLCD.drawRect(20, 152, 305, 184);
            break;
          default:
            break;
        }



        switch (Pong_new1)
        {
          case 0:
            myGLCD.setColor(255, 0, 0);
            myGLCD.drawRect (20, 194, 305, 226);
            Pong_new1 = 2;
            break;
          case 1:
            myGLCD.setColor(255, 0, 0);
            myGLCD.drawRect(20, 152, 305, 184);
            break;
          case 2:
            myGLCD.setColor(255, 0, 0);
            myGLCD.drawRect (20, 194, 305, 226);
            break;
          case 3:
            myGLCD.setColor(255, 0, 0);
            myGLCD.drawRect(20,152 , 305, 184);
            Pong_new1 = 1;
            break;
          default:
            break;
        } 
        }
}


void Pong_StartScreen()
{ 
  paddle1X = 150;
 paddle1Y = 0;
 oldPaddle1X=0; 
 oldPaddle1Y=0;
 paddle2X = 150;
 paddle2Y = 235;
 oldPaddle2X=0;
 oldPaddle2Y=0;
 ballDirectionX = 1;
 ballDirectionY = 1;
 Pong_mode=0;
 Pong_old=0;
 Pong_new1=1;
 Pong_score=0;
  Pong_Reset();
  score1=0;
  score2=0;
  myGLCD.setBackColor(0,0,0 );
   myGLCD.setColor(16, 167, 103); // Sets green color
   myGLCD.fillRoundRect (20, 60, 305, 110); // Draws filled rounded rectangle
   myGLCD.setColor(255, 255, 255); // Sets color to white
   myGLCD.drawRoundRect (20, 60, 305, 110); // Draws rounded rectangle without a fill, so the overall appearance of the button looks like it has a frame
   myGLCD.setFont(BigFont); // Sets the font to big
   myGLCD.setBackColor(16, 167, 103); // Sets the background color of the area where the text will be printed to green, same as the button
   myGLCD.setFont(BigFont);
   myGLCD.print("PONG",CENTER, 80);

       myGLCD.setColor(82, 76, 100); // Sets green color
  myGLCD.fillRoundRect (20, 152, 305, 184); // Draws filled rounded rectangle
  myGLCD.setColor(255, 0, 0); // Sets color to white
  myGLCD.drawRoundRect (20, 152, 305, 184); // Draws rounded rectangle without a fill, so the overall appearance of the button looks like it has a frame
  myGLCD.setFont(BigFont); // Sets the font to big
   myGLCD.setColor(255, 255, 255); // Sets color to white
  myGLCD.setBackColor(82, 76, 100); // Sets the background color of the area where the text will be printed to green, same as the button
  myGLCD.print("Singleplayer", CENTER, 159); // Prints the string
  
  myGLCD.setColor(82,76,100); // Sets green color
  myGLCD.fillRoundRect (20, 194, 305, 226); // Draws filled rounded rectangle
  myGLCD.setColor(255, 255, 255); // Sets color to white
  myGLCD.drawRoundRect (20, 194, 305, 226); // Draws rounded rectangle without a fill, so the overall appearance of the button looks like it has a frame
  myGLCD.setFont(BigFont); // Sets the font to big
  myGLCD.setBackColor(82,76,100); // Sets the background color of the area where the text will be printed to green, same as the button
  myGLCD.print("Multiplayer", CENTER, 201); // Prints the string

   while (Pong_mode==0) {
    {Pong_Select();
     if (btnA1.pressed())
        { myGLCD.clrScr();
          if (Pong_new1 == 1)
            Pong_mode = 1;
          if (Pong_new1 == 2)
            Pong_mode = 2;
        }}
  }
  myGLCD.clrScr();}

void drawPaddle()
{ myGLCD.setColor(0, 0, 0);
  if (oldPaddle1X != paddle1X || oldPaddle1Y != paddle1Y) {
 myGLCD.fillRoundRect(oldPaddle1X, oldPaddle1Y, oldPaddle1X+rectWidth, oldPaddle1Y+rectHeight);
 }
 if(Pong_mode==2){
 if (oldPaddle2X != paddle2X || oldPaddle2Y != paddle2Y) {
 myGLCD.fillRoundRect(oldPaddle2X, oldPaddle2Y, oldPaddle2X+rectWidth, oldPaddle2Y+rectHeight);
 }}

 myGLCD.setColor(255, 255, 255);

 if(Pong_mode==2){
 myGLCD.fillRoundRect(paddle2X, paddle2Y,  paddle2X+rectWidth, paddle2Y+rectHeight);
 oldPaddle2X = paddle2X;
 oldPaddle2Y = paddle2Y;}
 
 myGLCD.fillRoundRect(paddle1X, paddle1Y, paddle1X+rectWidth, paddle1Y+rectHeight);
 oldPaddle1X = paddle1X;
 oldPaddle1Y = paddle1Y;
 }
  
 void Pong_Reset()
{
 ballX = 160;
 ballY = 120; 
 ballDirectionX = random(-5,5);
 ballDirectionY = random(-1,1);
 while( ballDirectionX == 0 ) {
  ballDirectionX = random(-5,5);}
 if ( ballDirectionY == 0 ) {
 ballDirectionY = -1;
 }
 else 
 {
 ballDirectionY = 1;
 }
 ballSpeed = 20;
}



// this function determines the ball's position on screen
 

boolean inPaddle(int x, int y, int rectX, int rectY) {
 boolean result = false;

 if ((x >= rectX && x <= (rectX + rectWidth)) &&
 (y >= rectY && y <= (rectY + rectHeight))) {
 result = true;
 }

 return result;
 

}

void Pong_EndScreen()
{ 
  myGLCD.clrScr();
  /* char scoreChars[1];
  String scorestring ;
  myGLCD.setFont(SevenSegNumFont);
    scorestring = String(score1);
    scorestring.toCharArray(scoreChars, 2);
  myGLCD.print(scoreChars, 110, 50);
  myGLCD.setFont(BigFont);
 myGLCD.print(":", CENTER, 70);
     scorestring = String(score1);
    scorestring.toCharArray(scoreChars, 2);
  myGLCD.setFont(SevenSegNumFont);
  myGLCD.print(scoreChars, 180, 50);*/
  myGLCD.setFont(BigFont);

 if(Pong_mode==1){
  myGLCD.print("Game over", CENTER, 40);
  myGLCD.print("Score:", CENTER, 80);
  myGLCD.setFont(SevenSegNumFont);
  myGLCD.setBackColor(0, 0, 0);
  char scoreChars[5];
  String scorestring = String(Pong_score); /*to print the score*/ /*for tft screen need to be change to char for displaying*/
  scorestring.toCharArray(scoreChars, 5);
  myGLCD.print(scoreChars, CENTER + 1, 60);}

  else if(Pong_mode==2){
  if(score1==5)
  myGLCD.print("Player 1 wins", CENTER, 100);
  if(score2==5)
  myGLCD.print("Player 2 wins", CENTER, 100);
  }
  myGLCD.setFont(SmallFont);
  myGLCD.print("press any  button to continue", CENTER, 200);
  while(digitalRead(btnLEFT_P1)==HIGH&&digitalRead(btnUP_P1)==HIGH&&digitalRead(btnDOWN_P1)==HIGH&&digitalRead(btnRIGHT_P1)==HIGH&&digitalRead(btnA_P1)==HIGH&&digitalRead(btnB_P1)==HIGH);
  myGLCD.clrScr();
}

void showScore()
{ 
    char scoreChars[1];
  String scorestring ;
  myGLCD.setBackColor(0, 0, 0);
  scorestring = String(score1);
  myGLCD.setFont(SevenSegNumFont);
 scorestring.toCharArray(scoreChars, 2);
  myGLCD.print(scoreChars, 110, 80);
  myGLCD.setFont(BigFont);
  myGLCD.print(":", CENTER, 100);
 scorestring = String(score2);/*to print the score*/ /*for tft screen need to be change to char for displaying*/
  scorestring.toCharArray(scoreChars, 2);
  myGLCD.setFont(SevenSegNumFont);
  myGLCD.print(scoreChars, 180, 80);
  delay(800);
  myGLCD.setColor(0, 0, 0);
   myGLCD.setBackColor(0, 0, 0);
 scorestring = String(score1);
  myGLCD.setFont(SevenSegNumFont);
 scorestring.toCharArray(scoreChars, 2);
  myGLCD.print(scoreChars, 110,80);
  myGLCD.setFont(BigFont);
  myGLCD.print(":", CENTER, 100);
  scorestring = String(score2);/*to print the score*/ /*for tft screen need to be change to char for displaying*/
  scorestring.toCharArray(scoreChars, 2);
  myGLCD.setFont(SevenSegNumFont);
  myGLCD.print(scoreChars, 180, 80);
}

void moveBall() {
 // if the ball goes offscreen, Pong_Reset the game

 if(Pong_mode==2){
 if (ballX > 319 || ballX < 0) {
 ballDirectionX = -ballDirectionX;
 }

 if (ballY > 239 ){
 score1++;
 showScore();
 Pong_Reset();
 
 }

 if (ballY < 1) {
 score2++;
 showScore();
 Pong_Reset();
 
 }

 // check if the ball and the paddle occupy the same space on screen
    if (inPaddle(ballX, ballY, paddle1X, paddle1Y)) {
 ballDirectionX = random(-5,5);
 ballDirectionY = -ballDirectionY;
 }

 
 if (inPaddle(ballX, ballY, paddle2X, paddle2Y)) {
 ballDirectionX = random(-5,5);
 ballDirectionY = -ballDirectionY;
 }}

 else if(Pong_mode==1)
 {
  if (ballX > 319 || ballX < 0) {
 ballDirectionX = -ballDirectionX;
 }

 if (ballY > 239 ){
  ballDirectionX = random(-5,5);
 ballDirectionY = -ballDirectionY;
 }

 // check if the ball and the paddle occupy the same space on screen
    if (inPaddle(ballX, ballY, paddle1X, paddle1Y)) {
 ballDirectionX = random(-5,5);
 ballDirectionY = -ballDirectionY;
 Pong_score++;
 }}
 

 // update the ball's position
 ballX += ballDirectionX;
 ballY += ballDirectionY;

 // erase the ball's previous position
 myGLCD.setColor(0, 0, 0);

 if (oldBallX != ballX || oldBallY != ballY) {
 myGLCD.fillCircle(oldBallX, oldBallY, 5);
 }


 // draw the ball's current position
 myGLCD.setColor(255, 255, 255);
 myGLCD.fillCircle(ballX, ballY, 5);

 oldBallX = ballX;
 oldBallY = ballY;



}

void Pong_Game(){
 Pong_StartScreen(); 
 timestamp=millis();
 
 if(Pong_mode==2){
 while(score1!=5&&score2!=5)
 {
 if(digitalRead(btnLEFT_P1)==LOW&&paddle1X>=6)
 paddle1X -=2; 
 if(digitalRead(btnRIGHT_P1)==LOW&&paddle1X<(315-rectWidth))
 paddle1X +=2; 
  if(digitalRead(btnLEFT_P2)==LOW&&paddle2X>=6)
  paddle2X -=2; 
 if(digitalRead(btnRIGHT_P2)==LOW&&paddle2X<(315-rectWidth))
 paddle2X +=2;
 drawPaddle();
 if (millis() - timestamp > 10) {
 timestamp=millis();
 moveBall();
 }
}}

 else if(Pong_mode==1){
 while(ballY>1)
 {
 if(digitalRead(btnLEFT_P1)==LOW&&paddle1X>=6)
 paddle1X -=2; 
 if(digitalRead(btnRIGHT_P1)==LOW&&paddle1X<(315-rectWidth))
 paddle1X +=2; 
 drawPaddle();
 if (millis() - timestamp > 10) {
 timestamp=millis();
 moveBall();
 }
}}
if(k)
Pong_EndScreen();
}
