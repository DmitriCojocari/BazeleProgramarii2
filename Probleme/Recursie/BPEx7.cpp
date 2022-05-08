#include <iostream>
#include <cmath>

using namespace std;

// Recursive function to
// print factors of a number
int factors(int n, int i)
{
    if (i > n / 2)
        return 0;
    else if (n % i == 0 && i % 2 == 1)
        return 1 + factors(n, i + 1);
    else
        return factors(n, i + 1);
}

// Driver code
int main()
{
    int N = 100;
    cout << factors(N, 1);
}