#include <iostream>
#include <cstring>

using namespace std;

class Music : public Media {
 public:
  int duration;
  char* publisher;
  char* artist;

  void PrintOutput() {
    cout << "----------------------------------------------" << endl;
    cout << "Title: " << title << endl;
    cout << "Year: " << year << endl;
    cout << "Duration: " << duration << endl;
    cout << "Publisher: " << publisher << endl;
    cout << "Artist: " << artist << endl;
  }

  Music() {
    publisher = new char[100];
    artist = new char[100];
  }

  ~Music() {
    delete publisher;
    delete artist;
  }
};
