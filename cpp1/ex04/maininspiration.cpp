/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:58:55 by lcuevas-          #+#    #+#             */
/*   Updated: 2024/10/17 12:58:56 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Error: Wrong number of arguments" << std::endl;
        return 1;
    }

    std::string s1(argv[2]);
    std::string s2(argv[3]);
    if (s1.empty() || s2.empty())
    {
        std::cout << "Error: Strings cannot be empty" << std::endl;
        return 1;
    }

    // Open input file
    std::ifstream infile(argv[1]);
    if (!infile)
    {
        std::cout << "Error: Error opening file" << std::endl;
        return 1;
    }

    // Create output file name and open it using c_str()
    std::string outputFileName = std::string(argv[1]) + ".replace";
    std::ofstream outfile(outputFileName.c_str());
    if (!outfile)
    {
        std::cout << "Error: Error creating file" << std::endl;
        return 1;
    }

    std::string str;
    // Process each line of the input file
    while (std::getline(infile, str))
    {
        size_t pos = 0;
        // Find all occurrences of s1 in the current line
        while ((pos = str.find(s1, pos)) != std::string::npos)
        {
            // Erase the found substring s1
            str.erase(pos, s1.length());
            // Insert the new substring s2
            str.insert(pos, s2);
            // Move past the inserted substring to prevent infinite loop
            pos += s2.length();
        }
        // Write the modified line to the output file
        outfile << str << std::endl;
    }

    // Close the files
    infile.close();
    outfile.close();
    return 0;
}


/* int main(int argc, char **argv)
{
	if (argc < 4 || argc > 4)
	{
		std::cout << "Error: Wrong number of arguments" << std::endl;
		return 1;
	}
	int	i;
	std::string	str;
	std::string	s1(argv[2]);
	std::string s2(argv[3]);
	if (s2.empty() || s1.empty())
	{
		std::cout << "Error: String cant be empty" << std::endl;
		return 1;
	}
	std::ifstream infile;
	infile.open(argv[1]);
	if (infile.fail())
	{
		std::cout << "Error: Error opening file" << std::endl;
		return 1;
	}
	std::ofstream outfile;
	outfile.open((std::string(argv[1]) += ".replace").c_str());
	if (outfile.fail())
	{
		std::cout << "Error: Error creating file" << std::endl;
		return 1;
	}
	while(infile.good())
	{
		if (!std::getline(infile, str))
		{
			std::cout << "Error: Problem with funtion getline" << std::endl;
			return 1;
		}
		while ((i = str.find(s1)) != -1)
		{
			str.erase(i, s1.length());
			str.insert(i, s2);
			i += s2.length();
		}
		outfile << str << std::endl;
	}
	infile.close();
	outfile.close();
	return 0;
} */

