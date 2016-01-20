#include "CharacterGenerator.h"

#include <string>

CharacterGenerator::CharacterGenerator()
	: dist(0, ascii.length() - 1)
{
	random.seed(rd());
}


CharacterGenerator::~CharacterGenerator()
{
}

auto CharacterGenerator::GetRandomChar() -> char
{
	return ascii[dist(random)];
}

auto CharacterGenerator::GetRandomIndex(const std::string& str) -> size_t
{
	std::uniform_int_distribution<size_t> dist(0, str.length() - 1);
	return dist(random);
}

auto CharacterGenerator::GetRandomString(size_t length) -> std::string
{
	std::string generated;
	generated.reserve(length);

	for (size_t i = 0; i < length; i++)
	{
		generated.push_back(gen.GetRandomChar());
	}

	return generated;
}

auto CharacterGenerator::MutateString(const std::string & str) -> std::string
{
	std::string child = str;
	size_t index = GetRandomIndex(str);
	child[index] = GetRandomChar();

	return child;
}



const std::string CharacterGenerator::ascii = " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
