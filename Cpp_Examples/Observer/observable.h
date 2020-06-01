#ifndef __OBSERVABLE_H__
#define __OBSERVABLE_H__

#include "observer.h"

#include <mutex>
#include <string>
#include <vector>

template <typename T> struct Observable {
  void notify(T &source, const std::string &name) {
    std::scoped_lock<mutex> lock{mtx};
    for (auto obs : observers)
      obs->field_changed(source, name);
  };
  void subscribe(Observer<T> *f) {
    std::scoped_lock<mutex> lock{mtx};
    observers.push_back(f);
  };
  void unsubscribe(Observer<T> *f) {
    std::scoped_lock<mutex> lock{mtx};
    observers.erase(std::remove(observers.begin(), observers.end(), f));
  };

private:
  std::vector<Observer<T> *> observers;
  std::mutex mtx;
};

#endif