#include "Gems.h"

int GemsCount(const string & gems, const string & stones)
{
	int count = 0;
	for (const auto& i : stones)
	{
		for (const auto& j : gems)
		{
			if (i == j)
			{
				count++;
				break;
			}
		}
	}
	return count;
}
