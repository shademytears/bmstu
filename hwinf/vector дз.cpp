//============================================================================
// Name        : vector.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	/* 1 задача
    vector<int> numbers;
    for(int i = 1; i <= 10; i++) {
        numbers.push_back(i);
    }
    for(int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << " ";
    }*/
	/* 2 задача
	vector<int> numbers;
	for (int i = 0; i <= 10; i++){
		numbers.push_back(i);
	}
	for (int i = 0; i < numbers.size(); i++){
		cout << numbers[i] << " ";
	}
	cout << endl;
	for_each(numbers.begin(), numbers.end(), [](int &n){
			n = n * 2;
	});
	for (int i = 0; i < numbers.size(); i++){
		cout << numbers [i] << " ";
	}*/
	/* 3 задача
	vector<int> numbers;
	srand(time(0));
	for (int i = 0; i <= 20; i++){
		numbers.push_back(rand() % 100);
	}
	for (int i = 0; i < numbers.size(); i ++){
		cout << numbers[i] << " ";
	}
	cout << endl;
	auto maxi = max_element(numbers.begin(), numbers.end(), [](int a, int b){
		return a < b;
	});
	cout << *maxi;*/

	/*  4задача
	vector<int> numbers;
	srand(time(0));
	for (int i = 0; i < 20; i ++){
		numbers.push_back(rand() % 61-30);
	}
	for (int i = 0; i < numbers.size(); i++){
		cout << numbers[i] << " ";
	}
	cout << endl;
	auto newEnd = remove_if(numbers.begin(), numbers.end(), [](int num) {
	        return num < 0;
	    });
	numbers.erase(newEnd, numbers.end());
	for (int i = 0; i < numbers.size(); i++) {
	     cout << numbers[i] << " ";
	}*/

	/* 5 задача
	vector<int> numbers;
	srand(time(0));
	for (int i = 0; i <= 19; i++){
		numbers.push_back(rand() % 61-30);
	}
	for (int i = 0; i < numbers.size(); i++){
		cout << numbers[i] << " ";
	}
	cout << endl;
	auto minmax = minmax_element(numbers.begin(), numbers.end());
	cout << *minmax.first << endl;
	cout << *minmax.second << endl;
	int sum = accumulate(numbers.begin(), numbers.end(), 0);
	double avg = static_cast<double>(sum) / numbers.size();
	cout << avg << endl;
	vector<int> s = numbers;
	sort(s.begin(), s.end());
	double med;
	if (s.size() % 2 == 0) {
	        int mid1 = s[s.size() / 2 - 1];
	        int mid2 = s[s.size() / 2];
	        med = (mid1 + mid2) / 2.0;
	    } else {
	        med = s[s.size() / 2];
	    }

	    cout << med << endl;
	*/

	/* 6 задача
	srand(time(0));
	vector<int> numbers;
	for(int i = 0; i <= 19; i++){
		numbers.push_back(rand() % 61- 30);
	}
	for(int i = 0; i < numbers.size(); i++){
		cout << numbers[i] << " ";
	}
	cout << endl;
	auto seven = find(numbers.begin(), numbers.end(), 7);
	if (seven != numbers.end()){
		cout << "есть";
	}
	else{
		cout << "нету";
	}
	cout << endl;
	sort(numbers.begin(), numbers.end(), [](int a, int b) {
	    return a > b;
	});
	for(int i = 0; i < numbers.size(); i++){
			cout << numbers[i] << " ";
	}
	cout << endl;
	numbers.erase(unique(numbers.begin(), numbers.end()));
	for(int i = 0; i < numbers.size(); i++){
				cout << numbers[i] << " ";
	}*/
	/* 7 задача
	srand(time(0));
	vector<double> temp;
	for(int i = 0; i < 15; i++){
		double tempp = (rand() % 121 - 60) + (rand() % 100) / 100.0;
		temp.push_back(tempp);
	}
	for(int i = 0; i < temp.size(); i++){
		cout << temp[i] << " ";
	}
	cout << endl;
	temp.erase(remove_if(temp.begin(), temp.end(), [](double a) {
	    return a < -50.0 || a > 50.0;  // Условие для удаления
	            }),
	        temp.end()
	    );
	for(int i = 0; i < temp.size(); i++){
		cout << temp[i] << " ";
	}
	cout << endl;
	auto minmax = minmax_element(temp.begin(), temp.end());
	cout << *minmax.first << endl;
	cout << *minmax.second << endl;
	int sum = accumulate(temp.begin(), temp.end(), 0);
		double avg = static_cast<double>(sum) / temp.size();
		cout << avg << endl;
	bool b = all_of(temp.begin(), temp.end(), [](double a){
		return a > -10.0;
	});
	if (b){
		cout << "da";
	}
	else{
		cout << "net";
	}*/
	/* 8 задача
	srand(time(0));
	    vector<int> s;
	    for (int i = 0; i < 50; i++) {
	        int speed = rand() % 181;
	        s.push_back(speed);
	        if (i < 10) {
	            cout << speed << " ";
	        }
	    }
	    cout << endl;

	    vector<int> overspeeding;
	    copy_if(s.begin(), s.end(), back_inserter(overspeeding),
	        [](int speed) {
	            return speed > 120;
	        });
	    for (int speed : overspeeding) {
	        cout << speed << " ";
	    }
	    cout << endl;
	    cout << overspeeding.size();
	    cout << endl;
	    double average_speed = accumulate(s.begin(), s.end(), 0.0) / s.size();
	    cout << average_speed << endl;
	    bool always_moving = all_of(s.begin(), s.end(),
	        [](int speed) {
	            return speed > 0;
	        });

	    if (always_moving) {
	        cout << "> 0" << endl;
	    } else {
	        vector<int> zero_speeds;
	        copy_if(s.begin(), s.end(), back_inserter(zero_speeds),
	            [](int speed) {
	                return speed == 0;
	            });

	        cout << "останавливался " << zero_speeds.size();
	        cout << endl;
	        for (int speed : zero_speeds) {
	            cout << speed << " ";
	        }
	        cout << endl;
	    }
	    cout << endl;

	    vector<int> sorted = s;
	    sort(sorted.begin(), sorted.end(),
	        [](int a, int b) {
	            return a > b;
	        });
	    for (int i = 0; i < min(10, (int)sorted.size()); i++) {
	        cout << sorted[i] << " ";
	    }
	    cout << endl << endl;
	    auto minmax_speed = minmax_element(s.begin(), s.end());
	    cout << *minmax_speed.first << " км/ч" << endl;
	    cout << *minmax_speed.second << " км/ч" << endl;

	    int low_speed = count_if(s.begin(), s.end(), [](int a) { return a <= 60; });
	    int medium_speed = count_if(s.begin(), s.end(), [](int a) { return a > 60 && a <= 120; });
	    int high_speed = count_if(s.begin(), s.end(), [](int a) { return a > 120; });
	    cout << "(0-60 км/ч): " << low_speed << endl;
	    cout << "(61-120 км/ч): " << medium_speed << endl;
	    cout << "(>120 км/ч): " << high_speed << endl;
	    */
	/* 9 задача
	srand(time(0));

	    vector<double> p;
	    for (int i = 0; i < 20; i++) {
	        double power = (rand() % 120) - 10.0 + (rand() % 100) / 100.0;
	        p.push_back(power);
	        cout << power << " ";
	    }
	    cout << endl << endl;

	    p.erase(
	        remove_if(p.begin(), p.end(),
	            [](double power) {
	                return power < 0;
	            }),
	        p.end()
	    );
	    for (double power : p) {
	        cout << power << " ";
	    }
	    cout << endl;
	    cout << p.size();
	    cout << endl;

	    if (!p.empty()) {
	        auto minmax_power = minmax_element(p.begin(), p.end());
	        cout << *minmax_power.first << endl;
	        cout << *minmax_power.second << endl;

	        double average_power = accumulate(p.begin(), p.end(), 0.0) / p.size();
	        cout << average_power << " кВт" << endl << endl;
	    }

	    bool within_limits = all_of(p.begin(), p.end(), [](double pw) {
	        return pw >= 10.0 && pw <= 90.0;
	        });

	    if (within_limits) {
	        cout << "10-90" << endl;
	    } else {
	        vector<double> out_of_range;
	        copy_if(p.begin(), p.end(), back_inserter(out_of_range),
	            [](double power) {
	                return power < 10.0 || power > 90.0;
	            });
	        for (double power : out_of_range) {
	            cout << power << " ";
	        }
	        cout << endl;
	    }
	    cout << endl;

	    vector<double> sorted_power = p;
	    sort(sorted_power.begin(), sorted_power.end());
	    for (double power : sorted_power) {
	        cout << power << " ";
	    }
	    cout << endl;

	    double median;
	    if (sorted_power.size() % 2 == 0) {
	        median = (sorted_power[sorted_power.size() / 2 - 1] + sorted_power[sorted_power.size() / 2]) / 2.0;
	    } else {
	        median = sorted_power[sorted_power.size() / 2];
	    }

	    cout << median << endl;*/
	/* 10 задача
	srand(time(0));

	    vector<double> e;
	    for (int i = 0; i < 30; i++) {
	        double consumption = (rand() % 201 + 50) + (rand() % 100) / 100.0;
	        e.push_back(consumption);
	        cout << consumption << " ";
	    }
	    cout << endl << endl;

	    double total_consumption = accumulate(e.begin(), e.end(), 0.0);
	    cout << total_consumption << endl;

	    double average_daily = total_consumption / e.size();
	    cout << average_daily << endl;

	    auto minmax_days = minmax_element(e.begin(), e.end());
	    int min_day = distance(e.begin(), minmax_days.first);
	    int max_day = distance(e.begin(), minmax_days.second);

	    cout << *minmax_days.first << min_day + 1 << endl;
	    cout << *minmax_days.second << max_day + 1 << endl << endl;

	    double peak_threshold = average_daily * 1.2;
	    vector<double> peak_days;
	    copy_if(e.begin(), e.end(), back_inserter(peak_days),
	        [peak_threshold](double consumption) {
	            return consumption > peak_threshold;
	        });

	    cout << peak_threshold << endl;
	    for (double consumption : peak_days) {
	        cout << consumption << " ";
	    }
	    cout << endl;
	    cout << peak_days.size();*/

	/* 11 задача
	srand(time(0));

	    vector<double> a;
	    for (int i = 0; i < 50; i++) {
	        double amplitude = (rand() % 100) / 10.0;
	        a.push_back(amplitude);
	        cout << amplitude << " ";
	    }
	    cout << endl << endl;

	    a.erase(
	        remove_if(a.begin(), a.end(),
	            [](double amp) {
	                return amp < 0.1;
	            }),
	        a.end()
	    );
	    for (double amp : a) {
	        cout << amp << " ";
	    }
	    cout << endl;
	    cout << a.size();
	    cout << endl;

	    if (!a.empty()) {
	        double average_amplitude = accumulate(a.begin(), a.end(), 0.0) / a.size();
	        cout << "Средняя амплитуда: " << average_amplitude << endl;

	        auto max_amplitude = max_element(a.begin(), a.end());
	        cout << *max_amplitude << endl << endl;
	    }

	    bool all_above_threshold = all_of(a.begin(), a.end(),
	        [](double amp) {
	            return amp > 0.5;
	        });

	    if (all_above_threshold) {
	        cout << "превышают" << endl;
	    } else {
	        vector<double> below_threshold;
	        copy_if(a.begin(), a.end(), back_inserter(below_threshold),
	            [](double amp) {
	                return amp <= 0.5;
	            });
	        for (double amp : below_threshold) {
	            cout << amp << " ";
	        }
	        cout << endl;
	    }
	    cout << endl;

	    vector<double> sorted_a = a;
	    sort(sorted_a.begin(), sorted_a.end(),
	        [](double x, double y) {
	            return x > y;
	        });
	    for (int i = 0; i < min(10, (int)sorted_a.size()); i++) {
	        cout << sorted_a[i] << " ";
	    }*/
	/* 12 задача
	srand(time(0));

	    vector<double> f;
	    for (int i = 0; i < 50; i++) {
	        double fuel = (rand() % 100) + (rand() % 100) / 100.0;
	        f.push_back(fuel);
	        cout << fuel << " ";
	    }
	    cout << endl << endl;

	    auto min_fuel = min_element(f.begin(), f.end());
	    cout << *min_fuel << "%" << endl << endl;

	    auto max_fuel = max_element(f.begin(), f.end());
	    double critical_level = *max_fuel * 0.05;
	    bool never_below_critical = all_of(f.begin(), f.end(),
	        [critical_level](double fuel) {
	            return fuel >= critical_level;
	        });

	    if (never_below_critical) {
	        cout << "не падал" << endl;
	    } else {
	        vector<double> critical_values;
	        copy_if(f.begin(), f.end(), back_inserter(critical_values),
	            [critical_level](double fuel) {
	                return fuel < critical_level;
	            });
	        cout << critical_level;
	        for (double fuel : critical_values) {
	            cout << fuel << " ";
	        }
	        cout << endl;
	    }
	    cout << endl;

	    double c = f.front() - f.back();
	    cout << c << endl << endl;

	    vector<double> sorted_f = f;
	    sort(sorted_f.begin(), sorted_f.end());

	    double median;
	    if (sorted_f.size() % 2 == 0) {
	        median = (sorted_f[sorted_f.size() / 2 - 1] + sorted_f[sorted_f.size() / 2]) / 2.0;
	    } else {
	        median = sorted_f[sorted_f.size() / 2];
	    }
	    cout << median << endl;
	    */
	/* 13 задача
	srand(time(0));

	    vector<double> p;
	    for (int i = 0; i < 50; i++) {
	        double pressure = (rand() % 100) / 10.0 + 1.0;
	        p.push_back(pressure);
	        cout << pressure << " ";
	    }
	    cout << endl << endl;

	    p.erase(
	        remove_if(p.begin(), p.end(),
	            [](double pressure) {
	                return pressure < 0 || pressure > 12;
	            }),
	        p.end()
	    );
	    for (double pressure : p) {
	        cout << pressure << " ";
	    }
	    cout << endl;
	    cout << p.size();
	    cout << endl;

	    if (!p.empty()) {
	        double average_pressure = accumulate(p.begin(), p.end(), 0.0) / p.size();
	        cout << average_pressure << endl;

	        auto minmax_pressure = minmax_element(p.begin(), p.end());
	        cout << *minmax_pressure.first << endl;
	        cout << *minmax_pressure.second << endl << endl;
	    }
	    for_each(p.begin(), p.end(),
	        [](double pressure) {
	            if (pressure > 8.0) {
	                cout << pressure << " ";
	            }
	        });*/
	/* 14 задача
	srand(time(0));

	    vector<double> c;
	    for (int i = 0; i < 24; i++) {
	        double consumption = rand() % 401 + 100;
	        c.push_back(consumption);
	        cout << consumption << " ";
	    }
	    cout << endl << endl;

	    double total_consumption = accumulate(c.begin(), c.end(), 0.0);
	    double average_consumption = total_consumption / c.size();
	    cout << total_consumption << endl;
	    cout << average_consumption;
	    cout << endl;

	    auto peak_hour = max_element(c.begin(), c.end());
	    int peak_hour_index = distance(c.begin(), peak_hour);
	    cout << *peak_hour << peak_hour_index << endl << endl;

	    vector<double> deviations;
	    transform(c.begin(), c.end(), back_inserter(deviations),
	        [average_consumption](double consumption) {
	            return consumption - average_consumption;
	        });
	    for (double dev : deviations) {
	        cout << dev << " ";
	    }
	    cout << endl;

	    vector<double> sorted_c = c;
	    sort(sorted_c.begin(), sorted_c.end());
	    for (int i = 0; i < min(5, (int)sorted_c.size()); i++) {
	        cout << sorted_c[i] << " ";
	    }*/
	srand(time(0));

	    vector<vector<double>> temp(5, vector<double>(30));
	    vector<vector<double>> pressure(5, vector<double>(100));

	    for (int i = 0; i < 5; i++) {
	        for (int j = 0; j < 30; j++) {
	            temp[i][j] = (rand() % 500) / 10.0;
	        }
	        for (int j = 0; j < 100; j++) {
	            pressure[i][j] = (rand() % 1000) / 10.0 + 1.0;
	        }
	    }

	    vector<double> avg_temp(5);
	    transform(temp.begin(), temp.end(), avg_temp.begin(),
	        [](const vector<double>& channel) {
	            return accumulate(channel.begin(), channel.end(), 0.0) / channel.size();
	        });
	    for (double t : avg_temp) {
	        cout << t << " ";
	    }
	    cout << endl << endl;

	    vector<pair<double, double>> minmax_pressure(5);
	    transform(pressure.begin(), pressure.end(), minmax_pressure.begin(),
	        [](const vector<double>& channel) {
	            auto mm = minmax_element(channel.begin(), channel.end());
	            return make_pair(*mm.first, *mm.second);
	        });

	    for (int i = 0; i < 5; i++) {
	        cout << "канал " << i << ": min=" << minmax_pressure[i].first << " max=" << minmax_pressure[i].second << endl;
	    }
	    cout << endl;

	    vector<vector<double>> temp_diff(5, vector<double>(29));
	    for (int i = 0; i < 5; i++) {
	        transform(temp[i].begin(), temp[i].end() - 1, temp[i].begin() + 1, temp_diff[i].begin(),
	            [](double a, double b) {
	                return b - a;
	            });
	    }

	    vector<double> temp_variation(5);
	    transform(temp.begin(), temp.end(), temp_variation.begin(),
	        [](const vector<double>& channel) {
	            auto mm = minmax_element(channel.begin(), channel.end());
	            return *mm.second - *mm.first;
	        });

	    auto max_var_channel = max_element(temp_variation.begin(), temp_variation.end());
	    int max_var_index = distance(temp_variation.begin(), max_var_channel);
	    cout << max_var_index << *max_var_channel << endl;

	    vector<vector<double>> normalized_pressure(5, vector<double>(100));
	    for (int i = 0; i < 5; i++) {
	        double min_p = minmax_pressure[i].first;
	        double max_p = minmax_pressure[i].second;
	        transform(pressure[i].begin(), pressure[i].end(), normalized_pressure[i].begin(),
	            [min_p, max_p](double p) {
	                return (p - min_p) / (max_p - min_p);
	            });
	    }
	    for_each(normalized_pressure.begin(), normalized_pressure.end(),
	        [](const vector<double>& channel) {
	            for_each(channel.begin(), channel.end(),
	                [](double p) {
	                    if (p > 0.9) {
	                        cout << p << " ";
	                    }
	                });
	        });
	    cout << endl << endl;

	    vector<size_t> indices(5);
	    iota(indices.begin(), indices.end(), 0);
	    sort(indices.begin(), indices.end(),
	        [&avg_temp](size_t i, size_t j) {
	            return avg_temp[i] > avg_temp[j];
	        });

	    cout << indices[0] << avg_temp[indices[0]];


	return 0;
}
