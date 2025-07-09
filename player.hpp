#include <sstream>
#include <iostream>

#ifndef CLASS_PLAYER
#define CLASS_PLAYER

class Player {
  private:
  const std::string name;

  public:
  Player();
  Player(const std::string _name);
  void setName(std::string userName);
  const std::string getName() const;
}; //end of Class Player

#endif

