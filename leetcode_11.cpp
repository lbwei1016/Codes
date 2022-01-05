/*
***two pointer***
    Solution:
        從兩邊包夾，每次將較小的一邊淘汰 (因為算面積時只能取較小的邊)
    O(n)
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0, j = n-1, mx = 0;
        while(i < j) {
            mx = max(mx, (j-i)*min(height[i], height[j]));
            height[i]<height[j] ? ++i : --j; // try to find a taller edge
        }
        return mx;
    }
};