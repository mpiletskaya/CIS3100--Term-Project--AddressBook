#include <fstream>
#include "Menu.h"

using namespace std;


void main(){
	//show menu
	Menu menu;
	menu.showMenu();
}

/*
Example of writing to a file
void writeText(){
  ofstream myfile;
  myfile.open ("contacts.txt");
  myfile << "Writing this to a file.\n";
  myfile.close();
}
*/
