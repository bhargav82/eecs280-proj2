#include "shoe.hpp"
#include <cstdlib>
#include <random>

Shoe::Shoe()
{

    capacity = MAX_CAP;
    // create 3 deck objects, that need to be copied into shoeOfCards
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
    this->capacity--;                                               // won't delete memory, just decrease capacity, so all cards are kept in same block

    return cardToPlay;
}



void Shoe::shuffle() 
{
    // creates a second array to put the cards as they randomly selected by the shuffle   
    Card tempShoe[MAX_CAP];

    // We used this random device based on cursor position to generate a random number    
    std::random_device rd;
    std::mt19937 gen(rd());

    int range = MAX_CAP - 1;
    for(size_t i = 0; i < MAX_CAP; i++)
    {
        //this for loop goes over the array with the cards and randomly selects one of them    
        std::uniform_int_distribution<> distribution(0, range - i);
        int index = distribution(gen);
        tempShoe[i] = shoeOfCards[index];               //then the card is stored in thswitched with the card at the end of the original array         
                                                        //we then ignore the cards at the end of the array, since they have already been passed to the suffled array
                                                        //so we keep generating random positions between 0 and (156 - amount of shuffled cards)
        Card temp1;
        Card temp2;
        
        temp1 = shoeOfCards[index];
        temp2 = shoeOfCards[MAX_CAP - i - 1];
        
        shoeOfCards[index] = temp2;
        shoeOfCards[MAX_CAP - i - 1] = temp1;

    }
    
    
    //after we go trough the entire array we just put the cards in the temp array into the old array, but in the shuffled order
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



// reset capacity back to MAX_CAP (156), so array holds all cards again since they were never removed
void Shoe::resetShoe(){
    capacity = MAX_CAP;
}


int Shoe::getCapacity(){
    return capacity;
}


Shoe::~Shoe()
{
    std::cout << "Destructor called." << std::endl;
}




