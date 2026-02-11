# Solving Data Structure and Algorithm Problems on LeetCode Using C++

This repository contains 🌟 **solutions** to various data structure and algorithm problems from [LeetCode](https://leetcode.com/). All solutions are implemented in **C++** and are structured for easy understanding and reusability.

## 🗂️ Repository Structure

- 📂 **Each solution** is stored in a separate C++ file, named according to the problem number and title.
- 🏷️ **Organized by category**: Arrays, Strings, Trees, Graphs, and more.

### Directory Layout

<pre><code>
📂 .
├── 📁 backtracking
│   ├── 📁 medium
│   │   ├── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/backtracking/medium/22.generate_parentheses.cpp">22.generate_parentheses.cpp</a>
│   │   ├── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/backtracking/medium/46.permutations.cpp">46.permutations.cpp</a>
│   │   ├── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/backtracking/medium/47.permutations_ii.cpp">47.permutations_ii.cpp</a>
│   │   ├── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/backtracking/medium/78.subsets.cpp">78.subsets.cpp</a>
│   │   ├── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/backtracking/medium/784.letter_case_permutation.cpp">784.letter_case_permutation.cpp</a>
│   │   ├── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/backtracking/medium/90.subsets_ii.cpp">90.subsets_ii.cpp</a>
│   │   └── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/backtracking/medium/95.unique_binary_search_trees_ii.cpp">95.unique_binary_search_trees_ii.cpp</a>
├── 📁 binary-search
│   ├── 📁 easy
│   │   ├── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/binary-search/easy/35.search_insert_position.cpp">35.search_insert_position.cpp</a>
│   │   └── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/binary-search/easy/744.find_smallest_letter_greater_than_target.cpp">744.find_smallest_letter_greater_than_target.cpp</a>
│   ├── 📁 hard
│   │   └── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/binary-search/hard/154.find_minimum_in_rotated_sorted_array_ii.cpp">154.find_minimum_in_rotated_sorted_array_ii.cpp</a>
│   ├── 📁 medium
│   │   ├── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/binary-search/medium/153.find_minimum_in_rotated_sorted_array.cpp">153.find_minimum_in_rotated_sorted_array.cpp</a>
│   │   ├── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/binary-search/medium/33.search_in_rotated_sorted_array.cpp">33.search_in_rotated_sorted_array.cpp</a>
│   │   ├── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/binary-search/medium/34.find_first_and_last_position_of_element_in_sorted_array.cpp">34.find_first_and_last_position_of_element_in_sorted_array.cpp</a>
│   │   ├── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/binary-search/medium/702.search_in_a_sorted_array_of_unknown_size.cpp">702.search_in_a_sorted_array_of_unknown_size.cpp</a>
│   │   └── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/binary-search/medium/81.search_in_rotated_sorted_array_ii.cpp">81.search_in_rotated_sorted_array_ii.cpp</a>
├── 📁 bit-manipulation
│   ├── 📁 easy
│   │   └── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/bit-manipulation/easy/136.single_number.cpp">136.single_number.cpp</a>
│   ├── 📁 medium
│   │   └── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/bit-manipulation/medium/260.single_number_iii.cpp">260.single_number_iii.cpp</a>
├── 📁 depth-first-search
│   ├── 📁 easy
│   │   ├── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/depth-first-search/easy/112.path_sum.cpp">112.path_sum.cpp</a>
│   │   ├── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/depth-first-search/easy/257.binary_tree_paths.cpp">257.binary_tree_paths.cpp</a>
│   │   └── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/depth-first-search/easy/543.diameter_of_binary_tree.cpp">543.diameter_of_binary_tree.cpp</a>
│   ├── 📁 hard
│   │   └── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/depth-first-search/hard/124.binary_tree_maximum_path_sum.cpp">124.binary_tree_maximum_path_sum.cpp</a>
│   ├── 📁 medium
│   │   ├── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/depth-first-search/medium/113.path_sum_ii.cpp">113.path_sum_ii.cpp</a>
│   │   ├── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/depth-first-search/medium/129.sum_root_to_leaf_numbers.cpp">129.sum_root_to_leaf_numbers.cpp</a>
│   │   ├── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/depth-first-search/medium/1430.check_if_a_string_is_a_valid_sequence_from_root_to_leaves_path.cpp">1430.check_if_a_string_is_a_valid_sequence_from_root_to_leaves_path.cpp</a>
│   │   └── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/depth-first-search/medium/437.path_sum_iii.cpp">437.path_sum_iii.cpp</a>
├── 📁 design
│   ├── 📁 easy
│   │   ├── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/design/easy/225.implement_stack_using_queues.cpp">225.implement_stack_using_queues.cpp</a>
│   │   └── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/design/easy/232.implement_queue_using_stacks.cpp">232.implement_queue_using_stacks.cpp</a>
│   ├── 📁 medium
│   │   ├── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/design/medium/146.lru_cache.cpp">146.lru_cache.cpp</a>
│   │   └── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/design/medium/2502.design_memory_allocator.cpp">2502.design_memory_allocator.cpp</a>
├── 📁 dynamic-programming
│   ├── 📁 easy
│   │   └── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/dynamic-programming/easy/509.fibonacci_number.cpp">509.fibonacci_number.cpp</a>
│   ├── 📁 medium
│   │   └── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/dynamic-programming/medium/96.unique_binary_search_trees.cpp">96.unique_binary_search_trees.cpp</a>
├── 📁 graph
│   ├── 📁 easy
│   │   └── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/graph/easy/1971.find_if_path_exists_in_graph.cpp">1971.find_if_path_exists_in_graph.cpp</a>
│   ├── 📁 hard
│   │   └── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/graph/hard/815.bus_routes.cpp">815.bus_routes.cpp</a>
│   ├── 📁 medium
│   │   ├── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/graph/medium/1557.minimum_number_of_vertices_to_reach_all_nodes.cpp">1557.minimum_number_of_vertices_to_reach_all_nodes.cpp</a>
│   │   ├── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/graph/medium/547.number_of_provinces.cpp">547.number_of_provinces.cpp</a>
│   │   └── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/graph/medium/802.find_eventual_safe_states.cpp">802.find_eventual_safe_states.cpp</a>
├── 📁 heap-priority-queue
│   ├── 📁 hard
│   │   └── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/heap-priority-queue/hard/295.find_median_from_data_stream.cpp">295.find_median_from_data_stream.cpp</a>
│   ├── 📁 medium
│   │   └── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/heap-priority-queue/medium/436.find_right_interval.cpp">436.find_right_interval.cpp</a>
├── 📁 linked-list
│   ├── 📁 easy
│   │   ├── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/linked-list/easy/206.reverse_linked_list.cpp">206.reverse_linked_list.cpp</a>
│   │   ├── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/linked-list/easy/21.merge_two_sorted_lists.cpp">21.merge_two_sorted_lists.cpp</a>
│   │   └── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/linked-list/easy/83.remove_duplicates_from_sorted_list.cpp">83.remove_duplicates_from_sorted_list.cpp</a>
│   ├── 📁 medium
│   │   ├── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/linked-list/medium/24.swap_nodes_in_pairs.cpp">24.swap_nodes_in_pairs.cpp</a>
│   │   ├── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/linked-list/medium/82.remove_duplicates_from_sorted_list_ii.cpp">82.remove_duplicates_from_sorted_list_ii.cpp</a>
│   │   └── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/linked-list/medium/92.reverse_linked_list_ii.cpp">92.reverse_linked_list_ii.cpp</a>
├── 📁 matrix
│   ├── 📁 easy
│   │   ├── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/matrix/easy/463.island_perimeter.cpp">463.island_perimeter.cpp</a>
│   │   └── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/matrix/easy/733.flood_fill.cpp">733.flood_fill.cpp</a>
│   ├── 📁 medium
│   │   ├── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/matrix/medium/1254.number_of_closed_islands.cpp">1254.number_of_closed_islands.cpp</a>
│   │   ├── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/matrix/medium/1559.detect_cycles_in_2d_grid.cpp">1559.detect_cycles_in_2d_grid.cpp</a>
│   │   ├── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/matrix/medium/200.number_of_islands.cpp">200.number_of_islands.cpp</a>
│   │   ├── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/matrix/medium/694.number_of_distinct_islands.cpp">694.number_of_distinct_islands.cpp</a>
│   │   └── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/matrix/medium/695.max_area_of_island.cpp">695.max_area_of_island.cpp</a>
├── 📁 prefix-sum
│   ├── 📁 easy
│   │   └── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/prefix-sum/easy/303.range_sum_query_immutable.cpp">303.range_sum_query_immutable.cpp</a>
├── 📁 stack
│   ├── 📁 medium
│   │   └── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/stack/medium/155.min_stack.cpp">155.min_stack.cpp</a>
├── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/LICENSE">LICENSE</a>
├── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/README.md">README.md</a>
├── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/directory_layout_script.py">directory_layout_script.py</a>
├── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/problem_description_script.py">problem_description_script.py</a>
└── <a href="https://github.com/abdulaziz7225/leetcode-problems-in-cpp/blob/main/requirements.txt">requirements.txt</a>
</code></pre>

💡 **Pro Tip**: Click the filenames to view each solution directly on GitHub!

---

## 🔑 Problem Categories

| 📂 **Category**            | 📜 **Description**                                      |
| -------------------------- | ------------------------------------------------------- |
| 📊 **Arrays**              | Searching, sorting, subarray sums, and more.            |
| 🧵 **Strings**             | String manipulations, substrings, and pattern matching. |
| 🔗 **Linked Lists**        | Singly, doubly linked list problems.                    |
| 🌲 **Trees**               | Binary trees, search trees, and n-ary trees.            |
| 🗺️ **Graphs**              | Traversals, shortest paths, and connectivity.           |
| 🚀 **Dynamic Programming** | Optimal substructure and overlapping subproblems.       |

---

## 🛠️ Solution Format

Each solution file contains:

1. **Problem Description**: A detailed explanation of the problem, its constraints, and examples.
2. **Test Cases**: Example inputs and expected outputs.
3. **Python Implementation**: The function or class implementing the solution.
4. **Time and Space Complexity Analysis**: A brief analysis of the efficiency of the solution.
