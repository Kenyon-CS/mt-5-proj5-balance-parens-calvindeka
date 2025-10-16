#include "balance.hpp"
#include <string>

static bool is_balanced_rec(const std::string& s, int idx, int open) {
    // Base case: too many closing parentheses
    if (open < 0) return false;

    // Base case: reached the end of the string
    if (idx == s.size()) return open == 0;

    // Recursive step: check current character
    if (s[idx] == '(') {
        return is_balanced_rec(s, idx + 1, open + 1);
    } else if (s[idx] == ')') {
        return is_balanced_rec(s, idx + 1, open - 1);
    } else {
        // Ignore non-parenthesis characters
        return is_balanced_rec(s, idx + 1, open);
    }
}

bool is_balanced(const std::string& s) {
    return is_balanced_rec(s, 0, 0);
}
