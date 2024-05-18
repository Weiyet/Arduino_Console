int game = -1;

int x, y;
int old = 0;
int new1 = 1;

void menu()
{ // Title
  myGLCD.setBackColor(0, 0, 0); // Sets the background color of the area where the text will be printed to black
  myGLCD.setColor(255, 255, 255); // Sets color to white
  myGLCD.setFont(BigFont); // Sets font to big
  myGLCD.print("Game Console", CENTER, 10); // Prints the string on the screen
  myGLCD.setColor(255, 0, 0); // Sets color to red
  myGLCD.drawLine(0, 32, 319, 32); // Draws the red line
  myGLCD.setColor(255, 255, 255); // Sets color to white
  myGLCD.setFont(SmallFont); // Sets the font to small
  myGLCD.print("by EEE NTU", CENTER, 41); // Prints the string
  myGLCD.setFont(BigFont);
  myGLCD.print("Select Example", CENTER, 64);

  //button-Snake
  myGLCD.setColor(16, 167, 103); // Sets green color
  myGLCD.fillRoundRect (20, 90, 305, 122); // Draws filled rounded rectangle
  myGLCD.setColor(255, 255, 255); // Sets color to white
  myGLCD.drawRoundRect (20, 90, 305, 122); // Draws rounded rectangle without a fill, so the overall appearance of the button looks like it has a frame
  myGLCD.setFont(BigFont); // Sets the font to big
  myGLCD.setBackColor(16, 167, 103); // Sets the background color of the area where the text will be printed to green, same as the button
  myGLCD.print("SNAKE", CENTER, 97); // Prints the string

  //button-Pong Pong
  myGLCD.setColor(16, 167, 103); // Sets green color
  myGLCD.fillRoundRect (20, 132, 305, 164); // Draws filled rounded rectangle
  myGLCD.setColor(255, 255, 255); // Sets color to white
  myGLCD.drawRoundRect (20, 132, 305, 164); // Draws rounded rectangle without a fill, so the overall appearance of the button looks like it has a frame
  myGLCD.setFont(BigFont); // Sets the font to big
  myGLCD.setBackColor(16, 167, 103); // Sets the background color of the area where the text will be printed to green, same as the button
  myGLCD.print("PONG", CENTER, 139); // Prints the string

  //button-Setting
  myGLCD.setColor(16, 167, 103); // Sets green color
  myGLCD.fillRoundRect (20, 174, 305, 206); // Draws filled rounded rectangle
  myGLCD.setColor(255, 255, 255); // Sets color to white
  myGLCD.drawRoundRect (20, 174, 305, 206); // Draws rounded rectangle without a fill, so the overall appearance of the button looks like it has a frame
  myGLCD.setFont(BigFont); // Sets the font to big
  myGLCD.setBackColor(16, 167, 103); // Sets the background color of the area where the text will be printed to green, same as the button
  myGLCD.print("SETTING", CENTER, 181); // Prints the string

  myGLCD.setColor(255, 0, 0);
  myGLCD.drawRect(20, 90, 305, 122);

  old = 0;
  new1 = 1;
}


void consoleState() {

  switch (game)
  {
    case 0:
      { 
        if (j)
        { menu();
          j--;
          k=1;
        }
        Menu_getinput();
        if (btnA1.pressed())
        { myGLCD.clrScr();
          delay(500);
          if (new1 == 1)
            game = 1;
          else if (new1 == 2)
            game = 2;
            else if (new1 == 3)
            game = 3;
          j = 1;
        } break;
      }
    case 1:
      {
        Snake_Game();
        break;
      }
    case 2:
      {
        Pong_Game();
        break;
      }
    case 3:
      {
        Setting();
        break;
      }
    default:
      break;
  }
}




void Menu_getinput()
{
 if (myTouch.dataAvailable())
    {
      myTouch.read();
      x=myTouch.getX();
      y=myTouch.getY();
  if(x>=20&&x<=305)
     {if(y>=90&&y<=122)
        {
        game=1;
        myGLCD.clrScr();
        }
      else if(y>=132&&y<=164)
         {
          myGLCD.clrScr();
          game=2;
         }
       else if(y>=174&&y<=206)
         {
          myGLCD.clrScr();
          game=3;
         }
     }}    
 if (btnUP1.pressed())
        {
          old = new1;
          new1 = old - 1;
          switch (old)
        {
          case 0:
            myGLCD.setColor(255, 255, 255);
            myGLCD.drawRect (20, 174, 305, 206);
            break;
          case 1:
            myGLCD.setColor(255, 255, 255);
            myGLCD.drawRect(20, 90, 305, 122);
            break;
          case 2:
            myGLCD.setColor(255, 255, 255);;
            myGLCD.drawRect(20, 132, 305, 164);
            break;
          case 3:
            myGLCD.setColor(255, 255, 255);
            myGLCD.drawRect (20, 174, 305, 206);
            break;
          case 4:
            myGLCD.setColor(255, 255, 255);
            myGLCD.drawRect(20, 90, 305, 122);
            break;
          default:
            break;
        }



        switch (new1)
        {
          case 0:
            myGLCD.setColor(255, 0, 0);
            myGLCD.drawRect (20, 174, 305, 206);
            new1 = 3;
            break;
          case 1:
            myGLCD.setColor(255, 0, 0);
            myGLCD.drawRect(20, 90, 305, 122);
            break;
          case 2:
            myGLCD.setColor(255, 0, 0);
            myGLCD.drawRect(20, 132, 305, 164);
            break;
          case 3:
            myGLCD.setColor(255, 0, 0);
            myGLCD.drawRect (20, 174, 305, 206);
            break;
          case 4:
            myGLCD.setColor(255, 0, 0);
            myGLCD.drawRect(20, 90, 305, 122);
            new1 = 1;
            break;
          default:
            break;
        } 
        }
        if (btnDOWN1.pressed())
        {
          old = new1;
          new1 = old + 1;
          switch (old)
        {
          case 0:
            myGLCD.setColor(255, 255, 255);
            myGLCD.drawRect (20, 174, 305, 206);
            break;
          case 1:
            myGLCD.setColor(255, 255, 255);
            myGLCD.drawRect(20, 90, 305, 122);
            break;
          case 2:
            myGLCD.setColor(255, 255, 255);;
            myGLCD.drawRect(20, 132, 305, 164);
            break;
          case 3:
            myGLCD.setColor(255, 255, 255);
            myGLCD.drawRect (20, 174, 305, 206);
            break;
          case 4:
            myGLCD.setColor(255, 255, 255);
            myGLCD.drawRect(20, 90, 305, 122);
            break;
          default:
            break;
        }



        switch (new1)
        {
          case 0:
            myGLCD.setColor(255, 0, 0);
            myGLCD.drawRect (20, 174, 305, 206);
            new1 = 3;
            break;
          case 1:
            myGLCD.setColor(255, 0, 0);
            myGLCD.drawRect(20, 90, 305, 122);
            break;
          case 2:
            myGLCD.setColor(255, 0, 0);
            myGLCD.drawRect(20, 132, 305, 164);
            break;
          case 3:
            myGLCD.setColor(255, 0, 0);
            myGLCD.drawRect (20, 174, 305, 206);
            break;
          case 4:
            myGLCD.setColor(255, 0, 0);
            myGLCD.drawRect(20, 90, 305, 122);
            new1 = 1;
            break;
          default:
            break;
        } 
        }
}

void welcome()
{
  myGLCD.fillScr(255, 255, 255);
  myGLCD.setColor(255, 0, 0); // Sets color to white
  myGLCD.setBackColor(255, 255, 255);
  myGLCD.setFont(BigFont); // Sets font to big
  myGLCD.print("W", 60, 100);
  delay(200);
  myGLCD.setColor(255, 127, 0); // Sets color to white
  myGLCD.setBackColor(255, 255, 255);
  myGLCD.print("E", 90, 100);
  delay(200);
  myGLCD.setColor(255, 255, 0); // Sets color to white
  myGLCD.setBackColor(255, 255, 255);
  myGLCD.print("L", 120, 100);
  delay(200);
  myGLCD.setColor(0, 0, 255); // Sets color to white
  myGLCD.setBackColor(255, 255, 255);
  myGLCD.print("C", 150, 100);
  delay(200);
  myGLCD.setColor(0, 255, 0); // Sets color to white
  myGLCD.setBackColor(255, 255, 255);
  myGLCD.print("O", 180, 100);
  delay(200);
  myGLCD.setColor(75, 0, 130); // Sets color to white
  myGLCD.setBackColor(255, 255, 255);
  myGLCD.print("M", 210, 100);
  delay(200);
  myGLCD.setColor(148, 0, 211); // Sets color to white
  myGLCD.setBackColor(255, 255, 255);
  myGLCD.print("E", 240, 100);
  delay(1000);
  myGLCD.clrScr();// Prints the string on the screen
}


void btnhome ()
{
game=0;
j=1;
k=0;
collision=1;
score1=5;
score2=5;
Snake_Mode=1;
Pong_mode=1;
ballY=0;
myGLCD.clrScr();
menu();
  
}
