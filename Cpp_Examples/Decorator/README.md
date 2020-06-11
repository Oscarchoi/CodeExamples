# 데코레이터(Decorator) 패턴
## 개요

- 기존에 작성된 클래스에 코드를 수정하지 않고 기능을 추가할 수 있도록(OCP) 하는 구조 패턴
- 상속을 사용할 수 없는 상황(ex. virtual 소멸자가 없는 std::vector 등)의 상황에 적합

## 동적 데코레이터
상속 대신 컴포지션으로 데코레이터를 만들 수 있다. 이미 생성된 Shape의 객체의 참조를 저장하고 런타임에 동적으로 합성할 수 있다. 다만, 원본 객체가 가진 멤버들에 접근할 수 없다.

- [C++ Example](https://github.com/Oscarchoi/CodeExamples/blob/master/Cpp_Examples/Decorator/dynamic_decorator.cc)

## 정적 데코레이터
부모 클래스는 없지만 자식 클래스에만 존재하는 메소드가 있다면 동적 데코레이터에서는 이를 호출할 수 없다. 데코레이터들은 기본적으로 부모 클래스만 상속하기 때문이다.

예를 들어 Circle : Shape 클래스가 있다고 할 때, resize() 메소드가 Circle에만 있고 Shape에 없다면, Shape를 상속 받는 일반적인 데코레이터들은 resize() 함수를 호출할 수 없다. 이런 경우, 템플릿과 상속을 이용하는 정적 데코레이터를 통해 구현할 수 있다.

믹스인 상속(템플릿 파라미터를 통한 상속)을 이용해 컴파일 시점에 데커레이터를 합성한다. 이 경우에는 런타임에 객체를 다시 합성할 수가 없다. 하지만 원본 객체의 멤버들에 접근할 수 있는 장점이 있다. 그리고 생성자 포워딩을 통해 객체를 완전하게 초기화할 수 있다.

- [C++ Example](https://github.com/Oscarchoi/CodeExamples/blob/master/Cpp_Examples/Decorator/static_decorator.cc)

## 함수형 데코레이터
코드 불록이나 특정 함수에 다른 함수에 다른 동작을 덧씌워 합성할 수 있다.
- [C++ Example](https://github.com/Oscarchoi/CodeExamples/blob/master/Cpp_Examples/Decorator/functional_decorator.cc)