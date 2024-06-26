#include "Try.h"
#include <algorithm>
vector<Try> t;
vector<Z> z;

void change(Try& v) {
	
	v.set_b(v.get_b() / v.get_a());
	v.set_c(v.get_c() / v.get_a());
	v.set_a(1);

}
int main() {

	char x;
	ifstream file("file.txt");
	while (file >> x) {
		switch (x) {
		case '1': {
			Try a;
			file >> a;
			t.push_back(a);
			break;
		}
		case '2': {
			Z a;
			file >> a;
			z.push_back(a);
			break;

		}
		}	
	}
	file.close();
		for (const auto& i : t) {
			i.print();
		}
		for_each(t.begin(), t.end(), change);
		for (const auto& i : t) {
			cout << "new zvenyi ";
			i.print();

		}
		for (const auto& i : z) {
			i.print();
		}

		return 0;
}