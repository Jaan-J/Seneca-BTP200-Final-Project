// Milestone: 3
// Date: 2021/3/27
// Author: Jaan Javed
// Student Number: 100131192
///////////////////////////////////////////////////
#include <cstring>
#include "utils.h"
#include "IOAble.h"

using namespace std;
namespace sdds
{
	istream &operator>>(istream &first, IOAble &obj)
	{
		return obj.read(first);
	}

	ostream &operator<<(ostream &first, const IOAble &obj)
	{
		return obj.write(first);
	}
}