#pragma once

#include "list_singly.hpp"

template <typename T> class stack_list : private list_signly<T> {
  public:
    void push(T c) { list_signly<T>::push_front(c); }
    void pop(T &c) { list_signly<T>::pop_front(c); }
};
