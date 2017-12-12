//
//  checkers.h
//  
//
//  Created by Michael Boyd on 4/8/15.
//
//
#include "colors.h"
#include "game.h"
#include "space.h"

namespace main_savitch_14
{

    class checkers:public game {
    public:
        checkers();
        void display_status()const;
        bool is_legal(const std::string& move)const;
        void restart();
        void make_move(const std::string& move);
        bool is_slide(int& c1, int& c2, int& r1, int& r2)const;
        bool is_jump(int& c1, int& c2, int& r1, int& r2)const;
        bool is_game_over()const;
        void convert_move(const std::string& move, int& c1, int& c2, int& r1, int& r2)const;
        void make_king(int& c2, int& r2);
        void check_jumped(int& c1, int& c2, int& r1, int& r2);
        void count_pieces();
        void increment_blacks(){num_black_pieces++;}
        void increment_reds(){num_red_pieces++;}
        int reds()const {return num_red_pieces;}
        int blacks()const {return num_black_pieces;}
        int scan_moves()const;
        void scan_board();
        const bool can_jump()const;
        game * clone()const{return new checkers(*this);} //error will go away once all functons are defined
        void compute_moves(std::queue<string>& moves)const;
        int evaluate()const;
        game::who winning()const;
        

    private:
        space board[8][8];
        int num_red_pieces;
        int num_black_pieces;
    };
}

