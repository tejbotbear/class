#include <iostream>
#include <cstring>

using namespace std;

class Movies : public Media {
 public:
  int duration;
  int rating;
  char* director;

  void PrintOutput() {
    cout << "----------------------------------------------" << endl;
    cout << "Title: " << title << endl;
    cout << "Year: " << year << endl;
    cout << "Duration: " << duration << endl;
    cout << "Rating: " << rating << endl;
    cout << "Director: " << director << endl;
  }

  Movies() {
    director = new char[100];
  }

  ~Movies() {
    delete director;
  }
};
