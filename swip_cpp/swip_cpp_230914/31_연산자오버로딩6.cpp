// 31_연산자오버로딩6.cpp
#include <iostream>
using namespace std;

class Image {
public:
    Image() { cout << "Image()" << endl; }
    ~Image() { cout << "~Image()" << endl; }

    void Draw() const { cout << "Draw Image" << endl; }
};

#if 0
// Image* 역활을 수행하는 클래스입니다.
//  => 스마트 포인터(Smart Pointer)
//   : RAII(Resource Acquation Is Initalize)
class Ptr {
    Image* obj;

public:
    Ptr(Image* p = nullptr)
        : obj { p }
    {
    }

    // 아래의 연산자 오버로딩은 멤버 함수를 통해서만 제공할 수 있습니다.
    // 1) 포인터 역참조 연산자 오버로딩
    Image& operator*() { return *obj; }

    // 2) 포인터 멤버 접근 연산자 오버로딩
    Image* operator->() { return obj; }

    ~Ptr() { delete obj; }
};
#endif

template <typename TYPE>
class Ptr {
    TYPE* obj;

public:
    Ptr(TYPE* p = nullptr)
        : obj { p }
    {
    }

    // 아래의 연산자 오버로딩은 멤버 함수를 통해서만 제공할 수 있습니다.
    // 1) 포인터 역참조 연산자 오버로딩
    TYPE& operator*() { return *obj; }

    // 2) 포인터 멤버 접근 연산자 오버로딩
    TYPE* operator->() { return obj; }

    ~Ptr() { delete obj; }
};

#if 0
int main()
{
    // 클래스 템플릿에서 타입을 추론하는 것 - C++17
    // Ptr p { new Image };
    Ptr<Image> p { new Image };

    (*p).Draw();
    // (p.operator*()).Draw()

    p->Draw();
    // p.operator->()Draw();
    // 컴파일러는 아래와 같이 처리해줍니다.
    // => (p->)->Draw()
    //  : (p.operator->())->Draw()
}
#endif

#if 0
int main()
{
    Image* p = new Image;
    p->Draw();

    delete p;
}
#endif

// C++ 표준 라이브러리에 스마트 포인터가 제공됩니다.
#include <memory>

// shared_ptr
//  : 참조 계수
// unique_ptr
//  : 복사 금지

int main()
{
    // shared_ptr<Image> p { new Image };
    unique_ptr<Image> p { new Image };
    p->Draw();
    (*p).Draw();

    auto p2 = std::move(p);
    cout << p << endl;
    cout << p2 << endl;
}
