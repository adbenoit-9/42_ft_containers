/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 13:33:21 by adbenoit          #+#    #+#             */
/*   Updated: 2021/07/16 17:59:34 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
    template <class T1, class T2>
    class pair
    {
        public:
            typedef T1  first_type;
            typedef T2  second_type;
            
            pair() {}
            template<class U, class V>
            pair (const pair<U,V>& pr) : _first(pr._first), _second(pr._second) {}
            pair (const first_type& a, const second_type& b) : _first(a), _second(b) {}
            pair& operator= (const pair& pr)
            {
                this->_first = pr._first;
                this->_second = pr._second;
            }
            
            friend bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return lhs._first==rhs._first && lhs._second==rhs._second; }
            friend bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return !(lhs == rhs); }
            friend bool operator< (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return lhs._first<rhs._first || (!(rhs._first<lhs._first) && lhs._second<rhs._second); }
            friend bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return !(rhs < lhs); }
            friend bool operator> (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return rhs < lhs; }
            friend bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return !(lhs < rhs); }

        private:
            first_type  _first;
            second_type _second;
    };
}

#endif
