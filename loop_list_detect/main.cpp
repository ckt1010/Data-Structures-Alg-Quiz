#include <cstdlib>
#include <getRandStr.hpp>
#include <iostream>
#include <list_singly.hpp>
#include <string>
using namespace std;

/* reference from https://blog.csdn.net/yangnianjinxin/article/details/79025768 */
int32_t isLoop(listChar &l) {
    pNode fast, slow, firstHit;
    bool isOdd = false;
    fast = slow = l.begin();
    firstHit = nullptr;
    
    while (fast != nullptr)
    {
        fast = fast->next;
        if (fast == nullptr) {
            break;
        }

        if (fast == slow) {
            isOdd = true;
            firstHit = fast;
            break;
        }
        slow = slow->next;
        fast = fast->next;

        if (fast == slow) {
            firstHit = fast;
            break;
        }
    }

    if (firstHit != nullptr) {
        pNode tmp = l.begin();
        if (isOdd) {
            firstHit = firstHit->next;
        }

        int32_t pos = 0;

        while (tmp != firstHit) {
            tmp = tmp->next;
            firstHit = firstHit->next;
            pos++;
        }
        return pos;
    } else {
        return -1;
    }
}

void make_loop(listChar &l, uint32_t pos) {
    pNode lt = l.end();
    pNode loopStartNode = new nodeC;
    loopStartNode->data = 'l';
    lt->next = loopStartNode;
    l.insert(loopStartNode, pos);
}

string make_strList(listChar &l) {
    string str = getRandStr(10);
    for (size_t i = 0; i < str.size(); i++) {
        l.push_back(str[i]);
    }
    return str;
}

void print_loop(listChar &l, string str) {
    pNode tmp1 = l.begin();
    for (size_t i = 0; i < str.size() + 2; i++) {
        cout << tmp1->data;
        tmp1 = tmp1->next;
    }
}

int main() {
    listChar l1, l2, l3;
    string str1 = make_strList(l1);
    make_loop(l1, 0); // loop on head
    cout << "1. make loop list: ";
    print_loop(l1, str1);
    cout << " and check result is " << isLoop(l1) << endl;

    string str2 = make_strList(l2);
    make_loop(l2, 9); // loop on tail
    cout << "2. make loop list: ";
    print_loop(l2, str2);
    cout << " and check result is " << isLoop(l2) << endl;

    string str3 = make_strList(l3);
    make_loop(l3, 5); // loop on middle
    cout << "3. make loop list: ";
    print_loop(l3, str3);
    cout << " and check result is " << isLoop(l3) << endl;
    return 0;
}