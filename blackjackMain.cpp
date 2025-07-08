#include "card.hpp"
#include "shoe.hpp"
#include "blackjackPlayer.hpp"



int main()
{
    // Takes in three unshuffled decks, shuffles them, and puts them in one shoe
    User u1;
    Table* t1 = &u1;

    t1->getCardFromShoe();

    t1->toStr();
    
    return 0;
}