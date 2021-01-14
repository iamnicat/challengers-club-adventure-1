// https://www.hackerrank.com/challenges/bigger-is-greater/problem
#include <bits/stdc++.h>

using namespace std;

// Complete the biggerIsGreater function below.
std::string biggerIsGreater(std::string w) {
    int const sz = (int)w.size();

    for (int i = sz - 1; i > -1; --i)
        for (auto i2 = sz - 1; i2 > i; --i2)
            if (w[i] < w[i2])
            {
                using std::swap;
                swap(w[i2], w[i]);
                std::sort(&w[i] + 1, &w[0] + sz);
                return w;
            }
    return "no answer";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string w;
        getline(cin, w);

        string result = biggerIsGreater(w);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
