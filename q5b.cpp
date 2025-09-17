#include <iostream>
#include <queue>
using namespace std;

class StackUsingOneQueue {
    queue<int> q;

public:
    void push(int x) {
        q.push(x);
        int size = q.size();
        for (int i = 0; i < size - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (!q.empty())
            q.pop();
    }

    int top() {
        if (q.empty())
            return -1;
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    StackUsingOneQueue s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.top() << endl;
    s.pop();

    cout << s.top() << endl;
    s.pop();

    s.push(40);
    cout << s.top() << endl;

    return 0;
}
