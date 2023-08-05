/*Given an array of integers nums and an integer k.
A continuous subarray is called nice if there are k odd numbers on it.
Return the number of nice sub-arrays.
*/

class Solution {
public:

// int numberOfSubarraysPrefixed(vector<int>& nums, int k) {
//     int r=0,i=0,p=0;
//     vector<int>freq(2,0);

//     for(int j=0;j<nums.size();j++)
//     {
//         freq[nums[j]%2]++;

//         while(freq[1]>k && i<j)
//         {
//             p=0;
//             freq[nums[i]%2]--;
//             i++;
//         }
//         while(nums[i]%2==0 && i<j)
//         {
//             freq[nums[i]%2]--;
//             i++;
//             p++;
//         }
//         if(freq[1]==k)
//         r+=p+1;
//     }
//     return r;

// }
int numberOfSubarraysAtMost(vector<int>& nums, int k) {
    int res=0,i=0;
    vector<int>freq(2,0);

    for(int j=0;j<nums.size();j++)
    {
        freq[nums[j]%2]++;

        while(freq[1]>k )
        {
            freq[nums[i]%2]--;
            i++;
        }
       res+=j-i+1;
    }
    return res;

}

    // int numberOfSubarrays(vector<int>& nums, int k) {
    //     return numberOfSubarraysPrefixed(nums,k);
    // }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return numberOfSubarraysAtMost(nums,k)-numberOfSubarraysAtMost(nums,k-1);
    }
};