#include "utils.h"

bool isInt(char *str, size_t size){
	for (int i = 0; i < size; i++){
		if((str[i] <=47) | (str[i] >=58)){
			return false; }
	}
	return true;

}

int ipow(int a, int b){
	int total = 1;
	for (int i = 0; i < b; i++){
		total *= a; 	
	}
	return total;
}
int toInt(char *str, size_t size){
	int total = 0;	
	for (int i = 0; i < size; i++){
		total = total + (ipow(10, (size-i-1)) * (str[i] - 48));	
	}
	return total;
}

