# Sudoku

Generates Sudoku boards of any size, will work out best block size from greatest factors of
the boards length.

Generation avoids validating every placement by placing numbers from a managed available
pool for each row, column and block.

###TODO

- Generation is faster than it used to be (~1sec for <11 size), but still can't deal with sizes >11, it may be the inherent complexity of the problem is prohibative of large boards, or there may still be significant improvements to make this possible

- Presentation, might be easier to do in sfml over console based





