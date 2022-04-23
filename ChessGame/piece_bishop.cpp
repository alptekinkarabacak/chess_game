//
// Created by Alptekin's Macbook on 15.04.2022.
//

#include "piece_bishop.h"

void PieceBishop::createMoves() {
    std::shared_ptr<MoveSet> moveSet1 = std::make_shared<MoveSet>();
    moveSet1->right = 8;
    moveSet1->left = 0;
    moveSet1->forward = 8;
    moveSet1->backward = 0;
    m_piece_moves.push_back(moveSet1);
    std::shared_ptr<MoveSet> moveSet2 = std::make_shared<MoveSet>();
    moveSet2->right = 0;
    moveSet2->left = 0;
    moveSet2->forward = 0;
    moveSet2->backward = 8;
    m_piece_moves.push_back(moveSet2);
    std::shared_ptr<MoveSet> moveSet3 = std::make_shared<MoveSet>();
    moveSet3->right = 0;
    moveSet3->left = 8;
    moveSet3->forward = 8;
    moveSet3->backward = 0;
    m_piece_moves.push_back(moveSet3);
    std::shared_ptr<MoveSet> moveSet4 = std::make_shared<MoveSet>();
    moveSet4->right = 0;
    moveSet4->left = 8;
    moveSet4->forward = 0;
    moveSet4->backward = 8;
    m_piece_moves.push_back(moveSet4);
}
