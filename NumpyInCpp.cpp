#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm> 
#include <cmath>    

using namespace std;

class Temperature {
private:
    string filename;
    vector<int> days;
    vector<int> temperatures;

public:
    Temperature(string file) : filename(file) {}

    void readData() {
        ifstream fin(filename);

        if (!fin) {
            cerr << "Error opening file!" << endl;
            return;
        }

        string line;
        getline(fin, line); // Skip header
        while (getline(fin, line)) {
            stringstream ss(line);
            string day, temperature;

            getline(ss, day, ',');
            getline(ss, temperature, ',');

            days.push_back(stoi(day));
            temperatures.push_back(stoi(temperature));
        }

        fin.close();
    }

    void printData() {
        cout << "Day\tTemperature" << endl;
        for (size_t i = 0; i < days.size(); ++i) {
            cout << days[i] << "\t" << temperatures[i] << endl;
        }
    }

    void temperatureMean() {
        int temperatures_sum = 0;
        int temperatures_Size = temperatures.size();
        for (size_t i = 0; i < temperatures_Size; i++) {
            temperatures_sum += temperatures[i];
        }
        double Mean = static_cast<double>(temperatures_sum) / temperatures_Size;
        cout << "Temperatures Mean: " << Mean << endl;
    }

    void temperatureMedian() {
        vector<int> sortedTemps = temperatures;
        sort(sortedTemps.begin(), sortedTemps.end());

        size_t n = sortedTemps.size();
        double median;

        if (n % 2 == 0) {
            median = (sortedTemps[n / 2 - 1] + sortedTemps[n / 2]) / 2.0;
        } else {
            median = sortedTemps[n / 2];
        }

        cout << "Temperatures Median: " << median << endl;
    }

    void temperatureVarianceAndStdDev() {
        int n = temperatures.size();
        double mean = 0.0, variance = 0.0, stdDev = 0.0;

        for (int temp : temperatures) {
            mean += temp;
        }
        mean /= n;

        for (int temp : temperatures) {
            variance += (temp - mean) * (temp - mean);
        }
        variance /= n;

        stdDev = sqrt(variance);

        cout << "Temperatures Variance: " << variance << endl;
        cout << "Temperatures Standard Deviation: " << stdDev << endl;
    }
};

int main() {
    Temperature temp("temperature.csv");

    temp.readData();
    temp.printData();

    temp.temperatureMean();                 
    temp.temperatureMedian();               
    temp.temperatureVarianceAndStdDev();    

    return 0;
}
