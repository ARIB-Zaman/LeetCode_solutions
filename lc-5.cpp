#include <bits/stdc++.h>

using namespace std;

pair<int, int> fromletter(int index, string s){
    int adder = 0;
    int len = 0;
    int start, end;
    int lennn = s.size();
    while(index-adder >= 0 && index+adder < lennn){
        if(s[index+adder] == s[index-adder]) len++;
        else break;
        adder++;
    }
    return {index-adder+1, index+adder-1};
}

pair<int, int> fromspace(int index, string s){
    int len = 0;
    int adder = 0;
    int start, end;
    int lennn = s.size();
    while(index-adder >= 0 && index+adder+1 < lennn ){
        if(s[index-adder] == s[index+adder+1]) len++;
        else break;
        adder++;
    }
    return {index-adder+1, index+adder+1-1};

}

string longestPalindrome(string s) {
    int maxlen = -1;
    pair<int, int> maxpair;
    int len = s.size();

    for(int i=0; i<len; i++){
        pair<int,int> plndrm = fromletter(i, s);
        if(maxlen < plndrm.second - plndrm.first + 1){
            maxpair = plndrm;
            maxlen = plndrm.second - plndrm.first + 1;
        }
        plndrm = fromspace(i, s);
        if(maxlen < plndrm.second - plndrm.first + 1){
            maxpair = plndrm;
            maxlen = plndrm.second - plndrm.first + 1;
        }
    }

    return s.substr(maxpair.first, maxlen);
    
}

int main(){
    pair<int, int> smt = fromletter(1, "aasa");
    cout<<smt.first<<smt.second<<endl;
    cout<<longestPalindrome("asafasaasdf");
}