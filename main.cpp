// ============================================================================
// File: main.cpp (Spring 2018)
// ============================================================================
// Programmer: Jennifer King
// Project: Linked List Insert
// Date: 2/28/2018
// Professor: Scott Edwards
// Class: CSCI 133F | TR 4:30PM
// Description:
//              This program allows the user to insert integer values into a list,
//              using zero-based indexes to specify the target location of the inserted
//              item (e.g.,the first item is at location zero, the next at location 1,
//              etc., just like an array). At any point the user can display the
//              contents of the list to stdout. There is no support for removing items
//              from the list or releasing heap memory.
// ============================================================================

#include    <iostream>
#include    <cstdlib>
#include    <cstdio>
#include    <cctype>
using namespace std;


// linked list structure
struct  LNode
{
    int         item;
    LNode       *next;
};


// function prototypes
int     DisplayList(const LNode  *head);
void    DisplayMenu();
void    FlushInstream(istream  &inStream = cin);
LNode*  InsertItem(LNode  *head, int  index, int  item, bool  &bSuccess);


// ==== main ==================================================================
//
// ============================================================================

int     main()
{
    bool            bLoop = true;
    bool            bResult;
    char            selection;
    int             index;
    int             intVal;
    int             numInts = 0;
    LNode           *headPtr = NULL;

	// allow the user to manipulate the list
    do  {
        // display the main menu
        DisplayMenu();

        // get the user selection
        cout << "\nPlease enter your selection: ";
        cin >> selection;

        // call the appropriate member function
        switch (toupper(selection))
            {
            case  'A':
                // get a new integer value to insert
                cout << "Please enter a value to insert: ";
                if (!(cin >> intVal))
                    {
                    cout << "Error reading int, please try again...\n";
                    FlushInstream();
                    continue;
                    }

                // get an index
                cout << "Please enter a target index: ";
                if (!(cin >> index))
                    {
                    cout << "Error reading int, please try again...\n";
                    FlushInstream();
                    }
                else if ((index > numInts) || (index < 0))
                    {
                    cout << "Index is out of range...\n";
                    continue;
                    }
                else
                    {
                    headPtr = InsertItem(headPtr, index, intVal, bResult);
                    if (false == bResult)
                        {
                        cout << "Sorry, insertion failed...\n";
                        }
                    else
                        {
                        ++numInts;
                        }
                    }
                break;

            case  'D':
                // display the current contents of the list
                if (NULL == headPtr)
                    {
                    cout << "List is currently empty." << endl;
                    }
                else
                    {
                    cout << "Here is the list:" << endl;
                    DisplayList(headPtr);
                    cout << "There ";
                    cout << ((1 == numInts) ? "is " : "are ");
                    cout << numInts << " item";
                    cout << ((1 == numInts) ? "" : "s");
                    cout << " in the list" << endl;
                    }
                break;

            case  'Q':
                bLoop = false;
                cout << numInts;
                cout << " item";
                cout << ((1 == numInts) ? " " : "s ");
                cout << "released. Bye!" << endl;
                break;

            default:
                cout << "Unrecognized response; try again...\n";
                break;

            }  // end of switch

    return  0;

}  // end of "main"



// ==== DisplayMenu ===========================================================
//
// This function displays the menu selections to stdout.
//
// Input:
//      Nothing.
//
// Output:
//      Nothing.
//
// ============================================================================

void    DisplayMenu()
{
    cout << "\nDo you wish to:\n";
    cout << "  A)dd a new item to the list\n";
    cout << "  D)isplay the current contents of the list\n";
    cout << "  Q)uit the program\n";
}  // end of "DisplayMenu"



// ==== DisplayList ===========================================================
//
// This function displays the current contents of the list to stdout.
//
// Input:
//      head [IN]   -- a pointer to the head of the linked list
//
// Output:
//      counter -- the number of items written to stdout.
//
// ============================================================================

int     DisplayList(const LNode  *head)
{
    int counter = 0;

    while(head != NULL)
    {
        cout << head -> item << endl;
        head = head -> next;
        counter ++;
    }
    return counter;

}  // end of "DisplayList"



// ==== FlushInstream =========================================================
//
// This function displays the current contents of the list to the standard
// output stream.
//
// Input:
//      inStream    -- a reference to the input stream to flush
//
// Output:
//      Nothing.
//
// ============================================================================

void    FlushInstream(istream  &inStream)
{
    char        inChar;

    inStream.clear();
    while (false == inStream.eof())
        {
        inStream.get(inChar);
        if ('\n' == inChar)
            {
            break;
            }
        }

}  // end of "FlushInstream"



// ==== InsertItem ============================================================
//
// This function inserts a new item into the list. If the item is inserted
// successfully, the boolean parameter is set to true, otherwise it is set to
// false.
//
// Input:
//      head [IN]       -- a pointer to the first node in the linked list
//
//      index [IN]      -- the zero-based location index for the new item
//
//      item [IN]       -- the integer value to insert into the list
//
//      bSuccess [OUT]  -- the boolean result of the insert operation (true
//                         if successful, false if not)
//
// Output:
//      A pointer to the (potentially new) head of the linked list.
//
// ============================================================================

LNode*  InsertItem(LNode  *head, int  index, int  item, bool  &bSuccess)
{
    LNode *currNode;
    currNode = head;
    LNode *newNode;
    newNode -> item = item;
    LNode *nextNode;
    int counter = 0;

    if(index == 0)
    {
        newNode -> next = head;
    }
    else if(counter != index)
    {
        while(counter != index)
        {
            currNode = currNode -> next;
            counter++;
        }

        nextNode = currNode -> next;
        newNode -> next = nextNode;
        currNode -> next = newNode;
    }
    else
    {
        bSuccess = false;
    }

    return head;

}  // end of "InsertItem"
