/**
 * Description:
 *
 * According to the Wikipedia's article: "The Game of Life, also known simply
 * as Life, is a cellular automaton devised by the British mathematician John
 * Horton Conway in 1970."
 *
 * Given a board with `m` by `n` cells, each cell has an initial state live (1)
 * or dead (0). Each cell interacts with its eight neighbors (horizontal,
 * vertical, diagonal) using the following four rules (taken from the above
 * Wikipedia article):
 *
 * 1. Any live cell with fewer than two live neighbors dies, as if caused by
 *    under-population.
 * 2. Any live cell with two or three live neighbors lives on to the next
 *    generation.
 * 3. Any live cell with more than three live neighbors dies, as if by
 *    over-population..
 * 4. Any dead cell with exactly three live neighbors becomes a live cell, as
 *    if by reproduction.
 *
 * Write a function to compute the next state (after one update) of the board
 * given its current state.
 *
 * Follow up:
 *
 * Could you solve it in-place? Remember that the board needs to be updated at
 * the same time: You cannot update some cells first and then use their updated
 * values to update other cells.
 *
 * In this question, we represent the board using a 2D array. In principle, the
 * board is infinite, which would cause problems when the active area
 * encroaches the border of the array. How would you address these problems?
 */

#include <vector>

class Solution {
private:
  enum CellType {
    CT_DeadToDead = -1,
    CT_DeadToLive = 0,
    CT_LiveToLive = 1,
    CT_LiveToDead = 2,
  };

  void CheckCellType(std::vector<std::vector<int>> &Board, int I, int J) {
    int LiveCount = 0;

    int MinRow = I - 1 < 0 ? 0 : I - 1;
    int MaxRow = I + 1 == Board.size() ? I : I + 1;
    int MinColumn = J - 1 < 0 ? 0 : J - 1;
    int MaxColumn = J + 1 == Board[I].size() ? J : J + 1;

    for (auto Row = MinRow; Row <= MaxRow; ++Row) {
      for (auto Column = MinColumn; Column <= MaxColumn; ++Column) {
        if (Row == I && Column == J) {
          continue;
        }
        if (Board[Row][Column] >= 1) {
          ++LiveCount;
        }
      }
      if (Board[I][J] >= 1) {
        if (LiveCount < 2 || LiveCount > 3) {
          Board[I][J] = CT_LiveToDead;
        } else {
          Board[I][J] = CT_LiveToLive;
        }
      } else {
        if (LiveCount == 3) {
          Board[I][J] = CT_DeadToLive;
        } else {
          Board[I][J] = CT_DeadToDead;
        }
      }
    }
  }

public:
  void GameOfLife(std::vector<std::vector<int>> &Board) {
    for (int I = 0, MaxI = Board.size(); I < MaxI; ++I) {
      for (int J = 0, MaxJ = Board[I].size(); J < MaxJ; ++J) {
        CheckCellType(Board, I, J);
      }
    }

    for (int I = 0, MaxI = Board.size(); I < MaxI; ++I) {
      for (int J = 0, MaxJ = Board[I].size(); J < MaxJ; ++J) {
        int CT = Board[I][J];
        if (CT == -1 || CT == 2) {
          Board[I][J] = 0;
        } else {
          Board[I][J] = 1;
        }
      }
    }
  }
};

int main() {
  std::vector<std::vector<int>> In = {
    {1, 0, 1, 1},
    {1, 0, 0, 0},
    {0, 1, 1, 1},
  };
  Solution().GameOfLife(In);
  auto R = In == std::vector<std::vector<int>>({
    {0, 1, 0, 0},
    {1, 0, 0, 0},
    {0, 1, 1, 0},
  });
  assert(R == true);

  return 0;
}