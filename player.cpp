#include "player.hpp"
Player::Player(): name("n/a")
{

}

Player::Player(const std::string _name): name(_name)
{

}

const std::string Player::getName() const
{
	return this->name;
}

void Player::setName(std::string userName) {
	name = userName;
}