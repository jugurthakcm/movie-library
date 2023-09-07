#include "Functions.hpp"
#include <iostream>
#include <iomanip>

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

void DisplayMovies(){
  cout << setw(10) << "ID" << setw(30) << "TITLE" << setw(10) << "RATING"
       << setw(10) << "QUANTITY" << setw(10) << "STATUS" << endl;

  for (size_t i = 0; i < movies.size(); i++) {
    cout << setw(10) << movies[i].getId() << setw(30)
         << movies[i].getMovieTitle() << setw(10) << movies[i].getRating()
         << setw(10) << movies[i].getQuantity() << setw(10)
         << movies[i].getYear() << endl;
  }
}