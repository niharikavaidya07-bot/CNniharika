#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

int main() {
    int n, frame = 1, timeout;

    cout << "Stop and Wait ARQ\n\n";

    cout << "Enter number of frames: ";
    cin >> n;

    cout << "Enter timeout value in seconds: ";
    cin >> timeout;

    srand(time(0));

    while (frame <= n) {
        cout << "\nSending Frame " << frame << "...\n";
        cout << "Timer started.\n";

        int lost = rand() % 3;

        if (lost == 0) {
            cout << "Frame " << frame << " lost!\n";

            for (int i = 1; i <= timeout; i++) {
                cout << "Timer: " << i << " second(s)\n";
                this_thread::sleep_for(chrono::seconds(1));
            }

            cout << "Timeout occurred.\n";
            cout << "Retransmitting Frame " << frame << "...\n";

            lost = 1;
        }
        else {
            int receiveTime;

            if (timeout > 1)
                receiveTime = rand() % (timeout - 1) + 1;
            else
                receiveTime = 1;

            for (int i = 1; i <= receiveTime; i++) {
                cout << "Timer: " << i << " second(s)\n";
                this_thread::sleep_for(chrono::seconds(1));
            }

            cout << "Frame " << frame << " received successfully.\n";
            cout << "ACK " << frame << " received.\n";
            cout << "Timer stopped.\n";

            frame++;
        }
    }

    cout << "\nTransmission completed successfully.\n";

    return 0;
}