#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void Reverse_queue(queue<int>& q)
{
    stack<int> s;
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        s.push(temp);
    }
    while(!s.empty())
    {
        int temp = s.top();
        s.pop();
        q.push(temp);
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        queue<int> q;
        int size;
        cin >> size;

        for (int i = 0, val; i < size; i++) {
            cin >> val;
            q.push(val);
        }

        Reverse_queue(q);
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }

        cout << "\n";
    }
}
