#include<iostream>
// #include<map>
#include<string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        while(num != 0){
            if(num >= 1000){
                num -= 1000;
                res.append("M");
            }else if(num >= 900){
                num -= 900;
                res.append("CM");
            }else if(num >= 500){
                num -= 500;
                res.append("D");
            }else if(num >= 400){
                num -= 400;
                res.append("CD");
            }else if(num >= 100){
                num -= 100;
                res.append("C");
            }else if(num >= 90){
                num -= 90;
                res.append("XC");
            }else if(num >= 50){
                num -= 50;
                res.append("L");
            }else if(num >= 40){
                num -= 40;
                res.append("XL");
            }else if(num >= 10){
                num -= 10;
                res.append("X");
            }else if(num >= 9){
                num -= 9;
                res.append("IX");
            }else if(num >= 5){
                num -= 5;
                res.append("V");
            }else if(num >= 4){
                num -= 4;
                res.append("IV");
            }else{
                num -= 1;
                res.append("I");
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    int i;
    cout<<"please input the integer:";
    cin>>i;
    cout<< s.intToRoman(i)<<endl;
    return 0;
}