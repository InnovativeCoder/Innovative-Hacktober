/*
LeetCode Problem - 108. Convert Sorted Array to Binary Search Tree

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5

*/

/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {number[]} nums
 * @return {TreeNode}
 */
var sortedArrayToBST = function(nums) {
  if(nums === null || nums.length === 0) {
    return null;
  }
  
  return createBSTRecursive(nums, 0, nums.length - 1);
};

var createBSTRecursive = function(nums, left, right) {
  if(left > right) {
		return null;
  }
  
  let mid = Math.ceil((left + right) / 2);
  
  const current = new TreeNode(nums[mid]);
  
  current.left = createBSTRecursive(nums, left, mid - 1);
  current.right = createBSTRecursive(nums, mid + 1, right);
  return current;
}