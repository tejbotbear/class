/*
  Tej Hiremath
  -
  -
*/

#include <iostream>
#include <vector>
#include "media.h"
#include "videogames.h"
#include "music.h"
#include "movies.h"
using namespace std;

void Delete(vector <VideoGame> &VideoGameVect, vector <Music> &MusicVect, vector <Movies> &MovieVect);
void ADD(vector <VideoGame> &VideoGameVect, vector <Music> &MusicVect, vector <Movies> &MovieVect);
void ACTION(vector <VideoGame> &VideoGameVect, vector <Music> &MusicVect, vector <Movies> &MovieVect);

int main() {

  vector <Music> MusicVect;
  vector <Movies> MovieVect;
  vector <VideoGame> VideoGameVect;
  
  ACTION(VideoGameVect, MusicVect, MovieVect);
}

void ADD(vector <VideoGame> &VideoGameVect, vector <Music> &MusicVect, vector <Movies> &MovieVect) {
  
  char Input[10] = {'\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'};
  char videogame[] = "VIDEOGAME";
  char music[] = "MUSIC";
  char movie[] = "MOVIE";

  cout << "What kind of media are you trying to add? Your options are: 'VIDEOGAME', 'MOVIE', or 'MUSIC'." << endl;
  cin.getline(Input, 10);

  if (!strcmp(Input, videogame)) {
    VideoGame* Game = new VideoGame();
    cout << "What is the title of this videogame?" << endl;
    cin >> Game->title;
    cout << "What is the year this game was published?" << endl;
    cin >> Game->year;
    cout << "What is the rating of this videogame?" << endl;
    cin >> Game->rating;
    cout << "Who is the publisher of this game?" << endl;
    cin >> Game->publisher;
    VideoGameVect.push_back(*Game);
  }
  else if (!strcmp(Input, music)) {
    Music* Mus = new Music();
    cout << "What is the title of this song?" << endl;
    cin >> Mus->title;
    cout << "What is the year this song was published?" << endl;
    cin >> Mus->year;
    cout << "How long is this song (in seconds)" << endl;
    cin >> Mus->duration;
    cout << "Who published this song?" << endl;
    cin >> Mus->publisher;
    cout << "Who is the artist of this song?" << endl;
    cin >> Mus->artist;
    MusicVect.push_back(*Mus);
  }
  else if (!strcmp(Input, movie)) {
    Movies* Mov = new Movies();
    cout << "What is the title of this movie?" << endl;
    cin >> Mov->title;
    cout << "What is the year that this movie was published?" << endl;
    cin >> Mov->year;
    cout << "How long is this movie? (in minutes)" << endl;
    cin >> Mov->duration;
    cout << "What is this movie rated?" << endl;
    cin >> Mov->rating;
    cout << "Who is the director of this movie?" << endl;
    cin >> Mov->director;
    MovieVect.push_back(*Mov);
  }
  else {
    cout << "Not a valid input." << endl;
  }

}

void ACTION(vector <VideoGame> &VideoGameVect, vector <Music> &MusicVect, vector <Movies> &MovieVect) {
  //  char Input[10] = {'\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'};
  char Input[10] = {0};
  char search[] = "SEARCH";
  char add[] = "ADD";
  char del[] = "DELETE";
  char quit[] = "QUIT";
  char title[] = "TITLE";
  char year[] = "YEAR";
  int yearinput;
  char titleinput[100];
  bool ignore = false;
  int l;
  int k = 1;
  do {
    for (int l = k; l < k; l++) {
      cout << "Press enter to begin" << endl;
      ignore = true; 
    }
  } while (ignore == true);
  do {
    for(int i = 0; i < 10; i++) Input[i] = '\0';
    cin.ignore();
    cout << "You are now in the action menu. Type 'ADD' to add new media, or type 'SEARCH' to search through currently stored media. Additionally, entering 'DELETE' allows you to delete a media entry of your choice. 'QUIT' will end the program." << endl;
    cin.getline(Input, 10);

    if (!strcmp(Input, add)) {
      ADD(VideoGameVect, MusicVect, MovieVect);
    }
    else if (!strcmp(Input, del)) {
      Delete(VideoGameVect, MusicVect, MovieVect);
    }
    else if (!strcmp(Input, search)) {
      for(int i = 0; i < 10; i++) Input[i] = '\0';
      cout << "Enter 'YEAR' to search by publish year, or input 'TITLE' to search by title" << endl;
      cin.getline(Input, 10);
      if (!strcmp(Input, year)) {
	for(int i = 0; i < 10; i++) Input[i] = '\0';
	cout << "What year do you want to search for?" << endl;
	cin >> yearinput;
	int j = VideoGameVect.size();
	for (int i = 0; i < j; i++) {
	  VideoGame Game = VideoGameVect[i];
	  cout << "Results for your search" << endl;
	  if (Game.year == yearinput) {
	    Game.PrintOutput();
	  }
        }
	j = MusicVect.size();
	for (int i = 0; i < j; i++) {
	  Music Mus = MusicVect[i];
	  if ( Mus.year == yearinput) {
	    Mus.PrintOutput();
	  }
        }
	j = MovieVect.size();
	for (int i = 0; i < j; i++) {
	  Movies Mov = MovieVect[i];
	  if (Mov.year == yearinput) {
	    Mov.PrintOutput();
	  }
	}
      }
      else if (!strcmp(Input, title)) {
	for(int i = 0; i < 10; i++) Input[i] = '\0';
	cout << "What title do you want to search for?" << endl;
	cin >> titleinput;
	int j = VideoGameVect.size();
	for (int i = 0; i < j; i++) {
	  VideoGame Game = VideoGameVect[i];
	  cout << "Results for your search" << endl;
          if (!strcmp(Game.title, titleinput)) {
	    Game.PrintOutput();
	  }
	}
        j = MusicVect.size();
        for (int i = 0; i < j; i++) {
          Music Mus = MusicVect[i];
          if (!strcmp(Mus.title, titleinput)) {
            Mus.PrintOutput();
          }
        }
        j = MovieVect.size();
        for (int i = 0; i < j; i++) {
          Movies Mov = MovieVect[i];
          if (!strcmp(Mov.title, titleinput)) {
             Mov.PrintOutput();
          }
	}
      }
    }
  } while (strcmp(Input, quit));
}

void Delete(vector <VideoGame> &VideoGameVect, vector <Music> &MusicVect, vector <Movies> &MovieVect) {
  char Input[10] = {'\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'};
  char videogame[] = "VIDEOGAME";
  char music[] = "MUSIC";
  char movie[] = "MOVIE";
  //char quit[] = "QUIT";
  char yes[] = "YES";
  char no[] = "NO";
  int yearinput;
  char year[] = "YEAR";
  char title[] = "TITLE";
  char titleinput[100];
  
  for(int i = 0; i < 10; i++) Input[i] = '\0';

  cout << "Enter 'YEAR' to search by publish year, or input 'TITLE' to search by title" << endl;
  cin.getline(Input, 10);
  if (!strcmp(Input, year)) {
    for(int i = 0; i < 10; i++) Input[i] = '\0';
    cout << "What year do you want to search for?" << endl;
    cin >> yearinput;
    int j = VideoGameVect.size();
    for (int i = 0; i < j; i++) {
      VideoGame Game = VideoGameVect[i];
      cout << "Results for your search" << endl;
      if (Game.year == yearinput) {
        Game.PrintOutput();
      }
    }
    j = MusicVect.size();
    for (int i = 0; i < j; i++) {
      Music Mus = MusicVect[i];
      if ( Mus.year == yearinput) {
	Mus.PrintOutput();
      }
    }
    j = MovieVect.size();
    for (int i = 0; i < j; i++) {
      Movies Mov = MovieVect[i];
      if (Mov.year == yearinput) {
        Mov.PrintOutput();
      }
    }
    for(int i = 0; i < 10; i++) Input[i] = '\0';
    cout << "Would you like to delete these objects? ('YES', 'NO')" << endl;
    cin.getline(Input, 10);

    if (!strcmp(Input, yes)) {
      j = VideoGameVect.size();
      for (int i = 0; i < j; i++) {
	VideoGame Game = VideoGameVect[i];
	if (Game.year == yearinput) {
	  VideoGameVect.erase(VideoGameVect.begin()+i);
	  delete &Game;
	}
      }
      j = MusicVect.size();
      for (int i = 0; i < j; i++) {
	Music Mus = MusicVect[i];
	if (Mus.year == yearinput) {
	  MusicVect.erase(MusicVect.begin()+i);
	  delete &Mus;
	}
      }
      j = MovieVect.size();
      for (int i = 0; i < j; i++) {
	Movies Mov = MovieVect[i];
	if (Mov.year == yearinput) {
	  MovieVect.erase(MovieVect.begin()+i);
	  delete &Mov;
	}
      }
    }
    else if (!strcmp(Input, no)) {
        ACTION(VideoGameVect, MusicVect, MovieVect);
    }
  }
  else if (!strcmp(Input, title)) {
    for(int i = 0; i < 10; i++) Input[i] = '\0';
    cout << "What title do you want to search for?" << endl;
    cin >> titleinput;
    int j = VideoGameVect.size();
    for (int i = 0; i < j; i++) {
      VideoGame Game = VideoGameVect[i];
      cout << "Results for your search" << endl;
      if (!strcmp(Game.title, titleinput)) {
        Game.PrintOutput();
      }
    }
    j = MusicVect.size();
    for (int i = 0; i < j; i++) {
      Music Mus = MusicVect[i];
      if (!strcmp(Mus.title, titleinput)) {
        Mus.PrintOutput();
      }
    }
    j = MovieVect.size();
    for (int i = 0; i < j; i++) {
      Movies Mov = MovieVect[i];
      if (!strcmp(Mov.title, titleinput)) {
         Mov.PrintOutput();
      }
    }
    for(int i = 0; i < 10; i++) Input[i] = '\0';
    cout << "Would you like to delete these objects? ('YES', 'NO')" << endl;
    cin.getline(Input, 10);

    if (!strcmp(Input, yes)) {
      j = VideoGameVect.size();
      for (int i = 0; i < j; i++) {
	VideoGame Game = VideoGameVect[i];
	if(!strcmp(Game.title, titleinput)) {
	  VideoGameVect.erase(VideoGameVect.begin()+i);
	  delete &Game;
	}
      }
      j = MusicVect.size();
      for (int i = 0; i < j; i++) {
	Music Mus = MusicVect[i];
	if(!strcmp(Mus.title, titleinput)) {
	  MusicVect.erase(MusicVect.begin()+i);
	  delete &Mus;
	}
      }
      j = MovieVect.size();
      for (int i = 0; i < j; i++) {
	Movies Mov = MovieVect[i];
	if(!strcmp(Mov.title, titleinput)) {
	  MovieVect.erase(MovieVect.begin()+i);
	  delete &Mov;
	}
      }
    }
    else if (!strcmp(Input, no)) {
        ACTION(VideoGameVect, MusicVect, MovieVect);
    }
  }  
}
