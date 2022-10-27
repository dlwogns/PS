#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;
string s, n;
int cf;
deque<long long>num;
deque<char>oper;
int main(){
    cin>>s;
    for(int i=0; i<s.size(); i++){
        if(i == 0 && s[i] == '-'){
            cf = 1;
            continue;
        }
        if(s[i] <='9' && s[i] >='0'){
            n.push_back(s[i]);
        }else{
            if(cf == 1){
                num.push_back(-1 *stoll(n));
                cf = 0;
            }else 
                num.push_back(stoll(n));
            n.clear();
            oper.push_back(s[i]);
        }
    }
    if(!n.empty() && cf == 1)
        num.push_back( -1 *stoll(n));
    else if(!n.empty())
        num.push_back(stoll(n));
    while(!oper.empty()){
        // for(auto e : num){
        //     cout<<e<<' ';
        // }
        // cout<<endl;
        // for(auto o : oper){
        //     cout<<o<<' ';
        // }
        //cout<<endl;
        if(oper.size() == 1){
            long long ln1 = *num.begin(), ln2 = *(num.begin()+1), r1;
            if(oper.front()=='*')
                r1 = ln1*ln2;
            else if(oper.front()=='/')
                r1 = ln1/ln2;
            else if(oper.front()=='+')
                r1 = ln1+ln2;
            else
                r1 = ln1-ln2;
            num.push_front(r1);
            break;
        }
        int c1 =0, c2 = 0;
        if(oper.front()=='*'||oper.front()=='/') c1 = 1;
        if(oper.back()=='*'||oper.back()=='/') c2 = 1;
        if(c1 == c2){
            long long ln1 = *num.begin(), ln2 = *(num.begin()+1);
            long long rn1 = *(num.end()-1), rn2 = *(num.end()-2);
            long long r1, r2;
            if(oper.front()=='*')
                r1 = ln1*ln2;
            else if(oper.front()=='/')
                r1 = ln1/ln2;
            else if(oper.front()=='+')
                r1 = ln1+ln2;
            else
                r1 = ln1-ln2;
            
            if(oper.back()=='*')
                r2 = rn2*rn1;
            else if(oper.back()=='/')
                r2 = rn2/rn1;
            else if(oper.back()=='+')
                r2 = rn2+rn1;
            else
                r2 = rn2-rn1;
            //cout<<r1<<' '<<r2<<endl<<endl;
            if(r1 >= r2){
                num.pop_front();
                num.pop_front();
                num.push_front(r1);
                oper.pop_front();
            }else if(r1 < r2){
                num.pop_back();
                num.pop_back();
                num.push_back(r2);
                oper.pop_back();
            }


        }else if(c1 > c2){
            long long n1 = num.front();
            num.pop_front();
            long long n2 = num.front();
            num.pop_front();
            if(oper.front() == '*')
                num.push_front(n1*n2);
            else
                num.push_front(n1/n2);
            oper.pop_front();
        }else if(c1 < c2){
            long long n1 = num.back();
            num.pop_back();
            long long n2 = num.back();
            num.pop_back();
            if(oper.back() == '*')
                num.push_back(n2*n1);
            else
                num.push_back(n2/n1);
            oper.pop_back();
        }
    }
    cout<<num[0];
}