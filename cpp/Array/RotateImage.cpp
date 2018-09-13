/**
 * Description:
 *
 * You are given an `n x n` 2D matrix representing an image.
 *
 * Rotate the image by 90 degrees (clockwise).
 * Follow up: Could you do this in-place?
 *
 */

#include <cassert>
#include <vector>

class Solution {
public:
  void RotateImage(std::vector<std::vector<int>> &Matrix) {
    const int N = Matrix.size();

    for (int I = 0; I < N; ++I) {
      for (int J = 0; J < N - I; ++J) {
        std::swap(Matrix[I][J], Matrix[N - 1 - J][N - 1 - I]);
      }
    }

    for (int I = 0; I < N / 2; ++I) {
      for (int J = 0; J < N; ++J) {
        std::swap(Matrix[I][J], Matrix[N - 1 - I][J]);
      }
    }
  }
};

int main() {
  std::vector<std::vector<int>> In = {{1, 3, 5}, {2, 4, 6}, {10, 8, 5}};
  Solution().RotateImage(In);
  assert(In ==
         std::vector<std::vector<int>>({{10, 2, 1}, {8, 4, 3}, {5, 6, 5}}));

  return 0;
}