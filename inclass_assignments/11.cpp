#include <iostream>
#include <string>

using namespace std;


class MedicalThermometer {
protected:
    double temperature;
    const double MIN_TEMP = 32.0;
    const double MAX_TEMP = 42.0;

public:
  
    MedicalThermometer(double initTemp) {
        if (initTemp < MIN_TEMP) {
            temperature = MIN_TEMP;
            cout << "[Предупреждение] Температура ниже нормы, установлено " << MIN_TEMP << " C" << endl;
        } else if (initTemp > MAX_TEMP) {
            temperature = MAX_TEMP;
            cout << "[Предупреждение] Температура выше нормы, установлено " << MAX_TEMP << " C" << endl;
        } else {
            temperature = initTemp;
        }
    }

    double getTemperature() const {
        return temperature;
    }

    void setTemperature(double newTemp) {
        if (newTemp >= MIN_TEMP && newTemp <= MAX_TEMP) {
            temperature = newTemp;
        } else {
            cout << "Ошибка: температура должна быть в диапазоне от " 
                 << MIN_TEMP << " до " << MAX_TEMP << " C." << endl;
        }
    }
};


class SignalThermometer : virtual public MedicalThermometer {
protected:
    int tonePitch; // Высота тона в Гц

public:
    SignalThermometer(double initTemp, int pitch)
        : MedicalThermometer(initTemp), tonePitch(pitch) {}

    void beep() const {
        cout << "Пииип! Сработал звуковой сигнал (высота тона: " 
             << tonePitch << " Гц)." << endl;
    }
};


class DataThermometer : virtual public MedicalThermometer {
protected:
    string protocol; // Например: Bluetooth, Wi-Fi, Wire

public:
    DataThermometer(double initTemp, string proto)
        : MedicalThermometer(initTemp), protocol(proto) {}

    void showProtocol() const {
        cout << "Используемый протокол передачи данных: " << protocol << endl;
    }
};


class SmartThermometer : public SignalThermometer, public DataThermometer {
public:
   
    SmartThermometer(double initTemp, int pitch, string proto)
        : MedicalThermometer(initTemp),
          SignalThermometer(initTemp, pitch),
          DataThermometer(initTemp, proto) {}

    void showFullInfo() const {
        cout << "--- Информация об умном термометре ---" << endl;
        cout << "Текущая температура: " << getTemperature() << " C" << endl;
        beep();
        showProtocol();
    }
};

int main() {
    SmartThermometer myThermometer(36.6, 2000, "Bluetooth");

   
    myThermometer.showFullInfo();

    cout << "\nМеняем температуру на 38.5:" << endl;
    myThermometer.setTemperature(38.5);
    cout << "Новая температура: " << myThermometer.getTemperature() << " C" << endl;

    cout << "\nПробуем задать недопустимую температуру (50.0):" << endl;
    myThermometer.setTemperature(50.0);

    return 0;
}
