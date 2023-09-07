#ifndef _MOVIE
#define _MOVIE

#include <string>
using namespace std;

class Movie {
private:
  int m_id;
  string m_movie_title;
  string m_rating;
  int m_year;
  int m_quantity;

public:
  int getId();
  string getMovieTitle();
  string getRating();
  int getYear();
  int getQuantity();
  void Setup(int id, string movieTitle, string rating, int year, int quantity);
  void setQuantity(int quantity);
};

#endif