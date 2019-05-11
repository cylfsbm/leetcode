#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string pre = "1", cur = "1";
        while(n != 1){
            pre = cur;
            cur = "";
            for(int i=0;i<pre.size();i++){
                char temp = pre[i];
                int counter = 1;
                while(pre[i+1] == temp){
                    i++;
                    counter++;
                }
                cur += (counter+48);
                cur += temp;
            }
            n--;
        }
        return cur;
    }
};

int main(){
    Solution s;
    cout<<s.countAndSay(4)<<endl;
    system("pause");
    return 0;
}
