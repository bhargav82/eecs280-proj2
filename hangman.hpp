#include "game.hpp"
#include <set>
#include <vector>
#include <string>
#include <algorithm>



class Hangman : public Game
{
// pure virtual function 
public:
    virtual void drawBoard() override;
	virtual void getInput() override;
    virtual bool addScore( HighScore* newScore ) override;
	virtual int play(const Player&) override;
	virtual void resetGame() override;


    // game functionality
    Hangman();
    ~Hangman();
    
/* REQUIRES: filename as string
   EFFECTS: if file can be opened, a vector of strings is created of lowercase words from text file, if not throws error
   RESULTS: a vector of strings 
*/ 
     const std::vector<std::string> createWordList(const std::string& filename);

/* REQUIRES: vector of words
   EFFECTS: creates a random int from 0 to 999  
   RESULTS: word at random index of vector
*/
    const std::string randomWordGenerator(const std::vector<std::string>& listOfAllWords);
    
/* REQUIRES: word (each word of text file)
   EFFECTS: makes each letter lowercase
   RESULTS: changes word in place to lowercase version
*/
    void wordToLower(std::string& dirtyWord);

/* REQUIRES: letter guess, vector of already guessed letters
   EFFECTS: checks if user has inputted a valid letter -> if so, converts to lowercase and checks against guessed letters 
   RESULTS: false if already guessed or not valid letter, true is new letter
*/
    bool checkGuess(char c, std::set<char> guessedLetters);

/* REQUIRES: keyword (randomly chosen), should be lowercase
   EFFECTS: goes through word and creates a set of unique characters
   RESULTS: set of chars, (sets are auto unique)
*/
    std::set<char> findUniqueLetters(std::string& keyword);

/* REQUIRES: nothing
   EFFECTS: goes through the scores and sorts them
   RESULTS: sorts the scores
*/
    void sortScoreLowToHigh();

/* REQUIRES: nothing
   EFFECTS: writes the sorted scores on a file
   RESULTS: nothing
*/
	void writeToFile();


	

    // REQUIRES: filename containing high scores
    // MODIFIES: highscore vector, changes elements to what is in the text file
    // EFFECTS: returns a vector of pairs with names, and scores

	std::vector<std::pair<std::string, int>> readHighScores(const std::string filename);

    // REQUIRES: nothing
    // MODIFIES: the score board
    // EFFECTS: looks for the score with most tries and if it is bigger that the current score replaces it
    void updateScoreboard();

    // REQUIRES: the keyword and a vector of letters already guessed
    // MODIFIES: cout
    // EFFECTS: prints the hangman word with correctly guessed letters filled in
    void printHangmanWord(std::string keyword, std::set<char> lettersGuessed);

    // REQUIRES: the number of wrong guesses
    // MODIFIES: nothing
    // EFFECTS: prints the hangman with the bodyparts depending on the amount of wrong guesses
    void printHangmanGraphic(int strikeCount);

    // REQUIRES: user input and the letter already guessed
    // MODIFIES: strike count and hit count
    // EFFECTS: checks if the user guessed right and changes strike count and hit count based on that
    void correctAndIncorrectGuesses(char userInputLetter, std::set<char>& alreadyGuessedLetters);

    // REQUIRES: a vector with the remaining letters and the size of the word
    // MODIFIES: nothing
    // EFFECTS: prints the letters that the user hasent guessed yet
    void printHangmanLettersLeft(std::vector<char>& remainingLetters, size_t size);

    // REQUIRES: nothing
    // MODIFIES: nothing
    // EFFECTS: prints the menu
    void printHangmanMenu();


    std::vector<std::pair<std::string, int>> highScores; 
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



