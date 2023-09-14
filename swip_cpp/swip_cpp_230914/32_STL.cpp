// 32_STL.cpp
#include <iostream>
using namespace std;

// 시간 복잡도
//  => O(Big-oh 표기법)
//  => 데이터의 개수에 따라 성능의 추이
//  O(N)

// STL(Standard Template Library)
// - 1979년: C++ 탄생
// - 1998년: 1차 표준안, STL

// * STL 구성요소 3가지
// 1) 컨테이너: 자료구조
//   - vector, stack, list, deque, queue, map, set ...
//    vector
//      : 동적 배열, 연속된 메모리
//    장점: 임의 접근(Random Access)
//    단점: 데이터의 중간 삽입/삭제가 불편합니다.

//    list
//      : 연결 리스트
//    단점: 임의 접근이 불가능합니다.
//    장점: 데이터 삽입/삭제가 용이합니다.

//    deque
//     => 선형 자료 구조
//     => vector와 list의 절충형 자료구조
// 2) 알고리즘
// 3) 반복자

// * 컨테이너 특징
// 1) 템플릿 기반입니다.
//  - 타입에 상관없이 다양한 자료구조 사용할 수 있습니다.

// 2) 멤버 함수의 이름이 유사합니다.
//  - 자료구조의 전환을 쉽게 수행할 수 있습니다.

// 3) 데이터를 참조하는 연산과, 제거하는 연산이 분리되어 있습니다.
//  => 값을 반환하는 것이 아니라, 참조를 반환하기 위해서
//     반환용 임시 객체 복사/제거 비용을 제거하기 위해서

//     |---------------------|
// push_front     |      push_back  : 데이터 추가
//  pop_front     |      pop_back  : 데이터 제거
//    front       |      back    : 데이터 참조
//          insert/remove

#include <vector>
#include <list>
#include <deque>
#if 0


int main()
{
    deque<int> v = { 10, 20, 30 };
    v.push_back(100);
    v.push_back(200);
    v.push_back(300);

    v.pop_back();
    v.pop_back();
    v.pop_back();

    cout << v.back() << endl;

    for (auto e : v) {
        cout << e << endl;
    }
}
#endif

// 4) 자료구조의 형태에 따라서 지원되는 연산이 다를 수 있습니다.
//  - vector는 임의접근 연산자를 지원하지만,
//    list는 지원하지 않습니다.
//    : list[2] /* Error */

//  - list는 데이터를 앞에서 추가하고, 제거할 수 있지만
//    vector 불가능합니다.
//    : vector.push_front() /* Error */
//      vector.pop_front() /* Error */

#if 0
int main()
{
    // vector<int> v = { 10, 2, 3, 1, 4, 24, 5 };
    vector<int> v = { 10, 2, 3, 1, 4, 24, 5 };

    // 연속된 메모리이기 때문에 임의접근 연산이 가능합니다.
    cout << v[3] << endl;
    v[1] = 2000;
}
#endif

int main()
{
    list<int> v = { 10, 20, 30, 40, 50 };
    // vector<int> v = { 10, 20, 30, 40, 50 }; /* 지원하지 않습니다. */

    v.push_front(1000);
    v.pop_front();

    for (auto e : v) {
        cout << e << endl;
    }
}
