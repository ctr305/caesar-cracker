#include <iostream>
#include <string.h>
//The challenge is creating a program that can solve and crack caesar cyphers.

/*Caesar cyphers are the simplest and most well known kind of cyphers, the way they work is by
  shifting letters an x number of positions in the alphabet, and wrapping
  around if the alphabet ends while there are still positions left to shift.
  For example, wiht a cypher number of 1, A becomes Z, B becomes A, and so forth.

  In order to decode a caesar cypher, one must know the correct cypher number or brute force it, and
  this program aims to help in that regard.
*/

//WARNING: This is going to be really bad code

const char ALPHABET_UPPERCASE[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
const char ALPHABET_LOWERCASE[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

//This function is used if the user knows the correct number to their cypher
void solveCypher(std::string cypher,int cypherNo);
//This function is used to bruteforce the cypher if the user does not know the correct number
void crackCypher(std::string cypher);

int main(){
  std::string cypher;
  char knowCypherNo;
  bool breakCypherWithoutNumber = false;
  int cypherNo;

  std::cout << "Please enter your cyphered string" << std::endl;
  getline(std::cin,cypher);
  std::cout << "The cypher you entered was:" << std::endl;
  std::cout << cypher << std::endl;
  std::cout << "Do you know the cypher number for this string? (this number must be between 1 and 26)" << std::endl;
  std::cout << "y/N" << std::endl;
  std::cin >> knowCypherNo;

  switch(knowCypherNo){
    case 'y':
    case 'Y':
      std::cout << "Please enter the cypher number" << std::endl;
      std::cin >> cypherNo;
      while(cypherNo < 0 || cypherNo > 26){
        std::cout << "Please enter a valid cypher number" << std::endl;
        std::cin >> cypherNo;
      }
      solveCypher(cypher,cypherNo);
      break;
    default:
      std::cout << "Trying to crack the cypher without a cypher number" << std::endl;
      crackCypher(cypher);
  }

  return 0;
}

void solveCypher(std::string cypher,int cypherNo){
  int alphabetNo;
  char letter;
  bool lowercase = false;

  for(int i=0;i<cypher.size();i++){
    //Special character detectio through ASCII codes
    if((cypher[i]>=48 && cypher[i]<=57) ||
       (cypher[i]>=65 && cypher[i]<=90) ||
       (cypher[i]>=97 && cypher[i]<=122)){
      letter = cypher[i];

      for(int j=0;j<=25;j++){
        if(letter == ALPHABET_LOWERCASE[j]){
          lowercase = true;
          alphabetNo = j;
        }
      }
      if(!lowercase){
        for(int j=0;j<=25;j++){
          if(letter == ALPHABET_UPPERCASE[j]){
            alphabetNo = j;
          }
        }
        for(int k = 0;k<cypherNo;k++){
          if(alphabetNo == 0){
            alphabetNo = 25;
          }else{
            alphabetNo--;
          }
        }
        cypher[i] = ALPHABET_UPPERCASE[alphabetNo];
      }else{
        for(int k = 0;k<cypherNo;k++){
          if(alphabetNo == 0){
            alphabetNo = 25;
            }else{
            alphabetNo--;
          }
        }
        cypher[i] = ALPHABET_LOWERCASE[alphabetNo];
      }
    }
  }

  std::cout << "Cypher solved" << std::endl;
  std::cout << cypher << std::endl;
}

void crackCypher(std::string cypher){

  int alphabetNo, cypherNo = 1;
  char letter;
  bool lowercase = false;
  std::string auxCypher;

  std::cout << "Returning all possible answers\n" << std::endl;

  for(int l=0;l<26;l++){
    auxCypher = cypher;
    for(int i=0;i<auxCypher.size();i++){
      if((auxCypher[i]>=48 && auxCypher[i]<=57) ||
         (auxCypher[i]>=65 && auxCypher[i]<=90) ||
         (auxCypher[i]>=97 && auxCypher[i]<=122)){
        letter = auxCypher[i];

        for(int j=0;j<=25;j++){
          if(letter == ALPHABET_LOWERCASE[j]){
            lowercase = true;
            alphabetNo = j;
          }
        }
        if(!lowercase){
          for(int j=0;j<=25;j++){
            if(letter == ALPHABET_UPPERCASE[j]){
              alphabetNo = j;
            }
          }
          for(int k = 0;k<cypherNo;k++){
            if(alphabetNo == 0){
              alphabetNo = 25;
            }else{
              alphabetNo--;
            }
          }
          auxCypher[i] = ALPHABET_UPPERCASE[alphabetNo];
        }else{
          for(int k = 0;k<cypherNo;k++){
            if(alphabetNo == 0){
              alphabetNo = 25;
            }else{
              alphabetNo--;
            }
          }
          auxCypher[i] = ALPHABET_LOWERCASE[alphabetNo];
        }
      }
    }
    std::cout << auxCypher << std::endl;
    cypherNo++;
    lowercase = false;
  }
  std::cout << "\nCypher cracked" << std::endl;
}
