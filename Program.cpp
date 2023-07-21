#include "Program.h"
#include "Functions.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

vector<Movie> movies;

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

  cout << setw(10) << "ID" << setw(30) << "TITLE" << setw(10) << "RATING"
       << setw(10) << "QUANTITY" << setw(10) << "STATUS" << endl;

  for (size_t i = 0; i < movies.size(); i++) {
    cout << setw(10) << movies[i].getId() << setw(30)
         << movies[i].getMovieTitle() << setw(10) << movies[i].getRating()
         << setw(10) << movies[i].getQuantity() << setw(10)
         << movies[i].getYear() << endl;
  }
  cout << endl;
}


//Checkout Process
void Program::Menu_Checkout() {
  float priceNewFilm = 4.00;
  float priceOldFilm = 2.00;
  float totalPrice = 0;
  int amounttNewFilmRentals = 0;
  int amountOldFilmRentals = 0;
  int amountOfDaysRented = 0;
  int quantity = 0;
  int currentYear = 2001;

  cout << "CHECK OUT CUSTOMER" << endl;
  cout << endl;

  cout << "CHECK OUT how many copies of: " << m_movie0.getMovieTitle() << " ";
  quantity = GetChoice(0, m_movie0.getQuantity());
  m_movie0.setQuantity(m_movie0.getQuantity() - quantity);
  if (m_movie0.getYear() == 2001) {
    amounttNewFilmRentals += quantity;
  } else {
    amountOldFilmRentals += quantity;
  }

  cout << "CHECK OUT how many copies of: " << m_movie1.getMovieTitle() << " ";
  quantity = GetChoice(0, m_movie1.getQuantity());
  m_movie1.setQuantity(m_movie1.getQuantity() - quantity);
  if (m_movie1.getYear() == 2001) {
    amounttNewFilmRentals += quantity;
  } else {
    amountOldFilmRentals += quantity;
  }

  cout << "CHECK OUT how many copies of: " << m_movie2.getMovieTitle() << " ";
  quantity = GetChoice(0, m_movie2.getQuantity());
  m_movie2.setQuantity(m_movie2.getQuantity() - quantity);
  if (m_movie2.getYear() == 2001) {
    amounttNewFilmRentals += quantity;
  } else {
    amountOldFilmRentals += quantity;
  }

  cout << "CHECK OUT how many copies of: " << m_movie3.getMovieTitle() << " ";
  quantity = GetChoice(0, m_movie3.getQuantity());
  m_movie3.setQuantity(m_movie3.getQuantity() - quantity);
  if (m_movie3.getYear() == 2001) {
    amounttNewFilmRentals += quantity;
  } else {
    amountOldFilmRentals += quantity;
  }

  cout << "CHECK OUT how many copies of: " << m_movie4.getMovieTitle() << " ";
  quantity = GetChoice(0, m_movie4.getQuantity());
  m_movie4.setQuantity(m_movie4.getQuantity() - quantity);
  if (m_movie4.getYear() == 2001) {
    amounttNewFilmRentals += quantity;
  } else {
    amountOldFilmRentals += quantity;
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


//Checkin Process
void Program::Menu_Checkin() {
  int placeholder = 0;

  cout << "CHECK IN MOVIE" << endl;
  cout << endl;

  cout << "CHECK IN how many copies of \"Kiki's Delivery Service\"? ";
  cin >> placeholder;
  while (placeholder < 0) {
    cout << "Checkin ammount needs to be 0 or higher. ";
    cout << "CHECK IN how many copies? ";
    cin >> placeholder;
  }
  m_movie0.setQuantity(m_movie0.getQuantity() + placeholder);

  cout << "CHECK IN how many copies of \"My Neighbor Totoro\"? ";
  cin >> placeholder;
  while (placeholder < 0) {
    cout << "Checkin ammount needs to be 0 or higher. ";
    cout << "CHECK IN how many copies? ";
    cin >> placeholder;
  }
  m_movie1.setQuantity(m_movie1.getQuantity() + placeholder);

  cout << "CHECK IN how many copies of \"Castle in the Sky\"? ";
  cin >> placeholder;
  while (placeholder < 0) {
    cout << "Checkin ammount needs to be 0 or higher. ";
    cout << "CHECK IN how many copies? ";
    cin >> placeholder;
  }
  m_movie2.setQuantity(m_movie2.getQuantity() + placeholder);

  cout << "CHECK IN how many copies of \"Spirited Away\"? ";
  cin >> placeholder;
  while (placeholder < 0) {
    cout << "Checkin ammount needs to be 0 or higher. ";
    cout << "CHECK IN how many copies? ";
    cin >> placeholder;
  }
  m_movie3.setQuantity(m_movie3.getQuantity() + placeholder);

  cout << "CHECK IN how many copies of \"Princess Mononoke\"? ";
  cin >> placeholder;
  while (placeholder < 0) {
    cout << "Checkin ammount needs to be 0 or higher. ";
    cout << "CHECK IN how many copies? ";
    cin >> placeholder;
  }
  m_movie4.setQuantity(m_movie4.getQuantity() + placeholder);

  cout << endl;
  cout << "Inventory Updated" << endl;
  cout << endl;

  cout << "Returning to the Main Menu" << endl;
  cout << endl;
}