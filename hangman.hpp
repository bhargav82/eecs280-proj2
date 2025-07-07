#include "game.hpp"
#include <set>
#include <vector>
#include <string>



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
    ~Hangman();
    
    const std::vector<std::string> createWordList(const std::string& filename);
    const std::string randomWordGenerator(const std::vector<std::string>& listOfAllWords);

    void wordToLower(std::string& dirtyWord);
    bool checkGuess(char c, std::set<char> guessedLetters);
    std::set<char> findUniqueLetters(std::string& keyword);

    void printHangmanWord(std::string keyword, std::set<char> lettersGuessed);
    void printHangmanGraphic(int strikeCount);
    void correctAndIncorrectGuesses(char userInputLetter, std::set<char>& alreadyGuessedLetters);
    void printHangmanLettersLeft(std::vector<char>& remainingLetters, size_t size);
    void printHangmanMenu();

    private:
        char userInputLetter;
        std::string keyword;                                    // randomly chosen word
        std::set<char> unique_letters;                          // unique letters that checks against guessed characters
        int strikeCounter = 0;
        std::set<char> userGuessedLetters;
        int correctCounter = 0;
        std::vector<char> alphabet = 
        {
            'a','b','c','d','e','f','g','h','i','j','k','l','m',
            'n','o','p','q','r','s','t','u','v','w','x','y','z'
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

