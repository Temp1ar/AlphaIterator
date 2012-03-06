#include <cctype>
#include <iterator>

template <class T>
class alpha_iterator: 
	public std::iterator
	<std::forward_iterator_tag, 
	 typename std::iterator_traits<typename T::iterator>::value_type>
{
	typedef typename T::iterator it;
	it beginIt_;
	it endIt_;

	it& findNext()
	{
		beginIt_++;
		while(beginIt_ != endIt_ && !isalpha(*beginIt_)) {
			beginIt_++;
		}

		return beginIt_;
	}

public:
	alpha_iterator(it b, it e) :
		beginIt_(b), endIt_(e)
	{
		  if(!isalpha(*b)) {
			  findNext();
		  }
	}

	alpha_iterator(it e) :
		beginIt_(e), endIt_(e)
	{}
	
	it& operator++() 
	{
		return findNext();
	}

	it operator++(int) 
	{
		it temp = beginIt_;
		findNext();
		return temp;
	}

	bool operator==(const alpha_iterator& another) 
	{
		return (beginIt_ == another.beginIt_);
	}

	bool operator!=(const alpha_iterator& another) 
	{
		return (beginIt_ != another.beginIt_);
	}

	typename std::iterator_traits<it>::reference operator*() 
	{
		return *beginIt_;
	}

};