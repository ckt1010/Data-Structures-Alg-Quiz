#include "sort.hpp"
#include <iostream>
#include <chrono>
#include "getRandArr.hpp"
using namespace std;
typedef vector<uint32_t> arr;

#define ARRAY_NUM 10000

bool checkList(listUint &listIn, arr arrIn) {
    for (size_t i = 0; i < arrIn.size(); i++) {
        uint32_t tmp = 0;
        listIn.pop_front(tmp);
        if (tmp != arrIn[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    {
        getRandArr randArr1(ARRAY_NUM);
        arr Arr1 = randArr1.get();
        arr ArrRight1 = randArr1.getAfterSort();
        auto t1 = chrono::high_resolution_clock::now();
        sort_bobble(Arr1, Arr1.size());
        auto t2 = chrono::high_resolution_clock::now();

        cout << "Bobble with array sorting execute time: "
             << chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count()
             << "ms and check result: " << (ArrRight1 == Arr1) << endl;
    }
    {
        getRandArr randArr1(ARRAY_NUM);
        arr Arr1 = randArr1.get();
        arr ArrRight1 = randArr1.getAfterSort();
        listUint in;
        for (size_t i = 0; i < Arr1.size(); i++) {
            in.push_back(Arr1[i]);
        }
        auto t1 = chrono::high_resolution_clock::now();
        in.sort_bobble();
        auto t2 = chrono::high_resolution_clock::now();
        cout << "Bobble with array sorting execute time: "
             << chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count()
             << "ms and check result: " << checkList(in, ArrRight1) << endl;
    }
    return 0;
}