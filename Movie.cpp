#include "Movie.h"

// Implement movie functions
void Movie::Setup(int id, string movieTitle, string rating, int year,
                  int quantity) {
  m_id = id;
  m_movie_title = movieTitle;
  m_rating = rating;
  m_year = year;
  m_quantity = quantity;
}

string Movie::getMovieTitle() { return m_movie_title; }

string Movie::getRating() { return m_rating; }

int Movie::getYear() { return m_year; }

int Movie::getQuantity() { return m_quantity; }

void Movie::setQuantity(int quantity) { m_quantity = quantity; }

int Movie::getId() { return m_id; }