#include <bits/stdc++.h>

using namespace std;

string convertinttostring(long long a)
{
    string s = "";
    string result = "";
    while (a >= 1)
    {
        result = "";
        result += (a % 10) + 48;
        result += s;
        s = result;
        a /= 10;
    }
    return result;
}

vector< pair<string, long long> > allpowtwo;

void fillvector()
{
    long long a = 1;
    while (a <= 1e18)
    {
        string s = convertinttostring(a);
        allpowtwo.push_back(make_pair(s, s.size()));
        a *= 2;
    }
}

long long solve(string s)
{
    long long low = s.size() + 1, a = 0;
    while (allpowtwo[a].second <= s.size() * 2)
    {
        long long c = 0, d = 0, b = 0;
        while (true)
        {
            if (c < allpowtwo[a].first.size() && d < s.size())
            {
                if (allpowtwo[a].first[c] == s[d])
                {
                    b++;
                    c++;
                }
                d++;
            }
            else
            {
                break;
            }
        }
        long long aaa = (s.size() - b) + (allpowtwo[a].first.size() - b);
        low = min(low, aaa);
        a++;
    }
    return low;
}

int main()
{
    fillvector();
    long long a;
    cin >> a;
    for (long long i = 0; i < a; i++)
    {
        string b;
        cin >> b;
        cout << solve(b) << endl;
    }
}