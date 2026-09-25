class Solution {
public:
    string s;
    int idx = 0;

    set<string> parseExpr() {
        set<string> result = parseTerm();
        while (idx < s.size() && s[idx] == ',') {
            idx++; // skip ','
            set<string> term = parseTerm();
            result.insert(term.begin(), term.end());
        }
        return result;
    }

    set<string> parseTerm() {
        vector<set<string>> factors;
        while (idx < s.size() && s[idx] != ',' && s[idx] != '}') {
            factors.push_back(parseFactor());
        }
        set<string> result = {""};
        for (auto& f : factors) {
            set<string> merged;
            for (auto& prefix : result)
                for (auto& suf : f)
                    merged.insert(prefix + suf);
            result = merged;
        }
        return result;
    }

    set<string> parseFactor() {
        if (s[idx] == '{') {
            idx++; // skip '{'
            set<string> res = parseExpr();
            idx++; // skip '}'
            return res;
        }
        string literal;
        while (idx < s.size() && isalpha(s[idx])) {
            literal += s[idx++];
        }
        return {literal};
    }

    vector<string> braceExpansionII(string expression) {
        s = expression;
        idx = 0;
        set<string> result = parseExpr();
        return vector<string>(result.begin(), result.end());
    }
};