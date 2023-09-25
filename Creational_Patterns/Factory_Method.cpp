#include <iostream>

using namespace std;

typedef enum
{
    FM_MEM_FLASH = 0,
    FM_MEM_SD_CARD,
    FM_MEM_EMMC,
    /***************************************************************/
    /**************** Add new memory def. here *********************/

    /***************************************************************/
    FM_MEM_TOTAL_NUM_OF_MEM
}FACTORY_METHOD_PATTERN_MEMORY_TYPES_ENUM;

/* Interface for the memory handlers */
class Memory_Controller_Interface
{
protected:
    virtual void businessLogic() = 0;
public:
    virtual void doWork() = 0;    
};

class Flash_Memory_Handler : public Memory_Controller_Interface
{
protected:
    void businessLogic() override
    {
        cout << "Private business logic for flash memory" << endl;
    }
public:
    void doWork() override
    {
        this->businessLogic();
    }
};

class SdCard_Memory_Handler : public Memory_Controller_Interface
{
protected:
    void businessLogic() override
    {
        cout << "Private business logic for SD memory" << endl;
    }
public:
    void doWork() override
    {
        this->businessLogic();
    }
};

class Emmc_Memory_Handler : public Memory_Controller_Interface
{
protected:
    void businessLogic() override
    {
        cout << "Private business logic for EMMC memory" << endl;
    }
public:
    void doWork() override
    {
        this->businessLogic();
    }
};

/***************************************************************/
/**************** Add new memory type here *********************/

/***************************************************************/

class Memory_Handler_Object_Factory_Class
{
public:
    Memory_Controller_Interface* buildMemoryHandler(FACTORY_METHOD_PATTERN_MEMORY_TYPES_ENUM memoryType)
    {
        switch (memoryType)
        {
            case FM_MEM_FLASH:
            {
                return new Flash_Memory_Handler();
                break;
            }
            case FM_MEM_SD_CARD:
            {
                return new SdCard_Memory_Handler();
                break;
            }
            case FM_MEM_EMMC:
            {
                return new Emmc_Memory_Handler();
                break;
            }
            /***************************************************************/
            /**************** Add new memory case here *********************/

            /***************************************************************/
            default:
            {
                return nullptr;
                break;
            }
        }
    }
};

class Operator_Class
{
private:
    Memory_Controller_Interface* hMemoryController;
    Memory_Handler_Object_Factory_Class hMemoryHandlerObject;
public:
    ~Operator_Class()
    {
        if(nullptr != hMemoryController)
        {
            delete hMemoryController;
        }
    }
    
    void createMemoryControllerHandler(FACTORY_METHOD_PATTERN_MEMORY_TYPES_ENUM memoryType)
    {
        hMemoryController = hMemoryHandlerObject.buildMemoryHandler(memoryType);
    }
    
    Memory_Controller_Interface* getSelectedMemoryHandler()
    {
        return hMemoryController;
    }
};


int main() 
{
    Operator_Class* pOperatorObject = new Operator_Class();
    
    pOperatorObject->createMemoryControllerHandler(FM_MEM_FLASH);
    pOperatorObject->getSelectedMemoryHandler()->doWork();
    
    pOperatorObject->createMemoryControllerHandler(FM_MEM_SD_CARD);
    pOperatorObject->getSelectedMemoryHandler()->doWork();
    
    pOperatorObject->createMemoryControllerHandler(FM_MEM_EMMC);
    pOperatorObject->getSelectedMemoryHandler()->doWork();
    
    /***************************************************************/
    /**************** Add new memory call here *********************/

    /***************************************************************/

}