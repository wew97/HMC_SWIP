// 7_제어문2.c
#include <stdio.h>

#if 0
int main(void)
{
    int day;
    printf("day(1-7): ");

    scanf("%d", &day);

    // 아래의 형태는 switch 문을 사용하면
    // 편리합니다.
    if (day == 1) {
        printf("월\n");
    }
    else if (day == 2) {
        printf("화\n");
    }
    else if (day == 3) {
        printf("수\n");
    }
    else if (day == 4) {
        printf("목\n");
    }
    else if (day == 5) {
        printf("금\n");
    }
    else if (day == 6) {
        printf("토\n");
    }
    else if (day == 7) {
        printf("일\n");
    }
    else {
        printf("잘못된 입력입니다.\n");
    }

    return 0;
}
#endif

int main(void)
{
    int day;
    printf("day(1-7): ");

    scanf("%d", &day);

    // 1. break를 사용해야 합니다.
    // 2. default
    //  => 값이 일치하지 않는 경우를 처리할 수 있습니다.
    //  => else의 역할과 동일합니다.

    switch (day) {
    case 1:
        printf("월\n");
        break;
    case 2:
        printf("화\n");
        break;
    case 3:
        printf("수\n");
        break;
    case 4:
        printf("목\n");
        break;
    case 5:
        printf("금\n");
        break;
    case 6:
        printf("토\n");
        break;
    case 7:
        printf("일\n");
        break;

    default:
        printf("잘못된 입력입니다.\n");
        break; // 일관성 있게 break를 작성하는 것이 좋습니다.
    }

    return 0;
}