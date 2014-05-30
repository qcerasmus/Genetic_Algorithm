#include <iostream>
#include <vector>
#include "Child.h"
#include <cstdlib>
#include <time.h>
#include <algorithm>

using namespace std;

bool compare(const Child& lhs, const Child& rhs) {
  return lhs.strength > rhs.strength;
}

void print_best_child(const Child& best) {
  cout << "The best child was: \"" << best.word << "\" with strength: " << best.strength << endl;
}

void calculate_strength(Child& child, string user_input) {
  child.strength = 0;
  for( int i = 0 ; i < user_input.length() ; i++ ) {
    if(child.word[ i ] == user_input[ i ]) {
      child.strength++;
    }
  }
}

int main() {
  srand (time(NULL));
  
  // string user_input = "This sentence should be extremely long! 21236543";
  cout << "Please enter a word to guess: " << endl;
  string user_input;
  getline(cin, user_input);
  
  vector<Child> children = vector<Child>(100);

  //Initialize all the children here and print the best one.
  for( int i = 0 ; i < children.size() ; i++ ) {
    children.at(i).word = user_input;
    for( int j = 0 ; j < user_input.length() ; j++ ) {
      children.at(i).word[ j ] = rand() % 128;
    }
    calculate_strength(children.at(i), user_input);
  }
  size_t round = 1;
  cout << "Round #" << round << endl;
  sort(children.begin() , children.end() , compare);
  print_best_child(children.at( 0 ));
  
  //Base all the children on one of the 5 best ones and mutate a random letter.
  while(children.at( 0 ).strength != user_input.length()) {
    for( int i = 5 ; i < children.size() ; i++ ) {
      children.at( i ).word = children.at( rand() % 5 ).word;
      children.at( i ).word[ rand() % user_input.length() ] = rand() % 128;
      calculate_strength(children.at( i ), user_input);
    }
    round++;
    cout << "Round #" << round << endl;
    sort(children.begin() , children.end() , compare);
    print_best_child(children.at( 0 ));
  }
  return 0;
}
