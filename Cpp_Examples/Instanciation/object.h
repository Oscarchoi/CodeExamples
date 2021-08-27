#ifndef OBJECT_H_
#define OBJECT_H_

template <int N>
class Object {
 public:
  Object() = default;
  ~Object() = default;

  void SayHello();
};

#endif  // OBJECT_H_