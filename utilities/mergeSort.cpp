#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums, int start, int mid, int end){
    int i1 = start;
    int i2 = mid+1;
    vector<int> temp;
    while(i1<=mid && i2<=end){
        if(nums[i1] < nums[i2]){
            temp.push_back(nums[i1]);
            i1++;
        }
        else{
            temp.push_back(nums[i2]);
            i2++;
        }
    }

    while(i1<=mid){
        temp.push_back(nums[i1]);
        i1++;
    }
    while(i2<=end){
        temp.push_back(nums[i2]);
        i2++;
    }
    for(int n: temp){
        nums[start] = n;
        start++;
    }
}

void mergeSort(vector<int>& nums, int start, int end){
    int mid = start + (end-start)/2;

    if(start>=end) return;
    mergeSort(nums, start, mid);
    mergeSort(nums, mid+1, end);
    merge(nums, start, mid, end);

    return;

}



int main(){
    vector<int> n = {5, 9, 1, 45, 12, 10};
    mergeSort(n, 0, 5);
    for(int a: n){
        cout<<a<<" ";
    }
    return 0;
}