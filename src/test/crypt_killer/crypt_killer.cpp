#include <fstream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>

std::vector<std::string>
get_possible_word_translations(const std::vector<std::string>& v, int crypt_len)
{
	std::vector<std::string> pos_trans;
	for (auto str : v) {
		if (crypt_len == str.size()) {
			pos_trans.push_back(str);
		}
	}
	return pos_trans;
}

std::vector<char>
get_possible_char_translations(const std::vector<std::string>& v, int index)
{
	std::vector<char> pos_trans;
	for (auto str : v) {
		pos_trans.push_back(str[index]);
	}
	return pos_trans;
}

std::vector<char>
intersect_char_translations(const std::vector<char> new_translations, const std::vector<char> old_translations)
{
	std::vector<char> merged_translations;
	int nt_ind = 0;
	if (new_translations.size() == 0) {
		printf("here\n");
		return merged_translations;
	}
	if (old_translations.size() == 0) {
		merged_translations = new_translations;
		return merged_translations;
	}
	for (int i = 0; i < old_translations.size(); i++) {
		for (int j = 0; j < new_translations.size(); j++) {
			if (old_translations[i] == new_translations[j]) {
				merged_translations.push_back(new_translations[j]);
				break;
			}
		}
	}
	return merged_translations;
}

int
main(int argc, char *argv[])
{
	std::ifstream file;
	file.open(argv[1]);
	if (!file.is_open()) {
		printf("could not open file\n");
		return 1;
	}

	std::string word;
	std::vector<std::string> dict;
	file >> word;
	int num_dict_ents = atoi(word.c_str());
	dict.reserve(num_dict_ents);
	for (int i = 0; i < num_dict_ents; i++) {
		file >> word;
		dict.push_back(word);
	}

	std::vector<std::vector<char>> translation_table(26);
	std::vector<std::string> encrypted_sentence;
	while (file >> word) {
		std::vector<std::string> pt = get_possible_word_translations(dict, word.size());
		for (int i = 0; i < word.size(); i++) {
			char crypt_char = word[i];
			std::vector<char> pc = get_possible_char_translations(pt, i);
			translation_table[crypt_char - 'a'] = intersect_char_translations(pc, translation_table[crypt_char - 'a']);
			if (translation_table[crypt_char - 'a'].size() == 0) {
				printf("here2\n");
				exit(0);
			}
		}
		encrypted_sentence.push_back(word);
	}
	for (auto word : encrypted_sentence) {
		std::string final;
		final.reserve(word.size());
		std::vector<int> ind;
		ind.reserve(word.size());
		for (int i = 0; i < word.size(); i++) {
			char c = word[i];
			if (translation_table[c - 'a'].size() == 1) {
				final.push_back(translation_table[c-'a'][0]);
				ind.push_back(i);
			}
		}
		if (final.size() == word.size())
			printf("%s ", final.c_str());
		else {
			std::vector<std::string> matches;
			for (auto ent : dict) {
				bool match = true;
				for (int i = 0; i < ind.size(); i++) {
					if (ent[ind[i]] != final[i]) {
						match = false;
						break;
					}
				}
				if (match)
					matches.push_back(ent);
			}
			if (matches.size() == 1)
				printf("%s ", matches[0].c_str());
			else
				exit(0);
		}
	}
	printf("\n");
	return 0;
}

