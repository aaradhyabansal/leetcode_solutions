include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        return a.first < b.first;
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        int n = position.size();
        for (int i = 0; i < n; i++) {
            pair<int, int> temp = { position[i], speed[i] };
            cars.push_back(temp);
        }
        sort(cars.begin(), cars.end(), cmp);

        stack<float> st;

        for (auto temp : cars) {
            float time = ((target - temp.first) / (temp.second * 1.0));

            while (!st.empty() && st.top() <= time) {
                st.pop();
            }
            st.push(time);
        }

        return st.size();
    }
};

int main() {
    Solution solution;

    int target;
    cout << "Enter the target position: ";
    cin >> target;

    int n;
    cout << "Enter the number of cars: ";
    cin >> n;

    vector<int> position(n);
    vector<int> speed(n);

    cout << "Enter the position and speed of each car:\n";
    for (int i = 0; i < n; i++) {
        cin >> position[i] >> speed[i];
    }

    int fleets = solution.carFleet(target, position, speed);
    cout << "Number of Car Fleets: " << fleets << endl;

    return 0;
}
