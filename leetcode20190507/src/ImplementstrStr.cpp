#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        // if(haystack == NULL || needle == NULL) return -1;
        if(needle.size() == 0) return 0;
        int np = 0, res = -1;
        for(int i=0;i<haystack.size();i++){
            if(needle[np] == haystack[i]){
                np++;
                if(np == 1) res = i;
                if(np == needle.size()) return res;
            }else{
                if(np != 0) i = res;
                np = 0;
                res = -1;
            }
        }
        return -1;
    }
};

int main(){
    Solution s;
    cout<<s.strStr("aaaaa","bba")<<endl;
    system("pause");
    return 0;
}