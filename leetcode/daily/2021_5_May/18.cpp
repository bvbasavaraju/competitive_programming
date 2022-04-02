/****************************************************
Date: May 18th

link: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/600/week-3-may-15th-may-21st/3744/
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
    Q: Find Duplicate File in System

    Given a list paths of directory info, including the directory path, and all the files with contents in this directory,
    return all the duplicate files in the file system in terms of their paths. You may return the answer in any order.

    A group of duplicate files consists of at least two files that have the same content.

    A single directory info string in the input list has the following format:
    +  "root/d1/d2/.../dm f1.txt(f1_content) f2.txt(f2_content) ... fn.txt(fn_content)"
    It means there are n files (f1.txt, f2.txt ... fn.txt) with content (f1_content, f2_content ... fn_content) 
    respectively in the directory "root/d1/d2/.../dm". Note that n >= 1 and m >= 0. If m = 0, it means the directory is just the root directory.

    The output is a list of groups of duplicate file paths. For each group, it contains all the file paths 
    of the files that have the same content. A file path is a string that has the following format:

    + "directory_path/file_name.txt"

    Example 1:
        Input: 
            paths = ["root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)","root 4.txt(efgh)"]
        Output: 
            [["root/a/2.txt","root/c/d/4.txt","root/4.txt"],["root/a/1.txt","root/c/3.txt"]]
    
    Example 2:
    Input: 
        paths = ["root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)"]
    Output: 
        [["root/a/2.txt","root/c/d/4.txt"],["root/a/1.txt","root/c/3.txt"]]

    Constraints:
        1 <= paths.length <= 2 * 104
        1 <= paths[i].length <= 3000
        1 <= sum(paths[i].length) <= 5 * 105
        paths[i] consist of English letters, digits, '/', '.', '(', ')', and ' '.
        You may assume no files or directories share the same name in the same directory.
        You may assume each given directory info represents a unique directory. A single blank space separates the directory path and file info.

    Follow up:
    + Imagine you are given a real file system, how will you search files? DFS or BFS?
    + If the file content is very large (GB level), how will you modify your solution?
    + If you can only read the file by 1kb each time, how will you modify your solution?
    + What is the time complexity of your modified solution? What is the most time-consuming part and memory-consuming part of it? How to optimize?
    + How to make sure the duplicated files you find are not false positive?
*/

class Solution
{
private:
    void getFiles(const string &p, unordered_map<string, vector<string>> &filePaths)
    {
        int pos = 0;

        int t = p.find_first_of(' ', pos);
        string dir = p.substr(0, t);

        pos = t + 1;
        do
        {
            t = p.find_first_of('(', pos);
            string path = dir + "/" + p.substr(pos, t - pos);

            pos = t + 1;
            t = p.find_first_of(')', pos);
            string content = p.substr(pos, t - pos);

            filePaths[content].push_back(path);

            pos = t + 1;
            pos = p.find_first_of(' ', pos);

            if (pos != std::string::npos)
            {
                pos++;
            }
        } while (pos != std::string::npos);
    }

public:
    vector<vector<string>> findDuplicate(vector<string> &paths)
    {
        unordered_map<string, vector<string>> filePaths;

        for (string &p : paths)
        {
            getFiles(p, filePaths);
        }

        vector<vector<string>> ans;
        for (auto &p : filePaths)
        {
            if (p.second.size() > 1)
            {
                ans.push_back(p.second);
            }
        }

        return ans;
    }
};