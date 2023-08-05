#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void checkLeftPos(stack<char>& st, int& cnt) {
        while (st.top() == 'S' && st.size() != 1) {
            char cho = st.top();
            st.pop();
            if (cho == 'S' && st.top() == 'R') {
                cnt++;
                st.pop();
                st.push('S');
            }
        }
    }

    int countCollisions(string directions) {
        stack<char> st;
        int cnt = 0;

        for (auto ch : directions) {
            if (ch == 'R') {
                st.push(ch);
            }
            else if (ch == 'S' && st.empty()) {
                st.push(ch);
            }
            else {
                if (!st.empty()) {
                    if (ch == 'S' && st.top() == 'R') {
                        cnt++;
                        st.pop();
                        st.push('S');
                        checkLeftPos(st, cnt);
                    }
                    else if (ch == 'L' && st.top() == 'R') {
                        cnt += 2;
                        st.pop();
                        st.push('S');
                        checkLeftPos(st, cnt);
                    }
                    else if (ch == 'L' && st.top() == 'S') {
                        cnt++;
                        st.pop();
                        st.push('S');
                    }
                }
            }
        }

        return cnt;
    }
};

int main() {
    Solution solution;
    string directions;

    cout << "Enter the directions: ";
    cin >> directions;

    int collisions = solution.countCollisions(directions);
    cout << "Number of Collisions: " << collisions << endl;

    return 0;
}
