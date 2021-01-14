#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'nonDivisibleSubset' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY s
 */

#define NDEBUG

#ifndef NDEBUG
#define LOG(x) std::cout << (x) << '\n'
#else
#define LOG(x) ((void)0)
#endif


int nonDivisibleSubset(int const& k, std::vector<int> const& s) {
    LOG(s);
    // Hash map of { reminder : count }
    std::unordered_map<int, int> sets;
    sets.reserve(s.size());
    for (auto& elm : s)
        ++sets[elm % k];

    LOG(sets);

    // reminders of 0 and k/2 invalidate each ohter, so we only take 1 of each.
    int zero_and_half = 0;
    { // remove all but one of 
        auto it = sets.find(0);
        if (it != sets.end()) {
            ++zero_and_half;
            sets.erase(it);
        }

        if (k % 2 == 0 && (it = sets.find(k / 2)) != sets.end()) {
            ++zero_and_half;
            sets.erase(it);
        }
    }

    LOG(sets);

    using Pair = decltype(sets)::value_type;

    // Get the number of elements this one invalidates (makes evenly divisible by k).
    auto invalee_cnt = [k, &sets](Pair const& p) noexcept {
        auto invalee_it = sets.find(k - p.first);
        return  invalee_it == sets.end() ? 0 : invalee_it->second;
    };

    // Figure out who invalidates the most elements (as defined above).
    auto cmp = [invalee_cnt](Pair const& p1, Pair const& p2) noexcept {
        return invalee_cnt(p1) < invalee_cnt(p2);
    };

    // Remove elements that invalidates others the most until 
    // no element invalidates each other
    while (!sets.empty()) {
        auto const mx = std::max_element(sets.begin(), sets.end(), cmp);
        LOG(*mx);
        if (!invalee_cnt(*mx)) break;
        sets.erase(mx);
        LOG(sets);
    }

    // Add all the remaing counts to zero_and_half
    return std::accumulate(sets.begin(), sets.end(), 
        zero_and_half, [](int a, Pair const& p) { return a + p.second; });
}



int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string s_temp_temp;
    getline(cin, s_temp_temp);

    vector<string> s_temp = split(rtrim(s_temp_temp));

    vector<int> s(n);

    for (int i = 0; i < n; i++) {
        int s_item = stoi(s_temp[i]);

        s[i] = s_item;
    }

    int result = nonDivisibleSubset(k, s);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
