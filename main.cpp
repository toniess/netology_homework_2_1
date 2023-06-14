#include <fstream>
#include <iostream>


int main()
{
	std::fstream file;
	file.open("in.txt", std::ios::in);
	if (!file.is_open())
	{
		std::cout << "File could not be opened!" << std::endl;
		return 0;
	}
	
	int size1;
	file >> size1;
	int* array1 = new int[size1];
	for (int i = 0; i < size1; ++i)
	{
		file >> array1[i];
	}

	int size2;
	file >> size2;
	int* array2 = new int[size2];
	for (int i = 0; i < size2; ++i)
	{
		file >> array2[i];
	}
	file.close();

	file.open("out.txt", std::ios::trunc | std::ios::out);
	file << size2 << '\n';
	for (int i = 0; i < size2; ++i)
	{
		int shiftedIndex = (size2 + i - 1) % size2;
		file << array2[shiftedIndex] << ' ';
	}

	file << '\n' << size1 << '\n';
	for (int i = 0; i < size1; ++i)
	{
		int shiftedIndex = (i + 1) % size1;
		file << array1[shiftedIndex] << ' ';
	}

	delete[] array1;
	delete[] array2;
	return 0;
}