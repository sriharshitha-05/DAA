#include <iostream>
#include <stack>
using namespace std;

int main() {
    string s;
    cin >> s;

    stack<char> st;

    for(char c : s) {

        if(c == '(' || c == '[' || c == '{')
            st.push(c);

        else {
            if(st.empty()) {
                cout << "Invalid";
                return 0;
            }

            char x = st.top();
            st.pop();

            if((c == ')' && x != '(') ||
               (c == ']' && x != '[') ||
               (c == '}' && x != '{')) {
                cout << "Invalid";
                return 0;
            }
        }
    }

    if(st.empty())
        cout << "Valid";
    else
        cout << "Invalid";

    return 0;
}
