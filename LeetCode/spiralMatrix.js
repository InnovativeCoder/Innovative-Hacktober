/*
LeetCode Problem - 54. Spiral Matrix

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

*/

/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function(matrix) {
  const values = [];
  
  if(matrix === null || matrix.length === 0) {
    return values;
  }

  let startRow = 0, startColumn = 0;
  let endRow = matrix.length - 1, endColumn = matrix[0].length - 1;

  while(startRow <= endRow && startColumn <= endColumn) {
    for(let i = startColumn; i <= endColumn; i++) {
      values.push(matrix[startRow][i])
    }
    startRow++;
    
    for(let i = startRow; i <= endRow; i++) {
      values.push(matrix[i][endColumn])
    }
    endColumn--;
    
    if(startRow <= endRow) {
      for(let i = endColumn; i >= startColumn; i--) {
        values.push(matrix[endRow][i])
      }
      endRow--;   
    }
    
    if(startColumn <= endColumn) {
      for(let i = endRow; i >= startRow; i--) {
        values.push(matrix[i][startColumn])
      }
      startColumn++;    
    }
      
  }
  return values;
};
