// rpi_2_lcd.h

void toggleLCDEnable(int eightBits);
void sendBitsToLCD(int eightBits, int mode);
void initializeLCD();
void displayText(int lineNum, const char *stringPointer);
void changeLine(int line);
//void lcd(char textString[]);