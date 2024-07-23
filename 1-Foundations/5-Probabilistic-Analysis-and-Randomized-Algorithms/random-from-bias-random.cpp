#include <bits/stdc++.h>

void randomFromBiasRandom(std::vector<int>& Total, std::vector<int>& items, std::vector<double>& weights) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
   
    int i = 0;
    while (i < 100) {
        int a = items[std::rand() % items.size()];
        int b = items[std::rand() % items.size()];
       
        if (a < b) {
            Total.push_back(0);
            i++;
        } else if (a > b) {
            Total.push_back(1);
            i++;
        }
    }
}

int main() {
    std::vector<int> Total;
    std::vector<int> items = {0, 1};
    std::vector<double> weights = {0.2, 0.8};
   
    randomFromBiasRandom(Total, items, weights);
   
    int sum = 0;
   
    std::cout << "Result List : ";
    for (int result : Total) {
        std::cout << result << " ";
        sum += result;
    }
    std::cout << std::endl;
   
    double avg = static_cast<double>(sum) / Total.size();
   
    std::cout << "Average : " << avg << std::endl;
   
    return 0;
}
