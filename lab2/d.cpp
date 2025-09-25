#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }
    int max_freq = 0;
    for (auto &p : freq) {
        max_freq = max(max_freq, p.second);
    }
    vector<int> modes;
    for (auto &p : freq) {
        if (p.second == max_freq) {
            modes.push_back(p.first);
        }
    }
    sort(modes.rbegin(), modes.rend());
    for (int x : modes) cout << x << " ";
    cout << endl;
}