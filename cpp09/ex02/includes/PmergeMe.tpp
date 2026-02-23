#include "../includes/PmergeMe.hpp"

/* SECTION - constructors destructors */

template <typename c_type>
PmergeMe<c_type>::PmergeMe()
{
    FT_MSG("PmergeMe() Constructor")
    return;
}

template <typename c_type>
PmergeMe<c_type>::PmergeMe(const PmergeMe *copy)
{
    FT_MSG("PmergeMe(PmergeMe copy) Constructor")
    *this = copy;
    return;
}

template <typename c_type>
PmergeMe<c_type>::~PmergeMe()
{
    FT_MSG("PmergeMe() Destructor")
    return;
}

/* !SECTION */

/* SECTION - overload operators */

template <typename c_type>
PmergeMe<c_type> &PmergeMe<c_type>::operator=(const PmergeMe &src)
{
    if (this != &src)
    {
        this->_ct = src._ct;
    }

    return *this;
}

/* !SECTION */

/* SECTION - mini methods */

template <typename c_type>
void PmergeMe<c_type>::print(c_type c_lst)
{
    typename c_type::iterator it;
    for (it = c_lst.begin(); it != c_lst.end(); ++it)
    {
        PRINT << *it << " ";
    }
}

template <typename c_type>
void PmergeMe<c_type>::print_container()
{
    int i = 0;
    typename c_type::iterator it;
    for (it = _ct.begin(); it != _ct.end(); ++it)
    {
        PRINT << *it << " ";
        if (++i > 10)
        {
            PRINT << "...";
            break;
        }
    }
    SPACER(1)
}

template <typename c_type>
bool PmergeMe<c_type>::is_sorted(c_type c_lst)
{
    if (c_lst.size() > 1)
    {
        typename c_type::iterator it;
        typename c_type::iterator next_it = c_lst.begin();
        for (it = c_lst.begin(); it != --c_lst.end(); ++it)
        {
            ++next_it;
            if (*it > *next_it)
                return false;
        }
    }
    return true;
}

/* !SECTION */

/* SECTION - methods */

template <typename c_type>
void PmergeMe<c_type>::mini_sort(c_type &nb_lst)
{
    c_type tmp_lst;

    // do nothing if is already sorted
    if (is_sorted(nb_lst))
        return;

    // put each (nb_lst) member on a new list (tmp_lst), but sorted
    typename c_type::iterator it;
    for (it = nb_lst.begin(); it != nb_lst.end(); ++it)
    {
        // if (tmp_lst) is empty just push the current number
        if (tmp_lst.empty())
        {
            tmp_lst.push_back(*it);
        }
        // if the current number is greater than the lastone, push it in the end
        else if (*it >= *--tmp_lst.end())
        {
            tmp_lst.push_back(*it);
        }
        // search for the current number position on the (tmp_lst)
        else
        {
            typename c_type::iterator it2;
            for (it2 = tmp_lst.begin(); it2 != tmp_lst.end(); ++it2)
            {
                if (*it <= *it2)
                {
                    tmp_lst.insert(it2, *it);
                    break;
                }
            }
        }
    }
    nb_lst = tmp_lst;
}

template <typename c_type>
void PmergeMe<c_type>::merge_sort(c_type &nb_lst)
{
    int size = nb_lst.size();
    c_type c_first_half;
    c_type c_second_half;

    // do nothing if is already sorted
    if (!is_sorted(nb_lst))
    {
        // split (nb_lst) container in two halfs
        for (int i = 0; i < size; i++)
        {
            if (i < size / 2)
                c_first_half.push_back(nb_lst[i]);
            else
                c_second_half.push_back(nb_lst[i]);
        }

        // merge_sort each half recursively
        merge_sort(c_first_half);
        merge_sort(c_second_half);

        // merge the halves back together
        typename c_type::iterator it;
        for (it = c_second_half.begin(); it != c_second_half.end(); ++it)
        {
            c_first_half.push_back(*it);
        }

        // sort the complete list
        mini_sort(c_first_half);

        // "return" it
        nb_lst = c_first_half;
    }
}

template <typename c_type>
void PmergeMe<c_type>::insert_smallest(c_type smallest_nb_lst, c_type &nb_lst)
{

    // insert smallest numbers (smallest_nb_lst) in correct position
    typename c_type::iterator it;
    for (it = smallest_nb_lst.begin(); it != smallest_nb_lst.end(); ++it)
    {
        // if the current number is greater than the lastone, push it in the end
        if (*it >= *--nb_lst.end())
        {
            nb_lst.push_back(*it);
        }
        // search for the current number position on the (nb_lst)
        else
        {
            typename c_type::iterator it2;
            for (it2 = nb_lst.begin(); it2 != nb_lst.end(); ++it2)
            {
                if (*it <= *it2)
                {
                    nb_lst.insert(it2, *it);
                    break;
                }
            }
        }
    }
}

template <typename c_type>
void PmergeMe<c_type>::ford_johnson_algorithm(c_type &nb_lst)
{
    // do nothing if is already sorted
    if (is_sorted(nb_lst))
        return;

    c_type smallest_nb_lst;

    // iterate to transfer the smallest numbers of (nb_lst) to (smallest_nb_lst)
    typename c_type::iterator it1;
    for (it1 = nb_lst.begin(); it1 != nb_lst.end(); ++it1)
    {
        typename c_type::iterator it2 = it1;
        if (++it2 == nb_lst.end())
            break;

        if (*it1 <= *it2)
        {
            smallest_nb_lst.push_back(*it1);
            it1 = nb_lst.erase(it1);
        }
        else
        {
            smallest_nb_lst.push_back(*it2);
            nb_lst.erase(it2);
        }
    }
    // PRINT << BLUE; print(smallest_nb_lst); PRINT << RESEND;
    // PRINT << CYAN; print(nb_lst); PRINT << RESEND;

    // sort biggest numbers (nb_lst) using merge_sort
    merge_sort(nb_lst);

    // insert smallest numbers on (nb_lst)
    insert_smallest(smallest_nb_lst ,nb_lst);
}

template <typename c_type>
void PmergeMe<c_type>::sort()
{
    ford_johnson_algorithm(_ct);
}

/* !SECTION */

/* SECTION - getters */

template <typename c_type>
int PmergeMe<c_type>::get_size()
{
    return (_ct.size());
}

template <typename c_type>
double PmergeMe<c_type>::get_time()
{
    clock_t end = clock();

    return double(end - _start_time) / (CLOCKS_PER_SEC);
}

/* !SECTION */

/* SECTION - setters */

template <typename c_type>
void PmergeMe<c_type>::set_numbers(int ac, char **av)
{
    for (int i = 1; i < ac; i++)
    {
        int nb = atoi(av[i]);
        if (nb > 0 && nb < INT_MAX)
            _ct.push_back(nb);
        else
            throw InvalidInput();
    }
}

template <typename c_type>
void PmergeMe<c_type>::set_time()
{
    _start_time = clock();
}

/* !SECTION */

/* SECTION - exceptions */

template <typename c_type>
const char *PmergeMe<c_type>::InvalidInput::what() const throw()
{
    return (RED "Invalid input" RESET);
}

/* !SECTION */