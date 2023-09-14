// 32_예외2.cpp
#include <iostream>
#include <string>
using namespace std;

// 1. 예외의 종류에 따라서, 예외의 타입을 제공합니다.
#if 0
class InvalidFileNameException { };
class OutOfMemoryException { };

int ProcessFile(const string& filename)
{
    if (filename == "") {
        throw InvalidFileNameException();
    }

    throw OutOfMemoryException();

    return 0;
}

int main()
{
    try {
        ProcessFile("aaa");
    } catch (const InvalidFileNameException& e) {
        cout << "잘못된 파일 이름입니다." << endl;
    } catch (const OutOfMemoryException& e) {
        cout << "메모리가 부족합니다" << endl;
    }
}
#endif

class InvalidFileNameException : public std::exception {
public:
    const char* what() const noexcept override
    {
        return "잘못된 파일 이름입니다";
    }
};
class OutOfMemoryException : public std::exception {
public:
    const char* what() const noexcept override
    {
        return "메모리가 부족합니다.";
    }
};

int ProcessFile(const string& filename)
{
    if (filename == "") {
        throw InvalidFileNameException();
    }

    throw OutOfMemoryException();

    return 0;
}

int main()
{
    try {
        ProcessFile("aaa");
    } catch (const InvalidFileNameException& e) {
        cout << "잘못된 파일 이름입니다." << endl;
    } catch (const OutOfMemoryException& e) {
        cout << "메모리가 부족합니다" << endl;
    }

    try {
        ProcessFile("aaa");
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
}
