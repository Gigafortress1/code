#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main() {
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
    string str;

    while (getline(cin, str)) {
        int n=0,j=0;
        int result = 0;
        for (int i = 0; i < str.length();i++) {
            if (str[i] == ' ') {
                i++;
                continue;
            }
            else if(str[i]=='-'){
                n=str[i+1]-'0';j=i+2;
                while(str[j]<=57 && str[j]>=48&&j<str.length()){
                    n*=10;
                    n+=str[j]-'0';
                    j++;
                }
                result-=n;
                i=j;
            }
            else if (str[i] <= 57 && str[i] >= 48) {
                n=str[i]-'0';j=i+1;
                while(str[j]<=57 && str[j]>=48&&j<str.length()){
                n*=10;
                n+=str[j]-'0';
                j++;
            }
            result+=n;
            i=j;

            }
        }
        cout<<result<<endl;
    }

}