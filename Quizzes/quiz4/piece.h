/*
Header file for piece class
Taylor Bruening
*/
#include<iostream>
#include<cstdlib>
#include<string>
#include"colors.h"


#ifndef OTHELLO_PIECE
#define OTHELLO_PIECE


class piece{
public:

//CONSTRUCTOR
piece()
{empty = true;
color = true;}

//ACCESSORS
const std::string holder() const;

const bool emptiness() const;

const std::string has_piece_color() const;

//MUTATORS
void set_piece_black()
{color = true; empty = false;}

void set_piece_white()
{color = false; empty = false;}

void set_as_empty()
{empty = true;}

void flip();

private:
bool empty;
bool color;
};

#endif
