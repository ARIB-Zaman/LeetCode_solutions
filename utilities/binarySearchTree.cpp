#include <iostream>
#include <vector>

using namespace std;


int bst(vector<int> nums, int target, int start, int end){
    int size = end-start;
    int mid = start + size/2;
    if(nums[mid] == target) return mid;
    if(start>=end) return -1;

    if(nums[mid] > target){
        return bst(nums, target, start, mid-1);
    }
    else{
        return bst(nums, target, mid+1, end);
    }
}


int main(){

    vector<int> nums = {2, 4, 7, 9, 13, 15, 16, 20, 24, 29, 33, 35, 36, 39, 40, 45, 49};
    int target = 49;

    int ans_index = bst(nums, target, 0, nums.size()-1);


    cout<<ans_index;
    return 0;
}