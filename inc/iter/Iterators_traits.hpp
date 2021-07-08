/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterators_traits.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 18:24:40 by adbenoit          #+#    #+#             */
/*   Updated: 2021/07/08 15:50:01 by adbenoit         ###   ########.fr       */
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
	// ~ enable_if ~
 
	template <bool Cond>
	struct enable_if {};

	template <>
	struct enable_if<true> { typedef int type; };
	
	// ~ is_integral ~ 
	
	template <class T>
	struct is_integral { static const bool value = false; };
	
	template <>
	struct is_integral<bool> { static const bool value = true; };
	template <>
	struct is_integral<char> { static const bool value = true; };
	template <>
	struct is_integral<char16_t> { static const bool value = true; };
	template <>
	struct is_integral<char32_t> { static const bool value = true; };
	template <>
	struct is_integral<wchar_t> { static const bool value = true; };
	template <>
	struct is_integral<signed char> { static const bool value = true; };
	template <>
	struct is_integral<short int> { static const bool value = true; };
	template <>
	struct is_integral<int> { static const bool value = true; };
	template <>
	struct is_integral<long int> { static const bool value = true; };
	template <>
	struct is_integral<long long int> { static const bool value = true; };
	template <>
	struct is_integral<unsigned char> { static const bool value = true; };
	template <>
	struct is_integral<unsigned short int> { static const bool value = true; };
	template <>
	struct is_integral<unsigned int> { static const bool value = true; };
	template <>
	struct is_integral<unsigned long int> { static const bool value = true; };
	template <>
	struct is_integral<unsigned long long int> { static const bool value = true; };
}

#endif
