#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <list>
#include <deque>
#include <random>
#include "header3.4.h"

using namespace std;

int main() {
    const int M = 5;
    const int N = 20;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(-N, N);

    // 1. Создаем 4 разных контейнера
    array<int, M> arr;
    vector<int> vec(M);
    list<int> lst(M);
    deque<int> deq(M);

    // Заполняем их случайными числами
    for (int i = 0; i < M; ++i) arr[i] = dist(gen);
    for (int i = 0; i < M; ++i) vec[i] = dist(gen);
    for (auto& elem : lst) elem = dist(gen);
    for (auto& elem : deq) elem = dist(gen);

    int second_arg = dist(gen);

    // Приёмники для результатов (тип double)
    deque<double> res_arr;
    list<double> res_vec;
    vector<double> res_lst;
    array<double, M> res_deq;

    // 2. Используем ТРИ РАЗНЫХ вида циклов for

    // Вид 1: Обычный for с индексом [i]
    for (size_t i = 0; i < M; ++i) {
        res_arr.push_back(RandomAdd::extended_add<double>(arr[i], second_arg));
    }
    for (size_t i = 0; i < M; ++i) {
        res_vec.push_back(RandomAdd::extended_add<double>(vec[i], second_arg));
    }

    // Вид 2: Цикл через ИТЕРАТОРЫ (указатели-закладки)
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        res_lst.push_back(RandomAdd::extended_add<double>(*it, second_arg));
    }

    // Вид 3: Range-based for (C++11)
    size_t deq_idx = 0;
    for (const auto& elem : deq) {
        res_deq[deq_idx++] = RandomAdd::extended_add<double>(elem, second_arg);
    }

    
    ofstream outFile("table.md");

    if (outFile.is_open()) {
        
        outFile << "| Index | Array | Deque (Res) | Vector | List (Res) | List | Vector (Res) | Deque | Array (Res) |\n";
        outFile << "|-------|-------|-------------|--------|------------|------|--------------|-------|-------------|\n";

        auto it_lst_orig = lst.begin();
        auto it_list_res = res_vec.begin();

        for (size_t i = 0; i < M; ++i) {
            outFile << "| " << i 
                    << " | " << arr[i] 
                    << " | " << res_arr[i]
                    << " | " << vec[i] 
                    << " | " << *it_list_res
                    << " | " << *it_lst_orig 
                    << " | " << res_lst[i]
                    << " | " << deq[i] 
                    << " | " << res_deq[i] 
                    << " |\n";

            ++it_lst_orig;
            ++it_list_res;
        }

        outFile.close();
    }

    return 0;
}