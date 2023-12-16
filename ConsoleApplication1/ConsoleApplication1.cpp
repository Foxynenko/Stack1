#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

bool isValid(string s) {
    stack<char> stk;
    unordered_map<char, char> mapping = { {')', '('}, {']', '['}, {'}', '{'} };

    for (char c : s) {
        if (mapping.find(c) != mapping.end()) {
            char topElement = stk.empty() ? '#' : stk.top();
            stk.pop();

            if (topElement != mapping[c]) {
                return false;
            }
        }
        else {
            stk.push(c);
        }
    }

    return stk.empty();
}

int main() {
    // Приклад 1
    string s1 = "(";
    cout << s1 << endl;
    cout << "Example 1: " << (isValid(s1) ? "true" : "false") << endl;

    // Приклад 2
    string s2 = "()[]{}";
    cout << s2 << endl;
    cout << "Example 2: " << (isValid(s2) ? "true" : "false") << endl;

    // Приклад 3
    string s3 = "(]";
    cout << s3 << endl;
    cout << "Example 3: " << (isValid(s3) ? "true" : "false") << endl;

    return 0;
}
