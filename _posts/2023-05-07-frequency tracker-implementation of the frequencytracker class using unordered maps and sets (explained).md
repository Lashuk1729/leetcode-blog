---
layout: mypost
title: "Frequency Tracker - Implementation of the FrequencyTracker class using unordered maps and sets (Explained)"
tags: ["Hash Table", "Design", "C++", "Medium"]
---
# Problem Statement:
<p>Design a data structure that keeps track of the values in it and answers some queries regarding their frequencies.</p>

<p>Implement the <code>FrequencyTracker</code> class.</p>

<ul>
	<li><code>FrequencyTracker()</code>: Initializes the <code>FrequencyTracker</code> object with an empty array initially.</li>
	<li><code>void add(int number)</code>: Adds <code>number</code> to the data structure.</li>
	<li><code>void deleteOne(int number)</code>: Deletes <strong>one</strong> occurrence of <code>number</code> from the data structure. The data structure <strong>may not contain</strong> <code>number</code>, and in this case nothing is deleted.</li>
	<li><code>bool hasFrequency(int frequency)</code>: Returns <code>true</code> if there is a number in the data structure that occurs <code>frequency</code> number of times, otherwise, it returns <code>false</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input</strong>
[&quot;FrequencyTracker&quot;, &quot;add&quot;, &quot;add&quot;, &quot;hasFrequency&quot;]
[[], [3], [3], [2]]
<strong>Output</strong>
[null, null, null, true]

<strong>Explanation</strong>
FrequencyTracker frequencyTracker = new FrequencyTracker();
frequencyTracker.add(3); // The data structure now contains [3]
frequencyTracker.add(3); // The data structure now contains [3, 3]
frequencyTracker.hasFrequency(2); // Returns true, because 3 occurs twice

</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input</strong>
[&quot;FrequencyTracker&quot;, &quot;add&quot;, &quot;deleteOne&quot;, &quot;hasFrequency&quot;]
[[], [1], [1], [1]]
<strong>Output</strong>
[null, null, null, false]

<strong>Explanation</strong>
FrequencyTracker frequencyTracker = new FrequencyTracker();
frequencyTracker.add(1); // The data structure now contains [1]
frequencyTracker.deleteOne(1); // The data structure becomes empty []
frequencyTracker.hasFrequency(1); // Returns false, because the data structure is empty

</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input</strong>
[&quot;FrequencyTracker&quot;, &quot;hasFrequency&quot;, &quot;add&quot;, &quot;hasFrequency&quot;]
[[], [2], [3], [1]]
<strong>Output</strong>
[null, false, null, true]

<strong>Explanation</strong>
FrequencyTracker frequencyTracker = new FrequencyTracker();
frequencyTracker.hasFrequency(2); // Returns false, because the data structure is empty
frequencyTracker.add(3); // The data structure now contains [3]
frequencyTracker.hasFrequency(1); // Returns true, because 3 occurs once

</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= number &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= frequency &lt;= 10<sup>5</sup></code></li>
	<li>At most, <code>2 *&nbsp;10<sup>5</sup></code>&nbsp;calls will be made to <code>add</code>, <code>deleteOne</code>, and <code>hasFrequency</code>&nbsp;in <strong>total</strong>.</li>
</ul>

# Solution:
# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
One possible implementation of the FrequencyTracker class is to keep track of the frequency of each number in a hash map (`freq`) and the set of numbers that have a particular frequency in another hash map (`freqIndex`).

# Approach
<!-- Describe your approach to solving the problem. -->
- The `add` method updates the frequency of the given number in the freq hash map, removes the number from the set of numbers with the old frequency in the freqIndex hash map, and adds it to the set of numbers with the new frequency in the freqIndex hash map.

- The `deleteOne` method first checks if the given number is present in the freq hash map. If it is, it updates the frequency of the number in the freq hash map, removes the number from the set of numbers with the old frequency in the freqIndex hash map, and adds it to the set of numbers with the new frequency (if its frequency is still positive) in the freqIndex hash map. If the frequency of the number becomes zero, it is removed from the freq hash map.

- The `hasFrequency` method checks if the given frequency exists as a key in the freqIndex hash map and whether the corresponding set of numbers is not empty.

## Naive Approach
My first approach to this problem was different where I used `unordered_map` to keep track of the frequencies of the values added to it. 
This would take me $$O(n)$$ for `add` method and `hasFequency` method because: 
- for `add` method ($O(1)$ in the average case and $O(n)$ in the worst case if all the elements are unique). 
- for `hasFrequency` method as it was iterating through the key-value pairs of the nums map using a range-based for loop and checks if any value (frequency) matches the given frequency.

Hence, this solution gave me *TLE*.

# Complexity
- Time complexity:
  For the `add` method, the time complexity is $$O(1)$$ since it involves updating the frequency of the given number in the freq hash map, removing the number from the set of numbers with the old frequency, and adding it to the set of numbers with the new frequency. The space complexity is also O(1) since we only store the frequency of the number and the sets of numbers with different frequencies.

  For the `deleteOne` method, the time complexity is $$O(1)$$ since it involves updating the frequency of the given number in the freq hash map, removing the number from the set of numbers with the old frequency, and adding it to the set of numbers with the new frequency (if its frequency is still positive). The space complexity is also O(1) since we only store the frequency of the number and the sets of numbers with different frequencies.

  For the `hasFrequency` method, the time complexity is $$O(1)$$ since it involves checking if the given frequency exists as a key in the freqIndex hash map and whether the corresponding set of numbers is not empty.
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity:
  $$O(n)$$ where n is the number of distinct values added to the data structure. 
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
 {% highlight cpp %} 
class FrequencyTracker {
private:
    unordered_map<int, int> freq;
    unordered_map<int, unordered_set<int>> freqIndex;
public:
    FrequencyTracker() {}
    void add(int number) {
        freqIndex[freq[number]].erase(number);
        freq[number]++;
        freqIndex[freq[number]].insert(number);
    }
    void deleteOne(int number) {
        if (freq.count(number) > 0) {
            freqIndex[freq[number]].erase(number); 
            freq[number]--;
            if (freq[number] > 0) {
                freqIndex[freq[number]].insert(number);
            } else { 
                freq.erase(number);
            }
        }
    }
    bool hasFrequency(int frequency) {
        return freqIndex.count(frequency) > 0 && !freqIndex[frequency].empty();
    }
};
 {% endhighlight %}