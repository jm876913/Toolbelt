#include "gtest/gtest.h"
#include "Othello.h"
namespace {

TEST(Othello, make_move) {
  //Othello e;

 
  EXPECT_EQ("D3", make_move("D3"));
  EXPECT_EQ("B3", make_move("B3"));
  EXPECT_EQ("A3", make_move("A3"));
}
}  // namespace
