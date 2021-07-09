/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 14:08:07 by adbenoit          #+#    #+#             */
/*   Updated: 2021/07/10 01:09:53 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
    class stack
	{
		private:
			Container			_c;

		public:
			typedef Container	container_type;
			typedef	T			value_type;
			typedef size_t		size_type;
			
			explicit stack(const container_type& ctnr = container_type())	{ this->_c = ctnr; }
			
			bool                empty() const				{ return this->_c.empty(); }
			size_type           size() const				{ return this->_c.size(); }
			value_type&         top()						{ return (this->_c.back()); }
			const value_type&   top() const					{ return (this->_c.back()); }
			void                push(const value_type& val)	{ this->_c.push_back(val); }
			void                pop()						{ this->_c.pop_back(); }

		friend bool operator==	(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {return (lhs._c == rhs._c);}
		friend bool operator!=	(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {return (lhs._c != rhs._c);}
		friend bool operator<	(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {return (lhs._c < rhs._c);}
		friend bool operator<=	(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {return (lhs._c <= rhs._c);}
		friend bool operator>	(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {return (lhs._c > rhs._c);}
		friend bool operator>=	(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {return (lhs._c >= rhs._c);}
	};
}

#endif
