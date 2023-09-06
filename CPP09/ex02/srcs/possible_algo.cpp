#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int compare(int x, int y) {
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

// int fn_comparator(int (*f)(int, int), int x, int y) {
//     int r = f(x, y);
//     if (r < 0) return -1;
//     if (r > 0) return 1;
//     return 0;
// }

// int jacobsthal(int n) {
//     return round((pow(2, n) + pow(-1, n - 1)) / 3);
// }

// std::vector<int> pending_element_order(int n) {
//     std::vector<int> pending_elements;
//     for (int i = 0; ; ++i) {
//         int jacobsthal_n = jacobsthal(i);
//         if (jacobsthal_n > n) {
//             pending_elements.push_back(n);
//             n = i;
//         } else {
//             break;
//         }
//     }
//     pending_elements.push_back(n);

//     std::vector<int> insertion_indices;
//     for (size_t i = 0; i < pending_elements.size() - 1; ++i) {
//         int a = pending_elements[i];
//         int b = pending_elements[i + 1];
//         for (int j = b; j >= a; --j) {
//             insertion_indices.push_back(j);
//         }
//     }
//     return insertion_indices;
// }

// int binary_search_insertion_point(int (*comp)(int, int), int n, std::vector<int>& coll, int lower_bound, int upper_bound) {
//     if (lower_bound > upper_bound) {
//         return lower_bound;
//     } else {
//         int mid_index = (lower_bound + upper_bound) / 2;
//         int comparison_result = fn_comparator(comp, n, coll[mid_index]);
//         if (comparison_result > 0) {
//             return binary_search_insertion_point(comp, n, coll, mid_index + 1, upper_bound);
//         } else if (comparison_result < 0) {
//             return binary_search_insertion_point(comp, n, coll, lower_bound, mid_index - 1);
//         } else {
//             return mid_index;
//         }
//     }
// }

// int binary_search_insertion_point(int n, std::vector<int>& coll, int (*comp)(int, int)) {
//     return binary_search_insertion_point(comp, n, coll, 0, coll.size() - 1);
// }


// std::vector<int> insert(std::vector<int>& coll, int n, int i) {
//     std::vector<int> result;
//     result.insert(result.end(), coll.begin(), coll.begin() + i);
//     result.push_back(n);
//     result.insert(result.end(), coll.begin() + i, coll.end());
//     return result;
// }

// std::vector<int> binary_insert(std::vector<int>& coll, int n, int (*comp)(int, int)) {
//     int index = binary_search_insertion_point(comp, n, coll);
//     return insert(coll, n, index);
// }

std::vector<int> sort(std::vector<int>& coll, int (*comp)(int, int)) {
    if (coll.size() < 2) {
        return coll;
    } else {
        std::vector<int> sorted_pairs_v;
        for (size_t i = 0; i < coll.size(); i += 2) {
            int a = coll[i];
            int b = (i + 1 < coll.size()) ? coll[i + 1] : coll[i];
            if (comp(a, b) < 0) {
                sorted_pairs_v.push_back(a);
                sorted_pairs_v.push_back(b);
            } else {
                sorted_pairs_v.push_back(b);
                sorted_pairs_v.push_back(a);
            }
        }

        std::vector<int>::iterator _i;
        for (_i = sorted_pairs_v.begin(); _i != sorted_pairs_v.end(); _i++)
        {
            std::cout << "sorted_pairs_v " << *_i << std::endl;
        }

        std::vector<int> main_chain;
        main_chain.insert(main_chain.end(), sorted_pairs_v.begin(), sorted_pairs_v.begin() + sorted_pairs_v.size() / 2);

        for (_i = main_chain.begin(); _i != main_chain.end(); _i++)
        {
            std::cout << "main_chain" << *_i << std::endl;
        }
        
        std::vector<int> pending_elements;
        pending_elements.insert(pending_elements.end(), sorted_pairs_v.begin() + sorted_pairs_v.size() / 2, sorted_pairs_v.end());
        // if (coll.size() % 2 == 1) {
        //     pending_elements.push_back(coll[coll.size() - 1]);
        // }
        for (_i = pending_elements.begin(); _i != pending_elements.end(); _i++)
        {
            std::cout << "pending elements" << *_i << std::endl;
        }
        return(sorted_pairs_v);

        // std::vector<int> a_positions(main_chain.size());
        // for (size_t i = 0; i < a_positions.size(); ++i) {
        //     a_positions[i] = i;
        // }

        // for (size_t i = 0; i < pending_elements.size(); ++i) {
        //     int n = pending_elements[i];
        //     int insert_index = binary_search_insertion_point(comp, n, main_chain);
        //     for (size_t j = 0; j < a_positions.size(); ++j) {
        //         if (a_positions[j] >= insert_index) {
        //             a_positions[j]++;
        //         }
        //     }
        //     a_positions.insert(a_positions.begin() + insert_index, insert_index);
        //     main_chain.insert(main_chain.begin() + insert_index, n);
        // }

        // return main_chain;
    }
}

int main() {
    std::vector<int> data;
    data.push_back(5);
    data.push_back(3);
    data.push_back(8);
    data.push_back(1);
    data.push_back(9);
    data.push_back(2);
    data.push_back(7);

    sort(data, compare);

    // for (size_t i = 0; i < sorted_data_v.size(); ++i) {
    //     std::cout << sorted_data_v[i] << " ";
    // }

    return 0;
}
