# CRTP (Curiously Recurring Template Pattern)
Static polymorphism

## mechanism
베이스 클래스 템플릿은 lazy instantiation의 특성에 기반한다.

```
template <typename T>
struct Base {
  void interface() { 
    static_cast<T *>(this)->implementation(); }  
};

struct Derived : Base<Derived> {
  void implementation(){
    ...
  };  
};
```
위 코드에서 Base<Derived>::interface() 는 struct Derived 가 선언되기 전에 (컴파일러가 인지하기 전) 선언되지만 실제 함수에서 호출되기 전에는 인스턴스화 되지 않는다.

따라서 실제 함수 호출 시점에 Derived가 선언되고 implementation()이 선언 되었다면, 문제없이 인스턴스화 될 수 있다.


## static polymorphism
베이스 클래스의 파생 클래스 구현 호출을 컴파일 시점에 결정할 수 있다. 이는 동적 바인딩과 유사하지만, vtable이나 virtual 메소드들을 사용하지 않아 성능적인 이점이 있다.

[static_polymorphism.cc](https://github.com/Oscarchoi/CodeExamples/blob/master/Cpp_Examples/CRTP/static_polymorphism.cc) 에서 정적 바인딩이 가능함을 확인할 수 있다.





