#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>

typedef long long ll;

const int sqrtN = 316;
std::vector<int> A, ar, ids, cnt(101010), bucket(333);
int cnt2[333][101010];
std::unordered_map<int, int> id_map;

struct Query {
    int l, r, idx;
};

bool cmp(const Query& a, const Query& b) {
    if (a.l / sqrtN != b.l / sqrtN)
        return a.l / sqrtN < b.l / sqrtN;
    return a.r < b.r;
}

int get(int id) {
    if (id_map.find(id) == id_map.end()) {
        id_map[id] = std::lower_bound(ids.begin(), ids.end(), id) - ids.begin();
    }
    return id_map[id];
}

int l, r;

void offset(int x, int y) {
    while (r < y) {
        r++;
        int idx = A[r];
        int idx2 = idx / sqrtN;
        cnt2[idx2][cnt[idx]]--;
        cnt[idx]++;
        cnt2[idx2][cnt[idx]]++;
        bucket[idx2] = std::max(bucket[idx2], cnt[idx]);
    }
    while (l > x) {
        l--;
        int idx = A[l];
        int idx2 = idx / sqrtN;
        cnt2[idx2][cnt[idx]]--;
        cnt[idx]++;
        cnt2[idx2][cnt[idx]]++;
        bucket[idx2] = std::max(bucket[idx2], cnt[idx]);
    }

    while (r > y) {
        int idx = A[r];
        int idx2 = idx / sqrtN;
        cnt2[idx2][cnt[idx]]--;
        cnt[idx]--;
        cnt2[idx2][cnt[idx]]++;
        if (cnt2[idx2][bucket[idx2]] == 0) {
            bucket[idx2] = cnt[idx];
        }
        r--;
    }
    while (l < x) {
        int idx = A[l];
        int idx2 = idx / sqrtN;
        cnt2[idx2][cnt[idx]]--;
        cnt[idx]--;
        cnt2[idx2][cnt[idx]]++;
        if (cnt2[idx2][bucket[idx2]] == 0) {
            bucket[idx2] = cnt[idx];
        }
        l++;
    }
}

int get_ans(int maxN) {
    int idx = -1;
    int max = -1;

    for (int i = 0; i < maxN; i += sqrtN) {
        if (bucket[i / sqrtN] >= max) {
            max = bucket[i / sqrtN];
            idx = i;
        }
    }

    max = -1;
    int ans = 0;
    for (int i = idx; i < idx + sqrtN; i++) {
        if (cnt[i] >= max) {
            max = cnt[i];
            ans = i;
        }
    }

    return ans;
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N, Q;
    std::cin >> N >> Q;

    A.resize(N);
    ar.resize(N);
    for (int i = 0; i < N; i++) {
        std::cin >> ar[i];
        ids.push_back(ar[i]);
    }
    std::sort(ids.begin(), ids.end());
    ids.erase(std::unique(ids.begin(), ids.end()), ids.end());

    for (int i = 0; i < N; i++) {
        A[i] = get(ar[i]);
    }

    std::vector<Query> queries;
    std::vector<int> ans(Q);

    for (int i = 0; i < Q; i++) {
        int l, r;
        std::cin >> l >> r;
        queries.push_back({ l, r, i });
    }

    std::sort(queries.begin(), queries.end(), cmp);

    r = -1;

    for (Query q : queries) {
        offset(q.l - 1, q.r - 1);
        ans[q.idx] = get_ans(N + 1);
    }

    for (int i = 0; i < Q; i++)
        std::cout << ids[ans[i]] << '\n';

    return 0;
}
