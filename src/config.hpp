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
    -40,-40,-40,-40,-50,
    -30,-30,-30,-30,-40,
    -20,-20,-20,-20,-30,
    -10,-10,-10,-10,-20,
     10, 10, 20, 10, 0,
     10, 20, 20, 10, 0
};

const int wQueenTableMid[BOARD_H][BOARD_W] = {
    -10, -5, -5,-10,-20,
    -10,  0,  0,  0,-10,
     -5,  5,  5,  5,  5,
      0,  5,  5,  5,  5,
    -10,  0,  0,  0,  0,
    -20,-10,-10, -5,-10
};

const int wRookTableMid[BOARD_H][BOARD_W] = {
      5, 10, 10, 10, 10, 
     -5,  0,  0,  0,  0, 
     -5,  0,  0,  0,  0, 
     -5,  0,  0,  0,  0, 
     -5,  0,  0,  0,  0, 
      0,  0,  5,  5,  5, 
};

const int wBishopTableMid[BOARD_H][BOARD_W] = {
    -20,-10,-10,-10,-20,
    -10,  0,  0,  0,-10,
    -10,  5,  5,  5,-10,
    -10, 10, 10, 10,-10,
    -10,  5,  0,  5,-10,
    -20,-10,  0,-10,-20,
};

const int wKnightTableMid[BOARD_H][BOARD_W] = {
    -50,-40,-30,-40,-50,
    -40,-20,  0,-20,-40,
    -30,  0, 10,  0,-30,
    -30,  5, 10,  5,-30,
    -40,-20,  0,-20,-40,
    -50,-40,-30,-40,-50
};

const int wPawnTableMid[BOARD_H][BOARD_W] = {
    50, 50, 50, 50, 50,
    10, 20, 30, 20, 10,
     5, 10, 25, 10,  5,
     5, 10, 25, 10,  5,
     0,  0,  0,  0,  0,
   -20,-20,-20,-20,-20,
};


// Black's Piece-Square Tables
const int bKingTableMid[BOARD_H][BOARD_W] = {
      0, 10, 20, 20, 10,
      0, 10, 20, 10, 10,
    -20,-10,-10,-10,-10,
    -30,-20,-20,-20,-20,
    -40,-30,-30,-30,-30,
    -50,-40,-40,-40,-40
};

const int bQueenTableMid[BOARD_H][BOARD_W] = {
    -10, -5, -5,-10,-20,
    -10,  0,  0,  0,-10,
     -5,  5,  5,  5,  5,
      0,  5,  5,  5,  5,
    -10,  0,  0,  0,  0,
    -20,-10,-10, -5,-10
};

const int bRookTableMid[BOARD_H][BOARD_W] = {
      5,  5,  5,  0,  0, 
      0,  0,  0,  0, -5, 
      0,  0,  0,  0, -5, 
      0,  0,  0,  0, -5, 
      0,  0,  0,  0, -5, 
     10, 10, 10, 10,  5, 
};

const int bBishopTableMid[BOARD_H][BOARD_W] = {
    -20,-10,  0,-10,-20,
    -10,  5,  0,  5,-10,
    -10, 10, 10, 10,-10,
    -10,  5,  5,  5,-10,
    -10,  0,  0,  0,-10,
    -20,-10,-10,-10,-20,
};

const int bKnightTableMid[BOARD_H][BOARD_W] = {
    -50,-40,-30,-40,-50,
    -40,-20,  0,-20,-40,
    -30,  5, 10,  5,-30,
    -30,  0, 10,  0,-30,
    -40,-20,  0,-20,-40,
    -50,-40,-30,-40,-50
};

const int bPawnTableMid[BOARD_H][BOARD_W] = {
   -20,-20,-20,-20,-20,
     0,  0,  0,  0,  0,
     5, 10, 25, 10,  5,
     5, 10, 25, 10,  5,
    10, 20, 30, 20, 10,
    50, 50, 50, 50, 50,
};