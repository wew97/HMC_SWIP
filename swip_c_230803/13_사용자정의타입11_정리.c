// 13_사용자정의타입11.c
#include <stdio.h>

typedef struct {
    int x;
    int y;
} MouseEvent;

typedef struct {
    int keyCode;
} KeyEvent;

typedef union {
    MouseEvent mouse;
    KeyEvent key;
} EventData;

typedef enum {
    MOUSE,
    KEY
} EventType;

typedef struct {
    EventType type;
    EventData data;
} Event;

void PrintEvent(const Event* event)
{
    // 열거 상수는 컴파일 상수이기 때문에,
    // case의 라벨로 사용할 수 있습니다.
    switch (event->type) {
    case MOUSE:
        printf("Mouse Event: (%d, %d)\n",
            event->data.mouse.x, event->data.mouse.y);
        break;
    case KEY:
        printf("Key Event: %d\n", event->data.key.keyCode);
        break;
    default:
        printf("잘못된 이벤트 타입입니다.\n");
        break;
    }
}

int main(void)
{
    Event mouseEvent = {
        .type = MOUSE,
        .data.mouse.x = 10,
        .data.mouse.y = 20
    };
    PrintEvent(&mouseEvent);

    Event keyEvent = {
        .type = KEY,
        .data.key.keyCode = 65
    };
    PrintEvent(&keyEvent);

    return 0;
}