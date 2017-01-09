#include <string>
#include <fstream>
#include <vector>

void
strrev(std::string str)
{
	int start = 0;
	int end = str.length() - 1;
	while (start < end) {
		char tmp = str[start];
		str[start++] = str[end];
		str[end--] = tmp;
	}
	printf("%s\n", str.c_str());
}

int
fib(int n)
{
	if (n == 1 || n == 2)
		return 1;
	return fib(n-1) + fib(n-2);
}

void
mult()
{
	for (int i = 1; i <= 12; ++i) {
		for (int j = 1; j <= 12; ++j) {
			printf("%3d ", j*i);
		}
		printf("\n");
	}
}

int
sum(const char *fname)
{
	std::ifstream ifs;
	ifs.open(fname);
	if (!ifs.is_open()) {
		printf("could not open file\n");
		return 0;
	}
	int cur_num = 0;
	int sum = 0;
	while (ifs >> cur_num) {
		sum += cur_num;
	}
	return sum;
}

void
insertion(std::vector<int>& v)
{
	for (int i = 0; i < v.size(); ++i) {
		int x = v[i];
		int j = i;
		while ((j > 0) && (x < v[j-1])) {
			v[j] = v[--j];
		}
		v[j] = x;
	}
}

void
selection(std::vector<int>& v)
{
	for (int i = 0; i < v.size(); ++i) {
		int min = v[i];
		int min_ind = i;
		for (int j = i+1; j < v.size(); j++) {
			if (v[j] < min) {
				min = v[j];
				min_ind = j;
			}
		}
		int x = v[i];
		v[i] = min;
		v[min_ind] = x;
	}
}

void
bubble(std::vector<int>& v)
{
	bool swapped;
	do {
		swapped = false;
		for (int i = 0; i < v.size()-1; ++i) {
			if (v[i] > v[i+1]) {
				int x = v[i];
				v[i] = v[i+1];
				v[i+1] = x;
				swapped = true;
			}
		}
	} while (swapped);
}

void
merge(std::vector<int>&v, int lo, int mid, int hi)
{
	std::vector<int> copy = v;
	int i = lo;
	int j = mid + 1;
	int index = lo;
	while ((i <= mid) && (j <= hi)) {
		if (copy[i] <= copy[j])
			v[index] = copy[i++];
		else
			v[index] = copy[j++];
		++index;
	}
	for (; i <= mid; ++i)
		v[index++] = copy[i];
	for (; j <= hi; ++j)
		v[index++] = copy[j];
}

void
mergesort(std::vector<int>& v, int lo, int hi)
{
	if (lo >= hi)
		return;

	int mid = (lo + hi)/2;
	mergesort(v, lo, mid);
	mergesort(v, mid+1, hi);

	merge(v, lo, mid, hi);
}

void
quicksort(std::vector<int>& v, int lo, int hi)
{
	std::vector<int> copy = v;
	int pivot = hi;
	int hi_bound = hi;
	int lo_bound = lo;
	if (lo >= hi)
		return;
	for (int i = lo; i < hi; ++i) {
		if (copy[i] >= copy[pivot]) {
			v[hi_bound--] = copy[i];
		} else {
			v[lo_bound++] = copy[i];
		}
	}
	v[lo_bound] = copy[pivot];
	quicksort(v, lo, lo_bound-1);
	quicksort(v, lo_bound+1, hi);
}

void
odds()
{
	for (int i = 1; i < 100; ++i) {
		if ((i % 2) == 1)
			printf("%d\n", i);
	}
}

void
rgb(unsigned char r, unsigned char g, unsigned char b)
{
	char hex[7];
	sprintf(hex, "%02X%02X%02X", r, g, b);
	printf("%s\n", hex);
}

int
main()
{
	std::string str = {"Madam, I'm Adam."};
	//strrev(str);
	int i = fib(5);
	//printf("%d\n", i);
	//mult();
	//int s = sum("test.txt");
	//printf("%d\n", s);
	//odds();
	rgb(255, 0, 168);
	std::vector<int> v1 = {2, 5, 3, 7, 1};
	insertion(v1);
	for (int i : v1)
		printf("%d\n", i);
	printf("\n");
	std::vector<int> v2 = {2, 5, 3, 7, 1};
	selection(v2);
	for (int i : v2)
		printf("%d\n", i);
	printf("\n");
	std::vector<int> v3 = {2, 5, 3, 7, 1};
	bubble(v3);
	for (int i : v3)
		printf("%d\n", i);
	printf("\n");
	std::vector<int> v4 = {2, 5, 3, 7, 1};
	mergesort(v4, 0, v4.size()-1);
	for (int i : v4)
		printf("%d\n", i);
	printf("\n");
	std::vector<int> v5 = {2, 5, 3, 7, 1};
	quicksort(v5, 0, v5.size()-1);
	for (int i : v5)
		printf("%d\n", i);
	printf("\n");
}

