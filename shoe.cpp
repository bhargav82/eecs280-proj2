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



Card Shoe::playCard()
{
    Card cardToPlay = Shoe::getTop();
    this->capacity--;

    return cardToPlay;
}




void Shoe::shuffle() 
{
    std::vector <Card> playShoe;
    std::vector <Card> playShoe2;
    for(size_t i = 0; i < MAX_CAP; i++)
    {
        Card temp = shoeOfCards[i];
        playShoe.push_back(temp);
    }

    while(playShoe.size() > 0)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distribution(0, playShoe.size() - 1);
        int index = distribution(gen);
        Card temp = playShoe[index];
        playShoe2.push_back(temp);
        playShoe.erase(playShoe.begin() + index); 

    }
    
    for(size_t i = 0; i < MAX_CAP; i++)
    {
        shoeOfCards[i] = playShoe2[i];
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


