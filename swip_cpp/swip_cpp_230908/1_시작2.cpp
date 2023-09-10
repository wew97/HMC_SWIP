// 1_시작2.cpp
// https://github.com/yoondev-classroom/cpp_230908

#include <stdio.h> // C의 표준 입출력 헤더

#include <iostream> // C++의 표준 입출력 헤더
// C++에서도 표준 입출력 라이브러리가 제공됩니다.
// => C++의 표준 헤더는 확장자가 없습니다.

// 1) printf/scanf는 변수의 타입에 따라서, 서식을 지정해야 합니다.
//    std::cout/std::cin은 변수의 타입에 따라서 자동으로 처리됩니다.
// => 변수의 타입이 변경되어도, 코드를 수정할 필요가 없습니다.

// 2) std::cin을 통해 변수의 값을 변경할 때,
//    주소를 전달하지 않습니다.

#if 0
int main()
{
    int n = 42;
    double d = 3.14;

    printf("%d\n", n);
    std::cout << n << std::endl;

    printf("%lf\n", d);
    std::cout << d << std::endl;
}
#endif

int main()
{
    double n;
    scanf("%lf", &n);
    printf("%lf\n", n);

    std::cin >> n;
    std::cout << n << std::endl;
}
