#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

std::vector<int>
parse_triangle_file(const char *fname)
{
	FILE *fp = fopen(fname, "r");
	if (!fp) {
		printf("error: could not open triangle file\n");
		exit(EXIT_FAILURE);
	}
	
	std::vector<int> triangle;
	char num_buf[1024]; //only partially reads numbers with more than 1023 digits
	while (fscanf(fp, "%1023s", num_buf) == 1) {
		int num = strtol(num_buf, NULL, 0);
		// assume no negative numbers
		assert(num >= 0);
		triangle.push_back(num);
	}
	fclose(fp);
	return triangle;
}

// translate from row-column position to an index offset in the linear array.
// calculate the sum of 0 + 1 + ... + row to represent right end of the row (-1 b/c 0 indexed).
// offset backwards based on our column.
int
rowcol_to_index(const int row, const int col)
{
	return (((row*(row+1)/2)-1) - (row-col));
}

bool
is_last_row(const std::vector<int> triangle, const int row)
{
	//row is equal to row's length
	const int ind = rowcol_to_index(row, row);
	assert(ind < triangle.size());
	return (ind == triangle.size()-1);
}

int
max_sum_from(const std::vector<int>& triangle, std::vector<int> *sum_cache, const int row, const int col)
{
	int ind = rowcol_to_index(row, col);
	assert(ind < triangle.size());
	assert(ind < sum_cache->size());

	if (sum_cache->at(ind) != -1) {
		return sum_cache->at(ind);
	}
	const int current = triangle[ind];

	if (is_last_row(triangle, row)) {
		return current;
	}

	const int left_branch = max_sum_from(triangle, sum_cache, row+1, col);
	sum_cache->at(rowcol_to_index(row+1, col)) = left_branch;

	const int right_branch = max_sum_from(triangle, sum_cache, row+1, col+1);
	sum_cache->at(rowcol_to_index(row+1, col+1)) = right_branch;

	return (current+left_branch > current+right_branch) ? (current+left_branch) : (current+right_branch);
}

int
main(int argc, char **argv)
{
	const std::vector<int> triangle = parse_triangle_file("triangle.txt");
	std::vector<int> cache;
	cache.resize(triangle.size(), -1);
	const int max_sum = max_sum_from(triangle, &cache, 1, 1);
	printf("Max sum: %d\n", max_sum);
	return 0;
}
