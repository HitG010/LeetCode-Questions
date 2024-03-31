# 2444. Count Subarrays With Fixed Bounds

## Hard

You are given an integer array `nums` and two integers `minK` and `maxK`.

A **fixed-bound subarray** of `nums` is a subarray that satisfies the following conditions:

- The **minimum** value in the subarray is equal to `minK`.

- The **maximum** value in the subarray is equal to `maxK`.

Return _the **number** of fixed-bound subarrays_.

A **subarray** is a **contiguous** part of an array.

## Example 1:

Input:`nums = [1,3,5,2,7,5], minK = 1, maxK = 5`

Output: `2`

**Explanation**: The fixed-bound subarrays are [1,3,5] and [1,3,5,2].

## Example 2:

Input: `nums = [1,1,1,1], minK = 1, maxK = 1`

Output: `10`

**Explanation**: Every subarray of nums is a fixed-bound subarray. There are 10 possible subarrays.

## Constraints:

- `2 <= nums.length <= 10`<sup>`5`</sup>`

- `1 <= nums[i], minK, maxK <= 10`<sup>`6`</sup>

# DETAILED SOLUTION

# Intuition

- As we need contignous subarray, **sliding window** may be used to reduce complexity.

- We need two sliding windows, one which is of **max lengt**h which contains both `maxK` and `minK` and other which is of **min length** and contains both too.

# Approach

- Initialize `ans = 0`, `start = 0`, `minInd = -1` and `maxInd = -1` assuming they are both not present in the current sliding window

- Initialise `end = 0` and iterate over the size of nums.

- Whenever `nums[end]` is out of range of both `maxK` and `minK` is encountered, it implies the current window is invalid as the `end` is out of range, hence we set `start = end + 1`, `minInd = -1` and `maxInd = -1` which makes the window reinitialize

- Now if `nums[end]` **is equal to** `minK` we store its index to `minInd`

- Similarly if `nums[end]` **is equal to** `maxK` we store its index to `maxInd`

- This helps us to save the last occurances of the `minK` and `maxK` elements in the current window as our subarray must contain both of them.

- `Start` variable marks the **largest window** with all elements in range of `minK` and `maxK`

- Now if both `minInd` and `maxInd` are **not equal** to `-1`, it means that the current sliding window is **valid** as it contains both of them.

- To calculate the no of subarrays in the current sliding window which contains `nums[end]` and `minK` and `maxK` too. We take the **lower index** of `minInd` and `maxInd` because after that either `minK` or `maxK` will be missing.
  Hence increment `ans+=min(minInd, maxInd) - start + 1`

Eg :

```
[1, 2, 3, 1, 4, 5, 3, 6], minK = 1,  maxK = 5
Assume end reaches index = 5 and start will be 0
minInd = 3 and maxInd = 5
No of subarrays = 3 - 0 + 1 = 4
[1,2,3,1,4,5]
[2,3,1,4,5]
[3,1,4,5]
[1,4,5]

```

# Complexity

- Time complexity:
  $$O(n)$$

- Space complexity:
  $$O(1)$$
