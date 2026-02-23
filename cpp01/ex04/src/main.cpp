/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 00:48:02 by gneto-co          #+#    #+#             */
/*   Updated: 2024/11/01 13:23:31 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>

void ft_error(std::string error_msg)
{
	std::cout << error_msg << " Error" << std::endl;
	exit(1);
}

bool open_files(std::string read_filename, std::ifstream &read_file, std::string write_filename, std::ofstream &write_file)
{
	read_file.open(read_filename.c_str());
	if (read_file.is_open() == false)
		return false;
	write_file.open(write_filename.c_str());
	if (write_file.is_open() == false)
	{
		read_file.close();
		return false;
	}
	return true;
}

void replaceStrings(std::ofstream &fileOut, std::string s1, std::string s2, std::string input)
{
	size_t pos;
	size_t toSkip;

	pos = input.find(s1);
	if (pos == std::string::npos)
	{
		fileOut << input;
		return;
	}
	else
	{
		fileOut << input.substr(0, pos);
		fileOut << s2;
		toSkip = pos + s1.length();
		replaceStrings(fileOut, s1, s2, input.substr(toSkip));
	}
}

int main(int ac, char **av)
{
	/* get input */
	if (ac != 4)
		ft_error("Input");
	std::string read_filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];

	/* open files */
	std::ifstream read_file;
	std::ofstream write_file;
	if (open_files(read_filename, read_file, read_filename + ".replace", write_file) == false)
		ft_error("File error");

	/* read file, replace str and write file */
	std::string line;
	while (std::getline(read_file, line))
	{
		replaceStrings(write_file, s1, s2, line + '\n');
	}

	/* close files */
	read_file.close();
	write_file.close();

	return 0;
}
