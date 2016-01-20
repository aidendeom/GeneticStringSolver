#include <iostream>
#include <string>
#include <random>
#include <functional>
#include <chrono>
#include <cstdlib>

#include "CharacterGenerator.h"

CharacterGenerator gen;

void PrintGeneration(size_t generation, size_t fitness, const std::string& str)
{
	std::cout << "Generation: " << generation << " | "
		<< "Fitness: " << fitness << " | "
		<< str
		<< "\n";
}

size_t GetBest(size_t length, std::function<size_t(const std::string&)> getFitness)
{
	size_t generation = 1;
	std::string parent = gen.GetRandomString(length);
	size_t parentFitness = getFitness(parent);

	PrintGeneration(generation, parentFitness, parent);

	while (parentFitness != 0)
	{
		std::string child = gen.MutateString(parent);
		size_t childFitness = getFitness(child);

		if (childFitness < parentFitness)
		{
			// Printing takes a lot of time...
			PrintGeneration(generation, childFitness, child);
			parent = child;
			parentFitness = childFitness;
		}

		++generation;
	}

	PrintGeneration(generation, parentFitness, parent);

	return generation;
}

int main(int argc, char* argv[])
{
	std::string source;

	if (argc > 0)
		source = argv[1];

	auto HammingDistance = [&source](const std::string& target)
	{
		size_t distance = 0;
		for (size_t i = 0; i < source.length(); i++)
		{
			distance += std::abs(source[i] - target[i]);
		}

		return distance;
	};

	using namespace std::chrono;
	using clock = std::chrono::high_resolution_clock;
	using time_unit = std::chrono::microseconds;

	auto t1 = clock::now();

	GetBest(source.length(), HammingDistance);

	auto t2 = clock::now();

	std::cout << "Time taken: " << duration_cast<time_unit>(t2 - t1).count() << ' ' << (char)230 << "s\n";

	return 0;
}
