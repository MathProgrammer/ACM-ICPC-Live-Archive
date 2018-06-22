#include <cstdio>
#include <vector>

using namespace std;

void precompute(vector <long long> &good_permutations, int N, int mod)
{
    good_permutations[0] = 1;
    good_permutations[1] = 1;

    for(int i = 2; i < N; i++)
    {
        good_permutations[i] = (i - 1)*good_permutations[i - 1] + (i - 2)*good_permutations[i - 2];
        good_permutations[i] %= mod;
    }
}

int main()
{
    const int MAX_N = 1e6 + 15, MOD = 1e9 + 7;
    vector <long long> good_permutations(MAX_N + 1);
    precompute(good_permutations, MAX_N, MOD);

    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    for(int i = 1; i <= no_of_test_cases; i++)
    {
        int n;
        scanf("%d", &n);
        printf("Case %d: %lld\n", i, good_permutations[n]);
    }

    return 0;
}
