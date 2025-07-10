#include "hangman.hpp"
#include <fstream>
#include <sstream>
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

    this->highScores = readHighScores("hangmanHighscores.txt");

	sortScoreLowToHigh();
    updateScoreboard();
}

int Hangman::play(const Player& p) 
{
    drawBoard();
    size_t uniqueLettersSize = unique_letters.size(); 
    while ((correctCounter <= (uniqueLettersSize)) && strikeCounter < 6)
    {
        if (correctCounter == uniqueLettersSize)
        {
            printHangmanWord(keyword, userGuessedLetters);
            std::cout << "||   Good job! You correctly guessed the hidden   ||" << std::endl;
            std::cout << "            word with only " << strikeCounter << " mistake(s)." << std::endl;
            std::cout << "----------------------------------------------------" << std::endl;
            HighScore* newScore = new HighScore(p.getName(), strikeCounter);
            addScore(newScore);
            break;
        }

        getInput();
        correctAndIncorrectGuesses(userInputLetter, userGuessedLetters);
        printHangmanGraphic(strikeCounter);
        printHangmanLettersLeft(alphabet, alphabet.size());
        printHangmanWord(keyword, userGuessedLetters);
        
        
        
    }

    if (strikeCounter == 6)
    {
        std::cout << "||   Unlucky! You were unable to guess the word.  ||" << std::endl;
        std::cout << "         The correct answer was: " << keyword << std::endl;
        std::cout << "----------------------------------------------------" << std::endl;
    }

   
        
    return 1;
}



void Hangman::drawBoard()
{

    printHangmanMenu();
    printHangmanGraphic(strikeCounter);
    printHangmanWord(keyword, userGuessedLetters);

}


void Hangman::getInput() 
{
    std::cout << "Guess a letter: ";
    std::cin >> userInputLetter;
    std::cout << std::endl << "----------------------------------------------------" << std::endl;
}


void Hangman::correctAndIncorrectGuesses(char userInputLetter, std::set<char>& alreadyGuessedLetters)
{
    alphabet.erase(std::remove(alphabet.begin(), alphabet.end(), userInputLetter), alphabet.end());

    if (unique_letters.count(userInputLetter) && checkGuess(userInputLetter, alreadyGuessedLetters)){
        correctCounter++;
    }
    else if (!checkGuess(userInputLetter, alreadyGuessedLetters))
    {
        std::cout << "*** Already guessed! Please enter a new letter. ***" << std::endl;
        std::cout << "----------------------------------------------------" << std::endl;
    }
    else{
        strikeCounter++;
    }
    alreadyGuessedLetters.insert(userInputLetter);
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




void Hangman::resetGame() {
    this->keyword = randomWordGenerator(createWordList("wordList.txt"));
    this->strikeCounter = 0;
    this->correctCounter = 0;
    this->userGuessedLetters = {};
    this->unique_letters = {};
    this->userInputLetter = {};
    this->alphabet =  {
        'a','b','c','d','e','f','g','h','i','j','k','l','m',
        'n','o','p','q','r','s','t','u','v','w','x','y','z'
    };
    std::set<char> wordUniqueLetters = findUniqueLetters(keyword);
    unique_letters = wordUniqueLetters;

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



// REQUIRES: nothing
// MODIFIES: cout
// EFFECTS: prints a menu displaying the rules for the Hangman game
void Hangman::printHangmanMenu() {
    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << "Welcome to Hangman!! Here are the rules of the game." << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << "~ We will give you a random word to guess. This word" << std::endl;
    std::cout << "  will not have any spaces or non-letter characters." << std::endl << std::endl;
    std::cout << "~ You will be prompted to type a letter as a guess. " << std::endl;
    std::cout << "  If this letter is in the word, it will be revealed." << std::endl;
    std::cout << "  Otherwise, you will receive a strike."              << std::endl << std::endl;
    std::cout << "~ As you receive strikes, the hangman will be drawn." << std::endl;
    std::cout << "  If you get six strikes, you lose the game."         << std::endl << std::endl;
    std::cout << "          ** Good luck, and have fun!! **           " << std::endl;
    std::cout << "----------------------------------------------------" << std::endl << std::endl;
}

// REQUIRES: nothing
// MODIFIES: cout
// EFFECTS: prints the hangman letters left to guess to the terminal
void Hangman::printHangmanLettersLeft(std::vector<char>& remainingLetters, size_t size) {
    std::cout << "Remaining letters: ";
    for (size_t i = 0; i < size - 1; ++i) {
        std::cout << remainingLetters[i] << ", ";
        if (i == 10) {
            std::cout << std::endl << "                   ";
        }
    }
    std::cout << remainingLetters[size - 1] << std::endl;
    std::cout << std::endl << "----------------------------------------------------" << std::endl;
}


// REQUIRES: the keyword and a vector of letters already guessed
// MODIFIES: cout
// EFFECTS: prints the hangman word with correctly guessed letters filled in
void Hangman::printHangmanWord(std::string keyword, std::set<char> lettersGuessed)
{
    std::vector<char> lettersGuessedVector(lettersGuessed.begin(), lettersGuessed.end());
    char letterToPrint;

    for (auto i = 0; i < keyword.length(); ++i) {
        bool letterMatch = false;
        for (auto j = 0; j < lettersGuessedVector.size(); ++j) {
            if (keyword[i] == lettersGuessedVector[j]) {
                letterToPrint = lettersGuessedVector[j];
                letterMatch = true;
            }
        }

        if (letterMatch) {
            std::cout << letterToPrint << "  ";
        }
        else {
            std::cout << "__  ";
        
        }
        

    }
    std::cout << std::endl << "----------------------------------------------------" << std::endl;
}



// REQUIRES: nothing
// MODIFIES: cout
// EFFECTS: prints the hangman graphic to the terminal
void Hangman::printHangmanGraphic(int strikeCount) {
    if (strikeCount == 0) {
        std::cout << "           ------     " << std::endl;
        std::cout << "           |    |     " << std::endl;
        std::cout << "           |    " << std::endl;
        std::cout << "           | " << std::endl;
        std::cout << "           |     " << std::endl;
        std::cout << "          ---         " << std::endl; 
    }
    else if (strikeCount == 1) {
        std::cout << "           ------     " << std::endl;
        std::cout << "           |    |     " << std::endl;
        std::cout << "           |    O     " << std::endl;
        std::cout << "           | " << std::endl;
        std::cout << "           |          " << std::endl;
        std::cout << "          ---         " << std::endl; 
    }
    else if (strikeCount == 2) {
        std::cout << "           ------     " << std::endl;
        std::cout << "           |    |     " << std::endl;
        std::cout << "           |    O     " << std::endl;
        std::cout << "           |    |     " << std::endl;
        std::cout << "           |          " << std::endl;
        std::cout << "          ---         " << std::endl; 
    }
    if (strikeCount == 3) {
        std::cout << "           ------     " << std::endl;
        std::cout << "           |    |     " << std::endl;
        std::cout << "           |    O     " << std::endl;
        std::cout << "           |    |/    " << std::endl;
        std::cout << "           |    |     " << std::endl;
        std::cout << "           |          " << std::endl;
        std::cout << "          ---         " << std::endl; 
    }
    if (strikeCount == 4) {
        std::cout << "           ------     " << std::endl;
        std::cout << "           |    |     " << std::endl;
        std::cout << "           |    O     " << std::endl;
        std::cout << "           |   \\|/   " << std::endl;
        std::cout << "           |    |    " << std::endl;
        std::cout << "           |          " << std::endl;
        std::cout << "          ---         " << std::endl; 
    }
    if (strikeCount == 5) {
        std::cout << "           ------     " << std::endl;
        std::cout << "           |    |     " << std::endl;
        std::cout << "           |    O     " << std::endl;
        std::cout << "           |   \\|/   " << std::endl;
        std::cout << "           |    |    " << std::endl;
        std::cout << "           |     \\      " << std::endl;
        std::cout << "          ---         " << std::endl; 
    } 
    if (strikeCount == 6) {
        std::cout << "           ------     " << std::endl;
        std::cout << "           |    |     " << std::endl;
        std::cout << "           |    O     " << std::endl;
        std::cout << "           |   \\|/    " << std::endl;
        std::cout << "           |    |    " << std::endl;
        std::cout << "           |   / \\      " << std::endl;
        std::cout << "          ---         " << std::endl; 
    }
    std::cout << std::endl;
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



Hangman::~Hangman()
{
    std::cout << "Hangman Destructor." << std::endl;
}




std::vector<std::pair<std::string, int>> Hangman::readHighScores(const std::string filename)
{
	std::ifstream file;
    file.open(filename);

    if ( !file.is_open() )
    {
        throw std::runtime_error("File could not be opened.");
    }

	std::string line;

    while (std::getline(file, line))
    {
		std::pair<std::string, int> currentPlayerInfo;

		std::stringstream ss(line);
		std::string name;
		std::string score;
		
		std::getline(ss, name, ',');
		currentPlayerInfo.first = name;

		std::getline(ss, score);
		currentPlayerInfo.second = stoi(score);

		highScores.push_back(currentPlayerInfo);
    }

    file.close();
	return highScores;

}



// sorts top 10 by score puts into top10list
void Hangman::sortScoreLowToHigh() {

	for (size_t i = 0; i<highScores.size(); i++){
		for (size_t j = 0; j< highScores.size() -i -1; j++)
		{
			if (highScores.at(j).second > highScores.at(j+1).second)
			{
				int tempVal = highScores.at(j).second;
				std::string tempName = highScores.at(j).first;

				highScores.at(j).second = highScores.at(j+1).second;
				highScores.at(j).first = highScores.at(j+1).first;

				highScores.at(j+1).second = tempVal;
				highScores.at(j+1).first = tempName;
			}
		}
	}

	return;
}

bool Hangman::addScore( HighScore* newScore )
{
	
	bool addNewScore = false;
	int indexToChange = 0;
	int tempVal = 0;
	std::string tempName = "";
	int tempVal2 = 0;
	std::string tempName2 = "";
	
	for (int i = 0; i < static_cast<int>(highScores.size()); i++)
	{
		// needs to take this place and move everything down;
		if (newScore->getScore() < highScores.at(i).second)
		{
			addNewScore = true;
			indexToChange = i;

			tempVal = highScores.at(i).second;
			tempName = highScores.at(i).first;

			highScores.at(i).second = newScore->getScore();
			highScores.at(i).first = newScore->getName();
			break;
		}
	}

	if (addNewScore)
	{
		for (int j = indexToChange + 1; j < static_cast<int>(highScores.size()); j++)
		{
			tempVal2 = highScores.at(j).second;
			tempName2 = highScores.at(j).first;

			highScores.at(j).second = tempVal;
			highScores.at(j).first = tempName;

			tempVal = tempVal2;
			tempName = tempName2;
		}
		updateScoreboard();
		writeToFile();
	}


	
	return addNewScore;
}

void Hangman::writeToFile()
{
	std::ofstream outputFile("hangmanHighscores.txt");
	if (outputFile.is_open())
	{
		for (HighScore* h : top10list)
		{
			outputFile << h->getName() << ", " << h->getScore() << std::endl;
		}
	}
    outputFile.close();
}

void Hangman::updateScoreboard()
{
	for (int i = 0; i<10; i++)
	{
		
		delete top10list[i];

		top10list[i] = new HighScore(highScores.at(i).first, highScores.at(i).second);
		
	}
}