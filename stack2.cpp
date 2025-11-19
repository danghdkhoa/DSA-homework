#include <iostream>
#include <stack>
using namespace std;

void decimal_to_binary(int n) {
    if (n == 0) {
        cout << 0;
        return;
    }
    int bit;
    stack<int> bit_stack;
    while (n > 0) {
        bit = n % 2;
        n /= 2;
        bit_stack.push(bit);
    }
    while (bit_stack.empty() == false) {
        cout << bit_stack.top();
        bit_stack.pop();
    }
}
int main() {
    int n;
    cin >> n;
    decimal_to_binary(n);
    return 0;
}
