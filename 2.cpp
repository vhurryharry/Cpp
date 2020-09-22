#include <cstdio>
#include <cstdint>
#include <vector>
#include <numeric>

using namespace std;

vector<vector<uint32_t>> result;

void fork(int i, vector<uint32_t>& t, const uint32_t T, const vector<uint32_t>& I)
{
    int r = 0;
    if(result.size() > 0) r = accumulate(result[0].begin(), result[0].end(), 0);
    int s = accumulate(t.begin(), t.end(), 0);

    if(i == I.size() || s > T)
    {
        if(s <= T && t.size() && r <= s)
        {
            if(r < s)
                result.clear();
            result.push_back(t);
        }
        return;
    }

    vector<uint32_t> newT = t;
    newT.push_back(I[i]);
    fork(i + 1, newT, T, I);
    fork(i + 1, t, T, I);
}

void find_largest_sum(uint32_t T, const vector<uint32_t>& I, vector<uint32_t>& M, uint32_t& S)
{
    M.clear();
    fork(0, M, T, I);
    M = result[0];
    S = accumulate(M.begin(), M.end(), 0);
}

int main()
{
    uint32_t T = 11;
    vector<uint32_t> I{1, 2, 3, 4, 5, 6, 7};
    vector<uint32_t> M;
    uint32_t S;

    find_largest_sum(T, I, M, S);
    for(int i = 0; i < M.size(); i ++) {
        printf("%d ", M[i]);
    }
    printf("\n%d", S);
}