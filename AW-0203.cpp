#include <iostream>
#include <vector>
using namespace std;

vector<int> ex_gcd(int a, int b) {
    if (b == 0) {
        return vector<int>{1, 0, a};
    }

    vector<int> res = ex_gcd(b, a % b);
    int x = res[0], y = res[1];
    res[0] = y;
    res[1] = x - a / b * y;

    return res;
}

int main() {
    int a, b;
    cin >> a >> b;
    
    vector<int> res = ex_gcd(a, b);
    int x = res[0];
    while (x < 0) {
        x += b;
    }

    cout << x << endl;
}