//Devendra Uraon 
class Solution {
public:
    bool isToeplitzMatrix(const vector<vector<int>>& m) {
        if (m.empty()) {
            return true;
        }
        const auto n = m[0].size() - 1;
        for (auto i = 1u; i < m.size(); ++i) {
            const auto b1 = m[i - 1].begin();
            const auto b2 = m[i].begin();
            if (!equal(b1, b1 + n, b2 + 1)) {
                return false;
            }
        }
        return true;
    }
};
