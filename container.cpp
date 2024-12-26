#include <iostream>
#include <string>
using namespace std;
class maye
{
    friend class zarf;
    string n;
    float ch;
    maye* next;
};
class zarf
{
    maye* head;
    public:
    zarf();
    ~zarf();
    void Push(string a,float c);
    string Pop();
    string Top();
    bool isEmpty();
};
zarf::zarf()
{
    head=nullptr;
}
zarf::~zarf()
{
    maye* temp;
    while (head!=nullptr)
    {
        temp=head;
        delete temp;
        head=head->next;
    }
}
bool zarf::isEmpty()
{
    if(head==nullptr)return true;
    else return false;
}
void zarf::Push(string a, float c) {
    // Check if the element already exists
    maye* checker = head;
    while (checker != nullptr) {
        if (checker->n == a) { // If the name already exists
            cout << "Element \"" << a << "\" already exists. Ignoring push.\n";
            return; // Exit without pushing
        }
        checker = checker->next;
    }

     // Create the new element
    maye* nmaye = new maye;
    nmaye->n = a;
    nmaye->ch = c;
    nmaye->next = nullptr;
    // Insert the element in the correct position
    if (head == nullptr || nmaye->ch < head->ch) { // Insert at the head
        nmaye->next = head;
        head = nmaye;
    } else {
        maye* temp = head;
        while (temp->next != nullptr && temp->next->ch <= nmaye->ch) {
            temp = temp->next;
        }
        nmaye->next = temp->next;
        temp->next = nmaye;
    }
}

string zarf::Pop()
{
    
    if(isEmpty())
    {
        cout<<"This laboratory container is empty.\n";
        return " ";
    }

        maye* temp=head;
        head=head->next;
        string popedelement=temp->n;
        delete temp;
        return popedelement;
}
string zarf::Top()
{
    if(isEmpty())
    {
        cout<<"This laboratory container is empty.\n";
        return " ";
    }

        return head->n;
}
int main()
{
    zarf myzarf;
    cout << "+++++Guide+++++\n";
    cout << "1 for Push\n";
    cout << "2 for Pop\n";
    cout << "3 for Top\n";
    cout << "4 for checking if the stack is empty\n";
    bool con = true;
    int c;
    float cho;
    char m;
    string nam;
    while (con)
    {
        cout << "Please enter your choice: ";
        cin >> c;
        switch (c)
        {
        case 1:
            cout << "\n Please enter the name of the liquid: ";
            cin >> nam;
            cout << "\n Please enter the liquid density: ";
            cin >> cho;
            myzarf.Push(nam, cho);
            break;
        case 2:
            cout << "\nThe top liquid is " << myzarf.Pop() << " and removed.\n";
            break;
        case 3:
            cout << "\nThe top liquid is " << myzarf.Top();
            break;
        case 4:
            if (myzarf.isEmpty()) 
                cout << "\nThis laboratory container is empty. ";
            else 
                cout << "\nThis laboratory container is not empty. ";
            break;
        default:
            cout << "\n Undefined choice, try again.";
            break;
        }
        cout << "\nDo you want to continue? (y/n)";
        cin >> m;
        con = (m == 'y' || m == 'Y');
    }
    return 0;
}
