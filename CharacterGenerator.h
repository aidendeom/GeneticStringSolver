#pragma once

#include <string>
#include <random>

class CharacterGenerator
{
public:
	CharacterGenerator();
	~CharacterGenerator();

	auto GetRandomChar() -> char;
	auto GetRandomIndex(const std::string& str) -> size_t;
	auto GetRandomString(size_t length) -> std::string;
	auto MutateString(const std::string& str) -> std::string;

private:
	static const std::string ascii;
	std::random_device rd;
	std::mt19937 random;
	std::uniform_int_distribution<size_t> dist;
};

