      for (int i = m + 1; i <=n; i++) {
            int2bit(i, tmp2);
            for (int j = 0; j < 20; j++) {
                if (tmp1[j] == 1 && tmp2[j] == 1)
                    tmp1[j] = 1;
                else
                    tmp1[j] = 0;
                cout << (int)tmp2[j] << endl;
                tmp2[j] = 0;
            }
        }
        int res = 0;
        int index = 1;
        for (int i = 0; i < 20; i++) {
            res = tmp1[i]*index;
            index *= 10;
        }
        return res;