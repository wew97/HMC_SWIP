// add.cpp
#if 0
#include <iostream>
using namespace std;

// C++에서 C로 컴파일된 함수를 호출할 때, 해당 함수가 C의 형식으로 컴파일되었다는 사실을 컴파일러에게 알려주어야 합니다.
// => extern "C"

extern "C" int add(int a, int b);
//                  U _add

// int add(int a, int b);
//                  U __Z3addii

int main()
{
    cout << add(100, 200) << endl;
}
#endif

#include <iostream>
using namespace std;

extern "C" int add(int a, int b);
// 0000000000000000 T _add

int add(int a, int b)
{
    cout << "C++ add" << endl;
    return a + b;
}
