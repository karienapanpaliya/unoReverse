#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <string>
#include <iostream>

struct Player{
    Player();
    ~Player();
    bool play(Card* top, std::vector <Card*>& drawPile, std::vector<Card*>& discardPile); 
    void printHand(); 
    std::vector<Card*> hand_; 
    bool hasWon; 
};



#endif


