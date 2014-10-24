#define BOOST_TEST_MAIN 
#define BOOST_TEST_MODULE BasicAbstractDataTypes
#include <boost/test/unit_test.hpp>

#include <Training/basicAdt/basicAdt.hpp>
#include <Training/basicAdt/stringOperations.hpp>
#include <Training/basicAdt/matrixOperations.hpp>

template<class T>
void CheckMatrices(T const &matrixOne, T const &matrixTwo) {
	for(int i=0; i != matrixOne.size(); ++i){
  	for(int j=0; j != matrixOne.size(); ++j){
  		BOOST_CHECK(matrixOne[i][j] == matrixTwo[i][j]);
  	}
  }
}

	
BOOST_AUTO_TEST_SUITE(BasicAbstractDataTypes_suite)

BOOST_AUTO_TEST_CASE( string_all_unique_test_true )
{
	std::string murcielago("murcielago");
	BOOST_CHECK(basicAdt::AllUnique(murcielago));
	std::string abc("abcdefghijklmnoprstuvwxyz");
	BOOST_CHECK(basicAdt::AllUnique(abc));
}

BOOST_AUTO_TEST_CASE( string_all_unique_test_false )
{
  	std::string pepe("pepe");
	BOOST_CHECK(!basicAdt::AllUnique(pepe));
	std::string onomatopeya("onomatopeya");
	BOOST_CHECK(!basicAdt::AllUnique(onomatopeya));
}

BOOST_AUTO_TEST_CASE( string_Reverse )
{
	char hello[] = { 'H', 'e', 'l', 'l', 'o', '\0' };
	basicAdt::Reverse(hello);
	std::string result("olleH");
	BOOST_CHECK(!result.compare(hello));
}

BOOST_AUTO_TEST_CASE( string_Reverse_long_string )
{
	char paranga[] = { 'P', 'a', 'r', 'a', 'n', 'g', 'a', 'c',
			'u', 't', 'i', 'r', 'i', 'm', 'i', 'c', 'u', 'a', 'r', 'o', '\0' };
	basicAdt::Reverse(paranga);
	std::string result("oraucimiritucagnaraP");
	BOOST_CHECK(!result.compare(paranga));
}

BOOST_AUTO_TEST_CASE( string_remove_duplicate )
{
	std::string onomatopeya("onomatopeya");
	basicAdt::RemoveDuplicate(onomatopeya);
	BOOST_CHECK(!onomatopeya.compare("onmatpey"));
}

BOOST_AUTO_TEST_CASE( string_remove_duplicate_long )
{
	std::string longest_word_maybe("pneumonoultramicroscopicsilicovolcanoconiosis");
	basicAdt::RemoveDuplicate(longest_word_maybe);
	BOOST_CHECK(!longest_word_maybe.compare("pneumoltraicsv"));
}

BOOST_AUTO_TEST_CASE( permutation_small )
{
	std::string word("Parangacutirimicuaro");
	std::string permutation("oraucimiritucagnaraP");
	BOOST_CHECK(basicAdt::IsPermutation(word, permutation));
}

BOOST_AUTO_TEST_CASE( permutation_long_repeated_characters )
{
	std::string word("ooooooooooaaaaooooooooooooooooooaaaaooooooooooooooooooaaaaooooooooooooooooooaaaaooooooooooooooooooaaaaooooooooooooooooooaaaaooooooooooooooooooaaaaooooooooooooooooooaaaaooooooooooooooooooaaaaooooooooooooooooooaaaaooooooooooooooooooaaaaoooooooo");
	std::string permutation("ooaooooaooooaooooaooooooaooooaooooaooooaooooooaooooaooooaooooaooooooaooooaooooaooooaooooooaooooaooooaooooaooooooaooooaooooaooooaooooooaooooaooooaooooaooooooaooooaooooaooooaooooooaooooaooooaooooaooooooaooooaooooaooooaooooooaooooaooooaooooaoooo");
	BOOST_CHECK(basicAdt::IsPermutation(word, permutation));
}

BOOST_AUTO_TEST_CASE( replace_spaces_string_no_find )
{
	std::string word("Mr   John Smith    ");
	std::string changed("Mr%20%20%20John%20Smith");
	basicAdt::encodeSpacesStringNoFindNoInsert(word);
	BOOST_CHECK(!word.compare(changed));
}

BOOST_AUTO_TEST_CASE( replace_spaces_string_find )
{
	std::string word("Mr   John Smith    ");
	std::string changed("Mr%20%20%20John%20Smith");
	basicAdt::encodeSpacesStringFind(word);
	BOOST_CHECK(!word.compare(changed));
}

BOOST_AUTO_TEST_CASE( compress_word )
{
	std::string word("aabcccccaaa");
	std::string changed("a2b1c5a3");
	std::string result = basicAdt::compressWord(word);
	BOOST_CHECK(!result.compare(changed));
}

BOOST_AUTO_TEST_CASE( check_integer_matrix_rotation )
{
  std::vector< std::vector<int> > intMatrix { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };
  std::vector< std::vector<int> > resultsOne { { 13, 9, 5, 1 }, { 14, 10, 6, 2 }, { 15, 11, 7, 3 }, { 16, 12, 8, 4 } };
  std::vector< std::vector<int> > resultsTwo { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };

  basicAdt::Rotate<basicAdt::CW, int> RotateIntClockwise(intMatrix);
  CheckMatrices(intMatrix, resultsOne);

  basicAdt::Rotate<basicAdt::CCW, int> RotateIntCClockwise(intMatrix);
  CheckMatrices(intMatrix, resultsTwo);
}

BOOST_AUTO_TEST_CASE( check_string_matrix_rotation )
{
  std::vector< std::vector<std::string> > stringMatrix{ { "1", "2", "3", "4" }, { "5", "6", "7", "8" }, { "9", "10", "11", "12" }, { "13", "14", "15", "16" } };
  std::vector< std::vector<std::string> > resultsOne { { "13", "9", "5", "1" }, { "14", "10", "6", "2" }, { "15", "11", "7", "3" }, { "16", "12", "8", "4" } };
  std::vector< std::vector<std::string> > resultsTwo { { "1", "2", "3", "4" }, { "5", "6", "7", "8" }, { "9", "10", "11", "12" }, { "13", "14", "15", "16" } };

  basicAdt::Rotate<basicAdt::CW, std::string> RotateStringClockwise(stringMatrix);
  CheckMatrices(stringMatrix, resultsOne);
  basicAdt::Rotate<basicAdt::CCW, std::string> RotateStringCClockwise(stringMatrix);
  CheckMatrices(stringMatrix, resultsTwo);
}

BOOST_AUTO_TEST_CASE( transform_0_square_matrix )
{
	std::vector< std::vector<int> > squareMatrix{
      { 1, 2, 3, 4 },
      { 5, 0, 7, 8 },
      { 9, 10, 0, 12 },
      { 13, 14, 15, 16 }
  };
  std::vector< std::vector<int> > resultMatrix{
      { 1, 0, 0, 4 },
      { 0, 0, 0, 0 },
      { 0, 0, 0, 0 },
      { 13, 0, 0, 16 }
  };
  basicAdt::ClearRowsColumns clear(squareMatrix);
  CheckMatrices(squareMatrix, resultMatrix);
}

BOOST_AUTO_TEST_CASE( transform_0_rectangular_matrix )
{
  std::vector< std::vector<int> > rectangularMatrix{
      { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0, 12, 13, 14, 15, 16 },
      { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0, 12, 13, 14, 15, 16 },
      { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0, 12, 13, 14, 15, 16 },
      { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 12, 13, 14, 15, 16 },
      { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 12, 13, 14, 15, 16 },
      { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 12, 13, 14, 15, 16 }
  };
  std::vector< std::vector<int> > resultMatrix{
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0, 12, 13, 14, 15, 16 },
      { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0, 12, 13, 14, 15, 16 },
      { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0, 12, 13, 14, 15, 16 }
  };
  basicAdt::ClearRowsColumns clear2(rectangularMatrix);
  CheckMatrices(rectangularMatrix, resultMatrix);
}

BOOST_AUTO_TEST_CASE( check_rotation_in_string_substring )
{
	std::string original("waterbottle");
  std::string result("erbottlewat");
  basicAdt::IsRotation rot;
  BOOST_CHECK(rot.check(original, result));
}

BOOST_AUTO_TEST_SUITE_END()