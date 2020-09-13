#ifndef TRIPLE_H
#define TRIPLE_H


template<class elemType>
class Triple {
	public:
		Triple(elemType, elemType, elemType);
		
		//setters
		void set_first(elemType);
		void set_second(elemType);
		void set_third(elemType);
	
		//getters
		elemType get_first();
		elemType get_second();
		elemType get_third();


		elemType get_max();
		elemType get_min();
		int      num_unique();
		bool     contains(const elemType&);
		void     print();
	
	private:
		elemType first, second, third;
};


template <class elemType>
Triple<elemType>::Triple(elemType first, elemType second, elemType third)
{
	this->first = first;
	this->second = second;
	this->third = third;
}

template <class elemType>
void Triple<elemType>::set_first(elemType first)
{
	this->first = first;
}

template <class elemType>
void Triple<elemType>::set_second(elemType second)
{
	this->second = second;
}

template <class elemType>
void Triple<elemType>::set_third(elemType third)
{
	this->third = third;
}

template <class elemType>
elemType Triple<elemType>::get_first()
{
	return this->first;
}

template <class elemType>
elemType Triple<elemType>::get_second()
{
	return this->second;
}

template <class elemType>
elemType Triple<elemType>::get_third()
{
	return this->third;
}

template <class elemType>
elemType Triple<elemType>::get_max()
{
	if (first >= second && first >= third)
		return first;
	if (second >= first && second >= third)
		return second;
	if (third >= first && third >= second)
		return third;
	return first; //if here means they're all the same 
}


template <class elemType>
elemType Triple<elemType>::get_min()
{
	if (first <= second && first <= third)
		return first;
	if (second <= first && second <= third)
		return second;
	if (third <= first && third <= second)
		return third;
	return first; //if here means they're all the same 
}

template <class elemType>
int Triple<elemType>::num_unique()
{
	
	if (first != second && second != third && first != third)
		return 3;
	if (first != second || second != third || first != third)
		return 2;
	return 1;		
}

template <class elemType>
bool Triple<elemType>::contains(const elemType& cpy)
{
	if (first == cpy || second == cpy || third == cpy)
		return true;
	return false; 
}

template <class elemType>
void Triple<elemType>::print()
{
	std::cout << "(" << first << "," << second << "," << third << ")\n";}

#endif
