#include <Training/basicAdt/stringOperations.hpp>
#include <vector>
#include <sstream>



namespace basicAdt 
{

bool AllUnique(std::string const &rhs) {
  if(rhs.size() > 26) {
    return false;
  }
  int flag=0;
  for(std::size_t i=0; i!=rhs.size(); ++i){
    int offset = rhs.at(i) - 'a';
    offset = 1 << offset;
    if(flag & offset){
      return false;
    }
    flag = flag | offset;
  }
  return true;
}

void Reverse(char *str) {
  if(str){
    char *end = str;
    while(*end) {
      ++end;
    }
    --end;
    char tmp;
    while(str < end) {
      tmp = *str;
      *str++ = *end;
      *end--  = tmp;
    }
  }
}


void RemoveDuplicate(std::string &rhs)
{
  if(!rhs.empty()){
    int flag=0;
    for(std::size_t i=0; i!=rhs.size(); ++i){
      int offset = rhs.at(i) - 'a';
      offset = 1 << offset;
      if(flag & offset){
        rhs.erase(rhs.begin()+i);
        i--;
      }
      flag = flag | offset;
    }
  }
}

void PushOffsetIntoContainer(std::vector<int> &bit_container, char const &element);

bool IsPermutation(std::string const &lhs, std::string const &rhs)
{
  bool returnVal = false;
  if(lhs.size() == rhs.size()) {
    std::vector<int> flag_lhs { 0 };
    std::vector<int> flag_rhs { 0 };
    for(auto&& str : zip_range(lhs, rhs)) {
		PushOffsetIntoContainer(flag_lhs, str.get<0>());
		PushOffsetIntoContainer(flag_rhs, str.get<1>());
    }
    if(flag_rhs.size() == flag_lhs.size()) {
      for(auto&& bitContainer : zip_range(flag_lhs, flag_rhs)) {
		  if (bitContainer.get<0>() == bitContainer.get<1>()) {
          returnVal = true;
        } else {
          returnVal = false;
        }
      }
    }
  }
  return (returnVal);
}

void PushOffsetIntoContainer(std::vector<int> &bit_container, char const &element){
  int offset_ = element - 'a';
  offset_ = 1 << offset_;
  for(auto it = bit_container.begin(); it != bit_container.end(); ++it) {
    if(*it & offset_) {
		  if (std::distance(it, bit_container.end()) == 1) {
		    int pushIt = std::distance(bit_container.begin(), it);
		    bit_container.push_back(0);
		    it = bit_container.begin();
		    std::advance(bit_container.begin(), pushIt);
		  }
    } else {
      *it = *it | offset_;  
      break;
    }
  }
}


void encodeSpacesStringNoFindNoInsert(std::string &rhs) {
  std::string::iterator spaceFound = rhs.end();
	for (auto it = rhs.begin(); it != rhs.end(); ++it) {
    if (*it == ' ') {
      if (spaceFound == rhs.end()){
        spaceFound = it;
      }
    }
    else {
      if (spaceFound != rhs.end()) {
        auto spaceEnd = it;
        std::string middleSequence;
        for (auto innerItr = spaceFound; innerItr != spaceEnd; ++innerItr) {
          middleSequence.append("%20");
        }
        auto SequenceBegin = std::distance(rhs.begin(), spaceFound);
        auto SequenceEnd = std::distance(rhs.begin(), spaceEnd);
        std::string sequence(rhs.begin(), rhs.begin() + SequenceBegin);
        sequence.append(middleSequence);
        sequence.append(rhs.begin() + SequenceEnd, rhs.end());
        rhs = sequence;
        it = rhs.begin() + SequenceEnd;
        spaceFound = rhs.end();
      }
    }
	}
  if (spaceFound != rhs.end()){
    rhs.assign(rhs.begin(), spaceFound);
  }
}

void encodeSpacesStringFind(std::string &rhs) {
  std::string::iterator spaceFound = rhs.end();
  std::string::iterator finishSpaces;
  bool changed = false;
  for (auto it = rhs.end()-1; it != rhs.begin(); --it) {
    if (*it == ' ') {
      if (spaceFound == rhs.end()){
        spaceFound = it;
      }
    }
    else {
      finishSpaces = ++it;
      break;
    }
  }
  rhs.assign(rhs.begin(), finishSpaces);
  for (size_t pos = rhs.find(' '); pos != std::string::npos; pos = rhs.find(' ', pos))
  {
    rhs.replace(pos, 1, "%20");
  }
}

std::string compressWord(std::string const &rhs) {
  auto it = rhs.begin();
  auto pastEl = *it;
  std::advance(it, 1);
  std::stringstream finalAssembly;
  int count = 1;
  for (; it != rhs.end(); ++it) {
    if (pastEl == *it){
      count += 1;
    }
    else {
      finalAssembly << pastEl << count;
      count = 1;
      pastEl = *it;
    }
  }
  finalAssembly << pastEl << count;
  std::string result = finalAssembly.str();
  if (rhs.size() <= result.size()) {
    return rhs;
  }
  else {
    return result;
  }
}

bool IsRotation::isSubstring(std::string const &lhs, std::string const &rhs) {
  return (lhs.find(rhs) != std::string::npos);
}
bool IsRotation::check(std::string const &lhs, std::string const &rhs){
  return (isSubstring(std::string(lhs+lhs), rhs));
}

}