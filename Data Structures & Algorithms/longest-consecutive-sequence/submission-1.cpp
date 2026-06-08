class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
   if(nums.empty()) return 0;
   sort(nums.begin(), nums.end());
   int len = 1; 
   int ml = 1;
   for(int i=0; i<nums.size()-1; i++){
    if(nums[i+1]-nums[i]==1) len++;
    else if(nums[i+1] != nums[i]){
        len = 1;
    }
    ml = max(ml, len);
   }
   return ml;
    }
};
