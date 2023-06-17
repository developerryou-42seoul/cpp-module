#include <iostream>
#include <fstream>

void write(std::ofstream &fout, std::string &str, std::string &s1, std::string &s2)
{
	size_t index = str.find(s1);
	for (size_t i=0;i<str.size(); i++)
	{
		if (index != std::string::npos && i == index)
		{
			fout<<s2;
			i += s1.size();
			index = str.find(s1, i);
			i--;
		}
		else
			fout.put(str[i]);
	}
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout<<"Error : Wrong Argument"<<std::endl;
		return (1);
	}
	std::ifstream fin;
	std::string s1, s2, filename;
	filename = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	if (s1.size() == 0)
	{
		std::cout<<"Error : S1 length is 0"<<std::endl;
		return (1);
	}

	fin.open(filename);
	if (fin.fail())
	{
		std::cout<<"Error : Wrong Read File"<<std::endl;
		return (1);
	}
	std::string str;
	char c;
	while (fin.get(c))
		str += c;

	std::ofstream fout;
	fout.open(filename+".replace");
	if (fout.fail())
	{
		std::cout<<"Error : Wrong Write File"<<std::endl;
		fin.close();
		return (1);
	}
	write(fout, str, s1, s2);
	fin.close();
	fout.close();
	return (0);
}
