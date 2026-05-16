#include <iostream>
#include <stdexcept>
using namespace std;

class Person
{
private:
    string p_name;
    int age;
    string id;

public:
    Person(string p_name, int age, string id)
    {
        if (age <= 0)
            throw runtime_error("Invalid Age — must be greater than 0!");
        this->p_name = p_name;
        this->age = age;
        this->id = id;
    }

    virtual void display()
    {
        cout << "Patient Name : " << p_name << endl;
        cout << "Patient Age  : " << age << endl;
        cout << "Patient ID   : " << id << endl;
    }

    string getName() const { return p_name; }
};

class MedicalRecord
{
private:
    string bloodGroup;
    bool hasAllergy;

public:
    MedicalRecord(string bloodGroup, bool hasAllergy)
    {
        this->bloodGroup = bloodGroup;
        this->hasAllergy = hasAllergy;
    }

    void displayRecord()
    {
        cout << "Blood Group  : " << bloodGroup << endl;
        cout << "Has Allergy  : " << (hasAllergy ? "Yes" : "No") << endl;
    }
};

// Aggregation
class Doctor
{
private:
    string d_name;
    string specialization;

public:
    Doctor(string d_name, string specialization)
        : d_name(d_name), specialization(specialization) {}

    void displayDoctor()
    {
        cout << "Doctor Name      : " << d_name << endl;
        cout << "Specialization   : " << specialization << endl;
    }

    ~Doctor()
    {
        cout << "[Doctor " << d_name << " deleted independently]" << endl;
    }
};

class Patient : public Person
{
private:
    string *disease;
    int room_num;
    double billAmount;
    MedicalRecord r1; // Composition
    Doctor *d1;       // Aggregation
static int totalpatient;
public:
Patient():Person("",0,""),r1("",false),d1(nullptr){
    disease = new string ("");
    room_num=0;
    billAmount =0;
totalpatient++;
}
    Patient(string p_name, int age, string id,
            string disease, double billAmount, int room_num,
            string bloodGroup, bool hasAllergy,
            Doctor *d1 = nullptr)
        : Person(p_name, age, id), r1(bloodGroup, hasAllergy), d1(d1)
    {
        if (room_num <= 0)
            throw runtime_error("Invalid Room Number!");
        if (billAmount < 0)
            throw runtime_error("Bill Amount cannot be negative!");
        this->disease = new string(disease);
        this->billAmount = billAmount;
        this->room_num = room_num;
        totalpatient++;
    }

    // Deep copy constructor
    Patient(const Patient &other)
        : Person(other), r1(other.r1), d1(other.d1)
    {
        disease = new string(*(other.disease));
        room_num = other.room_num;
        billAmount = other.billAmount;
        totalpatient++;
    }

    double showBill() const { return billAmount; }

    inline void updateRoom(int r)
    {
        room_num = r;
        cout << "Room Updated to : " << r << endl;
    }

    bool operator>(const Patient &other)
    {
        return billAmount > other.billAmount;
    }

    void display() override
    {
        Person::display();
        cout << "Disease      : " << *disease << endl;
        cout << "Room No      : " << room_num << endl;
        cout << "Bill Amount  : " << billAmount << endl;
        r1.displayRecord();
        if (d1 != nullptr)
            d1->displayDoctor();
    }
static void totalPatients(){
    cout<<"Total Patient Are : "<<totalpatient<<endl;
}
    ~Patient()
    {
        cout << "Patient " << getName() << " deleted — disease " << endl;
        delete disease;
    }

    friend void applyDiscount(Patient &p);
};
int Patient:: totalpatient=0;
// Friend function
void applyDiscount(Patient &p)
{
    double discount = p.billAmount - (p.billAmount * 0.10);
    cout << "After 10% Discount, Bill is : " << discount << endl;
}

// Polymorphism
class EmergencyPatient : public Person
{
private:
    string level;

public:
    EmergencyPatient(string p_name, int age, string id, string level)
        : Person(p_name, age, id)
    {
        this->level = level;
    }

    void display() override
    {
        Person::display();
        cout << "Emergency Level : " << level << endl;
    }
};

int main()
{

    Doctor *d1 = new Doctor("Dr. Babar Nazir", "Cardiologist");

    // Array of Patient pointers
    Patient *patients[2];
    int count = 0;

    // Take input for 2 patients
    for (int i = 0; i < 2; i++)
    {
        string name, id, disease, bloodGroup;
        int age, room;
        double bill;
        bool allergy;

        cout << "\n Enter Details for Patient " << i + 1 << " " << endl;
        cout << "Name   of Patient    : ";
        cin.ignore();
        getline(cin, name);
     while (true) {
        cout << "Age of Patient   : ";
        cin >> age;
        if (age <= 0)
            cout << "Error: Age must be greater than 0! Enter again.\n";
        else
            break;
    }
        cout << "ID of Patient        : ";
        cin.ignore();
        getline(cin, id);
        cout << "Disease of Patient   : ";
        getline(cin, disease);
       while (true) {
        cout << "Room Number      : ";
        cin >> room;
        if (room <= 0)
            cout << "Error: Room must be greater than 0! Enter again.\n";
        else
            break;
    }
       while (true) {
        cout << "Bill of Patient   : ";
        cin >> bill;
        if (bill <= 0)
            cout << "Error: Bill must be greater than 0! Enter again.\n";
        else
            break;
    }

        cout << "Blood Group of Patient: ";
        cin.ignore();
        getline(cin, bloodGroup);
        cout << " Patient has Allergy(1/0): ";
        cin >> allergy;
        try
        {
            patients[count] = new Patient(name, age, id, disease, bill, room, bloodGroup, allergy, d1);
            count++;
        }
        catch (runtime_error &e)
        {
            cout << "Error: " << e.what() << endl;
            cout<<"Enter Again\n";
            i--; // retry this patient
        }
    }

    // Display all patients
    cout << "\n===== All Patients =====" << endl;
    for (int i = 0; i < count; i++)
    {
        cout << "\n--- Patient " << i + 1 << " ---" << endl;
        patients[i]->display(); // override called
    patients[i]->totalPatients();
    }

    // Operator overloading
    if (*patients[0] > *patients[1])
    {
        cout << "\nPatient 1 has higher bill." << endl;
        applyDiscount(*patients[0]); // friend function
    }
    else
    {
        cout << "\nPatient 2 has higher bill." << endl;
        applyDiscount(*patients[1]); // friend function
    }
int update;
cout<<"Enter Update Room : ";
cin>>update;
    patients[0]->updateRoom(update);

    cout << "\n===== Emergency Patient =====" << endl;
    Person *ep = new EmergencyPatient("Ali Khan", 30, "E123", "Critical");
    ep->display(); // calls EmergencyPatient::display()

    cout << "\nMemory Free\n" << endl;
    for (int i = 0; i < count; i++)
        delete patients[i]; // patient deleted, doctor survives
    cout << "Doctor Still Exists (Aggregation):" << endl;
    d1->displayDoctor();
    delete ep;
    delete d1; // deleted independently

    return 0;
}