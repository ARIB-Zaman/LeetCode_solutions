#include <bits/stdc++.h>

using namespace std;

string convert(string s, int numRows) {
    if(numRows == 1) return s;
    int size = s.size();
    int mazorRowdist = (numRows-1)*2;
    string newword = "";
    for(int i=0; i<numRows; i++){
        int latch = i;
        while(latch < size){
            int leech = (numRows - 1 - ( i%numRows))*2;
            newword += s[latch];
            if(latch+leech >= size) break;
            if(leech%mazorRowdist != 0) newword += s[latch+leech];
            latch += mazorRowdist;
        }
    }
    return newword;
    
}


int main(){
    cout<<convert("paypalishiring", 4);
}