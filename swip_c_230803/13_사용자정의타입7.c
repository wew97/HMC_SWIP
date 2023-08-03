// 13_사용자정의타입7.c
#include <stdio.h>
#include <string.h>

// 1. struct(구조체)
// 2. union(공용체)
// 1) 멤버 데이터 변수 중 가장 큰 크기를 가지는 멤버의 크기로
//    공용체 타입의 크기가 결정됩니다.
// 2) 각 멤버는 동일한 메모리를 공유합니다.

#if 0
union AAA {
    char a;
    double b;
    int c;
};
// |a|
// |------ d ------|
// |-- c --|

// |-|-|-|-|-|-|-|-|
int main(void)
{
    printf("%zu\n", sizeof(union AAA));

    return 0;
}
#endif

#if 0
union Integer {
    long long i64;
    int i32;
    short i16;
    signed char i8;
};

int main(void)
{
    union Integer value;
    value.i64 = 0x1234567812345678;
    printf("%llX\n", value.i64);
    printf("%X\n", value.i32);
    printf("%hX\n", value.i16);
    printf("%hhX\n", value.i8);

    return 0;
}
#endif

#if 0
union Data {
    int value;
    unsigned char bytes[4];
};

int main(void)
{
    union Data data;
    data.value = 0x12345678;
    printf(
        "%X %X %X %X\n",
        data.bytes[0],
        data.bytes[1],
        data.bytes[2],
        data.bytes[3]);

    int n = 0x12345678;
    unsigned char* pn = (unsigned char*)&n;
    printf("%X %X %X %X\n", pn[0], pn[1], pn[2], pn[3]);

    return 0;
}
#endif

#if 0
// 상호 베타적인 데이터를 관리할 때,
// 메모리를 효과적으로 사용할 수 있습니다.
union Job {
    char school[32];
    char company[32];
};

int main(void)
{
    union Job job;
    strcpy(job.company, "Hyundai");
    printf("%s\n", job.company);

    strcpy(job.school, "Seoul");
    printf("%s\n", job.school);

    return 0;
}
#endif