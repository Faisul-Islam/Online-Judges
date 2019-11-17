#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
using namespace std;
int main() {
    int t_case;
    string x;
    cin >> t_case;
    getchar();
    while(t_case--) {
        getline(cin,x);
        for(int i = 0; i<x.length(); i++) {
            if((x[i]>='A'&& x[i]<='Z')||(x[i]>='a' && x[i]<='z')) {
                x[i] += 3;
            }
        }
        reverse(x.begin(),x.end());
        if(x.length()%2!=0) {
            for(int i = (x.length()-1)/2; i < x.length(); i++) {
                x[i] -=1;
            }
        } else {
            for(int i = x.length()/2; i < x.length(); i++) {
                x[i] -=1;
            }
        }
        cout << x << endl;
    }

    return 0;
}
