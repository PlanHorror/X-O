#ifndef PLAYER_O_H
#define PLAYER_O_H

#include <vector>
class PlayerO{
public:
    bool win;
    std::vector<std::vector<int>> moves;
    int val;
    void set_move(int row, int col) {
        std::vector<int> move_address(2);
        move_address[0] = row;
        move_address[1] = col;
        moves.push_back(move_address);
        
    }
    void set_win(bool w) {
        win = w;
    }
    PlayerO() {
        win = false;
        
        moves = {};
        val = -1;
    }
};

#endif // PLAYER_O_H