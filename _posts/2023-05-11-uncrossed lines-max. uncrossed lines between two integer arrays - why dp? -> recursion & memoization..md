---
layout: mypost
title: "Uncrossed Lines - Max. Uncrossed Lines between Two Integer Arrays - Why DP? -> Recursion & Memoization."
tags: ["Array", "Dynamic Programming", "C++", "Recursion", "Memoization", "Medium"]
---
# Problem Statement:
<p>You are given two integer arrays <code>nums1</code> and <code>nums2</code>. We write the integers of <code>nums1</code> and <code>nums2</code> (in the order they are given) on two separate horizontal lines.</p>

<p>We may draw connecting lines: a straight line connecting two numbers <code>nums1[i]</code> and <code>nums2[j]</code> such that:</p>

<ul>
	<li><code>nums1[i] == nums2[j]</code>, and</li>
	<li>the line we draw does not intersect any other connecting (non-horizontal) line.</li>
</ul>

<p>Note that a connecting line cannot intersect even at the endpoints (i.e., each number can only belong to one connecting line).</p>

<p>Return <em>the maximum number of connecting lines we can draw in this way</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/04/26/142.png" style="width: 400px; height: 286px;" />
<pre>
<strong>Input:</strong> nums1 = [1,4,2], nums2 = [1,2,4]
<strong>Output:</strong> 2
<strong>Explanation:</strong> We can draw 2 uncrossed lines as in the diagram.
We cannot draw 3 uncrossed lines, because the line from nums1[1] = 4 to nums2[2] = 4 will intersect the line from nums1[2]=2 to nums2[1]=2.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums1 = [2,5,1,2,5], nums2 = [10,5,2,1,5,2]
<strong>Output:</strong> 3
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums1 = [1,3,7,1,7,5], nums2 = [1,9,2,5,1]
<strong>Output:</strong> 2
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length, nums2.length &lt;= 500</code></li>
	<li><code>1 &lt;= nums1[i], nums2[j] &lt;= 2000</code></li>
</ul>

# Solution:
# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
This problem is asking us to find the maximum number of non-intersecting connecting lines between the two given integer arrays `nums1` and `nums2`. The connecting lines must connect elements that are equal in both arrays, and once a connection is made, it cannot be used again.

In this specific problem, we can break down the task of finding the maximum number of connecting lines between two arrays into subproblems of finding the maximum number of connecting lines between smaller prefixes of these arrays. We can then combine the solutions to these subproblems to obtain the final answer. 

# Approach
<!-- Describe your approach to solving the problem. -->
The approach used is to start from the last element of both arrays and compare the elements. If they are equal, we increment the count of connecting lines and recursively move to the next elements of both arrays. If they are not equal, we recursively consider two options: either connect the current element of `nums2` with the next element of `nums1`, or connect the current element of `nums1` with the next element of `nums2`. We choose the maximum of these two options.

## Recursion Solution:

### Complexity
- __Time complexity__:
 The recursive approach has an exponential time complexity of $O(2^{(n+m)})$ because for each element in the two arrays, we have two options to consider.

<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- __Space complexity__:
 The space complexity is $O(n+m)$, where $n$ and $m$ are the sizes of the input arrays `nums1` and `nums2`, respectively.
 This is because in the worst case, the recursion depth can be as large as the sum of the lengths of the two input arrays. In each recursive call, we allocate space on the call stack to store the function's local variables and the return address.
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

## Code
 {% highlight cpp %} 
class Solution {
public:
    int crossLines(vector<int>& nums1, vector<int>& nums2, int n, int m) {
        if(n < 0 || m < 0)
            return 0;

        if(nums1[n] == nums2[m])
            return 1 + crossLines(nums1, nums2, n-1, m-1);

        else {
            return max(crossLines(nums1, nums2, n, m-1), crossLines(nums1, nums2, n-1, m));
        }
    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        return crossLines(nums1, nums2, n-1, m-1);
        
    }
};
 {% endhighlight %}
I submitted this soluton and got _TLE_; And after the time complexity analysis, I understood why (before the analysis, I thought, the solution _might_ get accepeted -> 80% of the problem is solved).

## Submitted Solution
In this case, as the recursion solution gave me _TLE_, I went forward with memoization as it reduces the number of recursive calls and improves the time complexity of the algorithm.

### Complexity
- __Time complexity__:
 The memoized recursive approach reduces the time complexity to $O(n*m)$ by using a 2D memoization table to store the intermediate results of subproblems and avoid recomputing them.

<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- __Space complexity__:
 The space complexity is $O(n*m)$, where $n$ and $m$ are the sizes of the input arrays nums1 and nums2, respectively.
 This is because we use a 2D array dp of size n x m to store the solutions to subproblems. Each entry in the array requires constant space to store an integer value. 
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

 {% highlight cpp %} 
class Solution {
public:
    int crossLines(vector<int>& nums1, vector<int>& nums2, int n, int m, vector<vector<int>>&dp) {
        if(n < 0 || m < 0)
            return 0;
        
        if(dp[n][m] != -1)
            return dp[n][m];

        else{
            if(nums1[n] == nums2[m])
                return 1 + crossLines(nums1, nums2, n-1, m-1, dp);

            return dp[n][m] = max(crossLines(nums1, nums2, n, m-1, dp), crossLines(nums1, nums2, n-1, m, dp));
        }
    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return crossLines(nums1, nums2, n-1, m-1, dp);
        
    }
};
 {% endhighlight %}