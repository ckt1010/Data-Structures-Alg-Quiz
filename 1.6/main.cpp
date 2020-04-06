#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;

static const char alphanum[] = "0123456789"
                               "!@#$%^&*"
                               "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                               "abcdefghijklmnopqrstuvwxyz";

int stringLength = sizeof(alphanum) - 1;

char genRandom() { return alphanum[rand() % stringLength]; }

string genRandomStr(int len = rand()) {

    std::string Str;
    for (unsigned int i = 0; i < len; ++i) {
        Str += genRandom();
    }
    return Str;
}

void permute(string str, int low) {
    if (low == str.size() - 1) {
        cout << str << endl;
    } else if (low >= str.size())
        return;
    for (int i = low; i < str.size(); i++) {
        swap(str[i], str[low]);
        permute(str, low + 1);
        swap(str[i], str[low]);
    }
}

void permute(string str) {
    if (str.empty())
        return;
    permute(str, 0);
}

int main() {
    srand(time(0));

    string str = genRandomStr(rand());
    cout << "we put in " << str.length() << endl;
    permute(str);
    return 0;
}