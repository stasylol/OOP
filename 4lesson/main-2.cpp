#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <iterator>

std::vector<int> readVectorFromFile(const std::string& filename) {
    std::vector<int> vec;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл: " << filename << '\n';
        return vec;
    }

    std::string line;
    while (std::getline(file, line)) {
       
        for (char& c : line) {
            if (c == ',') {
                c = ' ';
            }
        }

        std::stringstream ss(line);
        int value;
        while (ss >> value) {
            vec.push_back(value);
        }
    }

    return vec;
}





// std::map<int, int> countFrequenciesFor(const std::vector<int>& vec) {
//     std::map<int, int> freq;
//     int x = 0;
//     for (int x: vec) {
//         std::map<int, int>::iterator it = freq.find(x);
//         if (it == freq.end()) {
//             freq[x] = 0; 
//         }
//         freq[x]++;
//     }
//     return freq;
// }

std::map<int, int> countFrequenciesFor(const std::vector<int>& vec) {
    std::map<int, int> freq;

    for (int x : vec) {
        std::map<int, int>::iterator it = freq.find(x);

        if (it == freq.end()) {
            freq.insert(std::make_pair(x, 1));
        } else {
            it->second++;
        }
    }

    return freq;
}

std::map<int, int> countFrequenciesFor(const std::vector<int>& vec) {
    std::map<int, int> freq;

    for (int x : vec) {
        if (freq.find(x) == freq.end()) {
            freq.insert(std::make_pair(x, 1));
        } else {
            freq.at(x)++;
        }
    }

    return freq;
}


// std::map<int, int> countFrequenciesAlgorithm(const std::vector<int>& vec) {
//     std::map<int, int> freq;
//     std::for_each(vec.begin(), vec.end(), [&freq](int x) {

//         freq[x]++;
//     });
//     return freq;
// }

std::map<int, int> countFrequenciesAlgorithm(const std::vector<int>& vec) {
    std::map<int, int> freq;

    std::for_each(vec.begin(), vec.end(), [&freq](int x) {
        std::map<int, int>::iterator it = freq.find(x);

        if (it == freq.end()) {
            freq.insert(std::make_pair(x, 1));
        } else {
            it->second++;
        }
    });

    return freq;
}

void printFrequencies(const std::map<int, int>& freq) {
    for (const std::pair<const int, int>& entry : freq) {
        std::cout << entry.first << " встречается " << entry.second << " раз(а)\n";
    }
}


int sumFirstTen(const std::vector<int>& vec) {
    std::size_t n = std::min<std::size_t>(10, vec.size());
    return std::accumulate(vec.begin(), vec.begin() + n, 0);
}

int main() {

    int wer;
    std::cout << "вывод" << wer << "\n";
   
    std::string file1 = "s04_v1_42_1.txt";
    std::string file2 = "s04_v1_42_2.txt";

    std::vector<int> vecA = readVectorFromFile(file1);
    std::vector<int> vecB = readVectorFromFile(file2);

    if (vecA.empty() || vecB.empty()) {
        std::cerr << "Ошибка: один из файлов не прочитан или не содержит чисел.\n"
                  << "Проверь, что оба txt-файла лежат в рабочей папке программы.\n";
        return 1;
    }

    std::vector<int>& first = (vecA.size() >= vecB.size()) ? vecA : vecB;
    std::vector<int>& second = (vecA.size() >= vecB.size()) ? vecB : vecA;

    std::cout << "Количество элементов в первом (большем) векторе: "
              << first.size() << '\n';
    std::cout << "Количество элементов во втором (меньшем) векторе: "
              << second.size() << "\n\n";

   
    std::map<int, int> freqFirstFor = countFrequenciesFor(first);
    std::map<int, int> freqFirstAlg = countFrequenciesAlgorithm(first);
    std::map<int, int> freqSecondFor = countFrequenciesFor(second);
    std::map<int, int> freqSecondAlg = countFrequenciesAlgorithm(second);

    std::cout << "Частоты первого вектора (обычный for):\n";
    printFrequencies(freqFirstFor);
    std::cout << "\nЧастоты первого вектора (for_each):\n";
    printFrequencies(freqFirstAlg);
    std::cout << "\nЧастоты второго вектора (обычный for):\n";
    printFrequencies(freqSecondFor);
    std::cout << "\nЧастоты второго вектора (for_each):\n";
    printFrequencies(freqSecondAlg);

  
    int sumFirst1 = std::accumulate(first.begin(), first.end(), 0);
    int sumSecond1 = std::accumulate(second.begin(), second.end(), 0);

    int sumFirst2 = 0;
    std::for_each(first.begin(), first.end(), [&sumFirst2](int x) {
        sumFirst2 += x;
    });

    int sumSecond2 = 0;
    std::for_each(second.begin(), second.end(), [&sumSecond2](int x) {
        sumSecond2 += x;
    });

    std::cout << "\nСумма первого вектора: " << sumFirst1
              << " (accumulate), " << sumFirst2 << " (for_each)\n";
    std::cout << "Сумма второго вектора: " << sumSecond1
              << " (accumulate), " << sumSecond2 << " (for_each)\n";

    
    std::cout << "Сумма первых 10 элементов первого вектора: "
              << sumFirstTen(first) << '\n';
    std::cout << "Сумма первых 10 элементов второго вектора: "
              << sumFirstTen(second) << "\n\n";

    
    int resultFirstBinOp = std::accumulate(
        first.begin(), first.end(), 0,
        [](int acc, int x) {
            if (x % 2 == 0) {
                return acc + x;
            } else {
                return acc - x;
            }
        });

    int resultSecondBinOp = std::accumulate(
        second.begin(), second.end(), 0,
        [](int acc, int x) {
            if (x % 2 == 0) {
                return acc + x;
            } else {
                return acc - x;
                
            }
        });

    std::cout << "Результат бинарной операции для первого вектора: " << resultFirstBinOp << '\n';
    std::cout << "Результат бинарной операции для второго вектора: " << resultSecondBinOp << "\n\n";

   
    std::set<int> secondDuplicates;
    for (const std::pair<const int, int>& entry : freqSecondFor) {
        if (entry.second >= 2) {
            secondDuplicates.insert(entry.first);
        }
    }

    
    std::set<int> firstFrequent;
    for (const std::pair<const int, int>& entry : freqFirstFor) {
        if (entry.second > 3) {
            firstFrequent.insert(entry.first);
        }
    }

    std::cout << "Числа, которые во втором векторе встречаются 2 раза и более: ";
    for (int value : secondDuplicates) {
        std::cout << value << ' ';
    }

    std::cout << "\nЧисла, которые в первом векторе встречаются больше 3 раз: ";
    for (int value : firstFrequent) {
        std::cout << value << ' ';
    }
    std::cout << "\n\n";

   
    std::vector<int> result;
    std::set_intersection(
        secondDuplicates.begin(), secondDuplicates.end(),
        firstFrequent.begin(), firstFrequent.end(),
        std::back_inserter(result));

    std::cout << "Подходящие числа и количество их повторений (обычные циклы):\n";
    for (int value : result) {
        int countInFirst = 0;
        int countInSecond = 0;

        for (int x : first) {
            if (x == value) {
                countInFirst++;
            }
        }
        for (int x : second) {
            if (x == value) {
                countInSecond++;
            }
        }

        std::cout << value << ": в первом " << countInFirst
                  << ", во втором " << countInSecond << '\n';
    }

    

    std::cout << "\nПодходящие числа и количество их повторений (count_if):\n";
    for (int value : result) {
        int countInFirst = static_cast<int>(std::count_if(
            first.begin(), first.end(), [value](int x) {
                return x == value;
            }));

        int countInSecond = static_cast<int>(std::count_if(
            second.begin(), second.end(), [value](int x) {
                return x == value;
            }));

        std::cout << value << ": в первом " << countInFirst
                  << ", во втором " << countInSecond << '\n';
    }

    return 0;
}
