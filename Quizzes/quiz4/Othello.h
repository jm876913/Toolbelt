/*
Header file for Othello class
Taylor Bruening
*/
#include<iostream>
#include<cstdlib>
#include<string>
#include<queue>
#include"piece.h"
#include"game.h"
#include"colors.h"

#ifndef OTHELLO_GAME
#define OTHELLO_GAME


class Othello: public main_savitch_14::game{
public:

//PHASE1-2 FUNCTIONS
void display_status() const;

void make_move(const std::string& move);

bool is_legal(const std::string& move) const;

bool is_game_over() const;

void restart();

void victory() const;

//PHASE 3 FUNCTIONS
int evaluate() const;

void compute_moves(std::queue<std::string>& moves) const;

game* clone( ) const;

//FUNCTIONS USED TO TRAVERSE BOARD
std::string current_color() const;
bool checker(const string& move) const;
bool check_up(const string& move)const;
bool check_up_right(const string& move)const; 
bool check_right(const string& move)const;
bool check_down_right(const string& move)const;
bool check_down(const string& move)const;
bool check_down_left(const string& move)const;
bool check_left(const string& move)const;
bool check_up_left(const string& move)const;


private:
piece board[8][8];
};

#endif
