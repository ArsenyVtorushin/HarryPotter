#include <iostream>
#include <fstream>
#include <cstring>
#include <chrono>
#include <thread>
#include <sstream>
#include <vector>
#include <string>
#include <set>

std::string Convert(std::string str);

int main()
{
	std::vector<std::string> vector;
	std::set<std::string> set;

	std::ifstream in_file;
	in_file.open("J. K. Rowling - Harry Potter 1 - Sorcerer's Stone.txt");

	if (!in_file.is_open())
	{
		std::cerr << "you idiot";
	}
	else
	{
		std::chrono::time_point<std::chrono::steady_clock> start_vec;
		std::chrono::time_point<std::chrono::steady_clock> end_vec;
		std::chrono::time_point<std::chrono::steady_clock> start_set;
		std::chrono::time_point<std::chrono::steady_clock> end_set;


		start_vec = std::chrono::high_resolution_clock::now();

		std::string str;
		while (!in_file.eof())
		{
			str = "";
			std::getline(in_file, str, '\n');
			std::stringstream str_stream(str);
			std::string data;

			while (!str_stream.eof())
			{
				data = "";
				std::getline(str_stream, data, ' ');

				if (data != "")
				{
					vector.push_back(Convert(data));
				}			
			}
		}

		end_vec = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> duration_vec = end_vec - start_vec;
		std::cout << "Duration of vector: " << duration_vec.count() << " seconds\n";

		in_file.close();


		start_set = std::chrono::high_resolution_clock::now();

		while (!in_file.eof())
		{
			str = "";
			std::getline(in_file, str, '\n');
			std::stringstream str_stream(str);
			std::string data;

			while (!str_stream.eof())
			{
				data = "";
				std::getline(str_stream, data, ' ');

				if (data != "")
				{
					set.insert(Convert(data));
				}
			}
		}

		end_set = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> duration_set = end_set - start_set;
		std::cout << "Duration of set: " << duration_set.count() << " seconds\n";
	}

	in_file.close();

	return 0;
}



std::string Convert(std::string str)
{
	std::string punctuation = "\"\~`!@#$%^&*()-_+=,./?;:' ";

	for (size_t i = 0; i < str.size(); i++)
		str[i] = (char)tolower(str[i]);

	for (size_t i = 0; i < punctuation.size(); i++)
		str.erase(std::remove(str.begin(), str.end(), punctuation[i]), str.end());

	return str;
}