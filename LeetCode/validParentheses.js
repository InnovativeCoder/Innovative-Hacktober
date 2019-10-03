/*
LeetCode Problem - 20. Valid Parentheses

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.

Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true

*/

/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
  const stack = [];
  
  for (let bracket of s) {
    if(bracket === "(" || bracket === "[" || bracket === "{") {
      stack.push(bracket);
      continue;
    }
    
    if (bracket === ")") {
      if(doesEnd(stack, "(")) {
        stack.pop();
      } else {
        return false
      }
    } else if (bracket === "]") {
      if(doesEnd(stack, "[")) {
        stack.pop();
      } else {
        return false
      }
    } else if (bracket === "}") {
      if(doesEnd(stack, "{")) {
        stack.pop();
      } else {
        return false
      }
    }
  }
  
  return stack.length === 0;
};

var doesEnd = function(stack, bracket) {
  return stack[stack.length - 1] === bracket;
}