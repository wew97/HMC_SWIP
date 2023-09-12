// 18_초기화리스트2.cpp
#include <iostream>
using namespace std;

// 주의사항
// * 멤버 데이터가 초기화되는 순서는
//   초기화리스트의 순서에 의해서 결정되는 것이 아니라,
//   멤버 데이터가 선언된 순서대로 초기화됩니다.
// => 초기화리스트를 작성할 때, 멤버 데이터가 선언된 순서대로
//    작성해야 합니다.

class Sample {
    int x;
    int y;

public:
    Sample(int n)
        : x { n }
        , y { x + 10 }
    {
    }

    // 잘못된 순서대로 작성되었습니다.
    // => x는 초기화되지 않은 y를 이용해서 초기화됩니다.
    //    미정의 동작!
#if 0
    Sample(int n)
        : y { n }
        , x { y + 10 }
    {
    }
#endif

    void Print()
    {
        cout << x << ", " << y << endl;
    }
};

int main()
{
    Sample s { 100 };
    s.Print();
}
