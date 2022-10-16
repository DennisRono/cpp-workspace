#include <iostream>
using namespace std;

int main() {
    int fifteen = 15;
    double fivepointnine = 5.99;
    char letter_D = 'D';
    string hello = "Hello";
    bool truthy = true;
    cout << "The number is " << fifteen << endl;
    cout << "The double is " << fivepointnine << endl;
    cout << "The letter is " <<letter_D << endl;
    cout << "The greeting is " <<hello << endl;
    cout << truthy << endl;

    const float PI = 3.14;
    cout << "The value of Pi is " << PI << endl;
    return 0;
}