#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

uint32_t Fibonacci(uint32_t num) {
    uint32_t retFirst = 0, retSecond = 1;
    for (size_t i = 0; i < num; i++)
    {
        uint32_t tmp = retFirst;
        retFirst = retFirst + retSecond;
        retSecond = tmp;
    }
    return retFirst;
}

int main() {
    uint32_t N = 0, result = 0;
    cout << "enter Fibonacci No:\n";
    cin >> N;

    result = Fibonacci(N);
    cout << "result: " << result << endl;
    return 0;
}