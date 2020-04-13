int  num;
    cin >> num;
    int tmp2 = -1;
    int tmp = num;
    int single;
    int res = 0;
    while (tmp2 != num) {
        while (tmp != 0) {
            single = tmp % 10;
            res += single * single;
            tmp = tmp / 10;
        }
        tmp2 = res;
        tmp = res;
        res = 0;
        if (tmp2 == 1) break;
    }
    if (tmp2 == 1) cout << "true" << endl;
    else cout << "false" << endl;