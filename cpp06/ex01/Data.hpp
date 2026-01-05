
#ifndef DATA_HPP
#define DATA_HPP

class Data
{
public:
	bool fields[7];

	Data();
	Data(const Data &src);
	Data &operator=(const Data &src);
	~Data();
};

#endif

