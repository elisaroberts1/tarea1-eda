#include <iostream>
#include <ctime>
#include <cstdlib>
#include <ctime>
#include <cmath>

#include "sort/utils.hpp"

namespace sort{

	float* createArray(int n){
		return new float[n];
	}

	float* createRandomArray(int n){
		float* A = createArray(n);
		for (int i = 0; i < n; i++){
			A[i] =  std::rand() / static_cast<float>(RAND_MAX);
		}
		return A;
	}

	float* createRandomIntArray(int n, int minVal, int maxVal){
		float* A = createArray(n);
		for (int i = 0; i < n; i++){
			A[i] = getRandomInt(minVal, maxVal);
		}
		return A;
	}

	void deleteArray(float* A){
		delete[] A;
	}

	void printArray(float* A, int n){
		for (int i = 0; i < n; i++){
			std::cout<<A[i]<<" ";
		}
		std::cout<<std::endl;
	}

	void setAll(float* A, int n, float value){
		for (int i = 0; i < n; i++){
			A[i] =  value;
		}
	}

	void swap(float* A, int i, int j){
		float aux = A[i];
		A[i] = A[j];
		A[j] = aux;
	}

	int getRandomInt(int min, int max){
		float a = rand() / static_cast<float>(RAND_MAX);
		return static_cast<int>(a * (max - min) + min + 0.5);
	}

	int* linspace(int max, int n_parts){
		int* V = new int[n_parts];
		int part_size = max / n_parts;
		for(int i = 1; i <= n_parts; i++){
			V[i - 1] = part_size * i;
		}
		return V;
	}

	int getMax(float* A, int n) {
		int max = A[0];
		for (int i = 1; i < n; i++){
			if (A[i] > max){
				max = A[i];
			}
		}
		return max;
	}

	void countingSort(float* A, int n, int p) {
		int output[n];
		int count[10] = { 0 };

		for (int i = 0; i < 10; ++i){
			count[i] = 0;
		}
		for (int i = 0; i < n; i++){
			count[int(A[i] / p) % 10]++;
		}
		for (int i = 1; i < 10; i++){
			count[i] += count[i - 1];
		}
		for (int i = n - 1; i >= 0; i--) {
			output[count[int(A[i] / p) % 10] - 1] = A[i];
			count[int(A[i] / p) % 10]--;
		}
		for (int i = 0; i < n; i++){
			A[i] = output[i];
		}
	}
}
