
#include <cstdio>
#include <iostream>
using namespace std;

/*
* 说明，这个代码只适用于图像中只包含了一个矩阵块的情况
* 2713这个题目没有明确说明只有一个矩形区域，这个代码可以通过的话，说明就是只有一个
* 如果图像中包含有几个矩阵区域的情况，就会比较负责了，需要再考虑
*/

int main()
{
    int i, j, n, p, sx, sy, tx, ty, x, y;
    cin >> n;
    sx = sy = n; // 标记矩阵右下角
    tx = ty = 0; // 标记矩阵左上角
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            cin >> p;
            if (p == 0) {
                if (i + j < sx + sy) {
                    sx = i;
                    sy = j;
                }
                if (i + j > tx + ty) {
                    tx = i;
                    ty = j;
                }
            }
        }
    }
    x = tx - sx + 1;
    y = ty - sy + 1;
    x -= 2;
    y -= 2;
    cout << x * y << endl;
    return 0;
}