#ifndef _PROGRAM
#define _PROGRAM

#include "Movie.h"
#include "Functions.h"
#include <string>
using namespace std;

class Program {
  public:
  void Menu_Main();
  void Menu_ViewMovies();
  void Menu_Checkout();
  void Menu_Checkin();

  private:
  void Setup();

  Movie m_movie0, m_movie1, m_movie2, m_movie3, m_movie4;
};

#endif