#pragma once
#include <stdint.h>

template <typename T> class queue_ringArr {
  private:
    uint32_t _size;
    T *_ringArr;
    uint32_t _head;
    uint32_t _tail;

  public:
    queue_ringArr(uint32_t size) : _size(size), _tail(0), _head(0) {
        _ringArr = new T[size];
    }

    ~queue_ringArr() { delete[] _ringArr; }

    void push(T c) {
        if (_head == ((_tail + 1) % _size)) {
            throw "queue is full";
        }

        _ringArr[_tail] = c;
        if (_size > _tail) {
            _tail++;
        } else {
            _tail = 0;
        }
    }

    void pop(T &c) {
        if (_tail == _head) {
            throw "queue is empty";
        }

        c = _ringArr[_head];
        if (_size > _head) {
            _head++;
        } else {
            _head = 0;
        }
    }
};
