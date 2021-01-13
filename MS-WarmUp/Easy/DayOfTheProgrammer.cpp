#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

enum CalendarType { Julian, Gregorian };

constexpr bool is_leap(int const year, CalendarType const type) noexcept {
    if (year%4) return false;
    if (type == Julian) return true;
    return year % 100 || !(year%400);
}
// Complete the dayOfProgrammer function below.
string dayOfProgrammer(int year) {
    std::string buff("26.09.1918");
    if (year == 1918)
        return buff;
    bool leap = is_leap(year, year<1918?Julian:Gregorian);
    sprintf(&buff[0], "%d.09.%04d", leap?12:13, year);
    return buff;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string year_temp;
    getline(cin, year_temp);

    int year = stoi(ltrim(rtrim(year_temp)));

    string result = dayOfProgrammer(year);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
