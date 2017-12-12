/*
implementation file for piece class
Taylor Bruening
*/
#include<iostream>
#include<cstdlib>
#include<string>
#include"piece.h"

using namespace std;

const string piece::holder() const{
  string x = "   ";
  string holder = " \u23FA ";

  if(empty==true)
	{return x;}
  else
	{return holder;}
}

const bool piece::emptiness() const{
  if(empty == true)
	{return true;}
  else
	{return false;}
}

const string piece::has_piece_color() const{
  if((empty == false)&&(color == true))
	{return "black";}
  if((empty == false)&&(color == false))
	{return "white";}
  else
	{return "empty";}
}

void piece::flip(){
  if((color == true)&&(empty==false))
	{color = false;}
  else if(color == false&&(empty==false))
	{color = true;}
}
