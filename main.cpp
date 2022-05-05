/*
		Language syntax
		
		defintition
		type name = value :
		
		operators 
		name = name + second_name :
		print syntax
		print = name :
		
		condition_check
		ifn = name > second_name :
		print = second_name :
		endl :
		
		loop operation
		yet = name > second_name :
		print = a :
		name = name - second_name :
		endl :
		
		printer
		print = name :
		*/
#include <iostream>
#include <fstream>
#include <vector>
const std::string types[] = {"num" , "grs"};
const int SIZE = 3;
const int probels_count = 6;
bool test = true;
bool tester = false;

struct Integers
{
        std::string name;
        double value;
};

struct Words
{
        std::string name;
        std::string value;
};

std::string first_name_founder(std::string line);
void creater_Integers(Integers Description , std::string line);
double do_operation(std::string line , char sim);
void creater_grs(Words Desc , std::string line);
void printer(std::string name , std::string line);
void condition_check(std::string line);
void error_function(std::string line , int line_counter);

std::vector <Integers> num;
std::vector <Words> grs;

int main()
{
	Integers Description;
	Words Desc;
	std::string line{};
	int line_yet = 0;
	int line_counter = 0;
	std::string txt_file_name{};
	std::cout << "Please enter your txt file name : ";
	std::cin >> txt_file_name{};
	std::ifstream fin(txt_file_name);
	if(!fin.is_open())
	{
		std::cout << "file isn't open";
		exit(0);
	}
	while(!fin.eof())
	{
	   
	    std::getline(fin , line);
	    
	    ++line_counter;
	    if(first_name_founder(line) == "endl" && !tester)
	    {
	        test = true;
	    }
		else if(first_name_founder(line) == "endl" && tester)
		{
		    line_counter = line_yet;
		    fin.close();
		    fin.open("text.txt");
		    std::string str = {};
		    for(int a = 0 ; a < line_yet ; a++)
		    {
		        std::getline(fin , str);
		    }
		    line = str;
		}
		if(first_name_founder(line) == "ifn")
		{
			condition_check(line);
		}
		
		if(first_name_founder(line) == "yet")
		{
		    line_yet = line_counter;
		    for(char c : line)
		    {
		        if(c == '&' || c == '|' || c == '~' || c == '>' || c == '<')
		        {
		            tester = do_operation(line , c);
			    test = tester ;
		        }
		    }
		}
		
		else if(first_name_founder(line) == "exit")
		{
			if(!test)
			{
				test = !test;
			}
		}
	  
	
        if(test)
        {
	    if(line.substr(0 , SIZE) == "num")
        {
                	creater_Integers(Description , line);	
		}
		else if(line.substr(0 , SIZE) == "grs")
		{
			creater_grs(Desc , line);
		}
		
		else if(line.substr(0 , SIZE) != "grs" && line.substr(0 , SIZE) != "num")
 		{
			if(first_name_founder(line) == "print")
			{
				printer(first_name_founder(line) , line);
			}	
			for(char c : line)
			{
				if(c == '+' || c == '-' || c == '*' || c == '/' || c == '&' || c == '|' || c == '~' || c == '>' || c == '<')
				{
					if(c == '+')
					{
						for(int n = 0 ; n < grs.size() ; n++)
						{
							if(grs[n].name == line.substr(0,grs[n].name.length()))
							{
								do_operation(line , c);	
							}
						}
					}
					for(int n = 0 ; n < num.size() ; ++n)
					{
						if(num[n].name == line.substr(0,num[n].name.length()))
						{
							num[n].value = do_operation(line , c);
						}
					}
						
						
				}
			}
		}
		void error_function(line , line_counter);
	   
	}
	}
	fin.close();
}
	void creater_Integers(Integers Description , std::string line)
	{
		int j = 4;
                std::string Value;
                std::string Name;
                while(j > SIZE && line[j] != ' ')
                {
                        Name += line[j];
                        ++j;
                }
		for(int a = 0 ; a < line.length() ; ++a)
                {
                	if(line[a] >= '0' && line[a] <= '9')
                        {
                        	Value += line[a];
                        }
               	}
                Description.name = Name;
               	Description.value = (stoi(Value));
                num.push_back(Description);
	}
	void creater_grs(Words Desc , std::string line)
	{
		int j = 4;
		std::string Second_Value;
		std::string Name;
	while(j > SIZE && line[j] != ' ')
                {
                        Name += line[j];
                        ++j;
                }
		for(int a = 0 ; a < line.length() ; ++a)
                {
			if(line[a] == '=')
                        {
                        	int c = a + 2;
                                while(line[c] != ' ')
                                {
                                	Second_Value += line[c];
                                        ++c;
                               	}
			}
               	}
                        Desc.name = Name;
                        Desc.value = Second_Value;
                        grs.push_back(Desc);
	}
 	double do_operation(std::string line , char sim)
 	{
		int count = 0;
		int h = 0;
		int first_element = 0;
		int second_element = 1;
		int arr[SIZE];
		std::string str_arr[SIZE];
		int i = 0;
		std::string second_name{};
		std::string name;
		name = first_name_founder(line);
		i = 1;
		for(int a = 0 ; a < num.size() ; ++a)
		{
			if(line.substr(name.length() + SIZE , num[a].name.length()) == num[a].name)
			{
				arr[count] = num[a].value;
				second_name = num[a].name;
				++count;
				break;
			}
		}
			if(second_name.length() == 0)
			{
			        for(int a = name.length() + SIZE ; line[a] != ' ' ; ++a)
			        {
			             second_name += line[a];
			        }
			        arr[count] = stod(second_name);
			        ++count;
			       
			}
			
		for(int a = 0 ; a < num.size() ; ++a)
		{
			if(line.substr(name.length() + second_name.length() + probels_count , num[a].name.length()) == num[a].name)
			{
				arr[count] = num[a].value;
				second_name = num[a].name;
				++count;
				break;
			}
		}
		
		if(second_name.length() == 0)
		{
			for(int a = name.length() + h + probels_count + SIZE - 1; line[a] != ' ' ; ++a)
			{
				second_name += line[a];
			}
			arr[count] = stod(second_name);
			
			   ++i;
		
		}
		for(int a = 0 ; a < grs.size() ; ++a)
                {
                        if(line.substr(name.length() + SIZE , grs[a].name.length()) == grs[a].name)
                        {
                                str_arr[count] = grs[a].value;
                                second_name = grs[a].name;
                                ++count;
                                break;
                        }
                }
		
		
		for(int a = 0 ; a < grs.size() ; ++a)
                {
                        if(line.substr(name.length() + second_name.length() + probels_count , grs[a].name.length()) == grs[a].name)
                        {
                                str_arr[i] = grs[a].value;
                                second_name = grs[a].name;
                                ++i;
                                break;
                        }
                }
		for(int a = 0 ; a < num.size() ; ++a)
		{
			
			
				switch(sim)
				{
					case '+' : return arr[first_element] + arr[second_element] ;
					case '-' : return arr[first_element] - arr[second_element] ;
					case '*' : return arr[first_element] * arr[second_element] ;
					case '/' : return arr[first_element] / arr[second_element] ;
					case '~' : return arr[first_element] == arr[second_element] ;
                    			case '<' : return arr[first_element] < arr[second_element] ;
                    			case '>' : return arr[first_element] > arr[second_element] ;
                    			case '&' : return arr[first_element] && arr[second_element] ;
					case '|' : return arr[first_element] || arr[second_element] ;
					case '[' : return arr[first_element] >= arr[second_element] ;
					case ']' : return arr[first_element] <= arr[second_element] ;
				}
		}
	}
	std::string first_name_founder(std::string line)
	{
		std::string name;
		int i = 0;
		while(line[i] != ' ')
                {
                        name += line[i];
                        ++i;
                }
	 	return name;
	}
	void printer(std::string name , std::string line)
	{
		bool print_tester = false;
		for(int a = 0 ; a < num.size() ; ++a)
        	{
        		if(line.substr(name.length() + SIZE , num[a].name.length()) == num[a].name)
                	{
                		std::cout << num[a].value;
                       	 	break;
			}
       	 	}
		for(int a = 0 ; a < grs.size() ; ++a)
		{
			if(line.substr(name.length() + SIZE , grs[a].name.length()) == grs[a].name)
			{
				std::cout << grs[a].value;
				break;
			}			
		}
		
		if(!print_tester)
                {
                        std::string printer{};
                        for(int i = first_name_founder(line).length() + SIZE ; line[i] != ' ' ; ++i )
                        {
                                printer += line[i];
                        }
                        	std::cout << printer;
                }

	}
	
	void condition_check(std::string line)
	{
		for(char c : line)
		{
		    if(c == '&' || c == '|' || c == '~' || c == '>' || c == '<')
		    {
		       test = do_operation(line , c);
		    }
		}
	}
	
	void error_function(std::string line , int line_counter)
        {
                bool line_tester = false;
                for(int i = 0 ; i < num.size() ; ++i)
                {  
                   if(first_name_founder(line) == num[i].name || first_name_founder(line) == "grs" || first_name_founder(line) == "num")
                   {    
                        line_tester = true;
                   }
                }
                for(int i = 0 ; i < grs.size() ; ++i)
                {
                        if(first_name_founder(line) == grs[i].name)
                        {
                                line_tester = true;
                        }
                }
                for(int i = 0 ; i < Keywords_Size ; ++i)
                {
                        if(first_name_founder(line) == key_words[i])
                        {
                                line_tester = true;
                        }
                }
                if(line.length() == 0)
                {
                        line_tester = true;
                }
                if(line.length() == 0)
                {
                        line_tester = true;
                }

                if(!line_tester)
                {
                        std::cout << "in " << line_counter << " line is unknown word ";
                        exit(0);
                }

        }


	
