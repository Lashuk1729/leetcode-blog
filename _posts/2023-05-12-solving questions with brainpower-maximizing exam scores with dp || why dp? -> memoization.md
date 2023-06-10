---
layout: mypost
title: "Solving Questions With Brainpower - Maximizing Exam Scores with DP || Why DP? -> Memoization"
tags: ["Array", "Dynamic Programming", "C++", "Recursion", "Memoization", "Medium"]
---
# Problem Statement:
<p>You are given a <strong>0-indexed</strong> 2D integer array <code>questions</code> where <code>questions[i] = [points<sub>i</sub>, brainpower<sub>i</sub>]</code>.</p>

<p>The array describes the questions of an exam, where you have to process the questions <strong>in order</strong> (i.e., starting from question <code>0</code>) and make a decision whether to <strong>solve</strong> or <strong>skip</strong> each question. Solving question <code>i</code> will <strong>earn</strong> you <code>points<sub>i</sub></code> points but you will be <strong>unable</strong> to solve each of the next <code>brainpower<sub>i</sub></code> questions. If you skip question <code>i</code>, you get to make the decision on the next question.</p>

<ul>
	<li>For example, given <code>questions = [[3, 2], [4, 3], [4, 4], [2, 5]]</code>:

	<ul>
		<li>If question <code>0</code> is solved, you will earn <code>3</code> points but you will be unable to solve questions <code>1</code> and <code>2</code>.</li>
		<li>If instead, question <code>0</code> is skipped and question <code>1</code> is solved, you will earn <code>4</code> points but you will be unable to solve questions <code>2</code> and <code>3</code>.</li>
	</ul>
	</li>
</ul>

<p>Return <em>the <strong>maximum</strong> points you can earn for the exam</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> questions = [[3,2],[4,3],[4,4],[2,5]]
<strong>Output:</strong> 5
<strong>Explanation:</strong> The maximum points can be earned by solving questions 0 and 3.
- Solve question 0: Earn 3 points, will be unable to solve the next 2 questions
- Unable to solve questions 1 and 2
- Solve question 3: Earn 2 points
Total points earned: 3 + 2 = 5. There is no other way to earn 5 or more points.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> questions = [[1,1],[2,2],[3,3],[4,4],[5,5]]
<strong>Output:</strong> 7
<strong>Explanation:</strong> The maximum points can be earned by solving questions 1 and 4.
- Skip question 0
- Solve question 1: Earn 2 points, will be unable to solve the next 2 questions
- Unable to solve questions 2 and 3
- Solve question 4: Earn 5 points
Total points earned: 2 + 5 = 7. There is no other way to earn 7 or more points.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= questions.length &lt;= 10<sup>5</sup></code></li>
	<li><code>questions[i].length == 2</code></li>
	<li><code>1 &lt;= points<sub>i</sub>, brainpower<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
</ul>

# Solution:
# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
This is a classical Dynamic Programming Problem.

We have to find the maximum points we can earn by solving the exam questions in order while accounting for the constraint that we can only skip a limited number of questions after solving each one. 

Since the order in which we solve the questions matters, we have to use an approach starting from the $0^{th}$ index rather than from $n-1^{th}$ (it's mentioned: *process the questions __in order__*) to solve this problem recursively by breaking it down into smaller subproblems. 

We have to use memoization to avoid redundant calculations (I submitted using recursion solution even though I knew it will give _TLE_).

# Approach
<!-- Describe your approach to solving the problem. -->
We can define our state as the current question we are considering, and the maximum points we can earn from that question onwards. We can then use recursion to fill up our state table, with each recursive call representing our decision of whether to answer or skip the current question. We can then use memoization to store the results of our recursive calls, which will reduce the time complexity of our solution.

Let `dp[i]` denote the maximum points we can earn by solving the questions from `i` to the end of the sequence. We can compute this recursively as follows:

- If we skip the current question `i`, we move to the next question `(i+1)`, and our score remains the same. 
 So, the maximum points we can earn starting from the next question will be `pointsScored(questions, i + 1, dp)`.
- If we solve the current question i, we earn $points_i$ points, and we skip the next $brainpower_i$ questions.
 So, the maximum points we can earn starting from the next eligible question (i.e., `i + questions[i][1] + 1`) will be `questions[i][0] + pointsScored(questions, i + brainpower[i] + 1, dp)`.

# Complexity
- Time complexity: $O(n)$, where $n$ is the number of questions. This is because each question is processed only once, and each sub-problem is solved recursively only once, as the maximum points for a question are memoized in the dp array once they are computed.
  However, each recursive call involves solving two sub-problems, which takes $O(1)$ time. Therefore, the total time complexity of the algorithm is $$O(n * 1) = O(n)$$.
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity:
  The space complexity of this approach is O(n), which is the size of the dp array.
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
 {% highlight cpp %} 
class Solution {
public:
    long long pointsScored(vector<vector<int>>& questions, int n, vector<long long>& dp) {
        if(n >= questions.size())
            return 0;
        
        else {
            if(dp[n] != -1)
                return dp[n];
            
            else {
                return dp[n] = max(pointsScored(questions, n+1, dp), questions[n][0] + pointsScored(questions, n + questions[n][1] + 1, dp));
            }
        }
    }
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(), -1);
        return pointsScored(questions, 0, dp);
    }
};
 {% endhighlight %}