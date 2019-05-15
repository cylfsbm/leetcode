#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int counter = 0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i] != ' ') counter++;
            else {
                if(counter == 0) continue;
                else return counter;
            }
        }
        return counter;
    }
};

int main(){
    Solution s;
    string ss;
    cin>>ss;
    cout<<s.lengthOfLastWord(ss)<<endl;
    system("pause");
    return 0;
}