#include <iomanip>
#include <iostream>
#include <string>
#include "Program.h"
using namespace std;

int main() {
  cout << left << fixed << setprecision( 2 );

  Program program;
  program.Menu_Main();

 return 0;
}