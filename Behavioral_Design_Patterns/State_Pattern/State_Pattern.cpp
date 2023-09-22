#include <iostream>

using namespace std;

typedef enum
{
    BASE_CLASS_START = 0,
    BASE_CLASS_IN_PROGRESS,
    BASE_CLASS_FINALIZE,
    BASE_CLASS_TOTAL_NUM_OF_STATES
}BASE_CLASS_STATES;

/* abstract base class */
class BaseClass_A
{
private:
    BaseClass_A* stateTable[BASE_CLASS_TOTAL_NUM_OF_STATES];
    BaseClass_A* currentState;
    
protected:
    int dummyVar;
    
public:
    BASE_CLASS_STATES stateIndicator = BASE_CLASS_START;
    
    /* Base class constructor */
    BaseClass_A()
    {
        cout << "BaseClass_A() default constructor" << endl;
    }
    
    void initStateTable(BaseClass_A* stateStartObject, BaseClass_A* stateInProgressObject, BaseClass_A* stateFinalizeObject)
    {
        stateTable[BASE_CLASS_START] = stateStartObject;
        stateTable[BASE_CLASS_IN_PROGRESS] = stateInProgressObject;
        stateTable[BASE_CLASS_FINALIZE] = stateFinalizeObject;
        
        currentState = stateTable[stateIndicator];
    }
    
    void stateStepFunction()
    {
        if(stateIndicator == BASE_CLASS_START)
        {
            stateIndicator = BASE_CLASS_IN_PROGRESS;
        }
        else if(stateIndicator == BASE_CLASS_IN_PROGRESS)
        {
            stateIndicator = BASE_CLASS_FINALIZE;
        }
        else if(stateIndicator == BASE_CLASS_FINALIZE)
        {
            stateIndicator = BASE_CLASS_START;
        }
        else
        {
            /* error code implementation needed*/
        }
        currentState = stateTable[stateIndicator];
    }
    
    void stateRunner()
    {
        cout << "Current state : " << stateIndicator << endl;
        this->currentState->work();
    }
    
    /* No actual implementation of member functions */
    virtual void init()
    {}
    virtual void work()
    {}
    virtual void conclude()
    {}    
};

class StateClass_Start : public BaseClass_A
{
    private:
        BaseClass_A* baseClassAObjecttt;
        
    public:
        StateClass_Start(BaseClass_A* baseClassAObject)
        {
            cout << "StateClass_Start() default constructor" << endl;
            baseClassAObjecttt = baseClassAObject;
        }
        
        void work()
        {
            this->dummyVar = 2;
            cout << "StateClass_Start(): Dummy variable changed to " << this->dummyVar << endl;
            baseClassAObjecttt->stateStepFunction();
        }
};

class StateClass_InProgress : public BaseClass_A
{
    private:
        BaseClass_A* baseClassAObjecttt;
        
    public:
        StateClass_InProgress(BaseClass_A* baseClassAObject)
        {
            cout << "StateClass_InProgress() default constructor" << endl;
            baseClassAObjecttt = baseClassAObject;
        }
        
        void work()
        {
            this->dummyVar = 3;
            cout << "StateClass_InProgress(): Dummy variable changed to " << this->dummyVar << endl;
            baseClassAObjecttt->stateStepFunction();
        }  
};

class StateClass_Finalize : public BaseClass_A
{
    private:
        BaseClass_A* baseClassAObjecttt;
        
    public:
        StateClass_Finalize(BaseClass_A* baseClassAObject)
        {
            cout << "StateClass_Finalize() default constructor" << endl;
            baseClassAObjecttt = baseClassAObject;
        }
        
        void work()
        {
            this->dummyVar = 4;
            cout << "StateClass_Finalize(): Dummy variable changed to " << this->dummyVar << endl;
            baseClassAObjecttt->stateStepFunction();
        }  
};


int main() 
{
    BaseClass_A baseClassA_Object;
    StateClass_Start* stateStart_Object = new StateClass_Start(&baseClassA_Object);
    StateClass_InProgress* stateInProgress_Object = new StateClass_InProgress(&baseClassA_Object);
    StateClass_Finalize* stateFinalize_Object = new StateClass_Finalize(&baseClassA_Object);
    
    baseClassA_Object.initStateTable(stateStart_Object, stateInProgress_Object, stateFinalize_Object);
    cout << "**--**--**" << endl;
    baseClassA_Object.stateRunner();
    baseClassA_Object.stateRunner();
    baseClassA_Object.stateRunner();
    

}