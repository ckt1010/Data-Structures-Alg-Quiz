#include <iostream>
#include <random>
#include <limits>

using namespace std;

void printFr(double in) {
    for (size_t i = 0; in > 0; i++) {
        in *= 10;
        int intPart = (int)(in);
        printf("%d", intPart);
        in -= intPart;
    }
}

void printInt(int in) {
    if (in >= 10) {
        printInt(in / 10);
    }
    printf("%u", in % 10);
}

void printDigit(double in) {
    if (in < 0) {
        cout << "-";
        in = 0 - in;
    }
    
    //fetch int part 
    int intPart = in;
    printInt(intPart);
    printf(".");

    //fetch fraction part
    double frPart = in - intPart;
    printFr(frPart);
    printf("\n");
}
int main(int argc, char *argv[]) {
    std::random_device rd;
    std::mt19937 gen(rd()); 
    std::uniform_real_distribution<> dis(-10000, 10000);
    for (int n = 0; n < 1; ++n) {
        double in = dis(gen);
        printf("we put in : %lf\n", in);//don't believe it, because double always lost precision
        printDigit(in);
    }
    return 0;
}