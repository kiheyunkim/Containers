#include"Vector.h"
#include<vector>
void main()
{
	Vector vec;
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	vec.push_back(6);
	vec.push_back(7);

	for (Vector::Iterator iter = vec.Begin(); iter != vec.End(); iter++)
	{
		std::cout << *iter << ' ';
	}
}