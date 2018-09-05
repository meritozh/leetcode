/**
 * Description:
 *
 * Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules
 * http://sudoku.com.au/TheRules.aspx
 *
 * The Sudoku board could be partially filled, where empty cells are filled with
 * the character '.'.
 */

/**
 * Analyze:
 *
 * Just valid, doesn't mean can be resolved.
 */

#include <array>
#include <vector>
#include <cassert>

class Solution {
private:
  bool Check(char E, std::array<bool, 9> &Used) {
    if (E == '.') {
      return true;
    }
    if (Used[E - '1']) {
      return false;
    }
    Used[E - '1'] = true;
    return true;
  }

public:
  bool IsValidSudoku(const std::vector<std::vector<char>> &Board) {
    std::array<bool, 9> Used;

    // Check row
    for (int Row = 0, MaxRow = 9; Row < MaxRow; ++Row) {
      Used.fill(false);
      for (int Column = 0, MaxColumn = 9; Column < MaxColumn; ++Column) {
        auto E = Board[Row][Column];
        if (!Check(E, Used)) {
          return false;
        }
      }
    }

    // Check column
    for (int Column = 0, MaxColumn = 9; Column < MaxColumn; ++Column) {
      Used.fill(false);
      for (int Row = 0, MaxRow = 9; Row < MaxRow; ++Row) {
        auto E = Board[Row][Column];
        if (!Check(E, Used)) {
          return false;
        }
      }
    }

    // Check box
    for (int BoxIdx = 0, MaxBoxIdx = 9; BoxIdx < MaxBoxIdx; ++BoxIdx) {
      Used.fill(false);
      for (int BoxRow = 0, MaxBoxRow = 3; BoxRow < MaxBoxRow; ++BoxRow) {
        for (int BoxColumn = 0, MaxBoxColumn = 3; BoxColumn < MaxBoxColumn;
             ++BoxColumn) {
          auto E = Board[BoxIdx / 3 * 3 + BoxRow][BoxIdx % 3 * 3 + BoxColumn];
          if (!Check(E, Used)) {
            return false;
          }
        }
      }
    }

    return true;
  }
};

int main() {
  std::vector<std::vector<char>> In = {
    {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
    {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
  };
  assert(Solution().IsValidSudoku(In) == true);

  return 0;
}