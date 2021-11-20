#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int calculateTime(int dist, int speed) {
	return dist/speed;
}

int main() {
	int distance[5] = {10, 20, 30, 40, 50};
	int speed[5] = {2, 3, 4, 5, 6};

	free(distance);
	
	for(int i=0; i<5; i++) {
		if(distance[i] && speed[i]) {
			cout<<calculateTime(distance[i], speed[i])<<endl;
		}
	}
	
	return 0;
}
