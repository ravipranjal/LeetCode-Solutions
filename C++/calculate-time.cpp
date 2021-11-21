#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int calculateTime(int dist, int speed) {
	return dist/speed;
}

int main() {
	int distance[5];
	int speed[5];
	bool terminate = false;

	cout<<"Enter distance and speed elements"<<endl;
	for(int i=0; i<5; i++) {
		cin>>distance[i];
		cin>>speed[i];
		if(distance[i] < 0 || speed[i] <= 0) {
			free(distance);
			free(speed);
			terminate = true;
		}
		cout<<"The time in nearest integer is: "<<calculateTime(distance[i], speed[i])<<endl;
		if(terminate) break;
	}
	
	return 0;
}
