// 13_stack9.cpp
// 이미 C++ 표준 라이브러를 통해 다양한 자료구조가 제공되고,
// 그 중에 스택이 있습니다.

// STL(Standard Template Library)
//  : 템플릿 기반으로 모든 타입에 일반적으로 동작하는 표준 라이브러리

// - 자료구조: 컨테이너, 컬렉션

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    // 데이터를 제거하는 연산과 참조하는 연산이 분리되어 있습니다.
    //  참조 연산: s.top()
    //  제거 연산: s.pop()
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
}
