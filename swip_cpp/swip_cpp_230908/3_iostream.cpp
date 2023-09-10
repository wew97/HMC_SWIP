// 3_iostream.cpp
#include <iostream>
#include <iomanip> // setw
using namespace std;

int main()
{
    // int n = 0xFAFA;
    // 1111 1010 1111 1010

    // C++11, 0b를 통해 2진수 정수를 표현할 수 있습니다.
    // 정수 상수를 표현할 때, 단일 따옴표를 통해,
    // 가독성을 높일 수 있습니다.
    int n = 0b1111'1010'1111'1010;

    printf("%d\n", n);
    cout << n << endl;

    // IO Manipulator(IO 조정자)
    //  : hex, uppercase, setw, setfill

    printf("%x\n", n);
    cout << hex << n << endl;

    printf("%X\n", n);
    cout << hex << uppercase << n << endl;

    printf("%10X\n", n);
    cout << hex << uppercase << setw(10) << n << endl;

    printf("%010X\n", n);
    cout << hex << uppercase << setw(10) << setfill('0') << n << endl;
}
