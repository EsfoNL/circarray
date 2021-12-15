#include <iostream>
#include <string>
#include <algorithm>

template <class T>
class circulairArray {
	private:
		T* TCircArray;
		int size;
	public:
		//! initializers
		circulairArray() {
			size = 0;
			TCircArray = new T[0];
		}
		circulairArray(T* Tarray, int inputsize) {
			TCircArray = new T[inputsize];
			size = inputsize;
			std::copy(Tarray, Tarray + size, TCircArray);
		}
		//!destructor
		~circulairArray() {
			delete TCircArray;
		}
		//[] operator overloading
		T& operator[] (int i) {
			if (i >= 0) {return TCircArray[i%size];
			} else {return TCircArray[size + i%size];}
		}
		//append function
		circulairArray append(T item) {
			T* TNewArray = TCircArray;
			TCircArray = new T[size + 1];
			for (int i = 0; i < size; i++) {
				TCircArray[i] = TNewArray[i];
			}
			TCircArray[size] = item;
			delete TNewArray;
			size++;
			return *this;
		}
		//size getter function
		int getsize() {
			return size;
		}
};

circulairArray<int> inputarray() {
	circulairArray<int> carr;
	std::string a;
	for (std::cin >> a; a != "x"; std::cin >> a) {
		carr.append(std::stoi(a));
	}
	return carr;
};

int main() {
	circulairArray<int> carr = inputarray();
	std::string i;
	for (std::cin >> i; i != "x"; std::cin >> i) {
		std::cout << carr[std::stoi(i)];
	}
}