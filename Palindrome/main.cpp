#include <cstdlib>
#include <getRandStr.hpp>
#include <iostream>
#include <list_singly.hpp>
#include <string>
using namespace std;

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
    listChar l1, l2, l3;
    uint32_t l1_size = 4, l2_size = 6;

    /* test odd string */
    string randStr1 = getRandStr(l1_size+1);
    l1.push_back(*(randStr1.end()-1)); //insert middle
    for (size_t i = 0; i < l1_size; i++) {
        l1.push_front(randStr1[i]);
        l1.push_back(randStr1[i]);
    }
    cout << "check list 1 is: ";
    l1.printAll();
    cout << "is Palindrome? " << isPalindrome_fastSlowPointer(l1) << endl;
    l1.printAll();

    /* test even string */
    string randStr2 = getRandStr(l2_size);
    for (size_t i = 0; i < l2_size; i++) {
        l2.push_back(randStr2[i]);
        l2.push_front(randStr2[i]);
    }
    cout << "check list 2 is: ";
    l2.printAll();
    cout << "is Palindrome? " << isPalindrome_fastSlowPointer(l2) << endl;
    l2.printAll();

    /* test non-Palindrome string */
    string randStr3 = getRandStr(10);
    for (size_t i = 0; i < 10; i++) {
        l3.push_back(randStr3[i]);
    }
    cout << "check list 3 is: ";
    l3.printAll();
    cout << "is Palindrome? " << isPalindrome_fastSlowPointer(l3) << endl;
    l3.printAll();
    return 0;
}