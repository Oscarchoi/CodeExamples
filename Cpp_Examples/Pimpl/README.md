**pimpl 관용구 (pointer to implementation)**

- 포인터 뒤에 실제 객체의 구현부를 숨길 수 있다.
- 사용자는 객체의 멤버 변수나 메소드를 알 필요가 없으며, 따라서 구현 세부 사항과 인터페이스를 완전히 분리할 수 있다.

* 객체 참조자 및 포인터로 충분한 경우에는 객체를 직접 쓰지 않는다.
* 클래스 정의 대신 클래스 선언에 최대한 의존하도록 만든다.
* 선언부와 정의부에 대해 별도의 해더 파일을 제공한다.

* reference - [https://en.cppreference.com/w/cpp/language/pimpl](https://en.cppreference.com/w/cpp/language/pimpl)