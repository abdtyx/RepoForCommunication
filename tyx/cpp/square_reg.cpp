#include <bits/stdc++.h>

using namespace std;

class vet {
    public:
        double v[3];
        vet(double a, double b, double c) {
            v[0] = a;
            v[1] = b;
            v[2] = c;
        }
        double operator[](int index) {
            return v[index];
        }
        vet() {
            v[0] = 0;
            v[1] = 0;
            v[2] = 0;
        }
        vet operator+(double x) {
            vet b = *this;
            b.v[0] += x;
            b.v[1] += x;
            b.v[2] += x;
            return b;
        }
        // vet operator/(double x) {
        //     vet b = *this;
        //     b.v[0] /= x;
        //     b.v[1] /= x;
        //     b.v[2] /= x;
        //     return b;
        // }
        // friend vet& operator+(vet& a, vet& b);
        double Mod() {
            return sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
        }
};

// vet& operator+(vet& a, vet& b) {
//     vet c(a.v[0] + b.v[0], a.v[1] + b.v[1], a.v[2] + b.v[2]);
//     return c;
// }

// double w[3] = {1.0, 1.0, -1.0};

vet djf(vector<pair<pair<double, double>, int> > dt, vet w);
double jf(vector<pair<pair<double, double>, int> > dt, vet w);
double thetatx(pair<double, double> x, vet w);

int main() {
    pair<double, double> data[13] = {{0.9, 5.0}, {1.0, 1.0}, {1.0, 4.9}, {1.1, 5.1}, {1.2, 5.1}, {1.3, 3.9},/**/ {1.9, 4.0}, {1.9, 1.2}, {2.0, 3.0}, {2.05, 1.0}, {2.1, 1.3}, {2.2, 1.3}, {2.15, 2.9}};
    vector<pair<pair<double, double>, int> > dt;
    vet w(0.0, 1.0, -1.0);
    for (int i = 0; i < 13; i++) {
        if (i <= 5) {
            dt.push_back(make_pair(data[i], 1));
        }
        else {
            dt.push_back(make_pair(data[i], -1));
        }
    }

    for (int i = 0; i < 100; i++) {
        // for (int j = 0; j < 13; j++) {
        //     cout << jf(dt);
        // }
        cout << jf(dt, w) << " | ";
        vet grad = djf(dt, w);
        cout << grad.Mod() << endl;
        // w = w + (grad / 1000.0);
        w.v[0] -= grad.v[0] / 10000.0;
        w.v[1] -= grad.v[1] / 10000.0;
        w.v[2] -= grad.v[2] / 10000.0;
    }
    cout << w.v[0] << " | " << w.v[1] << " | " << w.v[2];
    return 0;
}

vet djf(vector<pair<pair<double, double>, int> > dt, vet w) {
    vet r;
    int sum = 0;
    for (int j = 0; j < 3; j++) {
        sum = 0;
        for (int i = 0; i < 13; i++) {
            double tmp = log(1 + exp(-(double)dt[i].second * thetatx(dt[i].first, w + 0.01))) - log(1 + exp(-(double)dt[i].second * thetatx(dt[i].first, w)));
            sum += tmp / 0.01;
        }
        r.v[j] = sum;
    }
    return r;
}

double jf(vector<pair<pair<double, double>, int> > dt, vet w) {
    double sum = 0;
    for (int i = 0; i < 13; i++) {
        sum += log(1 + exp(-(double)dt[i].second * thetatx(dt[i].first, w)));
    }
    return sum;
}

double thetatx(pair<double, double> x, vet w) {
    return w[0] + w[1] * x.first + w[2] * x.second;
}

double h(double x) {
    return 1 / (1 + exp(-x));
}