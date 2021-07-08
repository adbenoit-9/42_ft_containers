/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterators_traits.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 18:24:40 by adbenoit          #+#    #+#             */
/*   Updated: 2021/07/08 15:45:42 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_TRAITS_HPP
# define ITERATORS_TRAITS_HPP

template <class Iterator>
class iterator_traits
{
	public:
    	typedef typename Iterator::difference_type	difference_type;
	    typedef typename Iterator::value_type		value_type;
    	typedef typename Iterator::pointer			pointer;
    	typedef typename Iterator::reference		reference;
    	typedef std::random_access_iterator_tag		iterator_category;
};


namespace ft
{
	template <bool Cond>
	struct enable_if
	{
		// typedef T	type;
	};

	template <>
	struct enable_if<true> { typedef int type; };
	template <>
	struct enable_if<false> { };
	
	
	template <class T>
	struct is_integral { static const bool value = 0; };
	
	template <>
	struct is_integral<bool> { static const bool value = 1; };
	template <>
	struct is_integral<char> { static const bool value = 1; };
	template <>
	struct is_integral<char16_t> { static const bool value = 1; };
	template <>
	struct is_integral<char32_t> { static const bool value = 1; };
	template <>
	struct is_integral<wchar_t> { static const bool value = 1; };
	template <>
	struct is_integral<signed char> { static const bool value = 1; };
	template <>
	struct is_integral<short int> { static const bool value = 1; };
	template <>
	struct is_integral<int> { static const bool value = 1; };
	template <>
	struct is_integral<long int> { static const bool value = 1; };
	template <>
	struct is_integral<long long int> { static const bool value = 1; };
	template <>
	struct is_integral<unsigned char> { static const bool value = 1; };
	template <>
	struct is_integral<unsigned short int> { static const bool value = 1; };
	template <>
	struct is_integral<unsigned int> { static const bool value = 1; };
	template <>
	struct is_integral<unsigned long int> { static const bool value = 1; };
	template <>
	struct is_integral<unsigned long long int> { static const bool value = 1; };
}

#endif
