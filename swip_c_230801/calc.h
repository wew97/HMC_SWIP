// calc.h
extern int Add(int a, int b);

extern void foo(void);
extern void goo(void);

// 함수의 선언에서 extern을 사용하지 않는 것도
// 가능하지만 일관성을 위해서 사용하는 경우가
// 많다.

// 전역 변수의 선언은 반드시
// extern을 붙이는 것이 좋다.
// extern int x;

// extern
// => External linkage(외부 연결)
// : 전역 변수와 함수는 다른 파일에서는 접근하거나
//   호출이 가능하다.