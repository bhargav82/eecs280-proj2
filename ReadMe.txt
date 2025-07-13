## Welcome to our Project 2 Code! ##

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@  Our Group: Will, Bhargav, and Gabe  @@
@@  What We Made: Blackjack (card game) @@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
_____________________________________________________________________________________________
|  For our second project, we decided to utilize our knowledge of data structures to bring  |
|   the Las Vegas classic of Blackjack to the skel servers. There are a handful of key ways |
|        in which we utilized the content covered in EECS 280 to accomplish this task.      |
|  We implemented a number of custom data structures to store the cards in the different    | 
|    places in which they could end up. For example, we made a custom Hand data structure   |
|                to store the cards in the hands of the player and the dealer               |
|___________________________________________________________________________________________|    

*******************************
** THE "HAND" DATA STRUCTURE **
*******************************
    - In the game of Blackjack, there is always a dealer and at least one player with
      cards in their hands at any given time
    - The number of cards in the hands varies based on the scores they receive; each
      player and the dealer will be given no less than two cards. However, in theory,
      a player's hand could grow up to sixteen cards.
    - Thus, we needed to implement a dynamic data structure to be able to hold a certain
      number of cards taken directly from the Shoe data structure.
    - We created an array of pointers to Card class objects called cardsOfHand, which
      we used to store the cards in the hand of any object of the blackjackPlayer class
      (being either the dealer or the player). This array is initialized as empty.
    - After we made our array for the cards in the hand, we created helper functions
      to add a card, clear the hand of all objects, return the number of cards in the hand,
      return the capacity of the handOfCards array, and find the index of a specific card in the hand.
    - We also created a "resize()" function, which would replace the handOfCards array
      with one of doubled capacity. This makes our data structure dynamic, and allows us to
      use our computer's memory and store efficiently by not creating an array with a larger
      capacity than we would need.
    - Our hand starts out with a size of 2. Once the player or dealer receives two cards
      and decides to obtain another, the resize() function will be called inside of 
      addCard() and make a larger hand for the player.


<><><><><><><><><><><><><><><><>
// THE "SHOE" DATA STRUCTURE" \\
<><><><><><><><><><><><><><><><>
    - Our "Shoe" data structure consists of three objects of the "Deck" structure.
    - shoeOfCards is an array of Card class objects with a size of MAX_CAP = 156. This is the
      size of three full decks, which is the initial state of the shoe.
    - In the game of Blackjack, each time that the player or dealer needs a card, they will 
      take one from the shoe to be placed in their respective Hand structures. This means that
      the size and contents of the shoe, once it has been shuffled and the game has begun, will
      consistently change throughout the course of the game.
    - Thus, we needed to create a dynamic data structure of Card class objects to hold the cards
      in the shoe, with the necessary functions implemented to add and remove cards as the game
      progresses, as well as the ability to fully reset once the number of cards remaining becomes
      depleted.
    - Similarly to the "Hand" data structure, we created functions to get the capacity of the array, 
      fully reset the shoe to its full size of 156 (shuffled) cards, as well as taking the top card
      off of the deck to be given to the player or dealer in the game.
    - When cards are taken out of the shoe and given to the hand of the dealer or the player,
      the "capacity" member variable, which represents the size of the shoe at any given point,
      is decremented. Then, all members of the shoe from the bottom of the deck up until the card
      that was dealt is copied into a new array with a size one smaller than before. This, in effect,
      removes the dealt card from the deck, but does not destroy the values completely. This caveat
      will be important when we call resetShoe().
    - Our shuffle() function takes a full, unsorted deck of 156 cards and randomizes their order.
    - Unlike the resize() function for Hand, the Shoe::resize() function is called when the "capacity"
      variable denoting the size of the shoe gets too small to deal a fair hand of Blackjack. When this
      occurs, the resetShoe() function is called.
    - As mentioned previously, when we decreased the size of the shoe, we did not fully delete the points
      of data holding the dealt cards. By resizing the array to MAX_CAP, we can reclaim the points of
      data still in memory back into our shoe. After doing this, we reshuffle the deck, in effect refreshing
      the shoe and allowing for a full range of cards to be available again.




