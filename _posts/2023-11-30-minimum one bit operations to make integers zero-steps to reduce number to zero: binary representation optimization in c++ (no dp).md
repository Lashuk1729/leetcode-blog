---
layout: mypost
title: "Minimum One Bit Operations to Make Integers Zero - Steps to Reduce Number to Zero: Binary Representation Optimization in C++ (No DP)"
tags: ["Dynamic Programming", "Bit Manipulation", "Memoization", "C++", "Hard"]
---
# Problem Statement:
<p>Given an integer <code>n</code>, you must transform it into <code>0</code> using the following operations any number of times:</p>

<ul>
	<li>Change the rightmost (<code>0<sup>th</sup></code>) bit in the binary representation of <code>n</code>.</li>
	<li>Change the <code>i<sup>th</sup></code> bit in the binary representation of <code>n</code> if the <code>(i-1)<sup>th</sup></code> bit is set to <code>1</code> and the <code>(i-2)<sup>th</sup></code> through <code>0<sup>th</sup></code> bits are set to <code>0</code>.</li>
</ul>

<p>Return <em>the minimum number of operations to transform </em><code>n</code><em> into </em><code>0</code><em>.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 3
<strong>Output:</strong> 2
<strong>Explanation:</strong> The binary representation of 3 is &quot;11&quot;.
&quot;<u>1</u>1&quot; -&gt; &quot;<u>0</u>1&quot; with the 2<sup>nd</sup> operation since the 0<sup>th</sup> bit is 1.
&quot;0<u>1</u>&quot; -&gt; &quot;0<u>0</u>&quot; with the 1<sup>st</sup> operation.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 6
<strong>Output:</strong> 4
<strong>Explanation:</strong> The binary representation of 6 is &quot;110&quot;.
&quot;<u>1</u>10&quot; -&gt; &quot;<u>0</u>10&quot; with the 2<sup>nd</sup> operation since the 1<sup>st</sup> bit is 1 and 0<sup>th</sup> through 0<sup>th</sup> bits are 0.
&quot;01<u>0</u>&quot; -&gt; &quot;01<u>1</u>&quot; with the 1<sup>st</sup> operation.
&quot;0<u>1</u>1&quot; -&gt; &quot;0<u>0</u>1&quot; with the 2<sup>nd</sup> operation since the 0<sup>th</sup> bit is 1.
&quot;00<u>1</u>&quot; -&gt; &quot;00<u>0</u>&quot; with the 1<sup>st</sup> operation.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= n &lt;= 10<sup>9</sup></code></li>
</ul>

# Solution:
# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
There are 2 things, we need to understand (which took me lot of time to understand):
1. Recognize the pattern that to convert a number in the form of $2^{n}$ to make it $0$, it takes $2^{n+1} - 1$ steps.
    1. 1 $ightarrow$ 0 $\Rightarrow$ takes 1 step.
    2. 2 $\equiv$ 10 $\Rightarrow$ takes 3 steps 
    (10 $ightarrow$ 11 (step 1) $ightarrow$ 01 (step 2) $ightarrow$ 00 (step 3)).
    3. 4 $\equiv$ 100 $\Rightarrow$ takes 7 steps 
    (100 $ightarrow$ 101 (step 1) $ightarrow$ 111 (step 2) $ightarrow$ 110 (step 3) $ightarrow$ 010 $ightarrow$ (follow what we did in 2)).
    4. 8 $\equiv$ 1000 $\Rightarrow$ takes 15 steps 
    (1000 $ightarrow$ 1001 (step 1) $ightarrow$ 1011 (step 2) $ightarrow$ 1010 (step 3) $ightarrow$ 1110 (step 4) $ightarrow$ 1111 (step 5) $ightarrow$ 1101 (step 6) $ightarrow$ 1100 (step 7) $ightarrow$ 0100 (step 8) $ightarrow$ (follow what we did in 4)).

2. _For numbers that aren't powers of two, break them down into their binary representations and eliminate overlapping steps in their conversion_:
Now, let's take 22 $\equiv$ 10110. To get the minimum count, let's break the number:
10110 = 10000 + 100 + 10.
And we have seen above in point 1, that to convert 10000 to 0 (00000), we need 31 steps. 
But, we have to get the steps for 22, which has steps for 100 and 10, so, __*we have to remove the steps taken by 100 and 10; when counting the steps taken in 10110*__.

$	herefore$ the steps required for 22 ($\equiv$ 10110) = (31 - (7 - 3))

# Approach
<!-- Describe your approach to solving the problem. -->
1. Convert the given number into its reverse binary representation, using the function  {% highlight cpp %} reverseIntToBin {% endhighlight %} (Why reverse? This facilitates counting steps from the least significant bit, where the first '1' occurs).
2. Eliminating Overlapping Steps - Calculate the steps needed by considering the binary representation. Recognize that the steps for a number can be reduced by subtracting the steps required for its binary components. 
For instance, for the number 22 ($10110_{2}$), break it down into its binary components: $10000_2$+$100_2$+$10_2$. Remove the steps taken for $100_2$\u200B and $10_2$\u200B while counting the total steps for $10110_{2}$.

# Complexity
- Time complexity: O(log n)
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: O(log n) - As I'm storing all the binary string.
<!-- Add your space complexity here, e.g. $$O(n)$$ --> 

# Code
 {% highlight cpp %} 
class Solution {
public:
    string reverseIntToBin(int n) {
        string res = "";
        while(n) {
            res += string(1, (n % 2) + '0');
            n = n / 2;
        }
        return res;
    }
    int minimumOneBitOperations(int n) {
        string s_bin = reverseIntToBin(n);
        int ind = 0, res = 0, len = s_bin.length();
        
        while(ind <= len) {
            if(s_bin[ind] == '1')
                res = (pow(2, ind+1) - 1) - res;
            ind += 1;
        }

        return res;
    }
};
 {% endhighlight %}