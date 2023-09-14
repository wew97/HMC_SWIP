#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>

// 함수에 정책을 전달할 때, 함수 포인터를 전달합니다.
// * 인라인 함수라도, 함수 포인터에 담아서 호출하면,
//   인라인 최적화가 불가능합니다.
// * C++에서는 함수에 정책을 전달할 때,
//   함수 객체를 사용할 수 있습니다.
//  => 함수 객체는 인라인 최적화가 가능합니다.

bool cmp1(int a, int b)
{
    cout << "cmp1" << endl;
    return a > b;
}

class Cmp {
public:
    bool operator()(int a, int b) const
    {
        return a > b;
    }
};

int main()
{
    vector<int> v = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
    // sort(begin(v), end(v), cmp1);
    //                    bool (*)(int, int)

    Cmp cmp;
    // sort(begin(v), end(v), cmp);
    //                     Cmp

    // C++11, 함수 객체를 만드는 새로운 문법이 도입되었습니다.
    //  => Lambda Expression(람다 표현식)
    //  : 실행 가능한 코드 조각을 참조하는 기술
    //    익명의 함수 객체를 생성하는 문법
    sort(begin(v), end(v), [](int a, int b) -> bool {
        return a > b;
    });

    for (auto e : v) {
        cout << e << endl;
    }
}
