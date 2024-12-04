#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
  srand(time(NULL)); // Seed the random number generator
  int randomNumber;
  int x;
  int n;
  char again='y';
  do{
  std::cout<<"If you want to guess numbers between 0 and 10 press 1, if you want to guess numbers between 0 to 100 press 2, if you want to guess numbers between 0 to 1000 press 3, if you want to guess numbers between 0 to 10000 press 4: ";
  std::cin>>n;
  switch (n) {
    
    case 1:
      randomNumber = rand() % 10+1;
      std::cout << "Guess a number between 0 and 10: ";
      break;
    
    case 2:
      randomNumber = rand() % 100+1;
      std::cout << "Guess a number between 0 and 100: ";
      break;

    case 3:
      randomNumber = rand() % 1000+1;
      std::cout << "Guess a number between 0 and 1000: ";
      break;

    case 4:
      randomNumber = rand() % 10000+1;
      std::cout << "Guess a number between 0 and 10000: ";
      break;
  }
    
  std::cin >> x;
  while (randomNumber!=x){
    if (randomNumber>x){
      std::cout << "too low\n";
    }
    else{
      std::cout << "too high\n";
    }
    std::cout<<"try again: ";
    std::cin >> x;
  }
  std::cout << "correct\n";
  std::cout << "Do you want to play again? (y/n): ";
  std::cin >> again;
  } while(again=='y');
   std::cout << "Good Bey :) \n";
  return 0;
}