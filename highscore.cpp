#include "highscore.hpp"
#include <sstream>

HighScore::HighScore()
{
	this->score = 9999;
}

HighScore::HighScore( Player _p, int _score) : p(_p), score(_score)
{

}

std::string HighScore::toStr() 
{
	std::stringstream ss;
	ss << this->p.getName() << "\t" << this->score;
	return ss.str();
}

int HighScore::getScore()
{
	return this->score;
}

std::string HighScore::getName()
{
	return (this->p).getName();

}