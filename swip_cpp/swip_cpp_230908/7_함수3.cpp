// 7_함수3.cpp
#include <iostream>
using namespace std;

// 인라인 함수
// => 함수를 호출하지 않고, 함수의 기계어로 호출부를 치환합니다.
// => 인라인 최적화는 컴파일러 최적화 명령입니다.
//    MSVC: /Ob1
//    1) 함수가 더이상 호출되지 않기 때문에,
//       인라인 치환이 수행되는 함수의 기계어 코드가 코드 메모리 상에
//       존재하지 않습니다.
//    2) 짧은 길이가 아닌 함수에 대해서 인라인 최적화를 사용할 경우,
//       전체적인 코드 메모리 사용량이 증가합니다.
//      => 인라인 함수는 간결한 함수에서 유용합니다.
//    3) 최신 컴파일러는 인라인 함수라고 하더라도, 함수의 구현이 복잡한 경우
//       인라인 최적화를 수행하지 않습니다.
//  : 매크로 함수를 함수 호출의 오버헤드를 제거하는 목적으로 사용하기 보다는
//    인라인 함수를 사용하는 것이 좋습니다.
//   - C99 표준에서도 인라인 함수가 도입되었습니다.
//   C++: inline void foo() {}
//     C: static inline void foo(void) {}
//   => 인라인 함수는 컴파일 시간에 함수의 호출을 구현으로 치환해야 하기 때문에
//      인라인 함수의 구현이 헤더 파일을 통해 제공되어야 합니다.
//     : 인라인 함수는 internal linkage를 갖습니다.

inline int square(int x) { return x * x; }

int main()
{
    int x = 10;

    int result = square(x);
    /*
        mov     eax, DWORD PTR x$[rsp]
        imul    eax, DWORD PTR x$[rsp]
        mov     DWORD PTR result$[rsp], eax
    */

    cout << result << endl;

    int result2 = x * x;
    /*
        mov     eax, DWORD PTR x$[rsp]
        imul    eax, DWORD PTR x$[rsp]
        mov     DWORD PTR result2$[rsp], eax
    */

    cout << result2 << endl;
}
