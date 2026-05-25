#include <bits/stdc++.h>

using namespace std;


int reverse(int x) {
    int divider = 1000000000;
    int multiplier = 1;
    while(!(x/divider) && (divider!=1)) divider/=10;
    int ans = 0;
    while(x!=0){
        int a = x/divider;
        if(multiplier==1000000000){              //overflow handle
            if(abs(a)>2) return 0;
            if(abs(a)==2 && abs(ans)>147483647) return 0;
        }
        int additive = (x/divider)*multiplier;

        ans = ans + additive;
        x = x - (x/divider)*divider;
        divider/=10;
        if(multiplier==1000000000) return ans;  //overflow handle
        multiplier*=10;
    }
    return ans;
}

int main(){
    int a = -2147483412;
    int b = 4;
    int c = 2147483647;
    cout<<reverse(a);
}