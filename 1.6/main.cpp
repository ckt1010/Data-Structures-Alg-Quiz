#include <cstdlib>
#include <ctime>
#include <getRandStr.hpp>
#include <iostream>
#include <string>

using namespace std;

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

int main(int argc, char **argv) {
    string str;
    if (argc == 2) {
        str = getRandStr(atoi(argv[1]));
    } else {
        str = getRandStr();
    }

    cout << "we put in length" << str.length() << endl;
    permute(str);
    return 0;
}