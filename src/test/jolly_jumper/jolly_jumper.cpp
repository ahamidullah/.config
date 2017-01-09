#include <fstream>
#include <queue>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>

int
main(int argc, char **argv)
{
	std::ifstream file;
	file.open(argv[1]);
	std::priority_queue<int> q;
	std::string word;

	if (!file.is_open()) {
		printf("could not open file\n");
		return 1;
	}
	file >> word;
	int last = atoi(word.c_str());
	while (file >> word) {
		int num = abs(last - atoi(word.c_str()));
		q.push(num);
		last = atoi(word.c_str());
	}
	if (q.size() <= 1) {
		printf("size 1\n");
		return 0;
	}
	last = q.top();
	q.pop();
	for (int cur = q.top();
	     !q.empty();
	     q.pop(), cur = q.top()) {
		printf("%d\n", last);
		printf("%d\n", cur);
		if (cur != last-1) {
			printf("NOT JOLLY\n");
			return 0;
		}
		last = cur;
	}
	printf("JOLLY\n");
	return 0;
}

