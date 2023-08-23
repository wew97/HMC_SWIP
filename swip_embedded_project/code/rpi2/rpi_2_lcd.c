// rpi_2_lcd.c

#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <stdio.h>
#include "wiringPi.h"

#include "rpi_2_lcd.h"

#define LCD_BACKLIGHT_ON 0x08  // On             "0000 1000"
#define LCD_BACKLIGHT_OFF 0x00 // Off            "0000 0000"
#define LCD_ENABLE 0x04        // Enable         "0000 0100"
#define LCD_DISABLE 0x00       // Disable        "0000 0000"
#define LCD_RW_READ 0x02       // Read           "0000 0010"
#define LCD_RW_WRITE 0x00      // Write          "0000 0000"
#define LCD_RS_DATA 0x01       // Data           "0000 0001"
#define LCD_RS_INST 0x00       // Instruction    "0000 0000"

extern int deviceHandle;

void changeLine(int line);

void toggleLCDEnable(int eightBits)
{
    delayMicroseconds(500);
    wiringPiI2CWrite(deviceHandle, (eightBits | LCD_ENABLE));
    delayMicroseconds(500);
    wiringPiI2CWrite(deviceHandle, (eightBits | LCD_DISABLE));
    delayMicroseconds(500);
}

void sendBitsToLCD(int eightBits, int mode)
{

    int highFourBits;
    int lowFourBits;

    highFourBits = mode | (eightBits & 0xF0) | LCD_BACKLIGHT_ON;       // Let's always turn on the backlight
    lowFourBits = mode | ((eightBits << 4) & 0xF0) | LCD_BACKLIGHT_ON; // Let's always turn on the backlight

    // First, send highFourBits and pulse the enable pin
    wiringPiI2CWrite(deviceHandle, highFourBits); // 'xxxx abcd': xxxx is the high 4 bits of eightBits
    toggleLCDEnable(highFourBits);

    // Next, send lowFourBits and pulse the enable pin
    wiringPiI2CWrite(deviceHandle, lowFourBits); // 'yyyy abcd': yyyy is the low 4 bits of eightBits
    toggleLCDEnable(lowFourBits);
}

void initializeLCD()
{
    // Instruction: Function Set '001D NF--'
    sendBitsToLCD(0x33, LCD_RS_INST | LCD_RW_WRITE); // "0011 0011" (8-bit mode, 1 line, 5x8 dots)

    // Instruction: Function Set '001D NF--'
    sendBitsToLCD(0x32, LCD_RS_INST | LCD_RW_WRITE); // "0011 0010" (8-bit mode, 1 line, 5x8 dots)

    // Instruction: Entry Mode Set '0000 01IS'
    sendBitsToLCD(0x06, LCD_RS_INST | LCD_RW_WRITE); // "0000 0110" (cursor move direction is increment, normal shift operation)

    // Instruction: Display ON/OFF Control '0000 1DCB'
    sendBitsToLCD(0x0C, LCD_RS_INST | LCD_RW_WRITE); // "0000 1100" (display on, cursor Off, blink off)

    // Instruction: FUnction Set '001D NF--'
    sendBitsToLCD(0x28, LCD_RS_INST | LCD_RW_WRITE); // "0010 1000" (4-bit mode, 2 lines, 5x8 dots)

    // Instruction: Clear Display
    sendBitsToLCD(0x01, LCD_RS_INST | LCD_RW_WRITE); // "0000 0001" (clear display)

    sendBitsToLCD(0x80, LCD_RS_INST | LCD_RW_WRITE);

    delayMicroseconds(500);
}

// Display text string
void displayText(int lineNum, const char *stringPointer)
{
    char characterToSend;

    changeLine(lineNum);

    while (*stringPointer)
    {
        characterToSend = *stringPointer;

        // Don't send LF (line feed or new line) since LCD will display LF as some character on the screen
        // Note that ASCII code of LF is 10
        if ((unsigned int)characterToSend != 10)
        {
            sendBitsToLCD(*(stringPointer++), LCD_RS_DATA | LCD_RW_WRITE);
        }
        else
            return;
    }
}

// Change the text line
void changeLine(int line)
{
    if (line == 0)
    {
        sendBitsToLCD(0x80, LCD_RS_INST | LCD_RW_WRITE);
    }
    else if (line == 1)
    {
        sendBitsToLCD(0xC0, LCD_RS_INST | LCD_RW_WRITE);
    }
}

/*
void lcd(char textString[])
{
    //initializeLCD();

    displayText(0, textString);
}
*/