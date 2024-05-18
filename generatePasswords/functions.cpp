#include <map>
#include <string>
#include <random>
#include <iostream>
#include "functions.h"

using namespace std;

map<int, string> configureLayers()
{
	map<int, string> layers;
	layers[1] = "0123456789";
	layers[2] = "abcdefghijklmnopqrstuvwxyz";
	layers[3] = layers[2] + "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	layers[4] = layers[3] + layers[1];
	layers[5] = layers[4] + "^*%$!&@#,/.,<>?;:'|[]()-=+_";
	layers[6] = layers[5] + "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
	layers[7] = layers[6] + "ЯЮЭЬЫЪЩШЧЦХФУТСРПОНМЛКЙИЗЖЁЕДГВБА";

	return layers;
}

int getRandomIndex(int start, int end)
{
	random_device dev;
	mt19937 rng(dev());
	uniform_int_distribution<mt19937::result_type> randomIndex(start, end);

	return randomIndex(rng);
}

string generatePassword(int complexity, const int size)
{
	map<int, string> layers = configureLayers();
	map<int, string>::iterator it;
	string password = "";

	it = layers.find(complexity);
	if (it != layers.end())
	{
		string currentLayer = layers[complexity].c_str();
		int currentLayerSize = currentLayer.length();

		for (int i = 0; i < size; i++)
		{
			int randomIndex = getRandomIndex(0, currentLayerSize);
			password += currentLayer[randomIndex];
		}
	}
	else 
	{
		password = to_string(complexity) + " - this complexity doesn't exist";
	}

	return password;
}