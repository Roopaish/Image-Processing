#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

int main(){
  ifstream image;
  ofstream newImage;

  image.open("before-filtering.ppm");
  newImage.open("after-filtering.ppm");

  // Copy header info
  string type = "", width = "", height = "", max = "";
  image >> type >> width >> height >> max;
  // cout << type << " " << width << " " << height << " " << max << endl;
  newImage << type << endl;
  newImage << width << " " << height << endl;
  newImage << max << endl;

  string red = "", green = "", blue = "";
  int r = 0, g = 0, b = 0;

  while(!image.eof()){
    image >> red >> green >> blue;
    
    // Convert string to int
    stringstream redstream(red);
    stringstream greenstream(green);
    stringstream bluestream(blue);
    redstream >> r;
    greenstream >> g;
    bluestream >> b;

    if(b + 100 >= 255){
      b = 255;
    } else {
      b += 100;
    }

    newImage << r << " " << g << " " << b << " ";
  }

  image.close();
  newImage.close();

  return 0;
}