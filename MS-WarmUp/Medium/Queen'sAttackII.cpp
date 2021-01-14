// https://www.hackerrank.com/challenges/queens-attack-2/problem

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

struct Point {
    Point(int _x, int _y) : x{ _x }, y{ _y }{}
    Point(std::vector<int> const& vec) : Point(vec[0], vec[1])
    {
        assert(vec.size() == 2);
    }
    int x, y;
    bool operator==(Point const& other) const noexcept {
        return x == other.x && y == other.y;
    }
};

struct hash_point
{
    size_t n{};
    size_t operator()(Point const& point) const noexcept {
        return point.x + point.y * n;
    }
};

// Complete the queensAttack function below.
int queensAttack(int n, int k, int r_q, int c_q, std::vector<std::vector<int>> obstacles) {
    Point const q{ r_q, c_q };

    std::unordered_set<Point, hash_point> board(0, hash_point{ (size_t)n });
    // add new obstacles
    for (int i = 0; i <= n + 1; ++i)
    {
        board.insert({ 0, i });
        board.insert({ n + 1, i });
    }
    for (int i = 1; i < n + 1; ++i)
    {
        board.insert({ i, n + 1 });
        board.insert({ i, 0 });
    }

    for (auto const& p : obstacles)
    {
        board.insert(p);
    }

    int total{};

    auto move = [&q, &board, &total](auto tranformation) {
        auto p = q;
        while (true) {
            tranformation(p);
            if (board.find(p) != board.end())
                break;
            ++total;
        }
    };

    move([](Point& p) { ++p.x; });
    move([](Point& p) { --p.x; });
    move([](Point& p) { ++p.y; });
    move([](Point& p) { --p.y; });

    move([](Point& p) { ++p.x; ++p.y; });
    move([](Point& p) { ++p.x; --p.y; });

    move([](Point& p) { --p.x; ++p.y; });
    move([](Point& p) { --p.x; --p.y; });


    return total;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string r_qC_q_temp;
    getline(cin, r_qC_q_temp);

    vector<string> r_qC_q = split_string(r_qC_q_temp);

    int r_q = stoi(r_qC_q[0]);

    int c_q = stoi(r_qC_q[1]);

    vector<vector<int>> obstacles(k);
    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> obstacles[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
