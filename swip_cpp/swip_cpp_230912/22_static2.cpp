// 22_static2.cpp
#include <iostream>
using namespace std;

// 1. C++11부터 멤버 데이터 변수의 초기값을 지정할 수 있는 문법이
//    도입되었습니다.

// 2. 멤버 데이터와 멤버 함수는 객체의 상태와 행위를 나타내기 때문에,
//    객체를 생성해야지만 접근할 수 있습니다.

// 3. 멤버 함수에서
//    멤버 데이터를 접근하거나, 멤버 함수를 호출할 수 있습니다.
// 4. 멤버 함수에서
//    정적 멤버 데이터를 접근하거나, 정적 멤버 함수를 호출할 수 있습니다.
// 5. 정적 멤버 함수에서는
//    일반 멤버 데이터와 멤버 함수를 접근할 수 없습니다.
//    정적 멤버 데이터와 정적 멤버 함수를 접근할 수 있습니다.

class Sample {
    int a = 100; // 멤버 데이터
    static int s; // 정적 멤버 데이터
public:
    void member_function() { cout << "mfun" << endl; }
    static void static_member_function() { cout << "smfun" << endl; }

    // 멤버 함수
    void foo() // void foo(Sample* this)
    {
        cout << a << endl;
        //  this->a
        member_function();
        //  this->member_function()

        cout << s << endl;
        static_member_function();
    }

    // 정적 멤버 함수
    //  -> 암묵적으로 전달되는 this가 존재하지 않으므로,
    //     일반적인 멤버 데이터와 멤버 함수에 접근할 수 없습니다.
    static void goo()
    {
        // cout << a << endl; /* NO */
        // member_function(); /* NO */

        cout << s << endl; /* OK */
        static_member_function(); /* OK */
    }

    // 객체의 주소를 명시적으로 전달해서,
    // 멤버 데이터와 멤버 함수를 명시적으로 접근해서 호출할 수 있습니다.
    static void goo(Sample* self)
    {
        cout << self->a << endl; /* OK */
        self->member_function(); /* OK */

        cout << s << endl; /* OK */
        static_member_function(); /* OK */
    }
};

int Sample::s = 42;

// 멤버 함수를 객체를 통해서만 호출할 수 있는 이유
// => 멤버 함수의 첫번째 인자로 this(객체의 주소)가 전달되기 때문입니다.

// 정적 멤버 함수는 객체의 주소가 전달되지 않습니다.

int main()
{
    Sample s;
    s.foo();

    // s.goo();
    Sample::goo();
    Sample::goo(&s);
}
