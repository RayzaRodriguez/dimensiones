#include <iostream>
#include <random>
#include <ctime>
#include <ratio>
#include <math.h> 
#include <iomanip>
#include <chrono>

double getEuclideanDistanceFromNData(double min, double max,int numberOfData){
    std::random_device rd;
    double res = 0.0;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(min,max);
    for (size_t i = 0; i < numberOfData; i++)
    {
        double number = dis(gen);
        res+= pow(number,2.0);
    }
    res = sqrt(res);
    std::cout << "Resultado: " << res <<"\n";
    return res;
}

int main(int, char**) {
    std::chrono::time_point<std::chrono::high_resolution_clock>start,end;
    start = std::chrono::high_resolution_clock::now();
    getEuclideanDistanceFromNData(1.0,2.0,25000);
    end = std::chrono::high_resolution_clock::now();

    int64_t duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();
    std::cout<<"Tiempo de ejecucion: "<<duration<<" nanosegundos\n";
}
