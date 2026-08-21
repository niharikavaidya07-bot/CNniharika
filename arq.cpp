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
        }
        else {
            cout << "Frame " << frame << " received successfully.\n";
            cout << "ACK " << frame << " received.\n";

            frame++;
        }
    }

    cout << "\nTransmission completed successfully.\n";

    return 0;
}
/*Enter number of frames: 5
Enter timeout value in seconds: 3

Sending Frame 1...
Timer started.
Frame 1 lost!
Timer: 1 second(s)
Timer: 2 second(s)
Timer: 3 second(s)
Timeout occurred.
Retransmitting Frame 1...

Sending Frame 1...
Timer started.
Frame 1 received successfully.
ACK 1 received.

Sending Frame 2...
Timer started.
Frame 2 received successfully.
ACK 2 received.

Sending Frame 3...
Timer started.
Frame 3 received successfully.
ACK 3 received.

Sending Frame 4...
Timer started.
Frame 4 received successfully.
ACK 4 received.

Sending Frame 5...
Timer started.
Frame 5 received successfully.
ACK 5 received.

Transmission completed successfully.*/