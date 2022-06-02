#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <set>

using namespace std;

int main()
{
    string line = "";
    map<string, stack<int>> variables;
    stack<set<string>> current_blocks;

    current_blocks.push(set<string>());


    for (int i = 0; i < 1000000; i++)
    {
        getline(cin, line);

        if (line.empty())
            break;

        if (line == "{")
        {
            current_blocks.push(set<string>());
        }
        else if (line == "}")
        {
            for (auto& v : current_blocks.top())
            {
                if (variables.find(v) != variables.end())
                {
                    variables.find(v)->second.pop();
                    if (variables.find(v)->second.size() < 1)
                    {
                        variables.erase(v);
                    }
                }
            }
            current_blocks.pop();
        }
        else
        {
            string variable = "";
            string value = "";
            int number_value = 0;

            int i = 0;
            for (; line[i] != '='; i++)
            {
                variable += line[i];
            }
            i++;
            for (; i < line.size(); i++)
            {
                value += line[i];
            }

            try
            {
                number_value = stoi(value);
            }
            catch (exception e)
            {
                if (variables.find(value) != variables.end())
                {
                    number_value = variables.find(value)->second.top();
                }
                else
                {
                    current_blocks.top().insert(value);
                    variables.insert(pair<string, stack<int>>(value, stack<int>()));
                    variables.find(value)->second.push(0);
                }
                cout << number_value << endl;
            }

            if (variables.find(variable) != variables.end())
            {
                if (current_blocks.top().find(variable) != current_blocks.top().end())
                {
                    variables.find(variable)->second.pop();
                }
                variables.find(variable)->second.push(number_value);
            }
            else
            {
                variables.insert(pair<string, stack<int>>(variable, stack<int>()));
                variables.find(variable)->second.push(number_value);
            }
            current_blocks.top().insert(variable);
        }

    }

    return 0;
}