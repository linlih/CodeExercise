/*
 * 运行数据： ms  KB
 */
#include <bits/stdc++.h>
#include <cstdlib>
#include <functional>
using namespace std;

char *itoa_my(int value,char *string,int radix)
{
	char zm[37]="0123456789abcdefghijklmnopqrstuvwxyz";
	char aa[100]={0};
 
	int sum=value;
	char *cp=string;
	int i=0;
	
	if(radix<2||radix>36)//增加了对错误的检测
	{
		cout<<"error data!"<<endl;
		return string;
	}
 
	if(value<0)
	{
		cout<<"error data!"<<endl;
		return string;
	}
	
 
	while(sum>0)
	{
		aa[i++]=zm[sum%radix];
		sum/=radix;
	}
 
	for(int j=i-1;j>=0;j--)
	{
		*cp++=aa[j];
	}
	*cp='\0';
	return string;
}

string substract(string &a, string &b) {
    int a_ = atoi(a.c_str());
    int b_ = atoi(b.c_str());
    int res_ = a_ - b_;
    char str[10];
    itoa_my(res_, str, 10);
    string res(str);
    return res;
}

int main(int argc, char const *argv[])
{
    string num;
    cin >> num;
    while(num.size() < 4) {
        num += '0';        
    }
    string num_r(num);
    string res;
    while(res != "6174") {
        sort(num.begin(), num.end());
        sort(num_r.begin(), num_r.end(), greater<char>());
        res = substract(num_r, num);
        if (num.empty()){
            cout << "N - N = 0000" << endl;
            break;
        }
        if (res.empty()) {
            cout << num_r << " - " << num << " = " << "0000" << endl;
            break;
        }
        else 
            cout << num_r << " - " << num << " = " << res << endl;
        num = res;
        num_r = res;
    }
    return 0;
}