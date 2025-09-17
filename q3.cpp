#include<iostream>
#include<queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    queue<int> q1, q2;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(i < n/2) {
            q1.push(x);
        } else {
            q2.push(x);
        }
    }

    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) {
            if (!q1.empty()) {
                int a = q1.front();
                q1.pop();
                cout << a << endl;
            }
        } else {
            if (!q2.empty()) {
                int a = q2.front();
                q2.pop();
                cout << a << endl;
            }
        }
    }

    return 0;
}
