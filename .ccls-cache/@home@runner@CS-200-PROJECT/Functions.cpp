#include "Functions.h"
#include <iostream>
using namespace std;

int GetChoice(int min, int max) {
  int choice;
  cout << ">> ";
  cin >> choice;

  while (choice < min || choice > max) {
    cout << "INVALID, must be between " << min << "-" << max << endl;
    cout << ">> ";
    cin >> choice;
  }

  return choice;
}