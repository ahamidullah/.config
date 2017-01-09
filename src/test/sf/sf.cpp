#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <iostream>

void
register_combo(std::unordered_map<std::string, std::string>& combo_list, std::string inputs, std::string name)
{
	combo_list.insert({inputs, name});
}

void
on_key(std::string partial_input, const std::unordered_map<std::string, std::string>& combo_list, std::stack<std::string> total_input)
{
	auto combo = combo_list.find(partial_input);
	if (combo != combo_list.end()) {
		printf("%s\n", combo->second.c_str());
	}
	if (total_input.empty()) {
		return;
	}
	partial_input = total_input.top() + " " + partial_input;
	total_input.pop();
	on_key(partial_input, combo_list, total_input);
}

int
main(int argc, char *argv[])
{
	std::stack<std::string> total_input;
	std::unordered_map<std::string, std::string> combo_list;
	register_combo(combo_list, "up", "xyz");
	register_combo(combo_list, "up a b", "qwe");
	/*for (auto& x : combo_list)
		printf("%s, %s\n", x.first.c_str(), x.second.c_str());*/
	std::string input;
	while (std::cin >> input) {
		on_key(input, combo_list, total_input);
		total_input.push(input);
	}
}

