#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Time{
	int hour;
	int min;
	int sec;
};

void Convert(string& x, Time& xt);

int main() {
	string A, B, C;
	cin >> A >> B >> C;
	Time Raz, At, Bt, Ct;
	Convert(A, At);
	Convert(B, Bt);
	Convert(C, Ct);
	int sA, sC, sB, raz;
	int const  DAY = 24 * 60 * 60;
	sA = At.hour * 60 * 60 + At.min * 60 + At.sec;
	sC = Ct.hour * 60 * 60 + Ct.min * 60 + Ct.sec;
	if (sC >= sA) {
		raz = sC - sA;
		Raz.hour = raz / (60 * 60);
		raz %= (60 * 60);
		Raz.min = raz / 60;
		raz %= 60;
		Raz.sec = raz;
	}
	else {
		raz = DAY - sA + sC;
		Raz.hour = raz / (60 * 60);
		raz %= (60 * 60);
		Raz.min = raz / 60;
		raz %= 60;
		Raz.sec = raz;
	}

	if (Raz.hour % 2 == 1) {
		Raz.hour = Raz.hour / 2;
		Raz.min += 60;
	}
	else Raz.hour /= 2;

	if (Raz.min % 2 == 1) {
		Raz.min = Raz.min / 2;
		Raz.sec += 60;
	}
	else Raz.min /= 2;
	if (Raz.sec % 2 == 1) Raz.sec = Raz.sec / 2 + 1;
	else Raz.sec /= 2;

	sB = Bt.hour * 60 * 60 + Bt.min * 60 + Bt.sec;
	raz = Raz.hour * 60 * 60 + Raz.min * 60 + Raz.sec;
	raz += sB;
	Raz.hour = (raz / (60 * 60)) % 24;
	raz %= (60 * 60);
	Raz.min = raz / 60;
	raz %= 60;
	Raz.sec = raz;
	if (Raz.hour / 10) cout << Raz.hour << ':';
	else cout << '0' << Raz.hour << ':';
	if (Raz.min / 10) cout << Raz.min << ':';
	else cout << '0' << Raz.min << ':';
	if (Raz.sec / 10) cout << Raz.sec;
	else cout << '0' << Raz.sec;
	return 0;
}

void Convert(string &x, Time &xt) {
	xt.hour = ((int)x[0] - 48) * 10 + (int)x[1] - 48;
	xt.min = ((int)x[3] - 48) * 10 + (int)x[4] - 48;
	xt.sec = ((int)x[6] - 48) * 10 + (int)x[7] - 48;
}