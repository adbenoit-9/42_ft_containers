/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 14:08:07 by adbenoit          #+#    #+#             */
/*   Updated: 2021/06/30 14:53:23 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include <deque>

template <class T, class Container = std::deque<T> >
class stack
{
    private:
        typedef Container container_type;
        typedef T value_type;
        typedef size_t size_type;
        Container   _c;
    public:
        stack()  {}
        // explicit stack (const container_type& ctnr = container_type());
        
        bool                empty() const;
        size_type           size() const;
        value_type&         top();
        const value_type&   top() const;
        void                push(const value_type& val);
        void                pop();
};

// explicit stack (const container_type& ctnr = container_type())
// {
    
// }

template <class T, class Container>
bool                                    stack<T, Container>::empty() const
{
    return (this->_c.empty());
}

template <class T, class Container>
stack<T, Container>::size_type          stack<T, Container>::size() const
{
    return (this->_c.size());
}

template <class T, class Container>
stack<T, Container>::value_type&         stack<T, Container>::top()
{
    return (this->c.back);
}

template <class T, class Container>
const stack<T, Container>::value_type&   stack<T, Container>::top() const
{
    return (this->c.back);
}

template <class T, class Container>
void                                    stack<T, Container>::push(const stack<T, Container>::value_type& val)
{
    this->_c.push_back(val);
}

template <class T, class Container>
void                stack<T, Container>::pop()
{
    this->_c.pop_back(val);
}



#endif