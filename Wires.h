#pragma once
#include <iostream>
#include <vector>
#include <math.h>
template <class T> //counting the sum distance
T countS(const std::vector<std::vector<T>> &distance, const std::vector<std::vector<T>> &wires, std::vector<T> place)
{
	T bS = 0;
	for (unsigned int count1 = 0; count1<place.size(); count1++) {
		for (unsigned int count2 = 1; count2 + count1<place.size(); count2++) {
			bS = bS + distance[count1][count1 + count2] * wires[place[count1]][place[count1 + count2]];
		}
	}
	return bS;
}


template <class T>
void  spaceComponentsT(T variant, T free, T choose, const std::vector<std::vector<T>> &distance, const std::vector<std::vector<T>> &wires, std::vector<T> options, std::vector<T> place, T &bestS)
{
	std::swap(options[0 + free - 1], options[choose]);
	place.push_back(variant);

	T S = countS(distance, wires, place);
	if ((S>bestS) && (bestS != 0)) {
		std::cout << "S = " << S << " Минимальная S: " << bestS << std::endl;
		return;
	}
	if (place.size() == options.size()) {
		bestS = S;
		std::cout << "Минимальное решение на данный момент: " << bestS << std::endl;
		for (unsigned int p = 0; p<place.size(); p++)
			std::cout << place[p] << " ";
		std::cout << std::endl;
		return;
	}
	for (unsigned int var = 0; var + free < options.size(); var++)
	{
		spaceComponentsT(options[var + free], (free + 1), (int)(var + free), distance, wires, options, place, bestS);
	}
	return;
}

template <class T>//for first
void  spaceComponents(const std::vector<std::vector<T>> &distance, const std::vector<std::vector<T>> &wires, std::vector<T> options, std::vector<T> place, T &bestS)
{
	for (unsigned int var = 0; var < options.size(); var++)
	{ 
		spaceComponentsT(options[var], 1, (int)var, distance, wires, options, place, bestS);
	}
	std::cout << "Минимальная общая длина равна:  " << bestS << std::endl;
	return;
}

