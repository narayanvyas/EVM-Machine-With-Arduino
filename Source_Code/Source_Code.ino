/*  EVM Machine With Arduino
 * 
 *  GitHub URL - https://github.com/narayanvyas/EVM-Machine-With-Arduino
 * 
 *  Developed By Web Dev Fusion
 *  URL - https://www.webdevfusion.com  
 *  
 * Components
 * ----------
 *  - Arduino Uno
 *  - I2C LCD
 *  - Push Buttons
 *  - Jumper Wires
 *  - Breadboard / PCB
 *  
 *  Libraries
 *  ---------
 *  - NewLiquidCrystal - https://bitbucket.org/fmalpartida/new-liquidcrystal/downloads/
 *  
 */

#include <LCD.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C  lcd(0x27,2,1,0,4,5,6,7); // 0x27 is the I2C bus address for an unmodified backpack

#define sw1 3
#define sw2 4
#define sw3 5
#define sw4 6
#define sw5 7
#define sw6 8

int vote1=0;
int vote2=0;
int vote3=0;
int vote4=0;
void setup()
{
  pinMode(sw1,INPUT);
  pinMode(sw2,INPUT);
  pinMode(sw3,INPUT);
  pinMode(sw4,INPUT);
  pinMode(sw5,INPUT);
  pinMode(sw6,INPUT);
  
  lcd.begin (16,2);
  lcd.setBacklightPin(3,POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.home ();
  lcd.print("EVM Machine");
  lcd.setCursor(0, 1);
  delay(1500);
  
  digitalWrite(sw1, HIGH);
  digitalWrite(sw2, HIGH);
  digitalWrite(sw3, HIGH);
  digitalWrite(sw4, HIGH);
  digitalWrite(sw5, HIGH);
  digitalWrite(sw6, HIGH);
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("BJP");
  lcd.setCursor(4,0);
  lcd.print("INC");
  lcd.setCursor(8,0);
  lcd.print("AAP");
  lcd.setCursor(12,0);
  lcd.print("OTH");
}
void loop()
{
  lcd.setCursor(0,0);
  lcd.print("BJP");
  lcd.setCursor(1,1);
  lcd.print(vote1);
  lcd.setCursor(4,0);
  lcd.print("INC");
  lcd.setCursor(5,1);
  lcd.print(vote2);
  lcd.setCursor(8,0);
  lcd.print("AAP");
  lcd.setCursor(9,1);
  lcd.print(vote3);
  lcd.setCursor(12,0);
  lcd.print("OTH"); 
  lcd.setCursor(13,1);
  lcd.print(vote4);
   if(digitalRead(sw1)==0)
    vote1++;
    while(digitalRead(sw1)==0);
  if(digitalRead(sw2)==0)
    vote2++;
    while(digitalRead(sw2)==0);
  if(digitalRead(sw3)==0)
    vote3++;
    while(digitalRead(sw3)==0);
   if(digitalRead(sw4)==0)
    vote4++;
    while(digitalRead(sw4)==0);
   if(digitalRead(sw6)==0) {
    vote1=0;
    vote2=0;
    vote3=0;
    vote4=0;
   }
  while(digitalRead(sw6)==0);
   if(digitalRead(sw5)==0)
   {
     int vote=vote1+vote2+vote3+vote4;
     if(vote)
     {
      if((vote1 > vote2 && vote1 > vote3 && vote1 > vote4))
      {
       lcd.clear();
       lcd.print("BJP Wins");
       delay(2000);
       lcd.clear();
      }
      else if((vote2 > vote1 && vote2 > vote3 && vote2 > vote4))
      {
       lcd.clear();
       lcd.print("INC Wins");
       delay(2000);
       lcd.clear();
      }
      else if((vote3 > vote1 && vote3 > vote2 && vote3 > vote4))
      {
       lcd.clear();
       lcd.print("AAP Wins");
       delay(2000);
       lcd.clear();
      }
     else if(vote4 > vote1 && vote4 > vote2 && vote4 > vote3)
     {
       lcd.setCursor(0,0);
       lcd.clear();
       lcd.print("OTH Wins");
       delay(2000);
       lcd.clear();
     }
     
      else if(vote4 > vote1 && vote4 > vote2 && vote4 > vote3)
     {
       lcd.setCursor(0,0);
       lcd.clear();
       lcd.print("OTH Wins");
       delay(2000);
       lcd.clear();
     }
     
     else
     {
       lcd.clear();
       lcd.print("   Tie Up Or   ");
       lcd.setCursor(0,1);
       lcd.print("   No Result   ");
       delay(1000);
       lcd.clear();
     }
     
    }      
     else 
     {
       lcd.clear();
       lcd.print("No Voting....");
       delay(1000);
       lcd.clear();
     }
     vote1=0;vote2=0;vote3=0;vote4=0,vote=0;
     lcd.clear();
   }
}
