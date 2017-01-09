#include "zlib.h"

#include <vector>
#include <algorithm>
#include <cstdlib>

std::vector<int>
gen_numbers()
{
	srand(time(NULL));

	std::vector<int> nums;
	for (int i = 0; i < 10000000; ++i) {
		nums.push_back(i);
	}
	for (int i = 0; i < 1000000; ++i) {
		std::swap(nums[i], nums[(rand() % (10000000 + 1 - i)) + i]);
	}
	return nums;
}

std::vector<int>
rot1(std::vector<int> what, size_t many)
{
	int t;
	many = many%what.size();
	int final = 0;
	for (size_t i = 0; i < many; ++i) {
		t = what[i];
		size_t prevc = i;
		size_t rotc = what.size()-(many-i);
		for (size_t c = i+many; c != i; c = (c+many)%what.size()) {
			if (c < many)
				++final;
			what[prevc] = what[c];
			prevc = c;
		}
		what[rotc] = t;
		if (++final == many)
			break;
	}
	return what;
}

std::vector<int>
rot2(std::vector<int> what, size_t many)
{
	auto reverse = [&what](int i, int j) {
		while (i < j) {
			int tmp = what[i];
			what[i++] = what[j];
			what[j--] = tmp;
		}
	};
	reverse(0, many-1);
	reverse(many, what.size()-1);
	reverse(0, what.size()-1);
	return what;
}

struct Date {
	int month;
	int day;
	int year;
};

int
main(int argc, char **argv)
{
	std::vector<int> v = { 1, 5, 7, 4, 9, 3 };
	auto rv = rot1(v, 4);
	for (auto i : rv)
		printf("%d, ", i);
	printf("\n");
	return 0;
}

