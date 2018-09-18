#include <iostream>
#include <sstream> // oh stringstream that's neat maybe that's convenient
#include <fstream>

#include <vector> //hmmm what's this maybe this is useful

using namespace std;

struct Pixel {
 //hmm this could be useful but who knows
 int r;
 int g;
 int b;
};

int main() {
  int width = 0;
  int height = 0;

  ifstream in;
  in.open("in.data", ios::in);

  if(in.is_open()) { //if the file is open
    string line;
    getline(in, line); //stores a line in line
    width = stoi(line);

    getline(in, line);
    height = stoi(line);

    //TODO set up data structures
    Pixel arrPix[125][125];// maybe a 2d vector would be useful?
    int x;
    int y;

    while(getline(in, line)){  //reads a line at a time

      //TODO read in pixel data
      stringstream stream(line);

      stream >> x;
      stream >> y;
      stream >> arrPix[x][y].r;
      stream >> arrPix[x][y].g;
      stream >> arrPix[x][y].b;
    }

    cout << "Width = " << width << endl; //Print to console
    cout << "Height = " << height << endl;

    ofstream out;
    out.open("out.ppm", ios::out);
    if(out.is_open()) { //if the file is open
      out << "P3" << endl; //write to file
      out << width << " " << height << endl; 
      out << 255 << endl;

      //TODO writing your pixel data in ppm form
      for(int i = 0; i < 125; i++){
	  for(int j = 0; j < 125; j++){
	      out << arrPix[i][j].r << " " << arrPix[i][j].g << " " << arrPix[i][j].b << "\t";
	  }
	  out << endl;
      }
      out.close();
    }
    in.close();  
  }



}
