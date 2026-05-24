#include <bits/stdc++.h>

using namespace std;

double findMedianSortedArrays(vector<int> nums1, vector<int> nums2) {
    int i1 = 0;
    int i2 = 0;
    int i = 0;
    int size1 = nums1.size();
    int size2 = nums2.size();
    float medpos = (size1 + size2 - 1.0)/2;
    int med1pos = floor(medpos);
    int med2pos = ceil(medpos);
    int med1, med2;

    while(i1 < size1 && i2 < size2){
        if(nums1[i1] < nums2[i2]){
            if(i == med1pos) med1 = nums1[i1]; 
            if(i == med2pos) med2 = nums1[i1]; 
            i1++;
        }else{
            if(i == med1pos) med1 = nums2[i2]; 
            if(i == med2pos) med2 = nums2[i2]; 
            i2++;
        }
        i++;
    }
    while(i1<size1){
        if(i == med1pos) med1 = nums1[i1]; 
        if(i == med2pos) med2 = nums1[i1]; 
        i1++;
        i++;
    }
    while(i2<size2){
        if(i == med1pos) med1 = nums2[i2]; 
        if(i == med2pos) med2 = nums2[i2]; 
        i2++;
        i++;
    }

    return (med1 + med2 + 0.0)/2;

    
}

int main(){
    cout << findMedianSortedArrays({1,3},{2});
}