#include "person_impl.h"

PersonImpl::PersonImpl(const std::string &name, const int &age)
    : _name(name), _age(age) {}

std::string PersonImpl::name() const { return _name; }
int PersonImpl::age() const { return _age; }