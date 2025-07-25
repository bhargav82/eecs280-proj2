// here you can import more things. import everything needed for the implementation of this class.
#include "guess.hpp"		// the class definition
#include "consoledraw.hpp"	// stuff to help with writing to the console
#include "highscore.hpp"

// some generally helpful libraries
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <random>
#include <fstream>

// default constructor
Guess::Guess( ) : Game()
{
	
	std::cout << "Constructor for Guess!" << std::endl;

	// read the old scoreboard file here
	// populate the game's scoreboard object
	
	static const std::string filename = "guessHighScore.txt";
	this->highScores = readHighScores(filename);
	sortScoreLowToHigh();

	
	

}

// destructor
Guess::~Guess( )
{
	std::cout << "Destructor for Guess!" << std::endl;
	// nothing to delete
}

// reset the game to the initial state
void Guess::resetGame( )
{
	// seed the time to the random library
	std::srand(std::time(nullptr));

	// generate a random distribution
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distribution(GUESS_MIN, GUESS_MAX);
	
	// get a random magic number
	this->magic_number = distribution(gen);

	// reset number of guesses and board min/max
	this->num_guesses = 0;
	this->board_min = GUESS_MIN;
	this->board_max = GUESS_MAX;
}

// draw the board on the screen in its current state
void Guess::drawBoard()
{
        const int width = 60; // total characters for the line
        const std::string RED = "\033[31m";
        const std::string RESET = "\033[0m";

        // Compute the scale factor
        int range = GUESS_MAX - GUESS_MIN;
        if (range <= 0)
	{
            std::cerr << "Invalid range.\n";
            return;
        }

        // Build the number line
        std::string line;
        for (int i = 0; i <= width; ++i)
	{
            int value = GUESS_MIN + (i * range) / width;
            if (value < board_min || value > board_max)
	    {
                line += RED + "-" + RESET;
            } else {
                line += "-";
            }
        }

        // Print the line
        std::cout << line << "\n";

        // Create label line
        std::string labels(width + 1, ' ');
        int pos_min = (board_min - GUESS_MIN) * width / range;
        int pos_max = (board_max - GUESS_MIN) * width / range;

        if (pos_min >= 0 && pos_min <= width)
            labels[pos_min] = '|';
        if (pos_max >= 0 && pos_max <= width)
            labels[pos_max] = '|';

        std::cout << labels << "\n";

        // Print the numeric labels
        std::cout << std::setw(pos_min + 1) << board_min;
        std::cout << std::setw(pos_max - pos_min + 1) << board_max << "\n";

	return;
}

// we don't use this one but it's part of the interface so we have to implement it
void Guess::getInput()
{
	return;
}



std::vector<std::pair<std::string, int>> Guess::readHighScores(const std::string filename)
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

// needs to be implemented as part of the first task
bool Guess::addScore( HighScore* newScore )
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

void Guess::writeToFile()
{
	std::ofstream outputFile("guessHighScore.txt");
	if (outputFile.is_open())
	{
		for (HighScore* h : top10list)
		{
			outputFile << h->getName() << ", " << h->getScore() << std::endl;
		}
	}
	outputFile.close();
}



void Guess::updateScoreboard()
{
	for (int i = 0; i<10; i++)
	{
		
		delete top10list[i];
		top10list[i] = nullptr;

		top10list[i] = new HighScore(highScores.at(i).first, highScores.at(i).second);

		
	}
}


// sorts top 10 by score puts into top10list
void Guess::sortScoreLowToHigh() {

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




// handles the entire process of playing a single game
int Guess::play( const Player& player )
{
	// make sure everything is initialized
	this->resetGame();
	
	int user_guess = -1;
	while( user_guess != this->magic_number )
	{
		// clear the screen
		resetScreen();
		std::cout << "Guess the magic number!" << std::endl;

		// draw the board on the screen
		this->drawBoard();

		// ask the user for a guess and get it
		std::cout << "Enter your guess (between " << this->board_min << " and " << this->board_max << "): ";
		std::cin >> user_guess;

		// if the guess is too small
		if( user_guess < this->magic_number )
		{
			std::cout << "too small!" << std::endl;

			// if it is the highest low-guess then we can update the board
			if( this->board_min < user_guess )
			{
				this->board_min = user_guess;

				std::cout << "board min: " << this->board_min << std::endl;
			}
		}
		// if the guess is too big
		else if( user_guess > this->magic_number )
		{
			std::cout << "too big!" << std::endl;
			
			// if it is the lowest high-guess then we can update the board
			if( this->board_max > user_guess )
			{
				this->board_max = user_guess;
				
				std::cout << "board max: " << this->board_max << std::endl;
			}
		}

		// increment the number of guesses
		this->num_guesses ++;
	}

	// celebrate and output the amount of guesses required
	std::cout << "Good job! You figured out the magic number after only "
		  << this->num_guesses
		  << " guesses!"
		  << std::endl
	;

	HighScore playerScore(player, num_guesses);
	HighScore* playerScorePtr = &playerScore;

	addScore(playerScorePtr);

	return 0;
}

