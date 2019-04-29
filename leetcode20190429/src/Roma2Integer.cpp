#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int count = 0;
        int res = 0;
        while(count < s.size()){
            char c = s[count];
            // cout<<c<<","<<count<<endl;
            if(c == 'I'){
                if((count+1) < s.size()){
                    switch(s[count+1]){
                        case 'V': res += 4;count += 2;break;
                        case 'X': res += 9;count += 2;break;
                        default: res += 1;count++;break;
                    }
                }else{
                    res += 1;
                    count++;
                }
            }else if(c == 'X'){
                if((count+1) < s.size()){
                    switch(s[count+1]){
                        case 'L': res += 40;count += 2;break;
                        case 'C': res += 90;count += 2;break;
                        default: res += 10;count++;break;
                    }    
                }else{
                    res += 10;
                    count++;
                }
            }else if(c == 'C'){
                if((count+1) < s.size()){
                    switch(s[count+1]){
                        case 'D': res += 400;count += 2;break;
                        case 'M': res += 900;count += 2;break;
                        default: res += 100;count++;break;
                    }   
                }else{
                    res += 100;
                    count++;
                }
            }else{
                switch(c){
                    case 'V':res += 5;count++;break;
                    case 'L':res += 50;count++;break;
                    case 'D':res += 500;count++;break;
                    case 'M':res += 1000;count++;break;
                    default:break;
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    string roma;
    cout<<"please input the roma string:";
    getline(cin, roma);
    // cout<<"roma:"<<roma<<endl;
    cout<<s.romanToInt(roma)<<endl;
    // cout<<"roma:"<<roma<<endl;
    system("pause");
    // cin.getchar();
}