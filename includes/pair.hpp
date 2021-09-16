/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 13:33:21 by adbenoit          #+#    #+#             */
/*   Updated: 2021/09/16 16:55:48 by adbenoit         ###   ########.fr       */
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
            pair(const pair& pr) : first(pr.first), second(pr.second) {}
            pair(const first_type& a, const second_type& b) : first(a), second(b) {}
            pair& operator= (const pair& pr)
            {
                if (this == &pr)
                    return *this;
                this->first = pr.first;
                this->second = pr.second;
                return *this;
            }
            
            friend bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return lhs.first == rhs.first && lhs.second == rhs.second; }
            friend bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return !(lhs == rhs); }
            friend bool operator< (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second); }
            friend bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return !(rhs < lhs); }
            friend bool operator> (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return rhs < lhs; }
            friend bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return !(lhs < rhs); }


            first_type  first;
            second_type second;
    };

    template <class T1,class T2>
    ft::pair<T1,T2> make_pair (const T1& x, const T2& y)
    {
        return ft::pair<T1,T2>(x,y);
    }
}


#endif
