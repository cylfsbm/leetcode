#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        int size = num1.size() + num2.size();
        int* result = new int[size]{0};
        for(int i=num1.size()-1;i>=0;i--){
            int a = (num1[i]-48);
            for(int j=num2.size()-1;j>=0;j--){
                int b = (num2[j]-48);
                int r = (a * b) % 10, c = (result[i+j+1] + a * b) / 10;
                result[i+j+1] += r;
                result[i+j+1] %= 10;
                result[i+j] += c;
            }
        }
        string res = "";
        bool flag = true;
        for(int i=0;i<size;i++){
            if(result[i] == 0 && flag) continue;
            if(result[i] != 0 && flag == true) {
                flag = false;
            }
            res += (result[i]+48);
        }
        return res;
    }
};

int main(){
    Solution s;
    string num1 = "", num2 = "";
    cout<<"please input the num1 and num2:";
    cin>>num1>>num2;
    cout<<s.multiply(num1,num2)<<endl;
    system("pause");
    return 0;
}