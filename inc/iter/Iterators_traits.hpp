/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterators_traits.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 18:24:40 by adbenoit          #+#    #+#             */
/*   Updated: 2021/07/06 19:11:07 by adbenoit         ###   ########.fr       */
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
    	typedef std::random_access_iterator_tag	iterator_category;
};

#endif
