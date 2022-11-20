#include <iostream>
#include <cstring>
#include <music.h>

using namespace std;

Music::PrintOutput() {
  cout << "----------------------------------------------" << endl;
  cout << "Title: " << title << endl;
  cout << "Year: " << year << endl;
  cout << "Duration: " << duration << endl;
  cout << "Publisher: " << publisher << endl;
  cout << "Artist: " << artist << endl;
}
