//
// Created by Alptekin's Macbook on 15.04.2022.
//

#include "piece_queen.h"

void PieceQueen::createMoves() {
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
    std::shared_ptr<MoveSet> moveSet5 = std::make_shared<MoveSet>();
    moveSet5->right = 8;
    moveSet5->left = 0;
    moveSet5->forward = 8;
    moveSet5->backward = 0;
    m_piece_moves.push_back(moveSet5);
    std::shared_ptr<MoveSet> moveSet6 = std::make_shared<MoveSet>();
    moveSet6->right = 0;
    moveSet6->left = 8;
    moveSet6->forward = 8;
    moveSet6->backward = 0;
    m_piece_moves.push_back(moveSet6);
    std::shared_ptr<MoveSet> moveSet7 = std::make_shared<MoveSet>();
    moveSet7->right = 8;
    moveSet7->left = 0;
    moveSet7->forward = 0;
    moveSet7->backward = 8;
    m_piece_moves.push_back(moveSet7);
    std::shared_ptr<MoveSet> moveSet8 = std::make_shared<MoveSet>();
    moveSet8->right = 0;
    moveSet8->left = 8;
    moveSet8->forward = 0;
    moveSet8->backward = 8;
    m_piece_moves.push_back(moveSet8);
}
