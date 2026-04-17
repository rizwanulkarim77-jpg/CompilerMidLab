#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ifstream file("myfile.txt");
    char ch;

    while(file.get(ch))
    {

        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'))
        {
            string word="";
            while((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'))
            {
                word += ch;
                file.get(ch);
            }
            file.unget();

            if(word=="int" || word=="cout")
                cout<<word<<" -> Keyword"<<endl;
            else
                cout<<word<<" -> Identifier"<<endl;
        }


        else if(ch>='0' && ch<='9')
        {
            string num="";
            while(ch>='0' && ch<='9')
            {
                num+=ch;
                file.get(ch);
            }
            file.unget();

            cout<<num<<" -> Constant"<<endl;
        }


        else if(ch=='=' || ch=='+' || ch=='-' || ch=='*' || ch=='/')
            cout<<ch<<" -> Operator"<<endl;





        else if(ch=='(' || ch==')' || ch=='{' || ch=='}' || ch==';'|| ch=='<'||ch=='>')
            cout<<ch<<" ->Punctuation"<<endl;


        else if(ch=='"')
        {
            string str="";
            while(file.get(ch) && ch!='"')
                str+=ch;

            cout<<"\""<<str<<"\""<<" -> String"<<endl;
        }
    }

    file.close();
}
