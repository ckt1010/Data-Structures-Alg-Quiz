#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;

typedef struct node_t {
    node_t *next;
    char data;
} node, *pNode;

template <typename T> class list_one {
  private:
    pNode _head;
    pNode _tail;
    uint32_t _size;

  public:
    pNode begin() { return _head; };
    pNode end() { return _tail; };
    list_one() : _head(nullptr), _tail(nullptr), _size(0) {}
    ~list_one() {
        pNode prev;
        for (size_t i = 0; i < _size; i++) {
            prev = _head;
            _head = _head->next;
            delete prev;
        }
    }
    void push(T c) {
        if (_size == 0) {
            _head = _tail = new node;
            _head->next = nullptr;
        } else {
            _tail->next = new node;
            _tail = _tail->next;
            _tail->next = nullptr;
        }
        _tail->data = c;
        _size++;
    }
    void printAll() {
        pNode cur = _head;
        for (size_t i = 0; i < _size; i++) {
            cout << cur->data;
            cur = cur->next;
        }
        cout << endl;
    }
};

typedef list_one<char> listChar;

bool isPalindrome_fastSlowPointer(listChar &l) {
    bool isOdd = true, isPalindrome = true;
    pNode slow, fast, nextTmp, prevTmp = nullptr;
    slow = fast = l.begin();
    nextTmp = slow != nullptr ? slow->next : nullptr;
    while (nullptr != fast) {
        /* forward fast pointer */
        fast = fast->next;
        if (nullptr == fast) {
            isOdd = false;
            break;
        }
        fast = fast->next;

        /* forward and revers slow pointer */
        slow->next = prevTmp;
        prevTmp = slow;
        slow = nextTmp;
        nextTmp = nextTmp->next;
    }

    pNode highHalfPointer = prevTmp;
    pNode lowHalfPointer = nextTmp;
    // calibration
    if (isOdd) {
        highHalfPointer = highHalfPointer->next;
    }

    // compare
    while (nullptr != highHalfPointer && nullptr != lowHalfPointer) {
        if (highHalfPointer->data != lowHalfPointer->data) {
            isPalindrome = false;
            break;
        }
        highHalfPointer = highHalfPointer->next;
        lowHalfPointer = lowHalfPointer->next;
    }

    // resume
    pNode tmp = prevTmp;
    prevTmp = nextTmp;
    nextTmp = tmp;
    while (nullptr != slow) {
        /* forward and revers slow pointer */
        slow->next = prevTmp;
        prevTmp = slow;
        slow = nextTmp;
        nextTmp = nextTmp != nullptr ? nextTmp->next : nullptr;
    }
    return isPalindrome;
}

int main() {
    listChar l1, l2;
    l1.push('1');
    l1.push('0');
    l1.push('2');
    l1.push('0');
    l1.push('1');
    l1.printAll();
    cout << "is Palindrome? " << isPalindrome_fastSlowPointer(l1) << endl;

    
    l2.push('1');
    l2.push('0');
    l2.push('2');
    l2.push('2');
    l2.push('0');
    l2.push('1');
    l2.printAll();
    cout << "is Palindrome? " << isPalindrome_fastSlowPointer(l1) << endl;
    l2.printAll();
    return 0;
}