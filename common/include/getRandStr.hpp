#pragma once

#include <string>
using namespace std;

class getRandStr {
  private:
    const string _alphanum = "0123456789"
                             "!@#$%^&*"
                             "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                             "abcdefghijklmnopqrstuvwxyz";

    char genRandom() { return _alphanum[rand() % _alphanum.size()]; }
    std::string _str;

  public:
    getRandStr(uint32_t len = 0) {
        srand(time(0));
        if (0 == len) {
            len = rand();
        }
        for (unsigned int i = 0; i < len; ++i) {
            _str += genRandom();
        }
    }

    operator string() { return _str; }
    operator char() { return _str[0]; }
};
