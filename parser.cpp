#include <iostream>
#include <vector>
#include "card.h"
#include "uno.h"
#include "parser.h"
#include <sstream>

using namespace std;
Parser::Parser() {}

void Parser::parse (std::istream& is, std::vector<Card*>& drawPile){

// initialize 0 cards with numcard type 
drawPile.clear();
srand(time(0)); 

int n, type;  

is >> n >> type;
 
for(int i=0; i < n; i++){
string color;
int number;
if(is >> color >> number){
Card* newc = new numCard(type, number, color);
drawPile.push_back(newc); }
std::cout << " added " << type << " " << number << " " << color << std::endl;  
}

is >> n >> type; 
for (int i=0; i < n; i++){ 
     string color;
     is >> color; 
     string line;
     getline(is, line);
     stringstream ss(line);
     int num;
     while(ss >> num){
          Card* newc = new numCard(type, num, color); 
          drawPile.push_back(newc);
          std::cout << " added " << type << " " << num << " " << color << std::endl;  
     }
} 

is >> n >> type;
is >> ws; 
for (int i=0; i < n; i++){ 
     string color;
     
     string line; 
     getline(is, line);
     stringstream ss(line);
     ss >> color;
     int action;
     //ss >> color;
     while(ss >> action){
        Card* newc = new specialCard(type, color, action);  // number is action
          drawPile.push_back(newc);
          std::cout << " added special " << action << " " <<  color << std::endl;  
     }
}

is >> n >> type;
for (int i=0; i < n; i++){
          Card* newc = new wildCard(type, 0);
          Card* newca = new wildCard(type, 1);  
     
          drawPile.push_back(newc);
          drawPile.push_back(newca); 
     }

// now shuffle the vector
/// from website c++ 
// shuffle the vector 

for (size_t i= drawPile.size() - 1; i > 0; i--){
     std::srand(time(0)); 
     size_t idx = rand() % (i + 1);
     std::swap(drawPile[i], drawPile[idx]);
   }
   
}
