/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

/*
在入栈时，如果这个元素比最小值小，那么，我们让最小值入栈，然后将元素值赋给最小值，即新的最小值，然后正常将这个元素入栈；在出栈时，如果栈顶元素与最小值相等，说明他的下一个元素是之前push的最小值（上一个），出栈后，将这个之前的最小值赋值给最新的最小值。（每次push进去的最小值都是下面元素的最小值）
*/
// reference: https://blog.csdn.net/qq_33736809/article/details/79503655
class MinStack {
private:
    int min;
    stack<int> minstack;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if (minstack.empty()) {
            minstack.push(x);
            min = x;
        }
        else {
            // 小于等于的话多一次压入第二小的值，因为这次压入的是最小值
            // 为的是在pop的时候能够得到第二小的值
            if (x <= min) {
                minstack.push(min);
                min = x;
            }
            minstack.push(x);
        }
    }
    
    void pop() {
        if (minstack.empty()) return;
        int index = this->top();
        minstack.pop();
        if (min == index && !minstack.empty()) {
            min = this->top();
            minstack.pop();
        }
    }
    
    int top() {
        return minstack.top();        
    }
    
    int getMin() {
        return min;
    }
};


class MinStack_1 {
public:
    stack<pair<int, int>> nums;
    MinStack() {}
    
    void push(int x) {
        int min;
        if (nums.empty())
            min = x;
        else 
            min = std::min(x, nums.top().second);
        nums.push({x, min});
    }

    void pop() {
        nums.pop();
    }

    int top() {
        return nums.top().first;
    }

    int getMin() {
        return nums.top().second;
    }
};

// 这个代码跑了12ms，但是看实现浪费了大量的空间，不值得推荐
class MinStack_Best {
public:
    MinStack() {
        CurrentMin = INT_MAX;
    }

    void push(int x) {
        if (LastElementIndex > 0)
            CurrentMin = std::min(x, MinData[lastElementIndex - 1]);
        else 
            CurrentMin = x;
        MinData[LastElementIndex] = CurrentMin;
        ValueData[LastElemntIndex] = x;
        LastElementIndex++;
    }

    void pop() {
        LastElementIndex--;
    }

    int top() {
        return ValueData[LastElementIndex-1];
    }

    int getMin() {
        return MinData[LastElementIndex-1];
    }
private:
    int CurrentMin;
    int MinData[10000];
    int ValueData[10000];
    int LastElementIndex;
};

auto speedup=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(int argc, char const *argv[]) {
    MinStack minStack;

    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    
    cout << minStack.getMin() << endl;
    minStack.pop();
    
    cout << minStack.top() << endl;      
    cout << minStack.getMin() << endl;   

    return 0;
}