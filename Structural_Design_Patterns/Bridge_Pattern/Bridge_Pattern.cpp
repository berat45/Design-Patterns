#include <iostream>

using namespace std;

typedef enum
{
    CLIENT_TYPE_WINDOWS = 0,
    CLIENT_TYPE_LINUX,
    CLIENT_TYPE_NUM_OF_CLIENTS
}CLIENT_TYPE_ENUM;

class PlatformExecuterInterface
{
public:
    PlatformExecuterInterface()
    {
        cout << "PlatformExecuterInterface default constructor" << endl;
    }
    virtual void* execute() = 0;
};

class WindowsPE : public PlatformExecuterInterface
{
public:
    WindowsPE()
    {
        cout << "WindowsPE default constructor" << endl;
    }
    void* execute() override
    {
        cout << "Windows API PE running.." << endl;
        return nullptr;
    }
};
class LinuxPE : public PlatformExecuterInterface
{
public:
    LinuxPE()
    {
        cout << "LinuxPE default constructor" << endl;
    }
    void* execute() override
    {
        cout << "Linux API PE running.." << endl;
        return nullptr;
    }
};

class platformExecuter
{
public:
    PlatformExecuterInterface* oPlatformExec[CLIENT_TYPE_NUM_OF_CLIENTS];
    
    platformExecuter()
    {
        cout << "platformExecuter default constructor" << endl;
    }
    
    void executePlatformAPIs(CLIENT_TYPE_ENUM clientType)
    {
        oPlatformExec[clientType]->execute();
    }
    
};

int main() 
{
    /* Bridge method shall contain client class which is not implemented here since the implementation itself depends on main() branch */
    platformExecuter oPlatformExe;
    WindowsPE* oWindowsPE = new WindowsPE();
    LinuxPE* oLinuxPE = new LinuxPE();
    
    oPlatformExe.oPlatformExec[CLIENT_TYPE_WINDOWS] = oWindowsPE;
    oPlatformExe.oPlatformExec[CLIENT_TYPE_LINUX]   = oLinuxPE;
    
    cout << "*******************" << endl;
    oPlatformExe.executePlatformAPIs(CLIENT_TYPE_WINDOWS);
    
}