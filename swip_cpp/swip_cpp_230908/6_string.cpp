// 6_string.cpp
#include <iostream>
using namespace std;

#include <cstring>

// C의 문자열
// : '\0'문자로 종료되는 char 배열

// C의 문자열 문제점
// 1) 문자열의 기본적인 연산을 함수를 통해서 수행해야 합니다.
// 2) 문자열 연산을 수행할 때, 메모리를 직접 관리해야 합니다.
//    메모리가 충분히 확보되지 않은 상태로 연산을 수행할 경우,
//    미정의 동작이 발생합니다.
#if 0
int main()
{
    char str1[32] = "hello";
    const char* str2 = "hello";

    if (strcmp(str1, str2) == 0) {
        cout << "동일한 문자열" << endl;
    } else {
        cout << "다른 문자열" << endl;
    }

    char other[32];
    strcpy(other, str1);
    cout << other << endl;

    strcat(other, " world");
    cout << other << endl;
}
#endif

#include <string>
// C++은 문자열을 다루기 위한 새로운 타입이 도입되었습니다.
//  : std::string
// 1) 문자열의 기본적인 비교/복사/연결 등의 작업을 연산자를 통해
//    직관적으로 수행할 수 있습니다.
// 2) 문자열 메모리를 자동적으로 관리합니다.
//   - 미정의 동작의 위험성이 적습니다.
//   - 성능도 잘 최적화되어 있습니다.
//     SSO(Simple String Optimization)
//     : 짧은 길이 문자열의 경우, 지역으로 메모리를 할당해서 사용합니다.

int main()
{
    string s1 = "hello";
    string s2("hello");
    string s3 { "hello" };

    if (s1 == s2) {
        cout << "같은 문자열" << endl;
    } else {
        cout << "다른 문자열" << endl;
    }

    // string other = s1;
    string other { s1 };
    cout << other << endl;

    // other = other + " world";
    other += " world";
    cout << other << endl;
}
