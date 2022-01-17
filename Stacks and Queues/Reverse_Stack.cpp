#include <iostream>
#include <stack>
using namespace std;

void Reverse_Stack(stack<int> &input, stack<int> &extra)
{
    int n = input.size();
    if(n<=1)
    {
        return;
    }
    int top_most = input.top();
    input.pop();
    Reverse_Stack(input,extra);
    while(!input.empty())
    {
        int temp = input.top();
        input.pop();
        extra.push(temp);
    }
    input.push(top_most);
    while(!extra.empty())
    {
        int temp = extra.top();
        extra.pop();
        input.push(temp);
    }
}

int main() {
    stack<int> input, extra;
    int size;
    cin >> size;

    for (int i = 0, val; i < size; i++) {
        cin >> val;
        input.push(val);
    }

    Reverse_Stack(input, extra);

    while (!input.empty()) {
        cout << input.top() << " ";
        input.pop();
    }
  
}
