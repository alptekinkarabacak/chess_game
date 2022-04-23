//
// Created by Alptekin's Macbook on 15.04.2022.
//

#ifndef CHESSGAME_PIECE_KING_H
#define CHESSGAME_PIECE_KING_H

#include "peace_interface.h"

class PieceKing : public PieceInterface {
public:
    int m_points{100};
    int m_position_x{0};
    int m_position_y{0};
    bool m_cross_move{false};
    bool m_straight_move{true};
    bool m_special_pawn_move{false};
    bool m_special_knight_move{false};
    int m_max_move_count_x{1};
    int m_max_move_count_y{1};
    Colour m_piece_colour;
    static constexpr int max_number_of_count = 2;
    std::vector<std::shared_ptr<MoveSet>> m_piece_moves;
    void createMoves() override;

};


#endif //CHESSGAME_PIECE_KING_H
