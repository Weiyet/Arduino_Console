int Setting_new1=1;
int Setting_old=0;
int contrast=64;
  int brightness=16;

void Setting_Select()
{
  if (btnUP1.pressed())
        {
          Setting_old = Setting_new1;
          Setting_new1 = Setting_old - 1;
          switch (Setting_old)
        {
          case 0:
            myGLCD.setColor(255, 255, 255);
            myGLCD.drawRect (20, 132, 305, 164);
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
            myGLCD.drawRect (20, 90,305, 122);
            break;
          default:
            break;
        }



        switch (Setting_new1)
        {
          case 0:
            myGLCD.setColor(255, 0, 0);
            myGLCD.drawRect (20, 132, 305, 164);
            Setting_new1 = 2;
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
            myGLCD.drawRect (20, 90, 305, 122);
            Setting_new1 = 1;
            break;
          default:
            break;
        } 
        }
   
   if (btnDOWN1.pressed())
        {
          Setting_old = Setting_new1;
          Setting_new1 = Setting_old + 1;
          switch (Setting_old)
        {
          case 0:
            myGLCD.setColor(255, 255, 255);
            myGLCD.drawRect (20, 132, 305, 164);
            break;
          case 1:
            myGLCD.setColor(255, 255, 255);;
            myGLCD.drawRect(20, 90, 305, 122);
            break;
          case 2:
            myGLCD.setColor(255, 255, 255);
            myGLCD.drawRect (20, 132, 305, 164);
            break;
          case 3:
            myGLCD.setColor(255, 255, 255);
            myGLCD.drawRect(20, 90, 305, 122);
            break;
          default:
            break;
        }



        switch (Setting_new1)
        {
          case 0:
            myGLCD.setColor(255, 0, 0);
            myGLCD.drawRect (20, 132, 305, 164);
            Setting_new1 = 2;
            break;
          case 1:
            myGLCD.setColor(255, 0, 0);
            myGLCD.drawRect(20, 90, 305, 122);
            break;
          case 2:
            myGLCD.setColor(255, 0, 0);
            myGLCD.drawRect (20, 132, 305, 164);
            break;
          case 3:
            myGLCD.setColor(255, 0, 0);
            myGLCD.drawRect(20,90 , 305, 122);
            Setting_new1 = 1;
            break;
          default:
            break;
        } 
        }
   if(digitalRead(btnLEFT_P1)==LOW)
   {
    if(Setting_new1==1&&brightness>0)
    {   myGLCD.setColor(82, 76, 100); // Sets color to white
  myGLCD.setBackColor(82, 76, 100); // Sets the background color of the area where the text will be printed to green, same as the button
  myGLCD.printNumI(brightness, CENTER+2, 97); // Prints the string
      brightness--;
  myGLCD.setColor(255, 255,255); // Sets color to white
    myGLCD.printNumI(brightness, CENTER+2,97); // Prints the string
  
    
    myGLCD.setBrightness(brightness);
    delay(500);}
    
    else if(Setting_new1==2)
     if(Setting_new1==2&&contrast>0)
     {myGLCD.setColor(82, 76, 100); // Sets color to white
  myGLCD.setBackColor(82, 76, 100); // Sets the background color of the area where the text will be printed to green, same as the button
  myGLCD.printNumI(contrast, CENTER+2, 139); // Prints the string
      
      contrast--;
      myGLCD.setContrast(contrast);
     myGLCD.setColor(255, 255, 255); // Sets color to white
  myGLCD.printNumI(contrast, CENTER+2, 139); // Prints the string
  delay(500);
  }
    }
    if(digitalRead(btnRIGHT_P1)==LOW)
       {
    if(Setting_new1==1&&brightness<16)
{   myGLCD.setColor(82, 76, 100); // Sets color to white
  myGLCD.setBackColor(82, 76, 100); // Sets the background color of the area where the text will be printed to green, same as the button
  myGLCD.printNumI(brightness, CENTER+2, 97); // Prints the string
      brightness++;
  myGLCD.setColor(255, 255,255); // Sets color to white
    myGLCD.printNumI(brightness, CENTER+2,97); // Prints the string
  
    
    myGLCD.setBrightness(brightness);
    delay(500);}
    else if(Setting_new1==2)
     if(Setting_new1==2&&contrast<64)
      {myGLCD.setColor(82, 76, 100); // Sets color to white
  myGLCD.setBackColor(82, 76, 100); // Sets the background color of the area where the text will be printed to green, same as the button
  myGLCD.printNumI(contrast, CENTER+2, 139); // Prints the string
      
      contrast++;
      myGLCD.setContrast(contrast);
     myGLCD.setColor(255, 255, 255); // Sets color to white
  myGLCD.printNumI(contrast, CENTER+2, 139); // Prints the string
  delay(500);
  }
    }
   
}

void Setting()
{
  Setting_new1=1;
  Setting_old=0;
  myGLCD.setColor(82, 76, 100); // Sets green color
  myGLCD.fillRoundRect (20, 90, 305, 122); // Draws filled rounded rectangle
  myGLCD.setColor(255, 0, 0); // Sets color to white
  myGLCD.drawRoundRect (20, 90, 305, 122); // Draws rounded rectangle without a fill, so the overall appearance of the button looks like it has a frame
  myGLCD.setColor(255, 255, 255); // Sets color to white
  myGLCD.setFont(BigFont); // Sets the font to big
  myGLCD.setBackColor(82, 76, 100); // Sets the background color of the area where the text will be printed to green, same as the button
  myGLCD.print("BRIGHTNESS", CENTER, 97); // Prints the string 
  myGLCD.printNumI(brightness, CENTER+2, 97); // Prints the string
  //button-Pong Pong
  myGLCD.setColor(82, 76, 100); // Sets green color
  myGLCD.fillRoundRect (20, 132, 305, 164); // Draws filled rounded rectangle
  myGLCD.setColor(255, 255, 255); // Sets color to white
  myGLCD.drawRoundRect (20, 132, 305, 164); // Draws rounded rectangle without a fill, so the overall appearance of the button looks like it has a frame
  myGLCD.setFont(BigFont); // Sets the font to big
  myGLCD.setBackColor(82,76, 100); // Sets the background color of the area where the text will be printed to green, same as the button
  myGLCD.print("CONTRAST", CENTER, 139); // Prints the string 
   myGLCD.printNumI(contrast, CENTER+2, 139); // Prints the string
  while(k==1)
  Setting_Select();

}
