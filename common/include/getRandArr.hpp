#pragma once

#include <cstdlib>
#include <time.h>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_RAND 1000
#define MIN_RAND 0

class getRandArr {
  private:
    vector<uint32_t> _arr;

  public:
    getRandArr(uint32_t len = 0);
    vector<uint32_t> get() { return _arr; }
    vector<uint32_t> getAfterSort() {
        vector<uint32_t> tmp = _arr;
        sort(tmp.begin(), tmp.end());
        return tmp;
    }
};

getRandArr::getRandArr(uint32_t len) {
    srand(time(0));
    if (0 == len) {
        len = rand();
    }

    for (size_t i = 0; i < len; i++) {
        _arr.push_back((rand() % (MAX_RAND - MIN_RAND)) + MIN_RAND);
    }
}
