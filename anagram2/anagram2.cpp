#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool czy_rowne_dlugosci(string a[]) {

	for (int k = 1; k < 5; ++k) {
		if (a[k - 1].size() != a[k].size())
			return false;
	}
	return true;
}

void swap(char& x, char& y) {
	char tmp = x;
	x = y;
	y = tmp;
}

void sortuj(string& a) {
	int dlugosc = a.size();
	for (int i = 1; i < dlugosc; ++i) {
		for (int k = i; k > 0 && a[k] < a[k - 1]; --k) {
			swap(a[k], a[k - 1]);
		}
	}
}

bool czy_anagram(string a[]) {

	string kopia[5];
	for (int k = 0; k < 5; ++k) {
		kopia[k] = a[k];
	}
	for (int k = 0; k < 5; ++k) {
		sortuj(kopia[k]);
	}
	for (int k = 1; k < 5; ++k) {
		if (kopia[k - 1] != kopia[k])
			return false;
	}
	return true;
}

int main() {
	ifstream dane;
	ofstream odpowiedza, odpowiedzb;
	string wyrazy[5];

	dane.open("anagram.txt");
	odpowiedza.open("odp_4a.txt");
	odpowiedzb.open("odp_4b.txt");
	for (int i = 0; i < 200; ++i) {
		for (int k = 0; k < 5; ++k) {
			dane >> wyrazy[k];
		}
		if (!czy_rowne_dlugosci(wyrazy))
			continue;
		for (int k = 0; k < 5; ++k) {
			odpowiedza << wyrazy[k] << " ";
		}
		odpowiedza << endl;
		if (czy_anagram(wyrazy)) {
			for (int k = 0; k < 5; ++k) {
				odpowiedzb << wyrazy[k] << " ";
			}
			odpowiedzb << endl;
		}
	}

	odpowiedza.close();
	odpowiedzb.close();
	dane.close();

	return 0;
}
