#include <16F877A.h>
#device ADC=16

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=4MHz)

#define LCD_ENABLE_PIN PIN_D2
#define LCD_RS_PIN PIN_D0
#define LCD_RW_PIN PIN_D1
#define LCD_DATA4 PIN_D4
#define LCD_DATA5 PIN_D5
#define LCD_DATA6 PIN_D6
#define LCD_DATA7 PIN_D7
         
#include <lcd.c>

void displayEnterPasswordMessage() {
   lcd_putc("\f");                
   lcd_gotoxy(1, 1);               
   lcd_putc("Enter Password");     
   lcd_gotoxy(1, 2);               
}

void main()
{
l1:   lcd_init();
      displayEnterPasswordMessage(); 

   OUTPUT_B(0xff);  
   port_b_pullups(true);            
   int ag = 1;      
   int i=3;  
 
   unsigned char pa[4] = {3, 3, 3, 3};  
   unsigned char x[4];            

   while(i <= 3)
   {
      OUTPUT_B(0xef);
     
      if (!input(PIN_B0)) {
         lcd_gotoxy(ag, 2);          
         lcd_putc('7');  
         ag++;
         x[i--] = 7;
       
         while(!input(PIN_B0));
      }
      else if (!input(PIN_B1)) {
         lcd_gotoxy(ag, 2);          
         lcd_putc('4');
         ag++;
         x[i--] = 4;
       
         while(!input(PIN_B1));
      }
      else if (!input(PIN_B2)) {
         lcd_gotoxy(ag, 2);          
         lcd_putc('1');
         ag++;
         x[i--] = 1;
       
         while(!input(PIN_B2));
      }
      else if (!input(PIN_B3)) {
         lcd_gotoxy(ag, 2);          
         lcd_putc('!');  
         ag++;
         i--;
       
         while(!input(PIN_B3));
      }

      OUTPUT_B(0xff);    
      OUTPUT_B(0xdf);    
      if (!input(PIN_B0)) {
         lcd_gotoxy(ag, 2);          
         lcd_putc('8');  
         ag++;
         x[i--] = 8;
       
         while(!input(PIN_B0));
      }
      else if (!input(PIN_B1)) {
         lcd_gotoxy(ag, 2);          
         lcd_putc('5');  
         ag++;
         x[i--] = 5;
         while(!input(PIN_B1));
      }
      else if (!input(PIN_B2)) {
         lcd_gotoxy(ag, 2);         
         lcd_putc('2');  
         ag++;
         x[i--] = 2;
       
         while(!input(PIN_B2));
      }
      else if (!input(PIN_B3)) {
         lcd_gotoxy(ag, 2);         
         lcd_putc('0');  
         ag++;
         x[i--] = 0;
       
         while(!input(PIN_B3));
      }

      OUTPUT_B(0xff);    
      OUTPUT_B(0xbf);    
      if (!input(PIN_B0)) {
         lcd_gotoxy(ag, 2);         
         lcd_putc('9');  
         ag++;
         x[i--] = 9;
         
         while(!input(PIN_B0));
      }
      else if (!input(PIN_B1)) {
         lcd_gotoxy(ag, 2);          
         lcd_putc('6');  
         ag++;
         x[i--] = 6;
       
         while(!input(PIN_B1));
      }
      else if (!input(PIN_B2)) {
         lcd_gotoxy(ag, 2);          
         lcd_putc('3');  
         ag++;
         x[i--] = 3;
         
         while(!input(PIN_B2));
      }
      else if (!input(PIN_B3)) {
         lcd_gotoxy(ag, 2);          
         lcd_putc('=');  
         ag++;
         i--;
         while(!input(PIN_B3));
      }

      OUTPUT_B(0xff);    
      OUTPUT_B(0x7f);    
      if (!input(PIN_B0)) {
         lcd_gotoxy(ag, 2);          
         lcd_putc('*');  
         ag++;
         i--;
         while(!input(PIN_B0));
      }
       else if (!input(PIN_B1)) {
         lcd_gotoxy(ag, 2);          
         lcd_putc('+');  
         ag++;
         i--;
         while(!input(PIN_B1));
      }
       else if (!input(PIN_B2)) {
         lcd_gotoxy(ag, 2);         
         lcd_putc('-');  
         ag++;
         i--;
         while(!input(PIN_B2));
      }
      else if (!input(PIN_B3)) {
         lcd_gotoxy(ag, 2);         
         lcd_putc('/');  
         ag++;
         i--;
         while(!input(PIN_B3));
      }

      OUTPUT_B(0xff);
      if(i == -1) {
         if(x[3] == pa[0] && x[2] == pa[1] && x[1] == pa[2] && x[0] == pa[3]) {
            lcd_putc("\f");               
            for (int j = 0; j < 10; j++) { 
               output_toggle(PIN_A0);    
               delay_ms(300);            
            }
            lcd_gotoxy(1,2);
            lcd_putc("password correct");
            delay_ms(500);
         } else {
            OUTPUT_A(0x00);
            delay_ms(500);
            lcd_gotoxy(1,2);
            lcd_putc("password incorrect");
            delay_ms(1000);
         }

         OUTPUT_A(0x00);
         goto l1;
      }
   }
}
