// 11_동적메모리할당.cpp
#include <iostream>
using namespace std;

#include <cstdlib>
#if 0
// malloc
//  void* malloc(size_t size);
// free
//  void free(void* ptr)
// => 표준 라이브러리의 함수를 통해 동적 메모리 할당/해지를 수행합니다.

// 1) malloc은 인자로 메모리의 크기를 받고, void*를 반환합니다.
//    C++에서는 명시적인 캐스팅이 필요합니다.
//     : static_cast
// 2) free
//     : 할당받은 메모리의 주소를 인자로 받습니다.
//     NULL이 전달되었을 경우, 아무일도 수행하지 않습니다.
//     free를 사용할 때, 별도의 NULL 체크가 필요하지 않습니다.

int main()
{
    int* p = static_cast<int*>(malloc(sizeof(int)));
    free(p);

    int* p2 = NULL;
    free(p2); // 아무일도 일어나지 않습니다.
}
#endif

// 3. C++은 동적 메모리 할당을 연산자를 통해 제공합니다.
//    new / delete

// 4. malloc은 메모리의 사이즈를 전달하지만,
//    new는 타입을 전달합니다.
//    malloc은 할당된 메모리의 주소가 void*로 반환되지만,
//    new는 전달된 타입의 주소 타입으로 반환됩니다.
//   => 별도의 캐스팅이 필요하지 않습니다.

// 5. new를 통해 할당한 주소를 전달하면 됩니다.
//    delete로 전달된 주소가 NULL일 경우, 아무일도 수행하지 않습니다.
#if 0
int main()
{
    int* p = new int;
    delete p;

    p = NULL;
    delete p;
}
#endif

// 6. 연속으로 할당된 메모리를 해지할 때는,
//    delete[] 연산자를 사용해야 합니다.
#if 0
int main()
{
    int* p1 = static_cast<int*>(malloc(sizeof(int) * 10));
    free(p1);

    int* p2 = new int[10]; // 40byte 할당
    // delete p2; /* 미정의 동작 */
    delete[] p2;
}
#endif

int main()
{
    int* p = static_cast<int*>(malloc(sizeof(int)));
    // 할당된 메모리는 쓰레기값을 가집니다.
    free(p);

    int* p2 = new int;
    // 할당된 메모리는 쓰레기값을 가집니다.
    delete p2;

    // 하지만, new를 통해서는 할당된 메모리에 초기값을 지정할 수 있습니다.
    // int* p3 = new int(10);
    int* p3 = new int { 10 };
    cout << *p3 << endl;
    delete p3;

    int* p4 = new int[3] { 10, 20, 30 };
    cout << p4[0] << endl;
    cout << p4[1] << endl;
    cout << p4[2] << endl;
    delete[] p4;
}
