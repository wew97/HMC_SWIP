// 33_STL2.cpp
#include <iostream>
using namespace std;

// 반복자(Iterator)
// : 배열에서 포인터의 역활과 유사합니다.
//   컨테이너에서 요소의 위치를 참조하는 역활입니다.

// C++에서는 반개구간을 사용합니다.
//  [begin, end)
#if 0
int main()
{
    //          p1            p2
    //           |             |
    int x[5] = { 1, 2, 3, 4, 5 };

    int* p1 = x; // 시작 위치
    int* p2 = x + 5; // 마지막 요소 다음 위치(Past the end)

    while (p1 != p2) {
        cout << *p1 << endl;
        ++p1;
    }
}
#endif

// begin(x), x.begin(): 시작 위치를 가르키는 반복자
//     end(x), x.end(): 끝 다음 위치를 가르키는 반복자
//  => 일반 함수를 사용하는 것이 좋습니다.
//    :  배열도 컨테이너와 동일하게 사용할 수 있습니다.
#include <vector>
#include <list>
#include <deque>

int main()
{
    // int x[5] = { 1, 2, 3, 4, 5 };
    vector<int> x = { 1, 2, 3, 4, 5 };

    // vector<int>::iterator p1 = begin(x);

    // C++11, 일반 함수를 통해 반복자를 얻을 수 있습니다.
    // => 배열도 컨테이너와 동일하게 사용할 수 있습니다.

    // auto p1 = begin(x); // 시작 위치
    // auto p2 = end(x); // 마지막 요소 다음 위치(Past the end)

    auto p1 = x.begin();
    auto p2 = x.end();

    while (p1 != p2) {
        cout << *p1 << endl;
        ++p1;
    }
}
