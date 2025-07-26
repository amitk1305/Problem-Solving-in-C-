class Solution {
private:
    static constexpr uint MAXN = 100'000;

    static uint leftconf[MAXN][2];
    static uint64_t inc[MAXN];

    static void ins(const uint v, uint &a, uint &b) {
        // inserting v into descending-sorted list [a, b] excluding the bottom element
        const uint in = -(v > b), top = -(v > a), mid = in & ~top;
        b = (a & top) + (v & mid) + (b & ~in);
        a = (v & top) + (a & ~top);
    }

public:
    static long long maxSubarrays(const uint n, const vector<vector<int>> &conflictingPairs) {
        for (const auto &p : conflictingPairs) {
            const uint p0 = p[0], p1 = p[1];
            const auto lc = leftconf[max(p0, p1) - 1];
            ins(min(p0, p1), lc[0], lc[1]);
        }

        uint64_t res = 0, maxi = 0;
        uint lf = 0, ls = 0;
        for (uint r = 1; r <= n; r++) {
            const auto lc = leftconf[r-1];
            ins(lc[0], lf, ls);
            ins(lc[1], lf, ls);
            res += r - lf;
            const auto i = inc[lf] += lf - ls;
            maxi = max(i, maxi);
            lc[1] = lc[0] = 0;
        }

        fill_n(inc, n, 0);
        return res + maxi;
    }
};

uint Solution::leftconf[MAXN][2];
uint64_t Solution::inc[MAXN];