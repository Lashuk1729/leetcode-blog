---
layout: mypost
title: "Number of Adjacent Elements With the Same Color - From O(n * q) to O(q): Track the count of adjacent elements with the same color as we go along"
tags: ["Array", "C++", "Counting", "Medium"]
---
# Problem Statement:
<p>There is a <strong>0-indexed</strong> array <code>nums</code> of length <code>n</code>. Initially, all elements are <strong>uncolored </strong>(has a value of <code>0</code>).</p>

<p>You are given a 2D integer array <code>queries</code> where <code>queries[i] = [index<sub>i</sub>, color<sub>i</sub>]</code>.</p>

<p>For each query, you color the index <code>index<sub>i</sub></code> with the color <code>color<sub>i</sub></code> in the array <code>nums</code>.</p>

<p>Return <em>an array </em><code>answer</code><em> of the same length as </em><code>queries</code><em> where </em><code>answer[i]</code><em> is the number of adjacent elements with the same color <strong>after</strong> the </em><code>i<sup>th</sup></code><em> query</em>.</p>

<p>More formally, <code>answer[i]</code> is the number of indices <code>j</code>, such that <code>0 &lt;= j &lt; n - 1</code> and <code>nums[j] == nums[j + 1]</code> and <code>nums[j] != 0</code> after the <code>i<sup>th</sup></code> query.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 4, queries = [[0,2],[1,2],[3,1],[1,1],[2,1]]
<strong>Output:</strong> [0,1,1,0,2]
<strong>Explanation:</strong> Initially array nums = [0,0,0,0], where 0 denotes uncolored elements of the array.
- After the 1<sup>st</sup> query nums = [2,0,0,0]. The count of adjacent elements with the same color is 0.
- After the 2<sup>nd</sup> query nums = [2,2,0,0]. The count of adjacent elements with the same color is 1.
- After the 3<sup>rd</sup>&nbsp;query nums = [2,2,0,1]. The count of adjacent elements with the same color is 1.
- After the 4<sup>th</sup>&nbsp;query nums = [2,1,0,1]. The count of adjacent elements with the same color is 0.
- After the 5<sup>th</sup>&nbsp;query nums = [2,1,1,1]. The count of adjacent elements with the same color is 2.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 1, queries = [[0,100000]]
<strong>Output:</strong> [0]
<strong>Explanation:</strong> Initially array nums = [0], where 0 denotes uncolored elements of the array.
- After the 1<sup>st</sup> query nums = [100000]. The count of adjacent elements with the same color is 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= queries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>queries[i].length&nbsp;== 2</code></li>
	<li><code>0 &lt;= index<sub>i</sub>&nbsp;&lt;= n - 1</code></li>
	<li><code>1 &lt;=&nbsp; color<sub>i</sub>&nbsp;&lt;= 10<sup>5</sup></code></li>
</ul>

# Solution:
# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
The idea here is that we check the adjacent elements with the same color as we go along.

# Naive Approach
<!-- Describe your approach to solving the problem. -->
First, we will need to update the nums array with the new color for each query, and then for each query, loop through the nums array to count the number of adjacent elements that have the same color.

## Complexity
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
- Time complexity: $$O(n * q)$$ 
 Here, n is the length of the array and q is the number of queries. This is because we loop through the entire `nums` array for each query. As the size of the array and the number of queries increase, this approach becomes very slow and inefficient.

<!-- Add your space complexity here, e.g. $$O(n)$$ -->
- Space complexity: $$O(n)$$, where n is the length of the array.

## Code
 {% highlight cpp %} 
class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        int s = queries.size();
        vector<int> nums(n, 0);
        vector<int> answer(s, 0);

        for (int i = 0; i < s; i++) {
            nums[queries[i][0]] = queries[i][1];
            int count = 0;
            for (int j = 0; j < n - 1; j++) {
                if (nums[j] != 0 && nums[j] == nums[j+1]) {
                    count++;
                }
            }
            answer[i] = count;
        }

        return answer;
    }
};
 {% endhighlight %}
As the Code has a time complexity of $$O(n * q)$$; it will not work when the query.length is 10<sup>5</sup> and array length is also 10<sup>5</sup>.

# Approach 2: A bit optimal
Here, I need to reduce the loop or decrease the complexity of the code from $$O(n \cdot q)$$ to O(q) (processing the query does not take any time).*Italic* 
If I can keep the track of the count of adjacent elements with the same color as we go along, so that we don't need to iterate over the entire nums array for each query. This way, we can compute the answer for each query in constant time.

We can keep track of a running `count` of the number of adjacent elements with the same color. 
For each query, 
- We update the color at the specified index and check the adjacent elements to the left and right of the updated index. 
- We increment the count if any of these adjacent elements have the same color as the new color. 
- We also check the adjacent elements to the left and right of the updated index to see if they had the same color as the old color, and decrement the count if this is the case. 
- Finally, we append the current count to the answer array and return it.

## Complexity
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
- Time complexity: $$O(q)$$, where q is the number of queries (we process each query in constant time).

<!-- Add your space complexity here, e.g. $$O(n)$$ -->
- Space complexity: $$O(n)$$, where n is the length of the array.

## Code
 {% highlight cpp %} 
class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> nums(n, 0);
        vector<int> answer;
        int count = 0;

        for (int i = 0; i < queries.size(); i++) {
            int index = queries[i][0];
            int color = queries[i][1];

            int prevColor = nums[index];
            nums[index] = color;

            if (index > 0 && nums[index-1] != 0 && nums[index-1] == color) {
                count++;
            }

            if (index < n-1 && nums[index+1] != 0 && nums[index+1] == color) {
                count++;
            }

            if (prevColor != 0) {
                if (index > 0 && nums[index-1] != 0 && nums[index-1] == prevColor) {
                    count--;
                }

                if (index < n-1 && nums[index+1] != 0 && nums[index+1] == prevColor) {
                    count--;
                }
            }

            answer.push_back(count);
        }

        return answer;
    }
};
 {% endhighlight %}


