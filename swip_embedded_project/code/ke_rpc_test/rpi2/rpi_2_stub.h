enum FUNC_ID { DISPLAY_TEXT, MOVE_MOTOR, TERMINATE };

void displayTextUnmarshall(char* buffer, int* lineNum, char* inputString);
void moveMotorUnmarshall(char* buffer, int* inputVal);
void terminateRPCUnmarshall(char* buffer, char* inputString);