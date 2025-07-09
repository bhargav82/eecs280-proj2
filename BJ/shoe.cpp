#include "shoe.hpp"
#include <cstdlib>
#include <random>

Shoe::Shoe()
{

    capacity = MAX_CAP;
    // create 3 deck objects, that need to be copied into shoe
    Deck d1;
    Deck d2;
    Deck d3;

    int index = 0;

    for (int i = 0; i < DECK_SIZE; i++)
    {
        shoeOfCards[index] = d1.deckOfCards.at(i);
        index++;
    }

    for (int i = 0; i < DECK_SIZE; i++)
    {
        shoeOfCards[index] = d2.deckOfCards.at(i);
        index++;
    }

    for (int i = 0; i < DECK_SIZE; i++)
    {
        shoeOfCards[index] = d3.deckOfCards.at(i);
        index++;
    }
}


Card* Shoe::getShoe()
{
    return shoeOfCards;
}

Card Shoe::playCard()
{
    Card cardToPlay = Shoe::getTop();
    this->capacity--;

    return cardToPlay;
}


// make another array of size 156, get a random integer from 0-155 (index), put that index of card into top of 2nd shoe
// in og switch that card index with the last index, decrease range of random integer and repeat

void Shoe::shuffle() 
{
    Card tempShoe[MAX_CAP];

    std::random_device rd;
    std::mt19937 gen(rd());

    int range = MAX_CAP - 1;
    for(size_t i = 0; i < MAX_CAP; i++)
    {
        std::uniform_int_distribution<> distribution(0, range - i);
        int index = distribution(gen);
        tempShoe[i] = shoeOfCards[index];

        Card temp1;
        Card temp2;
        
        temp1 = shoeOfCards[index];
        temp2 = shoeOfCards[MAX_CAP - i - 1];
        
        shoeOfCards[index] = temp2;
        shoeOfCards[MAX_CAP - i - 1] = temp1;

    }
    
    for(int i = 0; i < MAX_CAP; i++)
    {
        shoeOfCards[i] = tempShoe[i];
    }

    return;
}




Card Shoe::getTop()
{
    if (!capacity)
    {
        throw std::runtime_error("There are no cards in shoe.");
    }

    Card topCard = shoeOfCards[capacity - 1];
    return topCard;
}



void Shoe::toStr()
{
    
    for (int i = 0; i < capacity; i++)
    {
        Card c = this->shoeOfCards[i];
        std::cout << c.name << " of " << c.suit << ", Value: " << c.value << std::endl;
    }
}


Shoe::~Shoe()
{
    std::cout << "Destructor called." << std::endl;
}


