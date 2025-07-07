#include "card.hpp"
#include "shoe.hpp"



int main()
{
    // Takes in three unshuffled decks, shuffles them, and puts them in one shoe
    Shoe s1;

    s1.toStr();
    s1.shuffle();
    std::cout << std::endl;
    s1.toStr();
    return 0;
}