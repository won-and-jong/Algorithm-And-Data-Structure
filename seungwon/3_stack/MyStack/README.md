# MyStack
> STL Stack implementation in C++
- std::vector로 구현했다.
- 템플릿 클래스의 선언과 정의를 분리하기 위해 `.hpp` 파일에는 선언만, `.tpp` 파일에는 정의만 작성했다.
- 매개변수 T를 받는 메소드를 그냥 `T`로 받았는데 이는 기본 타입일 때만 고려한 설계였다. 다른 사용자 정의 타입을 효율적으로 처리하려면 `const T&`로 받아야 한다.
