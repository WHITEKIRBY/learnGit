#include <iostream>
#include <vector>
using std::vector;
//最佳做法请参考：https://leetcode-cn.com/problems/median-of-two-sorted-arrays/

//这是自己手打的暴力解法（
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> combine;
        double ans;
        int i = 0;
        int j = 0;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] > nums2[j])
            {
                combine.push_back(nums2[j]);
                j++;
            }
            else if (nums1[i] < nums2[j])
            {
                combine.push_back(nums1[i]);
                i++;
            }
            else
            {
                combine.push_back(nums1[i]);
                combine.push_back(nums2[j]);
                i++;
                j++;
            }
        }
        if (j == nums2.size() && i != nums1.size())
        {
            for (; i < nums1.size(); i++)
            {
                combine.push_back(nums1[i]);
            }
        }
        if (i == nums1.size() && j != nums2.size())
        {
            for (; j < nums2.size(); j++)
            {
                combine.push_back(nums2[j]);
            }
        }
        if (combine.size() % 2 == 1)
        {
            ans = combine[(combine.size() - 1) / 2];
        }
        else
        {
            ans = static_cast<double>(combine[combine.size() / 2] + combine[combine.size() / 2 - 1]) / 2;
        }
        return ans;
    }
};
