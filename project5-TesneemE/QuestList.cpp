//
//  QuestList.cpp
//  p5_235
//
//  Created by Tesneem Essa on 10/30/23.
//Defines the public interface of class QuestList, a subclass of DoublyLinkedList which holds Quest pointers

#include "QuestList.hpp"
/**
    Default Constructor
*/
QuestList::QuestList()
{
    Quest();
}

/**
    @param: a reference to string name of an input file
    @pre: Formatting of the csv file is as follows:
        Title: A string
        Description: A string
        Completion Status: 0 (False) or 1 (True)
        Experience Points: A non negative integer
        Dependencies: A list of Quest titles of the form [QUEST1];[QUEST2], where each quest is separated by a semicolon. The value may be NONE.
        Subquests: A list of Quest titles of the form [QUEST1];[QUEST2], where each quest is separated by a semicolon. The value may be NONE.
    Notes:
        - The first line of the input file is a header and should be ignored.
        - The dependencies and subquests are separated by a semicolon and may be NONE.
        - The dependencies and subquests may be in any order.
        - If any of the dependencies or subquests are not in the list, they should be created as new quests with the following information:
            - Title: The title of the quest
            - Description: "NOT DISCOVERED"
            - Completion Status: False
            - Experience Points: 0
            - Dependencies: An empty vector
            - Subquests: An empty vector
        - However, if you eventually encounter a quest that matches one of the "NOT DISCOVERED" quests while parsing the file, you should update all the quest details.
        Hint: update as needed using addQuest()
        

    @post: Each line of the input file corresponds to a quest to be added to the list. No duplicates are allowed.

*/
QuestList::QuestList(string file_name)
{
    //create vectors for each item
    //then parse through and see if those items are there
    string title,description,complete,dependencies,subquests;
    ifstream fin(file_name);
    if (fin.fail()) {   //checks if file opens
        cerr << "File cannot be opened for reading." << endl;
        exit(1);
    }
    
    string line;  //declares string line
    vector<string> store_lines;  //declares vector to store lines
    
    // Read and ignore the header line
    getline(fin, line);
    
    while (getline(fin, line)) {
        istringstream iss(line);  //parses through contents of line
        string store_line;  //has lines extracted from string line
        
        while (getline(iss, store_line, '\t')) {   //splits the line by tab
            store_lines.push_back(store_line);  //stores lines in vector store_lines
        }
        vector<string> lines;  //creates new vector to store each line sep by the comma
        string full_line;  //the full line
        string sep_line; //the line sep by comma
        int comma;
        full_line=store_lines[0];  //gets first item in store_lines vector
        for(int i=0;i<6;i++) //for each column, finds comma, separates line by comma, stores that line into lines vector, and then makes full_line == the rest of the line
        {
            comma=full_line.find(",");
            sep_line=full_line.substr(0,comma);
            lines.push_back(sep_line);
            full_line=full_line.substr(comma+1);
        }
        int exp_num=0;
        title=lines[0];
        description=lines[1];
        bool complete_value = (lines[2] == "1");
        exp_num=stoi(lines[3]);
        dependencies=lines[4];
        subquests=full_line;
        subquests.erase(std::remove(subquests.begin(),subquests.end(),'\r'),subquests.end()); //removes \r char in subquests string
        vector<Quest*> dependencies_vector;  //creates empty dependencies and subquests vector
        vector<Quest*> subquests_vector;
        Quest* new_quest=nullptr;  //initalizes Quest pointer new_quest + sets it equal to     nullptr
        if(dependencies!="NONE")
        {
            vector<string> dependencies_sep;//declare dependencies_sep string vector
            int start=0; //to keep track of where the substring will start from
            for(int i=0;i<dependencies.length();i++)  //until loop reaches last letter of word
            {
                if(dependencies[i]==';')  //sep dependencies line by ';'
                {
                    string sub=dependencies.substr(start,i-start);  //sets string sub equal to sub string of dependencies that goes from the start pos to the index before ';' was found
                    dependencies_sep.push_back(sub);  //adds string sub to dependencies_sep vector
                    start=i+1;  //change starting position to index after ';' was found
                }
            }
            dependencies_sep.push_back(dependencies.substr(start));//the remaining substring is then added to the dependencies_sep vector as well
            for(int i=0;i<dependencies_sep.size();i++)
            {
                if(contains(dependencies_sep[i])) //if already in QuestList, add the item in the list to dependencies_vector
                {
                   dependencies_vector.push_back(getItem(getPosOf(dependencies_sep[i])));
                }
                else //if not create new subquest of the same title with zero values, add it to the QuestList and then to the dependencies_vector
                {
                    Quest* new_dependencies=nullptr;
                    new_dependencies=new Quest{dependencies_sep[i],"NOT DISCOVERED",false,0,{},{}};
                    addQuest(new_dependencies);
                    dependencies_vector.push_back(new_dependencies);
                }
            }
        }
        if(subquests!="NONE")
        {
            vector<string> subquests_sep;//declare subquests_sep string vector
            int start=0; //to keep track of where the substring will start from
            for(int i=0;i<subquests.length();i++)  //until loop reaches last letter of word
            {
                if(subquests[i]==';')  //sep subquests line by ';'
                {
                    string sub=subquests.substr(start,i-start);  //sets string sub equal to sub string of subquests that goes from the start pos to the index before ';' was found
                    subquests_sep.push_back(sub);  //adds string sub to subquests_sep vector
                    start=i+1;  //change starting position to index after ';' was found
                }
            }
            subquests_sep.push_back(subquests.substr(start));//the remaining substring is then                                             added to the vector as well
            for(int i=0;i<subquests_sep.size();i++)
            {
                if(contains(subquests_sep[i])) //if already in QuestList, add the item in the list to subquests_vector
                {
                   subquests_vector.push_back(getItem(getPosOf(subquests_sep[i])));
                }
                else   //if not create new subquest of the same title with zero values, add it to the QuestList and then to the subquests_vector
                {
                    Quest* new_subquests=nullptr;
                    new_subquests=new Quest{subquests_sep[i],"NOT DISCOVERED",false,0,{},{}};
                    addQuest(new_subquests);
                    subquests_vector.push_back(new_subquests);
                }
            }
        }
        new_quest=new Quest{title,description,complete_value,exp_num,dependencies_vector,subquests_vector};
        //intializes Quest object w/ values from csv file
        if(new_quest!=nullptr)
        {
            addQuest(new_quest);  //adds new_quest to QuestList
        }
        store_lines.clear(); // clears the vector for the next row
    }
    
    fin.close();   //closes file
}

/**
    @param: A string reference to a quest title
    @return: The integer position of the given quest if it is in the QuestList, -1 if not found.
*/
int QuestList::getPosOf(const string& title) const //iterate w/ pointers from headPointer
{
    for(int i=0;i<item_count_;i++)
    {
        if(getItem(i)->title_==title)
        {
            return i;
        }
    }
    return -1;
}

/**
    @param: A string reference to a quest title
    @return: True if the quest with the given title is already in the QuestList
*/
bool QuestList::contains(const string& title) const
{
    for(int i=0;i<item_count_;i++)
    {
        if(getItem(i)->title_==title)
        {
            return true;
        }
    }
    return false;
}

/**
    @pre: The given quest is not already in the QuestList
    @param:  A pointer to a Quest object
    @post:  Inserts the given quest pointer into the QuestList. Each of its dependencies and subquests are also added to the QuestList IF not already in the list.
            If the quest is already in the list but is marked as "NOT DISCOVERED", update its details. (This happens when a quest has been added to the list through a dependency or subquest list)
           
    @return: True if the quest was added successfully, False otherwise
*/
bool QuestList::addQuest(Quest* quest)  //if you're updating do you still return true
{
    bool check_in=false;   //to check if it's in the list already
    bool check_added=false;  // to check if its added or its details were updated
    for(int i=0;i<item_count_;i++)
    {
        if(getItem(i)->title_==quest->title_)
        {
            check_in=true;
            if(getItem(i)->description_=="NOT DISCOVERED")
            {
                getItem(i)->description_=quest->description_;  //copies details of given quest to the quest pointer in the list with the same title_
                getItem(i)->completed_=quest->completed_;
                getItem(i)->experience_points_=quest->experience_points_;
                getItem(i)->dependencies_=quest->dependencies_;
                getItem(i)->subquests_=quest->subquests_;
                check_added=true;
            }
        }
    }
    if(!check_in) //if not in list insert quest at the next index in list, item_count_
    {
        insert(item_count_,quest);
        check_added=true;
    }
    return check_added;
}

/**
    @param:  A reference to string representing the quest title
    @param:  A reference to string representing the quest description
    @param:  A reference to boolean representing if the quest is completed
    @param:  An reference to int representing experience points the quest rewards upon completion
    @param:  A reference to vector of Quest pointers representing the quest's dependencies
    @param:  A reference to vector of Quest pointers representing the quest's subquests
    @post:   Creates a new Quest object and inserts a pointer to it into the QuestList.
             If the quest is already in the list but is marked as "NOT DISCOVERED", update its details. (This happens when a quest has been added to the list through a dependency or subquest list)
             Each of its dependencies and subquests are also added to the QuestList IF not already in the list.
             

    @return: True if the quest was added successfully

*/
bool QuestList::addQuest(const string& title, const string& description, const bool& complete, const int& exp, const vector<Quest*>& dependencies, const vector<Quest*>& subquests)
{
    Quest* new_quest=nullptr;
    new_quest=new Quest{title,description,complete,exp,dependencies,subquests};
    for(int i=0;i<dependencies.size();i++)
    {
        addQuest(dependencies[i]);  //adds dependencies to list
    }
    for(int i=0;i<subquests.size();i++)
    {
        addQuest(subquests[i]);  //adds subquests to list
    }
   return addQuest(new_quest);  //makes sure quest is added
    
}

/**
    @param:  A Quest pointer
    @return: A boolean indicating if all the given quest's dependencies are completed
*/
bool QuestList::dependenciesComplete(Quest* quest)
{
    for(int i=0;i<quest->dependencies_.size();i++)
    {
        if(quest->dependencies_[i]->completed_==false)
        {
            return false;  //if one dependency is incomplete, returns false immediately
        }
    }
    return true;
}

/**
    @param: A Quest pointer
    @return: A boolean if the given quest is available.
    Note: For a quest to be available, it must not be completed, and its dependencies must be complete.
*/
bool QuestList::questAvailable(Quest* quest)
{
    if(dependenciesComplete(quest))
    {
        if(quest->completed_==false)
        {
            return true;
        }
    }
    return false;
}

/**
    @param: A Quest pointer
    @post: Prints the quest title and completion status
    The output should be of the form:
    [Quest Title]: [Complete / Not Complete]
    [Quest Description]\n\n
*/
void QuestList::printQuest(Quest* quest)
{
    cout<<quest->title_<<": "<< (quest->completed_ ? "Complete" : "Not Complete")<<"\n"<<quest->description_<<"\n\n";
}

/**
    @param: A Quest pointer
    @post: Prints the quest title and indents accordingly for questQuery
*/
void QuestList::questRecursive(Quest* item)
{
    string query="";  //in order to print recursively, create string query and add to the string as the function runs so as to print in correct order
    if(item->completed_==false)
    {
        if(dependenciesComplete(item))  //if the quest's dependencies are complete and the quest is                                 not complete, prints Ready: and the quest's title
        {
            if(item->completed_==false)
            {
                query+="Ready: ";
                query+=item->title_;
                query+="\n";
            }
        }
        else                                        //if the item isn't complete and its dependencies are not completed either, then it is printed without the Ready: and indented and it's dependencies are also called by the function
        {
            query+="  ";
            if(item->completed_==false)
            {
                query+=item->title_;
                query+="\n";
                for(int i=0;i<item->dependencies_.size();i++)
                {
                    questRecursive(item->dependencies_[i]);
                    
                }
            }
        }
    }
    cout<<query;
}

/**
    @param: A string reference to a quest title
    @post:  Prints a list of quests that must to be completed before the given quest can be started (incomplete dependencies).
            If any of the quest's incomplete dependencies have an incomplete dependency, recursively print the quests that need to be done in order, indenting incomplete quests.
            The indentation for incomplete quests is 2 spaces: "  "
            The format of the list should be of the following forms for each different case:

            Query: [Quest Title]
            No such quest.
    
            Query: [Quest Title]
            Quest Complete
    
            Query: [Quest Title]
            Ready: [Quest Title]
    
            Query: [Quest Title]
            Ready: [Dependency0]
              [Quest Title]
            
            Query: [Quest Title]
            Ready: [Dependency0]
            Ready: [Dependency1]
              [Quest Title]
    
            Query: [Quest Title]
            Ready: [Dependency0]
            Ready: [Dependency1]
              [Dependency2]
              [Quest Title]
              
     If the given quest title is not found in the list, print "No such quest."
*/
void QuestList::questQuery(const string& title)
{
    cout<<"Query: "<<title<<"\n";
    if(!contains(title))
    {
        cout<<"No such quest."<<"\n";
    }
    else
    {
        int pos= getPosOf(title);
        Quest* item=getItem(pos);
        if(item->completed_==true)
        {
            cout<<"Quest Complete"<<"\n";
        }
       else
       {
           questRecursive(item);
       }
    }
}
        
/**
    @return: An integer sum of all the experience gained
    Note: This should only include experience from completed quests
*/
int QuestList::calculateGainedExperience()
{
    int sum=0;
    for(int i=0;i<item_count_;i++)
    {
        if(getItem(i)->completed_==true)
        {
            sum+=getItem(i)->experience_points_;
        }
    }
    return sum;
}

/**
    @param: A quest pointer to a main quest
    @return: An integer sum of all the experience that can be gained from completing the main quest AND all its subquests.
    Note: Also consider the potential experience if a subquest itself has subquests.
*/
int QuestList::calculateProjectedExperience(Quest* main_quest)
{
    int sum=0;
    sum+=main_quest->experience_points_;
    for(int i=0;i<main_quest->subquests_.size();i++)
    {
        sum+=calculateProjectedExperience(main_quest->subquests_[i]);
    }
    return sum;
}

///**
//    @param: A quest pointer to a main quest
//    @return: An integer sum of all the experience that has already been gained by completing the given quest's subquests.
//    Note: Also consider the experience gained if a completed subquest itself has subquests.
//*/
int QuestList::calculatePathwayExperience(Quest* main_quest)
{
    int sum=0;
    for(int i=0;i<main_quest->subquests_.size();i++) //loops through subquests of main_quest and adds exp value
    {
        sum+=main_quest->subquests_[i]->experience_points_;
        if(main_quest->subquests_[i]->completed_)
        {
            sum+=calculatePathwayExperience(main_quest->subquests_[i]);  //if subquest is completed adds the exp value of its subquests
            
        }
    }
    return sum;
}

/**
    @param: A string reference to a filter with a default value of "NONE".
    @post: With default filter "NONE": Print out every quest in the list.
           With filter "COMPLETE":   Only print out the completed quests in the list.
           With filter "INCOMPLETE": Only print out the incomplete quests in the list.
           With filter "AVAILABLE":  Only print out the available quests in the list.
           If an invalid filter is passed, print "Invalid Filter\n"
    Printing quests should be of the form:
    [Quest title]: [Complete / Not Complete]
    [Quest description]\n
*/
void QuestList::questHistory(const string& filter)
{
    if(filter=="NONE")
    {
        for(int i=0;i<item_count_;i++)
        {
            printQuest(getItem(i));
        }
    }
    else if(filter=="INCOMPLETE")
    {
        for(int i=0;i<item_count_;i++)
        {
            if(getItem(i)->completed_==false)
            {
                printQuest(getItem(i));
            }
        }
    }
    else if(filter=="AVAILABLE")
    {
        for(int i=0;i<item_count_;i++)
        {
            if(questAvailable(getItem(i)))
            {
                printQuest(getItem(i));
            }
        }

    }
    else
    {
        cout<<"Invalid Filter"<<"\n";
    }
        
}

/**
    @param: A quest pointer to a main quest, an int value spaces
    @post:  Outputs subquest pathway. Print quest names with two spaces ("  ") of indentation for each subquest, recursively.
            Also print the percentage of experience gained in this pathway, rounded down to the lower integer.
            The format should be of the form:
            [Main Quest] ([Pathway XP] / [Projected XP]% Complete)
                [Subquest0]: [Complete / Not Complete]
                    [Sub-Subquest01]: [Complete / Not Complete]
                        [Sub-Subquest011]: [Complete / Not Complete]
                    [Subquest02]: [Complete / Not Complete]
            Hint: You can write a helper function to print the subquests recursively. If the given quest is already marked as completed, you can assume that all of its subquests are also completed.
*/
void printQuestRecursively(Quest* quest, int spaces)
{
    for(int i=0;i<spaces;i++) //prints out two spaces according to spaces int, which is determined by how many subquests a quest has
    {
        cout<<"  ";
    }
    cout<<"  "<<quest->title_<<": "<<(quest->completed_ ? "Complete" : "Not Complete")<<"\n";
    for(int i=0;i<quest->subquests_.size();i++)   //checks if the subquests have their own subquests and prints accordingly
    {
        cout<<"  ";
        printQuestRecursively(quest->subquests_[i],spaces);
    }
}

/**
    @param: A quest pointer to a main quest
    @post:  Outputs subquest pathway. Print quest names with two spaces ("  ") of indentation for each subquest, recursively.
            Also print the percentage of experience gained in this pathway, rounded down to the lower integer.
            The format should be of the form:
            [Main Quest] ([Pathway XP] / [Projected XP]% Complete)
                [Subquest0]: [Complete / Not Complete]
                    [Sub-Subquest01]: [Complete / Not Complete]
                        [Sub-Subquest011]: [Complete / Not Complete]
                    [Subquest02]: [Complete / Not Complete]
            Hint: You can write a helper function to print the subquests recursively. If the given quest is already marked as completed, you can assume that all of its subquests are also completed.
*/
void QuestList::printQuestDetails(Quest* main_quest)
{
    float a=calculatePathwayExperience(main_quest);
    float b=calculateProjectedExperience(main_quest);
    float num=(a/b)*100;
    cout<<main_quest->title_<<" ("<<num<<"% Complete)"<<"\n";
    int spaces=0;  //to be used to determine how many spaces before each line
    for(int i=0;i<main_quest->subquests_.size();i++)
    {
        printQuestRecursively(main_quest->subquests_[i], spaces);
        spaces++;
    }
}
