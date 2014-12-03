/*
SNAKE.pde
 
 Example file using the The Meggy Jr Simplified Library (MJSL)
  from the Meggy Jr RGB library for Arduino
   
 Blink a damned LED.
   
   
 
 Version 1.25 - 12/2/2008
 Copyright (c) 2008 Windell H. Oskay.  All right reserved.
 http://www.evilmadscientist.com/
 
 This library is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this library.  If not, see <http://www.gnu.org/licenses/>.
 	  
 */

 
 
 
 

/*
 * Adapted from "Blink,"  The basic Arduino example.  
 * http://www.arduino.cc/en/Tutorial/Blink
 */

#include <MeggyJrSimple.h>    // Required code, line 1 of 2.

void setup()                    // run once, when the sketch starts
{
  MeggyJrSimpleSetup(); // Required code, line 2 of 2.
  Serial.begin(9600); 
}


// Global variables go here...
int x = 3;  //coordinates of player dot
int y = 4;
int xa = random(8);  //apple vars
int ya = random(8);
int direction = 0;  //possible values are 0, 90, 180, and 270
struct Point
{
  int x;
  int y;
};
//Point p1 = {3,4};  // p1.x = 3; p1.y = 4
Point snakeArray[64] =
{p1, p2, p3};

Point p1 = {3,4,};
Point p2 = {4,4};
Point p3 = {5,4};

/*
  DrawPxplayer  -  call drawSNAKE
  DisplaySlate / DELAY 100
  CheckButtons
  update direction if a button is pressed
  UPDATE PLAYER BSED ON DIRECTION
  CORRECT FOR WRAPPING
*/

void loop()
{
  void drawSnake()
  {
    for(int i = 0; i < marker; i++)
    {
      DrawPx(snakeArray [i].x, snakeArray[i].y,Green)
    }
  }
  
  Serial.print("x is ");
  Serial.println(x);  //ln = line
  Serial.print("y is ");
  Serial.println(y);
  Serial.println();
  
  // DrawPx(x,y,Green);
  DrawPx(xa,ya,Red);
  DisplaySlate();
  delay(125);
  ClearSlate();
  
  
  CheckButtonsDown();
  if (Button_Right)
    direction = 90;
  if (Button_Left)
    direction = 270;
  if (Button_Up)
    direction =0;
  if (Button_Down)
    direction = 180;
    
  if (direction == 0)
    y++;
  if (direction == 90)
    x++;
  if (direction == 180)
    y--;
  if (direction == 270)
    x--;
  if (x > 7)
    x = 0;
  if (y > 7)
    y = 0;
  if (x < 0)
    x = 7;
  if (y < 0)
    y = 7;
    
  if (xa == x)    //apple codes
  {
    if (ya == y)
    {
      xa = random(8);
      ya = random(8);
    }
  }

}
  
  
  
  
  
  
  
  
 /* 
  // left and right
  CheckButtonsDown();
  if(Button_Right)
   {
   }
   else
   {
     if (x < 7)
     {
       x = x + 1;  // Also x++;
     }
     else
     {
       x = 0;
     }
   }
   
  
   
   CheckButtonsDown();
   if (Button_Left)
   { 
   }
   
   else
   {
     if (x > 0)
     {
       x = x - 1;
     }
   }
    /* if (x > 0)
     {
       x = x -1;
     }
     else
     {
       x = 7;
     }
   }
   // end
   
   
   // up and down
   CheckButtonsDown();
  if(Button_Up)
   {
   }
   else
   {
     if (y < 7)
     {
       y = y + 1;  // Also x++;
     }
     else
     {
       y = 0;
     }
   }
   
  
   
   CheckButtonsDown();
   if (Button_Down)
   {
   }
   else
   {
     if (y > 0)
     {
       y = y -1;
     }
     else
     {
       y = 7;
     }
   }
   
   */
   
   
  
  




