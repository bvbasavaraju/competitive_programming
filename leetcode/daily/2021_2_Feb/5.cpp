/****************************************************
Date: Feb 5th

link: https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/584/week-1-february-1st-february-7th/3628/
****************************************************/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <limits.h>

using namespace std;

/*
  Q: Simplify Path

  Given a string path, which is an absolute path (starting with a slash '/') to a file or directory
  in a Unix-style file system, convert it to the simplified canonical path.

  In a Unix-style file system, a period '.' refers to the current directory, 
  a double period '..' refers to the directory up a level, 
  and any multiple consecutive slashes (i.e. '//') are treated as a single slash '/'. 
  For this problem, any other format of periods such as '...' are treated as file/directory names.

  The canonical path should have the following format:
    + The path starts with a single slash '/'.
    + Any two directories are separated by a single slash '/'.
    + The path does not end with a trailing '/'.
    + The path only contains the directories on the path from the root directory to the target file or directory 
      (i.e., no period '.' or double period '..')

  Return the simplified canonical path.

  Example 1:
    Input: path = "/home/"
    Output: "/home"
    Explanation: 
      Note that there is no trailing slash after the last directory name.

  Example 2:
    Input: path = "/../"
    Output: "/"
    Explanation:
      Going one level up from the root directory is a no-op, as the root level is the highest level you can go.

  Example 3:
    Input: path = "/home//foo/"
    Output: "/home/foo"
    Explanation:
      In the canonical path, multiple consecutive slashes are replaced by a single one.

  Example 4:
    Input: path = "/a/./b/../../c/"
    Output: "/c"

  Constraints:
    1 <= path.length <= 3000
    path consists of English letters, digits, period '.', slash '/' or '_'.
    path is a valid absolute Unix path.
*/

class Solution 
{  
private:
  void addToFolders(string& folder, vector<string>& folders)
  {
    static const string CURRENT_DIR = ".";
    static const string PREVIOUS_DIR = "..";
    static const string ADDITIONAL_SLASH = "/";
    
    if(!folder.empty())
    {
      if(!folders.empty() && (folder == PREVIOUS_DIR))
      {
        folders.pop_back();
      }
      else if((folder != CURRENT_DIR) && (folder != ADDITIONAL_SLASH) && (folder != PREVIOUS_DIR))
      {
        folders.push_back(folder);
      }
    }
  }
  
public:
  string simplifyPath(string path) 
  {
    int l = path.size();
    
    vector<string> folders;
    
    int i = 0;
    for(; i < l;)
    {
      size_t p = path.find_first_of('/', i);
      if(p == std::string::npos)
      {
        break;
      }
      
      string folder = path.substr(i, p-i);
      addToFolders(folder, folders);
      
      i = p+1;
    }
    
    if(i < l)
    {
      string folder = path.substr(i, l-i);
      addToFolders(folder, folders);
    }
    
    string ans = folders.size() == 0 ? "/" : "";
    for(string& folder : folders)
    {
      ans += "/" + folder;
    }
    
    return ans;
  }
};