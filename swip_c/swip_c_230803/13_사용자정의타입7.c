// 13_���������Ÿ��7.c
#include <stdio.h>
#include <string.h>

// 1. struct(����ü)
// 2. union(����ü)
// 1) ��� ������ ���� �� ���� ū ũ�⸦ ������ ����� ũ���
//    ����ü Ÿ���� ũ�Ⱑ �����˴ϴ�.
// 2) �� ����� ������ �޸𸮸� �����մϴ�.

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
// ��ȣ ��Ÿ���� �����͸� ������ ��,
// �޸𸮸� ȿ�������� ����� �� �ֽ��ϴ�.
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