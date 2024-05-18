#include <Button.h>
#include <UTFT.h>
#include <URTouch.h>

UTFT myGLCD(ILI9341_16, 38, 39, 40, 41);
URTouch myTouch( 6, 5, 4, 3, 2);

extern uint8_t SmallFont[];
extern uint8_t BigFont[];
extern uint8_t SevenSegNumFont[];

Button btnUP1(A0);
Button btnDOWN1(A1);
Button btnLEFT1(A2);
Button btnRIGHT1(A3);
Button btnA1(A4);

#define screenWidth 320
#define screenHeight 240

//Player 1
#define btnUP_P1 A0
#define btnDOWN_P1 A1
#define btnLEFT_P1 A2
#define btnRIGHT_P1 A3
#define btnA_P1 A4
#define btnB_P1 A5

//homebutton
#define btnHOME 21//interrupt pin

//Player2
#define btnUP_P2 15
#define btnDOWN_P2 14
#define btnLEFT_P2 17
#define btnRIGHT_P2 16
#define btnA_P2 18
#define btnB_P2 19

#define tileSize 6

int i = 1;//counter
int j=1;
int k=1;


