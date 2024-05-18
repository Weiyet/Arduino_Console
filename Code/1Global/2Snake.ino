/*colour*/
/*colour*/
#define Rfood 0
#define Gfood 255
#define Bfood 0
#define Rsnake1 0
#define Gsnake1 0
#define Bsnake1 255
#define Rsnake2 255
#define Gsnake2 105
#define Bsnake2 180
#define Rscreen 0
#define Gscreen 0
#define Bscreen 0
#define Rtext 111
#define Gtext 230
#define Btext 0
  char scoreChars[1];
  String scorestring ;

long timestamp = 0;
long time1 = 200;
int score = 0;
int collision = 0;
int goX1 = tileSize;
int goY1 = 0;
int goX2 = -tileSize;
int goY2 = 0;
int Snake_Mode=0;
int Snake_old=1;
int Snake_new1=1;

struct coord_struct { /*consist x and y plot and next ptr*/
  int x;
  int y;
  struct coord_struct *next_ptr;
};

typedef struct coord_struct coord; /*name struct as coord*/

coord *new_ptr1; /*pointer*/
coord *temp1; /*3rd variable as a temporary variable to transfer the value, work to display the "body" of the snake*/
coord *head1 = NULL;

coord *new_ptr2; /*pointer*/
coord *temp2; /*3rd variable as a temporary variable to transfer the value, work to display the "body" of the snake*/
coord *head2 = NULL;

struct {
  int x;
  int y;
  int growBy;
} food; /*let a variable named food with this structure*/

void drawRet(int x, int y, int R, int G, int B)
{
  myGLCD.setColor(R, G, B);
  myGLCD.fillRect(x, y, x + tileSize, y + tileSize); //fill with certain colour//
}

void remLast1()
{
  coord *last;  /*there is a pointer variable last in this function (only)*/
  temp1 = head1;
  last = temp1;
  while (temp1 != NULL && temp1->next_ptr != NULL) {
    last = temp1;
    temp1 = temp1->next_ptr;
  }
  if (last == temp1) {
    free(temp1);
    head1 = NULL;
  } else {
    drawRet(temp1->x, temp1->y, Rscreen, Gscreen, Bscreen); /*erase the old ,display with "game background colour*/
    free(last->next_ptr);
    last->next_ptr = NULL;
  }
}

void remLast2()
{
  coord *last;  /*there is a pointer variable last in this function (only)*/
  temp2 = head2;
  last = temp2;
  while (temp2 != NULL && temp2->next_ptr != NULL) {
    last = temp2;
    temp2 = temp2->next_ptr;
  }
  if (last == temp2) {
    free(temp2);
    head2 = NULL;
  } else {
    drawRet(temp2->x, temp2->y, Rscreen, Gscreen, Bscreen); /*erase the old ,display with "game background colour*/
    free(last->next_ptr);
    last->next_ptr = NULL;
  }
}

void reset()
{
  goX1 = 0;
  goY1 = tileSize;
  goX2 = 0;
  goY2 = -tileSize;
  collision = 0;
  score = 0;
  Snake_old = 1;
  Snake_Mode = 0;
  Snake_new1=1;
  while (head1) {
    remLast1();
  }
  while (head2) {
    remLast2();
  }
}

void addFirst1(int x, int y)
{
  new_ptr1 = (coord *)malloc(sizeof(coord));
  new_ptr1->x = x;
  new_ptr1->y = y;
  new_ptr1->next_ptr = head1;
  head1 = new_ptr1;
}

void addFirst2(int x, int y)
{
  new_ptr2 = (coord *)malloc(sizeof(coord));
  new_ptr2->x = x;
  new_ptr2->y = y;
  new_ptr2->next_ptr = head2;
  head2 = new_ptr2;
}

void getDirection1() /*get the direction*/
{
  if (digitalRead(btnLEFT_P1)==LOW && goX1 == 0) {
    goX1 = -tileSize;  /*turn the y direction to 0 and x to -x direction (moving left) */
    goY1 = 0;
  }
  else if (digitalRead(btnDOWN_P1)==LOW && goY1 == 0) {
    goX1 = 0;
    goY1 = tileSize;
  }
  else if (digitalRead(btnUP_P1)==LOW && goY1 == 0) {
    goX1 = 0;
    goY1 = -tileSize;
  }
  else if (digitalRead(btnRIGHT_P1)==LOW && goX1 == 0) {
    goX1 = tileSize;
    goY1 = 0;
  }
  if (digitalRead(btnLEFT_P2)==LOW && goX2 == 0) {
    goX2 = -tileSize;  /*turn the y direction to 0 and x to -x direction (moving left) */
    goY2 = 0;
  }
  else if (digitalRead(btnDOWN_P2)==LOW && goY2 == 0) {
    goX2 = 0;
    goY2 = tileSize;
  }
  else if (digitalRead(btnUP_P2)==LOW && goY2 == 0) {
    goX2 = 0;
    goY2 = -tileSize;
  }
  else if (digitalRead(btnRIGHT_P2)==LOW && goX2 == 0) {
    goX2 = tileSize;
    goY2 = 0;
  }
}

void putFood()
{
  int validPlace = 0;
  while (!validPlace) {
    food.x = 2 + (int)random(1, 49) * tileSize;
    food.y = 2 + (int)random(1, 24) * tileSize;
    if (food.x != head1->x && food.y != head1->y) { /*food cannot be at head or else the loop keep generate a random food*/
      validPlace = 1; /*stop the loop */
    }
  }
  drawRet(food.x, food.y, Rfood, Gfood, Bfood);
}

void Snake_Select()
{
  if (btnUP1.pressed())
        {
          Snake_old = Snake_new1;
          Snake_new1 = Snake_old - 1;
          switch (Snake_old)
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



        switch (Snake_new1)
        {
          case 0:
            myGLCD.setColor(255, 0, 0);
            myGLCD.drawRect (20, 194, 305, 226);
            Snake_new1 = 2;
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
            Snake_new1 = 1;
            break;
          default:
            break;
        } 
        }
   
   if (btnDOWN1.pressed())
        {
          Snake_old = Snake_new1;
          Snake_new1 = Snake_old + 1;
          switch (Snake_old)
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



        switch (Snake_new1)
        {
          case 0:
            myGLCD.setColor(255, 0, 0);
            myGLCD.drawRect (20, 194, 305, 226);
            Snake_new1 = 2;
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
            Snake_new1 = 1;
            break;
          default:
            break;
        } 
        }
}

void startScreen()
{
  reset();
  { myGLCD.setBackColor(Rscreen, Gscreen, Bscreen );
    myGLCD.setColor(16, 167, 103); // Sets green color
    myGLCD.fillRoundRect (20, 60, 305, 110); // Draws filled rounded rectangle
    myGLCD.setColor(255, 255, 255); // Sets color to white
    myGLCD.drawRoundRect (20, 60, 305, 110); // Draws rounded rectangle without a fill, so the overall appearance of the button looks like it has a frame
    myGLCD.setBackColor(16, 167, 103); // Sets the background color of the area where the text will be printed to green, same as the button
    myGLCD.setFont(BigFont);
    myGLCD.print("Snake", CENTER, 80);

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

  }
  while (Snake_Mode==0)
  {Snake_Select();
     if (btnA1.pressed())
        { myGLCD.clrScr();
          if (Snake_new1 == 1)
            Snake_Mode = 1;
          if (Snake_new1 == 2)
            Snake_Mode = 2;
        }}

  myGLCD.setBackColor(Rscreen, Gscreen, Bscreen);
  myGLCD.setColor(0, 255, 255);
  myGLCD.drawRect(1, 1, myGLCD.getDisplayXSize() - 1, myGLCD.getDisplayYSize() - 1);

  for (int i = 68; i <= 116; i += 6) { /*draw a snake with intial length of 5*/
    addFirst1(i, 110);
    drawRet(head1->x, head1->y, Rsnake1, Gsnake1, Bsnake1); /*draw snake*/
  }
  
  if(Snake_Mode==2){
  for (int i = 188; i <= 236; i += 6) { /*draw a snake with intial length of 5*/
    addFirst2(i, 110);
    drawRet(head2->x, head2->y, Rsnake2, Gsnake2, Bsnake2); /*draw snake*/
  }}

  putFood();
}

int isGrow1()/*when head == food length++*/
{
  if (head1->x == food.x && head1->y == food.y) {
    return 1;
  } else {
    return 0;
  }
}

int isGrow2()/*when head == food length++*/
{
  if (head2->x == food.x && head2->y == food.y) {
    return 1;
  } else {
    return 0;
  }
}

int isCollision1()
{
  temp1 = head1->next_ptr;
  temp2 = head2;
  while (temp1) { /*loop ends till temp=NULL*/
    if (temp1->x == head1->x && temp1->y == head1->y) { /*collision with its snake body*/
      return 1;
    }
    temp1 = temp1->next_ptr;
  }
  while (temp2) { /*loop ends till temp=NULL*/
    if (head1->x == temp2->x && head1->y == temp2->y) { /*collision with its snake body*/
      return 1;
    }
       //if(temp1!=NULL)
    temp2 = temp2->next_ptr;
  }
  if (head1->x < 2 || head1->x > 313 || head1->y < 2 || head1->y > 232) { /*collision with the wall*/
    return 1;
  }
  return 0;
}

int isCollision2()
{
  temp2 = head2->next_ptr;
  temp1 = head1;
  while (temp2) { /*loop ends till temp=NULL*/
    if (temp2->x == head2->x && temp2->y == head2->y) { /*collision with its snake body*/
      return 1;
    }
    temp2 = temp2->next_ptr;
  }
    while (temp1) { /*loop ends till temp=NULL*/
    if (head2->x == temp1->x && head2->y == temp1->y) { /*collision with its snake body*/
      return 1;
    }
    //if(temp2!=NULL)
    temp1 = temp1->next_ptr;
  }
  if (head2->x < 2 || head2->x > 313 || head2->y < 2 || head2->y > 232) { /*collision with the wall*/
    return 1;
  }
  return 0;
}

void endScreen()
{
  myGLCD.clrScr();
  myGLCD.setBackColor(0, 255, 0);
  myGLCD.setColor(255, 255, 255);
  myGLCD.setColor(Rtext, Gtext, Btext);
  myGLCD.setFont(BigFont);
  if(Snake_Mode==1){
  myGLCD.print("Game over", CENTER, 40);
  myGLCD.print("Score:", CENTER, 80);
  myGLCD.setFont(SevenSegNumFont);
  myGLCD.setBackColor(0, 0, 0);
  char scoreChars[5];
  String scorestring = String(score); /*to print the score*/ /*for tft screen need to be change to char for displaying*/
  scorestring.toCharArray(scoreChars, 5);
  myGLCD.print(scoreChars, CENTER + 1, 60);}

  else if(Snake_Mode==2){
  if(score==1)
  myGLCD.print("Player 2 wins", CENTER, 40);
  if(score==2)
  myGLCD.print("Player 1 wins", CENTER, 40);}
  
  myGLCD.setBackColor(0, 0, 0);
  myGLCD.setColor(Rtext, Gtext, Btext);
  myGLCD.setFont(SmallFont);
  myGLCD.print("press any  button to continue", CENTER, 200);
  while (digitalRead(btnUP_P1) == HIGH && digitalRead(btnDOWN_P1) == HIGH && digitalRead(btnLEFT_P1) == HIGH && digitalRead(btnRIGHT_P1) == HIGH && digitalRead(btnA_P1) == HIGH&&digitalRead(btnB_P1)==HIGH);
  {
    myGLCD.clrScr();
  }
}


void
Snake_Game()
{ int j = 1;
  startScreen();
  if(Snake_Mode==1){
   while (!collision) {
    Serial.println("gameplay");
    getDirection1();
    /*if (j == 1)
    { timestamp = millis();
      delay(50);
      j--;
    }*/
    if (millis() - timestamp > 80) {
      addFirst1((head1->x + goX1), (head1->y + goY1));
      drawRet(head1->x, head1->y, Rsnake1, Gsnake1, Bsnake1);

      if (food.growBy) {
        food.growBy--;
        score++;
      }
      else {
        remLast1();
      }
      if (isGrow1()) {
        food.growBy++;
        putFood();
      }
      if (isCollision1()) {
        collision = 1;
      }
      timestamp = millis();}
  }}
  else if(Snake_Mode==2){
  while (!collision) {
    Serial.println("gameplay");
    getDirection1();
    /*if (j == 1)
    { timestamp = millis();
      delay(50);
      j--;
    }*/
    if (millis() - timestamp > 80) {
      addFirst1((head1->x + goX1), (head1->y + goY1));
      drawRet(head1->x, head1->y, Rsnake1, Gsnake1, Bsnake1);
      addFirst2((head2->x + goX2), (head2->y + goY2));
      drawRet(head2->x, head2->y, Rsnake2, Gsnake2, Bsnake2);
      if (food.growBy) {
        food.growBy--;
      }
      else {
        remLast1();
        remLast2();
      }
      if (isGrow1()||isGrow2()) {
        food.growBy++;
        putFood();
      }
      if (isCollision1()) {
        collision = 1;
        score=1;
      }
      if (isCollision2()) {
        collision = 1;
        score=2;
      }
      timestamp = millis();
    }
  }}
  if(k)
  endScreen();
}

