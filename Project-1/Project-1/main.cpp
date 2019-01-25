/* Project 1,2,3
 * CSC-114
 * Khalidah Abdul-Muqtadir
 * Write a program that deals 13 cards from a deck to 4 players
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>

using namespace std;


//Global constants
const int NUM_CARDS = 52;
const int NUM_PLAYERS=4;

const string RANKS[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10",
    "Jack", "Queen", "King"};
const string SUITS[] = {"Spades", "Hearts", "Diamonds", "Clubs"};


//Create Function prototypes for card loading and shuffling deck of

void unwrap(vector<int> &);
void shuffle(vector<int> &);
void printCards(vector<int>);

//Function for dealing cards to players
void deal(vector<vector<int>>&hands, vector<int>&deck);
void showHands(const vector<vector<int>>&hands);

//Function for sorting cards
void sort(vector<int>&);
void swap(vector<int> &deck, int first, int second);


int main() {
    
    //Declare vector for the number of cards
    vector<int>deck;
    
    cout << "The deck, unwrapped: " << endl;
    unwrap(deck);
    printCards(deck);
    
    cout << " The deck after shuffling: " << endl;
    shuffle(deck);
    printCards(deck);
    
    cout << " The deck after sorting: " << endl;
    sort(deck);
    printCards(deck);
    
    //Declare 2d vector for dealing the cards to each player
    vector<vector<int>> players(NUM_PLAYERS);
    
    cout << " Before cards have been dealt " << endl;
    showHands(players);
    
    cout << " After the cards have been dealt "<<endl;
    deal(players, deck);
    showHands(players);
    
    return 0;
}

void swap(vector<int> &deck, int first, int second)
{
    int temp = deck[first];
    deck[first] = deck[second];
    deck[second] = temp;
}
//Function definitions that load cards and randomly shuffles them
void unwrap(vector<int> &deck)
{
    //Load vector with ints from 0 to 51
    deck.clear();        // ensure that it starts emtpy
    for (int i = 0; i < NUM_CARDS; i++)
    {
        deck.push_back(i);
    }
}

// Randomize the cards in the deck
void shuffle(vector<int> &deck)
{
    random_shuffle(deck.begin(), deck.end());
    
}

// Print the card's name to cout
void printCard(int card)
{
    cout << RANKS[card % 13] << " of " << SUITS[card / 13];
}


void printCards(vector<int> deck)
{
    for(size_t j=0; j<deck.size(); j++)
    {
        if (j%8==0)
            cout << endl;
        printCard(deck[j]);
        cout << ", ";
    }
    cout << endl << endl;
}
// deal one card to each player in order, repeat until the entire deck is dealt
void deal(vector<vector<int>>& players, vector<int>& deck)
{
    // clear the players' hands
    for (size_t i = 0; i < players.size(); ++i) {
        players[i].clear();
    }
    
    // Deal the cards from deck to the hands.
    for (size_t i = 0; i < deck.size(); ++i) {
        players[i%players.size()].push_back(deck[i]);
    }
    //clear deck
    deck.clear();
}

//Show hand after cards have been randomly dealt to each player
void showHands(const vector<vector<int>>& players)
{
    for (size_t i = 0; i < players.size(); ++i) {
        cout << "PLAYER " << i + 1 << ":\n";
        cout << "------" <<endl;
        printCards(players[i]);
    }
}

void sort(vector<int> &deck)
{
    int i, j;
    
    for(i = 0; i<NUM_CARDS-1; i++)
    {
        for(j = i+1; j<NUM_CARDS; j++)
        {
            if( deck[j] < deck[i] )
            {
                swap(deck, j, i);
            }
        }
    }
}
