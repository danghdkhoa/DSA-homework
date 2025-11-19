
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
#define MAX 300
#include <stack>

string StringReverse(string &s) {
    stack<string> t_stack;
    for (int i = 0; i < s.length(); i++) {
        string cur_tok = "";
        if (s[i] == ' ') {
            while (i < s.length() && s[i] == ' ') {
                cur_tok += s[i];
                i++;
            }
        } else {
            while (i < s.length() && s[i] != ' ') {
                cur_tok += s[i];
                i++;
            }
        }
        i--;
        t_stack.push(cur_tok);
    }
    string r_s = "";
    while (t_stack.empty() == false) {
        r_s += t_stack.top();
        t_stack.pop();
    }
    s = r_s;
    return s;
}


int main () {
    string s;

    getline(std::cin, s);	//Nhap chuoi s

    if(s.empty() == true)
        cout << "Chuoi rong." << endl;
    else {
        StringReverse(s);
        cout << s << endl;

    }

    return 0;
}
