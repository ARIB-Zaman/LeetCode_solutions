#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int x) {
    if(x<0) return false;
    string s = to_string(x);
    int start = s.size()-1;
    int end = 0;
    while(end<start){
        if(s[end] != s[start]) return false;
        end++;
        start--;
    }       
    return true;
}

int main(){
    cout<<isPalindrome(0);
}