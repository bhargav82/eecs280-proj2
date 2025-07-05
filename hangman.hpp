#include "game.hpp"


class Hangman : public Game
{
// pure virtual function (need to implement)
public:
    virtual void drawBoard() override;
	virtual void getInput() override;
    virtual bool addScore( HighScore newScore ) override;
	virtual int play(const Player&) override;
	virtual void resetGame() override;


    // game functionality
    Hangman();
    void toLower(std::string& dirtyWord);
    const std::vector<std::string> createWordList(const std::string& filename);
    const std::string randomWordGenerator(const std::vector<std::string>& listOfAllWords);

    bool checkGuess(char c, std::vector<char> guessedLetters);
    std::set<char> findUniqueLetter(std::string& keyword);



    // create word object each time you start a new game
    class Word 
    {
    public:
        std::string keyword;                                    // randomly chosen word
        std::set<char> unique_letters;                          // unique letters that checks against guessed characters

    };
};







/*
    STUFF THAT IS DONE:
    function that makes word lsit
    function that gets random word
    function that checks user guess against guessed letters
    funciton that prints hangman
    function that prints hangman word accurate to letters of guessed
    funciton that prints unguessed letters
    



    STUFF TO DO:
    class for word: that has keyword, vector of unique letters, 
    fucntion that find index of guessed letter, returns vector of ints
    function that checks number of unqiue letters and size of correct guessed letters (must be unique), if equal they won
    print message when you win, if you run out of guesses print sad message


    finish hangman and scoring for guess and try to plan half of blackjack by sunday night
    

*/

