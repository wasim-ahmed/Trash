//This file is responsibnle for task1  = listing down terminal & non-terminal 

#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

#define GRAMMAR_RULE 23

string trim(string str)
{
    str.erase(0, str.find_first_not_of(' '));       //prefixing spaces
    str.erase(str.find_last_not_of(' ')+1);         //surfixing spaces
    return str;
}


int main()
{

/*	string str[GRAMMAR_RULE] = {"decl -> idList colon ID #",
			 "idList -> ID idList1 #",
			 "idList1 -> #",	
			 "idList1 -> COMMA ID idList1 #"};
*/
/*string str[GRAMMAR_RULE] = {"S -> A B #",
				"S -> C #",
				"C -> c #",
				"S -> a #",
				"A -> a A #",
				"B -> b #"};*/
/*	string str[GRAMMAR_RULE] = {
				"S -> a A #",
					"S -> g B h #",
					"A -> a B #",
					"B -> d C f A #",
					"B -> r #",
					"C -> t B b #"};
*/

string str[GRAMMAR_RULE] = {"X -> Y Z #",
"X -> F Q P z #",
"Y -> U B i S O F T #",
"Z -> W W #",
"A -> B C Q q r #",
"B -> C U P #",
"C -> S T O R E #",
"C -> k C #",
"U -> V W #",
"V -> W #",
"W -> X #",
"D -> R E A D #",
"E -> H j #",
"F -> F A I R #",
"R -> A R A R A t #",
"S -> Y X A #",
"T -> S D d #",
"G -> H Q #",
"H -> I R I B #",
"I -> A B C D E F G H I j k l m n O P Q R S T U V W X Y Z #",
"O -> Z Y X W V U T S R Q P O n m l k j I H G F E D C B A #",
"P -> I R Q #",
"Q -> C S E #"};

/*
//14
string str[GRAMMAR_RULE] =	{"S -> A B e F D #",
"S -> B C d E F #",
"A -> A a B #",
"A -> A A b B #",
"A -> #",
"B -> C A #",
"B -> c a a a a C b b b b A #",
"C -> #",
"C -> C c C #",
"C -> E B #",
"D -> E F #",
"E -> F E #",
"F -> D z D #",
"F -> C C #"};
*/
	cout<<"Input grammar:"<<endl;
	for(int i = 0 ; i < GRAMMAR_RULE ; i++)
	{
		cout<<str[i]<<endl;
	}
	cout<<"Grammar breakup:"<<endl;
	list<string> non_terminal;	
	list<string> terminal;
	string tokenx;
	for(int i = 0 ; i < GRAMMAR_RULE ; i++)
	{
		size_t pos = str[i].find("->");
		tokenx = trim(str[i].substr(0,pos));
		non_terminal.push_back(tokenx);
		cout<<"RHS = "<<str[i].substr(0,pos)<<"\t";
		string strX = str[i].substr(pos);
		string strY = strX.erase(0,3);
		
		cout<<"LHS = ";

		string s = strY;
		string delimiter = " ";

		size_t posX = 0;
		string token;
		while ((posX = s.find(delimiter)) != string::npos) {
		    token = trim(s.substr(0, posX));
		    cout << token << "\t";
			terminal.push_back(token);
		    s.erase(0, posX + delimiter.length());
			}
		std::cout << s << std::endl;
	}
	cout<<endl;

	list<string> master_list;
	
	
	list<string>::iterator it_T;

	cout<<"Terminal:-"<<endl;
	for(it_T = terminal.begin(); it_T != terminal.end(); it_T++)
	{
		cout<<*it_T<<"\t";
		master_list.push_back(*it_T);
	}

		cout<<endl;
		cout<<endl;
	
			
	list<string>::iterator it_NT;
	bool flag = true;
	string starting_symbol;
	cout<<"Non Terminal:-"<<endl;
	for(it_NT = non_terminal.begin(); it_NT != non_terminal.end(); it_NT++)
	{
		cout<<*it_NT<<"\t";
		if(flag == true)
		{
			starting_symbol = *it_NT;
			flag = false;
		}
		master_list.push_back(*it_NT);
	}

	
	cout<<endl;
	cout<<"----starting symbol------"<<starting_symbol<<endl;
			cout<<endl;
	
	
	list<string>::iterator it_ML;
	cout<<"Master List:-"<<endl;
	for(it_ML = master_list.begin(); it_ML != master_list.end(); it_ML++)
	{
		cout<<*it_ML<<"\t";
	}
	cout<<endl;
	cout<<endl;
	cout<<"Creation of Main List starts::Computation"<<endl<<endl;
	
	list<string> main_list;
	cout<<"Handling Terminals"<<endl;
	string temp;
	for(it_T = terminal.begin(); it_T != terminal.end(); it_T++)
	{
		for(it_ML = master_list.begin(); it_ML != master_list.end(); it_ML++)
		{
			if(*it_T == *it_ML)
			{	
				cout<<*it_T<<"\t";
				temp = *it_T;
				main_list.push_back(temp);
				break;
				
			}
			
		}
	master_list.remove(temp);
	}
	cout<<endl;
	cout<<"Master List after removing Terminals"<<endl;
	for(it_ML = master_list.begin(); it_ML != master_list.end(); it_ML++)
	{
		cout<<*it_ML<<"\t";
	}
	cout<<endl;
	cout<<"Handling Non Terminals"<<endl;
	for(it_NT = non_terminal.begin(); it_NT != non_terminal.end(); it_NT++)
	{
		for(it_ML = master_list.begin(); it_ML != master_list.end(); it_ML++)
		{
			if(*it_NT == *it_ML)
			{	
				cout<<*it_NT<<"\t";
				temp = *it_NT;
				main_list.push_back(temp);
				break;
			}
		
		}
	master_list.remove(temp);	
	}
	cout<<endl;
	cout<<"Master List after removing Non Terminals"<<endl;
	for(it_ML = master_list.begin(); it_ML != master_list.end(); it_ML++)
	{
		cout<<*it_ML<<"\t";
	}
	cout<<endl;
	cout<<endl;
	cout<<"Main List :-"<<endl;
	list<string>::iterator it_MaL;
	for(it_MaL = main_list.begin(); it_MaL != main_list.end(); it_MaL++)
	{
		cout<<*it_MaL<<"\t";
	}

	list<string> helper_list;
	
	string tingu_temp;
	for(it_NT = non_terminal.begin(); it_NT != non_terminal.end(); it_NT++)
	{
		//cout<<*it_NT<<"\t";
		for(it_MaL = main_list.begin(); it_MaL != main_list.end(); it_MaL++)
		{		
			if(*it_NT == *it_MaL)
			{
				tingu_temp = *it_MaL;
				cout<<endl;
				helper_list.push_back(tingu_temp);
				cout<<"-------------------"<<endl;
				cout<<tingu_temp<<endl;
				cout<<"-------------------"<<endl;
				break;
			}
		}
		main_list.remove(tingu_temp);
	}
	cout<<endl;
	cout<<endl;
	cout<<"The final Non terminal list out of Main List"<<endl;
	list<string>::iterator ith;
	for(ith = helper_list.begin();ith != helper_list.end(); ith++)
	{
		cout<<*ith<<"\t";
	}
	cout<<endl;
	cout<<endl;
	cout<<"The final Main List after removal of non terminal"<<endl;
	for(it_MaL = main_list.begin(); it_MaL != main_list.end(); it_MaL++)
	{
		cout<<*it_MaL<<"\t";
	}
	cout<<endl;
	cout<<endl;
	/*
	cout<<"The final required list"<<endl;
	//main_list.merge(helper_list);//can't do a merge as it automatically sorts
	//for(it_MaL = main_list.begin(); it_MaL != main_list.end(); it_MaL++)
	{
		//cout<<*it_MaL<<"\t";
	}
	cout<<endl;
	cout<<endl;
	for(ith = helper_list.begin(); ith != helper_list.end(); ith++)
	{
		//cout<<*it_MaL<<"\t";
		//main_list.push_back(*ith);
	}
	cout<<endl;
	cout<<endl;
	for(it_MaL = main_list.begin(); it_MaL != main_list.end(); it_MaL++)
	{
		cout<<*it_MaL<<"\t";
	}
	cout<<endl;
	cout<<endl;
*/
	//pick the non-terminals out of terminals

	//again a flop idea
	/*cout<<"finding non-terminals sequentially"<<endl;

	list<string> NT_out_T;

	for(it_T = terminal.begin(); it_T != terminal.end(); it_T++)
	{
		//cout<<*it_T<<"\t";
		for(it_NT = non_terminal.begin(); it_NT != non_terminal.end(); it_NT++)
		{
				//cout<<*it_NT<<"\t";
				if(*it_T == *it_NT)
				{
					cout<<*it_T<<"\t";
					NT_out_T.push_back(*it_T);
					break;
				}
		}

	}

	cout<<endl;
	cout<<endl;
	cout<<"making out final non-terminal list:"<<endl;

	list<string> NT_out_T_Y(NT_out_T);
	list<string> final_non_terminal;

	list<string>::iterator it_NT_out_T;
	list<string>::iterator it_NT_out_T_Y;
	list<string>::iterator it_f_NT;
*/
	/*cout<<"just to check baba"<<NT_out_T_Y.size()<<endl;
	for(it_NT_out_T_Y = NT_out_T_Y.begin();it_NT_out_T_Y != NT_out_T_Y.end();it_NT_out_T_Y++)
	{
		cout<<*it_NT_out_T_Y<<"\t";
	}
	*/
	/*cout<<endl;

	string del_str;

	for(it_NT_out_T = NT_out_T.begin();it_NT_out_T != NT_out_T.end();it_NT_out_T++)
	{
		for(it_NT_out_T_Y = NT_out_T_Y.begin();it_NT_out_T_Y != NT_out_T_Y.end();it_NT_out_T_Y++)
		{
				if(*it_NT_out_T_Y == *it_NT_out_T)
				{
					cout<<*it_NT_out_T<<"\t";
					del_str = *it_NT_out_T;
					final_non_terminal.push_back(del_str);
					break;
				}

		}
		NT_out_T_Y.remove(del_str);
	}
	cout<<endl<<endl;
	cout<<"The final non terminal list goes here:"<<endl;
	for(it_f_NT = final_non_terminal.begin();it_f_NT != final_non_terminal.end();it_f_NT++)
	{
		cout<<*it_f_NT<<"\t";
	}

	cout<<endl;

	cout<<"here it goes "<<endl;
	main_list.push_back(starting_symbol);
	for(it_f_NT = final_non_terminal.begin();it_f_NT != final_non_terminal.end();it_f_NT++)
	{
		//cout<<*it_f_NT<<"\t";
		main_list.push_back(*it_f_NT);
	}

	for(it_MaL = main_list.begin(); it_MaL != main_list.end(); it_MaL++)
	{
		cout<<*it_MaL<<"\t";
	}
	cout<<endl;
	*/
}
