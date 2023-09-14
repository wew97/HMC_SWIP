// 31_연산자오버로딩4.cpp
#include <iostream>
using namespace std;

// 1. endl은 함수 입니다.
//  => IO 조정자(IO Manipulator)
ostream& xendl(ostream& os)
{
    return os << '\n';
}

// 2. 사용자는 다양한 형태의 IO 조정자로 복잡한 출력의 과정을
//    함수로 캡슐화 할 수 있습니다.
ostream& menu(ostream& os)
{
    os << "1. 짜장면" << endl;
    os << "2. 짬뽕" << endl;
    os << "3. 탕수육" << endl;

    return os;
}

int main()
{
    cout << menu;
}

#if 0
int main()
{
    cout << "hello";
    cout << xendl;
    // cout.operator<<(xendl);
    /*
        ostream& operator<<(ostream& (*f)(ostream&)) {
            f(*this);
            return *this;
        }
    */

    // xendl(cout);
}
#endif
