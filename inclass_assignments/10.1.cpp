#include <iostream>
#include <iomanip>
using namespace std;


class Thermometer {
protected:
    double temperature;

public:
    Thermometer() {
        temperature = 0;
    }

    void setTemperature(double t) {
        temperature = t;
    }

    double getTemperature() {
        return temperature;
    }
};


class MedicalThermometer : public Thermometer {
public:
    void setTemperature(double t) {
        if (t >= 34.0 && t <= 42.0) {
            temperature = t;
            cout << "Temperature measured: "
                 << fixed << setprecision(1)
                 << temperature << endl;
        }
        else {
            cout << "Temperature is out of range!" << endl;
        }
    }

    void beep() {
        cout << "Measurement finished!" << endl;
    }
};


class WirelessMedicalThermometer final : private MedicalThermometer {
public:

  
    using MedicalThermometer::beep;

    void send_T() {
        cout << "Temperature " << temperature
             << " successfully sent!" << endl;
    }
};

int main() {

    MedicalThermometer medical;

    medical.setTemperature(36.6);
    medical.beep();

    cout << endl;

    WirelessMedicalThermometer wireless;

    wireless.beep();
    wireless.send_T();

    return 0;
}