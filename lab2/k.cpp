#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        queue<char> q;
        map<char, int> m;
        for (int i = 0; i < n; i++) {
            char a;
            cin >> a;
            m[a]++;
            q.push(a);
            while (!q.empty() && m[q.front()] > 1) {
                q.pop();
            }
            if (q.empty())
                cout << -1 << ' ';
            else
                cout << q.front() << ' ';
        }
        cout << endl;
    }
}