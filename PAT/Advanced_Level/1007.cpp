/*
   问题描述：
   解题思路： 
 */
  > Modified Time: 2021.03.31 19:22

using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    int leftindex = 0, rightindex = n-1, sum = -1, temp = 0, tempindex = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
        temp = temp + v[i];
        if (temp < 0) {
            temp = 0; 
            tempindex = i + 1;
        }
        else if (temp > sum) {
            sum = temp;
            leftindex = tempindex;
            rightindex = i;
        }
    } 
    if (sum < 0) sum = 0;
    cout << sum << " " << v[leftindex] << " " << v[rightindex] << endl;
    return 0;
}
