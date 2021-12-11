//CMP 307 Project
//By Ross Paterson  1803583
//Lightweight asset tracking system for ScottishGlen

#include <iostream>
#include <fstream>
#include<string>
#include <stdlib.h>
using namespace std;

int assID;
int SoftassID;

struct SoftAsset {
    string proName, type, desc, version, dev, licType, licKey, purchDate, otherNotes;
    int  Softassid;
};

struct Asset {
    string assName, type, desc, model, manufacturer, IID, MAC, IP, physLoc, purchDate, warrInfo, otherNotes;
    int  assid;
};



bool login()
{
    string username, password, un, pw;
    std::cout << "Enter Username: ";
    std::cin >> username;
    std::cout << "Enter Passsword: ";
    std::cin >> password;

    ifstream read(username + ".txt");
    getline(read, un);
    getline(read, pw);

    if (un == username && pw == password)
    {
        return true;
    }

    else
    {
        return false;
    }
}

void insertAss() {
    Asset Asset;


    ofstream write;
    write.open("database.txt", ios::app);

    system("cls");
 
    std::cout << "INSERT ASSET INFORMATION, USE '.' INSTEAD OF A SPACE:" << endl;
    
    std::cout << "Insert asset name:";
    std::cin.get();
    getline(std::cin, Asset.assName); //Nouman Habib
    std::cout << "Insert type of asset:";
    std::cin >> Asset.type;
    std::cout << "Insert asset description:";
    std::cin >> Asset.desc;
    std::cout << "Insert asset model:";
    std::cin >> Asset.model;
    std::cout << "Insert asset manufacuturer:";
    std::cin >> Asset.manufacturer;
    std::cout << "Insert Internal assID:";
    std::cin >> Asset.IID;
    std::cout << "Insert asset MAC address:";
    std::cin >> Asset.MAC;
    std::cout << "Insert asset IP address:";
    std::cin >> Asset.IP;
    std::cout << "Insert asset physical location:";
    std::cin >> Asset.physLoc;
    std::cout << "Insert asset purchase date:";
    std::cin >> Asset.purchDate;
    std::cout << "Insert asset warranty infortmation:";
    std::cin >> Asset.warrInfo;
    std::cout << "Insert any other notes:";
    std::cin >> Asset.otherNotes;
    assID++;

    write << "\n" << assID;
    write << "\n" << Asset.assName;
    write << "\n" << Asset.type;
    write << "\n" << Asset.desc;
    write << "\n" << Asset.model;
    write << "\n" << Asset.manufacturer;
    write << "\n" << Asset.IID;
    write << "\n" << Asset.MAC;
    write << "\n" << Asset.IP;
    write << "\n" << Asset.physLoc;
    write << "\n" << Asset.purchDate;
    write << "\n" << Asset.warrInfo;
    write << "\n" << Asset.otherNotes;

    write.close();
    write.open("assetID.txt");
    write << assID;
    write.close();
    std::cout << "\n\tData save to file";
}

void SoftinsertAss() {
    SoftAsset Asset;


    ofstream write;
    write.open("softdatabase.txt", ios::app);

    system("cls");

    std::cout << "INSERT ASSET INFORMATION, USE '.' INSTEAD OF A SPACE:" << endl;

    std::cout << "Insert asset name:";
    std::cin.get();
    getline(std::cin, Asset.proName); //Nouman Habib
    std::cout << "Insert type of asset:";
    std::cin >> Asset.type;
    std::cout << "Insert asset description:";
    std::cin >> Asset.desc;
    std::cout << "Insert asset version:";
    std::cin >> Asset.version;
    std::cout << "Insert asset developer:";
    std::cin >> Asset.dev;
    std::cout << "Insert licence type:";
    std::cin >> Asset.licType;
    std::cout << "Insert licence key:";
    std::cin >> Asset.licKey;
    std::cout << "Insert purchase date:";
    std::cin >> Asset.purchDate;
    std::cout << "Insert other notes:";
    std::cin >> Asset.otherNotes;
    SoftassID++;

    write << "\n" << SoftassID;
    write << "\n" << Asset.proName;
    write << "\n" << Asset.type;
    write << "\n" << Asset.version;
    write << "\n" << Asset.dev;
    write << "\n" << Asset.licType;
    write << "\n" << Asset.licKey;
    write << "\n" << Asset.purchDate;
    write << "\n" << Asset.otherNotes;

    write.close();
    write.open("softassetID.txt");
    write << SoftassID;
    write.close();
    std::cout << "\n\tData save to file";
}

void print(Asset s) {
    std::cout << "\n---Asset Data---";
    std::cout << "\nID: " << s.assid;
    std::cout << "\nName: " << s.assName;
    std::cout << "\nType: " << s.type;
    std::cout << "\nDescription: " << s.desc;
    std::cout << "\nModel: " << s.model;
    std::cout << "\nManufacturer: " << s.manufacturer;
    std::cout << "\nInternal ID: " << s.IID;
    std::cout << "\nMAC Address: " << s.MAC;
    std::cout << "\nIP Address: " << s.IP;
    std::cout << "\nPhysical Location: " << s.physLoc;
    std::cout << "\nPurchase Date: " << s.purchDate;
    std::cout << "\nWarranty Info: " << s.warrInfo;
    std::cout << "\nOtherNotes: " << s.otherNotes;


}

void Softprint(SoftAsset s) {
    std::cout << "\n---Asset Data---";
    std::cout << "\nID: " << s.Softassid;
    std::cout << "\nName: " << s.proName;
    std::cout << "\nType: " << s.type;
    std::cout << "\nDescription: " << s.desc;
    std::cout << "\nVersion: " << s.version;
    std::cout << "\nDeveloper: " << s.dev;
    std::cout << "\nLicence Type: " << s.licType;
    std::cout << "\nLicence Key: " << s.licKey;
    std::cout << "\nPurchase Date: " << s.purchDate;
    std::cout << "\nOtherNotes: " << s.otherNotes;
   
}

void readAsset() {
    Asset Asset;
    ifstream read;
    read.open("database.txt");
    while (!read.eof()) {
        read >> Asset.assid;
        read.ignore();
        getline(read, Asset.assName);
        read >> Asset.type;
        read >> Asset.desc;
        read >> Asset.model;
        read >> Asset.manufacturer;
        read >> Asset.IID;
        read >> Asset.MAC;
        read >> Asset.IP;
        read >> Asset.physLoc;
        read >> Asset.purchDate;
        read >> Asset.warrInfo;
        read >> Asset.otherNotes;
        print(Asset);
    }
    read.close();
}


void SoftreadAsset() {
    SoftAsset SoftAsset;
    ifstream read;
    read.open("softdatabase.txt");
    while (!read.eof()) {
        read >> SoftAsset.Softassid;
        read.ignore();
        getline(read, SoftAsset.proName);
        read >> SoftAsset.type;
        read >> SoftAsset.desc;
        read >> SoftAsset.version;
        read >> SoftAsset.licType;
        read >> SoftAsset.licKey;
        read >> SoftAsset.purchDate;
        read >> SoftAsset.otherNotes;
        Softprint(SoftAsset);
    }
    read.close();
}
int search() {
    int assid;
    std::cout << "\n\tEnter Asset ID want to search : ";
    std::cin >> assid;
    Asset Asset;
    ifstream read;
    read.open("database.txt");
    while (!read.eof()) {
        read >> Asset.assid;
        read.ignore();
        getline(read, Asset.assName);
        read >> Asset.type;
        read >> Asset.desc;
        read >> Asset.model;
        read >> Asset.manufacturer;
        read >> Asset.IID;
        read >> Asset.MAC;
        read >> Asset.IP;
        read >> Asset.physLoc;
        read >> Asset.purchDate;
        read >> Asset.warrInfo;
        read >> Asset.otherNotes;
        if (Asset.assid == assid) {
            print(Asset);
            return assid;
        }
    }
}



int Softsearch() {
    int assid;
    std::cout << "\n\tEnter Asset ID want to search : ";
    std::cin >> assid;
    SoftAsset SoftAsset;
    ifstream read;
    read.open("softdatabase.txt");
    while (!read.eof()) {
        read >> SoftAsset.Softassid;
        read.ignore();
        getline(read, SoftAsset.proName);
        read >> SoftAsset.type;
        read >> SoftAsset.desc;
        read >> SoftAsset.version;
        read >> SoftAsset.licType;
        read >> SoftAsset.licKey;
        read >> SoftAsset.purchDate;
        read >> SoftAsset.otherNotes;
        if (SoftAsset.Softassid == assid) {
            Softprint(SoftAsset);
            return assid;
        }
    }
}

void deleteAsset() {
    int assid = search();
    std::cout << "\nYou want to delete asset (y/n) : ";
    char choice;
    std::cin >> choice;
    if (choice == 'y') {
        Asset Asset;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("database.txt");
        while (!read.eof()) {
            read >> Asset.assid;
            read.ignore();
            getline(read, Asset.assName);
            read >> Asset.type;
            read >> Asset.desc;
            read >> Asset.model;
            read >> Asset.manufacturer;
            read >> Asset.IID;
            read >> Asset.MAC;
            read >> Asset.IP;
            read >> Asset.physLoc;
            read >> Asset.purchDate;
            read >> Asset.warrInfo;
            read >> Asset.otherNotes;
            if (Asset.assid != assid) {
                tempFile << "\n" << Asset.assid;
                tempFile << "\n" << Asset.assName;
                tempFile << "\n" << Asset.type;
                tempFile << "\n" << Asset.desc;
                tempFile << "\n" << Asset.model;
                tempFile << "\n" << Asset.manufacturer;
                tempFile << "\n" << Asset.IID;
                tempFile << "\n" << Asset.MAC;
                tempFile << "\n" << Asset.IP;
                tempFile << "\n" << Asset.physLoc;
                tempFile << "\n" << Asset.purchDate;
                tempFile << "\n" << Asset.warrInfo;
                tempFile << "\n" << Asset.otherNotes;
            }
        }
        read.close();
        tempFile.close();
        remove("database.txt");
        rename("temp.txt", "database.txt");
        std::cout << "\nAsset deleted successfuly";
    }
    else {
        std::cout << "\nAsset not deleted";
    }
}



void SoftdeleteAsset() {
    int assid = Softsearch();
    std::cout << "\nYou want to delete asset (y/n) : ";
    char choice;
    std::cin >> choice;
    if (choice == 'y') {
        SoftAsset Asset;
        ofstream tempFile;
        tempFile.open("softtemp.txt");
        ifstream read;
        read.open("softdatabase.txt");
        while (!read.eof()) {
            read >> Asset.Softassid;
            read.ignore();
            getline(read, Asset.proName);
            read >> Asset.type;
            read >> Asset.desc;
            read >> Asset.version;
            read >> Asset.dev;
            read >> Asset.licType;
            read >> Asset.licKey;
            read >> Asset.purchDate;
            read >> Asset.otherNotes;
            if (Asset.Softassid != assid) {
                tempFile << "\n" << Asset.Softassid;
                tempFile << "\n" << Asset.proName;
                tempFile << "\n" << Asset.type;
                tempFile << "\n" << Asset.desc;
                tempFile << "\n" << Asset.version;
                tempFile << "\n" << Asset.dev;
                tempFile << "\n" << Asset.licType;
                tempFile << "\n" << Asset.licKey;
                tempFile << "\n" << Asset.purchDate;
                tempFile << "\n" << Asset.otherNotes;
            }
        }
        read.close();
        tempFile.close();
        remove("softdatabase.txt");
        rename("softtemp.txt", "softdatabase.txt");
        std::cout << "\nAsset deleted successfuly";
    }
    else {
        std::cout << "\nAsset not deleted";
    }
}

void updateAsset() {
    int assid = search();
    std::cout << "\n\tYou want to update record (y/n) : ";
    char choice;
    std::cin >> choice;
    if (choice == 'y') {
        Asset newData;
        std::cout << "\n\tEnter Asset name : ";
        std::cin.get();
        getline(std::cin, newData.assName);
        std::cout << "Insert type of asset:";
        std::cin >> newData.type;
        std::cout << "Insert asset description:";
        std::cin >> newData.desc;
        std::cout << "Insert asset model:";
        std::cin >> newData.model;
        std::cout << "Insert asset manufacuturer:";
        std::cin >> newData.manufacturer;
        std::cout << "Insert Internal assID:";
        std::cin >> newData.IID;
        std::cout << "Insert asset MAC address:";
        std::cin >> newData.MAC;
        std::cout << "Insert asset IP address:";
        std::cin >> newData.IP;
        std::cout << "Insert asset physical location:";
        std::cin >> newData.physLoc;
        std::cout << "Insert asset purchase date:";
        std::cin >> newData.purchDate;
        std::cout << "Insert asset warranty infortmation:";
        std::cin >> newData.warrInfo;
        std::cout << "Insert any other notes:";
        std::cin >> newData.otherNotes;
        Asset Asset;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("database.txt");
        while (!read.eof()) {
            read >> Asset.assid;
            read.ignore();
            getline(read, Asset.assName);
            read >> Asset.type;
            read >> Asset.desc;
            read >> Asset.model;
            read >> Asset.manufacturer;
            read >> Asset.IID;
            read >> Asset.MAC;
            read >> Asset.IP;
            read >> Asset.physLoc;
            read >> Asset.purchDate;
            read >> Asset.warrInfo;
            read >> Asset.otherNotes;

            if (Asset.assid != assid) {
                tempFile << "\n" << Asset.assid;
                tempFile << "\n" << Asset.assName;
                tempFile << "\n" << Asset.type;
                tempFile << "\n" << Asset.desc;
                tempFile << "\n" << Asset.model;
                tempFile << "\n" << Asset.manufacturer;
                tempFile << "\n" << Asset.IID;
                tempFile << "\n" << Asset.MAC;
                tempFile << "\n" << Asset.IP;
                tempFile << "\n" << Asset.physLoc;
                tempFile << "\n" << Asset.purchDate;
                tempFile << "\n" << Asset.warrInfo;
                tempFile << "\n" << Asset.otherNotes;

            }
            else {
                tempFile << "\n" << Asset.assid;
                tempFile << "\n" << Asset.assName;
                tempFile << "\n" << Asset.type;
                tempFile << "\n" << Asset.desc;
                tempFile << "\n" << Asset.model;
                tempFile << "\n" << Asset.manufacturer;
                tempFile << "\n" << Asset.IID;
                tempFile << "\n" << Asset.MAC;
                tempFile << "\n" << Asset.IP;
                tempFile << "\n" << Asset.physLoc;
                tempFile << "\n" << Asset.purchDate;
                tempFile << "\n" << Asset.warrInfo;
                tempFile << "\n" << Asset.otherNotes;
            }
        }
        read.close();
        tempFile.close();
        remove("database.txt");
        rename("temp.txt", "database.txt");
        std::cout << "\nAsset updated successfuly";
    }
    else {
        std::cout << "\nAsset not deleted";
    }
}


void SoftupdateAsset() {
    int assid = Softsearch();
    std::cout << "\n\tYou want to update record (y/n) : ";
    char choice;
    std::cin >> choice;
    if (choice == 'y') {
        SoftAsset newData;
        std::cout << "\n\tEnter Asset name : ";
        std::cin.get();
        getline(std::cin, newData.proName);
        std::cout << "Insert type of asset:";
        std::cin >> newData.type;
        std::cout << "Insert asset description:";
        std::cin >> newData.desc;
        std::cout << "Insert asset model:";
        std::cin >> newData.version;
        std::cout << "Insert asset manufacuturer:";
        std::cin >> newData.dev;
        std::cout << "Insert Internal assID:";
        std::cin >> newData.licType;
        std::cout << "Insert asset MAC address:";
        std::cin >> newData.licKey;
        std::cout << "Insert asset IP address:";
        std::cin >> newData.purchDate;
        std::cout << "Insert asset physical location:";
        std::cin >> newData.otherNotes;

        SoftAsset Asset;
        ofstream tempFile;
        tempFile.open("softtemp.txt");
        ifstream read;
        read.open("softdatabase.txt");
        while (!read.eof()) {
            read >> Asset.Softassid;
            read.ignore();
            getline(read, Asset.proName);
            read >> Asset.type;
            read >> Asset.desc;
            read >> Asset.version;
            read >> Asset.dev;
            read >> Asset.licType;
            read >> Asset.licKey;
            read >> Asset.purchDate;
            read >> Asset.otherNotes;

            if (Asset.Softassid != assid) {
                tempFile << "\n" << Asset.Softassid;
                tempFile << "\n" << Asset.proName;
                tempFile << "\n" << Asset.type;
                tempFile << "\n" << Asset.desc;
                tempFile << "\n" << Asset.version;
                tempFile << "\n" << Asset.dev;
                tempFile << "\n" << Asset.licType;
                tempFile << "\n" << Asset.licKey;
                tempFile << "\n" << Asset.purchDate;
                tempFile << "\n" << Asset.otherNotes;

            }
            else {
                tempFile << "\n" << Asset.Softassid;
                tempFile << "\n" << Asset.proName;
                tempFile << "\n" << Asset.type;
                tempFile << "\n" << Asset.desc;
                tempFile << "\n" << Asset.version;
                tempFile << "\n" << Asset.dev;
                tempFile << "\n" << Asset.licType;
                tempFile << "\n" << Asset.licKey;
                tempFile << "\n" << Asset.purchDate;
                tempFile << "\n" << Asset.otherNotes;
            }
        }
        read.close();
        tempFile.close();
        remove("softdatabase.txt");
        rename("softtemp.txt", "softdatabase.txt");
        std::cout << "\nAsset updated successfuly";
    }
    else {
        std::cout << "\nAsset not deleted";
    }
}

int main()
{
    ifstream read;
    read.open("assetID.txt");
    if (!read.fail()) {
        read >> assID;
    }
    else {
        assID = 0;
    }
    read.close();

    int menuchoice;

    std::cout << "cmp307 project by Ross Paterson" << endl << endl;
    std::cout << "Asset Tracking System for ScotGlen - For both Hardware and Software"

    std::cout << "Menu:" << endl;
    std::cout << "1. Register: \n2. Login: " << endl;
    std::cin >> menuchoice;
    if (menuchoice == 1)
    {
        string username, password;
        std::cout << "select a username :";
        std::cin >> username;
        std::cout << "select a password :";
        std::cin >> password;

        ofstream file;
        file.open(username + ".txt");

        file << username << endl << password;
        file.close();

        main();
    }
    else if (menuchoice == 2)
    {
        bool status = login();

        if (!status)
        {
            std::cout << "Login incorrect" << endl;
            system("PAUSE");
            return 0;
        }
        else
        {
            std::cout << "\nChoose Hardware asset database or software asset database: ";
            std::cout << "\n1.Hardware database: ";
            std::cout << "\n2.Software database: ";
            std::cin >> menuchoice;
            if (menuchoice == 1)
            {
                while (true) {
                    std::cout << "\nHARDWARE TRACKING SYSTEM :";
                    std::cout << "\n\n1.Insert new asset: ";
                    std::cout << "\n2.Display all assets: ";
                    std::cout << "\n3.Search an existing asset: ";
                    std::cout << "\n4.Delete an asset: ";
                    std::cout << "\n5.Edit all assets: ";
                    std::cout << "\n6.Quit program: ";

                    int choice;
                    std::cout << "\n\nEnter choice : ";
                    std::cin >> choice;
                    switch (choice) {
                    case 1:
                        insertAss();
                        break;
                    case 2:
                        readAsset();
                        break;
                    case 3:
                        search();
                        break;
                    case 4:
                        deleteAsset();
                        break;
                    case 5:
                        updateAsset();
                        break;
                    case 6:
                        system("PAUSE");
                        return 0;
                    }
                }
            }
            else
                std::cout << "\nSOFTWARE TRACKING SYSTEM: ";
            std::cout << "\n\n1.Insert new asset: ";
            std::cout << "\n2.Display all assets: ";
            std::cout << "\n3.Search an existing asset: ";
            std::cout << "\n4.Delete an asset: ";
            std::cout << "\n5.Edit all assets: ";
            std::cout << "\n6.Quit program: ";

            int choice;
            std::cout << "\n\nEnter choice : ";
            std::cin >> choice;
            switch (choice) {
            case 1:
                SoftinsertAss();
                break;
            case 2:
                SoftreadAsset();
                break;
            case 3:
                Softsearch();
                break;
            case 4:
                SoftdeleteAsset();
                break;
            case 5:
                SoftupdateAsset();
                break;
            case 6:
                system("PAUSE");
                return 0;
            }
        }
    }
}