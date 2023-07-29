class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int gap = (m+n+1)/2;
        
        for(int i=m;i<m+n;i++)
        {
            nums1[i] = nums2[i-m];
        }
        
        while(gap)
        {
            for(int i=0;i<m+n;i++)
            {
                if((i+gap) < m+n && nums1[i] > nums1[i+gap]) swap(nums1[i],nums1[i+gap]);
                else if(i+gap >= m+n) break;
            }
            if(gap != 1) gap = (gap + 1)/2;
            else gap = 0;
        }
    }
};