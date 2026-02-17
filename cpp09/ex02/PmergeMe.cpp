
#include "PmergeMe.hpp"
#include <climits>
#include <deque>
#include <utility>
#include <vector>
#include "algorithm"

size_t &p::operator[](size_t i)
{
	return this->i[i];
}

std::vector<int> ford_jonhson(std::vector<int> nums)
{
	size_t max_group_size = 0;
	for (size_t group_size = 1; nums.size() / 2 >= group_size; group_size <<= 1)
	{
		size_t n_groups = nums.size() / group_size;
		size_t n_comparisons = n_groups / 2;

		size_t starting_index = 0;
		for (size_t swap_i = 0; swap_i < n_comparisons; swap_i++, starting_index += (group_size << 1))
		{
			size_t comp_1_i = starting_index + group_size - 1;
			size_t comp_2_i = starting_index + (group_size << 1) - 1;

			bool do_swap = nums[comp_1_i] > nums[comp_2_i];
			for (size_t i = 0; do_swap && i < group_size; i++)
				std::swap(nums[starting_index + i],  nums[starting_index + group_size + i]);
		}
		max_group_size = group_size;
	}

	for (size_t group_size = max_group_size; group_size; group_size >>= 1)
	{
		std::vector<int> S;
		std::vector<int> to_insert;

		bool is_nums_odd = nums.size() & 1;
		size_t remaining_elem_n = nums.size() % group_size;
		remaining_elem_n -= is_nums_odd * (remaining_elem_n != 0);

		size_t n_groups = nums.size() - remaining_elem_n;
		n_groups /= group_size;

		size_t group_start_i = 0;
		for (size_t group_i = 0; group_i < n_groups; group_i++, group_start_i += group_size)
		{
			bool insert_to_S = !group_i || group_i % 2;
			std::vector<int> &inserted = insert_to_S? S : to_insert;

			for (size_t i = group_start_i; i < group_start_i + group_size; i++) inserted.push_back(nums[i]);
		}
		if (is_nums_odd && group_size > 1) to_insert.push_back(nums[nums.size() - 1]);

		// Binary search insertion
		while (to_insert.size())
		{
			int num = to_insert[0];

			size_t bottom = 0;
			size_t top = S.size();
			size_t compare_pos = 0;
			while (bottom + 1 < top)
			{
				compare_pos = (top - bottom) / 2 + bottom;
				//if (num <= S[compare_pos + 1] && num >= S[compare_pos]) break;
				if (num < S[compare_pos]) top = compare_pos;
				else if (num > S[compare_pos]) bottom = compare_pos;
				else break;
			}
			compare_pos = (top - bottom) / 2 + bottom;
			compare_pos += num > S[compare_pos];

			if (compare_pos == S.size()) S.push_back(num);
			else						 S.insert(S.begin() + compare_pos, num);

			to_insert.erase(to_insert.begin());
		}


		for (size_t i = 0; i < remaining_elem_n; i++) S.push_back(nums[nums.size() - 1 - remaining_elem_n + i - is_nums_odd]);

		nums = S;
	}
	return nums;
}


// If keys, ignore nums
std::vector<int> ford_jonhson(std::vector<int> nums, std::vector<size_t> *keys)
{
	if (nums.size() <= 1)
	{
		if (keys) keys->push_back(0);
		return nums;
	}

	std::vector<int> largers;
	std::vector<int> smaller;
	std::vector<p> pairs;

	// Indices of the larger array
	std::vector<size_t> inner_keys;

	bool odd_nums = nums.size() & 1;
	int unpaired = 0;
	if (odd_nums) unpaired = nums[nums.size() - 1];

	for (size_t i = 0; i < nums.size() - 1; i += 2)
	{
		size_t larger_i = i + (nums[i + 1] >= nums[i]);
		size_t smaller_i = i + (nums[i + 1] < nums[i]);

		p tmp_pair;
		tmp_pair[0] = smaller_i;
		tmp_pair[1] = larger_i;

		pairs.push_back(tmp_pair);
		smaller.push_back(nums[smaller_i]);
		largers.push_back(nums[larger_i]);
		//inner_keys.push_back(i >> 1);
	}

	std::vector<int> S = ford_jonhson(largers, &inner_keys);

	{
	std::vector<size_t> tmp_keys = inner_keys;

	// From now on, pair[x][1] refers to the array S
	// Update pairs
	for (size_t i = 0; i < tmp_keys.size(); i++)
	{
		size_t key = tmp_keys[i];
		int duplicated = false;
		for (size_t j = 0; j < i && !duplicated; j++) duplicated = duplicated || tmp_keys[j] == tmp_keys[i];
		if (duplicated) continue;

		size_t tmp = pairs[i][1];
		pairs[i][1] = pairs[key][1];
		pairs[key][1] = tmp;

		tmp = pairs[i][0];
		pairs[i][0] = pairs[key][0];
		pairs[key][0] = tmp;

	}}

	for (size_t i = 0; keys && i < inner_keys.size(); i++) keys->push_back(inner_keys[i]);

	S.insert(S.begin(), nums[pairs[0][0]]);
	for (size_t i = 1; keys && i < keys->size(); i++) keys[0][i]++;

	//std::vector<size_t> up_to_positions;
	std::vector<size_t> to_insert;
	size_t smaller_y = 1;
	size_t bigger_y = 2;
	size_t sum = 4;
	size_t current_group_size = 2;
	for (size_t i = 0; to_insert.size() < pairs.size() - 1; i++)
	{
		if (i == current_group_size)
		{
			current_group_size = sum - current_group_size;
			sum = sum << 1;
			i = 0;

			smaller_y = bigger_y + 1;
			bigger_y += current_group_size + 1;

			if (current_group_size + to_insert.size() > pairs.size() - 1) bigger_y -= current_group_size + to_insert.size() - pairs.size() - 1;
		}

		size_t tmp = bigger_y - i;

		tmp -= (current_group_size - i - 1);

		to_insert.push_back(tmp);
		//up_to_positions.push_back(bigger_y - 1);
	}
	//if (odd_nums) to_insert.push_back(unpaired);

	while (S.size() < nums.size())
	{
		size_t position_in_nums = nums.size() - 1;
		if (to_insert.size()) position_in_nums = pairs[to_insert[0]][0];

		int num = nums[position_in_nums];

		size_t insertion_pos; // Binary search
	{
		size_t top = position_in_nums;
		size_t bottom = 0;
		while (bottom + 1 < top)
		{
			size_t compare_pos = (top - bottom) / 2 + bottom;
			if (S[compare_pos - 1] <= num && S[compare_pos] >= num) {insertion_pos = compare_pos; goto after_binary_search;}

			if (S[compare_pos - 1] >= num)  top = compare_pos;
			else if (S[compare_pos] <= num) bottom = compare_pos;
		}
		insertion_pos = bottom + (nums[bottom] < num);
	}

	after_binary_search:
		S.insert(S.begin() + insertion_pos, num);
		if (keys)
		{
			if (keys->size())
				keys->insert(keys->begin() + insertion_pos, position_in_nums);
			else
				keys->push_back(position_in_nums);
			for (size_t i = insertion_pos + 1; i < keys->size(); i++) keys[0][i]++;
		}

		if (to_insert.size()) to_insert.erase(to_insert.begin());
	}

	return S;
}

std::deque<int> ford_jonhson(std::deque<int> nums)
{
	std::deque<int> out;
	return nums;
}
