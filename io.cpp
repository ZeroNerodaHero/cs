#include <iostream>
#include <fstream>

#define LINES 250
int lines;
void printarr(char array[LINES][LINES], std::ofstream &out){
	for(int i = 0; i < lines; i++){
        for(int j = 0; j < lines; j++){
            out << array[i][j];
        }
		out << '\n';
    }
	return;
}

int main(){
	std::ifstream in("range.in");
	std::ofstream out("range.out");
	in >> lines; 
	char array[LINES][LINES];
	for(int i = 0; i < lines; i++){
		for(int j = 0; j < lines; j++){
			in >> array[i][j];
		}
	}

	out << lines << '\n';
	printarr(array,out);
	out.close();	
	in.close();
	return 0;
}
