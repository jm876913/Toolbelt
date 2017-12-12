//
//  checkers.cc
//  
//
//  Created by Michael Boyd on 4/8/15.
//
//

#include "colors.h"
#include "game.h"
#include "checkers.h"
#include "space.h"
#include <iostream>
#include <cstdlib>
#include <string>

namespace main_savitch_14
{    
    checkers::checkers()
    {
        num_red_pieces = 12;
        num_black_pieces = 12;
        //Fill black spaces
        int x = 0;
        int y = 0;
        while (x<7) {
            board[x][y].set_occ(true);
            board[x][y].set_black(true);
            x+=2;
        }
        x=y=1;
        while (x<8) {
            board[x][y].set_occ(true);
            board[x][y].set_black(true);
            x+=2;
        }
        x=0;
        y=2;
        while (x<7) {
            board[x][y].set_occ(true);
            board[x][y].set_black(true);
            x+=2;
        }
        
        //Fill red spaces
        x=1;
        y=5;
        while (x<8) {
            board[x][y].set_occ(true);
            board[x][y].set_red(true);
            x+=2;
        }
        x = 0;
        y = 6;
        while (x<7) {
            board[x][y].set_occ(true);
            board[x][y].set_red(true);
            x+=2;
        }
        x=1;
        y=7;
        while (x<8) {
            board[x][y].set_occ(true);
            board[x][y].set_red(true);
            x+=2;
        }
    }
    
    void checkers::restart()
    {
        //Fill black spaces
        int x = 0;
        int y = 0;
        while (x<7) {
            board[x][y].set_occ(true);
            board[x][y].set_black(true);
            x+=2;
        }
        x=y=1;
        while (x<8) {
            board[x][y].set_occ(true);
            board[x][y].set_black(true);
            x+=2;
        }
        x=0;
        y=2;
        while (x<7) {
            board[x][y].set_occ(true);
            board[x][y].set_black(true);
            x+=2;
        }
        
        //Fill red spaces
        x=1;
        y=5;
        while (x<8) {
            board[x][y].set_occ(true);
            board[x][y].set_red(true);
            x+=2;
        }
        x = 0;
        y = 6;
        while (x<7) {
            board[x][y].set_occ(true);
            board[x][y].set_red(true);
            x+=2;
        }
        x=1;
        y=7;
        while (x<8) {
            board[x][y].set_occ(true);
            board[x][y].set_red(true);
            x+=2;
        }
        game::restart();
    }
    
    void checkers::make_king(int& c2, int& r2)
    {
        if (board[c2][r2].is_red()){
            if (r2 == 0) {
                board[c2][r2].set_king(true);
            }
        }
        else if (board[c2][r2].is_black()) {
            if (r2 == 7) {
                board[c2][r2].set_king(true);
            }
        }
    }
    
    void checkers::count_pieces()
    {
        int reds = 0;
        int blacks = 0;
        
        for (int y = 0; y<8; y++) {
            for (int x = 0; x<8; x++) {
                if (board[x][y].is_red()) reds+=1;
                else if (board[x][y].is_black()) blacks +=1;
            }
        }
        num_red_pieces = reds;
        num_black_pieces = blacks;
    }
    
    //converts move from string into 4 ints that correspond to the coordinates on the board
    void checkers::convert_move(const std::string& move, int& c1, int& c2, int& r1, int& r2)const
    {
        string temp = move;
        c1 = temp[0] - 97;
        r1 = temp[1] - 49;
        c2 = temp[2] - 97;
        r2 = temp[3] - 49;
    }
    
    //checks if move is forward 1 space diagonally, or either direciton diagonally if king
    bool checkers::is_slide(int& c1, int& c2, int& r1, int& r2)const
    {
        //red non-king
        if (board[c1][r1].is_red() && !board[c1][r1].is_king()) {
            if ((c2 == c1-1) && (r2 == r1-1)) {
                return true;
            }
            else if ((c2 == c1+1) && (r2 == r1-1)) {
                return true;
            }
            else return false;
        }
        //black non-king
        else if (board[c1][r1].is_black() && !board[c1][r1].is_king()) {
            if ((c2 == c1-1) && (r2 == r1+1)) {
                return true;
            }
            else if ((c2 == c1+1) && (r2 == r1+1)) {
                return true;
            }
            else return false;
        }
        //red king
        else if (board[c1][r1].is_red() && board[c1][r1].is_king()) {
            if ((c2 == c1-1) && (r2 == r1-1)) {
                return true;
            }
            else if ((c2 == c1+1) && (r2 == r1-1)) {
                return true;
            }
            else if ((c2 == c1-1) && (r2 == r1+1)) {
                return true;
            }
            else if ((c2 == c1+1) && (r2 == r1+1)) {
                return true;
            }
            else return false;
        }
        //black king
        else if (board[c1][r1].is_black() && board[c1][r1].is_king()) {
            if (((c2 == c1-1) && (r2 == r1-1)) || ((c2 == c1+1) && (r2 == r1-1)) || ((c2 == c1-1) && (r2 == r1+1)) || ((c2 == c1+1) && (r2 == r1+1))) {
                return true;
            }
            else return false;
        }
        else return false;
    }
    
    bool checkers::is_jump(int& c1, int& c2, int& r1, int& r2)const
    {
        //similar to is_slide, but check for +-2 instead of +-1
        //and check that the space in between is occupied by a piece of the opposite color
        //no need to check for occupied destination, the is_legal fx will already have returned false
        
        int cmid, rmid;
        
        //red non-king
        if (board[c1][r1].is_red() && !board[c1][r1].is_king()) {
            if (((c2 == c1-2) && (r2 == r1-2))) {
                cmid = c1-1;
                rmid = r1-1;
                if (board[cmid][rmid].is_occ() && board[cmid][rmid].is_black()) {
                    return true;
                }
                else return false;
            }
            else if (((c2 == c1+2) && (r2 == r1-2))) {
                cmid = c1+1;
                rmid = r1-1;
                if (board[cmid][rmid].is_occ() && board[cmid][rmid].is_black()) {
                    return true;
                }
                else return false;
            }
        }
        //black non-king
        else if (board[c1][r1].is_black() && !board[c1][r1].is_king()) {
            if ((c2 == c1-2) && (r2 == r1+2)) {
                cmid = c1-1;
                rmid = r1+1;
                if (board[cmid][rmid].is_occ() && board[cmid][rmid].is_red()) {
                    return true;
                }
                else return false;
            }
           else if ((c2 == c1+2) && (r2 == r1+2)) {
                cmid = c1+1;
                rmid = r1+1;
                if (board[cmid][rmid].is_occ() && board[cmid][rmid].is_red()) {
                    return true;
                }
                else return false;
            }
            else return false;
        }
        //red king
        else if (board[c1][r1].is_red() && board[c1][r1].is_king()) {
            if ((c2 == c1-2) && (r2 == r1-2)) {
                cmid = c1-1;
                rmid = r1-1;
                if (board[cmid][rmid].is_occ() && board[cmid][rmid].is_black()) {
                    return true;
                }
                else return false;
            }
            else if (((c2 == c1+2) && (r2 == r1-2))) {
                cmid = c1+1;
                rmid = r1-1;
                if (board[cmid][rmid].is_occ() && board[cmid][rmid].is_black()) {
                    return true;
                }
                else return false;
            }
            else if ((c2 == c1-2) && (r2 == r1+2)) {
                cmid = c1-1;
                rmid = r1+1;
                if (board[cmid][rmid].is_occ() && board[cmid][rmid].is_black()) {
                    return true;
                }
                else return false;
            }
            else if ((c2 == c1+2) && (r2 == r1+2)) {
                cmid = c1+1;
                rmid = r1+1;
                if (board[cmid][rmid].is_occ() && board[cmid][rmid].is_black()) {
                    return true;
                }
                else return false;
            }
            else return false;
        }
        //black king
        else if (board[c1][r1].is_black() && board[c1][r1].is_king()) {
            if ((c2 == c1-2) && (r2 == r1-2)) {
                cmid = c1-1;
                rmid = r1-1;
                if (board[cmid][rmid].is_occ() && board[cmid][rmid].is_red()) {
                    return true;
                }
                else return false;
            }
            else if (((c2 == c1+2) && (r2 == r1-2))) {
                cmid = c1+1;
                rmid = r1-1;
                if (board[cmid][rmid].is_occ() && board[cmid][rmid].is_red()) {
                    return true;
                }
                else return false;
            }
            else if ((c2 == c1-2) && (r2 == r1+2)) {
                cmid = c1-1;
                rmid = r1+1;
                if (board[cmid][rmid].is_occ() && board[cmid][rmid].is_red()) {
                    return true;
                }
                else return false;
            }
            else if ((c2 == c1+2) && (r2 == r1+2)) {
                cmid = c1+1;
                rmid = r1+1;
                if (board[cmid][rmid].is_occ() && board[cmid][rmid].is_red()) {
                    return true;
                }
                else return false;
            }
            else return false;
        }
        else return false;
        return 0;
    }


    //If move has legal jump, sets the jumped piece's 'jumped' variable to 'true'
    void checkers::check_jumped(int& c1, int& c2, int& r1, int& r2)
    {
        int cmid, rmid;
        
        //red non-king
        if (board[c1][r1].is_red() && !board[c1][r1].is_king()) {
            if (((c2 == c1-2) && (r2 == r1-2))) {
                cmid = c1-1;
                rmid = r1-1;
                if (board[cmid][rmid].is_occ() && board[cmid][rmid].is_black()) {
                    board[cmid][rmid].set_jumped(true);
                }
            }
            else if (((c2 == c1+2) && (r2 == r1-2))) {
                cmid = c1+1;
                rmid = r1-1;
                if (board[cmid][rmid].is_occ() && board[cmid][rmid].is_black()) {
                    board[cmid][rmid].set_jumped(true);
                }
            }
        }
        //black non-king
        else if (board[c1][r1].is_black() && !board[c1][r1].is_king()) { 
            if ((c2 == c1-2) && (r2 == r1+2)) {
                cmid = c1-1;
                rmid = r1+1;
                if (board[cmid][rmid].is_occ() && board[cmid][rmid].is_red()) {
                    board[cmid][rmid].set_jumped(true);
                }
            }
            else if ((c2 == c1+2) && (r2 == r1+2)) {
                cmid = c1+1;
                rmid = r1+1;
                if (board[cmid][rmid].is_occ() && board[cmid][rmid].is_red()) {
                    board[cmid][rmid].set_jumped(true);
                }
            }
        }
        //red king
        else if (board[c1][r1].is_red() && board[c1][r1].is_king()) {
            if ((c2 == c1-2) && (r2 == r1-2)) {
                cmid = c1-1;
                rmid = r1-1;
                if (board[cmid][rmid].is_occ() && board[cmid][rmid].is_black()) {
                    board[cmid][rmid].set_jumped(true);
                }
            }
            else if (((c2 == c1+2) && (r2 == r1-2))) {
                cmid = c1+1;
                rmid = r1-1;
                if (board[cmid][rmid].is_occ() && board[cmid][rmid].is_black()) {
                    board[cmid][rmid].set_jumped(true);
                }
            }
            else if ((c2 == c1-2) && (r2 == r1+2)) {
                cmid = c1-1;
                rmid = r1+1;
                if (board[cmid][rmid].is_occ() && board[cmid][rmid].is_black()) {
                    board[cmid][rmid].set_jumped(true);
                }
            }
            else if ((c2 == c1+2) && (r2 == r1+2)) {
                cmid = c1+1;
                rmid = r1+1;
                if (board[cmid][rmid].is_occ() && board[cmid][rmid].is_black()) {
                    board[cmid][rmid].set_jumped(true);
                }
            }
        }
        //black king
        else if (board[c1][r1].is_black() && board[c1][r1].is_king()) {
            if ((c2 == c1-2) && (r2 == r1-2)) {
                cmid = c1-1;
                rmid = r1-1;
                if (board[cmid][rmid].is_occ() && board[cmid][rmid].is_red()) {
                    board[cmid][rmid].set_jumped(true);
                }
            }
            else if (((c2 == c1+2) && (r2 == r1-2))) {
                cmid = c1+1;
                rmid = r1-1;
                if (board[cmid][rmid].is_occ() && board[cmid][rmid].is_red()) {
                    board[cmid][rmid].set_jumped(true);
                }
            }
            else if ((c2 == c1-2) && (r2 == r1+2)) {
                cmid = c1-1;
                rmid = r1+1;
                if (board[cmid][rmid].is_occ() && board[cmid][rmid].is_red()) {
                    board[cmid][rmid].set_jumped(true);
                }
            }
            else if ((c2 == c1+2) && (r2 == r1+2)) {
                cmid = c1+1;
                rmid = r1+1;
                if (board[cmid][rmid].is_occ() && board[cmid][rmid].is_red()) {
                    board[cmid][rmid].set_jumped(true);
                }
            }
        }
    }
    void checkers::display_status() const
    {
        system("clear"); //clears terminal for each move//
        std::cout << "  | A | B | C | D | E | F | G | H |" << std::endl;
//        std::cout << "  | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |" << std::endl;
        for (int y = 0; y < 8; y++) {
            std::cout << BOLD << "--" << B_GREEN << "---------------------------------" << RESET << " " <<  std::endl;
            std::cout << y+1 << " " << B_GREEN<< '|' << RESET;
            for (int x = 0; x < 8; x++) {
                if (!board[x][y].is_black() && !board[x][y].is_red()) {
                    std::cout << B_GREEN << "   " << RESET;
                }
                if (board[x][y].is_black() && board[x][y].is_king()){
                    std::cout << B_BLACK << BOLD << " * " << RESET;
                }
                else if (board[x][y].is_red() && board[x][y].is_king()){
                    std::cout << B_RED << BOLD << " * " << RESET;
                }
                else if (board[x][y].is_black()){
                    std::cout << B_BLACK << "   " << RESET;
                }
                else if (board[x][y].is_red()){
                    std::cout << B_GREEN << B_RED << "   " << RESET;
                }

                if (y <= 7 && x <= 6){
                    std::cout << B_GREEN << BLACK << BOLD << "|" << RESET;
                }
            }
            if (y <= 7) {
                std::cout  << B_GREEN << BLACK << BOLD << "|\n" << RESET;
            }
        }
        std::cout << "  " << B_GREEN << BOLD << "---------------------------------" << RESET << std::endl;

    }
    
    //Generates a string for all possible moves, adds 1 for each legal move on the board
    int checkers::scan_moves()const
    {
        int num_legal_moves = 0;
        string temp;
        for (char i = 'a'; i<='h'; i++) {
            for (char j = '1'; j<='8'; j++) {
                for (char k = 'a'; k<='h'; k++) {
                    for (char l = '1'; l<='8'; l++) {
                        //cout << "(" << i << "," << j << ")" << " " << "(" << k << "," << l << ")" <<endl;
                        temp = "";
                        temp +=i;
                        temp +=j;
                        temp +=k;
                        temp +=l;
                        if (is_legal(temp)) {
                            num_legal_moves+=1;
                        }
                    }
                }
            }
        }
        return num_legal_moves;
    }
    
    const bool checkers::can_jump()const
    {
        int x = 0;
        bool jump_possible = false;
        while (jump_possible == false || x == 8) {
            for (int y = 0; y<7; y++) {
                for (int x = 0; x<7; x++) {
                    
                }
            }
        }
        return jump_possible;
    }
    
    bool checkers::is_legal(const std::string& move)const
    {
        string fmove = move;
        int col1, col2, row1, row2;
        convert_move(move, col1, col2, row1, row2);
       
        //Beginning of conditions for human moves
        if (game::next_mover()== HUMAN)
        {
            if (col1<0 || col1>7 || col2<0 || col2>7 || row1<0 || row1>7 || row2<0 || row2>7) return false;         //Player tries to move to/from a piece not on the board
            if (board[col1][row1].is_black()) return false;                                                         //Player tries to move wrong color
            else if (board[col2][row2].is_occ()) return false;                                                      //Player tries to move to an occupied space
            else if ((!is_jump(col1, col2, row1, row2)) && !(is_slide(col1, col2, row1, row2))) return false;       //Player tries to make a move other than a legal slide or jump
            //else if (can_jump() && !is_jump(col1, col2, row1, row2)) return false;                             //Player has a jump available, but doesnt take it
            else return true;
        }
        //Beginning of conditions for computer moves
        else if (game::next_mover()== COMPUTER)
        {
            if (board[col1][row1].is_red()) return false;                                                           //Computer tries to move wrong color
            else if (board[col2][row2].is_occ()) return false;                                                      //Computer tries to move to an occupied space
            else if (!(is_jump(col1, col2, row1, row2)) && !(is_slide(col1, col2, row1, row2))) return false;       //Computer tries to make a move other than a legal slide or jump
            //else if (can_jump() && !is_jump(col1, col2, row1, row2)) return false;                             //Computer has a jump available, but doesnt take it

            else return true;
        }
        else return false;
    }
    

    void checkers::make_move(const std::string& move)
    {
        int col1, col2, row1, row2;
        bool done = false;
        convert_move(move, col1, col2, row1, row2);
        
        if (is_jump(col1, col2, row1, row2)) {
            do {
                    //Capture jumped piece
                    check_jumped(col1, col2, row1, row2);
                    for (int y = 0; y<8; y++) {
                        for (int x = 0; x<8; x++) {
                            if (board[x][y].was_jumped()) {
                                board[x][y].remove_piece();
                                board[x][y].set_jumped(false);
                            
                            
                            }
                        }
                    }
                
                    for (int y = 0; y<8; y++) {
                        for (int x = 0; x<8; x++) {
                            if (is_jump(col2, x, row2, y)) {
                                //Capture jumped piece
                                check_jumped(col1, x, row1, y);
                                for (int y = 0; y<8; y++) {
                                    for (int x = 0; x<8; x++) {
                                        if (board[x][y].was_jumped()) {
                                            board[x][y].remove_piece();
                                            board[x][y].set_jumped(false);
                                            
                                        }
                                    }
                                }
                            }
                        }
                        if (y==7) {
                            done = true;
                        }
                    }
                }while (!done);
            }
        
        //if the piece your removed was black, it places a black piece on the chosen space
        if (board[col1][row1].is_black()) {
            board[col2][row2].place_black();
        }
        //same thing, but with red rather than black
        else if (board[col1][row1].is_red()) {
            board[col2][row2].place_red();
        }

        //remove old piece
        board[col1][row1].remove_piece();
        
        //Make king if applicable
        make_king(col2, row2);
        
        //Update piece numbers
        scan_moves();
        
        //Parent call
        game::make_move(move);
    }
    
    bool checkers::is_game_over()const
    {
        //Game is over if 50 moves are completed
        if (game::moves_completed() == 50) {
            return true;
        }
        
        //If someone runs out of pieces
        else if (num_black_pieces == 0 || num_red_pieces == 0) return true;
        
        //If there are no more legal moves on the board
        else if (scan_moves() == 0) return true;
        
        else return false;
    }
    
    void checkers::compute_moves(std::queue<string>& moves)const
    {
        string temp;
        for (char i = 'a'; i<='h'; i++) {
            for (char j = '1'; j<='8'; j++) {
                for (char k = 'a'; k<='h'; k++) {
                    for (char l = '1'; l<='8'; l++) {
                        temp = "";
                        temp +=i;
                        temp +=j;
                        temp +=k;
                        temp +=l;
                        if (is_legal(temp)) {
                            moves.push(temp);
                        }
                    }
                }
            }
        }
    }
    
    int checkers::evaluate()const
    {
        int val = 0;
        for (int y = 0; y < 8; y++) {
            for (int x = 0; x < 8; x++) {
                if (board[x][y].is_black() && board[x][y].is_king()) val+=3;
                else if (board[x][y].is_red() && board[x][y].is_king()) val-=3;
                else if (board[x][y].is_black() && !board[x][y].is_king()) val+=1;
                else if (board[x][y].is_red() && !board[x][y].is_king()) val-=1;
                else val+=0;
            }
        }
        return val;
    }
    
    void checkers::scan_board()
    {
        for (int y = 0; y < 8; y++) {
            for (int x = 0; x < 8; x++) {
                if (board[x][y].is_black()) increment_blacks();
                else if (board[x][y].is_red()) increment_reds();
            }
        }

    }
    
    game::who checkers::winning()const
    {
        if (reds() > blacks()) return HUMAN;
        else if (blacks() > reds()) return COMPUTER;
        else return NEUTRAL;
    }
}

