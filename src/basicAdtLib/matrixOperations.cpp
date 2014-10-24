#include <Training/basicAdt/matrixOperations.hpp>


namespace basicAdt {

ClearRowsColumns::ClearRowsColumns(std::vector<std::vector<int> > &rectangularMatrix) {
  int N = rectangularMatrix[0].size();
  for (int i = 0; i != rectangularMatrix.size(); ++i) {
    for (int j = 0; j != N; ++j) {
      if (rectangularMatrix[i][j] == 0) {
        rowZeros.insert(i);
        columnZeros.insert(j);
      }
      else {
        rowNumbers.insert(i);
        columnNumbers.insert(j);
      }
    }
  }
  if (rowZeros.size() >= columnZeros.size()){
    for (auto it = rowZeros.begin(); it != rowZeros.end(); ++it) {
      for (int j = 0; j != N; ++j){
        rectangularMatrix[(*it)][j] = 0;
      }
    }
    for (auto it = columnZeros.begin(); it != columnZeros.end(); ++it){
      for (auto jt = rowNumbers.begin(); jt != rowNumbers.end(); ++jt) {
        rectangularMatrix[(*jt)][(*it)] = 0;
      }
    }
  }
  else {
    for (auto it = columnZeros.begin(); it != columnZeros.end(); ++it) {
      for (int j = 0; j != N; ++j){
        rectangularMatrix[j][(*it)] = 0;
      }
    }
    for (auto it = rowZeros.begin(); it != rowZeros.end(); ++it){
      for (auto jt = columnNumbers.begin(); jt != columnNumbers.end(); ++jt) {
        rectangularMatrix[(*it)][(*jt)] = 0;
      }
    }
  }
}


}