#include "baking_machine.h"
#include "Shapes.h"
#include "Ingredients.h"

//finds minimun value
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))


void baking_machine::acceptInput() {

	cout << "Available ingredients :\noil , cream , sugar , floor , cheese , nuts, baking_soda\n";
	cout << "For Biscuit: oil, sugar, floor, nuts is needed\n";
	cout << "For Bread: oil, sugar, floor, baking_soda is needed\n";
	cout << "For Cake: oil, sugar, floor, nuts, cream is needed\n";
	cout << "For Pizza: oil, sugar, floor, cheese is needed\n";
	
	cout << "Enter number of ingredients to be selected\n";
	cin >> n;
	inpData = new string[n];
	inpQuantity = new float[n];
	cout << "Enter available inputs\n";
	for (int i = 0; i < n; i++) {
		cin >> inpData[i];
	}
	cout << "Enter their respective quantity available in kg\n";
	for (int i = 0; i < n; i++) {
		cin >> inpQuantity[i];
	}

	cout << "Enter baking temperature\n";
	cin >> avail_temp;
	cout << "Enter baking time\n";
	cin >> avail_time;

	calculate_shape(inpData);
	checkProducts(inpData, n);

	
}

static int avail[] = { 1,1,1,1,1 };
string* baking_machine::calculate_shape(string *list) {
	int i, pos, j;
	
	Shapes ss;

	for (i = 0; i < 5; i++) {
		if (list[i] == "nuts") {
			for (j = 0; j < 5; j++) {
				if (ss.getshape(j) == "star") {
					pos = j;
					avail[pos] = 0;
				}
			}
		}

		if (list[i] == "baking_soda") {
			for (j = 0; j < 5; j++) {
				if (ss.getshape(j) == "circular" || ss.getshape(j) == "square") {
					pos = j;
					avail[pos] = 0;
				}
			}
		}

		if (list[i] == "cheese") {
			for (j = 0; j < 5; j++) {
				if (ss.getshape(j) == "star" || ss.getshape(j) == "diamond" || ss.getshape(j) == "square") {
					pos = j;
					avail[pos] = 0;
				}
			}
		}




	}

	static string shape_ret[5]; int top = 0;
	for (i = 0; i < 5; i++) {
		if (avail[i]) {
			shape_ret[top] = ss.getshape(i);
			top++;
		}
	}

	return shape_ret;

}

int calorieList[4] = { 0,0,0,0 };
void baking_machine::calculateCalories(string *a, int n, int num) {
	string temp; float sum = 0;
	Ingredients in;
	Biscuit b;
	Bread br;
	Cake c;
	Pizza p;

	for (int i = 0; i < n; i++) {
		temp = a[i];
		for (int j = 0; j < 7; j++) {
			if (temp == in.getitem(j)) {
				sum += in.getcalories(temp);
			}
		}
	}
	calorieList[num] = (int)sum;
	if (num == 0)b.set_calories(sum);
	else if (num == 1)br.set_calories(sum);
	else if (num == 2)c.set_calories(sum);
	else p.set_calories(sum);
}

int selected[] = { 0,0,0,0 };
void baking_machine::checkProducts(string *input, int n) {
	int size = n;
	Biscuit b;
	Bread br;
	Cake c;
	Pizza p;

	int *tickmark; int i, j; string a;

	
	//check if biscuit could be prepared
	tickmark = new int[b.getnum()];
	
	for (i = 0; i < n; i++) {
		a = input[i];
		for (j = 0; j < b.getnum(); j++) {
			if (a == b.get_ingredient(j)) {
				tickmark[j] = 1;
			}
		}
	}
	
	for (i = 0; i < b.getnum(); i++) {
		if (tickmark[i] != 1)break;
	}
	if (i == b.getnum()) {
		
		calculateCalories(b.get_ingredients(),b.getnum(), 0);
		selected[0] = 1;
	}


	//check if bread could be prepared
	tickmark = new int[br.getnum()];
	//tickmark = { 0 };
	for (i = 0; i < n; i++) {
		a = input[i];
		for (j = 0; j < br.getnum(); j++) {
			if (a == br.get_ingredient(j)) {
				tickmark[j] = 1;
			}
		}
	}

	for (i = 0; i < br.getnum(); i++) {
		if (tickmark[i] != 1)break;
	}
	if (i == br.getnum()) {
		//cout << "Bread can be prepared\n";
		calculateCalories(br.get_ingredients(), br.getnum(), 1);
		selected[1] = 1;
	}

	//check if cake could be prepared
	tickmark = new int[c.getnum()]{ 0 };
	//tickmark = { 0 };
	for (i = 0; i < n; i++) {
		a = input[i];
		for (j = 0; j < c.getnum(); j++) {
			if (a == c.get_ingredient(j)) {
				tickmark[j] = 1;
			}
		}
	}

	for (i = 0; i < c.getnum(); i++) {
		if (tickmark[i] != 1)break;
	}
	if (i == c.getnum()) {
		//cout << "cake can be prepared\n";
		calculateCalories(c.get_ingredients(), c.getnum(), 2);
		selected[2] = 1;
	}

	//check if pizza could be prepared
	tickmark = new int[p.getnum()]{0};
	//tickmark = { 0 };
	for (i = 0; i < n; i++) {
		a = input[i];
		for (j = 0; j < p.getnum(); j++) {
			if (a == p.get_ingredient(j)) {
				tickmark[j] = 1;
			}
		}
	}

	for (i = 0; i < p.getnum(); i++) {
		if (tickmark[i] != 1)break;
	}
	if (i == p.getnum()) {
		//cout << "Pizza can be prepared\n";
		calculateCalories(p.get_ingredients(), p.getnum(), 3);
		selected[3] = 1;
	}

	for (i = 0; i < 4; i++) {
		if (selected[i] == 1)break;
	}
	if (i == 4) {
		cout << "None of the products could be prepared\n";
		//exit(0);
	}

	calculate_quantity(inpQuantity);
}

float maximum[] = { 0,0,0,0,0 };
void baking_machine::calculate_quantity(float *inp) {
	int ch,select=0; float mini = 999; float cp = 0; float maxi = 0; float price;
	Shapes ss;
	Biscuit b;
	Bread br;
	Cake c;
	Pizza p;

	for (int i = 0; i < 4; i++) {
		if (selected[i] == 1) { select = i + 1; }
		else { continue; }
		switch (select) {
		case 1: ch = b.getnum(); ch--;
			mini = 999;
			for (int z = 0; z < 5; z++) {
				if (avail[z] == 1) {
					while (ch >= 0) {
						mini = min(mini, (inp[ch] / b.get_quan(ch)));
						cp = cp +
							ch--;
					}
					mini = mini - ss.getwastage(z) * mini;
					cout << ss.getshape(z) << " Biscuit qty= " << round(mini) << endl; price = ((calculate_price(b.get_ingredients(), ss.getshape(z), b.getnum())) / round(mini));
					cout << price << "per biscuit\n";
					b.set_cost(price);
					maxi = max(maxi, (round(mini)*price));
					maximum[z] = (round(mini)*price);
				}
				else {
					continue;
				}

			}
			cout << "Calories is " << calorieList[0] << endl;
			for (int i = 0; i < 5; i++) {
				if (maximum[i] == maxi) {
					cout << ss.getshape(i) << " biscuit to be used for more profit" << endl; break;
				}
			}
			break;
		case 2: ch = br.getnum(); ch--;
			mini = 999;
			for (int z = 0; z < 5; z++) {
				if (avail[z] == 1) {
					while (ch >= 0) {
						mini = min(mini, (inp[ch] / br.get_quan(ch)));
						ch--;
					}
					mini = mini - ss.getwastage(z) * mini;
					cout << ss.getshape(z) << " Bread qty= " << round(mini) << endl; price = ((calculate_price(br.get_ingredients(), ss.getshape(z), br.getnum())) / round(mini));
					cout << price << "per bread\n";
					br.set_cost(price);
					maxi = max(maxi, (round(mini)*price));
					maximum[z] = (round(mini)*price);
				}
				else {
					continue;
				}

			}
			cout << "Calories is " << calorieList[1] << endl;
			for (int i = 0; i < 5; i++) {
				if (maximum[i] == maxi) {
					cout << ss.getshape(i) << " bread to be used for more profit" << endl; break;
				}
			}
			break;
		case 3: ch = c.getnum(); ch--;
			mini = 999;
			for (int z = 0; z < 5; z++) {
				if (avail[z] == 1) {
					while (ch >= 0) {
						mini = min(mini, (inp[ch] / c.get_quan(ch)));
						ch--;
					}
					mini = mini - ss.getwastage(z) * mini;
					cout << ss.getshape(z) << " Cake qty= " << round(mini) << endl; price = ((calculate_price(c.get_ingredients(), ss.getshape(z), c.getnum())) / round(mini));
					cout << price << "per piece\n";
					c.set_cost(price);
					maxi = max(maxi, (round(mini)*price));
					maximum[z] = (round(mini)*price);
				}
				else {
					continue;
				}

			}
			cout << "Calories is " << calorieList[2] << endl;
			for (int i = 0; i < 5; i++) {
				if (maximum[i] == maxi) {
					cout << ss.getshape(i) << " cake to be used for more profit" << endl; break;
				}
			}
			break;
		case 4: ch = p.getnum(); ch--;
			mini = 999;
			for (int z = 0; z < 5; z++) {
				if (avail[z] == 1) {
					while (ch >= 0) {
						mini = min(mini, (inp[ch] / p.get_quan(ch)));
						ch--;
					}
					mini = mini - ss.getwastage(z) * mini;
					cout << ss.getshape(z) << " Pizza qty= " << round(mini) << endl; price = ((calculate_price(p.get_ingredients(), ss.getshape(z), p.getnum())) / round(mini));
					cout << price << "per piece\n";
					p.set_cost(price);
					maxi = max(maxi, (round(mini)*price));
					maximum[z] = (round(mini)*price);
				}
				else {
					continue;
				}

			}
			cout << "Calories is " << calorieList[3] << endl;
			for (int i = 0; i < 5; i++) {
				if (maximum[i] == maxi) {
					cout << ss.getshape(i) << " pizza to be used for more profit" << endl; break;
				}

			}
			break;
		}

	}
}

float baking_machine::calculate_price(string *a, string b, int n) {
	int i, j; float cp = 0;
	Ingredients in;
	Shapes ss;
	for (i = 0; i < n; i++) {
		string temp = a[i];
		for (j = 0; j < 7; j++) {
			if (temp == in.getitem(j)) {
				cp = cp + in.getcost(temp);
			}
		}
	}
	if (b == ss.getshape(0)) {
		cp = cp + ss.getextra(0)*cp;
	}
	else if (b == ss.getshape(1)) {
		cp = cp + ss.getextra(1)*cp;
	}
	else if (b == ss.getshape(2)) {
		cp = cp + ss.getextra(2)*cp;
	}
	else if (b == ss.getshape(3)) {
		cp = cp + ss.getextra(3)*cp;
	}
	else {
		cp = cp + ss.getextra(4)*cp;
	}
	return cp;
}

string* baking_machine::getInput() {
	return this->inpData;
}

int baking_machine::getN() {
	return this->n;
}

float* baking_machine::getQuan() {
	return this->inpQuantity;
}

baking_machine::baking_machine()
{
}


baking_machine::~baking_machine()
{
}
