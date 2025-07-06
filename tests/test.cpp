#include "../hangman.hpp"
#include "gtest/gtest.h"

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}





TEST(findUniqueLetters, setOfUniqueLetters)
{
    Hangman h1;
    std::set<char> input1 = {'a', 'r', 'y'};
    std::string testWord1 = "array";

    ASSERT_EQ(h1.findUniqueLetters(testWord1), input1);
}


TEST(checkGuess, allowNewChars)
{
    Hangman h1;
    std::set<char> input1 = {'a', 'r', 'y'};

    ASSERT_FALSE(h1.checkGuess('a', input1));
    ASSERT_FALSE(h1.checkGuess('A', input1));
    ASSERT_FALSE(h1.checkGuess('@', input1));
    ASSERT_TRUE(h1.checkGuess('b', input1));
}



