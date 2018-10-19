//
//  main.c
//  HashTable
//
//  Created by Dirk on 10/18/18.
//  Copyright © 2018 Dirk. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int search(int table[], int key) {
	for (int i = 0; i < 25; i++) {
		if (table[i] == key) {
			return table[i];
		}
	}
	return -1;
}

void linear(int table[], int indexToInsert) {
	int searchIndex = indexToInsert;
	bool flag = false;
	while (flag == false) {
		if (searchIndex + 1 > 25) {
			searchIndex = 0;
		}
		
		if (table[(searchIndex + 1) % 25] == -1) {
			table[(searchIndex + 1) % 25] = indexToInsert;
			flag = true;
		} else {
			searchIndex++;
		}
	}
}

void quadratic(int table[], int indexToInsert) {
	// Fix this
	int searchIndex = 0;
	bool flag = false;
	while (flag == false) {
		
		if ((indexToInsert + (int)pow(2, searchIndex)) % 25 > 25 ) {
			searchIndex = 0;
		}
		
		if (table[(indexToInsert + (int)pow(2, searchIndex)) % 25] == -1) {
			table[(indexToInsert + (int)pow(2, searchIndex)) % 25] = indexToInsert;
			flag = true;
		} else {
			searchIndex++;
		}
	}
}

void hash(int table[], int indexToCheck, int answer) {
	if (table[indexToCheck] % 25 == -1) {
		table[indexToCheck] = indexToCheck;
	} else {
		if (answer == 0) {
			linear(table, indexToCheck);
		} else {
			quadratic(table, indexToCheck);
		}
	}
}

void findNextLinear() {
	
}

void print(int table[], int size) {
	for (int i = 0; i < size; i++) {
		printf("Item in slot %d is %d\n", i, table[i]);
	}
}

int main(int argc, const char * argv[]) {
	
	int const size = 25;
	int table[size];
	
	for (int i = 0; i < size; i++) {
		table[i] = -1;
	}
	
	int answer;
	printf("Enter 0 for Linear or 1 for Quadratic\n");
	scanf("%d", &answer);
	
	srand((unsigned int)time(NULL));
	
	for (int i = 0; i < size; i++) {
		int num = rand() % 100 + 1;
		hash(table, num, answer);
	}
	
	
	print(table, size);
	
	return 0;
}
