#include "hand.hpp"


// called once when game starts, create 1 array, do not call for each singlePlay
Hand::Hand()
{
    size = 0;
    capacity = 2;
    cardsOfHand = new Card[capacity];
}

// only call when game is completely over, not after each singlePlay
Hand::~Hand()
{
    delete [] cardsOfHand;
}



void Hand::addCard(Card &c)
{
    if (size == capacity)
    {
        resize();
    }

    cardsOfHand[size] = c;
    size++;
}


void Hand::resize()
{
    capacity *= 2;
    Card* newHand = new Card[capacity];

    for (int i = 0; i < size; i++)
    {
        newHand[i] = cardsOfHand[i];
    }
    
    delete [] cardsOfHand;                          // delete old pointer
    cardsOfHand = newHand;                          // reassign pointer of cardsOfHand to newHand
}



// call after each single play is over
void Hand::clearHand(){
    size = 0;                                       // capacity should normally stay between 2-8 cards, so don't need to update capacity, can keep old array

    if (capacity > 20)
    {
        capacity = 2;
        delete [] cardsOfHand;
        cardsOfHand = new Card[capacity];         // in cases of capacity growing very large (playing a ton of hands), then create a new array
    }
}



int Hand::getSize()
{
    return size;
}


int Hand::getCapacity(){
    return capacity;
}


Card Hand::atIndex(int counter)
{
   return cardsOfHand[counter];

}
