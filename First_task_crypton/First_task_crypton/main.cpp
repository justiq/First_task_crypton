#include <vector>
#include <time.h>
#include <iostream>
#include <random>

int input_check(); // Is input correct?
int rand_num(int&, int&);	// randomizer
void print_array(const std::vector<int>&);
int kinda_interface();

int main() {

	int buf_num = 0;
	int variation = 0; //sort variation
	int lim_1, lim_2; //limtis for array gneration
	std::vector<int> vec_array; 

	std::cout << "This prograrmm automaticaly generates 30 random integer numbers betwen 2 limits you'll write \n";
	
	std::cout << "First limit: ";
	lim_1 = input_check();

	std::cout << "Second limit: ";
	lim_2 = input_check();

	if (lim_2 < lim_1)	// checks limits order
		std::swap(lim_1, lim_2);
	
	for (int i = 0; i < 30; i++){ //generating new array
		vec_array.emplace_back(rand_num(lim_1, lim_2));
	}
	
	std::cout << "Created array: ";
	print_array(vec_array);
	
	while (variation < 1 || variation > 3) //choise of sort
		variation = kinda_interface();

	if (variation == 1) {
		for (auto it = vec_array.begin(); it != vec_array.end(); ) {	//EVEN numbers delition
			if (*it % 2 == 0) {
				it = vec_array.erase(it);
			}
			else {
				++it;
			}
		}
		std::sort(vec_array.begin(), vec_array.end());
		std::cout << "Result: ";
		print_array(vec_array);
		std::cout << "\n";
	}

	else if (variation == 2) {
		for (auto it = vec_array.begin(); it != vec_array.end(); ) { //ODD numbers delition
			if (*it % 2 != 0) {
				it = vec_array.erase(it);
			}
			else {
				++it;
			}
		}
		std::sort(vec_array.rbegin(), vec_array.rend());
		std::cout << "Result: ";
		print_array(vec_array);
		std::cout << "\n";
	}

	else {
		
		std::sort(vec_array.begin(), vec_array.end());

		for (auto it = vec_array.rbegin(); it != vec_array.rend();  ) {
			if (*it % 2 != 0) {
				buf_num = *it;
				it = vec_array.erase(it);
				vec_array.emplace_back(buf_num);
			}
			else {
				++it;
			}
		}


		std::cout << "Result: ";
		print_array(vec_array);
		std::cout << "\n";
	}

	return 0;
}

int input_check() {
	
	int input_num = 0;
	while (!(std::cin >> input_num)) {
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "Bad data inputed! Try again: ";
	}
	return input_num;
}

int rand_num(int& min_lim, int& max_lim) {
	
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distrib(min_lim, max_lim);
	return distrib(gen);
}

void print_array(const std::vector<int>& vec) {
	for (int n : vec) {  //output of generated array
		std::cout << n << " ";
	}
	std::cout << "\n";
}

int kinda_interface() {

	std::cout << "What do you want to do with generated array? \n"<< 
				"	1 - Delete all EVEN numbers & sort in increasing order \n" << 
				"	2 - Delete all ODD numbers & sort in decreasing order \n" << 
				"	3 - Sort all EVEN in increasing order & all ODD in decreasing. EVENs followed by ODDs \n" <<
				"	> ";
	
	return input_check();
}
	