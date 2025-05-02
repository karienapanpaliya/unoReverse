#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include "card.h"
#include "parser.h"
#include "player.h"
#include "uno.h"

using namespace std;

int main(int argc, char* argv[]){
     if (argc < 2){
          cout << "no cards input" << endl;
          return 1;
     }

uno g; 
ifstream ifile(argv[1]);
Parser p; 
g.readCards(ifile,p);

Player p1, p2;
vector<Player*> players;
players.push_back(&p1);
players.push_back(&p2); 
g.dealCards(p1,p2); 

cout << "Cards have been dealt" << endl;


bool gameOver = false;
int n =0;
bool played = false; 
bool turn = 0; 
//Card* top = g.getTopCard(); 

//g.getDiscardPile().push_back(top); 
cout << "here " << endl;
cout << "Cards have been dealt" << endl;
cout << "Draw pile size: " << g.getDrawPile().size() << endl;
cout << "P1 hand size: " << p1.hand_.size() << endl;
cout << "P2 hand size: " << p2.hand_.size() << endl;

Card* top = g.getTopCard();
if(top == NULL){
    cout << "couldnt get top card" << endl;
    return 1;
}
cout << "Top card obtained" << endl;
g.getDiscardPile().push_back(top); 

while(!gameOver){
    n++; 
    // player has a turn 
    Player& currplayer = *players[turn];
    
    played = currplayer.play(top, g.getDrawPile(), g.getDiscardPile()); 
    if(played){
        top = g.getDiscardPile().back();
        cout << "new top " << endl; 
        top->printCard();
        
    }

    else{
        cout << "Didn't find a playable card, next player's turn" << endl; 
    }
        
    
    if(currplayer.hand_.size() == 1){
        cout << "UNO!" << endl; 
    }

    else if (currplayer.hand_.size() == 0){
        cout << "Player " << turn + 1 << " wins!" << endl; 
        gameOver = true; 
    }
    played = false; 
    turn = n % 2; 
    if(n >= 50){
        cout << "game terminated after 50 " << endl;
        break;
    }
}
return 0; 
}
