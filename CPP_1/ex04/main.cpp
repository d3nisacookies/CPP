#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

std::string replace(std::string str, std::string s1, std::string s2)
{
	size_t	pos;

	pos = str.find(s1);
	while ((pos = str.find(s1)) != std::string::npos)
	{
		str = str.substr(0, pos) + s2 + str.substr(pos + s1.length());
	}
	return (str);
}

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Usage: ./replace filename s1 s2" << std::endl;
		return (1);
	}
	else
	{
		std::ifstream infile(av[1]);
		std::string outname = std::string(av[1]) + ".replace";
		std::ofstream output(outname.c_str());
		if (!infile.is_open() || !output.is_open())
		{
			std::cerr << "Error: cannot open file" << std::endl;
			return (1);
		}
		if (std::string(av[2]).empty())
		{
			std::cerr << "Error: s1 cannot be empty" << std::endl;
			return (1);
		}
		std::string content((std::istreambuf_iterator<char>(infile)),
			std::istreambuf_iterator<char>());
		if (content.empty())
			return (0);
		std::string str = replace(content, av[2], av[3]);
		output << str;
		output.close();
	}
	return (0);
}