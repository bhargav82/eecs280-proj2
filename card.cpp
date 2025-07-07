#include "card.hpp"



int main() {

    Deck d1;
    for (auto card : d1.deckOfCards)
    {
        std::cout << card.suit << " " << card.value << std::endl;
    }

    return 0;
}