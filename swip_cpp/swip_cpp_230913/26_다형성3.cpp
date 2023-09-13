// 26_다형성3.cpp
#include <iostream>
#include <vector> // 컨테이너
using namespace std;

#if 0
class Dog { };
class Cat { };

// 각 타입을 위한 별도의 컨테이너를 사용해야 합니다.
int main()
{
    vector<Dog*> dogs;
    dogs.push_back(new Dog);
    dogs.push_back(new Dog);
    dogs.push_back(new Dog);

    vector<Cat*> cats;
    cats.push_back(new Cat);
    cats.push_back(new Cat);
    cats.push_back(new Cat);
}
#endif

// 활용 2. 동종을 보관하는 컨테이너
class Animal { };
class Dog : public Animal { };
class Cat : public Animal { };

int main()
{
    vector<Animal*> animals;
    animals.push_back(new Dog);
    animals.push_back(new Cat);
}

#if 0
int main()
{
    // int x[5]; // 정적 배열: 크기가 고정되어 있습니다.
    // vector - 동적 배열: 크기가 동적으로 늘어납니다.

    vector<int> v = { 10, 20, 30, 40, 50 };
    v.push_back(100);
    v.push_back(200);
    v.push_back(300);

    cout << v[0] << endl;
    for (auto e : v) {
        cout << e << endl;
    }
}
#endif
