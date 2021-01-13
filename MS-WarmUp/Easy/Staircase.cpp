#include <bits/stdc++.h>

using namespace std;

// Complete the staircase function below.
void staircase(int const n) {
    for (int i = 0; i < n; ++i) {
        int j = 0;
        for (; j < n - i - 1; ++j)
            putchar(' ');
        for (; j < n; ++j)
            putchar('#');
        putchar('\n');
    }
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    staircase(n);

    return 0;
}
