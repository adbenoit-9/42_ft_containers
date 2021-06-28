template< class T, class Allocator = std::allocator<T> > 
List::List() : _size(0)
{
   Allocator    alloc;
   this->_values = alloc.allocate(0);

}

template< class T, class Allocator = std::allocator<T> > 
explicit List::List(const Allocator& alloc)
{
   Allocator    alloc;
   this->_values = alloc.allocate(0);
}


template< class T, class Allocator = std::allocator<T> > 
explicit List::List(List::size_type count, const T& value = T(), const Allocator& alloc = Allocator()) : _size(count)
{
   Allocator    alloc;
   this->_values = alloc.allocate(_size);

    for (int i = 0; i < count; i++)
        this->_values[i] = value;
}


template< class T, class Allocator = std::allocator<T> > 
template< class InputIt >
List::List(InputIt first, InputIt last, const Allocator& alloc = Allocator())
{
    
}


List::List(const List& other)
{
    
}


List::~List()
{
    
}


// ft_List&			List::operator=(const ft_List& other)
// {
    
// }



// void				assign(size_type count, const T& value)
// {
    
// }


// template< class InputIt >
// void				assign(InputIt first, InputIt last)
// {
    
// }
 
// /*
// ** Element access
// */
    
// reference				front()
// {
    
// }


// const_reference			front() const
// {
    
// }


// reference				back()
// {
    
// }


// const_reference			back() const
// {
    
// }


// /*
// ** Iterators
// */
    
// iterator				begin()
// {
    
// }


// const_iterator			begin() const
// {
    
// }


// iterator				end()
// {
    
// }


// const_iterator			end() const
// {
    
// }


// reverse_iterator		rbegin()
// {
    
// }


// const_reverse_iterator	rbegin() const
// {
    
// }


// reverse_iterator		rend()
// {
    
// }


// const_reverse_iterator	rend() const
// {
    
// }



// /*
// ** Capacity
// */
    
    
//     bool					empty() const
// {
    
// }


// size_type				size() const
// {
    
// }


// size_type				max_size() const
// {
    
// } 

// /*
// ** Modifiers
// */
    
//     void 					clear()
// {
    
// }


// iterator				insert(iterator pos, const T& value)
// {
    
// }


// void					insert(iterator pos, size_type count, const T& value)
// {
    
// }


// template<class InputIt>
// void					insert(iterator pos, InputIt first, InputIt last)
// {
    
// }


// iterator				erase(iterator pos)
// {
    
// }


// iterator				erase(iterator first, iterator last)
// {
    
// }


// void					push_back(const T& value)
// {
    
// }


// void					pop_back()
// {
    
// }


// void					push_front(const T& value)
// {
    
// }


// void					pop_front()
// {
    
// }


// void					resize(size_type count, T value = T())
// {
    
// }


// void					swap(List& other)
// {
    
// }
 
//  /*
// ** Operations
// */
    
// void					merge(List& other)
// {
    
// }


// template <class Compare> 
// void					merge(List& other, Compare comp)
// {
    
// }


// void					splice(const_iterator pos, List& other)
// {
    
// }


// void					splice(const_iterator pos, List& other, const_iterator it)
// {
    
// }


// void					splice(const_iterator pos, List& other, const_iterator first, const_iterator last)
// {
    
// }


// void					remove( const T& value )
// {
    
// }


// template<class UnaryPredicate>
// void					remove_if(UnaryPredicate p)
// {
    
// }


// void					reverse()
// {
    
// }


// void					unique()
// {
    
// }


// template<class BinaryPredicate>
// void					unique(BinaryPredicate p)
// {
    
// }


// void					sort()
// {
    
// }


// template<class Compare> 
// void					sort(Compare comp)
// {
    
// }