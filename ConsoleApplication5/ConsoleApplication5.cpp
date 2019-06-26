#include "pch.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

int main() {
	int n, len;
	std::cin >> n;
	std::cin >> len;
	char buffer[1000000 + 1];
	std::cin >> buffer;
	std::string s(buffer);
	int pow = 1;
	for (int i = 0; i < len; i++) {
		pow *= 10;
	}
	std::vector<bool> was(pow, false);
	int value = 0;
	for (int i = 0; i + 1 < len && i < n; i++) {
		value = value * 10 + s[i] - '0';
	}
	for (int i = len - 1; i < n; i++) {
		value = value * 10 + s[i] - '0';
		value %= pow;
		if (was[value]) {
			printf("YES");
			return 0;
		}
		was[value] = true;
	}
	printf("NO");
	return 0;
}
