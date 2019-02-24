#include <iostream>
#include <string>

using namespace std;

void transform(string &s) {
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] += 32;
    }
}

void split_to_word(string &s) {

}


int main(int argc, char const *argv[])
{
    string word;
    string p;
    getline(cin, word);
    getline(cin, p);

    transform(word);
    transform(p);

    string tmp_word;
    int total = 0;
    int flag = 0;
    int index = 0;
    for (int i = 0; i < p.length(); ++i) {
        if (p[i] != ' ')
            tmp_word+=p[i];
        if (p[i] == ' ' || i == (p.length() - 1) ) {
            if (word.compare(tmp_word) == 0) {
                total ++;
                if (flag == 0) {
                    index = i - tmp_word.length();
                    flag = 1;
                }
            }
            tmp_word.clear();
        }
    }
    if (flag == 0)
        cout << "-1" << endl;
    else 
        cout << total << " " << index << endl;
    return 0;
}