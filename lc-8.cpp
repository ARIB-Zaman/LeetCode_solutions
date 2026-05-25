#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s) {
    int ans = 0;
    string trimmed = "";
    bool negative = false;
    bool wordfound = false;

    //trim empty space
    for(char c: s){
        if(c == ' ' && !wordfound) continue;
        wordfound = true;
        trimmed += c;
    }

    //trim +- sign
    int trimmed_len = trimmed.size()-1;
    if(trimmed[0]=='-') negative = true;
    if(negative || trimmed[0]=='+') trimmed = trimmed.substr(1,trimmed_len);

    //atoi
    int digitcount = 0;
    for(char c: trimmed){
        if(!isdigit(c)) break;
        // edge cases
        if(digitcount >= 9){     
            if(!negative && ans>214748364) return 2147483647;
            if(!negative && ans==214748364 && (c-'0')>7) return 2147483647;
            if(negative && ans>214748364) return -2147483648;
            if(negative && ans==214748364 && (c-'0')>7) return -2147483648;
        }
        ans = ans*10 + (c-'0');
        digitcount++;
    }
    if(negative) return -ans;
    return ans;
}

int main(){
    cout<<myAtoi("  -0 235adsf");
}