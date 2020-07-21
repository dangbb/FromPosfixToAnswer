#include <bits/stdc++.h>
#define f first
#define s second
#define maxn 10005
using namespace std;

typedef pair<int,int> pi;

stack<char> c;
stack<int> q;

void Discard()
{
    int a = q.top();
    q.pop();
    int b = q.top();
    q.pop();

    char sign = c.top();
    c.pop();

    if(sign == '*')
    {
        q.push(b * a);
    }
    else if(sign == '/')
    {
        q.push(b / a);
    }
    else if(sign == '+')
    {
        q.push(b + a);
    }
    else if(sign == '-')
    {
        q.push(b - a);
    }

    //cout << b << " " << sign << " " << a << endl;
}

void DiscardUntilEncounterC()
{
    while(c.size() && c.top() != '(')
    {
        Discard();
    }
    if(c.size())
    {
        c.pop();
    }
}

void AllINeed()
{
    //cout << c.size() << " " << q.size() << endl;
}

int main()
{
    //freopen("a.inp","r",stdin);

    string S;
    cin >> S;

    int num = 0;
    bool isSign = false;

    for(int i=0;i<S.length();i++)
    {
        if(S[i] == ' ') continue;
        if('0' <= S[i] && S[i] <= '9')
        {
            num = num * 10 + S[i] - '0';
            isSign = false;
        }
        else
        {
            if(!isSign)
            {
                q.push(num);
                num = 0;

                isSign = true;
            }
            //cout << S[i] << endl;

            if(S[i] == ')')
            {
                DiscardUntilEncounterC();
            }
            else
            {
                if(S[i] != '(' && c.size() && (c.top() == '*'|| c.top() == '/'))
                {
                    Discard();
                }
                c.push(S[i]);
                //cout << S[i] << endl;
            }
            AllINeed();
        }
    }

    if(!isSign)
    {
        q.push(num);
        AllINeed();
    }

    DiscardUntilEncounterC();
    cout << q.top();
}
