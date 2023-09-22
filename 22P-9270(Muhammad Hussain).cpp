#include <iostream>
using namespace std;
struct person
{
    int id = 0;
    string firstName = "N/A";
    string lastName = "N/A";
};

struct Admin
{
    string Password = "admin";
    person data;
};
struct salePerson
{
    string Password = "saleperson123";
    double saleByQtr[4] = {0, 0, 0, 0};
    double totalSale = 0;
    person data;
};
Admin admin_data;
salePerson salePerson_data[5];

int checkrecord();
void mainmenu();
void admin();
void SalePerson();
void enrollingNewMembers();
void Display(int x = -1);
int main()
{

    mainmenu();

    return 0;
}

void mainmenu()
{
    int choice;
    cout << "\nWelcome to Sales Management System" << endl;

    cout << "For logging as Admin press 1" << endl;
    cout << "For logging as Sale person press 2" << endl;
    cin >> choice;
    if (choice == 1)
    {
        admin();
    }
    else if (choice == 2)
    {
        SalePerson();
    }
    else
    {
        cout << "incorrect choice";
        mainmenu();
    }
}
void admin()
{
    if (admin_data.Password == "admin")
    {
        cout << "Default Password is admin so\n Enter a new password" << endl;
        cin >> admin_data.Password;
        admin();
    }
    else
    {
        string password;
        cout << "Enter your password\n";
        cin >> password;
        if (password == admin_data.Password)
        {
            while (1)
            {
                int choiceOfDisplayForAdmin;
                cout << "\n\nChoose 1 of the following\n";
                cout << "1: For displaying the complete record of Sale Persons" << endl;
                cout << "2: For displaying the individual record of Sale Persons" << endl;
                cout << "3: For adding or enrolling new Sale Persons" << endl;
                cout << "4: For logging out" << endl;
                cin >> choiceOfDisplayForAdmin;

                if (choiceOfDisplayForAdmin == 1)
                {
                    if (checkrecord() == 0)
                    {
                        cout << "First Enroll a member\n";
                        continue;
                    }
                    else
                    {
                        Display();
                    }
                }
                else if (choiceOfDisplayForAdmin == 2)
                {
                    if (checkrecord() == 0)
                    {
                        cout << "First Enroll a member\n";
                        continue;
                    }
                    else
                    {
                        int search_id;
                        cout << "\nEnter ID you want to display data of\n";
                        cin >> search_id;
                        getchar();
                        Display(search_id);
                    }
                }
                else if (choiceOfDisplayForAdmin == 3)
                {
                    if (checkrecord() == -1)
                    {
                        cout << "\n5 Person are already registered\n";
                        continue;
                    }
                    enrollingNewMembers();
                }
                else if (choiceOfDisplayForAdmin == 4)
                {
                    mainmenu();
                }
            }
        }
        else
        {
            cout << "wrong password Enter your password again" << endl;
            admin();
        }
    }
}
void enrollingNewMembers()
{
    int check = checkrecord();
    cout << "Enter id of the Person you want to enroll" << endl;
    cin >> salePerson_data[check].data.id;
    cout << "Enter first name of the Person you want to enroll" << endl;
    cin >> salePerson_data[check].data.firstName;
    cout << "Enter last name of the Person you want to enroll" << endl;
    cin >> salePerson_data[check].data.lastName;

    admin();
}
void SalePerson()
{
    int id;
    cout << "Enter your ID" << endl;
    cin >> id;
    for (int i = 0; i < 5; i++)
    {
        if (id == salePerson_data[i].data.id)
        {
            int salePersonChoice;
            if (salePerson_data[i].Password == "saleperson123")
            {
                cout << "Default password for sale person is saleperson123" << endl;
                cout << "Enter new password" << endl;
                cin >> salePerson_data[i].Password;
                --i;
                continue;
            }
            else
            {
                string password;
                cout << "Enter  password" << endl;
                cin >> password;
                if (password == salePerson_data[i].Password)
                {
                    cout << "\nChoose one of the following\n";
                    cout << "1 : Update sale by QTR\n";
                    cout << "2 : view sale person record\n";
                    cout << "3 : logout to main menu\n";
                    cin >> salePersonChoice;
                    if (salePersonChoice == 1)
                    {
                        for (int j = 0; j < 4; j++)
                        {
                            cout << "Enter your sales for the QTR " << j + 1 << ": ";
                            cin >> salePerson_data[i].saleByQtr[j];
                            salePerson_data[i].totalSale += salePerson_data[i].saleByQtr[j];
                        }
                        --i;
                        continue;
                    }
                    else if (salePersonChoice == 2)
                    {
                        if (salePerson_data[i].totalSale == 0)
                        {
                            cout << "\nNo data is updated\n";
                            --i;
                            continue;
                        }
                        cout << "ID\t\tQTR1\t\tQTR2\t\tQTR3\t\tQTR4\t\tTotal" << endl;
                        cout << salePerson_data[i].data.id << "\t\t  " << salePerson_data[i].saleByQtr[0] << "\t\t  " << salePerson_data[i].saleByQtr[1] << "\t\t  " << salePerson_data[i].saleByQtr[2] << "\t\t  " << salePerson_data[i].saleByQtr[3] << "\t\t  " << salePerson_data[i].totalSale;
                        mainmenu();
                    }
                    else
                    {
                        mainmenu();
                    }
                }
                else
                {
                    cout << "wrong password Enter your password again" << endl;
                    --i;
                    continue;
                }
            }
        }
    }
    cout << "-------------------this id is not registered---------------------" << endl;
    SalePerson();
}
int checkrecord()
{
    for (int i = 0; i < 5; i++)
    {
        if (salePerson_data[i].data.id == 0)
        {
            return i;
        }
    }
    return -1;
}
void Display(int x)
{
    double total_Qtr[4] = {0, 0, 0, 0};
    int Max_id, Max_Qtr;
    double Max_Amount, Max_Qtr_Amount;
    if (x == -1)
    {
        cout << "\n------------------Annual Sales Report----------------\n\n";
        cout << "ID\t\tQTR1\t\tQTR2\t\tQTR3\t\tQTR4\t\tTotal" << endl;
        cout << "---------------------------------------------------------------------------------------\n";
        for (int i = 0; i < 5; i++)
        {
            if (salePerson_data[i].data.id != 0)
            {
                cout << salePerson_data[i].data.id << "\t\t  " << salePerson_data[i].saleByQtr[0] << "\t\t  " << salePerson_data[i].saleByQtr[1] << "\t\t  " << salePerson_data[i].saleByQtr[2] << "\t\t  " << salePerson_data[i].saleByQtr[3] << "\t\t  " << salePerson_data[i].totalSale << endl;

                total_Qtr[0] += salePerson_data[i].saleByQtr[0];
                total_Qtr[1] += salePerson_data[i].saleByQtr[1];
                total_Qtr[2] += salePerson_data[i].saleByQtr[2];
                total_Qtr[3] += salePerson_data[i].saleByQtr[3];
                if (i == 0)
                {
                    Max_id = salePerson_data[i].data.id;
                    Max_Amount = salePerson_data[i].totalSale;
                }
                else
                {
                    if (salePerson_data[i].totalSale > Max_Amount)
                    {
                        Max_id = salePerson_data[i].data.id;
                        Max_Amount = salePerson_data[i].totalSale;
                    }
                }
            }
            else
            {
                break;
            }
        }
        cout << "\nTotal\t\t  ";
        for (int i = 0; i < 4; i++)
        {
            cout << total_Qtr[i] << "\t\t  ";
            if (i == 0)
            {
                Max_Qtr = 1;
                Max_Qtr_Amount = total_Qtr[i];
            }
            else
            {
                if (total_Qtr[i] > Max_Qtr_Amount)
                {
                    Max_Qtr = i + 1;
                    Max_Qtr_Amount = total_Qtr[i];
                }
            }
        }
        cout << endl
             << endl;
        cout << "Max sale by SalesPerson: ID = " << Max_id << ", Amount = " << Max_Amount << endl;
        cout << "Max sale by Quarter: Quarter = " << Max_Qtr << ", Amount = " << Max_Qtr_Amount << endl;
        cout << "---------------------------------------------------------------------------------------\n\n";
    }
    else
    {
        for (int i = 0; i < 5; i++)
        {
            if (salePerson_data[i].data.id == x)
            {
                cout << "ID\t\tQTR1\t\tQTR2\t\tQTR3\t\tQTR4\t\tTotal" << endl;
                cout << "-----------------------------------------------------------------------\n";
                cout << salePerson_data[i].data.id << "\t\t  " << salePerson_data[i].saleByQtr[0] << "\t\t  " << salePerson_data[i].saleByQtr[1] << "\t\t  " << salePerson_data[i].saleByQtr[2] << "\t\t  " << salePerson_data[i].saleByQtr[3] << "\t\t  " << salePerson_data[i].totalSale;
                return;
            }
        }
        cout << "\nId Not Match" << endl;
    }
}