/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 13:33:21 by adbenoit          #+#    #+#             */
/*   Updated: 2021/07/16 19:49:30 by adbenoit         ###   ########.fr       */
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
            pair (const pair<U,V>& pr) : first(pr.first), second(pr.second) {}
            pair (const first_type& a, const second_type& b) : first(a), second(b) {}
            pair& operator= (const pair& pr)
            {
                this->first = pr.first;
                this->second = pr.second;
            }
            
            friend bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return lhs.first==rhs.first && lhs.second==rhs.second; }
            friend bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return !(lhs == rhs); }
            friend bool operator< (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }
            friend bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return !(rhs < lhs); }
            friend bool operator> (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return rhs < lhs; }
            friend bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return !(lhs < rhs); }

        public:
            first_type  first;
            second_type second;
    };
}

#endif
