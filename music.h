#include <iostream>
#include <cstring>

using namespace std;

class Music : public Media {
 public:
  int duration;
  char publisher[100];
  char artist[100];

  void PrintOutput() {
    cout << "----------------------------------------------" << endl;
    cout << "Title: " << title << endl;
    cout << "Year: " << year << endl;
    cout << "Duration: " << duration << endl;
    cout << "Publisher: " << publisher << endl;
    cout << "Artist: " << artist << endl;
  }
};
