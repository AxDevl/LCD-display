/*Program to display simple messages and values on an LCD screen
Adapted from publically available GITHUB program for an arduino
01/11/23
Version 3
*/

/* Ensure RW LCD pin is connected to GND and connect a 10 K potentiometer with wiper connected to V0 and other ends to A and K LCD pins.
 Connect a 100 ohm resistor (ideally 500 Ohm) between A LCD pin and VDD.
 */

#include "mbed.h"
#include "TextLCD.h"
#include <algorithm>
#include <string>

TextLCD lcd(D14, D15, D13, D12, D11, D10, TextLCD::LCD20x4); // Connect these nucleo pins to RS, E, D4, D5, D6 and D7 pins of the LCD
 
DigitalOut bulb0(D0); //Bottom Left E
DigitalOut bulb1(D1); //Bottom D
DigitalOut bulb2(D2); //DP
DigitalOut bulb3(D3); //Bottom Right C
DigitalOut bulb4(D4); //Top A
DigitalOut bulb5(D5); //Top Right B
DigitalOut bulb6(D6); //Top Left F
DigitalOut bulb7(D7); //Middle
DigitalIn button1(D8, PullUp); //LEFT
DigitalIn button2(D9, PullUp);

PinName ReturnPinName(int count)
{
    switch(count)
    {
        case 0: return D0;
        case 1: return D1;
        case 2: return D2;
        case 3: return D3;
        case 4: return D4;
        case 5: return D5;
        case 6: return D6;
        case 7: return D7;
    }
    return D10;
}

void Display(string name)
{
    int count = 0;
    for(char c : name)
    {
        if (c == '1')
        {
            DigitalOut bulb(ReturnPinName(count));
            bulb = true;
        }
        if (c == '0')
        {
            DigitalOut bulb(ReturnPinName(count));
            bulb = false;
        }
        count++;
    }
}

void executionLCD(int buttonSelection)
    {
        if (buttonSelection == 1)
        {
            lcd.cls(); //clears the lcd screen
            lcd.locate(0,0); //sets the cursor to column 0 and row 1
            lcd.printf("Displaying...\n"); //displays the message Hello World on the LCD 

            lcd.locate(0,1); //set cursor on row number 1 (bottom row)
            lcd.printf("FirstName"); //displays an integer value
        }
        if (buttonSelection == 2)
        {
            lcd.cls(); //clears the lcd screen
            lcd.locate(0,0); //sets the cursor to column 0 and row 1
            lcd.printf("Displaying...\n"); //displays the message Hello World on the LCD 

            lcd.locate(0,1); //set cursor on row number 1 (bottom row)
            lcd.printf("LastName"); //displays an integer value
        }
        if (buttonSelection == 0)
        {
            lcd.locate(0,0); //sets the cursor to column 0 and row 1
            lcd.printf("1) First name\n"); //displays the message Hello World on the LCD

            lcd.locate(0,1); //set cursor on row number 1 (bottom row)
            lcd.printf("2) Last name"); //displays an integer value
        }
        
    }

// main() runs in its own thread in the OS
int main()
{
    Display("00110100");
    thread_sleep_for(1000);
    Display("10101000");
    thread_sleep_for(1000);
    Display("00101011");
    thread_sleep_for(1000);
    Display("00101001");
    thread_sleep_for(1000);
    Display("11111111");
    thread_sleep_for(1000);
    Display("10101011");
    thread_sleep_for(1000);

    executionLCD(0);
   

    while (true)
    {
        if (button1 == false)
        {  
                executionLCD(1);
                Display("00110100");
                thread_sleep_for(1000);
                Display("10101000");
                thread_sleep_for(1000);
                Display("00101011");
                thread_sleep_for(1000);
                Display("00101001");
                thread_sleep_for(1000);
                Display("11111111");
                thread_sleep_for(1000);
                Display("10101011");
                thread_sleep_for(1000);
        }
        if (button1 == true && button2 == true)
        {
            executionLCD(0);
            Display("00000000");
            thread_sleep_for(1000);
        }
        if (button2 == false)
        {       
                executionLCD(2);
                Display("11110100");
                thread_sleep_for(1000);
                Display("10111000");
                thread_sleep_for(1000);
                Display("00001011");
                thread_sleep_for(1000);
                Display("00101001");
                thread_sleep_for(1000);
                Display("00010000");
                thread_sleep_for(1000);
                Display("10101010");
                thread_sleep_for(1000);
        }
    }
    /*bulb0 = true;
    bulb1 = true;
    bulb2 = true;
    bulb3 = true;
    bulb4 = true;
    bulb5 = true;
    bulb6 = true;*/
}
