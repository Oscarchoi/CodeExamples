#include "person.h"
#include "person_impl.h"

Person::Person(const std::string &name, const int &age)
    : pImpl(new PersonImpl(name, age)) {}

std::string Person::name() const { return pImpl->name(); }
int Person::age() const { return pImpl->age(); }