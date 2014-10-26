#include <iostream>
#include <cstdlib>

// solution 1
int Rand5() {
	int result = 100;
	while (1) {
		result = Rand7();
		if (result <= 5) return result;
	}
	return rand() % 5 + 1;
}
int Rand7() {
	int x = 10000;
        while (x > 21){
		x = 5*(Rand5()-1) + Rand5();
	}	
	return x % 7 + 1;
		
}

// solution 2
we can create a binary tree. This only applies to Rand4 based on Rand2. 
