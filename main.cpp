#include <iostream>
#include <fstream>
#include <cstring>
#include <chrono>
#include <thread>
#include <sstream>
#include <vector>
#include <string>
#include <set>
#include<thread>

std::string Convert(std::string str);

int main()
{
	::setlocale(LC_ALL, "ru");

	std::vector<std::string> vector;
	std::set<std::string> set;

	auto start_point = std::chrono::system_clock::now();

	std::ifstream in_file;
	in_file.open("J. K. Rowling - Harry Potter 1 - Sorcerer's Stone.txt");

	if (!in_file.is_open())
	{
		std::cerr << "you idiot";
	}
	else
	{
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
					set.insert(Convert(data));
				}
			}
		}
	}

	in_file.close();

	auto end_point = std::chrono::system_clock::now();
	auto t_diff = std::chrono::duration_cast<std::chrono::milliseconds>(end_point - start_point);

	std::cout << "Ќа заполнение контейнеров ушло: " << t_diff.count() << " миллисекунд\n";

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