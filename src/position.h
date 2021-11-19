#ifndef _POSITION_H_
#define _POSITION_H_
#include <iostream>
#include "piece.h"
#include "square.h"
#include "bitboard.h"

class Position {
  private:
    // There is one Bitboard for each piece type, plus one extra for all pawns
    Bitboard bbs[NUM_PIECES + 1];
    Piece squareList[BOARD_SQ_NUM];

  public:
    // Default constructor initializes the squareList
    Position();

    // placePiece puts the given piece on the given square
    // Requires: 
    //  * piece is not EMPTY or OFFBOARD
    //  * square is a valid square on the chess board
    void placePiece(Piece, Square);

    // removePiece removes and returns the piece on the given square
    // Requires:
    //  * square is a valid square on the chess board
    //  * the piece occupying the square is not EMPTY of OFFBOARD
    Piece removePiece(Square);

    // Prints the pieces on each valid square
    friend std::ostream &operator<<(std::ostream &, const Position &);
};

#endif
