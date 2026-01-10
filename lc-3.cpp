#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int itr(string s, int start, int end){
    vector<int> map(127, -1);
    int maxlen = end-start+1;

    if(start>=end) return 1;

    for(int i=start; i<=end; i++){
        if(map[s[i]] == -1){
            map[s[i]] = i;
            continue;
        }
        int l1 = itr(s, start, i-1);
        int l2 = itr(s, map[s[i]], i-1);
        int l3 = itr(s, map[s[i]]+1, end);
        maxlen = max(l1, max(l2, l3));
        break;
    }

    return maxlen;
}


int lengthOfLongestSubstring(string s){
    int size = s.size();
    if(size == 0) return 0;
    int len = itr(s, 0, size-1);
    return len;
}

int main(){
    string st = "asdfasdf";
    cout<<st.size()<<endl;
    cout<<lengthOfLongestSubstring(st);
    return 0;
}