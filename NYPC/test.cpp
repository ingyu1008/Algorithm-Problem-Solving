#include <iostream>
#include <vector>

int a[100000000];

int main(void){
	for(int i = 0; i < 100000000; i++){
		if((i % 10000000) == 0) std::cout << a[i] << "\n";
	}
}