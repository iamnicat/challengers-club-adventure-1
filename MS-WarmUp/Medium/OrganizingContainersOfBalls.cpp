// https://www.hackerrank.com/challenges/organizing-containers-of-balls/problem
#include <bits/stdc++.h>

using namespace std;

// Complete the organizingContainers function below.
char const* organizingContainers(std::vector<std::vector<int>> const& container) {
    auto const clr_cnt = container.size();
    std::unordered_multiset<int> container_sizes;
    container_sizes.reserve(clr_cnt);
    
    for (auto const& c : container)
        container_sizes.insert(std::accumulate(c.begin(), c.end(), 0));

    for (int i = 0; i < clr_cnt; ++i)
    {
        int cnt{};
        for (int j = 0; j < clr_cnt; ++j)
        {
            cnt += container[j][i];
        }
        auto const curr_clr_container = container_sizes.find(cnt);
        if (curr_clr_container == container_sizes.end())
            return "Impossible";
        container_sizes.erase(curr_clr_container);
    }

    return "Possible";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> container(n);
        for (int i = 0; i < n; i++) {
            container[i].resize(n);

            for (int j = 0; j < n; j++) {
                cin >> container[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        string result = organizingContainers(container);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
