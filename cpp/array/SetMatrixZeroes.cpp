/**
 * Description:
 *
 * Given a `m x n` matrix, if an element is 0, set its entire row and column to
 * 0. Do it in place.
 *
 * __Follow up__: Did you use extra space?
 *
 * A straight forward solution using O(mn) space is probably a bad idea.
 *
 * A simple improvement uses O(m + n) space, but still not the best solution.
 *
 * Could you devise a constant space solution?
 */

#include <cassert>
#include <vector>

class Solution {
public:
  void SetMatrixZeroes(std::vector<std::vector<int>> &Matrix) {
    auto RowHasZero = false;
    auto ColumnHasZero = false;

    // First row
    for (int J = 0, ColumnMax = Matrix[0].size(); J < ColumnMax; ++J) {
      if (Matrix[0][J] == 0) {
        RowHasZero = true;
        break;
      }
    }

    // First column
    for (int I = 0, RowMax = Matrix.size(); I < RowMax; ++I) {
      if (Matrix[I][0] == 0) {
        ColumnHasZero = true;
        break;
      }
    }

    // x * *    x 0 *
    // * 0 * => 0 0 *
    // * * *    * * *
    for (int I = 1, RowMax = Matrix.size(); I < RowMax; ++I) {
      for (int J = 1, ColumnMax = Matrix[I].size(); J < ColumnMax; ++J) {
        if (Matrix[I][J] == 0) {
          Matrix[0][J] = 0;
          Matrix[I][0] = 0;
        }
      }
    }

    for (int I = 1, RowMax = Matrix.size(); I < RowMax; ++I) {
      for (int J = 1, ColumnMax = Matrix[I].size(); J < ColumnMax; ++J) {
        if (Matrix[I][0] == 0 || Matrix[0][J] == 0) {
          Matrix[I][J] = 0;
        }
      }
    }

    if (RowHasZero) {
      for (int J = 0, RowMax = Matrix.size(); J < RowMax; ++J) {
        Matrix[0][J] = 0;
      }
    }

    if (ColumnHasZero) {
      for (int I = 0, ColumnMax = Matrix[0].size(); I < ColumnMax; ++I) {
        Matrix[I][0] = 0;
      }
    }
  }
};

int main() {
  std::vector<std::vector<int>> In = {{2, 4, 7}, {2, 0, 8}, {4, 5, 9}};
  Solution().SetMatrixZeroes(In);
  assert(In ==
         std::vector<std::vector<int>>({{2, 0, 7}, {0, 0, 0}, {4, 0, 9}}));

  return 0;
}