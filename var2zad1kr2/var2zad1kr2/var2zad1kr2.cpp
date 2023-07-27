#include <iostream>
#include<math.h>
using namespace std;

int main(int argc, char* argv[])
{
    double a, b, h, result = 0;
    cout << "vvedite a" << endl;
    cin >> a;
    cout << "vvedite b" << endl;
    cin >> b;
    cout << "vvedite h" << endl;
    cin >> h;
    cout << "Argument     " << "F(x) = " << endl;
    while (a <= b) {
        result = 7 * pow(sin(a), 2) - 1 / 2 * cos(a);
        cout << a << "             " << result << endl;
        a += h;
    }

    system("pause");
    return 0;
}