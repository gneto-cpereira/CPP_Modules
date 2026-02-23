#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include "Strings.h"

#include <algorithm>
#include <vector>
#include <deque>
#include <ctime>
// #include <exception>
// #include <fstream>
// #include <sstream>

template <typename c_type>
class PmergeMe
{
private:
	/* attributes */
	c_type _ct;
	clock_t _start_time;
	/* mini methods */
	void print(c_type);
	bool is_sorted(c_type);
	/* methods */
	void mini_sort(c_type &);
	void merge_sort(c_type &);
	void ford_johnson_algorithm(c_type &nb_lst);
	void insert_smallest(c_type smallest, c_type &nb_lst);

public:
	/* constructors destructors */
	PmergeMe();
	PmergeMe(const PmergeMe *);
	~PmergeMe();

	/* operators */
	PmergeMe &operator=(const PmergeMe &);

	/* methods */
	void print_container();
	void print();
	void sort();

	/* setters */
	void set_numbers(int, char **);
	void set_time();

	/* getters */
	int get_size();
	double get_time();

	/* exceptions */
	class InvalidInput : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

#include "PmergeMe.tpp"

#endif