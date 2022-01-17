#include <iostream>
#include <stack>
using namespace std;

int* Stock_Span(int* arr,int n)
{
    int* output = new int[n];
    stack<int> s;
    for(int i=0;i<n;i++)
    {
        if(s.empty())
        {
            output[i]=i+1;
            s.push(i);
        }
        else
        {
            if(arr[i]<=arr[s.top()])
            {
                output[i]=i-s.top();
                s.push(i);
            }
            else
            {
                while(!s.empty() && arr[i]>arr[s.top()])
                {
                    s.pop();
                }
                if(s.empty())
                {
                    output[i]=i+1;
                    s.push(i);
                }
                else
                {
                    output[i]=i-s.top();
                    s.push(i);
                }
            }

        }
    }

    return output;
}

int main()
{
    int size;
    cin >> size;

    int *input = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }

    int *output = Stock_Span(input, size);
    for (int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }

    cout << "\n";

    delete[] input;
    delete[] output;
}
