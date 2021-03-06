#include <iostream>
#include <string.h>
#include <cmath>

union contribution {
	long long int depositI;
	double depositD;
};

struct note {
	size_t id;
	contribution deposit;			
	char name[15];
	char category[5];
	char date[11];
	bool isDepositDouble;
};

std::ostream& operator << (std::ostream &out, const struct note memo) {
	out << memo.date << " " << memo.id << " " << memo.name << " " << memo.category << " ";
	if (memo.isDepositDouble) {
		out << memo.deposit.depositD;
	} else {
		out << memo.deposit.depositI;
	}

  return out;
}

int main(int argc, char *argv[]) {
	char file_name[30] = "";
  if (argc == 1) {
  	std::cout << "Enter file name: ";
    std::cin >> file_name;
  } else {
    strcat(file_name, argv[1]);
  }

	char names[][30] = {"alex", "mikle", "alexey", "danil", "kirill", "artem"};
	char categories[][5] = {"fast", "slow"};

	srand(time(0));
	note tmp;
	size_t times;

	std::cout << "Enter count of notes: ";
  std::cin >> times;

	FILE* f = fopen(file_name, "wb");
	for (size_t i = 0; i < times; i++) {
		tmp.id = 100000 + i;
		if (rand() & 1) {
			tmp.deposit.depositD = 1000 + rand() % 50 * 100 + (rand() % 100) / 100.0;
			tmp.isDepositDouble = true;
		} else {
			tmp.deposit.depositI = 1000 + rand() % 50 * 100;
			tmp.isDepositDouble = false;
		}
		sprintf(tmp.name, "%s", names[rand() % 6]);
		sprintf(tmp.category, "%s", categories[rand() % 2]);
		sprintf(tmp.date, "%02d.%02d.%4d", rand() % 28 + 1, rand() % 11 + 1, 2020 - (int) i);
		std::cout << tmp << std::endl;
		fwrite(&tmp, sizeof(tmp), 1, f);
	}

	fclose(f);
}