// 30_예외.cpp
#include <iostream>
#include <string>
using namespace std;

// int atoi(const char *str);
//   : 전달된 문자열로 표현된 숫자를 정수 타입으로 변경해줍니다.
// 실패할 경우, 0을 반환합니다.
//  => 성공과 실패를 구분하기 어렵습니다.
//  원인: 함수의 결과와 함수의 에러를 모두 return을 통해
//       전달하기 때문입니다.
#if 0
int main()
{
    /// int n = atoi("42");
    // int n = atoi("xxx");
    int n = atoi("0");

    cout << n << endl;
}
#endif

// * 반환값을 통한 오류 처리의 문제점
// 1) 함수의 결과와 오류의 결과가 동일하지 않도록 주의해야 합니다.
//   : 결과와 오류를 모두 return 합니다.

// 2) 함수를 수행하였을 때, 실패 가능성이 존재하는 경우
//    반드시 오류를 체크해야 합니다.
//   : 오류 처리를 강제할 수 없습니다.

// * C++은 예외를 지원합니다.
#if 0
int ProcessFile(const string& filename)
{
    if (filename == "") {
        return -1;
    }

    // 연산의 결과를 반환합니다.
    return 0;
}

int main()
{
    int result = ProcessFile("");
    // ...
}
#endif

// 1. 오류는 throw 하고, 결과는 return 합니다.
// 2. 오류가 발생하였을 때, 예외를 처리하지 않으면
//    프로그램이 비정상 종료됩니다.
// 3. throw 오류(예외)를 처리하기 위해서는 try{}catch{}을 통해
//    오류를 처리할 수 있습니다.
int ProcessFile(const string& filename)
{
    if (filename == "") {
        // throw -1; // 예외
        throw 3.14;
    }

    // 연산의 결과를 반환합니다.
    return 0;
}

int main()
{
    try {
        int result = ProcessFile("11");
        cout << "정상 동작" << endl;
    } catch (int e) {
        cout << e << endl;
    } catch (double e) {
        cout << e << endl;
    }

    cout << "프로그램 종료" << endl;
}
