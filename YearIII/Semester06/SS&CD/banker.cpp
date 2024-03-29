#include <iostream>
using namespace std;

#define MAX_RESOURCES 10
#define MAX_PROCESSES 10

static int NUM_RESOURCES = 3;
static int NUM_PROCESSES = 5;
int completed_processes = 0;
static int available[MAX_RESOURCES] = {3, 3, 2};
static int maximum[MAX_PROCESSES][MAX_RESOURCES] = {
	{7, 5, 3},
	{3, 2, 2},
	{7, 0, 2},
	{2, 2, 2},
	{4, 3, 3}
};
static int allocation[MAX_PROCESSES][MAX_RESOURCES] = {
	{0, 1, 0},
	{2, 0, 0},
	{5, 0, 2},
	{2, 1, 1},
	{0, 0, 2}
};

int need[MAX_PROCESSES][MAX_RESOURCES];
bool finish[MAX_PROCESSES] = {false};
int safe_sequence[MAX_PROCESSES];

int main() {
	for (int i = 0; i < NUM_PROCESSES; i++) {
		for (int j = 0; j < NUM_RESOURCES; j++) {
			need[i][j] = maximum[i][j] - allocation[i][j];
			cout << need[i][j] << " ";
		}
		cout << endl;
	}

	while (completed_processes < NUM_PROCESSES) {
		bool found = false;
		for (int i = 0; i < NUM_PROCESSES; i++) {
			if (!finish[i]) {
				bool safe = true;
				for (int j = 0; j < NUM_RESOURCES; j++)
					if (need[i][j] > available[j]) {
						safe = false;
						break;
					}
				if (safe) {
					for (int j = 0; j < NUM_RESOURCES; j++)
						available[j] += allocation[i][j];
					finish[i] = true;
					safe_sequence[completed_processes++] = i;
					found = true;
					cout << "Process " << i + 1<< " runs to completion!" << endl;
				}
			}
		}
		if (!found)
			break;
	}

	if (completed_processes == NUM_PROCESSES) {
		cout << "Safe sequence is: ";
		for (int i = 0; i < NUM_PROCESSES; i++)
			cout << safe_sequence[i] + 1<< " ";
		cout << endl;
	} else {
		cout << "Unsafe state" << endl;
	}
	return 0;
}