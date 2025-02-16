#include <iostream>
#include <string> 
#include <fstream>

using namespace std;

struct hourly_data {
    string time;
    int power;
    int no_of_miners;
};

struct calculation_data
{
    int n;
    hourly_data array_of_hours[9000];
};

void tokenize(string s, string del, string ret[6])
{
    int start, end = -1 * del.size();
    int i = 0;
    do {
        start = end + del.size();
        end = s.find(del, start);
        ret[i++] = s.substr(start, end - start);
    } while (end != -1);
}

hourly_data new_data(string separated_data[6]) {
    hourly_data hd;

    hd.time = separated_data[0];
    hd.power = floor(stod(separated_data[1]));

    return hd;
}

int readFile(string file_path, hourly_data data[9000]) {
    //iterator
    int i = 0;

    // Open the text file named "input.txt"
    ifstream f(file_path);

    // Check if the file is successfully opened
    if (!f.is_open()) {
        cerr << "Error opening the file!";
    }

    // String variable to store the read data
    string s;

    //array for separated elements of each line
    string ret[6];

    // Read each line of the file and print it to the
    // standard output stream till the whole file is
    // completely read
    while (getline(f, s)) {
        tokenize(s, ",", ret);
        data[i] = new_data(ret);
        i++;
    }


    // Close the file
    f.close();

    return i;
}

void number_of_miners_each_hour(calculation_data podaci, int miner_power) {
    for (int i = 0; i < podaci.n; i++) {
        podaci.array_of_hours[i].no_of_miners = podaci.array_of_hours[i].power / miner_power;
    }
}

int main()
{
    
    calculation_data podaci;

    string input_file_path = "hourly_data.txt";
    podaci.n = readFile(input_file_path, podaci.array_of_hours);

    cout << "br clanova: " << podaci.n << endl;

    number_of_miners_each_hour(podaci, 3);

    for (int i = 0; i < podaci.n; i++) {
        cout << podaci.array_of_hours[i].time << ", " << podaci.array_of_hours[i].power << podaci.array_of_hours[i].no_of_miners << endl;
    }


    /*string ret[6];
    tokenize("20050101:0010,0.0,0.0,0.3,1.03,0.0", ",", ret);

    for (int i = 0; i < 6; i++) {
        cout << ret[i] << endl;
    }
    */
    return 0;
}
