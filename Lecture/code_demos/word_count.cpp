#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

// President Abraham Lincoln's Gettysburg Address,
// with punctuation and capitalization removed.
// Ref:  https://en.wikipedia.org/wiki/Gettysburg_Address
const char *gettysburg =
    "four score and seven years ago our fathers brought forth on this "
    "continent a new nation conceived in liberty and dedicated to the "
    "proposition that all men are created equal now we are engaged in a great "
    "civil war testing whether that nation or any nation so conceived and so "
    "dedicated can long endure we are met on a great battle field of that war "
    "we have come to dedicate a portion of that field as a final resting place "
    "for those who here gave their lives that that nation might live it is "
    "altogether fitting and proper that we should do this but in a larger "
    "sense we can not dedicate we can not consecrate we can not hallow this "
    "ground the brave men living and dead who struggled here have consecrated "
    "it far above our poor power to add or detract the world will little note "
    "nor long remember what we say here but it can never forget what they did "
    "here it is for us the living rather to be dedicated here to the "
    "unfinished work which they who fought here have thus far so nobly "
    "advanced it is rather for us to be here dedicated to the great task "
    "remaining before us that from these honored dead we take increased "
    "devotion to that cause for which they gave the last full measure of "
    "devotion that we here highly resolve that these dead shall not have died "
    "in vain that this nation under god shall have a new birth of freedom and "
    "that government of the people by the people for the people shall not "
    "perish from the earth";

int main(int argc, char **argv) {

  std::stringstream ss{gettysburg};

  std::string word;

  std::set<std::string> set_words;
  std::map<std::string, size_t> map_word_count;

  while (ss >> word) {
    set_words.insert(word);
    // (map_word_count[word])++;
    size_t prev_word_count = map_word_count[word];
    map_word_count[word] = prev_word_count + 1;
  }

  std::cout << "set_words.size() = " << set_words.size() << std::endl;
  std::cout << "map_word_count.size() = " << map_word_count.size() << std::endl;

  // C++11 style
  // for (auto itr = set_words.begin(); itr != set_words.end(); ++itr) { }

  for (const auto &w : set_words) {
    // if(w == "freedom") { std::cout << "find freedom" << std::endl; }
    std::cout << w << " ";
  }

  std::cout << std::endl;

  for (const auto &wc : map_word_count) {
    std::cout << wc.first << " " << wc.second << std::endl;
  }

  //
  // Find top 5 most frequent words

  // copy map contents into vector
  std::vector<std::pair<std::string, size_t>> vec_word_count;
  for (const auto &wc : map_word_count) {
    vec_word_count.push_back(wc);
  }
  std::sort(
      vec_word_count.begin(), vec_word_count.end(),
      [](const auto &lhs, const auto &rhs) { return lhs.second > rhs.second; });

  std::cout << std::endl << "== Top 5 == " << std::endl;
  size_t num_printed{0};
  for (const auto &wc : vec_word_count) {
    if (num_printed++ >= 5) {
      break;
    }
    std::cout << wc.first << " " << wc.second << std::endl;
  }

  return 0;
}
