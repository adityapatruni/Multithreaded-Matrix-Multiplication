//A (100x80) X B (80X150) = C (100x150)

#include <iostream>
#include <thread>
#include <time.h>
using namespace std;

void multiply(int A[][80], int B[][150], int C[][150], int i1, int i2, int j1, int j2, int k) {
	for (int i = i1; i <= i2; i++) {
		for (int j = j1; j <= j2; j++) {
			int ret = 0;
			for (int w = 0; w < k; w++) {
				ret += A[i][w] * B[w][j];
			}
			C[i][j] = ret;
		}
	}
}

int main() {
	int A[100][80], B[80][150], C[100][150];
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 80; j++)
			A[i][j] = rand() % 100;
	}
	for (int i = 0; i < 80; i++) {
		for (int j = 0; j < 150; j++)
			B[i][j] = rand() % 100;
	}

	thread t1(multiply, A, B, C, 0, 49, 0, 74, 80);
	thread t2(multiply, A, B, C, 0, 49, 75, 149, 80);
	thread t3(multiply, A, B, C, 50, 99, 0, 74, 80);
	thread t4(multiply, A, B, C, 50, 99, 75, 149, 80);

	t1.join();
	t2.join();
	t3.join();
	t4.join();

	for (int i = 0; i < 100; i++)
	{
		cout << endl;
		for (int j = 0; j < 150; j++) {
			cout << C[i][j] << " ";
		}
	}
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
