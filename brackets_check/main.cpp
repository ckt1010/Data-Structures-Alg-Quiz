#include <getRandArr.hpp>
#include <iostream>
#include <stack_list.hpp>
#include <string>
using namespace std;
typedef stack_list<char> stackChar;

bool isBracketsPair(const string &s) {
    stackChar sc;
    size_t rightBracketsIndex = 0;
    const string leftBrackets = "(<[{", rightBrackets = ")>]}";
    for (auto c : s) {
        if (string::npos != leftBrackets.find(c)) {
            sc.push(c);
        } else if (string::npos != (rightBracketsIndex = rightBrackets.find(c))) {
            char rc;
            sc.pop(rc);
            if (rightBracketsIndex != leftBrackets.find(rc)) {
                cout << rc << " can't pair with " << c << ".\n";
                return false;
            }
        }
    }

    char rc = '\0';
    sc.pop(rc);
    if ('\0' == rc) {
        return true;
    } else {
        cout << rc << " have no pair bracket.\n";
        return false;
    }
}

int main() {
    stackChar s1;
    const string rightString = "{fdafadf[daf<dfdd(12434)fd>sfs]f}",
                 wrong1String = "{fdafadf[daf<dfdd(12434)fd>sfs]",
                 wrong2String = "{fdafadf[daf<dfdd(12434)fd>sfs]>";;

    cout << "check right string, and result: " << isBracketsPair(rightString) << endl;
    cout << "check wrong string, and result: " << isBracketsPair(wrong1String) << endl;
    cout << "check wrong string, and result: " << isBracketsPair(wrong2String) << endl;
    return 0;
}