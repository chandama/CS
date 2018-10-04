#pragma once
#include "List.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
using namespace std;

class Deck
{
    private:
    List decklist;

    public:
    Deck(){}
    ~Deck(){}
    void createDeck(string newDeck);
    void shuffle();
    void drawCard(bool turn);
    void dealCards();
    void displayDeck();
    void displayPlayerHand();
    void displayComputerHand();//Maybe not needed if called correctly
    void play(int handSize);
    void guessCard();
    void checkMatch();
    string get_string_at(int i);
    int get_int_at(int i);
    int deckSize();
    
    
};