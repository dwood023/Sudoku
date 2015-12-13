# Sudoku

Generates Sudoku boards of any size, will work out best block size from greatest factors of
the boards length.

Generation avoids validating every placement by placing numbers from a managed available
pool for each row, column and block.

TODO -- 

- Generation is currently pretty slow despite not validating every cell - the architecture needs abstracting to increase efficiency and readability

- Remove numbers to start game

- Presentation

- With large boards (12+ size), generation is still possible, but currently very unlikely within any
  reasonable period of time, when generation gets stuck many times in a row, it currently restarts
  the whole board, ideally, as much of the board will be kept as possible in future.




