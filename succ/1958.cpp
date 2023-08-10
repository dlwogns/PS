#include <iostream>
#include <string>
using namespace std;
string s1, s2,s3, ans;
int arr[1001][1001], arr2[1001];
int main(){
    cin>>s1>>s2>>s3;
    for(int i=1; i<=s1.size(); i++)
        for(int j=1; j<=s2.size(); j++){
            if(s1[i-1] == s2[j-1])
                arr[i][j] = arr[i-1][j-1]+1;
            else 
                arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
        }
    
    cout<<arr[s1.size()][s2.size()]<<'\n';
    cout<<ans;
}