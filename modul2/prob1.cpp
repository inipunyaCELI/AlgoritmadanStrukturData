#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;

    stack<int> st;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        if (isdigit(s[0]) || (s.size() > 1)) {
            st.push(stoi(s));
        } else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();

            if (s == "+") st.push(a + b);
            else if (s == "-") st.push(a - b);
            else if (s == "*") st.push(a * b);
            else if (s == "/") st.push(a / b);
        }
    }

    cout << st.top();
}
