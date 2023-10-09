// 2022 by Polevoi Dmitry
// task source https://codeforces.com/problemset/problem/978/B
// 978B. ��� �����

#include <iostream>
#include <string>

int main() {
  int n = 0; // ����� ����� �����
  std::string name;
  std::cin >> n >> name;
  const char bad_sym = 'x';
  int len_deleted = 0;
  for (int i = 0; i < n; i += 1) {
    if (bad_sym == name[i]) {
      // ������ ������������ ����������� ������������������
      int len = 1;
      while (bad_sym == name[i + len]) {
        len += 1;
      }
      if (2 < len) {
        len_deleted += len - 2;
      }
      i += len;
    }
  }
  std::cout << len_deleted;
}
