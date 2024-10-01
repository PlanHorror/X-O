#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "game.cpp"
using namespace std;
int main() {
    int choice;
    std::cout << "Enter \n1 for 3x3 and \n2 for 5x5\n3 for 7x7\n4 for 9x9\n5 for 11x11:\n ";
        while (true) {
        cin >> choice;

        // Check if cin failed to extract a valid integer or if there are leftover characters
        if (cin.fail() || cin.peek() != '\n'|| choice <= 1 || choice > 5) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid integer. Please enter a valid integer: ";
        } else {
            break; // Valid input
        }
    }
    int row, col;
    Game game {choice*2+1};
    Board board {choice*2+1};
    PlayerX player_x;
    PlayerO player_o;
    while (game.is_started && !game.is_finished) {
        board.print_board();
        if (game.turn % 2 == 0) {
            std::cout << "Player X turn: " << std::endl;
            std::cout << "Enter row and column: ";
            cin >> row >> col;
            player_x.set_move(row, col);
            board.make_move(row, col, 1);
            game.turn++;
            game.end(board);
        } else {
            std::cout << "Player O turn: " << std::endl;
            std::cout << "Enter row and column: ";
            cin >> row >> col;
            player_o.set_move(row, col);
            board.make_move(row, col, -1);
            game.turn++;
            game.end(board);
        }
    }
    if (game.w_l_or_d) {
        if (game.winner == 1) {
            std::cout << "Player X wins!" << std::endl;
        } else {
            std::cout << "Player O wins!" << std::endl;
        }
    } else {
        std::cout << "Draw!" << std::endl;
    };

    
    return 0;
}