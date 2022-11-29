#include <iostream>
#include <cstring>

using namespace std;

class VideoGame : public Media {
 public:
  int rating;
  char* publisher;
  

  void PrintOutput() {
    cout << "----------------------------------------------" << endl;
    cout << "Title: " << title << endl;
    cout << "Year: " << year << endl;
    cout << "Rating: " << rating << endl;
    cout << "Publisher: " << publisher << endl;
    return;
  }

  VideoGame() {
    publisher = new char[100];
  }

  ~VideoGame() {
    delete publisher;
  }
};
