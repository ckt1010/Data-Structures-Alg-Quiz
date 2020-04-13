#include <getRandArr.hpp>
#include <iostream>
#include <list_singly.hpp>
#include <string>
using namespace std;
typedef vector<uint32_t> arr;
typedef list_signly<uint32_t> listUint;
typedef list_signly<uint32_t>::pNode pNodeUint;

void make_sortingList(listUint &l, uint32_t len) {
    arr tmp = getRandArr(len).getAfterSort();
    for (size_t i = 0; i < tmp.size(); i++) {
        l.push_back(tmp[i]);
    }
}

void merge(listUint &l1, listUint &l2, listUint &newlist) {
    pNodeUint l1Tmp = l1.begin(), l2Tmp = l2.begin();
    while (l1Tmp != nullptr && l2Tmp != nullptr) {
        pNodeUint &addNode = (l1Tmp->data < l2Tmp->data) ? l1Tmp : l2Tmp; //replace name
        newlist.push_back(addNode);
        addNode = addNode->next;
    }

    for (; l1Tmp != nullptr; l1Tmp = l1Tmp->next) {
        newlist.push_back(l1Tmp);
    }
    for (; l2Tmp != nullptr; l2Tmp = l2Tmp->next) {
        newlist.push_back(l2Tmp);
    }
}

int main() {
    listUint *l1 = new listUint;
    listUint *l2 = new listUint;
    listUint* newlist = new listUint;
    make_sortingList(*l1, 10);
    make_sortingList(*l2, 20);
    cout << "We need merge: ";
    l1->printAll();
    cout << "And ";
    l2->printAll();

    merge(*l1, *l2, *newlist);
    cout << "After merge: ";
    newlist->printAll();
    newlist->erase(1);
    newlist->erase(-1);
    cout << "After delete: ";
    newlist->printAll();
    delete newlist;//since l1 and l2 merged to newlist, only newlist need delete
    return 0;
}