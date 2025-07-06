#include "hangman.hpp"
#include <fstream>
#include <random>



/* REQUIRES: 
   EFFECTS: Creates a word object, stores random word as 
   RESULTS: initializes Hangman game
*/
Hangman::Hangman() : Game()
{

    std::string file = "wordList.txt";
    keyword = randomWordGenerator(createWordList(file));                                     // generates word list from text file, chooses random word


    std::set<char> wordUniqueLetters = findUniqueLetters(keyword);
    unique_letters = wordUniqueLetters;
 
}



Hangman::~Hangman()
{
    std::cout << "Hangman Destructor." << std::endl;
}


/* REQUIRES: filename as string
   EFFECTS: if file can be opened, a vector of strings is created of lowercase words from text file, if not throws error
   RESULTS: a vector of strings 
*/
const std::vector<std::string> Hangman::createWordList(const std::string& filename)
{

    std::ifstream file;
    file.open(filename);

    if ( !file.is_open() )
    {
        throw std::runtime_error("File could not be opened.");
    }

    std::vector<std::string> wordList(1000);
    std::string word;
    int index = 0;

    while (std::getline(file, word))
    {
        wordToLower(word);
        wordList.at(index++) = word;
    }

    file.close();
    return wordList;
}



/* REQUIRES: vector of words
   EFFECTS: creates a random int from 0 to 999  
   RESULTS: word at random index of vector
*/
const std::string Hangman::randomWordGenerator(const std::vector<std::string>& wordList)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distribution(0, 999);

    return wordList.at(distribution(gen));
}


/* REQUIRES: keyword (randomly chosen), should be lowercase
   EFFECTS: goes through word and creates a set of unique characters
   RESULTS: set of chars, (sets are auto unique)
*/
std::set<char> Hangman::findUniqueLetters(std::string& keyword)
{
    std::set<char> uniqueLetters;
    for (char& c : keyword)
    {
        uniqueLetters.insert(c);
    }

    return uniqueLetters;
}



/* REQUIRES: letter guess, vector of already guessed letters
   EFFECTS: checks if user has inputted a valid letter -> if so, converts to lowercase and checks against guessed letters 
   RESULTS: false if already guessed or not valid letter, true is new letter
*/
bool Hangman::checkGuess(char userGuess, std::set<char> guessedLetters)
{
    if (!isalpha(userGuess))
    {
        return false;
    }

    userGuess = std::tolower(userGuess);
    for (char letter : guessedLetters)
    {
        
        if (userGuess == letter)
        {
            return false;
        }
    }

    return true;
}



/* REQUIRES: word (each word of text file)
   EFFECTS: makes each letter lowercase
   RESULTS: changes word in place to lowercase version
*/
void Hangman::wordToLower(std::string& word)
{
    for (char& c : word)
    {
        c = std::tolower(c);
    }

}

// IMPLEMENT THESE PURE VIRTUAL FUNCTIONS

void Hangman::drawBoard() 
{

}
void Hangman::getInput() 
{

}
bool Hangman::addScore( HighScore newScore )
{
        return true;
}
int Hangman::play(const Player&) 
{
        return 1;
}
void Hangman::resetGame() {

}