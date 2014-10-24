#include <iostream>
#include <Training/basicAdt/basicAdt.hpp>
#include <Training/basicAdt/stringOperations.hpp>
#include <Training/basicAdt/matrixOperations.hpp>

#include <vector>


int main() {
  using basicAdt::AllUnique;
  using basicAdt::Reverse;
  using basicAdt::RemoveDuplicate;
  using basicAdt::IsPermutation;
  using basicAdt::encodeSpacesStringNoFindNoInsert;
  using basicAdt::encodeSpacesStringFind;
  using basicAdt::compressWord;
  using basicAdt::Rotate;
  using basicAdt::ClearRowsColumns;
  using basicAdt::IsRotation;

  std::string original("waterbottle");
  std::string check("erbottlewat");
  IsRotation rot;
  bool stuff = rot.check(original, check);

	/*std::string word("parangacutirimicuaro");
	std::string permutation("oraucimiritucagnarap");
	IsPermutation(word, permutation);

	word = "ooooooooooaaaaoooooooo";
	permutation = "ooaooooaooooaooooaoooo";
	IsPermutation(word, permutation);


	word = "ooooooooooaaaaooooooooooooooooooaaaaooooooooooooooooooaaaaooooooooooooooooooaaaaooooooooooooooooooaaaaooooooooooooooooooaaaaooooooooooooooooooaaaaooooooooooooooooooaaaaooooooooooooooooooaaaaooooooooooooooooooaaaaooooooooooooooooooaaaaoooooooo";
	permutation = "ooaooooaooooaooooaooooooaooooaooooaooooaooooooaooooaooooaooooaooooooaooooaooooaooooaooooooaooooaooooaooooaooooooaooooaooooaooooaooooooaooooaooooaooooaooooooaooooaooooaooooaooooooaooooaooooaooooaooooooaooooaooooaooooaooooooaooooaooooaooooaoooo";
	IsPermutation(word, permutation);

  encodeSpacesStringNoFindNoInsert(std::string("Mr   John Smith    "));
  encodeSpacesStringFind(std::string("Mr   John Smith    "));
  std::string test = compressWord(std::string("aabcccccaaa"));
  
  std::vector< std::vector<int> > intMatrix {
      { 1, 2, 3, 4 },
      { 5, 6, 7, 8 },
      { 9, 10, 11, 12 },
      { 13, 14, 15, 16 }
  };

  Rotate<basicAdt::CW, int> rotateIntClockwise(intMatrix);
  Rotate<basicAdt::CCW, int> rotateIntCClockwise(intMatrix);

  std::vector< std::vector<double> > doubleMatrix{
      { 1, 2, 3, 4 },
      { 5, 6, 7, 8 },
      { 9, 10, 11, 12 },
      { 13, 14, 15, 16 }
  };

  Rotate<basicAdt::CW, double> rotateDblClockwise(doubleMatrix);
  Rotate<basicAdt::CCW, double> rotateDblCClockwise(doubleMatrix);

  std::vector< std::vector<std::string> > stringMatrix{
      { "1", "2", "3", "4" },
      { "5", "6", "7", "8" },
      { "9", "10", "11", "12" },
      { "13", "14", "15", "16" }
  };

  Rotate<basicAdt::CW, std::string> rotateStringClockwise(stringMatrix);
  Rotate<basicAdt::CCW, std::string> rotateStringCClockwise(stringMatrix);
 
  std::vector< std::vector<int> > squareMatrix{
      { 1, 2, 3, 4 },
      { 5, 0, 7, 8 },
      { 9, 10, 0, 12 },
      { 13, 14, 15, 16 }
  };
  ClearRowsColumns clear(squareMatrix);

  for (int i = 0; i != squareMatrix.size(); ++i)
  {
    for (int j = 0; j != squareMatrix[i].size(); ++j)
    {
      std::cout << squareMatrix[i][j] << ' ';
    }
    std::cout << std::endl;
  }

  std::vector< std::vector<int> > intMatrix{
      { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0, 12, 13, 14, 15, 16 },
      { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0, 12, 13, 14, 15, 16 },
      { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0, 12, 13, 14, 15, 16 },
      { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 12, 13, 14, 15, 16 },
      { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 12, 13, 14, 15, 16 },
      { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 12, 13, 14, 15, 16 }
  };
  ClearRowsColumns clear2(intMatrix);
  for (int i = 0; i != intMatrix.size(); ++i)
  {
    for (int j = 0; j != intMatrix[i].size(); ++j)
    {
      std::cout << intMatrix[i][j] << ' ';
    }
    std::cout << std::endl;
  }*/
  return 0;
}
