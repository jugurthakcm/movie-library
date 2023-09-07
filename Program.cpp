#include "Program.hpp"
#include "Functions.hpp"
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

void Program::Setup() {
  ifstream input;
  ofstream output;

  input.open("movies.txt");

  if (input.fail()) {
    output.open("movies.txt");

    // Setup movie class and save it to movies vector
    m_movie0.Setup(1, "Kiki's Delivery Service", "G", 1989, 10);
    movies.push_back(m_movie0);
    m_movie1.Setup(2, "My Neighbor Totoro", "G", 1988, 11);
    movies.push_back(m_movie1);
    m_movie2.Setup(3, "Castle in the Sky", "PG", 1986, 13);
    movies.push_back(m_movie2);
    m_movie3.Setup(4, "Spirited Away", "PG", 2001, 14);
    movies.push_back(m_movie3);
    m_movie4.Setup(5, "Princess Mononoke", "PG-13", 1997, 10);
    movies.push_back(m_movie4);

    // Save movies to movies.txt file
    for (size_t i = 0; i < movies.size(); i++) {
      output << "{" << endl;
      output << "TITLE" << endl;
      output << movies[i].getMovieTitle() << endl;
      output << "RATING" << endl;
      output << movies[i].getRating() << endl;
      output << "YEAR" << endl;
      output << movies[i].getYear() << endl;
      output << "QUANTITY" << endl;
      output << movies[i].getQuantity() << endl;
      output << "}" << endl;
    }
    output.close();
  } else {
    // Get data from movies.txt and save it to movies vector
    string buffer;
    string title, rating;
    int year, quantity, id = 1;

    while (getline(input, buffer)) {
      if (buffer == "TITLE") {
        getline(input, title);
      }

      else if (buffer == "RATING") {
        getline(input, rating);
      }

      else if (buffer == "YEAR") {
        input >> year;
      } else if (buffer == "QUANTITY") {
        input >> quantity;
      } else if (buffer == "}") {
        Movie movie;
        movie.Setup(id, title, rating, year, quantity);
        movies.push_back(movie);
        id++;
      }
    }
    input.close();
  }
}

void Program::Menu_Main() {
  Setup();
  bool quit = false;

  while (!quit) {
    cout << "DVDepot" << endl;
    cout << string(20, '-') << endl;
    cout << "MAIN MENU" << endl;

    cout << endl;

    cout << "0. Exit" << endl;
    cout << "1. View available movies" << endl;
    cout << "2. Check out customer" << endl;
    cout << "3. Check in movies" << endl;
    cout << "4. Add new movie" << endl;
    cout << "5. Edit new existing movie" << endl;

    cout << endl;
    int choice = GetChoice(0, 3);
    cout << endl;

    switch (choice) {
    case 0:
      quit = true;
      break;
    case 1:
      Menu_ViewMovies();
      break;
    case 2:
      Menu_Checkout();
      break;
    case 3:
      Menu_Checkin();
      break;
    }
  }
}

void Program::Menu_ViewMovies() {
  cout << "AVAILABLE MOVIES" << endl;
  cout << endl;

  DisplayMovies();

  cout << endl;
}

// Checkout Process
void Program::Menu_Checkout() {
  float priceNewFilm = 4.00;
  float priceOldFilm = 2.00;
  float totalPrice = 0;
  int amounttNewFilmRentals = 0;
  int amountOldFilmRentals = 0;
  int amountOfDaysRented = 0;
  int quantity = 0;
  int currentYear = 2001;
  int choiceID;
  bool quit = false;

  cout << "CHECK OUT CUSTOMER" << endl;
  cout << endl;

  DisplayMovies();
  cout << endl;

  /* *********************************************/
  while (!quit) {
    cout << "ENTER MOVIE ID TO CHECK OUT, OR 0 TO FINISH: ";

    cin >> choiceID;
    if (choiceID == 0) {
      quit = true;
    } else {
      for (size_t i = 0; i < movies.size(); i++) {
        if (movies[i].getId() == choiceID) {
          if (movies[i].getYear() == currentYear) {
            amounttNewFilmRentals++;
            cout << "Added movie \"" << movies[i].getMovieTitle() << "\""
                 << endl;
          } else {
            amountOldFilmRentals++;
            cout << "Added movie \"" << movies[i].getMovieTitle() << "\""
                 << endl;
          }
        }
      }
    }
  }

  cout << endl;
  cout << "Rent for how many days? ";
  cin >> amountOfDaysRented;
  while (amountOfDaysRented < 1) {
    cout << "Minimum rental time is 1 day. ";
    cout << "Rent for how many days? ";
    cin >> amountOfDaysRented;
  }

  totalPrice = ((priceNewFilm * amounttNewFilmRentals) +
                (priceOldFilm * amountOldFilmRentals)) *
               amountOfDaysRented;

  cout << endl;
  cout << fixed << setprecision(2);
  cout << "Total is $" << totalPrice << endl;

  cout << endl;
  cout << "Returning to the Main Menu" << endl;
  cout << endl;
}

// Checkin Process
void Program::Menu_Checkin() {
  int placeholder = 0;
  bool quit = false;
  int choiceID;

  cout << "CHECK IN MOVIE" << endl;
  cout << endl;

  DisplayMovies();

  cout << endl;

  while (!quit) {
    cout << "ENTER MOVIE ID TO CHECK OUT, OR 0 TO FINISH: ";

    cin >> choiceID;
    if (choiceID == 0) {
      quit = true;
    } else {
      for (size_t i = 0; i < movies.size(); i++) {
        if (movies[i].getId() == choiceID) {
          cout << "How many movies are you checking in? ";
          cin >> placeholder;
          movies[i].setQuantity(movies[i].getQuantity() + placeholder);
          cout << placeholder << " movies added" << endl;
        }
      }
    }
  }

  cout << endl;
  cout << "Inventory Updated" << endl;
  cout << endl;

  cout << "Returning to the Main Menu" << endl;
  cout << endl;
}