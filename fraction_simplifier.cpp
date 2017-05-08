//============================================================================
// Name        : Fraction Simplifier
// Author      : Martin Rivera
// Version     : 1
// Description : Takes in fraction numerator and denominator, finds GCD between them,
//					divides numerator and denominator by GCD.
//============================================================================

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


// Prototype GCD function
int find_gcd(int x, int y);

int main(int argc, char *argv[]) {
	int num = 0, den = 0;				// sorts inputs.
	for(int i = 0; i < argc; i++){
		if(std::string(argv[i]) == "-num"){
			string temp = std::string(argv[i+1]);
			num = atoi(temp.c_str());
		}

		if(std::string(argv[i]) == "-den"){
			string temp = std::string(argv[i+1]);
			den = atoi(temp.c_str());
		}
	}

	int common = find_gcd(num,den);		// calculate GCD between numerator and denominator.
	cout << num << "/" << den			// prints simplified function to screen.
			<< " simplified is "
			<< num/common << "/"
			<< den/common << ".";
	return 0;
}

// Function to find GCD.
int find_gcd(int x, int y){
	int high, low;
	if(x > y){
		high = x;
		low = y;
	}else{
		high = y;
		low = x;
	}

	int rem = high%low;
	if(rem == 0){
		return low;
	}else{
		return find_gcd(low, rem);
	}
}
