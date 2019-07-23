#include "OrderItems.h"
#include<queue>

int *numpiz;
string *pizdest;
int *bakingtime;
int *reachingtime;
int *delivery;

int register_entry[] = { 0,0,0,0,0,0 };


void OrderItems::orderItems() {
	int n, i, j;

	int a = 1;

	while (a == 1) {
		//accepting input
		cout << "Price of each pizza is 100rs\n";
		cout << "Enter number of orders\n";
		cin >> n;
		numpiz = new int[n];
		pizdest = new string[n];
		bakingtime = new int[n];
		reachingtime = new int[n] {0};
		delivery = new int[n];
		for (i = 0; i < n; i++) {
			cout << "Enter number of Pizzas\n";
			cin >> numpiz[i];
			cout << "Enter destination\n";
			cin >> pizdest[i];
		}

		for (i = 0; i < n; i++) {
			bakingtime[i] = numpiz[i] * 5;
		}

		for (i = 0; i < n; i++) {
			if (bakingtime[i] % 10 == 0) { delivery[i] = (bakingtime[i] / 10); }
			else {
				delivery[i] = (bakingtime[i] / 10) + 1;
			}
		}

		for (i = 0; i < n; i++) {
			for (j = 0; j < totaldest; j++) {
				if (pizdest[i] == destination[j]) {
					reachingtime[i] = delivery[i] * 10 + traveltime[j];
					register_entry[j] += 1;
				}
			}
		}

		int count = n; int z = 1;

		//holds destination address
		queue<string> q1, q2, q3;
		//holds respective time arrival duration
		queue<int> s1, s2, s3;
		//holds respective price
		queue<int> r1, r2, r3;

		

		while (count > 0) {

			for (i = 0; i < n; i++) {
				if (delivery[i] == z) {

					if (reachingtime[i] <= 15) {
						q1.push(pizdest[i]);
						s1.push(reachingtime[i]);
						for (j = 0; j < totaldest; j++) {
							if (destination[j] == pizdest[i])break;
						}
						if (register_entry[j] >= 3) {
							r1.push((int)(numpiz[i] * 105 * 0.9));
						}
						else {
							r1.push(numpiz[i] * 105);
						}
					}
					else
						if (reachingtime[i] > 15 && reachingtime[i] <= 30) {
							q2.push(pizdest[i]);
							s2.push(reachingtime[i]);
							for (j = 0; j < totaldest; j++) {
								if (destination[j] == pizdest[i])break;
							}
							if (register_entry[j] >= 3) {
								r1.push((int)(numpiz[i] * 100 * 0.9));
							}
							else {
								r2.push(numpiz[i] * 100);
							}
						}
						else {
							q3.push(pizdest[i]);
							s3.push(reachingtime[i]);
							for (j = 0; j < totaldest; j++) {
								if (destination[j] == pizdest[i])break;
							}
							register_entry[j] -= 1;
							r3.push(0);
						}
				}
			}

			//fstream next;
			//next.open("newregister.csv", ios::app | ios::in | ios::out);

			int cost = 100;
			while (!q1.empty()) {
				string a, b, c; int count = 0;

				

				cout << "Delivery Boy " << z << " delivers to " << q1.front() << " at " << s1.front() << " min" << endl;
				if (count >= 3) {
					cout << "Cost is " << r1.front()*0.9 << endl; r1.pop();
				}
				else {
					cout << "Cost is " << r1.front() << endl; r1.pop();
				}
				q1.pop();
				s1.pop();
				count--;
			}
			while (!q2.empty()) {

				cout << "Delivery Boy " << z << " delivers to " << q2.front() << " at " << s2.front() << " min" << endl;
				cout << "Cost is " << r2.front() << endl; r2.pop();
				q2.pop();
				s2.pop();
				count--;
			}
			while (!q3.empty()) {

				cout << "Delivery Boy " << z << " delivers to " << q3.front() << " at " << s3.front() << " min" << endl;
				cout << "Cost is free\n";
				q3.pop();
				s3.pop();
				count--;
			}

			z++;
			if (z > 5)break;
			
			delete[] numpiz;
			delete[] pizdest;
			delete[] bakingtime;
			delete[] reachingtime;
			delete[] delivery;
		}
		cout << "Enter 1 want to continue\n";
		cin >> a;

	}

	
	
}

OrderItems::OrderItems()
{
}


OrderItems::~OrderItems()
{
}
