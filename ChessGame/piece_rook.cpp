//
// Created by Alptekin's Macbook on 15.04.2022.
//

#include "piece_rook.h"

void PieceRook::createMoves() {
    std::shared_ptr<MoveSet> moveSet1 = std::make_shared<MoveSet>();
    moveSet1->right = 8;
    moveSet1->left = 0;
    moveSet1->forward = 0;
    moveSet1->backward = 0;
    m_piece_moves.push_back(moveSet1);
    std::shared_ptr<MoveSet> moveSet2 = std::make_shared<MoveSet>();
    moveSet2->right = 0;
    moveSet2->left = 8;
    moveSet2->forward = 0;
    moveSet2->backward = 0;
    m_piece_moves.push_back(moveSet2);
    std::shared_ptr<MoveSet> moveSet3 = std::make_shared<MoveSet>();
    moveSet3->right = 0;
    moveSet3->left = 0;
    moveSet3->forward = 8;
    moveSet3->backward = 0;
    m_piece_moves.push_back(moveSet3);
    std::shared_ptr<MoveSet> moveSet4 = std::make_shared<MoveSet>();
    moveSet4->right = 0;
    moveSet4->left = 0;
    moveSet4->forward = 0;
    moveSet4->backward = 8;
    m_piece_moves.push_back(moveSet4);
}

PieceRook::PieceRook(int position_x, int position_y, Colour piece_colour) :m_position_x(position_x), m_position_y(position_y) {
    m_points = 5;
    m_cross_move = false;
    m_straight_move = true;
    m_special_pawn_move = false;
    m_special_knight_move = false;
    m_max_move_count_x = 8;
    m_max_move_count_y = 8;

    int m_points{5};
    int m_position_x{0};
    int m_position_y{0};
    bool m_cross_move{false};
    bool m_straight_move{true};
    bool m_special_pawn_move{false};
    bool m_special_knight_move{false};
    int m_max_move_count_x{8};
    int m_max_move_count_y{8};

}
