class Solution {
    static constexpr uint8_t ENTER = 0;
    static constexpr uint8_t EXIT = 1;

    struct Frame {
        int node;
        int above;
        uint8_t stage;
    };

public:
    vector<int> findSubtreeSizes(const vector<int>& parent, const string& s) {
        const int n = static_cast<int>(parent.size());
        vector<int> first_child(n, -1), next_sibling(n, -1);
        for (int x = n - 1; x > 0; --x) {
            const int p = parent[x];
            next_sibling[x] = first_child[p];
            first_child[p] = x;
        }

        vector<int> size(n, 1);
        int last[26];
        fill_n(last, 26, -1);

        vector<Frame> stack;
        stack.reserve(2 * n);
        stack.push_back({0, -1, ENTER});

        while (!stack.empty()) {
            const auto [x, above, stage] = stack.back();
            stack.pop_back();

            if (stage == ENTER) {
                const int c = s[x] - 'a';
                const int prev_last = last[c];
                int child = first_child[x];

                if (child == -1) {
                    if (x) {
                        const int dest = prev_last >= 0 ? prev_last : parent[x];
                        size[dest] += 1;
                    }
                    continue;
                }

                stack.push_back({x, prev_last, EXIT});
                last[c] = x;
                while (child != -1) {
                    stack.push_back({child, -1, ENTER});
                    child = next_sibling[child];
                }
            } else {
                const int c = s[x] - 'a';
                last[c] = above;
                if (x) {
                    const int dest = above >= 0 ? above : parent[x];
                    size[dest] += size[x];
                }
            }
        }

        return size;
    }
};