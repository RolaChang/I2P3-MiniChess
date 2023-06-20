#pragma once

/*Board Size, Don't change!*/
#define BOARD_H 6
#define BOARD_W 5

/*You can modify these things in development for fast testing*/
/*When TA run your program, we will use default settings (123, 10, 50)*/
#define RANDOM_SEED 123
#define timeout 10
#define MAX_STEP 50


/*Which character/words for pieces*/
/* By default, the pieces are '♟', '♜', '♞', '♝', '♛', '♚' from unicode*/
// #define PIECE_STR_LEN 1
// const char piece_table[2][7][5] = {
//   {" ", "♟", "♜", "♞", "♝", "♛", "♚"},
//   {" ", "♙", "♖", "♘", "♗", "♕", "♔"},
// };
// k for knight, K for King
#define PIECE_STR_LEN 2
const char PIECE_TABLE[2][7][5] = {
  {"  ", "wP", "wR", "wk", "wB", "wQ", "wK"},
  {"  ", "bP", "bR", "bk", "bB", "bQ", "bK"},
};

// White's Piece-Square Tables
const int wKingTableMid[BOARD_H][BOARD_W] = {
     -21, -26, -26, -31, -31 ,
     -21, -26, -26, -31, -31 ,
     -21, -26, -26, -31, -31 ,
     -21, -11,   0, -11, -21 ,
     -16,   0,   4,   0, -16 ,
     -16,   0,   1,   0, -16 
};

const int wQueenTableMid[BOARD_H][BOARD_W] = {
     -26, -10,  0, -16, -26 ,
     -16,   0,  0,   0, -16 ,
       0,   0, 10,   0,   0 ,
     -16,   0,  0,   0, -16 ,
     -26, -16,  0, -16, -26 ,
     -36, -26,-16, -26, -36 
};
const int wRookTableMid[BOARD_H][BOARD_W] = {
       0,   0,   0,   0,   0 ,
       1,   4,   4,   4,   1 ,
     -11,   0,   0,   0, -11 ,
     -11,   0,   0,   0, -11 ,
     -11,   0,   0,   0, -11 ,
       0,   0,   0,   0,   0 
};
const int wBishopTableMid[BOARD_H][BOARD_W] = {
     -16, -11, -11, -11, -16 ,
     -11,   0,   0,   0, -11 ,
     -11,   0,   0,   0, -11 ,
     -11,   0,   0,   0, -11 ,
     -16, -11, -11, -11, -16 ,
       0,   0,   0,   0,   0 
};
const int wKnightTableMid[BOARD_H][BOARD_W] = {
     -16,  14, -12, -14, -16 ,
     -14, -10,   0, -10, -14 ,
     -12,   0,   1,   0, -12 ,
     -14, -10,   0, -10, -14 ,
     -16, -14, -12, -14, -16 ,
     -18, -14, -12, -14, -18 
};

const int wPawnTableMid[BOARD_H][BOARD_W] = {
       0,   0,   0,   0,   0 ,
     -10,  -8,  -8,   2,   2 ,
     -10,  -8, -14,   1,   1 ,
     -14, -12, -14,   4,   1 ,
     -16, -16, -16,   2,   8 ,
       0,   0,   0,   0,   0 
};

// Black's Piece-Square Tables
const int bKingTableMid[BOARD_H][BOARD_W] = {   
     -16,   0,   1,   0, -16 ,
     -16,   0,   4,   0, -16 ,
     -21, -11,   0, -11, -21 ,
     -21, -26, -26, -31, -31 ,
     -21, -26, -26, -31, -31 ,
     -21, -26, -26, -31, -31 
};

const int bQueenTableMid[BOARD_H][BOARD_W] = {
     -26, -21, -16, -11,   0 ,
     -21, -16, -11,   0,   1 ,
     -16, -11,   0,   1,   4 ,
     -11,   0,   1,   4,   9 ,
       0,   1,   4,   9,  14 ,
       1,   4,   9,  14,  18 
};
const int bRookTableMid[BOARD_H][BOARD_W] = {
       0,   0,   0,   0,   0 ,
     -11,   0,   0,   0, -11 ,
     -11,   0,   0,   0, -11 ,
     -11,   0,   0,   0, -11 ,
       1,   4,   4,   4,   1 ,
       0,   0,   0,   0,   0 
};
const int bBishopTableMid[BOARD_H][BOARD_W] = {
     -16, -11, -11, -11, -16 ,
     -11,   0,   0,   0, -11 ,
     -11,   0,   0,   0, -11 ,
     -11,   0,   0,   0, -11 ,
     -16, -11, -11, -11, -16 ,
       0,   0,   0,   0,   0 
};
const int bKnightTableMid[BOARD_H][BOARD_W] = {
     -18, -14, -12, -14, -18 ,
     -16, -14, -12, -14, -16 ,  
     -14, -10,   0, -10, -14 ,
     -12,   0,   1,   0, -12 ,
     -14, -10,   0, -10, -14 ,
     -16, -14, -12, -14, -16 
};
const int bPawnTableMid[BOARD_H][BOARD_W] = {
       0,   0,   0,   0,   0 ,
     -16, -16, -16,   2,   8 ,
     -14, -12, -14,   4,   1 ,
     -10,  -8, -14,   1,   1 ,
     -10,  -8,  -8,   2,   2 ,
       0,   0,   0,   0,   0 
};