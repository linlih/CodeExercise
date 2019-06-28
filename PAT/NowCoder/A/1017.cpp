    /*
    * 运行数据： ms  KB
    */
    #include <bits/stdc++.h>

    using namespace std;
    int main(int argc, char const *argv[])
    {
        int num;
        char symbol;
        cin >> num >> symbol;

        if (num < 1)
            return -1;
        else if (num == 1) {
            cout << symbol << endl;
            cout << "0" << endl;
            return 0;
        }

        int level_node = 1;
        num -= 1;
        while (num >= 0) {
            level_node += 2;
            num -= (level_node * 2);
        }
        int max_node = level_node - 2; // 上面的循环中多加了一次2，最大层数的符号数要再减去2
        int left_node = num + (level_node * 2); // 剩余的节点数
        
        int tmp_node = max_node;
        int out_space = 0;
        while (tmp_node >=0) {
            for (int j = 0; j < out_space; ++j)
                cout << " ";
            for (int i = 0; i < tmp_node; ++i) 
                cout << symbol;
            cout << endl;
            out_space++;
            tmp_node -= 2;
        }
        tmp_node = 3;
        out_space -= 2;
        while (tmp_node <= max_node) {
            for (int j = 0; j < out_space; ++j)
                    cout << " ";
            for (int i = 0; i < tmp_node; ++i) 
                cout << symbol;
            cout << endl;
            out_space--;
            tmp_node += 2; 
        }

        cout << left_node << endl;
        return 0;
    }