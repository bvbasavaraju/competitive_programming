#include<iostream>
#include<vector>

using namespace std;

class SudokuSolverT
{
  private:
    bool solved;
    vector< vector<uint32_t> > grid;

    bool IsUnique(vector<uint32_t>& num_freq, uint32_t num)
    {
      if(num == 0)
      {
        return true;
      }
      num_freq[num]++;
      return (num_freq[num] == 1);
    }

    bool IsValid(uint32_t row, uint32_t col)
    {
      { //Check for row
        vector<uint32_t> num_freq(10, 0);
        vector<uint32_t>& row_vals = grid[row];
        for(uint32_t num : row_vals)
        {
          if(!IsUnique(num_freq, num))
          {
            return false;
          }
        }
      }

      { //Check for column
        vector<uint32_t> num_freq(10, 0);
        for(uint32_t i = 0U; i < 9U; ++i)
        {
          if(!IsUnique(num_freq, grid[i][col]))
          {
            return false;
          }
        }
      }

      { // check for 3X3 grid
        uint32_t row_start = (row < 3U) ? 0U : ( (row < 6U) ? 3U : 6U);
        uint32_t col_start = (col < 3U) ? 0U : ( (col < 6U) ? 3U : 6U);

        vector<uint32_t> num_freq(10, 0);
        for(uint32_t i = row_start ; i < (row_start + 3U); ++i)
        {
          for(uint32_t j = col_start; j < (col_start + 3U); ++j)
          {
            if(!IsUnique(num_freq, grid[i][j]))
            {
              return false;
            }
          }
        }
      }

      return true;
    }

    bool SolveGrid(uint32_t row, uint32_t col)
    {
      if(row >= 9)
      {
        return true;
      }

      if(col >= 9)
      {
        return SolveGrid(row+1, 0);
      }

      if(grid[row][col] != 0)
      {
        return SolveGrid(row, col+1);
      }

      for(uint32_t v = 1U; v <= 9U; ++v)
      {
        grid[row][col] = v;
        if(IsValid(row, col))
        {
          if(SolveGrid(row, col+1))
          {
            return true;
          }
        }
      }

      grid[row][col] = 0;
      return false;
    }

  public:
    SudokuSolverT()
    : solved(false)
    {
      for(uint32_t i = 0U; i < 9U; ++i)
      {
        grid.push_back({0,0,0,0,0,0,0,0,0});
      }
    }

    bool FillGrid(const vector<vector<uint32_t> >& grid_)
    {
      for(uint32_t i = 0U; i < 9U; ++i)
      {
        for(uint32_t j = 0U; j < 9U; ++j)
        {
          if(!IsValid(i, j))
          {
            return false;
          }

          if(grid_[i][j] != 0)
          {
            grid[i][j] = grid_[i][j];
          }
        }
      }

      return true;
    }

    void Solve(void)
    {
      if(SolveGrid(0, 0))
      {
        solved = true;
      }
    }

    bool Solved(void) const
    {
      return solved;
    }

    void PrintGrid(void)
    {
      for(uint32_t i = 0U; i < 9U; ++i)
      {
        if(i == 0U || i == 3U || i == 6U)
        {
          std::cout << "---------------------------------------" << endl;
        }

        for(uint32_t j = 0U; j < 9U; ++j)
        {
          if(j == 0U || j == 3U || j == 6U)
          {
            std :: cout << " | ";
          }

          if(grid[i][j] > 0)
          {
            std::cout << " " << grid[i][j] << " ";
          }
          else
          {
            std::cout << " . ";
          }
        }
        std::cout << " | " << endl;
      }

      std::cout << "---------------------------------------" << endl;
    }
};

void SolvePuzzle(const vector<vector<uint32_t> >& puzzle)
{
  SudokuSolverT sudokuSolver;
  if(!sudokuSolver.FillGrid(puzzle))
  {
    std::cout << "Given grid is not a valid Sudoku" << endl;
    return;
  }
  sudokuSolver.PrintGrid();
  
  sudokuSolver.Solve();
  if(sudokuSolver.Solved())
  {
    sudokuSolver.PrintGrid();
  }
  else
  {
    std::cout << "Could not solve the puzzle" << endl;
  }
}

int main()
{
  { //Puzzle 1;
    vector<vector<uint32_t> > puzzle = 
    {
      {5,3,0,0,7,0,0,0,0},
      {6,0,0,1,9,5,0,0,0},
      {0,9,8,0,0,0,0,6,0},
      {8,0,0,0,6,0,0,0,3},
      {4,0,0,8,0,3,0,0,1},
      {7,0,0,0,2,0,0,0,6},
      {0,6,0,0,0,0,2,8,0},
      {0,0,0,4,1,9,0,0,5},
      {0,0,0,0,8,0,0,7,9},
    };

    SolvePuzzle(puzzle);
  }
  
  // { //Puzzle 2
  //   vector<vector<uint32_t> > puzzle = 
  //   {
  //     {3,0,0,8,0,1,0,0,2},
  //     {2,0,1,0,3,0,6,0,4},
  //     {0,0,0,2,0,4,0,0,0},
  //     {8,0,9,0,0,0,1,0,6},
  //     {0,6,0,0,0,0,0,5,0},
  //     {7,0,2,0,0,0,4,0,9},
  //     {0,0,0,5,0,9,0,0,0},
  //     {9,0,4,0,8,0,7,0,5},
  //     {6,0,0,1,0,7,0,0,3}
  //   };

  //   SolvePuzzle(puzzle);
  // }
  
  // { //Puzzle 3 - Hard1
  //   vector<vector<uint32_t> > puzzle = 
  //   {
  //     {9,4,6,1,5,0,0,0,0},
  //     {0,0,0,0,0,0,7,0,0},
  //     {5,0,3,0,8,0,0,0,0},
  //     {0,0,4,9,2,0,0,0,0},
  //     {0,1,0,0,0,0,0,0,0},
  //     {0,0,0,0,0,0,0,7,8},
  //     {0,8,0,0,4,0,6,1,0},
  //     {0,0,0,0,0,0,0,5,7},
  //     {3,0,1,6,0,0,0,0,4}
  //   };

  //   SolvePuzzle(puzzle);
  // }

  // { //Puzzle 4 - Hard2
  //   vector<vector<uint32_t> > puzzle = 
  //   {
  //     {0,0,6,0,0,0,0,0,1},
  //     {0,3,0,0,0,0,8,0,0},
  //     {0,0,0,5,0,8,4,0,0},
  //     {0,6,0,0,1,0,0,2,0},
  //     {0,0,3,0,0,7,0,0,0},
  //     {0,9,1,0,0,0,3,0,0},
  //     {0,0,0,0,0,5,1,7,0},
  //     {1,5,0,0,2,6,0,0,0},
  //     {0,0,0,0,9,0,6,5,0}
  //   };

  //   SolvePuzzle(puzzle);
  // }

  // { //Puzzle 5 - Hard3
  //   vector<vector<uint32_t> > puzzle = 
  //   {
  //     {0,1,0,0,0,0,2,0,0},
  //     {0,0,0,8,3,1,0,0,0},
  //     {0,0,0,0,0,0,0,5,0},
  //     {0,0,0,1,0,7,9,0,0},
  //     {0,0,5,0,9,0,0,0,8},
  //     {0,9,0,0,0,0,0,0,3},
  //     {3,7,0,0,0,5,0,0,2},
  //     {4,0,9,7,6,0,0,0,0},
  //     {0,0,0,0,0,8,0,3,4}
  //   };

  //   SolvePuzzle(puzzle);
  // }

  // { //Puzzle 6 - Hard4
  //   vector<vector<uint32_t> > puzzle = 
  //   {
  //     {9,0,0,0,0,3,0,0,1},
  //     {0,0,0,0,0,0,0,0,0},
  //     {0,0,0,0,0,0,9,0,0},
  //     {0,7,0,8,0,0,0,0,0},
  //     {0,0,0,0,5,0,0,0,0},
  //     {0,0,0,0,0,6,0,7,0},
  //     {0,0,9,0,0,0,0,0,0},
  //     {0,0,0,0,0,0,0,0,0},
  //     {1,0,0,3,0,0,0,0,9}
  //   };

  //   SolvePuzzle(puzzle);
  // }

  return 0;
}