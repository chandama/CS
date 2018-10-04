
#include "Deck.h"

void Deck::createDeck(string newDeck)
{
   decklist.clear(); //First clear any current deck
    while (newDeck.length() > 2)
    {
        //Find any space and create substrings to parse string into words and numbers.
        int i = newDeck.find(" ");
        string card_type = newDeck.substr(0,i);
        int cnum = stoi(newDeck.substr(i+1,1));
        
        //Erase up to the space and insert new node at head with substr data.
        newDeck.erase(0, i+2);
       // cout << card_type << " " << cnum << endl;
       // cout << newDeck;
        decklist.insertHead(cnum, card_type);
    }
}

void Deck::shuffle()
{
   /* decklist.shuffleList();
    int max = decklist.numitems();
    for(int i=0; i < max; i++) {
        int card = rand()% max;
        decklist.insertTail(decklist.at(card));
        decklist.remove(card);
    }*/
}

void Deck::drawCard(bool turn)
{
    
    //Player turn
    if (turn == true) {
        //Get node values

        //
    }
    //Computer turn
    else {
        
    }
}

int Deck::get_int_at(int i) {
    return decklist.int_at(i);
}

string Deck::get_string_at(int i) {
    return decklist.st_at(i);
}

void Deck::dealCards()
{
    int size = decklist.numitems();
    
}

int Deck::deckSize() {
    return decklist.numitems();
}

void Deck::displayDeck()
{
    cout <<decklist.toString();
}

void Deck::displayPlayerHand()
{
    string str = decklist.toString();
    //Removes new lines from string to display hands.
    string::size_type pos = 0; 
    while ( ( pos = str.find ("\r\n",pos) ) != string::npos )
    {
    str.erase ( pos, 2 );
    }
    cout << str;
}

void Deck::displayComputerHand()
{
    string str = decklist.toString();
    //Removes new lines from string to display hands.
    string::size_type pos = 0; 
    while ( ( pos = str.find ("\r\n",pos) ) != string::npos )
    {
    str.erase ( pos, 2 );
    }
    cout << str;
}

void Deck::play(int handSize)
{
    
}