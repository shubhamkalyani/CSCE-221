#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::map;
using std::pair;
using std::multimap;
using std::vector;

multimap<int, string> flip(map<string, int> &m) {
  multimap<int, string> mm;
  for (auto itr = m.begin(); itr != m.end(); itr++) {
    mm.insert(make_pair(itr->second, itr->first));
  }
  return mm;
}

int main(int argc, char **argv) {

  map<string, int> numCommentsByAuthor;
  multimap<string, size_t> authorUTC;
  multimap<string, int> sizeByAuthor;
  map<string, int> totalSizeByAuthor;
  map<pair<string, string>, int> numSubredditByAuthor;
  map<string, int> numAuthorBySubreddit;

  //
  // Parse the reddit ndjson input file
  std::ifstream ifs("../data/RC_2019-02-01_trimmed.ndjson");
  std::string line;
  size_t record_count{0};
  
  while (std::getline(ifs, line)) {
    //if( record_count == 5000) break;
    record_count++;
    // Use this to help test faster with fewer records
    
  
    //
    // Important fields to use
    auto json = nlohmann::json::parse(line);
    std::string author = json["author"];
    std::string subreddit = json["subreddit"];
    std::string body = json["body"];
    std::string id = json["id"];
    std::string parent_id = json["parent_id"];
    size_t created_utc = json["created_utc"];
    size_t score = json["score"];

    
    numCommentsByAuthor[author]++;
    authorUTC.insert(make_pair(author, created_utc));
    sizeByAuthor.insert(make_pair(author, body.size()));
    totalSizeByAuthor[author] += body.size();
    numSubredditByAuthor[make_pair(author, subreddit)]++;
    numAuthorBySubreddit[subreddit]++;
  }
  cout << record_count << " records parsed." << endl;

  //////////////////////////////////////////////////////////////////////////////
  // Deliverables:  Answer the following 10 questions by cout'ing to console  //
  //////////////////////////////////////////////////////////////////////////////

  //
  // Notes:
  // When ties in authors or subreddits exists, lexigraphically sort by string.
  //

  //
  // 1. Who are the Top 10 most prolific authors (most number of comments)?

  multimap<int, string> newMap = flip(numCommentsByAuthor); 

  cout << "1. Top 10 most prolific authors: " << endl;

  int i = 1;
  for (auto itr = newMap.rbegin(); itr != newMap.rend(); ++itr) {
    cout << "   " << i << ". " << itr->second << " with " << itr->first << " comment(s)." << endl;
    i++;
    if (i > 10) {
      break;
    }
  }

  //
  // 2. How many authors only comment once?

  int numOnce = 0;
  for (auto itr = numCommentsByAuthor.begin(); itr != numCommentsByAuthor.end(); ++itr) {
    if (itr->second == 1) {
      numOnce++;
    }
  }
  cout << "2. " << numOnce << " authors only comment once." << endl;

  //
  // 3. Which author makes the most total comments?

  auto authorMostComments = std::max_element(numCommentsByAuthor.begin(), numCommentsByAuthor.end(), [](const auto &x, const auto &y) {
                    return x.second < y.second;
                });
 
  cout << "3. " << authorMostComments->first << " makes the most total comments at " << authorMostComments->second << "." << endl;

  //
  // 4. For the author with the most comments, what is the min/max UTC time?

  vector<size_t> utcs;
  for (auto itr = authorUTC.begin(); itr != authorUTC.end(); itr++) {
    if (itr->first == authorMostComments->first) {     
      utcs.push_back(itr->second);
    }
  }
  //cout << utcs.size() << endl;
  cout << "4. The author with the most comments, " << authorMostComments->first << ", has a \n   max UTC time of " << utcs[utcs.size() - 1] << " and a min UTC time of " << utcs[0] << "." << endl; 

  //
  // 5. Which author makes the longest comment?   Hint:  body.size()
  vector<int> sizes;
  for (auto itr = sizeByAuthor.begin(); itr != sizeByAuthor.end(); itr++) {
    sizes.push_back(itr->second);
  }

  sort(sizes.begin(), sizes.end());

  for (auto itr = sizeByAuthor.begin(); itr != sizeByAuthor.end(); itr++) {
    if (itr->second == sizes[sizes.size() - 1]) {
      cout << "5. " << itr->first << " makes the longest comment." << endl;
      break;
    }
  }

  //
  // 6. Which author types the most? (assume body.size() is how much the author
  // typed).

  multimap<int, string> newMap1 = flip(totalSizeByAuthor);
  for (auto itr = newMap1.rbegin(); itr != newMap1.rend(); itr++) {
    cout << "6. " << itr->second << " types the most." << endl;
    break;
  }

  //
  // 7. Which author comments on the most number of subreddits?
  
  int max = 0;
  string maxAuthor;
  string prevAuthor;
  int count = 0;
  int stop = 0;
  for (auto itr = numSubredditByAuthor.begin(); itr != numSubredditByAuthor.end(); itr++) {
    if (stop == 0) {
      max = 1;
      maxAuthor = itr->first.first;
      prevAuthor = itr->first.first;
      count = 1;
      stop++;
      continue;
    }

    if (itr->first.first == prevAuthor) {
      count++;
      if (count > max) {
        max = count;
        maxAuthor = itr->first.first;
        prevAuthor = itr->first.first;
      }
    } else {
      count = 1;
      if (count > max) {
        max = count;
      }
      prevAuthor = itr->first.first;
    }
  }

  cout << "7. " << maxAuthor << " comments on the most number of subreddits." << endl;

  //
  // 8. How many authors only comment on 1 subreddit?

  int x = 0;
  for (auto itr = numSubredditByAuthor.begin(); itr != numSubredditByAuthor.end(); itr++) {
    if (itr->second == 1) {
      x++;
    }
  }
  cout << "8. " << x << " authors only comment on 1 subreddit." << endl;

  //
  // 9. How many subreddits only have 1 author?

  multimap<int, string> newMap2 = flip(numAuthorBySubreddit);
  int oneAuthor = 0;
  for (auto itr = newMap2.rbegin(); itr != newMap2.rend(); itr++) {
    if (itr->first == 1) {
      oneAuthor++;
    }
  }
  cout << "9. " << oneAuthor << " subreddits only have one author." << endl;

  //
  // 10. Which subreddit has the most authors?
  
  for (auto itr = newMap2.rbegin(); itr != newMap2.rend(); itr++) {
    cout << "10. The subreddit " << itr->second << " has the most authors with " << itr->first << " authors." << endl;
    break;
  }

  //////////////////////////////////////////////////////////////////////////////
  // EXTRA CREDIT:  10pts each                                                //
  //        Google is your friend to help tokenize the body of the comments   //
  //////////////////////////////////////////////////////////////////////////////

  //
  // 11. Which authors have the shortest and longest average comment length

  //
  // 12. Which word is the most frequently used to start a comment?
  //     (Assume words are just characters separated by whitespace)

  //
  // 13. For the top 10 commented on subreddits, what is the most used word?

  //
  // 14. What is the relative frequency of each character in all comments?
}

