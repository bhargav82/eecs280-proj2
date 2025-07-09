#include "hand.hpp"

Hand::Hand()
{
    size = 0;
    capacity = 2;
    cardsOfHand = new Card[capacity];
}

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

void Hand::clearHand(Card &c){
    size = 0;
}



int Hand::getSize()
{
    return size;
}


int Hand::getCapacity(){
    return capacity;
}
