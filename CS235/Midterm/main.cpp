

#include "Deck.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

string string_guess(string deck){
    if (deck == "pokedeck.txt") {
        int random = (rand()%11 + 1);
        if (random == 1) {return "bulbasaur";}
        if (random == 2) {return "ivysaur";}
        if (random == 3) {return "venasaur";}
        if (random == 4) {return "charmander";}
        if (random == 5) {return "charmeleon";}
        if (random == 6) {return "charizard";}
        if (random == 7) {return "squirtle";}
        if (random == 8) {return "wartortle";}
        if (random == 9) {return "blastoise";}
        if (random == 10) {return "pikachu";}
        if (random == 11) {return "raichu";}
    }
    else if (deck == "deck_small.txt"){
        int random = (rand()%2 + 1);
        if (random == 1) {return "Fish";}
        if (random == 2) {return "Cat";}       
    }
    else if (deck == "deck_large.txt") {
        int random = (rand()%15 + 1);
        if (random == 1) {return "minnow";}
        if (random == 2) {return "carp";}
        if (random == 3) {return "salmon";}
        if (random == 4) {return "albacore";}
        if (random == 5) {return "blowfish";}
        if (random == 6) {return "cod";}
        if (random == 7) {return "catfish";}
        if (random == 8) {return "dogfish";}
        if (random == 9) {return "flagfin";}
        if (random == 10) {return "goldfish";}
        if (random == 11) {return "herring";}    
        if (random == 12) {return "guppy";}
        if (random == 13) {return "loach";}
        if (random == 14) {return "mulet";}
        if (random == 15) {return "tuna";}
    }
    else {
        cout << "Deck doesn't match any of the imported decks!\n";
        return " ";
    }
        
}

int number_guess(string deck){
    if (deck == "pokedeck.txt") {
        int random = (rand()%3 + 1);
        return (random);
    }
    else if (deck == "deck_small.txt"){
        int random = (rand()%3 + 1);
        return (random);        
    }
    else if (deck == "deck_large.txt") {
        int random = (rand()%15 + 1);
        return (random);        
    }
    else {
        cout << "Deck doesn't match any of the imported decks!\n";
        return -1;
    }
}

int main() {

    Deck player_deck;
    Deck comp_deck;
    Deck drawstack;
    string currentdeck;
    bool player_turn = true;
    int choice_num = 0;
    int play_menu = 0;
    const int NUM_CHOICES = 4;
    const int PLAY_CHOICES = 5;
    
    string choices[] = {
        "1. Create new deck",
        "2. Display current deck",
        "3. Play!!!",
        "4. Quit"
    };
    string play[] = {
        "1. Make Guess",
        "2. Shuffle Deck",
        "3. Display Deck",
        "4. Display Computer Hand",
        "5. Give Up"
    };
    
    cout << "Welcome to Ultimate Go-Fish Simulatior v1.0!\n";
    while (choice_num < NUM_CHOICES) {

        // Select the next operation.
        cout << "Please choose from the options below:\n";
        for (int i = 0; i < NUM_CHOICES; i++) {
          cout << choices[i] << endl;
        }
        cin >> choice_num;
        //Check for valid integer input
        if(cin.fail() || choice_num < 1 || choice_num > NUM_CHOICES)
        {
            cin.clear();
            cin.ignore();
            cout << "Please enter a valid input\n";
        }
        else
        {
            switch (choice_num) {
                case 1:
                {
                    string deckfile;
                    string line;
                    string deck;
                    stringstream ss;
                    
                    cout << "Create New Deck\n";
                    cout << "Please enter a .txt filename to import: ";
                    cin.ignore();
                    getline(cin, deckfile);
                    cout << endl;
                    currentdeck = deckfile;
                    
                    ifstream ifs;
                    ifs.open(deckfile); //Open up the .txt file
                    if (ifs) {
                        ss << ifs.rdbuf();
                    }
                    deck = ss.str() + ss.str();
                    
                    drawstack.createDeck(deck);
                    cout << "Display deck: " << endl;
                    drawstack.displayDeck();
                    cout << endl;
                    
                }
                    break;
                case 2:
                {
                    cout << "Display current deck\n";
                    drawstack.displayDeck();
                    cout << endl;
                }
                    break;
                case 3:
                {
                    //Deal cards 
                     
                    
                    //Play menu implemented after deal.
                    while (play_menu < PLAY_CHOICES) {
                        for (int i = 0; i < PLAY_CHOICES; i++) {
                            cout << play[i] << endl;
                        }
                        cin >> play_menu;
                        //Check again for valid input
                        if(cin.fail() || play_menu < 1 || play_menu > PLAY_CHOICES)
                        {
                            cin.clear();
                            cin.ignore();
                            cout << "Please enter a valid input\n";
                            play_menu = 0;
                        }
                        else
                        {
                            switch(play_menu) {
                                case 1:
                                {
                                    cout << "Make Guess!" << endl;
                                    if (player_turn == true) {
                                        //Player makes guess
                                        //Search computer hand for match or draw from start of drawstack
                                        //Search hand for matches, discard, add points
                                        int guessnumber;
                                        string guesstype;
                                        
                                        cout << "Please guess a card type and a number: \n";
                                        cout << "Numeber: ";
                                        cin >> guessnumber;
                                        
                                        if (cin.fail()){
                                            cout << "You entered an invalid input" << endl;
                                            cin.clear();
                                            cin.ignore();
                                        }
                                        else {
                                        cout << endl << "Type: ";
                                        cin.ignore();
                                        getline(cin, guesstype);
                                        //Search Function
                                        
                                        
                                        //Draw card
                                        int size = drawstack.deckSize();
                                        cout << size << endl;
                                        int random = (rand()%size);
                                        cout << random << endl;
                                        int drawnum = player_deck.get_int_at(random);
                                        string drawstr = player_deck.get_string_at(random);
                                        

                                        
                                        
                                        }//end else
                                    }
                                    else {
                                        //Computer guess (automated)
                                        //search player hand or draw from end of drawstack
                                        //serach hand for matches, discard, points
                                        string guesstype = string_guess(currentdeck);
                                        int guessnumber = number_guess(currentdeck);
                                        
                                    }
                                }
                                    break;
                                case 2:
                                {
                                    cout << "Shuffle Deck: " << endl;
                                    drawstack.shuffle();
                                }
                                    break;    
                                case 3:
                                {
                                    cout << "Show Player Deck: " << endl;
                                    player_deck.displayPlayerHand();
                                }
                                     break;   
                                case 4:
                                {
                                   cout << "Show Computer Hand:" << endl;
                                   comp_deck.displayComputerHand();
                                }
                                    break;    
                                case 5:
                                {
                                    cout << "You gave up!!!";
                                }
                                    break;
                                default:
                                    break;
                            }//End Switch
                        }
                    }//End While
                }//End Case 3
                    break;
                case 4:
                {
                   /* cout << "                               .\n";
                    cout << "                            A       ;\n";
                    cout << "                  |   ,--,-/ \\---,-/|  ,\n";
                    cout << "                 _|\\,'. /|      /|   `/|-.\n";
                    cout << "             \\`.'    /|      ,            `;.\n";
                    cout << "            ,'\\   A     A         A   A _ /| `.;\n";
                    cout << "          ,/  _              A       _  / _   /|  ;\n";
                    cout << "         /\\  / \\   ,  ,           A  /    /     `/|\n";
                    cout << "         _| | _ \\         ,     ,             ,/  \\\n";
                    cout << "       // | |/ `.\\  ,-      ,       ,   ,/ ,/      \\/\n";
                    cout << "       / @| |@  / /'   \\  \\      ,              >  /|    ,--.\n";
                    cout << "      |\\_/   \\_/ /      |  |           ,  ,/       \\ \\  ./' __:..\n";
                    cout << "      |  __ __  |       |  | .--.  ,         >  >   |-'   /     `\n";
                    cout << "    ,/| /  '  \\ |       |  |     \\      ,           |    /\n";
                    cout << "   /  |<--.__,->|       |  | .    `.        >  >    /   (\n";
                    cout << "  /_,' \\  ^  /  \\     /  /   `.    >--            /^\\   |\n";
                    cout << "        \\___/    \\   /  /      \\__'     \\   \\   \\/   \\  |\n";
                    cout << "         `.   |/          ,  ,                  /`\\    \\  )\n";
                    cout << "           \\  '  |/    ,       V    \\          /        `-\\\n";
                    cout << "            `|/  '  V      V           \\    \\.'            \\_\n";
                    cout << "             '`-.       V       V        \\./'\\\n";
                    cout << "                 `|/-.      \\ /   \\ /,---`\\\n";
                    cout << "                  /   `._____V_____V'\n";*/
                    return 0;
                }
                    break;
                default:
                    break;
            }//End switch
        }
        play_menu = 0;
        choice_num = 0;
    }//End while

}