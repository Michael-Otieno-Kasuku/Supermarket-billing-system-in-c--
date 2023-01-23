//craeting a dev C++ class with 3 files
#ifndef VIDEOGAME_H
#define VIDEOGAME_H
#include<string.h>
#include<iostream>
using namespace std;

class VideoGame
{
	private:
		string title;
		string console;
		double price;
		int releaseYear;
		int numberInstock;
	public:
		VideoGame();//default constructor
		VideoGame(string , string c, double p, int year, int number);
		string getTitle();
		string getConsole();
		string getPrice();
		string getReleaseYear();
		string getnumberInstock();
		void setTitle(string t);
		void setConsole(string c);
		void setPrice(double p);
		void setReleaseYear(int year);
		void setNumberInstock(int number);
		void increaseNumberInstock(int number);//increase NumberInstock by number
		void decreaseStock(int number);//decrease numberInstock by number
		void display();
};

#endif
