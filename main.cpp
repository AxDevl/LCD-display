// To include all the libraries for the code space to reference other code / commands.

#include "mbed.h"
#include "TextLCD.h"
#include <algorithm>
#include <climits>
#include <string>


// ------- PIN references----------------

TextLCD lcd(D14, D15, D13, D12, D11, D10, TextLCD::LCD20x4); // Connect these nucleo pins to RS, E, D4, D5, D6 and D7 pins of the LCD
DigitalOut bulb0(D0); //Bottom Left E
DigitalOut bulb1(D1); //Bottom D
DigitalOut bulb2(D2); //Decimal Point
DigitalOut bulb3(D3); //Bottom Right C
DigitalOut bulb4(D4); //Top A
DigitalOut bulb5(D5); //Top Right B
DigitalOut bulb6(D6); //Top Left F
DigitalOut bulb7(D7); //Middle
DigitalIn FirstNameButton(D8, PullUp); //Left Button  
DigitalIn LastNameButton(D9, PullUp); //Right Button

// --------------------------------------

/*
When ReturnPinName is called with a number as a parameter, the code will return the pin number asocciated to the number.
*/

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

/*
Return corresponding pattern layout for letter.
*/

string ReturnLetterString(char count)
{
    
    switch(tolower(count))
    {
        case 'a': return "00001110";
        case 'b': return "01010011";
        case 'c': return "00001011";
        case 'd': return "11000101";
        case 'e': return "01001001";
        case 'f': return "10001001";
        case 'g': return "01110001";
        case 'h': return "10010011";
        case 'i': return "10100000";
        case 'j': return "01110000";
        case 'k': return "10000011";
        case 'l': return "11000000";
        case 'm': return "10011000";
        case 'n': return "00010001";
        case 'o': return "00001111";
        case 'p': return "10001101";
        case 'q': return "00011011";
        case 'r': return "10000001";
        case 's': return "01011001";
        case 't': return "10001010";
        case 'u': return "11010000";
        case 'v': return "11110000";
        case 'w': return "00100111";
        case 'x': return "10010110";
        case 'y': return "00110011";
        case 'z': return "01101101";   
    }
    return "00000000";
}

/*
This code displays the actual pins to light up based on the string of numbers provided.
*/

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

/*
This code is for the LCD display the current execution if first name is displayed or last name is displayed.

Parameter
0 = Home Screen
1 = First Name
2 = Last Name

*/

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



/*
The main section will the first peice of code that is executed when the program loads.
*/

int main()
{
    string firstName = "bArTo";
    string LastName = "godle";

    executionLCD(0);
   
    while (true)
    {
        if (FirstNameButton == false)
        {  
                executionLCD(1);
                for (char c : firstName)
                {
                    Display(ReturnLetterString(c));
                    thread_sleep_for(1000);
                }
                
        }
        if (FirstNameButton == true && LastNameButton == true)
        {
            executionLCD(0);
            Display("00000000");
            thread_sleep_for(1000);
        }
        if (LastNameButton == false)
        {       
                executionLCD(2);
                for (char c : LastName)
                {
                    Display(ReturnLetterString(c));
                    thread_sleep_for(1000);
                }
        }
    } 
}
