#ifndef __OBSERVER_H__
#define __OBSERVER_H__

#include <string>

template <typename T> struct Observer {
  virtual void field_changed(T &source, const std::string &field_name) = 0;
};

#endif