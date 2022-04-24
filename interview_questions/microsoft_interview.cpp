#include <bits/stdc++.h>

using namespace std;

/*
  Q: Node swapping!
  i/p -> 1->2->3->4->5
  o/p -> 2->1->4->3->5
*/

//Solved!!

/*
  Q: Domain capture
*/
#include <iostream>
#include <bits/stdc++.h>
/*
    https://app.codility.com/c/codelive/CL-9RB9CA-46J/
    https://app.codility.com/c/codelive/CL-9RB9CA-46J?a=1&b=2#go-here
    https://app.codility.com/c/codelive/CL-9RB9CA-46J#go-here

    app.x.a.codility.com
    x.a.codility.com
    app.codility.com
    codility.com
*/

using namespace std;
class IdentifyDomain_t
{
private:
    vector<string> domainEndsWith;  //.com, .in, azure.com
    //vector<string> protos;  // https,
    vector<string> patterns;    // ://, /

    string getSubString(const string& str, const string& pattern, bool first_occurance, bool pre_pattern = false)
    {
        string empty;
        if(str.empty() || pattern.empty())
        {
            return empty;
        }

        size_t p1 = -1;
        if(first_occurance)
        {
            p1 = str.find_first_of(pattern);
        }
        else
        {
            p1 = str.find_last_of(pattern);
        }

        size_t pattern_pos = p1 + pattern.size();
        if((p1 == std::string::npos) || (!pre_pattern && (pattern_pos >= str.size())))
        {
            return empty;
        }

        if(pre_pattern)
        {
            return str.substr(0, p1);
        }
        
        if(first_occurance)
        {
            return str.substr(pattern_pos, str.size() - (p1+pattern_pos));
        }

        return str.substr(pattern_pos);
    }

    bool isUrlValid(const string& url)
    {
        if(url.empty())
        {
            return false;
        }

        //TODO: look for standard url syntax;

        return true;
    }

public:
    IdentifyDomain_t()
    {
        domainEndsWith.push_back(".com");
        //protos.push_back("https");
        patterns = {"://", "/"};
    }

    string getDomain(const string& url)
    {
        string empty;
        if(!isUrlValid(url))
        {
            return empty;
        }

        string str1 = getSubString(url, patterns[0], true);
        if(str1.empty())
        {
            return empty;
        }

        string only_domain_app = getSubString(str1, patterns[1], true, true);
        
        string temp = getSubString(only_domain_app, ".", false, true);      //app.codiity

        return getSubString(temp, ".", false) + domainEndsWith[pos];
    }
};

int main() {
    // you can write to stdout for debugging purposes, e.g.
    std::cout << "This is a debug message" << std::endl;

    IdentifyDomain_t idDomain;
    string url = "https://app.codility.com/c/codelive/CL-9RB9CA-46J#go-here";
    std::cout << idDomain.getDomain(url) << std::endl;
    return 0;
}
