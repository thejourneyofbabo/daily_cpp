// input output file

#include <fstream>
#include <iostream>
#include <string>

int main() {
  // Prepare to read file
  std::ifstream in("test.txt");

  if (!in.is_open()) {
    std::cout << "Can't find the file" << std::endl;
    return 0;
  }

  std::string s;
  while (getline(in, s)) {
    /*getline(in, s);*/
    std::cout << s << std::endl;
  }

  return 0;
}

/*int main() {*/
/*  // prepare to read file*/
/*  std::ifstream in("test.txt");*/
/*  char buf[100];*/
/**/
/*  if (!in.is_open()) {*/
/*    std::cout << "Can't find file" << std::endl;*/
/*    return 0;*/
/*  }*/
/**/
/*  while (in) {*/
/*    in.getline(buf, 100);*/
/*    std::cout << buf << std::endl;*/
/*  }*/
/**/
/*  return 0;*/
/*}*/

/*int main() {*/
/*  // prepare to read file*/
/*  std::ifstream in("test.txt");*/
/*  std::string s;*/
/**/
/*  if (in.is_open()) {*/
/*    in.seekg(0, std::ios::end);*/
/**/
/*    int size = in.tellg();*/
/**/
/*    s.resize(size);*/
/**/
/*    in.seekg(0, std::ios::beg);*/
/**/
/*    in.read(&s[0], size);*/
/*    std::cout << s << std::endl;*/
/*  } else {*/
/*    std::cout << "can't find file" << std::endl;*/
/*  }*/
/**/
/*  return 0;*/
/*}*/

/*int main() {*/
/*  // prepare to read file*/
/*  std::ifstream in("test.txt");*/
/*  std::string s;*/
/**/
/*  if (in.is_open()) {*/
/*    in >> s;*/
/*    std::cout << "the input string:: " << s << std::endl;*/
/*  } else {*/
/*    std::cout << "can't find the file!" << std::endl;*/
/*  }*/
/**/
/*  in.close();*/
/*  in.open("other.txt");*/
/**/
/*  if (in.is_open()) {*/
/*    in >> s;*/
/*    std::cout << "the input string:: " << s << std::endl;*/
/*  } else {*/
/*    std::cout << "can't fine the file!" << std::endl;*/
/*  }*/
/**/
/*  return 0;*/
/*}*/
