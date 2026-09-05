#include <iostream>
using namespace std;

int main()
{
    float A;
    float B;
    float X;

    cout << "Hello! My name is Talan and welcome to my Lab 2 program! We are going to solve the problem:" << endl;
    cout << "Ax + B = 0" << endl;
    cout << "For x" << endl;
    cout << endl;

    cout << "Please enter the value of A: ";
    cin >> A;

    cout << "Please enter the value of B: ";
    cin >> B;

    cout << endl;
    cout << "Solving " << A << "x + " << B << " = 0 for x." << endl;
    cout << endl;

    X = -B / A;

    cout << "The answer is:" << endl;
    cout << "x=" << X << endl;

    return 0;
}