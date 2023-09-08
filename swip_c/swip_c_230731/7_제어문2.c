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

#if 0
int main(void)
{
    int day;
    printf("day(1-7): ");

    scanf("%d", &day);

    // 1. break를 사용해야 합니다.
    // 2. default
    //  => 값의 일치하는 경우를 처리할 수 있습니다.
    //  => else의 역활과 동일합니다.
    // - switch 에서 break는 반드시 작성되어야 합니다.
    // - default는 가장 위와 마지막만 허용합니다.

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
#endif

int main(void)
{
    char grade = 'D';

    // MISRA 에서 아래처럼 사용하는 것은 허용됩니다.
    switch (grade) {
    case 'A':
        printf("우와\n"); /* 허용 하지 않습니다. */
    case 'B':
        printf("합격\n");
        break;
    case 'C':
        printf("보류\n");
        break;

    case 'D': /* 특정 라벨에서 아무것도 수행하지 않고, 내리는 경우만 허용합니다. */
    case 'F':
        printf("불합격\n");
        break;
    default:
        printf("잘못된 입력입니다.\n");
        break;
    }

    return 0;
}