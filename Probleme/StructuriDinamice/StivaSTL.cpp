#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> numbers;
    int x;
    do
    {
        cout << "Number=";
        cin >> x;
        numbers.push(x);
    } while (x != 0);
    int p = 1;
    while (!numbers.empty())
    {
        cout << numbers.top() << endl;
        if (numbers.top() < 0)
        {
            p *= numbers.top();
        }
        // trebuie sa facem pop mereu, pentru ca stiva nu se va modifica si va fi ciclu infinit
        numbers.pop();
    }
    cout << "Product of negative elements : " << p;
    return 0;
}