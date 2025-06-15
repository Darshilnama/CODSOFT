#include <bits/stdc++.h>
using namespace std;
int main(){
    char op;
    float num1, num2, res;
    cout<<"Enter two numbers : ";
    cin>>num1>>num2;
    cout<<"Enter the operation[+,/,*,-] : ";
    cin>>op;
    switch(op){
        case '+':{
            res=num1+num2;
            break;
        }
         case '-':{
            res=num1-num2;
            break;
        }
         case '*':{
            res=num1*num2;
            break;
        }
         case '/':{
            res=num1/num2;
            break;
        }
        default:{
            cout<<"Enter valid operator"<<endl;
            res=DBL_MAX;
        }

    }
    if(res!=DBL_MAX){
    cout<<"Result : "<<res;
    }
    return 0;

}