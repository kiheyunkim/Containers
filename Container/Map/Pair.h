#ifndef _PAIR_H_
#define _PAIR_H_

template<typename First, typename Second>
class Pair
{
public:
	First first;
	Second second;

public:
	Pair& operator=(const Pair<First, Second>& right)
	{
		first = right->first;
		second = right->second;
	}

	void swap(Pair<First, Second>& right)
	{
		First tempFirst = right.first;
		Second tempSecond = right.second;

		right.first = first;
		right.second = second;

		first = tempFirst;
		second = tempSecond;
	}
};

#endif