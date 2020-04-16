#include "queue_ringArr.hpp"
#include <getRandArr.hpp>
#include <iostream>
#include <string>
using namespace std;
typedef queue_ringArr<char> queueRingArrChar;

int main() {

    queueRingArrChar q1(10);
    try {
        char c1;
        q1.pop(c1);
    } catch (const char *e) {
        std::cerr << e << '\n';
    }

    try {
        string s = "fdafasfasdfsafsdffffff";
        for (auto c : s) {
            q1.push(c);
        }
    } catch (const char *e) {
        std::cerr << e << '\n';
    }

    try {

        cout << "string1:";
        for (size_t i = 0; i < 5; i++) {
            char c1;
            q1.pop(c1);
            cout << c1;
        }
        cout << endl;

        string s = "123242";
        for (auto c : s) {
            q1.push(c);
        }
        cout << "string2:";
        for (size_t i = 0; i < s.size(); i++) {
            char c1;
            q1.pop(c1);
            cout << c1;
        }
        cout << endl;

    } catch (const char *e) {
        std::cerr << e << '\n';
    }
    return 0;
}