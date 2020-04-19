class Solution {
public:
    bool checkValidString(string s) {
        string s1, s2, s3;
        s1 = s2 = s3 = s;
        auto it = s.find('*');
        if (it != s.end()) {
            s1.erase(it, it+1);
            s2.replace(it, it+1, "(");
            s3.replace(it, it+1, ")");
        }
        stack<char> st;
        stack<char> empty;
        for (int i = 0; i < s.size(); i++) {
            if (s1[i] == '(') st.push('(');
            else if (s1[i] == ')') st.pop();
        }
        if (st.size() == 0) return true;
        swap(st, empty);
        for (int i = 0; i < s.size(); i++) {
            if (s2[i] == '(') st.push('(');
            else if (s2[i] == ')') st.pop();
        }
        if (st.size() == 0) return true;
        swap(st, empty);
        for (int i = 0; i < s.size(); i++) {
            if (s3[i] == '(') st.push('(');
            else if (s3[i] == ')') st.pop();
        }
        if (st.size() == 0) return true;
        else return false;
    }
};