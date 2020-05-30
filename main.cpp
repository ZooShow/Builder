#include <iostream>

using namespace std;

//enum RAM{
//
//};

enum PROCESSOR{
    intelI3,
    intelI5,
    intelI7,
    AMDRizen3,
    AMDRizen5,
    AMDRizen9
};

enum MOUSE{
    gaming,
    noGaming
};

enum MONITOR{
    fullHD4k,
    simpleMontior
};

enum COOLINGSYSTEM{
    waterCoolingSystem,
    fan
};


class Computer{
    string videoAdapter;
    unsigned int ram;
    PROCESSOR processor;
    string motherboard;
    MOUSE mouse;
    MONITOR monitor;
    COOLINGSYSTEM coolingSystem;
public:
    string toStringProcessor(PROCESSOR processor){
        switch (processor){
            case intelI3:
                return "Intel core i3";
            case intelI5:
                return "Intel core i5";
            case intelI7:
                return "Intel core i7";
            case AMDRizen3:
                return "AMD Rizen 3";
            case AMDRizen5:
                return "AMD Rizen 5";
            case AMDRizen9:
                return "AMD Rizen 9";
        }
    }

    string toStringMouse(MOUSE mouse) {
        switch (mouse){
            case gaming:
                return "gaming mouse";
            case noGaming:
                return "simple mouse";
        }
    }

    string toStringMonitor(MONITOR monitor) {
        switch (monitor){
            case fullHD4k:
                return "fullHD 4k";
            case simpleMontior:
                return "simple monitor";
        }
    }

    string toStringCoolingSystem(COOLINGSYSTEM coolingsystem) {
        switch (coolingsystem){
            case waterCoolingSystem:
                return "water cooling system";
            case fan:
                return "fans";
        }
    }

    void getConfiguration(){
        cout << "Your processor: " << toStringProcessor(processor) <<
        ", you have " << ram << "gb ram, video adapter is " << videoAdapter <<
        ", motherboard " << motherboard << ", mouse is " << toStringMouse(mouse)<<
        ", monitor is " << toStringMonitor(monitor) << ", sistem cooling is " <<
        toStringCoolingSystem(coolingSystem)<< endl;
    }

    friend class LowCostComputerBuider;
    friend class ComputerForStudyBuider;
};

class ComputerBuilder{
protected:
    string videoAdapter;
    unsigned int ram;
    PROCESSOR processor;
    string motherboard;
    MOUSE mouse;
    MONITOR monitor;
    COOLINGSYSTEM coolingSystem;
public:

    virtual Computer* build() = 0;

    void setMouse(MOUSE mouse) {
        this->mouse = mouse;
    }

    void setMonitor(MONITOR monitor) {
        this->monitor = monitor;
    }
};

class LowCostComputerBuider: public ComputerBuilder{
public:
    virtual Computer* build(){
        Computer* computer = new Computer();
        computer->processor = PROCESSOR::intelI3;
        computer->coolingSystem = COOLINGSYSTEM::fan;
        computer->ram = 4;
        computer->motherboard = "zalman";
        computer->videoAdapter = "GeeForce 720";
        computer->monitor = monitor;
        computer->mouse = mouse;
        return computer;
    }
};

class ComputerForStudyBuider: public ComputerBuilder{
public:
    virtual Computer* build(){
        Computer* computer = new Computer();
        computer->processor = PROCESSOR::intelI7;
        computer->coolingSystem = COOLINGSYSTEM::waterCoolingSystem;
        computer->ram = 16;
        computer->motherboard = "Asus";
        computer->videoAdapter = "GeeForce 2080";
        computer->monitor = monitor;
        computer->mouse = mouse;
        return computer;
    }
};

void setConfiguration(string mouse, string monitor, ComputerBuilder &computerBuilder){
    if (mouse == "y"){
        computerBuilder.setMouse(MOUSE::gaming);
    } else{
        computerBuilder.setMouse(MOUSE::noGaming);
    };

    if (monitor == "y"){
        computerBuilder.setMonitor(MONITOR::fullHD4k);
    } else {
        computerBuilder.setMonitor(MONITOR::simpleMontior);
    }

    Computer *computer = computerBuilder.build();
    computer->getConfiguration();
}

int main() {
    string monitor;
    string mouse;
    string answer;
    ComputerForStudyBuider computer;
    LowCostComputerBuider computer1;
    cout << "Do you want gaming mouse? (y/n)" << endl;
    cin >> mouse;
    cout << "Do you want good monitor? (y/n)" << endl;
    cin >> monitor;
    setConfiguration(mouse, monitor, computer);
    setConfiguration(mouse, monitor, computer1);
    return 0;
}
