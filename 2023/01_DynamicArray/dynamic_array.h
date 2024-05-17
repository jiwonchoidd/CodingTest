#pragma once
template <typename T>
class dynamic_array
{
	T* data;
	size_t n;
public:
	dynamic_array()
	{
	};
	dynamic_array(int n)
	{
		this->n = n;
		data = new T[n];
	};
};

