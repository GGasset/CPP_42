
#ifndef MUTANT_HPP
#define MUTANT_HPP

#include "vector"
#include "list"
#include "deque"
#include "stack"

#define FORWARD0(name, return_type) inline return_type name() { return this->c.name(); }
#define FORWARD_CONST(name, return_type) inline return_type name() const { return (return_type)this->c.name(); }

template<class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
private:

public:
	typedef typename std::stack<T, Container>::container_type::iterator iterator; 
	typedef typename std::stack<T, Container>::container_type::const_iterator const_iterator; 

	FORWARD0(begin, iterator);
	FORWARD_CONST(begin, const_iterator);
	
	FORWARD0(end, iterator);
	FORWARD_CONST(end, const_iterator);
};

#endif

