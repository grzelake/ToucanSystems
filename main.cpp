#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include <algorithm>
using namespace std;
struct Punkt{
	float x;
	float y;
};
struct Prosta {
	float a;
	float b;
};
Prosta liczProsta(Punkt A, Punkt B) {
	float a = (A.y - B.y) / (A.x - B.x);
	float b = A.y - (a*A.x);
	Prosta p = { a, b };
	return p;
}
Punkt liczY(Prosta p, float x) {
	float y = p.a*x + p.b;
	Punkt A = { x, y };
	return A;
}
Punkt wprowadzPunkt() {
	float x, y;
	cout << "Wprowadz x: " << endl;
	cin >> x;
	cout << "Wprowadz y: " << endl;
	cin >> y;
	Punkt p = { x, y };
	return p;
}
int wprowadzN() {
	int n;
	cout << "Wprowadz ilosc kolejnych punktow: " << endl;
	cin >> n;
	return n;
}
vector<float> wprowadzWspX(int n) {
	float x;
	vector<float> v;
	for (int i = 0; i < n; i++) {
		cout << "Wprowadz x: " << endl;
		cin >> x;
		v.push_back(x);
	}
	return v;
}
vector<Punkt> wyznaczPunkty(vector<float> wspX, Punkt A, Punkt B) {
	Prosta P = liczProsta(A, B);
	vector<Punkt> punkty;
	Punkt temp;
	for (int i = 0; i < wspX.size(); i++) {
		temp = liczY(P, wspX[i]);
		punkty.push_back(temp);
	}
	return punkty;
}
void zapiszPunkty(vector<Punkt> v) {
	ofstream file;
	file.open("punkty.csv");
	string a, b;
	for (int i = 0; i < v.size(); i++) {
		a = to_string(v[i].x);
		b = to_string(v[i].y);
		replace(a.begin(), a.end(), '.', ',');
		replace(b.begin(), b.end(), '.', ',');
		file << a << " " << b << "\n";
	}
	file.close();
}
int main() {
	Punkt a = { 2.0, 5.0 };
	Punkt b = { 8.0, 10.0 };
	Prosta P = liczProsta(a, b);
	Punkt C = liczY(P, 4);
	cout << C.y <<endl;
	Punkt A = wprowadzPunkt();
	Punkt B = wprowadzPunkt();
	int n = wprowadzN();
	vector<float> wspX = wprowadzWspX(n);
	vector<Punkt> punkty = wyznaczPunkty(wspX, A, B);
	zapiszPunkty(punkty);
	return 0;
}