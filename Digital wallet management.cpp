#include <bits/stdc++.h>
using namespace std;
int main() 
{
    int N;
    cin >> N;
    vector<pair<int, int>> users(N);
    for (int i = 0; i < N; i++) {
        int ID, balance;
        cin >> ID >> balance;
        users[i] = {ID, balance};
    }
    int T;
    cin >> T;
    for (int j = 0; j < T; j++) {
        int fID, tID, amount;
        cin >> fID >> tID >> amount;
        int from_index = -1, to_index = -1;
        for (int i = 0; i < N; i++) {
            if (users[i].first == fID) {
                from_index = i;
            }
            if (users[i].first == tID) {
                to_index = i;
            }
        }
        if (from_index != -1 && to_index != -1 && users[from_index].second >= amount) {
            users[from_index].second -= amount;
            users[to_index].second += amount;
            cout << "Success" << endl;
        } else {
            cout << "Failure" << endl;
        }
    }
    sort(users.begin(), users.end(), [](pair<int, int> &a, pair<int, int> &b) {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second < b.second;
    });
    cout<<endl;
    for (auto &user : users) {
        cout << user.first << " " << user.second << endl;
    }
    return 0;
}
