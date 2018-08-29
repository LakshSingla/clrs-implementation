#include <iostream>
#include <cstring>

using namespace std;

int substringSearch ( char*, char*);

int main () { 

	int a = substringSearch ( "Hello" , "e");
	int b = substringSearch ( "Hello" , "llo");
	int c = substringSearch ( "Hello" , "M");

	cout<<a<<endl;
	cout<<b<<endl;
	cout<<c<<endl;

	return 0;
}

int substringSearch ( char *essay, char *searchText) {

	int essayLength = strlen (essay);
	int searchTextLength = strlen(searchText);

	for (int i = 0; i <= (essayLength - searchTextLength); i++) {

		for ( int j = i , k = 0; k < searchTextLength ; j++, k++) {

			if ( essay[j] != searchText[k]) break;

			if ( k == (searchTextLength - 1 )) return i;

		}
			
	}

	return -1;  //Incase nowhere the string has been found
}
