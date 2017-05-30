// Lab3_PiAA.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include "Wires.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Лабораторная работа №3 ст.гр. 5382 Лисс Натальи. " << endl;
	cout << "Введите количество ячеек: " << endl;
	int n;
	cin >> n;
	vector <vector<int>> distance(n);
	for (int j = 0; j < n; ++j) {//Resizes the container so that it contains n elements.
		distance[j].resize(n);
	}

	int count = 0;
	for (int i = 0; i<n; i++) {
		for (int q = 0; (q + count)<n; q++) {
			if (i != (q + count)) {
				cout << "Введите расстояние между " << i << " и " << count + q << " ячейкой:" << endl;
				cin >> distance[i][count + q];//fill the matrix D
				distance[count + q][i] = distance[i][count + q];
			}
			else
				distance[i][count + q] = 0;
		}
		++count;
	};
	count = 0;
	vector <vector<int>> wires(n);
	for (int j = 0; j < n; ++j) {
		wires[j].resize(n);
	}

	for (int i = 0; i<n; i++) {
		for (int q = 0; (q + count)<n; q++) {
			if (i != (q + count)) {
				cout << "Введите количество проводов между " << i << " и " << count + q << " компонентами" << endl;
				cin >> wires[i][count + q];//matrix C(wires)
				wires[count + q][i] = wires[i][count + q];
			}
			else
				wires[i][count + q] = 0;
		}
		++count;
	};
	vector<int> posibility;
	for (int p = 0; p<n; p++)
		posibility.push_back(p);
	vector<int> place;
	int bestS = 0;
	cout << "Матрица D:" << endl;
	for (int i = 0; i<n; ++i) {
		for (int q = 0; q<n; ++q) {
			cout << distance[i][q] << " ";
		}
		cout << endl;
	}
	cout << "Матрица C:" << endl;
	for (int i = 0; i<n; ++i) {
		for (int q = 0; q<n; ++q) {
			cout << wires[i][q] << " ";
		}
		cout << endl;
	}

	spaceComponents(distance, wires, posibility, place, bestS);
	system("pause");
    return 0;
}

