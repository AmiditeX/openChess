#include <iostream>
#include "Board.h"

Board g_board;

/// <summary> </summary>
/// <param name="b"> - the chess board object </param>
/// <returns> why the game ended. 1 = checkmate, 2 = no moves left, 3 = not enough material, TODO add more</returns>
uint8_t gameOver(const Board& b)
{

    return 0;
}

int main()
{
    std::string col;
    std::cout << "Pick your color (w / b): ";
    std::cin >> col;
    g_board.setPlayingAsWhite(col[0] == 'w');

    uint8_t gameStatus;
    while (gameStatus = gameOver(g_board) == 0)
    {
        std::cout << g_board << '\n';

        Move move;
        do
        {
            std::string plyMoveSrc, plyMoveDest;
            std::cout << "Enter valid move for " << (g_board.whitesTurn() ? "white" : "black") << " (src_square dest_square):";
            std::cin >> plyMoveSrc >> plyMoveDest;

            move = Move::getMove(plyMoveSrc, plyMoveDest);
            move.setIntention(g_board.findIntention(move));
        } while (!g_board.isValidMove(move));

        g_board.movePiece(move);
    }

    bool whiteWon = !g_board.whitesTurn();
    switch (gameStatus)
    {
    case 1:
        std::cout << "Checkmate! " << (whiteWon ? "white" : "black") << " won!\n";
        break;
    case 2:
        std::cout << "Stalemate! No moves left for " << (!whiteWon ? "white" : "black") << '\n';
        break;
    case 3:
        std::cout << "Stalemate due to lack of material\n";
        break;
    default:
        std::cout << "Game ended because of unknown cause\n";
        break;
    }
}
