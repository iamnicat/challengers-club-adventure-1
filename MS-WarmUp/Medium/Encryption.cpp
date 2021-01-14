// https://www.hackerrank.com/challenges/encryption/problem?h_r=next-challenge&h_v=zen
#include <bits/stdc++.h>

using namespace std;

// Complete the encryption function below.
std::string encryption(std::string const& s) {
    auto const sz = static_cast<int>(s.size());

    int row = static_cast<int>(std::sqrt(sz));
    int col = row;
    col += (col * row < sz);
    row += (col * row < sz);

    std::string res;
    for (int i = 0; i < col; ++i)
    {
        for (int k = i; k < sz; k += col)
            res += s[k];
        res += ' ';
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
