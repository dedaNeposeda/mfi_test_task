#include "parttrue_search.h"

void parttrue_search(std::ifstream& file_stream, const std::string& sub_string)
{
    while (file_stream.good())
    {
        std::string tmp;
        std::getline(file_stream, tmp);

        int difference = 2;
        if (abs((static_cast<double>(sub_string.size()) - static_cast<double>(tmp.size()))) < 2)
        {

            if (sub_string.size() < tmp.size())
            {
                auto sub_string_iter = sub_string.begin();
                auto tmp_iter = tmp.begin();
                while (sub_string_iter != sub_string.end() && difference)
                {
                    if (*sub_string_iter != *tmp_iter)
                    {
                        difference--;
                        tmp_iter++;
                    }
                    else
                    {
                        sub_string_iter++;
                        tmp_iter++;
                    }                    
                }
            }

            if (sub_string.size() == tmp.size())
            {
                auto sub_string_iter = sub_string.begin();
                auto tmp_iter = tmp.begin();
                while (difference && sub_string_iter != sub_string.end())
                {
                    if (*sub_string_iter != *tmp_iter)
                        difference--;
                    sub_string_iter++;
                    tmp_iter++;
                }
            }

            if (sub_string.size() > tmp.size())
            {
                auto sub_string_iter = sub_string.begin();
                auto tmp_iter = tmp.begin();
                while (difference && tmp_iter != tmp.end())
                {
                    if (*sub_string_iter != *tmp_iter)
                    {
                        difference--;
                        sub_string_iter++;
                    }
                    else
                    {
                        sub_string_iter++;
                        tmp_iter++;
                    }
                }
            }
        }
        else
            difference = 0;
        if (difference)
            std::cout << tmp << std::endl;
    }
    file_stream.seekg(0);
}