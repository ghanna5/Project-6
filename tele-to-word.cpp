#include<iostream>
#include <fstream>

std::string convert(char n)
{
    std::string s;
    switch(n)
    {
    case '2':
        s = "ABC";
        break;
    case '3':
        s = "DEF";
        break;
    case '4':
        s = "GHI";
        break;
    case '5':
        s = "JKL";
        break;
    case '6':
        s = "MNO";
        break;
    case '7':
        s = "PQRS";
        break;
    case '8':
        s = "TUV";
        break;
    case '9':
        s = "WXYZ";
        break;
    }

    return s;
}

void generate_names(std::string a, std::string b, std::string c, std::string d, std::string e, std::string f, std::string g, std::string p)
{
    int counter = 0;
    std::ofstream outdata(p);

    for(int i = 0; i < a.length(); i++)
    {
       for(int j = 0;  j < b.length(); j++)
       {
            for(int k = 0; k < c.length(); k++)
            {
                for(int l = 0; l < d.length(); l++)
                {
                    for(int m = 0; m < e.length(); m++)
                    {
                        for(int n = 0; n < f.length(); n++)
                        {
                            for(int o = 0; o < g.length(); o++)
                            {
                                outdata << a[i] << b[j] << c[k] << d[l] << e[m] << f[n] << g[o] << "\t";
                                counter += 1;

                                if(counter % 8 == 0)
                                {
                                    outdata << "\n";
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

bool check_number(std::string n)
{
    int flag = 1;

    for(int i = 0; i < n.length(); i++)
    {
        if(n[i] == '1' || n[i] == '0')
        {
            flag = 0;
        }
    }

    return flag;
}

int main()
{
   std::string number;   
   std::string path;

   std::cout << "\nEnter the output file path: ";
   std::cin >> path;

   std::cout << "Enter a phone number (digits 2 through 9) in the form: xxx-xxxx: ";
   std::cin >> number;

   if(check_number(number))
   {
       std::string parameter1, parameter2, parameter3, parameter4, parameter5, parameter6, parameter7;
       std::string extension = ".dat";

       parameter1 = convert(number[0]);
       parameter2 = convert(number[1]);
       parameter3 = convert(number[2]);
       parameter4 = convert(number[4]);
       parameter5 = convert(number[5]);
       parameter6 = convert(number[6]);
       parameter7 = convert(number[7]);

      std::string full_file_path = path + number + extension;
      generate_names(parameter1, parameter2, parameter3, parameter4, parameter5, parameter6, parameter7, full_file_path);

      std::cout << "For phone number " << number << ":" << std::endl;
    }

    else
    {
        std::cout << "This number is not valid\nProgram will exit now";
    }

}