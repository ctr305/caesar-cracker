#include <iostream>

//The challenge is creating a program that can crack caesar cyphers

void solveCypher(int cypherNo);
void crackCypher();

int main(){
  string cyphered;
  char knowCypherNo;
  bool breakCypherWithoutNumber = false;
  int cypherNo;

  std::cout << "Please enter your cyphered string" << std::endl;
  std::cin >> cyphered;
  std::cout << "Do you know the cypher number for this string?" << std::endl;
  std::cout << "Y/N" << std::endl;
  std::cin >> knowCypherNo;

  switch(knowCypherNo){
    case 'y':
    case 'Y':
      std::cout << "Please enter the cypher number" << std::endl;
      std::cin >> cypherNo;
      break;
    default:
      std::cout << "Trying to crack the cypher without a cypher number" << std::endl;
      breakCypherWithoutNumber = true;
  }

  if(!breakCypherWithoutNumber){
    solveCypher(cypherNo);
  }else{
    crackCypher();
  }

  return 0;
}

void solveCypher(int cypherNo){
  //placeholder
  std::cout << "Cypher solved" << std::endl;
}

void crackCypher(){
  //placeholder
  std::cout << "Cypher cracked" << std::endl;
}
